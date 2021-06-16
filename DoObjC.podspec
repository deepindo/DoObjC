#
# Be sure to run `pod lib lint DoObjC.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|

    s.name         = "DoObjC"
    s.version      = "0.0.1"
    s.summary      = "DoObjC is a library which in Objective-C language."
    s.description  = "DoObjC is a library which contain marco、utility、global、libs、modules、extensions & tools for Objective-C language"

    s.homepage     = "https://github.com/deepindo/DoObjC"
    s.license      = "MIT"
    s.author       = { "deepindo" => "732872042@qq.com" }
    s.platform     = :ios
    s.ios.deployment_target = "9.0"

    s.source       = { :git => "https://github.com/deepindo/DoObjC.git", :tag => "0.0.1" }
    # s.source_files  = "Classes", "Classes/**/*.{h,m}"
    s.source_files = 'DoObjC/Classes/**/*{h,m}'

    s.requires_arc = true
    # s.dependency 'AFNetworking', '~> 4.0.1'
        
    # s.resource  = "icon.png"
    # s.resources = "Resources/*.png"
    # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
    # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

    # s.resource_bundles = {
    #   'DoObjC' => ['DoObjC/Assets/*.png']
    # }

    # s.exclude_files = "Classes/Exclude"
    # s.public_header_files = "Classes/**/*.h"
    
    # s.preserve_paths = "FilesToSave", "MoreFilesToSave"
    # s.framework  = "SomeFramework"
    # s.frameworks = "SomeFramework", "AnotherFramework"
    # s.library   = "iconv"
    # s.libraries = "iconv", "xml2"
    
    # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
    # s.dependency "JSONKit", "~> 1.4"
    # s.public_header_files = 'Pod/Classes/**/*.h'
    # s.frameworks = 'UIKit', 'MapKit'
    
end
