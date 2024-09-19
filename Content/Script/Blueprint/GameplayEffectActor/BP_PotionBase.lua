--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type BP_PotionBase_C
local M = UnLua.Class()

function M:BndEvt__BP_GEActor_Sphere_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult)
    if(self.GameplayEffectClass == nil) then
        UE.UKismetSystemLibrary.PrintString(nil,"GameplayEffect is nil",true,true,UE.FLinearColor(1, 1, 1, 1),2)
    else
        self:ApplyGameplayEffectToActor(OtherActor,self.GameplayEffectClass)
        self:K2_DestroyActor()
    end
end

-- function M:Initialize(Initializer)
-- end

-- function M:UserConstructionScript()
-- end

-- function M:ReceiveBeginPlay()
-- end

-- function M:ReceiveEndPlay()
-- end

-- function M:ReceiveTick(DeltaSeconds)
-- end

-- function M:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
-- end

-- function M:ReceiveActorBeginOverlap(OtherActor)
-- end

-- function M:ReceiveActorEndOverlap(OtherActor)
-- end

return M
