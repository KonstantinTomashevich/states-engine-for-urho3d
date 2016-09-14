--- Helper function for defining classes.
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

--- Create table for StatesEngine lua utils.
_G.StatesEngineUtils = {}

--- Add getter for StatesEngine.
function GetStatesEngine ()
    return StatesEngine.StatesEngineSubsystem:GetInstance ()
end

--- Create table for lua state objects instances.
_G.StatesEngineUtils.LuaStateObjects = {}

_G.StatesEngineUtils.LuaStateObjectInstance = Class ()
function _G.StatesEngineUtils.LuaStateObjectInstance:Construct ()
    self.ready_ = false
    self.isWillBeUpdated_ = true
    self.isWillBeDeleted_ = false
    self.parent_ = nil
end

--- ! Will be overrided in inheritors !
--- ! Used by C++ !
function _G.StatesEngineUtils.LuaStateObjectInstance:Init ()
    Log:Write (LOG_WARNING "Called empty LuaStateObjectInstance:Init ()!")
    self.ready_ = true
    self.lastInitReturn_ = true
    return true
end

--- ! Will be overrided in inheritors !
--- ! Used by C++ !
function _G.StatesEngineUtils.LuaStateObjectInstance:Update (timeStep)
    Log:Write (LOG_WARNING, "Called empty LuaStateObjectInstance:Update (timeStep)!")
    self.lastUpdateReturn_ = true
    return true
end

--- ! Will be overrided in inheritors !
--- ! Used by C++ !
function _G.StatesEngineUtils.LuaStateObjectInstance:Dispose ()
    Log:Write (LOG_WARNING, "Called empty LuaStateObjectInstance:Dispose ()!")
    self.ready_ = true
    self.lastDisposeReturn_ = true
    return true
end