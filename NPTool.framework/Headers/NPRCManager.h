//
//  NPRCManager.h
//  NPTool
//
//  Created by nox_chong on 2022/7/4.
//

#import <NPCore/NPCore.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^NPRCFetchFailed)(NSError * _Nullable error);

typedef NS_ENUM(NSUInteger, NPRCFetchStatus) {
    NPRCFetchStatusNewConfig,
    NPRCFetchStatusOldConfig,
    NPRCFetchStatusError
};

@interface NPRCManager : NSObject

/// 初始化Firebase并初始化一个NoxRCManager对象
+ (instancetype)managerAndInitFirebase:(nullable NPRCFetchFailed)handler;

/// 初始化一个NoxRCManager对象
+ (instancetype)manager:(nullable NPRCFetchFailed)handler;

/// 设置默认配置plist文件名
- (void)setDefaultsPlistFileName:(NSString *)name;

/// 设置最小获取间隔；单位：秒(s)
- (void)setMinimumFetchInterval:(NSTimeInterval)interval;

/// 获取配置并激活
- (void)fetchAndActivateWithHandler:(nullable void(^)(NPRCFetchStatus status, NSError * _Nullable error))handler;

/// 获取远程字符串配置
- (nullable NSString *)remoteStringForKey:(NSString *)key;

/// 获取远程JSON对象配置
/// @discussion 本地plist默认配JSON方式要和RC后台一模一样，直接写JSON不用转任何格式, 例：key=person, type=String, value={"name":"Jordan"}
- (nullable id)remoteJSONForKey:(NSString *)key;

/// 获取RC远程数字配置
- (nullable NSNumber *)remoteDigitForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
