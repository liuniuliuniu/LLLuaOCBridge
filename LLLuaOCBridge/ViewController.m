//
//  ViewController.m
//  LLLuaOCBridge
//
//  Created by 韶桦 on 2022/1/13.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.context = [[LSCContext alloc] init];
    [self.context onException:^(NSString *message) {
        NSLog(@"lsc exception = %@", message);
        
    }];
    
    [self.context evalScriptFromFile:@"main.lua"];
    NSMutableArray *arrM = [NSMutableArray array];
    LLItem *itemOne = [LLItem new];
    itemOne.name = @"数组的操作";
                
    
    itemOne.block = ^{
        [self objectArr];
    };
    [arrM addObject:itemOne];
    
    self.arrData = arrM.copy;
}

- (void)objectArr {
    NSArray *arr = @[@"1243"];
    NSLog(@">>>>>> %p", arr);
    [self.context callMethodWithName:@"funcArr" arguments:@[[LSCValue objectValue:arr]]];
}




@end
