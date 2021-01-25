//
//  HDTOutputAdData.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/28.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class HDTOutputDataAd;

@interface HDTOutputAdData : NSObject

/// 主标题
@property (nonatomic, copy) NSString *mainTitle;

/// 副标题
@property (nonatomic, copy) NSString *subTitle;

/// 任务说明
@property (nonatomic, copy) NSString *taskDescription;

/// 创意logo
@property (nonatomic, copy) NSString *adCreativeLogo;

/// 是否是视频广告
@property (nonatomic, assign) BOOL isVideoAd;

/// 创意详情图
@property (nonatomic, copy) NSString *adCreativeDetailimg;

/// 创意缩略图
@property (nonatomic, copy) NSString *adCreativeThumbimg;

/// 计费链接
@property (nonatomic, copy) NSString *adClickUrl;

/// 任务类型多个以','分割(1-表单预约,2-下载,3-激活,4-注册,5-付费行为,6-下单,10-授信)
@property (nonatomic, copy) NSString *taskType;

@end

@protocol HDTOutputDataAdDelegate <NSObject>

@optional

/// 广告加载成功回调
/// @param rewardedVideoAd HDTOutputDataAd实例
- (void)hdt_outputDataAdDidLoad:(HDTOutputDataAd *)rewardedVideoAd;

/// 获取广告数据成功回调
/// @param rewardedVideoAd HDTOutputDataAd实例
/// @param data 广告数据实体
- (void)hdt_getAdData:(HDTOutputDataAd *)rewardedVideoAd didSuccessWithData:(NSArray<HDTOutputAdData *> *)data;

/// 获取广告数据失败回调
/// @param rewardedVideoAd HDTOutputDataAd实例
/// @param error 失败错误信息
- (void)hdt_getAdData:(HDTOutputDataAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/*
 * 以下为激励视频相关回调↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
 */

/// 视频广告数据加载成功回调
/// @param rewardedVideoAd HDTOutputDataAd实例
- (void)hdt_rewardVideoAdDidLoad:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频数据下载成功回调，已经下载过的视频会直接回调
/// @param rewardedVideoAd  HDTOutputDataAd实例
- (void)hdt_rewardVideoAdVideoDidLoad:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频播放页即将展示回调
/// @param rewardedVideoAd HDTOutputDataAd 实例
- (void)hdt_rewardVideoAdWillVisible:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频广告曝光回调
/// @param rewardedVideoAd HDTOutputDataAd 实例
- (void)hdt_rewardVideoAdDidExposed:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频播放页关闭回调
/// @param rewardedVideoAd HDTOutputDataAd 实例
- (void)hdt_rewardVideoAdDidClose:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频广告信息点击回调
/// @param rewardedVideoAd HDTOutputDataAd 实例
- (void)hdt_rewardVideoAdDidClicked:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频广告各种错误信息回调
/// @param rewardedVideoAd HDTOutputDataAd 实例
/// @param error 具体错误信息
- (void)hdt_rewardVideoAd:(HDTOutputDataAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/// 视频广告播放达到激励条件回调
/// @param rewardedVideoAd HDTOutputDataAd 实例
- (void)hdt_rewardVideoAdDidRewardEffective:(HDTOutputDataAd *)rewardedVideoAd;

/// 视频广告视频播放完成
/// @param rewardedVideoAd HDTOutputDataAd 实例
- (void)hdt_rewardVideoAdDidPlayFinish:(HDTOutputDataAd *)rewardedVideoAd;

@end

@interface HDTOutputDataAd : NSObject

@property (nonatomic, weak) id<HDTOutputDataAdDelegate> delegate;

/**
 * 构造方法
 * @param placementId - 广告位 ID
 * @return HDTRewardVideoAd 实例
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;


/**
 * 加载广告并获取广告数据方法
 * @param viewController 广告展示的容器
 */
- (void)loadAndGetAdDataWithRootViewController:(UIViewController *)viewController;

/**
 * 展示激励视频广告
 * 注：adType广告类型为2或3，即视频类型时，需调用该方法展示激励视频
 */
- (void)showRewardVideoAd;

@end

NS_ASSUME_NONNULL_END
