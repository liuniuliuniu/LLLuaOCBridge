function LLPerson.prototype:destroy ()
    print("LLPerson destroy");
end

local person = LLPerson();
person.name = "vimfung";

-- 不支持对象的传递
local dog = LLDog();
dog.name = "dog";
dog:speak();

person.dog = dog;
person:walk();
person:speak();
