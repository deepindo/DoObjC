//
//  DoApps.m
//  39
//
//  Created by deepindo on 2020/12/29.
//  Copyright © 2020 DD. All rights reserved.
//

#import "DoApps.h"

@implementation DoApps

// 当前app的信息
+ (NSDictionary *)appInfoDict {
    return [[NSBundle mainBundle] infoDictionary];
}

// app名称
+ (NSString *)appName {
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *name = [infoDict objectForKey:@"CFBundleDisplayName"];
    return name;
}

// app版本
+ (NSString *)appVersion {
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *version = [infoDict objectForKey:@"CFBundleShortVersionString"];
    return version;
}

// app build版本
+ (NSString *)appBuild {
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *build = [infoDict objectForKey:@"CFBundleVersion"];
    return build;
}

//手机别名: 用户定义的名称
+ (NSString *)appPhoneCusName {
    NSString *name = [[UIDevice currentDevice] name];
    return name;
}

// 设备名称
+ (NSString *)appSystemName {
    NSString *name = [[UIDevice currentDevice] systemName];
    return name;
}

// 手机系统版本
+ (NSString *)appSystemVersion {
    NSString *version = [[UIDevice currentDevice] systemVersion];
    return version;
}

// 手机型号
+ (NSString *)appPhoneModel {
    NSString *model = [[UIDevice currentDevice] model];
    return model;
}

// 本地化型号
+ (NSString *)appLocalizedModel {
    NSString *model = [[UIDevice currentDevice] localizedModel];
    return model;
}


@end
