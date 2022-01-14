Object:typeMapping("ios", "LogModule", "LogModule");
Object:typeMapping("ios", "NSURL", "NSURL");
Object:typeMapping("ios", "LLDog", "LLDog");

function luaIntercept(mediatorInfo, target, selString, arguments)
    print("mediatorInfoGloal值是:", mediatorInfo);
    local message = mediatorInfo.message;
    if (message ~= "拦截") then
        return
    end
    mediatorInfo.message = "我是修改后的值";
    
    print("target值是:", target);
    
    print("selstring值是", selString);
    print("arguments 值", arguments);
            
     if (selString == "canOpenURL:") then
        local url = arguments[1];
        local urlString = url.absoluteString;
        LogModule:writeLog(urlString);
        -- :URLWithString("newAlipay");
        local newUrl = NSURL:URL("newAlipay");
        arguments[1] = newUrl;
        print("arguments 值", arguments[1]);
    else
        print("不相等")
    end
end


function luaInterceptArrTest(arr)
    print(arr[1]);
    arr[1] = "123";
    print(arr[1]);
end


function luaInterceptOne(luaObject)
    print("mediatorInfoGloal值是:", luaObject.mediator);
    local message = luaObject.mediator.message;
    if (message ~= "拦截") then
        return
    end
    luaObject.mediator.message = "我是修改后的值";
    local url =  NSURL:URL("newAlipay");
    -- luaObject:updateObject(url, 0);
    -- luaObject:updateObject("我是null", 1);
    -- luaObject:updateObject(3, 2);
    -- luaObject:updateObject('runrunrunrun', 3);
    
    luaObject.arguments = {url, 我是null, 3, "runrunrun"};
    
end
