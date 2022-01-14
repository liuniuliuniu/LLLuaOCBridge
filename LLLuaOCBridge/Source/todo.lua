url = "https://vimfung.github.io/LuaScriptCore/";

local json = require("dkjson");

local tbl = getDeviceInfo();

local str = json.encode (tbl, { indent = true })

print(url);

print(str);


function add (a, b)

    return a+b;

end

function makeList()
	-- body 数组
	local list = {}
	for i=1,600 do
     -- 字典
		local obj = {}
		obj.name = "test"
		table.insert(list, obj)
	end
	print("---------- ok")

    return list;
end


function operationObject (object)
    local dog = object:getDog();
    print(dog)
    print(dog:getName())
    return object:getName();
end
