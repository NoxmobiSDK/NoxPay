//
//  NPIAPInfo.h
//  NPCore
//
//  Created by nox_chong on 2022/5/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NPIAPInfo : NSObject

@property (nonatomic, copy, readonly) NSString *projectID;// 智勇那边生成的项目id
@property (nonatomic, copy, readonly) NSString *uid;
@property (nonatomic, copy, readonly) NSString *accessToken;

/// @param projectID 项目ID 中台生成
/// @param uid 用户id 非强制登录初始化可为空 登录态不传递该值有可能会导致丢单问题
/// @param accessToken 非强制登录可为空 登录态不传递该值有可能会导致丢单问题
+ (instancetype)infoWithProjectID:(NSString *)projectID
                              uid:(nullable NSString *)uid
                      accessToken:(nullable NSString *)accessToken;

@end

NS_ASSUME_NONNULL_END
