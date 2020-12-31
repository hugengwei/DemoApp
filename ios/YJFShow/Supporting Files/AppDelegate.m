//
//  AppDelegate.m
//  YJFShow
//
//  Created by 胡庚伟 on 2020/12/15.
//

#import "AppDelegate.h"

#import <HDTAdSDK/HDTSDKManager.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>

#import "ViewController.h"
#import "ActivitiesVC.h"
#import "IntegralMallVC.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    /// 初始化SDK
    [HDTSDKManager registerAppId:MediaID];
    /// 开启debug调试
    [HDTSDKManager enableDebuging:YES];
    
    [UIApplication sharedApplication].statusBarHidden = NO;
    self.window = [[UIWindow alloc] init];
    self.window.frame = [UIScreen mainScreen].bounds;
    
    UITabBarController *tabbar = [[UITabBarController alloc] init];
    tabbar.tabBar.barTintColor = UIColor.whiteColor;
    tabbar.viewControllers = self.viewControllers;
    [self.window setRootViewController:tabbar];
    
    [self.window makeKeyAndVisible];
    return YES;
}

- (NSArray *)viewControllers
{
    ViewController *home = [[ViewController alloc] init];
    [self setTabBarItem:home.tabBarItem
                      title:@""
                  titleSize:13.0
              titleFontName:@"HeiTi SC"
              selectedImage:@"tabbar_home"
         selectedTitleColor:[UIColor clearColor]
                normalImage:@"tabbar_home"
           normalTitleColor:[UIColor clearColor]];
    
    ActivitiesVC *activities = [[ActivitiesVC alloc] init];
    [self setTabBarItem:activities.tabBarItem
                      title:@""
                  titleSize:13.0
              titleFontName:@"HeiTi SC"
              selectedImage:@"tabbar_activities"
         selectedTitleColor:[UIColor clearColor]
                normalImage:@"tabbar_activities"
           normalTitleColor:[UIColor clearColor]];
    
    IntegralMallVC *integralMall = [[IntegralMallVC alloc] init];
    [self setTabBarItem:integralMall.tabBarItem
                      title:@""
                  titleSize:13.0
              titleFontName:@"HeiTi SC"
              selectedImage:@"tabbar_integralmall"
         selectedTitleColor:[UIColor clearColor]
                normalImage:@"tabbar_integralmall"
           normalTitleColor:[UIColor clearColor]];
    
    return @[home,activities,integralMall];
}

- (void)setTabBarItem:(UITabBarItem *)tabbarItem
                title:(NSString *)title
            titleSize:(CGFloat)size
        titleFontName:(NSString *)fontName
        selectedImage:(NSString *)selectedImage
   selectedTitleColor:(UIColor *)selectColor
          normalImage:(NSString *)unselectedImage
     normalTitleColor:(UIColor *)unselectColor
{
    
    //设置图片
    tabbarItem = [tabbarItem initWithTitle:title image:[[UIImage imageNamed:unselectedImage]imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal] selectedImage:[[UIImage imageNamed:selectedImage]imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal]];
    
    // S未选中字体颜色
    [[UITabBarItem appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName:unselectColor,NSFontAttributeName:[UIFont fontWithName:fontName size:size]} forState:UIControlStateNormal];
    
    // 选中字体颜色
    [[UITabBarItem appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName:selectColor,NSFontAttributeName:[UIFont fontWithName:fontName size:size]} forState:UIControlStateSelected];
}

@end
