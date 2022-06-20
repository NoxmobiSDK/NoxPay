//
//  NPMaterialControlProtocol.h
//  NPCore
//
//  Created by nox_chong on 2022/4/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NPMaterialControlProtocol <NSObject>

- (void)downloadWithConfig:(NSString *)json progress:(void(^)(NSInteger currentTaskNumber, NSInteger totalTaskCount, double progress))progressBlock complete:(void(^)(BOOL isSuccess, NSDictionary *result, NSError *error))complete;

/// 获取Icon素材
/// @param placementId 展示位id
- (NSDictionary *)fetchIconMaterial:(NSString *)placementId;

/// 获取Load素材
/// @param placementId 展示位id
- (NSDictionary *)fetchLoadMaterial:(NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
