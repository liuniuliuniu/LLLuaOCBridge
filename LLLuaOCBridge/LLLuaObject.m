//
//  LLLuaObject.m
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/12.
//

#import "LLLuaObject.h"

@implementation LLLuaObject

- (void)updateObject:(id)object withIndex:(int)index {
    NSLog(@">>>>updateObject%@ >>>>%d  >>>>%@", object, index, [object class]);    
    [self.arguments replaceObjectAtIndex:index withObject:object];
//    switch (index) {
//        case 0:
//            self.arguments[index] = object;
//            break;
//        case 1:
//        default:
//            break;
//    }
}

- (void)setArguments:(NSMutableArray *)arguments {
    NSLog(@">>>>>>setArguments:%@", arguments);
    _arguments = arguments;
}

@end

