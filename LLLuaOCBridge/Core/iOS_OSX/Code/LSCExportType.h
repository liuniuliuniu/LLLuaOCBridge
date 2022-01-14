//
//  LSCExportModule.h
//  LuaScriptCore
//
//  Created by 冯鸿杰 on 2017/9/5.
//  Copyright © 2017年 vimfung. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 导出模块协议，实现此协议可以将模块导出到Lua层使用
 LSCExportType主要用于将原生类型导出到lua中进行使用。由于lua并没有面向对象的特性，因此LSC提供了一套相对完成的面向对象协议，只要遵循LSCExportType则可以直接在lua中调用类型，并能像原生代码一样访问其方法和属性。更加详细的面向对象类型可以参考《LuaScriptCore面向对象》
 */
@protocol LSCExportType <NSObject>

@end
