--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type WBP_ManaGlobe_C
local M = UnLua.Class("Blueprint.UI.Globe_ProgressBar.WBP_GlobeProgressBar")

--function M:Initialize(Initializer)
--end


function M:update_mana_globe()
    self.ProgressBar:SetPercent(self.mana/self.max_mana)
end

function M:PreConstruct(IsDesignTime)
    self.Super.PreConstruct(self,IsDesignTime)
end

function M:OnWidgetControllerSet()
    
    self.WidgetController.OnManaChanged:Add(self,function (new_mana)
        self.mana = new_mana
        self:update_mana_globe()
    end)
    self.WidgetController.OnMaxManaChanged:Add(self,function (new_max_mana)
        self.max_mana = new_max_mana
        self:update_mana_globe()
    end)
end

-- function M:Construct()
-- end

--function M:Tick(MyGeometry, InDeltaTime)
--end

return M
