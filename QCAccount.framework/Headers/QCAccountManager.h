//
//  QCAccountManager.h
//  QCAccount
//
//  Created by Wp on 2019/12/4.
//  Copyright © 2019 Reo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^Indicator)(BOOL success);

@interface QCAccountManager : NSObject

+ (instancetype)shared;

- (void)setAppId:(NSString *)appId onSuccess:(Indicator)result;

- (void)signInWithAccountName:(NSString *)name password:(NSString *)password complete:(Indicator)complete;
- (void)signOutWithResult:(Indicator)result;



@end

NS_ASSUME_NONNULL_END
