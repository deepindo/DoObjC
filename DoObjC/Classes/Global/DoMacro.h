//
//  DoMacro.h
//  DoDemo
//
//  Created by deepindu on 2021/4/19.
//

#ifndef DoMacro_h
#define DoMacro_h


#pragma mark - 方法缩写(仅依赖系统API, 不依赖第三方的)

#define DoImage(i)         ([UIImage imageNamed:i])          /// 图片
#define DoSysFont(i)       ([UIFont systemFontOfSize:i])     /// 系统默认字体
#define DoSysBoldFont(i)   ([UIFont fontWithName:@"Helvetica-Bold" size:i]) /// 系统粗体
#define DoRGB(r,g,b)        ([UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]) /// RGB颜色，非透明
#define DoRGBA(r,g,b,a)     ([UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a])   /// RGB颜色，有透明
#define DoHexColor(i)       ([UIColor colorWithHEX:i]) /// 十六进制颜色值

/**
    以下写法，到时候，得改weakSelf & strongSelf
 */
#define DoWeakSelf          __weak typeof(self) weakSelf = self;
#define DoStrongSelf        __strong typeof(weakSelf) strongSelf = weakSelf;

//#define DoWeakify(o)          __weak   typeof(self) weakSelf = o;
//#define DoStrongify(o)        __strong typeof(weakSelf) strongSelf = weakSelf;


#pragma mark - 方法缩写(依赖第三方的)

#define DoNotice(i)    ([DDPopup popupCustomText:i])  // 文字toast




#pragma mark - 偏好设置

//#define kToken         @"token"
//#define kName          @"name"
//#define kUserName      @"username"
//#define kRoleName      @"role_name"
//#define kUserId        @"id"
//#define kSex           @"sex"
//#define kUnreadCount   @"unreadCount"
//#define kDepartment    @"department"
//#define kAvatar        @"avatar"
//#define kType          @"type"
//#define kComponent     @"kComponent"
//#define kMaterial      @"kMaterial"

#endif /* DoMacro_h */
