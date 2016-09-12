function Class (...)
    local newClass = {}
    local bases = {...}
    
    for index, base in ipairs (bases) do
        for key, value in pairs (base) do
            newClass [key] = value
        end
    end
    
    if newClass.HasCXXBase == nil then
        newClass.HasCXXBase = function () return false end
    end
    
    newClass.__index = newClass
    newClass.IsA = { [newClass] = true }
    for index, base in ipairs (bases) do
        if base.IsA ~= nil then
            for baseOfBase in pairs (base.IsA) do
                newClass.IsA [baseOfBase] = true
            end
        end
        newClass.IsA [ base ] = true
    end
    
    setmetatable (newClass,
        {__call = 
            function (classType, ...)
                local instance = setmetatable ( {}, classType)
                local init = instance.Construct
                if init then 
                    init (instance, ...) 
                end
                return instance
            end}
        )
    
    return newClass
end