//
//  YJFNoEntranceWebAd.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/11/3.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class YJFNoEntranceWebAd;
@protocol YJFNoEntranceWebAdDelegate <NSObject>

@optional

/// 数据加载成功
/// @param noEntranceWebAd 广告实例
- (void)yjf_noEntranceWebAdLoadSuccess:(YJFNoEntranceWebAd *)noEntranceWebAd;

/// 加载失败
/// @param noEntranceWebAd 广告实例
/// @param error 错误信息
- (void)yjf_noEntranceWebAdLoadFailure:(YJFNoEntranceWebAd *)noEntranceWebAd failureError:(NSError *)error;

/// 需要登录
/// @param noEntranceWebAd 广告实例
- (void)yjf_noEntranceWebAdNeedLogin:(YJFNoEntranceWebAd *)noEntranceWebAd;

@end

@interface YJFNoEntranceWebAd : NSObject

/**
 *  可选的，用户唯一标识，用于给用户发放奖励。
 */
@property (nonatomic, copy) NSString *userId;

/**
 *  是否展示状态栏
 */
@property (nonatomic, assign) BOOL isShowStatusBar;

@property (nonatomic, weak) id<YJFNoEntranceWebAdDelegate> delegate;

/**
 *  构造方法
 * @param placementId 活动ID
 * @param viewController  viewController - 用于页面跳转的视图控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId viewController:(UIViewController *)viewController;

/**
 * 拉取并展示活动
 */
- (void)loadAdAndShow;

/**
 * 可选的，重新加载页面URL，用于登录后刷新页面
 * 注：在设置userId后调用
 */
- (void)reloadAdUrl;
@end

NS_ASSUME_NONNULL_END
