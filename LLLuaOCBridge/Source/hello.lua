-- Object:typeMapping("ios", "LogModule", "LogModule");

function luaFunc(mediatorInfo, target, selString, url)
    local name = mediatorInfo.name;
    if (name ~= "基础数据") then
        return
    end    
    print("target值是:", target);
    print("selstring值是", selString);
     if (selString == "customSelFunc") then
             print("方法为customSelFunc 则调用")
        target:customSelFunc();
    else
        print("不相等")
    end
                
    local path = Path:app()
    print("path = ", path);
    
    print("url = ", url);
    local urlString = url.absoluteString;
    print("urlString = ", urlString);
    
    LogModule:writeLog(urlString);
    LLDog:classFunc();
    
end

