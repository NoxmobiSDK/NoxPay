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

@interface NPTool : NSObject

void NPLog(NSString *format, ...);
void IAPLog(NSString *format, ...);

@end
