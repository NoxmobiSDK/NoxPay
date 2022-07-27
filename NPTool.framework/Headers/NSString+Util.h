//
//  NSString+Util.h
//  测试WebView点击事件
//
//  Created by nox_chong on 2022/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Util)

#pragma mark - RSA

// return base64 encoded string
- (NSString *)encryptStringWithPublicKey:(NSString *)pubKey;
// return raw data
- (NSData *)encryptData:(NSData *)data publicKey:(NSString *)pubKey;
// return base64 encoded string
- (NSString *)encryptStringWithPrivateKey:(NSString *)privKey;
// return raw data
- (NSData *)encryptData:(NSData *)data privateKey:(NSString *)privKey;

// decrypt base64 encoded string, convert result to string(not base64 encoded)
- (NSString *)decryptStringWithPublicKey:(NSString *)pubKey;
- (NSData *)decryptData:(NSData *)data publicKey:(NSString *)pubKey;
- (NSString *)decryptStringWithPrivateKey:(NSString *)privKey;
- (NSData *)decryptData:(NSData *)data privateKey:(NSString *)privKey;


#pragma mark - 散列

/**
 *  创新部的写法
 *
 *  源码无修改
 */
+ (NSString *)hmac:(NSString *)plaintext key:(NSString *)key;


#pragma mark - 文件散列函数

/**
 *  计算文件的MD5散列结果
 *
 *  终端测试命令：
 *  @code
 *  md5 file.dat
 *  @endcode
 *
 *  @return 32个字符的MD5散列字符串
 */
- (NSString *)fileMD5Hash;

#pragma mark - AES加解密

- (NSString *)aesEncrypt_XL;// 原'创新部'写法

NSString * aesEncryptString(NSString *content, NSString *key, NSError **error);
NSString * aesDecryptString(NSString *content, NSString *key, NSError **error);
NSData   * aesEncryptData(NSData *data, NSData *key, NSError **error);
NSData   * aesDecryptData(NSData *data, NSData *key, NSError **error);

#pragma mark - 公共基础

NSString * safe_text(NSString *string);

/// 这两个方法调用前提是self是标准JSON
- (NSDictionary *)toDict;
- (NSArray *)toArray;

@end

NS_ASSUME_NONNULL_END
