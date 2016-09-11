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
    
    -- TODO: GetStatesEngine ():GetState ():Create () isn't work now, will be fixed later.
    
    local testObject1 = StatesEngine.LuaStateObject:new (context)
    testObject1:CreateObject ("_G.TestObject", "\"Hello, world!\"")
    GetStatesEngine ():GetState ():Add (testObject1)
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].ready_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't ready after GetStatesEngine ():GetState ():Add ()!")
        return 2
    end
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].isInitPassed_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't passed init after GetStatesEngine ():GetState ():Add ()!")
        return 3
    end
    
    local updateEventData = VariantMap ()
    updateEventData.TimeStep = 1 / 60
    GetStatesEngine ():Update (StringHash ("Update"), updateEventData)
    
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].isUpdatePassed_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't passed update after GetStatesEngine ():Update (StringHash (\"Update\"), updateEventData)!")
        return 4
    end
    
    if string.format ("%.5f", _G.StatesEngineUtils.LuaStateObjects 
            [testObject1:GetObjectName ()].lastUpdateTimestep_) ~= 
            string.format ("%.5f", 1 / 60) then
            
        Log:Write (LOG_INFO, "FAILED: Object's last update timestep isn't match expected!")
        return 5
    end
    
    GetStatesEngine ():GetState ():DisposeAll ("LuaStateObject")
    if _G.StatesEngineUtils.LuaStateObjects [testObject1:GetObjectName ()].isDisposePassed_ ~= true then
        Log:Write (LOG_INFO, "FAILED: Object isn't passed dispose after GetStatesEngine ():GetState ():DisposeAll (\"LuaStateObject\")!")
        return 6
    end
    
    GetStatesEngine ():GetState ():RemoveAll ("LuaStateObject", true)
    testObject1:delete ()
    return 100500
end