# PolyvLiveAPI

当前版本：

- PolyvLiveAPI ~ 0.7.1+190221

Podfile 中添加

```ruby
platform :ios, "8.0"

use_frameworks!

target 'YourApp' do
    pod 'PolyvLiveAPI', '~> 0.7.1'      # Polyv live api.
end
```

## 历史版本

  各版本下载可通过版本后的 直接下载 地址或在 github [releases](https://github.com/polyv/PolyvLiveAPI/releases) 中找到对应版本下载

### 0.7.1+190221

  - 更新拉流地址及多码率获取逻辑
  - 修复枚举类型错误可能导致编译失败问题

  直接下载：[0.7.1+190221](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI_0.7.1+190221.zip)

### 0.7.0+181031

  - 获取直播频道信息的备用接口地址更新（废弃旧接口）
  - 新增聊天室历史记录接口（更多参数）
  - 部分错误注释信息更新

  直接下载：[0.7.0+181031](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI_0.7.0+181031.zip)

### 0.6.0+180815

  - 新增获取频道信息接口及自动重试的接口
  - 废弃获取频道信息的备用接口
  - PLVLiveConfig 新增用户账号信息相关设置方法
  - 已知问题优化：内部使用静态方法防止不同SDK符号冲突问题

  直接下载：[0.6.0+180815](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI_0.6.0+180815.zip)

### 0.5.0+180730

  - 新增获取自定义 TAB 接口
  - 新增频道限制信息接口；live channel 添加 直播限制相关属性信息

  直接下载：[0.5.0+180730](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI_0.5.0+180730.zip)

### 0.4.1+180629

  - 新增直播加入连麦和退出连麦通知

  直接下载：[0.4.1+180629](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI_0.4.1+180629.zip)

### 0.4.0+180622

  - 新增 更新默认清晰度 接口 
  - 新增 直播信息多码率属性（兼容v2接口数据问题） 
  - 新增 获取聊天室在线成员列表 接口

  直接下载：[0.4.0+180622](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI_0.4.0+180622.zip)

### 0.3.0-rc+180315

  - PLVLiveConfig
    - 添加统计后台参数
  - PLVLiveReporter
    - 添加各个接口的二版本，减少参数
    - 添加sessionId参数不为null的判断
  - 0.3.0+180306 中 TimeStamp 函数冲突问题修复

  直接下载：[0.3.0+180315](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI.framework_0.3.0+180315.zip)

### 0.3.0+180306

  - PLVLiveAPI
    - 新增“获取推流地址”接口
    - 更新“获取推流频道信息及地址”接口
  - PLVLiveChannel
    - 新增暖场相关属性
    - 新增直播场次Id属性
  - PLVPushChannel
    - 废弃了推流地址属性及设置方法
  - PLVLiveReporter
    - 新增播放信息统计 v2 版本
    
  直接下载：[0.3.0+180306](http://repo.polyv.net/ios/download/liveAPI/PLVLiveAPI.framework_0.3.0+180306.zip)

### 0.2.0+180125

  - 重大接口更新（重构）
  - Polyv iOS 直播观看、推流、云课堂、聊天室等相关接口.

  直接下载：[0.2.0](http://repo.polyv.net/ios/download/liveAPI/0.2.0/PLVLiveAPI.framework.zip)

### 0.1.4+180122

  - 移除内部GTMBase64第三方库
  - 修复同Polyv点播SDK的方法名冲突问题

  直接下载：[0.1.4](http://repo.polyv.net/ios/download/liveAPI/0.1.4/PLVLiveAPI.framework.zip)

### 0.1.3+180112

  - 新增获取频道咨询提问菜单状态接口
  - 新增Socket、连麦授权接口
  - 新增获取聊天室所有在线成员列表接口
  - Qos接口版本号更新：iOS-livePlayerSDK2.2.0+180111

  直接下载：[0.1.3](http://repo.polyv.net/ios/download/liveAPI/0.1.3/PLVLiveAPI.framework.zip)

  CocoaPods： `pod 'PolyvLiveAPI', '~> 0.1.3'`

### 0.1.2+180102

  - Qos接口版本号更新：iOS-livePlayerSDK2.1.2.180102

  直接下载：[0.1.2](http://repo.polyv.net/ios/download/liveAPI/0.1.2/PLVLiveAPI.framework.zip)

  CocoaPods： `pod 'PolyvLiveAPI', '~> 0.1.2'`
