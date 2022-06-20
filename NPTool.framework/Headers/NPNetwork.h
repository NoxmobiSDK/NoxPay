//
//  NPNetwork.h
//  NPInAppPurchase
//
//  Created by nox_chong on 2022/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NPNetwork : NSObject

+ (instancetype)shared;


/// POST请求
/// @param url 目标URL
/// @param param 请求的参数字典
/// @param complete 请求结束后的回调，isSucceed == YES时response为响应体，isSucceed == NO时response为error
+ (NSURLSessionDataTask *)POST:(NSString *)url param:(NSDictionary *)param complete:(void(^)(BOOL isSucceed, id response))complete;


/// 下载文件
/// @param url 目标URL
/// @param savePath 文件下载后的保存地址
/// @param progressBlock 下载进度(0-1)
/// @param complete filePath:下载文件的本地路径，error:如果发生错误error将有值
+ (NSURLSessionDownloadTask *)download:(NSString *)url savePath:(NSURL *)savePath progress:(void(^)(double progress))progressBlock complete:(void (^)(NSString *filePath, NSError *error))complete;

@end

NS_ASSUME_NONNULL_END

