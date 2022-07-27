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
    NPErrorAppIDInvalid = 600001,
    
    /**
     * MIS配置请求失败
     */
    NPErrorFailedToRequestMISConfig = 600002,
    
    /**
     * SDK未初始化
     */
    NPErrorSDKNotInit = 600003,
    
    /**
     * 展示位id不合法
     */
    NPErrorPlacementIDInvalid = 600004,
    
    /**
     * MIS未配置限时购买商品
     */
    NPErrorNoTimeLimitedOffer = 600005,
    
    /**
     * MIS未配置任何素材
     */
    NPErrorNoMaterialConfig = 600006,
    
    /**
     * 内部数据转换失败
     */
    NPErrorFailedToConvert = 600007,
    
    /**
     * AES解析配置为空
     */
    NPErrorAESFailedToDecode = 600008,
    
    /**
     * NPIAPInfo传入参数不合法
     */
    NPErrorIAPInfoInvalid = 600009,
    
    /**
     * 素材模块：配置不合法
     */
    NPErrorMaterialConfigInvalid = 700001,
    
    /**
     * 素材模块：配置转数组失败
     */
    NPErrorMaterialConfigToArrayFailed = 700002,
    
    /**
     * 素材模块：配置中的展示位无效
     */
    NPErrorMaterialConfigPidInvalid = 700003,
    
    /**
     * 素材模块：配置中没有需要下载的任务
     */
    NPErrorMaterialConfigNoTask = 700004,
    
    /**
     * 素材模块：下载文件失败，无法保存该文件
     */
    NPErrorMaterialDownloadFailed = 700005,
    
    /**
     * IAP：商品ID无效
     */
    NPErrorProductIDInvalid = 800001,
    
    /**
     * IAP：获取商品列表失败
     */
    NPErrorFailedToFetchProductList = 800002,
    
    /**
     * IAP：此设备已禁用内购功能
     */
    NPErrorIAPWasDisable = 800003,
    
    /**
     * IAP：交易失败
     */
    NPErrorTransactionFailed = 800005,
    
    /**
     * IAP：验单时网络异常
     */
    NPErrorNetworkExceptionWhenVerifyOrder = 800008,
    
    /**
     * IAP：恢复购买验证失败(未启用，预留)
     */
    NPErrorRestoreFailedToVerify = 800009,
    
    /**
     * IAP：创建订单失败
     */
    NPErrorCreateOrderFailed = 800010,
    
    /**
     * IAP：获取订单信息失败(未启用，预留)
     */
    NPErrorFetchOrderFailed = 800011,
    
    /**
     * IAP特别错误：验单时网络断开
     */
    NPErrorNetworkUnreachable = 890001,
    
    /**
     * Tool：AES键或值为空
     */
    NPErrorAESKeyOrContentWasNil = 900001,
    
    /**
     * Tool：AES键长度不合法
     */
    NPErrorAESKeyLengthInvalid = 900002,
    
    /**
     * Tool：Firebase SDK 尚未初始化
     */
    NPErrorFirebaseSDKNotInit = 900003,
    
    /**
     * Tool：Remote Config SDK 未正确引入
     */
    NPErrorRCSDKImportedFailed = 900004,
    
    /**
     * Tool：获取并激活RC配置失败
     */
    NPErrorRCFetchAndActivateFailed = 900005,
    
};

@interface NPError : NSObject

+ (NSError *)errorCode:(NSUInteger)code reason:(NSString *)reason;
+ (NSString *)domain;
+ (NSString *)domainServer;
+ (NSString *)domainNetwork;

@end

NS_ASSUME_NONNULL_END

