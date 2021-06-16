//
//  DoObjC.h
//  DoDemo
//
//  Created by deepindu on 2021/6/16.
//

#ifndef DoObjC_h
#define DoObjC_h

// !!!: - 基类的头文件，相互依赖

#import "DoVC.h"             /// ViewController基类
#import "DoNavC.h"           /// 导航栏控制器基类
//#import "DoTabBarC.h"        /// TabBarController基类

#import "DoSysVC.h"          /// 基类VC(系统的导航栏)
#import "DoSysWebVC.h"       /// WKWebView基类VC(系统的导航栏)
#import "DoSysTableVC.h"     /// UITableView基类VC(系统的导航栏)

//#import "DoCusVC.h"          /// 基类VC(自定义的导航栏)
//#import "DoCusWebVC.h"       /// WKWebView基类VC(自定义的导航栏)
//#import "DoCusTableVC.h"     /// UITableView基类VC(自定义的导航栏)

//#import "DoTableViewCell.h"  /// 自定义封装UITableViewCell基类


//#import "DoTabBarC.h"
//#import "DoBaseVC.h"
//#import "DoBaseNavC.h"   /// NavigationController基类
//#import "DoBaseWebVC.h"


// !!!: - 工具类的头文件，相互依赖
// MARK: - 全局配置类的头文件

#import "DoMacro.h"      /// 通用宏
//#import "DoColorMacro.h"  /// 颜色配置类
#import "DoSizeDefine.h"   /// 尺寸变量类


// !!!: - 系统类

// 全局方法

#import "DoUtility.h"       /// 自定义方法类

//#import "DoFuncs.h"       /// 自定义方法类
#import "DoApps.h"        /// 自定义app相关
//#import "DoPermission.h"  /// 自定义权限类

// You can define DoPrintEnable & DoLogEnable macro before import DoLog.h
#ifdef DEBUG
#define DoPrintEnable 1
#else
#define DoPrintEnable 0
#endif

#ifdef DEBUG
#define DoLogEnable 1
#else
#define DoLogEnable 0
#endif
#import "DoLog.h"


// !!!: - Category类的头文件，相互依赖


// MARK: - 网络类的头文件
//#import "DoNetworkAPI.h"       /// 网络链接API管理类
//#import "DoNetwork+Requests.h" /// 网络方法封装类


// MARK: - 数据库类的头文件










// !!!: - 系统类

// !!!: - 第三方库的头文件，内部
// 第三方
//#import "Masonry.h"
//#import "TABAnimated.h"
//#import "MJExtension.h"
//#import "MJRefresh.h"
//
//#import "MBProgressHUD.h"
//#import "SVProgressHUD.h"
//
//#import "SDCycleScrollView.h"
//#import "BRPickerView.h"
//#import "GKPhotoBrowser.h"
//#import "IQKeyboardManager.h"
//#import "TZImagePickerController.h"

//#import "UIView+Toast.h"
//#import <DZNEmptyDataSet/UIScrollView+EmptyDataSet.h>


// 旧的扩展，后期更新
//#import "UIColor+BS.h"
//#import "UILabel+BS.h"
//#import "UIImage+BS.h"
//#import "NSString+BS.h"
//
//#import "UIKit+AFNetworking.h"
//
//#import "SDImageCache.h"
//#import "UIImageView+WebCache.h"
////#import "FWPopupBaseView.h"
////?????
//#import "CFMacro.h"
//#import "UIView+CFFrame.h"
//#import "DDPopup.h"
//#import "FonerySystem.h"




// Category

//#import "UIView+Do.h"

#endif /* DoObjC_h */
