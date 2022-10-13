//
//  NoxPayIAP.h
//
//  Created by 陈晓龙 on 2020/3/27.
//  Refactor by 高崇 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@class NoxPayIAP;

typedef NS_ENUM(NSUInteger, NPIAPStatus) {
    NPIAP_Start = 20000,                    //开始购买流程
    NPIAP_FetchingProduct = 20010,          //获取商品列表开始
    NPIAP_FetchProductFinished = 20011,     //获取商品列表完成
    NPIAP_GeneratingOrder = 20020,          //生成订单中
	NPIAP_GeneratingOrderFinished = 20021,  //订单生产完成
	NPIAP_AddToPaymentQueue = 20022,        //加入支付队列
    NPIAP_RecoverPaidOrder = 20023,         //恢复了一笔已支付的订单，“正在为您恢复已支付的订单”
    NPIAP_Paying = 20030,                   //支付中
	NPIAP_PayingFinished = 20031,           //支付完成
    NPIAP_Verifying = 20032,                //订单验证中
	NPIAP_VerifyingFailed = 20033,          //支付成功,校验失败 属于丢单范畴
    NPIAP_Success  = 20040,                 //支付成功
    NPIAP_Cancel = 30001,                   //用户取消支付
    NPIAP_Failed = 30002,                   //支付失败
    NPIAP_Occupied = 30003,                 //IAP模块被占用中(正在处理其它订单)，SDK同时只能处理一单
    NPIAP_NotInit = 30004,                  //IAP模块未初始化，请先初始化IAP
    NPIAP_TransactionDeferred = 30020,      //交易推迟 官方解释是：交易已经加入队列，但是需要等待外部操作 主要用于儿童模式，需要询问家长同意。这种情况下不能关闭订单（完成交易），否则这类充值将无法处理。
	
	NPIAP_Restore_Start = 50001,
	NPIAP_Restore_None = 50002,             //暂无可恢复的购买项
    NPIAP_Restore_Cancel = 50003,
    NPIAP_Restore_Success = 50004,
    NPIAP_Restore_Failed = 50005,
};

typedef NS_ENUM(NSUInteger, NPIAPEnviroument) {
    NPIAP_PRODUCTION,
    NPIAP_SANDBOX
};

NS_ASSUME_NONNULL_BEGIN

#pragma mark - NoxModuelPaymentEvents
@protocol NoxModuelPaymentEvents <NSObject>
@required
/// 内购事件通知
/// @param manager 管理对象 单例
/// @param status 状态码 可以仅监听业务需要关注的
/// @param error 错误对象 可根据错误码处理相关错误以及国际化文案
/// @param extra 当status == NPIAP_Success，此字典中可获取该订单号，key可通过extra系列函数获取
-(void)paymentManager:(NoxPayIAP*)manager
      didUpdateStatus:(NPIAPStatus)status
                error:(NSError* _Nullable)error
                extra:(NSDictionary *_Nullable)extra;

@optional
/// 用于Adjust数据上报（暂时看没啥用）
/// @param manager 管理对象 单例
/// @param receipt 凭据数据
/// @param transaction 交易对象
/// @param extInfo 预留字段避免后续新增额外回调参数
- (void)paymentManager:(NoxPayIAP*)manager
didFinishPayingWithReceipt:(NSData*)receipt
           transaction:(SKPaymentTransaction*)transaction
               product:(SKProduct*)product
               extInfo:(id)extInfo;


/// 商店内IAP单元点击回调事件（暂时看没啥用）
/// @param manager 管理对象 单例
/// @param payment 交易对象
/// @param product 用户选择的内购产品对象
-(void)paymentManager:(NoxPayIAP*)manager
shouldAddStorePayment:(SKPayment *)payment
		   forProduct:(SKProduct *)product;


/// 恢复交易事件
/// @param manager 管理对象 单例
/// @param userInfo 订单用户信息数组
/// @param error 恢复失败错误信息,为空则表示恢复成功
-(void)paymentManager:(NoxPayIAP*)manager didFinishRestoreTransactionWithResult:(NPIAPStatus)restoreStatus info:(NSArray *)userInfo error:(NSError *)error;

@end


#pragma mark - NoxModuelPayment

@interface NoxPayIAP : NSObject

/// 当前支付队列中的交易（不推荐使用）
@property (nonatomic, strong, readonly) NSArray<SKPaymentTransaction *> *transactions;

/// 获取单例对象
+ (NoxPayIAP*)shared;

/// 设置开发环境
/// @param enviroument 传入一个枚举值，默认 NPIAP_PRODUCTION
+ (void)setupEvn:(NPIAPEnviroument)enviroument;

/// 获取开发环境
+ (NPIAPEnviroument)currentEnv;

/// 获取商品列表
/// @param produuctIDs 商品ID数组
/// @param completation Apple返回的SKProduct对象数组
+ (void)fetchProductList:(NSArray <NSString *> *)produuctIDs complete:(void(^)(NSArray<SKProduct*>* _Nullable  products, NSError * _Nullable error))completation;

/// 购买商品
/// @param productID 购买的产品ID
+ (void)purchaseProduct:(NSString *)productID;

/// 恢复购买
+ (void)restoreTransaction;

/// 检测丢单问题
+ (void)startProcessLostOrders;

/// 获取交易流水
/// @param orderStatus 订单状态，nil返回全部状态
/// @param type 支付方式 nil.全部方式  1.微信, 2.google, 3.apple, 4.支付宝
/// @param offset offset
/// @param size size
/// @param resultBlock error = nil 为成功
+ (void)getOrderInfo:(NSString * _Nullable)orderStatus clientType:(NSString * _Nullable)type unionId:(NSString *)uid offset:(NSInteger)offset size:(NSInteger)size resultBlock:(void (^)(NSDictionary * _Nullable, NSError * _Nullable))resultBlock;

#pragma mark - Extra Key

/// 用于获取extra字典中购买成功的订单号
+ (NSString *)ek_order_number;

/// 获取extra key，购买成功的商品id
+ (NSString *)ek_product_id;

/// 获取extra key，购买成功的商品名称
+ (NSString *)ek_product_name;

/// 获取extra key，展示位id
+ (NSString *)ek_placement_id;

/// 获取extra key，用户自定义透传字段
+ (NSString *)ek_user_info;

#pragma mark - Event Broadcast
/// 添加事件通知
/// @param observer 实现 NoxModuelPaymentEvents 协议的对象，无需传递弱引用
+ (void)addPaymentEventObserver:(id<NoxModuelPaymentEvents>)observer;

/// 移除事件通知
/// @param observer 实现 NoxModuelPaymentEvents 协议的对象，不强制在dealloc中调用，在认为无需监听事件的时刻移除即可
+ (void)removePaymentEventObserver:(id<NoxModuelPaymentEvents>)observer;

#pragma mark - Remote Config

/// Remote Config管理实例
@property (nonatomic, strong, class) NPRCManager *rc;

/// 初始化Remote Config
/// return RC初始化成功返回YES，反之返回NO
+ (BOOL)initializeRC:(void(^)(NSError * _Nullable error))complete;

/// 先初始化Firebase再初始化RC
/// return RC和FIrebase同时初始化成功返回YES，反之返回NO
+ (BOOL)initializeRCAndFirebase:(void(^)(NSError * _Nullable error))complete;

@end


NS_ASSUME_NONNULL_END
