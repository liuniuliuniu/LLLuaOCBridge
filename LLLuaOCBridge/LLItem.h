//
//  LLItem.h
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LLItem : NSObject

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) dispatch_block_t  block;

@end

NS_ASSUME_NONNULL_END
