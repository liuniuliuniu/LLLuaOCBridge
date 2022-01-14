//
//  LLEncodingModuleViewController.m
//  LuaScripCoreDemo
//
//  Created by 韶桦 on 2022/1/5.
//

#import "LLEncodingModuleViewController.h"

@interface LLEncodingModuleViewController ()

@end

@implementation LLEncodingModuleViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    
    NSMutableArray *arrM = [NSMutableArray array];
    self.context = [[LSCContext alloc] init];
    [self.context onException:^(NSString *message) {
        NSLog(@"lsc exception = %@", message);
    }];
    
    NSTimeInterval start = [[NSDate new] timeIntervalSince1970];
    
    
    [self.context evalScriptFromFile:@"Encoding-Sample.lua"];
    
    
    NSTimeInterval end = [[NSDate new] timeIntervalSince1970];
    NSLog(@">>>>>%lf", end * 1000 - start * 1000);
    
    LLItem *itemOne = [LLItem new];
    itemOne.name = @"Encoding_Sample_urlEncode()";
    itemOne.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_urlEncode()"];
    };
    
    
    LLItem *itemTwo = [LLItem new];
    itemTwo.name = @"Encoding_Sample_urlDecode()";
    itemTwo.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_urlDecode()"];
    };
    
    
    LLItem *itemThree = [LLItem new];
    itemThree.name = @"Encoding_Sample_base64Encode()";
    itemThree.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_base64Encode()"];
    };
    
    
    LLItem *itemFour = [LLItem new];
    itemFour.name = @"Encoding_Sample_jsonEndode()";
    itemFour.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_jsonEndode()"];
    };
    
    LLItem *itemFive = [LLItem new];
    itemFive.name = @"Encoding_Sample_jsonDecode()";
    itemFive.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_jsonDecode()"];
    };
    
    LLItem *itemSix = [LLItem new];
    itemSix.name = @"Encoding_Sample_hexEncode()";
    itemSix.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_hexEncode()"];
    };
    
    LLItem *itemSeven = [LLItem new];
    itemSeven.name = @"Encoding_Sample_hexDecode()";
    itemSeven.block = ^{
        [self.context evalScriptFromString:@"Encoding_Sample_hexDecode()"];
    };
    
    [arrM addObject:itemOne];
    [arrM addObject:itemTwo];
    [arrM addObject:itemThree];
    [arrM addObject:itemFour];
    [arrM addObject:itemFive];
    [arrM addObject:itemSix];
    [arrM addObject:itemSeven];
    self.arrData = arrM.copy;
}

@end
