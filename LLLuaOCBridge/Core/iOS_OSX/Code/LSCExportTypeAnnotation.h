//
//  LSCExportTypeAnnotation.h
//  LuaScriptCore
//
//  Created by 冯鸿杰 on 2017/11/24.
//  Copyright © 2017年 vimfung. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 该类型主要对导出到lua中的类型进行注解，告诉框架原生类型那些属性、方法是不被导出到lua中的。用于控制lua对原生类型的访问权限。


 导出类型注解
 */
@protocol LSCExportTypeAnnotation <NSObject>

@optional

/**
 被排除的类方法，被排除的方法无法导出到Lua中
 
 @return 方法列表
 */
+ (NSArray<NSString *> *)excludeExportClassMethods;

/**
 被排除的属性，被排除的方法无法导出到Lua中

 @return 属性列表
 */
+ (NSArray<NSString *> *)excludeProperties;

/**
 被排除的实例方法，被排除的方法无法导出到Lua中
 
 @return 方法列表
 */
+ (NSArray<NSString *> *)excludeExportInstanceMethods;

@end
