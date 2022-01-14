//
//  APBinAOPMsgSendMediator.m
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/7.
//

#import "APBinAOPMsgSendMediator.h"

@implementation APBinAOPMsgSendMediator

- (void)setMessage:(NSString *)message {
    NSLog(@">>>>>>>>message%@", message);
    _message = message;
}

@end
