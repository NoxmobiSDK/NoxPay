//
//  NPSDKInfo.h
//  NPCore
//
//  Created by nox_chong on 2022/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, NPMode) {
    NPModeRelease,
    NPModeDebug
};

@interface NPSDKInfo : NSObject

@property (nonatomic, copy, readonly) NSString *appId;// mis生成的app id
@property (nonatomic, assign, readonly) NPMode sdkMode;
@property (nonatomic, assign, readonly) BOOL autoRestoreEnable;


/// 便捷构造器
/// @param appId 应用id，由mis创建
/// @param mode 枚举值二选一：NPModeRelease/NPModeDebug
+ (instancetype)infoWithAppId:(NSString *)appId sdkMode:(NPMode)mode;
                      
+ (instancetype)infoWithAppIdAndAutoRestore:(NSString *)appId sdkMode:(NPMode)mode autoRestoreEnable:(BOOL)autoRestore;

@end

NS_ASSUME_NONNULL_END
