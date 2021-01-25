//
//  HDTSDKManager.h
//  HDTAdSDK
//
//  Created by 胡庚伟 on 2020/6/17.
//  Copyright © 2020 胡庚伟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HDTSDKManager : NSObject

/// 开启debug调试日志 默认 NO
+ (void)enableDebuging:(BOOL)enable;

/**
 SDK 注册接口，请在 app 初始化时调用。
 @param appId - 媒体ID
*/
+ (void)registerAppId:(NSString *)appId;

/**
 * 获取 SDK 版本
 */

+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
