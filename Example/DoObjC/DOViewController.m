//
//  DOViewController.m
//  DoObjC
//
//  Created by deepin on 06/16/2021.
//  Copyright (c) 2021 deepin. All rights reserved.
//

#import "DOViewController.h"
#import "DoObjC.h"

@interface DOViewController ()

@end

@implementation DOViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    self.view.backgroundColor = [UIColor cyanColor];
    
    DoLog(kScreenWidth);
    
    DoLog(kScreenHeight);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
