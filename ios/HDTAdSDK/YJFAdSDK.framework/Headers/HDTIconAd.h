//
//  HDTIconAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/28.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class HDTIconAd;

@protocol HDTIconAdDelegate <NSObject>

@optional

/// icon广告数据加载成功
/// @param iconAd 广告实例
- (void)hdt_iconAdDidLoadSuccess:(HDTIconAd *)iconAd;

/// icon广告加载失败
/// @param iconAd 广告实例
/// @param error 错误原因
- (void)hdt_iconAdLoadFailure:(HDTIconAd *)iconAd faiureError:(NSError *)error;

/// icon广告被用户关闭时调用
/// @param iconAd 广告实例
- (void)hdt_iconAdClosed:(HDTIconAd *)iconAd;

/// icon广告已经曝光
/// @param iconAd 广告实例
- (void)hdt_iconAdDidExposure:(HDTIconAd *)iconAd;

/// icon广告被点击
/// @param iconAd 广告实例
- (void)hdt_iconAdDidClicked:(HDTIconAd *)iconAd;

@end

@interface HDTIconAd : NSObject
@property (nonatomic, weak) id<HDTIconAdDelegate> delegate;

/**
 * 构造方法
 * @param placementId  广告位ID
 * @param controller  展示icon的控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId showController:(UIViewController *)controller;

/**
 * 构造方法
 * @param placementId  广告位ID
 * @param controller  展示icon的控制器
 * @param userId 用户ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId showController:(UIViewController *)controller userId:(NSString *)userId;

/**
 * 拉取并展示广告
 */
- (void)loadAdAndShow;

@end

NS_ASSUME_NONNULL_END
