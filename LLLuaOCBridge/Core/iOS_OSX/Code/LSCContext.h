//
//  LUAContext.h
//  LuaSample
//
//  Created by vimfung on 16/7/13.
//  Copyright © 2016年 vimfung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LSCTypeDefinied.h"

@class LSCFunction;
@class LSCScriptController;
@class LSCConfig;

/**
 *  Lua上下文对象
 */
@interface LSCContext : NSObject

/**
 配置信息
 */
@property (nonatomic, strong, readonly) LSCConfig *config;


/**
 初始化

 @return 上下文对象
 */
- (instancetype)init;

/**
 初始化

 @param config 配置信息
 @return 上下文对象
 */
- (instancetype)initWithConfig:(LSCConfig *)config;

/**
 抛出异常
 
 @param message 消息
 */
- (void)raiseExceptionWithMessage:(NSString *)message;

/**
 *  发生异常时触发
 *
 *  @param handler 事件处理器
 */
- (void)onException:(LSCExceptionHandler)handler;

/**
 *  添加搜索路径，如果执行的lua脚本不是放在默认目录（应用目录）内时，需要添加指定路径，否则会提示无法找到脚本从而运行出错
 *  在lua脚本中当使用require来引用其他lua脚本时，默认情况下，lua解析器只会查找一些内置的搜索路径（如lua解析器所在目录，系统库目录等）。如果引用的脚本不在这些内置目录中则会提示无法找到对应的脚本文件。这时候就需要使用此方法来添加一个搜索路径，让解析器可以在指定的路径下查找lua脚本文件。
 *  @param path 路径
 */
- (void)addSearchPath:(NSString *)path;

/**
 设置全局变量
 为lua层的某个全局变量赋值，如果指定变量名称不存在则创建变量，如果存在则覆盖变量原有值。其中变量的值需要先封装到LSCValue中再传给方法
 @param value 变量值
 @param name 名称
 */
- (void)setGlobalWithValue:(LSCValue *)value forName:(NSString *)name;

/**
 获取全局变量
 通过变量名称来获取lua层中全局变量的值。返回值会封装在LSCValue对象中返回给原生层。
 @param name 变量名称
 @return 变量值
 */
- (LSCValue *)getGlobalForName:(NSString *)name;

/**
 保留Lua层的变量引用，使其不被GC所回收。
 注：判断value能否被保留取决于value所保存的真实对象，所以只要保证保存对象一致，即使value为不同对象并不影响实际效果。
 即：LSCValue *val1 = [LSCValue objectValue:obj1]与LSCValue *val2 = [LSCValue objectValue:obj1]传入方法中效果相同。
 
 
 @param value 对应Lua层变量的原生对象Value，如果value为非Lua回传对象则调用此方法无任何效果。
 */
- (void)retainValue:(LSCValue *)value;

/**
 释放Lua层的变量引用，使其内存管理权交回Lua。
 注：判断value能否被释放取决于value所保存的真实对象，所以只要保证保存对象一致，即使value为不同对象并不影响实际效果。
 即：LSCValue *val1 = [LSCValue objectValue:obj1]与LSCValue *val2 = [LSCValue objectValue:obj1]传入方法中效果相同。

 @param value 对应Lua层变量的原生对象Value，如果value为非Lua回传对象则调用此方法无任何效果。
 */
- (void)releaseValue:(LSCValue *)value;

/**
 *  解析脚本
 *
 *  @param string 脚本字符串
 * 将lua脚本内容以字符串形式传给LSCContext来解析。这种方式使用灵活，可以在程序执行时动态生成脚本让上下文对象进行解析。脚本内容可以带有返回值（只要在内容最后写入return关键字即可返回想要的结果），在方法执行完后，返回值会封装在LSCValue对象中
 *  @return 返回值
 */
- (LSCValue *)evalScriptFromString:(NSString *)string;

/**
 解析脚本

 @param string 脚本字符串
 @param scriptController 脚本控制器
 @return 返回值
 */
- (LSCValue *)evalScriptFromString:(NSString *)string
                  scriptController:(LSCScriptController *)scriptController;

/**
 *  解析脚本
 *
 *  @param path 脚本路径
 * 通过传入lua脚本文件所在路径来解析脚本。传入路径分两种情况：如果脚本包含在应用包内，则可以通过传入相对路径来指定脚本路径。除了前面说到的情况外都必须传入绝对路径来指定脚本的位置。
 *  @return 返回值
 */
- (LSCValue *)evalScriptFromFile:(NSString *)path;


/**
 解析脚本

 @param path 脚本路径
 @param scriptController 脚本控制器
 @return 返回值
 */
- (LSCValue *)evalScriptFromFile:(NSString *)path
                scriptController:(LSCScriptController *)scriptController;

/**
 *  调用方法
 *
 *  @param methodName 方法名称
 *  @param arguments  参数
 * 使用该方法可以在原生层让一个lua层的方法进行调用执行并返回结果，传入方法名称和参数即可。其中方法的每个参数要求封装到一个LSCValue对象中，并且添到一个NSArray类型中传入给方法，数组的元素位置表示参数的顺序（下标0的元素表示方法第一个参数，下标1表示第二个参数，如此类推）。
 
 对于registerMethodWithName:block:注册到lua的方法，同样可以使用该方法进行调用。
 *  @return 返回值
 */
- (LSCValue *)callMethodWithName:(NSString *)methodName
                       arguments:(NSArray<LSCValue *> *)arguments;


/**
 调用方法

 @param methodName 方法名称
 @param arguments 参数
 @param scriptController 脚本控制器
 @return 返回值
 */
- (LSCValue *)callMethodWithName:(NSString *)methodName
                       arguments:(NSArray<LSCValue *> *)arguments
                scriptController:(LSCScriptController *)scriptController;

/**
 *  注册方法
 *     将一段原生层的处理逻辑注册为一个lua方法提供lua层调用。对于一些功能lua无法直接处理的（如调用手机的摄像头拍照），可以使用该方法让原生层来负责处理，并在lua层生成一个方法入口，让lua层在任何地方都可以调用。
 *  @param methodName 方法名称
 *  @param block      处理过程
 */
- (void)registerMethodWithName:(NSString *)methodName block:(LSCFunctionHandler)block;


/**
 将指定方法放入线程中执行

 @param function 方法对象
 @param arguments 参数
 */
- (void)runThreadWithFunction:(LSCFunction *)function
                    arguments:(NSArray<LSCValue *> *)arguments;


/**
 将指定方法放入线程中执行

 @param function 方法对象
 @param arguments 参数
 @param scriptController 脚本控制器
 */
- (void)runThreadWithFunction:(LSCFunction *)function
                    arguments:(NSArray<LSCValue *> *)arguments
             scriptController:(LSCScriptController *)scriptController;

@end
