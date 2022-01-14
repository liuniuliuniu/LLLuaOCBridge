//
//  LLThreadModuleVC.m
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/7.
//

#import "LLThreadModuleVC.h"

@interface LLThreadModuleVC ()

@end

@implementation LLThreadModuleVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.context = [[LSCContext alloc] init];
    [self.context onException:^(NSString *message) {
        NSLog(@"lsc exception = %@", message);
        
    }];
    
    NSTimeInterval start = [[NSDate new] timeIntervalSince1970];
    
    [self.context evalScriptFromFile:@"Thread-Sample.lua"];
    
    NSTimeInterval end = [[NSDate new] timeIntervalSince1970];
    NSLog(@">>>>>%lf", end * 1000 - start * 1000);
    
    NSMutableArray *arrM = [NSMutableArray array];
    LLItem *itemOne = [LLItem new];
    itemOne.name = @"Thread_Sample_run()";
    itemOne.block = ^{
        [self.context evalScriptFromString:@"Thread_Sample_run()"];
    };
    [arrM addObject:itemOne];
    
    LLItem *itemTwo = [LLItem new];
    itemTwo.name = @"Thread_Sample_stop()";
    itemTwo.block = ^{
        [self.context evalScriptFromString:@"Thread_Sample_stop()"];
    };
    [arrM addObject:itemTwo];
    
    self.arrData = arrM.copy;
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
