//
//  IPDFCameraViewController.h
//  InstaPDF
//
//  Created by Maximilian Mackh on 06/01/15.
//  Copyright (c) 2015 mackh ag. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,IPDFCameraViewType)
{
    IPDFCameraViewTypeBlackAndWhite,
    IPDFCameraViewTypeNormal
};

@interface IPDFCameraViewController : UIView

- (void)setupCameraView;

- (void)start;
- (void)stop;

@property (nonatomic, assign, getter=isBorderDetectionEnabled) BOOL enableBorderDetection;
@property (nonatomic, assign, readonly, getter=isTorchSupported) BOOL torchSupported;
@property (nonatomic, assign, getter=isTorchEnabled) BOOL enableTorch;

@property (nonatomic, assign) float refreshInterval;
@property (nonatomic, assign) BOOL postEdit;
@property (nonatomic, assign) void(^overlayRenderBlock)(CGContextRef ctx, CGRect rect, CGPoint topLeft, CGPoint topRight, CGPoint bottomLeft, CGPoint bottomRight);

@property (nonatomic,assign) IPDFCameraViewType cameraViewType;

- (void)overrideOverlayRenderMethod:(void(^)(CGContextRef ctx, CGRect rect, CGPoint topLeft, CGPoint topRight, CGPoint bottomLeft, CGPoint bottomRight)) block;
- (void)setEnableBorderDetection:(BOOL)enable;
- (void)focusAtPoint:(CGPoint)point completionHandler:(void(^)())completionHandler;
- (void)captureImageWithCompletionHander:(void(^)(NSString *imageFilePath))completionHandler;
- (void)captureImageForPostEditWithCompletionHander:(void(^)(NSString *imgPath, NSArray *features))handler;
- (void)setBorderDetectionFrameStyle:(UIColor *)fill border:(UIColor *)borderColor borderWidth:(float) width;

@end
