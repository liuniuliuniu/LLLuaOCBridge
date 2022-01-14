//
//  LSCExportPropertyDescriptor.h
//  LuaScriptCore
//
//  Created by 冯鸿杰 on 2017/11/24.
//  Copyright © 2017年 vimfung. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LSCValue;
@class LSCExportTypeDescriptor;
@class LSCFunction;

/**
 导出属性描述
 导出属性描述，用于描述导出类型的导出属性相关信息。该类型不需要开发者进行初始化，一旦原生类型实现LSCExportType则会将类型导出，并生成对应的导出属性的描述对象。
 */
@interface LSCExportPropertyDescriptor : NSObject

/**
 属性名称
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 初始化属性描述，用于创建原生属性时使用

 @param name 属性名称
 @param getterSelector Getter方法
 @param setterSelector Setter方法
 
 @return 属性描述对象
 */
- (instancetype)initWithName:(NSString *)name
              getterSelector:(SEL)getterSelector
              setterSelector:(SEL)setterSelector;


/**
 初始化属性描述，用于创建Lua属性时使用

 @param name 属性名称
 @param getterFunction Getter方法
 @param setterFunction Setter方法
 @return 属性描述对象
 */
- (instancetype)initWithName:(NSString *)name
              getterFunction:(LSCFunction *)getterFunction
              setterFunction:(LSCFunction *)setterFunction;

/**
 调用Getter方法

 @param instance 实例对象
 @param typeDescriptor 类型
 
 @return 返回值
 */
- (LSCValue *)invokeGetterWithInstance:(id)instance
                        typeDescriptor:(LSCExportTypeDescriptor *)typeDescriptor;

/**
 调用Setter方法

 @param instance 实例对象
 @param typeDescriptor 类型
 @param value 值
 */
- (void)invokeSetterWithInstance:(id)instance
                  typeDescriptor:(LSCExportTypeDescriptor *)typeDescriptor
                           value:(LSCValue *)value;

@end
