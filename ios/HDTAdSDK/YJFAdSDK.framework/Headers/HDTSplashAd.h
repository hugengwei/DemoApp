//
//  HDTSplashAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/23.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HDTSplashAd;

@protocol HDTSplashAdDelegate <NSObject>

@optional

/// 开屏广告素材加载成功
/// @param splashAd 广告实例
- (void)hdt_splashAdDidLoad:(HDTSplashAd *)splashAd;

/// 开屏广告展示成功
/// @param splashAd 广告实例
- (void)hdt_splashAdShowSuccess:(HDTSplashAd *)splashAd;

/// 开屏广告展示失败
/// @param splashAd 广告实例
/// @param error 错误信息
- (void)hdt_splashAdShowFailure:(HDTSplashAd *)splashAd failure:(NSError *)error;

/// 开屏广告点击回调
/// @param splashAd 广告实例
- (void)hdt_splashAdClicked:(HDTSplashAd *)splashAd;

/// 开屏广告关闭回调
/// @param splashAd 广告实例
- (void)hdt_splashAdClosed:(HDTSplashAd *)splashAd;

/// 开屏广告剩余时间回调
/// @param time 剩余时间
- (void)hdt_splashAdLifeTime:(NSUInteger)time;

@end

@interface HDTSplashAd : NSObject

@property (nonatomic, weak) id<HDTSplashAdDelegate> delegate;

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) CGFloat fetchDelay;

/**
 * 开屏广告的背景图片；可以设置背景图片作为开屏加载时的默认背景
 */
@property (nonatomic, strong) UIImage *backgroundImage;

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
 * 拉取数据并展示
 * @param window 开屏广告所在window
 * @param bottomView 底部logo展示容器
 */
- (void)loadAdAndShowWithWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

@end

NS_ASSUME_NONNULL_END
