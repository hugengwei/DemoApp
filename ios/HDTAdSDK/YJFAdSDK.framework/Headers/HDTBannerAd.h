//
//  HDTBannerAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/24.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class HDTBannerAd;

@protocol HDTBannerAdDelegate <NSObject>

@optional

/// banner广告数据加载成功回调
/// @param bannerAd 广告实例
- (void)hdt_bannerAdDidLoadSuccess:(HDTBannerAd *)bannerAd;

/// banner广告数据加载失败回调
/// @param bannerAd 广告实例
/// @param error 错误信息
- (void)hdt_bannerAdDidLoadFailure:(HDTBannerAd *)bannerAd failureError:(NSError *)error;

/// banner广告已曝光
/// @param bannerAd 广告实例
- (void)hdt_bannerAdDidExposure:(HDTBannerAd *)bannerAd;

/// banner广告被点击
/// @param bannerAd 广告实例
- (void)hdt_bannerAdDidClicked:(HDTBannerAd *)bannerAd;

@end

@interface HDTBannerAd : NSObject

@property (nonatomic, weak) id<HDTBannerAdDelegate> delegate;

/**
 * 构造方法
 * @param placementId  广告位ID
 * @param view  展示banner的容器
 * @param viewController  viewController - 用于页面跳转的视图控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId showView:(UIView *)view viewController:(UIViewController *)viewController;

/**
 * 构造方法
 * @param placementId  广告位ID
 * @param view  展示banner的容器
 * @param viewController  viewController - 用于页面跳转的视图控制器
 * @param userId  userId - 用户ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId showView:(UIView *)view viewController:(UIViewController *)viewController userId:(NSString *)userId;

/**
 * 拉取并展示广告
 */
- (void)loadAdAndShow;

@end

NS_ASSUME_NONNULL_END
