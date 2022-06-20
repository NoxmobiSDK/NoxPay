//
//  NoxPaymentError.h
//
//  Created by 陈晓龙 on 2020/3/27.
//  Refactor by 高崇 on 2022/5/6.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, NoxPaymentErrorCode) {
	NPEC_Unavailable = 910001, // 未开启内购功能
    NPEC_InvalidProductID = 910002,//无效的产品ID
    NPEC_InlegalProduct = 910003,//无法获取产品信息
	NPEC_OrderGenFailed = 910004,//无法生成订单
	NPEC_RecieptCheckError = 910005,//凭据校验错误
	NPEC_TokenInvalid = 910006,//token 无效
    NPEC_TransactionCancel = 910007,//交易取消
	NPEC_TransactionFaild = 910008,//交易失败

};

NS_ASSUME_NONNULL_BEGIN

@interface NoxPaymentError : NSError
+(instancetype)errorWithCode:(NSInteger)code;
-(NSString*)errDesc;
@property (nonatomic, assign, readonly) NoxPaymentErrorCode errorCode;//same to code
@end

NS_ASSUME_NONNULL_END
