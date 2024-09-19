--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--
-- local GlobeProgressBar = require "Blueprint.UI.Globe_ProgressBar.WBP_GlobeProgressBar"

---@type WBP_HealthGlobe_C
local M = UnLua.Class("Blueprint.UI.Globe_ProgressBar.WBP_GlobeProgressBar")


function M:update_health_globe()
    self.ProgressBar:SetPercent(self.health/self.max_health)
end

function M:OnGlobeHealthChanged(new_health)
    self.health = new_health
    self:update_health_globe()
end

function M:OnGlobeMaxHealthChanged(new_max_health)
    UE.UKismetSystemLibrary.PrintString(nil,"new max health is "..new_max_health,true,true,UE.FLinearColor(1, 1, 1, 1),2)
    self.max_health = new_max_health
    self:update_health_globe()
end

function M:OnWidgetControllerSet()
    self.WidgetController.OnHealthChanged:Add(self,self.OnGlobeHealthChanged)
    self.WidgetController.OnMaxHealthChanged:Add(self,self.OnGlobeMaxHealthChanged)
end

--function M:Initialize(Initializer)
--end

function M:PreConstruct(IsDesignTime)
    self.Super.PreConstruct(self,IsDesignTime)
end

-- function M:Construct()
-- end

--function M:Tick(MyGeometry, InDeltaTime)
--end

return M
