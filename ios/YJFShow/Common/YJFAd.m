//
//  YJFAd.m
//  YJFShow
//
//  Created by 胡庚伟 on 2020/12/16.
//

#import "YJFAd.h"
#import <YJFAdSDK/YJFNoEntranceWebAd.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>

@interface YJFAd ()<YJFNoEntranceWebAdDelegate>
@property (nonatomic, strong) YJFNoEntranceWebAd *noEntranceWebAd;
@end

@implementation YJFAd

- (void)loadAdAndShow:(NSString *)placementId viewController:(UIViewController *)controller {
    self.noEntranceWebAd = [[YJFNoEntranceWebAd alloc] initWithPlacementId:placementId viewController:controller];
    self.noEntranceWebAd.delegate = self;
    self.noEntranceWebAd.userId = @"1";
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            [self.noEntranceWebAd loadAdAndShow];
        }];
    } else {
        [self.noEntranceWebAd loadAdAndShow];
    }
}

#pragma mark-- delegate
/// 数据加载成功
/// @param noEntranceWebAd 广告实例
- (void)yjf_noEntranceWebAdLoadSuccess:(YJFNoEntranceWebAd *)noEntranceWebAd
{
    
}

/// 加载失败
/// @param noEntranceWebAd 广告实例
/// @param error 错误信息
- (void)yjf_noEntranceWebAdLoadFailure:(YJFNoEntranceWebAd *)noEntranceWebAd failureError:(NSError *)error
{
    
}

/// 需要登录
/// @param noEntranceWebAd 广告实例
- (void)yjf_noEntranceWebAdNeedLogin:(YJFNoEntranceWebAd *)noEntranceWebAd
{
    
}

@end
