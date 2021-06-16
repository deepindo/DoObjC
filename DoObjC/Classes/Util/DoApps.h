//
//  DoApps.h
//  39
//
//  Created by deepindo on 2020/12/29.
//  Copyright © 2020 DD. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DoApps : NSObject

// 当前app的信息
+ (NSDictionary *)appInfoDict;

// app名称
+ (NSString *)appName;

// app版本
+ (NSString *)appVersion;

// app build版本
+ (NSString *)appBuild;

//手机别名: 用户定义的名称
+ (NSString *)appPhoneCusName;

// 设备名称
+ (NSString *)appSystemName;

// 手机系统版本
+ (NSString *)appSystemVersion;

// 手机型号
+ (NSString *)appPhoneModel;

// 本地化型号
+ (NSString *)appLocalizedModel;

@end

NS_ASSUME_NONNULL_END
