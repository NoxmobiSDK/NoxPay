//
//  NPFirebaseManager.h
//  NPTool
//
//  Created by nox_chong on 2022/7/4.
//

#import <NPCore/NPCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface NPFirebaseManager : NPError

+ (BOOL)firebaseIsConfigured;

/// 初始化Firebase
+ (void)initFirebase;

/**
 Firebase打点
 key ：1 to 40 alphanumeric characters
 value ：up to 100 characters long
*/
+ (void)trackEventName:(NSString *)name parameters:(nullable NSDictionary<NSString *, id> *)parameters;

@end

NS_ASSUME_NONNULL_END
