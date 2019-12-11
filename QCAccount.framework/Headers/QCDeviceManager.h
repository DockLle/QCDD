//
//  QCDeviceManager.h
//  QCAccount
//
//  Created by Wp on 2019/12/6.
//  Copyright © 2019 Reo. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void(^Result) (BOOL success, id data);


@protocol QCDeviceManagerDelegate <NSObject>

- (void)managerDidReceiveDeviceInfo:(id)deviceInfo;//

@end

@interface QCDeviceManager : NSObject

@property (nonatomic,strong) id<QCDeviceManagerDelegate> delegate;

+ (instancetype)shared;

/// 注册设备监听
- (void)registerDeviceActiveComplete:(Result)complete;

/// 获取设备列表
- (void)getDeviceListComplete:(Result)complete;

/// 绑定设备
/// @param signatureInfo 配网成功产生的签名信息
- (void)bindDevice:(NSString *)signatureInfo complete:(Result)complete;

/// 解绑设备
/// @param productId 产品id
/// @param deviceName 设备名
- (void)deleteDevice:(NSString *)productId andDeviceName:(NSString *)deviceName complete:(Result)complete;

/// 获取设备详情
/// @param productId 产品id
/// @param deviceName 设备名
- (void)getDeviceInfo:(NSString *)productId andDeviceName:(NSString *)deviceName complete:(Result)complete;

/// 上报数据
/// @param deviceData 要上报的设备信息
- (void)reportDeviceData:(NSDictionary *)deviceData productId:(NSString *)productId andDeviceName:(NSString *)deviceName complete:(Result)complete;

/// 修改设备别名
/// @param aliasName 别名
- (void)modifyAliasName:(NSString *)aliasName ByProductId:(NSString *)productId andDeviceName:(NSString *)deviceName complete:(Result)complete;
@end
