//
//  YJFEmbeddedWebAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/11/3.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YJFEmbeddedWebAd;
@protocol YJFEmbeddedWebAdDelegate <NSObject>

@optional

/// 数据加载成功
/// @param embeddedWebAd 广告实例
- (void)yjf_embeddedWebAdLoadSuccess:(YJFEmbeddedWebAd *)embeddedWebAd;

/// 加载失败
/// @param embeddedWebAd 广告实例
/// @param error 错误信息
- (void)yjf_embeddedWebAdLoadFailure:(YJFEmbeddedWebAd *)embeddedWebAd failureError:(NSError *)error;

/// 需要登录
/// @param embeddedWebAd 广告实例
- (void)yjf_embeddedWebAdNeedLogin:(YJFEmbeddedWebAd *)embeddedWebAd;

@end

@interface YJFEmbeddedWebAd : NSObject
@property (nonatomic, weak) id<YJFEmbeddedWebAdDelegate> delegate;

/**
 * web是否可以返回上一页
 */
@property (nonatomic, readonly, getter=canGoBack) BOOL canGoBack;

/**
 * 可选的，用户唯一标识，用于给用户发放奖励。
 */
@property (nonatomic, copy) NSString *userId;

/**
 * 构造方法
 * @param placementId  活动ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 * 拉取活动
 * @return UIViewController
 */
- (UIViewController *)loadAd;

/**
 * 可选的，重新加载页面URL，用于登录后刷新页面
 * 注：在设置userId后调用
 */
- (void)reloadAdUrl;

/**
 * 返回上一页
 *  @return bool
 */
- (BOOL)goBack;

@end

NS_ASSUME_NONNULL_END
