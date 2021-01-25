//
//  ViewController.m
//  YJFShow
//
//  Created by 胡庚伟 on 2020/12/15.
//

#import "ViewController.h"

#import <YJFAdSDK/YJFNoEntranceWebAd.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>

@interface ViewController ()
@property (strong, nonatomic) UIImageView *bannerView;
@property (strong, nonatomic) UIImageView *iconView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupViews];
}

#pragma mark-- action
- (void)bannerAction
{
    [[[YJFAd alloc] init] loadAdAndShow:BannerID viewController:self];
}

- (void)iconAction
{
    [[[YJFAd alloc] init] loadAdAndShow:IconID viewController:self];
}

#pragma mark-- setup
- (void)setupViews {
    
    UIImage *image = [UIImage imageNamed:@"home_bg"];
    UIImageView *bgImg = [[UIImageView alloc] initWithImage:image];
    bgImg.frame = CGRectMake(0, 0, self.view.width, bgImg.height);
    [self.view addSubview:bgImg];
    
    [self.view addSubview:self.bannerView];
    [self.bannerView mas_makeConstraints:^(MASConstraintMaker *make) {
        if (YJFIsIphoneXSeries()) {
            make.top.equalTo(self.view).offset(kScale(62));
            make.height.offset(kScale(108));
        } else {
            make.top.equalTo(self.view).offset(kScale(70));
            make.height.offset(kScale(111));
        }
        make.left.right.equalTo(self.view).inset(kScale(10));
    }];
    
    [self.view addSubview:self.iconView];
    [self.iconView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.view).inset(kScale(50)+YJFSafeAreaBottomHeight()+YJFTabbarHeight());
        make.right.equalTo(self.view).inset(kScale(10));
        make.height.width.offset(kScale(50));
    }];
    
}

#pragma mark-- getter method
- (UIImageView *)bannerView
{
    if (!_bannerView) {
        _bannerView = [[UIImageView alloc] init];
        _bannerView.userInteractionEnabled = YES;
        _bannerView.image = [UIImage imageNamed:@"home_banner"];
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(bannerAction)];
        [_bannerView addGestureRecognizer:tap];
    }
    return _bannerView;
}

- (UIImageView *)iconView
{
    if (!_iconView) {
        _iconView = [[UIImageView alloc] init];
        _iconView.userInteractionEnabled = YES;
        _iconView.image = [UIImage imageNamed:@"home_icon"];
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(iconAction)];
        [_iconView addGestureRecognizer:tap];
    }
    return _iconView;
}

@end
