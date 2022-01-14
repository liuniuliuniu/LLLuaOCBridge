//
//  LSCExportMethodDescriptor.h
//  LuaScriptCore
//
//  Created by 冯鸿杰 on 2017/9/8.
//  Copyright © 2017年 vimfung. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 导出方法描述，用于描述导出类型的导出方法相关信息并决定方法的调用方式。该类型不需要开发者进行初始化，一旦原生类型实现LSCExportType则会将类型导出，并生成对应的导出方法的描述对象。
 导出方法描述
 */
@interface LSCExportMethodDescriptor : NSObject

/**
 选择子
 */
@property (nonatomic, readonly) SEL selector;

/**
 参数签名，如：@@、@I@B
 */
@property (nonatomic, copy, readonly) NSString *paramsSignature;


/**
 方法签名
 */
@property (nonatomic, strong, readonly) NSMethodSignature *methodSignature;


/**
 初始化

 @param selector 选择子
 @param methodSignature 方法签名
 @param paramsSignature 参数签名
 @return 方法描述
 */
- (instancetype)initWithSelector:(SEL)selector
                 methodSignature:(NSMethodSignature *)methodSignature
                 paramsSignature:(NSString *)paramsSignature;


/**
 创建方法调用器
 */
- (NSInvocation *)createInvocation;

@end
