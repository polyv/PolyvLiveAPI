//
//  PLVNetworking.h
//  PLVLiveStreamer
//
//  Created by LinBq on 16/11/7.
//  Copyright © 2016年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVChannel.h"


/// SDK 通用错误码
typedef NS_ENUM(NSInteger, PLVLiveErrorCode) {
    /// 参数无效/非法
    PLVLiveErrorCodeParamInvalid                = -10000,
    
    /// 网络请求错误
    PLVLiveErrorCodeNetworkError                = -10010,
    /// 服务器响应非200
    PLVLiveErrorCodeResponseCodeNot200          = -10011,
    /// 服务器响应403
    PLVLiveErrorCodeResponseCode403             = -10012,
    
    /// JSON解析失败
    PLVLiveErrorCodeJsonDecodeFailure           = -10020,
    /// 加密JSON解析失败
    PLVLiveErrorCodeEncodeJsonDecodeFailure     = -10021,
    /// 解码失败(异常)
    PLVLiveErrorCodeDecodeFailure               = -10022,
    
    /* -- 以下主要为服务器对参数验证不通过 -- */
    /// 登录失败(登录接口)
    PLVLiveErrorCodeLoginFailure                = -10030,
    /// 请求失败
    PLVLiveErrorCodeRequestFailure              = -10031,
    /// 设置失败
    PLVLiveErrorCodeSettingFailure              = -10032,
    /// 授权验证失败
    PLVLiveErrorCodeAuthFailure                 = -10033,
    
    /// 未知类型
    PLVLiveErrorCodeUnknown                     = -9999
};



@interface PLVNetworking : NSObject

/**
 日志开关
 */
+ (void)logEnable:(BOOL)enable;

/**
 登陆
 @param channelId 频道号
 @param password 密码
 @param completion 成功回调
 @param failure 失败回调
 */
+ (void)loginWithChanelid:(NSString *)channelId
                 password:(NSString *)password
               completion:(void (^)(NSDictionary *responseDict))completion failure:(void(^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 请求 RTMP URL
 @param urlNgb NgbUrl
 @param streamName 流名
 @param completion 成功回调
 @param failure 失败回调
 */
+ (void)requestUrlRtmpWithNgb:(NSString *)urlNgb
                       stream:(NSString *)streamName
                   completion:(void (^)(NSString *urlRTMP))completion
                      failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 设置频道名称
 @param newName 新的频道名称
 @param completion 成功回调
 @param failure 失败回调
 */
+ (void)updateChanelName:(NSString *)newName
              completion:(void (^)(NSDictionary *responseDict))completion
                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;



/**
 连麦授权
 @param channelId 频道号
 @param role 角色
 @param userId 用户Id（对应POLYV官网账号）
 @param appSecret 用户密钥（对应POLYV官网账号）
 @param completion 成功回调
 @param failure 失败回调
 */
+ (void)getChatTokenWithChannelId:(NSInteger)channelId
                             role:(NSString *)role
                           userId:(NSString *)userId
                            appld:(NSString *)appId
                        appSecret:(NSString *)appSecret
                       completion:(void (^)(NSDictionary *responseDict))completion failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取观众列表
 @param length 查询长度
 @param page 起始位置
 @param completion 成功回调
 @param failure 失败回调
 */
+ (void)requestViewerListWithLength:(NSUInteger)length
                               page:(NSUInteger)page
                         completion:(void (^)(NSInteger count, NSArray *viewerList, NSError *error))completion
                            failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 设置流模式
 @param channelId 频道号
 @param stream 流名称
 @param completion 成功回调
 @param failure 失败回调
 */
+ (void)notifyStreamModeWithChannelId:(NSString *)channelId
                               stream:(NSString *)stream
                           videoWidth:(NSUInteger)videoWidth
                          videoHeight:(NSUInteger)videoHeight
                           completion:(void (^)(NSString *responseCont))completion
                              failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;


@end

