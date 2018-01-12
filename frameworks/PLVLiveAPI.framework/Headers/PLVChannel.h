//
//  PLVChannel.h
//  PolyvIJKLivePlayer
//
//  Created by ftao on 2016/12/14.
//  Copyright © 2016年 easefun. All rights reserved.
//

#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

#import <Foundation/Foundation.h>

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

typedef NS_ENUM(NSInteger, PLVLiveStreamState) {
    PLVLiveStreamStateUnknown = -1,     // 直播流状态未知
    PLVLiveStreamStateNoStream = 0,     // 没有流
    PLVLiveStreamStateLive = 1          // 直播中
};

@interface PLVChannel : NSObject

@property (nonatomic, copy, readonly) NSString *channelId;          // 直播频道ID
@property (nonatomic, copy, readonly) NSString *userId;             // 直播用户ID
@property (nonatomic, copy, readonly) NSString *name;               // 直播频道名称
@property (nonatomic, copy, readonly) NSString *flvUrl;             // 直播FLV 地址
@property (nonatomic, copy, readonly) NSString *m3u8Url;            // 直播M3U8 地址
@property (nonatomic, copy, readonly) NSString *stream;             // 直播流名称

@property (nonatomic, readonly) BOOL isNgbEnabled;                  // NGB 是否开启
@property (nonatomic, readonly) BOOL isUrlProtected;                // 防盗链是否开启
@property (nonatomic, copy, readonly) NSString *ngbUrl;             // NGB URL
@property (nonatomic, copy, readonly) NSString *bakUrl;             // bakUrl URL

@property (nonatomic, copy, readonly) NSNumber *reportFreq;


/**
 *  登录频道获取video json（回调都在主线程中进行）
 *
 *  @param userId               用户ID
 *  @param channelId            频道ID
 *  @param completionHandler    加载成功的回调
 *  @param failureHandler       加载失败的回调（频道号不存在：响应码500；用户名不正确：响应码403）
 */
+ (void)loadVideoJsonWithUserId:(NSString *)userId
                      channelId:(NSString *)channelId
              completionHandler:(void (^)(PLVChannel *channel))completionHandler
                 failureHandler:(void (^)(NSString *errorName, NSString *errorDescription))failureHandler;

/**
 * 当前流是否正在直播(此方法为同步线程)
 *
 * @param stream 直播流名
 *
 * @return PLVLiveStreamState 直播状态
 */
+ (PLVLiveStreamState)isLiveWithStreame:(NSString *)stream;

#pragma mark - 新增接口

/**
 获取频道咨询提问菜单状态
 
 @param channelId 频道号
 @param completion 获取成功，参数不能为 nil
 @param failure 获取失败
 */
+ (void)getChannelInfoWithQuestionMenuStatus:(NSUInteger)channelId
                                  completion:(void(^)(BOOL isOn))completion
                                     failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 Socket、连麦授权接口
 
 @param channelId 频道号
 @param appId Polyv直播后台“API设置“中appId参数（用户参数）
 @param appSecret Polyv直播后台“API设置“中appSecret参数（用户参数）
 @param success 授权完成，参数不能为 nil
 @param failure 授权失败，PLVLiveErrorCode: ParamInvalid、NetworkError、ResponseCodeNot200、AuthFailure、EncodeJsonDecodeFailure、DecodeFailure、JsonDecodeFailure
 */
+ (void)requestAuthorizationForLinkingSocketWithChannelId:(NSUInteger)channelId
                                                    Appld:(NSString *)appId
                                                appSecret:(NSString *)appSecret
                                                  success:(void (^)(NSDictionary *responseDict))success
                                                  failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取聊天室所有在线成员列表
 
 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomListUsersWithRoomId:(NSUInteger)roomId
                                completion:(void (^)(NSDictionary *listUsers))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

@end
