//
//  PLVLiveChannel.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 暖场类型
typedef NS_ENUM(NSUInteger, PLVLiveCoverType) {
    /// 无暖场
    PLVLiveCoverTypeNone,
    /// 图片类型
    PLVLiveCoverTypeImage,
    /// 视频类型
    PLVLiveCoverTypeVideo,
};

/**
 直播观看频道信息
 */
@interface PLVLiveChannel : NSObject

/// 直播频道 Id
@property (nonatomic, copy, readonly) NSNumber *channelId;
/// 直播用户 Id
@property (nonatomic, copy, readonly) NSString *userId;
/// 直播场次
@property (nonatomic, copy, readonly) NSString *sessionId;
/// 直播频道名称
@property (nonatomic, copy, readonly) NSString *name;
/// 直播 FLV 地址
@property (nonatomic, copy, readonly) NSString *flvUrl;
/// 直播 M3U8 地址
@property (nonatomic, copy, readonly) NSString *m3u8Url;
/// 直播流名称
@property (nonatomic, copy, readonly) NSString *stream;

/// 暖场类型
@property (nonatomic, readonly) PLVLiveCoverType coverType;
/// 暖场资源地址
@property (nonatomic, copy, readonly) NSString *coverUrl;
/// 图片类型暖场的跳转链接(可能为nil)
@property (nonatomic, copy, readonly) NSString *coverHref;
    
/// 多码率是否开启
@property (nonatomic, readonly) BOOL isMultirateEnabled;
/// 默认清晰度，多码率开启时使用
@property (nonatomic, copy, readonly) NSString *defaultDefinition;
/// 默认清晰度地址，多码率开启时使用
@property (nonatomic, copy, readonly) NSString *defaultDefinitionUrl;
/// 所有清晰度，多码率开启时使用
@property (nonatomic, copy, readonly) NSArray<NSDictionary *> *definitions;

/// NGB 是否开启
@property (nonatomic, readonly) BOOL isNgbEnabled;
/// 防盗链是否开启
@property (nonatomic, readonly) BOOL isUrlProtected;
/// NGB URL
@property (nonatomic, copy, readonly) NSString *ngbUrl;
/// bakUrl URL
@property (nonatomic, copy, readonly) NSString *bakUrl;

/// Qos 发送频率
@property (nonatomic, copy, readonly) NSNumber *reportFreq;

/**
 便利初始化方法
 */
+ (instancetype)liveChannelWithJsonDict:(NSDictionary *)jsonDict;

/**
 更新默认清晰度

 @param definition 清晰度
 */
- (void)updateDefaultDefinitionWithDefinition:(NSString *)definition;

@end
