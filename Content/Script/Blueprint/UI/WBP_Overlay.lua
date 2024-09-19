--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type WBP_Overlay_C
local M = UnLua.Class()

--function M:Initialize(Initializer)
--end

-- function M:PreConstruct(IsDesignTime)


-- end

-- function M:Construct()
-- end

--function M:Tick(MyGeometry, InDeltaTime)
--end
function M:OnWidgetControllerSet()
    -- UE.UKismetSystemLibrary.PrintString(nil,"hello setting controller",true,true,UE.FLinearColor(1, 1, 1, 1),2)
    self.WBP_HealthGlobe:SetWidgetController(self.WidgetController)
    self.WBP_ManaGlobe:SetWidgetController(self.WidgetController)
end

return M
