#
#  Be sure to run `pod spec lint PolyvLiveAPI.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "PolyvLiveAPI"
  s.version      = "0.7.5"
  s.summary      = "Polyv iOS 直播观看、推流、聊天室相关接口"
  # s.description  = <<-DESC
  #                  DESC

  s.homepage     = "https://github.com/polyv/PolyvLiveAPI"
  s.license      = { :type => "MIT" }
  s.author       = { "ftao" => "fft1026@163.com" }
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/polyv/PolyvLiveAPI.git", :tag => "#{s.version}" }

  # s.source_files  = "Classes", "Classes/**/*.{h,m}"
  # s.exclude_files = "Classes/Exclude"
  s.vendored_frameworks = 'frameworks/PLVLiveAPI.framework'

  # s.public_header_files = "Classes/**/*.h"

  # s.framework  = "SomeFramework"
  # s.frameworks = "SomeFramework", "AnotherFramework"

  s.requires_arc = true
  # s.user_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "JSONKit", "~> 1.4"
end
