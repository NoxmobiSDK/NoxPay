//
//  NPIAPInfo.h
//  NPCore
//
//  Created by nox_chong on 2022/5/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NPIAPInfo : NSObject

@property (nonatomic, copy) NSString *projectID;// 智勇那边生成的项目id
@property (nonatomic, copy) NSString *uid;

/// @param projectID 项目ID 中台生成
/// @param uid 用户id 非强制登录初始化可为空 登录态不传递该值有可能会导致丢单问题
+ (instancetype)infoWithProjectID:(NSString *)projectID uid:(nullable NSString *)uid;



#pragma mark - DEPRECATED

@property (nonatomic, copy) NSString *accessToken __attribute__((deprecated("This property is no longer used.")));

/// @param projectID 项目ID 中台生成
/// @param uid 用户id 非强制登录初始化可为空 登录态不传递该值有可能会导致丢单问题
/// @param accessToken 非强制登录可为空 登录态不传递该值有可能会导致丢单问题
+ (instancetype)infoWithProjectID:(NSString *)projectID
                              uid:(nullable NSString *)uid
                      accessToken:(nullable NSString *)accessToken __attribute__((deprecated("This method is no longer used.")));

@end

NS_ASSUME_NONNULL_END
