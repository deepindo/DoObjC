//
//  DoNavC.m
//  DoDemo
//
//  Created by deepindu on 2021/4/7.
//

#import "DoNavC.h"

@interface DoNavC ()<UIGestureRecognizerDelegate>

@end

@implementation DoNavC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.interactivePopGestureRecognizer.delegate = self;
    [self.interactivePopGestureRecognizer setEnabled:YES];
}

/** 以下两个重写后，在viewController中设置显示风格或者隐藏才会生效
*/
- (UIViewController *)childViewControllerForStatusBarStyle {
    return self.topViewController;
}

- (UIViewController *)childViewControllerForStatusBarHidden {
    return self.topViewController;
}

#pragma mark - 重写push方法

/// 重写了push时的操作
/// 根据入栈数据，push时判断是否隐藏bottomBar
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {
    NSInteger cout = self.childViewControllers.count;
    //viewController.hidesBottomBarWhenPushed = cout > 0 ? YES : NO;
    
    /// 修复iOS14下的问题
    if (cout == 1) {
        viewController.hidesBottomBarWhenPushed = YES;
    } else {
        viewController.hidesBottomBarWhenPushed = NO;
    }
    [super pushViewController:viewController animated:animated];
}


#pragma mark - 手势代理方法

- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer {
    return self.viewControllers.count <= 1 ? NO : YES;
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return self.viewControllers.count <= 1 ? NO : YES;
}

@end
