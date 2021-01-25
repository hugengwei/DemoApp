//
//  HDTInterstitialWebAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/10/14.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class HDTInterstitialWebAd;
@protocol HDTInterstitialWebAdDelegate <NSObject>

@optional

/// 插屏广告数据加载成功
/// @param interstitialWebAd 广告实例
- (void)hdt_interstitialWebAdLoadSuccess:(HDTInterstitialWebAd *)interstitialWebAd;

/// 插屏广告加载失败
/// @param interstitialWebAd 广告实例
/// @param error 错误信息
- (void)hdt_interstitialWebAdLoadFailure:(HDTInterstitialWebAd *)interstitialWebAd failureError:(NSError *)error;

/// interstitial广告被用户关闭时调用
/// @param interstitialWebAd 广告实例
- (void)hdt_interstitialWebAdClosed:(HDTInterstitialWebAd *)interstitialWebAd;

/// interstitial广告已经曝光
/// @param interstitialWebAd 广告实例
- (void)hdt_interstitialWebAdDidExposure:(HDTInterstitialWebAd *)interstitialWebAd;

@end

@interface HDTInterstitialWebAd : NSObject

@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, weak) id<HDTInterstitialWebAdDelegate> delegate;

/**
 * 构造方法
 * @param placementId  广告位ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/// 加载并显示广告
/// @param controller  控制器
- (void)loadAdAndShowWithViewController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
