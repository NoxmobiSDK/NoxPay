//
//  NPTimer.h
//  NPTool
//
//  Created by nox_chong on 2022/5/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NPTimerDelegate <NSObject>

@optional

- (void)timerTicktock;
- (void)timerTicktockWithInfo:(id)info;

@end

@interface NPTimer : NSObject

+ (instancetype)timerWithDelegate:(id<NPTimerDelegate>)delegate;

- (void)start;
- (void)cancel;

- (void)startWithInfo:(id)info;

@end

NS_ASSUME_NONNULL_END
