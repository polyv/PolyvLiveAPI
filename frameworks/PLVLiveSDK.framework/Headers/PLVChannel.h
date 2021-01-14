//
//  PLVChannel.h
//  PLVLiveStreamer
//
//  Created by LinBq on 16/11/21.
//  Copyright © 2016年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BqSingletonGCD.h"

@interface PLVChannel : NSObject
BqSingletonH(Channel)

/// 频道号（主账号id）
@property (nonatomic, copy) NSString *channelId;
/// 聊天室房间号（分房间场景下，是第一个分房间号）
@property (nonatomic, copy) NSString *chatRoomId;

/// 当前账号（主账号或子账号id）
@property (nonatomic, copy) NSString *accountId;

/// 子账号信息列表(键：accountId 值：accountName)
@property (nonatomic, copy) NSDictionary *channelAccountList;

/// 流名
@property (nonatomic, copy) NSString *streamName;

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appSecret;

/// 推流模式（是否主账号推流）
- (BOOL)isMasterAccount;


/// 主账号id
- (NSString *)masterChannelid __deprecated;

/// 是否为子账号
- (BOOL)subAccount __deprecated;


@end
