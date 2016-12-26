//
//  MacroDefinition.h
//
//  Created by ljw on 14-6-9.
//  Copyright (c) 2013年 ljw. All rights reserved.
//

#ifndef MacroDefinition_h
#define MacroDefinition_h

//NavBar高度
#define NavigationBar_Height 44

//屏幕宽、高
#define Screen_Width ([UIScreen mainScreen].bounds.size.width)
#define Screen_Height ([UIScreen mainScreen].bounds.size.height)

//1个像素的宽度
#define Single_Line_Width (1.0f/[UIScreen mainScreen].scale)

//系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define IS_IOS6 (IOS_VERSION >= 6.0 && IOS_VERSION < 7)
#define IS_IOS7 (IOS_VERSION >= 7.0 && IOS_VERSION < 8.0)
#define IS_IOS8 (IOS_VERSION >= 8.0 && IOS_VERSION < 9.0)
#define IS_IOS9 (IOS_VERSION >= 9.0 && IOS_VERSION < 10.0)
#define IOS7AndLater (IOS_VERSION >= 7.0)
#define IOS8AndLater (IOS_VERSION >= 8.0)

//图片
/** png格式 */
#define ImageWithPngName(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:@"png"]]
/** jpg格式 */
#define ImageWithJpegName(B) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:B ofType:@"jpg"]]

/** rgb颜色(十进制) */
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)
/** 设置随机颜色 */
#define RandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]


/** rgb颜色(十六进制) */
#define HexRGB(rgbValue) \
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0] \

//清除背景色
#define ClearColor [UIColor clearColor]

/** 弱指针*/
#define kWeakSelf(weakSelf) __weak __typeof(&*self)weakSelf = self;

//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
/** 当前国家 */
#define LOCAL_COUNTRY [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode]


//判断是否 Retina屏、设备是否iPhone 5、是否是iPad
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

// 设备判断
#define is_Phone [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone
#define is_Pad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//NSUserDefaults等 实例化
#define User_Default [NSUserDefaults standardUserDefaults]
#define Noti_Center [NSNotificationCenter defaultCenter]
#define UI_Application [UIApplication shareApplication]
#define File_Manager [NSFileManager defaultManager]

#define CacheDir [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
#define DocumentDir [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
#define TempDir NSTemporaryDirectory()

/** 获取相机权限状态（一般是直接用下面两个 拒绝或同意）*/
#define SXCameraStatus [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo]
#define SXCameraDenied ((SXCameraStatus == AVAuthorizationStatusRestricted)||(SXCameraStatus == AVAuthorizationStatusDenied))
#define SXCameraAllowed (!SXCameraDenyed)

/** 定位权限*/
#define SXLocationStatus [CLLocationManager authorizationStatus];
#define SXLocationAllowed ([CLLocationManager locationServicesEnabled] && !((status == kCLAuthorizationStatusDenied) || (status == kCLAuthorizationStatusRestricted)))
#define SXLocationDenied (!SXLocationAllowed)

//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

/** iPhone的型号 */
#define IS_IPHONE4 ([[UIScreen mainScreen] bounds].size.height == 480)
#define IS_IPHONE5 ([[UIScreen mainScreen] bounds].size.height == 568)
#define IS_IPHONE6 ([[UIScreen mainScreen] bounds].size.height == 667)
#define IS_IPHONE6_PLUS ([[UIScreen mainScreen] bounds].size.height == 736)

/** APP版本号 */
#define APP_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

/** APP BUILD 版本号 */
#define APP_BUILD_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

/** APP名字 */
#define APP_DISPLAY_NAME  [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]

/** 判断设备是真机还是模拟器 */
#if TARGET_OS_IPHONE
#endif

#if TARGET_IPHONE_SIMULATOR
#endif

/** 判断系统为64位还是32位 */
#if __LP64__
NSLog(@"64");
#else
NSLog(@"32");
#endif

/** 字体大小 */
#define kUIFontWithName(NAME,FONTSIZE) [UIFont fontWithName:(NAME) size:(FONTSIZE)]
#define kUIFond(FONTSIZE)    [UIFont systemFontOfSize:FONTSIZE]
#define kUIFondWithBold(FONTSIZE)   [UIFont boldSystemFontOfSize:FONTSIZE]

/** 设置 view 圆角和边框 */


#define LRViewBorderRadius(View, Radius, Width, Color)\

\

[View.layer setCornerRadius:(Radius)];\

[View.layer setMasksToBounds:YES];\

[View.layer setBorderWidth:(Width)];\

[View.layer setBorderColor:[Color CGColor]]

//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

// 加载

#define kShowNetworkActivityIndicator() [UIApplication sharedApplication].networkActivityIndicatorVisible = YES

// 收起加载

#define HideNetworkActivityIndicator()      [UIApplication sharedApplication].networkActivityIndicatorVisible = NO

// 设置加载

#define NetworkActivityIndicatorVisible(x)  [UIApplication sharedApplication].networkActivityIndicatorVisible = x
//window
#define kWindow [UIApplication sharedApplication].keyWindow


/*
 //define this constant if you want to use Masonry without the 'mas_' prefix
 #define MAS_SHORTHAND
 //define this constant if you want to enable auto-boxing for default syntax
 #define MAS_SHORTHAND_GLOBALS
 #import "Masonry.h"
 */


//DEBUG模式下,打印日志(包括函数名、行号)
#ifdef DEBUG
/** debug模式下代替NSLog */
# define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
/** release */
# define DLog(...)
#endif
#define DLogFunc DLog(@"%s", __func__)

#endif


#endif
