//
//  APBinAOPMsgSendMediator.h
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APBinAOPMsgSendMediator : NSObject

@property (nonatomic, assign) BOOL need_modify_arg;

@property (nonatomic, copy) NSString *message;

@end

NS_ASSUME_NONNULL_END
