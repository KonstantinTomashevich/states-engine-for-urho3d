require "Class"

--- Add table which contains lua instances ---
_G.StatesEngineUtils = {}
_G.StatesEngineUtils.LuaStateObjects = {}

--- ! Used by C++ ! ---
--- Check is lua instance exists, for LuaStateObject internal use ---
function _G.StatesEngineUtils:IsLuaStateObjectExists (name)
    if type (_G.StatesEngineUtils.LuaStateObjects [name]) ~= "nil" then
        return 1
    else
        return 0
    end
end

--- ! Used by C++ ! ---
--- Delete lua instance if it in lua instances table
function _G.StatesEngineUtils:ReleaseLuaStateObject (name)
    if _G.StatesEngineUtils.IsLuaStateObjectExists (name) == 1 then
        _G.StatesEngineUtils.LuaStateObjects [name] = nil
        return true;
    end
    return false;
end

--- Get lua state object instance data table ---
function _G.StatesEngineUtils.GetLuaTable (luaStateObjectInstance)
    return _G.StatesEngineUtils.LuaStateObjects [luaStateObjectInstance:GetObjectName ()]
end

_G.StatesEngineUtils.LuaStateObjectInstance = Class ()
function _G.StatesEngineUtils.LuaStateObjectInstance:Construct ()
    self ["ready_"] = false
    self ["isWillBeUpdated_"] = true
    self ["isWillBeDeleted_"] = false
    self ["parent_"] = nil
end

--- ! Will be overrided in inheritors ! ---
--- ! Used by C++ ! ---
function _G.StatesEngineUtils.LuaStateObjectInstance:Init ()
    Log:Write (LOG_WARNING "Called empty LuaStateObjectInstance:Init ()!")
    self ["ready_"] = true
    return true
end

--- ! Will be overrided in inheritors ! ---
--- ! Used by C++ ! ---
function _G.StatesEngineUtils.LuaStateObjectInstance:Update (timeStep)
    Log:Write (LOG_WARNING, "Called empty LuaStateObjectInstance:Update (timeStep)!")
    return true
end

--- ! Will be overrided in inheritors ! ---
--- ! Used by C++ ! ---
function _G.StatesEngineUtils.LuaStateObjectInstance:Dispose ()
    Log:Write (LOG_WARNING, "Called empty LuaStateObjectInstance:Dispose ()!")
    self ["ready_"] = false
    return true
end
