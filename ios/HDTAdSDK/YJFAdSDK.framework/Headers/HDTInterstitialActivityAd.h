//
//  HDTInterstitialActivityAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/28.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class HDTInterstitialActivityAd;

@protocol HDTInterstitialActivityAdDelegate <NSObject>

@optional

/// 插屏活动广告数据加载成功
/// @param interstitialActivityAd 广告实例
- (void)hdt_interstitialActivityAdLoadSuccess:(HDTInterstitialActivityAd *)interstitialActivityAd;

/// 插屏活动广告已展现
/// @param interstitialActivityAd 广告实例
- (void)hdt_interstitialActivityAdDidExposure:(HDTInterstitialActivityAd *)interstitialActivityAd;

/// 插屏活动广告加载失败
/// @param interstitialActivityAd 广告实例
/// @param error 错误信息
- (void)hdt_interstitialActivityAdLoadFailure:(HDTInterstitialActivityAd *)interstitialActivityAd failureError:(NSError *)error;

@end

@interface HDTInterstitialActivityAd : NSObject

@property (nonatomic, weak) id<HDTInterstitialActivityAdDelegate> delegate;

/**
 * 构造方法
 * @param placementId - 广告位 ID
 * @return HDTRewardVideoAd 实例
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;


/**
 * 加载并展示广告方法
 */
- (void)preLoadActivity;

/**
 * 展示插屏活动
 * @param viewController 广告展示的容器
 */
- (void)showPreActivityWithViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
