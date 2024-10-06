--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type WBP_GlobeProgressBar_C
local M = UnLua.Class()

--function M:Initialize(Initializer)
--end
function M:InitGlobeProgressBar()
    -- UE.UKismetSystemLibrary.PrintString(nil,"Construct base globe ",true,false,UE.FLinearColor(1, 1, 1, 1),2)
    self.width = 100
    self.height = 100
    -- 调整尺寸
    self.SizeBox_root:SetWidthOverride(self.width)
    self.SizeBox_root:SetHeightOverride(self.height)
    -- 设置边框图像
    self.BorderImage:SetBrush(self.BorderBrush)
    -- -- 设置进度条图像
    self.ProgressBar.WidgetStyle.BackgroundImage = self.ProgressBarBackgroundImg
    self.ProgressBar.WidgetStyle.FillImage = self.ProgressBarFillImg
    self.GhostProgressBar.WidgetStyle.FillImage = self.GhostProgressBarFillImg
    -- -- 设置玻璃样式图像
    self.GlassImage:SetBrush(self.GlassBrush)
end

function M:PreConstruct(IsDesignTime)
   self:InitGlobeProgressBar()
end

function M:update_ghost_globe()
    self.GhostProgressBar:SetPercent(self.ghost_percent);
end
-- function M:Construct()
-- end

function M:Tick(MyGeometry, InDeltaTime)
    self.ghost_percent = UE.UKismetMathLibrary.FInterpTo(self.ghost_percent,self.target_ghost_percent,InDeltaTime,1);

    self:update_ghost_globe();
end

return M
