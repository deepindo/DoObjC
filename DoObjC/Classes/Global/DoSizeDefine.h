//
//  DoSizeDefine.h
//  ZBBao
//
//  Created by deepindo on 2020/6/18.
//

#ifndef DoSizeDefine_h
#define DoSizeDefine_h


#pragma mark - 全局变量

/*
 /// UIDeviceOrientation是设备的方向，只能读，不能修改
 UIDeviceOrientationIsLandscape([kSharedApplication statusBarOrientation])
 */
#define kISPortrait            UIInterfaceOrientationIsPortrait([[UIApplication sharedApplication] statusBarOrientation])   /// 是否是竖屏
#define kISLandscape           UIInterfaceOrientationIsLandscape([[UIApplication sharedApplication] statusBarOrientation])   /// 是否是横屏

#define kSharedApplication      ([UIApplication sharedApplication])             /// 主程序
#define kSharedWindow           ([UIApplication sharedApplication].keyWindow)   /// 主window
#define kSharedDelegate         ([UIApplication sharedApplication].delegate)    /// 主delegate
#define kUserDefaults           ([NSUserDefaults standardUserDefaults])         /// 偏好设置
#define kScreenBounds           ([UIScreen mainScreen].bounds)   /// 屏幕区域
#define kScreenSize             ([UIScreen mainScreen].bounds.size)         /// 屏幕尺寸
#define kScreenWidth            (kISPortrait ? [UIScreen mainScreen].bounds.size.width : [UIScreen mainScreen].bounds.size.height)   /// 屏幕屏宽
#define kScreenHeight           (kISPortrait ? [UIScreen mainScreen].bounds.size.height : [UIScreen mainScreen].bounds.size.width)   /// 屏幕屏高
#define kScreenScale            (kScreenWidth / 375)                        /// 屏幕比例
#define kUIAdapter(v)           (v*(kScreenWidth / 375))              /// 尺寸适配
#define kRectAdapter(x,y,w,h)   (CGRectMake(kUIAdapter(x), kUIAdapter(y), kUIAdapter(w), kUIAdapter(h)))              /// rect适配

#define kISIPhoneX_Serial       ([[UIApplication sharedApplication] statusBarFrame].size.height > 20 ? YES : NO)
#define kNavBarH                (kISIPhoneX_Serial == YES ? 88 : 64)  /// 导航栏高度
#define kTabBarH                (kISIPhoneX_Serial == YES ? 83 : 49)  /// 底部Tabbar高度
#define kStatusBarH             (kISIPhoneX_Serial == YES ? 44 : 20)  /// 状态栏高度
#define kSafeAreaBottomHeight   (kISIPhoneX_Serial == YES ? 34 : 0)   /// 底部安全区高度


#endif /* DoSizeDefine_h */
