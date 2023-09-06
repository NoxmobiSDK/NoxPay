#
#  Be sure to run `pod spec lint NoxPay.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "NoxPay"
  spec.version      = "0.7.8"
  spec.summary      = "A aggregate payment SDK provided Nox."
  spec.homepage     = "https://github.com/NoxmobiSDK/NoxPay"
  spec.license      = "MIT"
  spec.author       = { "gaochong" => "gaochong@noxgroup.com" }
  spec.platform     = :ios, "10.0"
  spec.source       = { :git => "https://github.com/NoxmobiSDK/NoxPay.git", :tag => "#{spec.version}" }
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  spec.requires_arc = true

  spec.subspec 'Tool' do |ss|
    ss.source_files = "NPTool.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NPTool.framework'
    ss.dependency 'AFNetworking'
    ss.dependency 'GTMBase64'
    ss.dependency 'Firebase/Analytics'
    ss.dependency 'Firebase/RemoteConfig'
  end

  spec.subspec 'Core' do |ss|
    ss.source_files = "NPCore.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NPCore.framework'
    ss.dependency 'AFNetworking'
    ss.dependency 'NoxPay/Tool'
  end

  spec.subspec 'IAP' do |ss|
    ss.source_files = "NPInAppPurchase.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NPInAppPurchase.framework'
    ss.dependency 'YYCache'
    ss.dependency 'MJExtension'
    ss.dependency 'NoxPay/Core'
  end

  spec.subspec 'MaterialControl' do |ss|
    ss.source_files = "NPMaterialControl.framework/Headers/*.{h}"
    ss.ios.vendored_frameworks = 'NPMaterialControl.framework'
	ss.dependency 'NoxPay/Core'
  end

end
