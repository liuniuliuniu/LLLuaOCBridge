//
//  LLBaseTableVC.h
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/5.
//

#import <UIKit/UIKit.h>
#import "LLItem.h"
#import "LuaScriptCore.h"
NS_ASSUME_NONNULL_BEGIN

@interface LLBaseTableVC : UIViewController

@property (nonatomic, copy) NSArray<LLItem *> *arrData;

@property (nonatomic, strong) LSCContext *context;

@end

NS_ASSUME_NONNULL_END
