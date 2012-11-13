//
//  TCDAppDelegate.h
//  TinCanDemo
//
//  Created by Dan Frazee on 11/13/12.
//  Copyright (c) 2012 Maestro. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TCDViewController;

@interface TCDAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) TCDViewController *viewController;

@end
