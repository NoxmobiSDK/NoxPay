//
//  NPError.h
//  NPCore
//
//  Created by nox_chong on 2022/6/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, NPErrorCode) {
    /**
     * App id 不合法
     */
    NPErrorAppIDInvalid = 100001,
    
    /**
     * MIS配置请求失败
     */
    NPErrorFailedToRequestMISConfig = 100002,
    
    /**
     * SDK未初始化
     */
    NPErrorSDKNotInit = 100003,
    
    /**
     * 展示位id不合法
     */
    NPErrorPlacementIDInvalid = 100004,
    
    /**
     * MIS未配置限时购买商品
     */
    NPErrorNoTimeLimitedOffer = 100005,
    
    /**
     * MIS未配置任何素材
     */
    NPErrorNoMaterialConfig = 100006,
    
    /**
     * 内部数据转换失败
     */
    NPErrorFailedToConvert = 100007,
    
    /**
     * AES解析配置为空
     */
    NPErrorAESFailedToDecode = 100008,
    
    /**
     * NPIAPInfo传入参数不合法
     */
    NPErrorIAPInfoInvalid = 100009,
    
    /**
     * 素材模块：配置不合法
     */
    NPErrorMaterialConfigInvalid = 200001,
    
    /**
     * 素材模块：配置转数组失败
     */
    NPErrorMaterialConfigToArrayFailed = 200002,
    
    /**
     * 素材模块：置中的展示位无效
     */
    NPErrorMaterialConfigPidInvalid = 200003,
    
    /**
     * 素材模块：配置中没有需要下载的任务
     */
    NPErrorMaterialConfigNoTask = 200004,
    
    /**
     * 素材模块：下载文件失败，无法保存该文件
     */
    NPErrorMaterialDownloadFailed = 200005,
    
    /**
     * IAP：商品ID无效
     */
    NPErrorProductIDInvalid = 300001,
    
    /**
     * IAP：获取商品列表失败
     */
    NPErrorFailedToFetchProductList = 300002,
    
    /**
     * IAP：此设备已禁用内购功能
     */
    NPErrorIAPWasDisable = 300003,
    
    /**
     * IAP：交易失败
     */
    NPErrorTransactionFailed = 300005,
    
    /**
     * IAP：Token失效
     */
    NPErrorTokenInvalid = 300007,
    
    /**
     * IAP：验单时网络异常
     */
    NPErrorNetworkExceptionWhenVerifyOrder = 300008,
    
    /**
     * IAP：恢复购买验证失败
     */
    NPErrorRestoreFailedToVerify = 300009,
    
    /**
     * IAP：创建订单失败
     */
    NPErrorCreateOrderFailed = 300010,
    
    /**
     * IAP：获取订单信息失败
     */
    NPErrorFetchOrderFailed = 300011,
    
    /**
     * IAP特别错误：验单时网络断开
     */
    NPErrorNetworkUnreachable = 390001,
    
    /**
     * Tool：AES键或值为空
     */
    NPErrorAESKeyOrContentWasNil = 400001,
    
    /**
     * Tool：AES键长度不合法
     */
    NPErrorAESKeyLengthInvalid = 400002,
};

@interface NPError : NSObject

+ (NSError *)errorCode:(NPErrorCode)code reason:(NSString *)reason;
+ (NSString *)domain;
+ (NSString *)domainServer;
+ (NSString *)domainNetwork;

@end

NS_ASSUME_NONNULL_END

