//
//  HDTInterstitialAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/24.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class HDTInterstitialAd;

@protocol HDTInterstitialAdDelegate <NSObject>

@optional

/// 插屏广告数据加载成功
/// @param interstitialAd 广告实例
- (void)hdt_interstitialAdLoadSuccess:(HDTInterstitialAd *)interstitialAd;

/// 插屏广告加载失败
/// @param interstitialAd 广告实例
/// @param error 错误信息
- (void)hdt_interstitialAdLoadFailure:(HDTInterstitialAd *)interstitialAd failureError:(NSError *)error;

/// interstitial广告被用户关闭时调用
/// @param interstitialAd 广告实例
- (void)hdt_interstitialAdClosed:(HDTInterstitialAd *)interstitialAd;

/// interstitial广告已经曝光
/// @param interstitialAd 广告实例
- (void)hdt_interstitialAdDidExposure:(HDTInterstitialAd *)interstitialAd;

/// interstitial广告被点击
/// @param interstitialAd 广告实例
- (void)hdt_interstitialAdDidClicked:(HDTInterstitialAd *)interstitialAd;

@end

@interface HDTInterstitialAd : NSObject

@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, weak) id<HDTInterstitialAdDelegate> delegate;

/**
 * 构造方法
 * @param placementId  广告位ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 * 构造方法
 * @param placementId  广告位ID
 * @param userId  用户ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId userId:(NSString *)userId;

/**
 * 拉取广告请求方法
 */
- (void)loadAd;

/**
 * 广告位展示方法
 * @param rootViewController  发起展示广告请求, 必须传入用于显示插播广告的UIViewController
 */
- (void)showAdWithRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
