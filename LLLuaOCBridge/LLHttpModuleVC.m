//
//  LLHttpModuleVC.m
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/5.
//

#import "LLHttpModuleVC.h"

@interface LLHttpModuleVC ()

@end

@implementation LLHttpModuleVC

- (void)viewDidLoad {
    [super viewDidLoad];

    NSMutableArray *arrM = [NSMutableArray array];
    self.context = [[LSCContext alloc] init];
    [self.context onException:^(NSString *message) {
        NSLog(@"lsc exception = %@", message);
    }];
    
    NSTimeInterval start = [[NSDate new] timeIntervalSince1970];
    
    
    [self.context evalScriptFromFile:@"HTTP-Sample.lua"];
    
    NSTimeInterval end = [[NSDate new] timeIntervalSince1970];
    NSLog(@">>>>>%lf", end * 1000 - start * 1000);
    
    LLItem *itemOne = [LLItem new];
    itemOne.name = @"HTTP_Sample_get()";
    itemOne.block = ^{
        NSLog(@"请求之前OC");
        [self.context evalScriptFromString:@"HTTP_Sample_get()"];
        NSLog(@"请求之后OC");
    };
    
    LLItem *itemTwo = [LLItem new];
    itemTwo.name = @"HTTP_Sample_post()";
    itemTwo.block = ^{
        [self.context evalScriptFromString:@"HTTP_Sample_post()"];
    };
    
    
    LLItem *itemThree = [LLItem new];
    itemThree.name = @"HTTP_Sample_upload()";
    itemThree.block = ^{
        [self.context evalScriptFromString:@"HTTP_Sample_upload()"];
    };
    
    
    LLItem *itemFour = [LLItem new];
    itemFour.name = @"HTTP_Sample_download()";
    itemFour.block = ^{
        [self.context evalScriptFromString:@"HTTP_Sample_download()"];
    };
    
    [arrM addObject:itemOne];
    [arrM addObject:itemTwo];
    [arrM addObject:itemThree];
    [arrM addObject:itemFour];
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
