//
//  NSObject+Util.h
//  NPTool
//
//  Created by nox_chong on 2022/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Util)

- (NSString *)toJSON;

/// 判断空字典
BOOL isNullDict(id dict);

/// 判断空数组
BOOL isNullArr(id arr);

/// 判断空字符串
BOOL isNullStr(id str);

@end

NS_ASSUME_NONNULL_END
