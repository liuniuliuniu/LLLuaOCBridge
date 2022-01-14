//
//  LLLuaObject.h
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import "APBinAOPMsgSendMediator.h"

NS_ASSUME_NONNULL_BEGIN

@interface LLLuaObject : NSObject

@property (nonatomic, strong) APBinAOPMsgSendMediator *mediator;

/// 参数信息数组
/// index = 0 则为 mediatorInfo  切面信息
/// index = 1 则为 target             方法调用者
/// index = 2  则为 selString       方法名字符串
/// index = 3  args1         此方法的参数1，
/// index = 4  args2         此方法的参数2， （端上会按顺序依次将参数传入）
@property (nonatomic, strong) NSMutableArray *arguments;

- (void)updateObject:(id)object withIndex:(int)index;
//-- [arrM replaceObjectAtIndex:0 withObject: nil];

@end

NS_ASSUME_NONNULL_END
