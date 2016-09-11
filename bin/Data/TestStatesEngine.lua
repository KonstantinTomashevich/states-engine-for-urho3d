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
    
    local testObject1 = StatesEngine.LuaStateObject:new (context)
    local testObject2 = StatesEngine.LuaStateObject:new (context)
    
    testObject1:CreateObject ("_G.TestObject", "123")
    testObject2:CreateObject ("_G.TestObject", "456")
    
    testObject2:SetParent (testObject1)
    Log:Write (LOG_INFO, tostring (_G.StatesEngineUtils.GetLuaTable (testObject2:GetParent ()).containedValue_))
    
    testObject1:delete ()
    testObject2:delete ()
    return 0
end