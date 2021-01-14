//
//  PLVLiveUtil.h
//  PLVLiveSDK
//
//  Created by ftao on 26/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Polyv 通用工具类
 */
@interface PLVLiveUtil : NSObject

#pragma mark - MD5

/**
 MD5 加密方法

 @param input 待加密的字符串
 @return 32 位小写加密串
 */
+ (NSString*)md5HexDigest:(NSString*)input;

#pragma mark - 二进制/十六进制

/**
 二进制转十六进制

 @param data 二进制
 @return 十六进制字符串
 */
+ (NSString *)hexStringFromData:(NSData *)data;

/**
 十六进制字符串转二进制

 @param hexString 十六进制字符串
 @return 二进制
 */
+ (NSData*)dataForHexString:(NSString*)hexString;

#pragma mark - AES 128

/**
 AES 128 加密

 @param data 待加密的数据
 @param key key 值
 @param iv iv 向量值
 @return 加密后的 data 数据
 */
+ (NSData *)AES128EncryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

/**
 AES 128 解密

 @param data 待解密数据
 @param key key 值
 @param iv iv 向量值
 @return 解密的 data 数据
 */
+ (NSData *)AES128DecryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

#pragma mark - URL SafeBase64

/**
 普通字符的 URL safeBase64 编码

 @param string 待编码字符串
 @return 编码的 safeBase64 字符串
 */
+ (NSString *)safeUrlBase64Encode:(NSString *)string;

/**
 URL safeBase64 字符解码

 @param safeBase64Str 编码的 safeBase64 字符串
 @return data base64 数据
 */
+ (NSData *)safeUrlBase64Decode:(NSString*)safeBase64Str;

#pragma mark - URL Encode

/// 字符串的URL编码
+ (NSString *)URLEncodedString:(NSString *)url;

/// url string 安全的 percent-encoding，防止已 percent-encoding 的字符串二次编码
+ (NSString *)stringBySafeAddingPercentEncoding:(NSString *)urlStr;

@end
