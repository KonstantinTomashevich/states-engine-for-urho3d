require "Class"

_G.TestObject = Class (_G.StatesEngine_LuaStateObjectInstance)
function _G.TestObject:Construct (someValue)
    _G.StatesEngineUtils.LuaStateObjectInstance.Construct (self)
    self.isInitPassed_ = false
    self.isUpdatePassed_ = false
    self.isDisposePassed_ = false
    self.lastUpdateTimestep_ = 0.0
    self.containedValue_ = someValue
end

function _G.TestObject:Init ()
    self.ready_ = true
    self.isInitPassed_ = true
    self.lastInitReturn_ = true
    return true
end

function _G.TestObject:Update (timeStep)
    self.isUpdatePassed_ = true
    self.lastUpdateTimestep_ = timeStep
    self.lastUpdateReturn_ = true
    return true
end

function _G.TestObject:Dispose ()
    self.ready_ = false
    self.isDisposePassed_ = true
    self.lastDisposeReturn_ = true
    return true
end

function TestStatesEngine ()
    --- Is StatesEngine available? ---
    if GetStatesEngine () == nil then
        Log:Write (LOG_INFO, "FAILED: StatesEngine is nil in script!")
        return 1
    end
    
    if GetStatesEngine ():GetState () == nil then
        Log:Write (LOG_INFO, "FAILED: StatesEngine's GetState return nil in script")
        return 2
    end
      
    local testObject1 = GetStatesEngine ():GetState ():CreateLuaStateObject ("_G.TestObject", "\"Hello, world!\"")
    GetStatesEngine ():GetState ():Init ()
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].parent_ ~= GetStatesEngine ():GetState () then
        Log:Write (LOG_INFO, "FAILED: Object's parent isn't equal to GetStatesEngine ():GetState ()!")
        return 3
    end
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].ready_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't ready after GetStatesEngine ():GetState ():Add ()!")
        return 4
    end
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].isInitPassed_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't passed init after GetStatesEngine ():GetState ():Add ()!")
        return 5
    end
    
    local updateEventData = VariantMap ()
    updateEventData.TimeStep = 1 / 60
    GetStatesEngine ():Update (StringHash ("Update"), updateEventData)
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].isUpdatePassed_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't passed update after GetStatesEngine ():Update (StringHash (\"Update\"), updateEventData)!")
        return 6
    end
    
    if string.format ("%.5f", _G.StatesEngineUtils.LuaStateObjects 
            [testObject1:GetObjectName ()].lastUpdateTimestep_) ~= 
            string.format ("%.5f", 1 / 60) then
            
        Log:Write (LOG_INFO, "FAILED: Object's last update timestep isn't match expected!")
        return 7
    end
    
    GetStatesEngine ():GetState ():DisposeAll ("LuaStateObject")
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].isDisposePassed_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't passed dispose after GetStatesEngine ():GetState ():DisposeAll (\"LuaStateObject\")!")
        return 8
    end
    
    GetStatesEngine ():GetState ():RemoveAllByLuaTypeName ("_G.TestObject", true)
    if testObject1:IsObjectNotNull () ~= true then
        Log:Write (LOG_INFO, "FAILED: Object is nil now!")
        return 9
    end
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].containedValue_ ~= "Hello, world!" then
        Log:Write (LOG_INFO, "FAILED: Object's containedValue_ isn't equal setted! It is \"" .. 
            tostring (_G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].containedValue_) .. 
            "\" but will be \"Hello, world!\"!")
        return 10
    end
    
    testObject1:ReleaseObject ()
    if testObject1:IsObjectNotNull () ~= false then
        Log:Write (LOG_INFO, "FAILED: Object isn't nil after ReleaseObject ()!")
        return 11
    end
    
    testObject1:delete ()
    return 100500
end