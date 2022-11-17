//
//  NoxPay.h
//  NPCore
//
//  Created by nox_chong on 2022/4/22.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NPSDKInfo, NPIAPInfo;

@interface NoxPay : NSObject

/// 启动SDK所需要的参数集合对象
@property (nonatomic, strong, readonly) NPSDKInfo *sdkInfo;

/// 使用IAP模块所需要的参数
@property (nonatomic, strong, readonly) NPIAPInfo *iapInfo;

/// SDK是否已启动
@property (nonatomic, assign, readonly) BOOL isStarted;

/// 获取NoxPay单例对象
+ (instancetype)shared;

/**  启动SDK
 
 @param info SDK配置
 @param complete 启动SDK结果，isSuccess = 启动是否成功，placements = 展示位信息，error = 错误信息
 @discussion placements字典数据结构：
 {
     "placements" : [
         {
             "placement_id":"",
             "product_id":"",
             "product_name":"",
             "product_price":"",
             "product_currency":""
         }
     ]
 }
 */
+ (void)startWithSDKInfo:(NPSDKInfo *)info complete:(nullable void(^)(BOOL isSuccess, NSDictionary *_Nullable placements, NSError *_Nullable error))complete;

/// 获取SDK版本号
+ (NSString *)sdkVersion;

@end


#pragma mark - 内购

@interface NoxPay (IAP)

/// 启动IAP模块
/// @param iapInfo IAP模块配置
/// @param initComplete 启动IAP模块结果，isSuccess = 启动是否成功，error = 错误信息
/// @param purchaseProcess 购买流程全景回调，status : NPInAppPurchase模块NPIAPStatus枚举值；error : 报错信息；extra:当status==20033时，extra中可获取订单号等交易和商品信息,可以通过ek系列方法获取key。
+ (void)startIAPWithInfo:(NPIAPInfo *)iapInfo
            initComplete:(nullable void(^)(BOOL isSuccess, NSError *_Nullable error))initComplete
         purchaseProcess:(nullable void(^)(NSUInteger status, NSError *_Nullable error, NSDictionary *extra))purchaseProcess;

/// 启动IAP模块并且同时初始化Firebase
/// @param iapInfo IAP模块配置
/// @param initComplete 启动IAP模块结果，isSuccess = 启动是否成功，error = 错误信息
/// @param purchaseProcess 购买流程全景回调，status : NPInAppPurchase模块NPIAPStatus枚举值；error : 报错信息；extra:当status==20033时，extra中可获取订单号等交易和商品信息,可以通过ek系列方法获取key。
+ (void)startIAPAndFIRWithInfo:(NPIAPInfo *)iapInfo
            initComplete:(nullable void(^)(BOOL isSuccess, NSError *_Nullable error))initComplete
         purchaseProcess:(nullable void(^)(NSUInteger status, NSError *_Nullable error, NSDictionary *extra))purchaseProcess;

/// 获取商品信息
/// @param placementId  展示位id
+ (nullable NSDictionary *)getPlacementInfo:(NSString *)placementId;

/// 获取商品列表
/// @param groupId  展示位的分组id
+ (nullable NSArray *)getPlacementInfos:(NSString *)groupId;

/// 购买商品
/// @param placementID 要购买的商品所在的展示位ID
+ (void)purchase:(NSString *)placementID;


/// 购买商品
/// @param placementID 要购买的商品所在的展示位ID
/// @param userInfo 用户自定义透传字段，userInfo与本次交易的生命周期相同。请注意：key必须为NSString，value必须是NSString或NSNumber
+ (void)purchase:(NSString *)placementID userInfo:(nonnull NSDictionary <NSString *, id<NSCopying, NSSecureCoding>>*)userInfo;

/// 获取extra key，购买成功的订单号
+ (NSString *)ek_order_number;

/// 获取extra key，购买成功的商品id
+ (NSString *)ek_product_id;

/// 获取extra key，购买成功的商品名称
+ (NSString *)ek_product_name;

/// 获取extra key，展示位id
+ (NSString *)ek_placement_id;

/// 获取extra key，用户自定义透传字段
+ (NSString *)ek_user_info;

/// 恢复购买
/// @param complete 恢复购买回调：status=NPInAppPurchase模块NPIAPStatus枚举值；userInfo=订单用户信息数组；error=报错信息；
+ (void)restore:(void(^)(NSUInteger status, NSArray *userInfo, NSError *error))complete;

/// 处理丢单(不建议开发者主动调用，SDK内部会自动处理丢单问题)
+ (void)handleMissingOrders;

/// 刷新用户信息
+ (void)refreshUserInfo:(NSString *)userId;


#pragma mark - DEPRECATED

/// 刷新token
/// @param token access token
+ (void)refreshAccessToken:(NSString *)token __attribute__((deprecated("This method is no longer used.")));

// 处理丢单
/// @param token token必须为有效token SDK内部丢单验证逻辑不处理token过期问题
+ (void)handleMissingOrdersWithAccessToken:(NSString *)token __attribute__((deprecated("This method is no longer used.")));

@end

#pragma mark - 素材管理

@interface NoxPay (MaterialControl)


/// 下载素材
/// @param progressBlock currentTaskNumber:当前正在下载中的任务的序号，totalTaskCount:任务总数，progress:当前任务的进度
/// @param complete 当isSuccess为YES时，结果在result中；当isSuccess为NO时，错误信息在error中
+ (void)downloadMaterial:(void(^)(NSInteger currentTaskNumber, NSInteger totalTaskCount, double progress))progressBlock complete:(void(^)(BOOL isSuccess, NSDictionary *result, NSError *error))complete;

/// 获取Icon素材
/// @param placementId 展示位id
+ (nullable NSDictionary *)fetchIconMaterial:(NSString *)placementId;

/// 获取Load素材
/// @param placementId 展示位id
+ (nullable NSDictionary *)fetchLoadMaterial:(NSString *)placementId;

/**
 注册倒计时监听(限时购买)
 
 @discussion 每次调用此接口，SDK会先拉取服务端倒计时时间，开启计时器。每次进入后台时停掉计时器，回到前台则再次拉取服务端倒计时时间后开始计时。
 
 @param placementID 展示位id
 @param countdown 仅在展示位的商品为限时购买时使用，remainSec : 剩余时间(秒)
 @param failure 如果失败，则错误信息在error对象中
 */
+ (void)monitorForPlacement:(NSString *)placementID countdown:(void(^)(double remainSec))countdown failure:(void(^)(NSError *error))failure;

@end


NS_ASSUME_NONNULL_END

