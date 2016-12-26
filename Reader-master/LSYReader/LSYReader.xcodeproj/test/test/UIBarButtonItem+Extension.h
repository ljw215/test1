//
//  UIBarButtonItem+Extension.h
//  test
//
//  Created by ljw on 16/8/23.
//  Copyright © 2016年 ljw. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (Extension)
+ (instancetype)itemWithImage:(NSString *)image highImage:(NSString *)highImage target:(id)target action:(SEL)action;
@end
