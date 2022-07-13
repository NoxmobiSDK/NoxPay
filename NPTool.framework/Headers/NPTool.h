//
//  NPTool.h
//  NPTool
//
//  Created by nox_chong on 2022/4/22.
//

#import <Foundation/Foundation.h>


// In this header, you should import all the public headers of your framework using statements like #import <NPTool/PublicHeader.h>


#import <NPTool/NPNetwork.h>
#import <NPTool/NSString+Util.h>
#import <NPTool/NSObject+Util.h>
#import <NPTool/NPTimer.h>
#import <NPTool/NSDictionary+NoxPaymentParaEncrypt.h>
#import <NPTool/NPFirebaseManager.h>
#import <NPTool/NPRCManager.h>

@interface NPTool : NSObject

void NPLog(NSString *format, ...);
void IAPLog(NSString *format, ...);

/// 无参，类方法调用，有返回值
id classInvocation(Class class, NSString *selName);
/// 2个参数，类方法调用，有返回值
id classInvocation_2(Class class, NSString *selName, id para1, id para2);
/// 无参，实例方法调用，有返回值
id instanceInvocation(id obj, NSString *selName);
/// 1个参数，实例方法调用，有返回值
id instanceInvocation_1(id obj, NSString *selName, id para);

@end
