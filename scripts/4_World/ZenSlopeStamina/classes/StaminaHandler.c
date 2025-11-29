modded class StaminaHandler
{
    override void Init()
	{
        super.Init();

		#ifdef SERVER
		//----------------- depletion --------------------
		m_RegisteredDepletionModifiers.Insert(ZenSlopeStaminaMultiplierTypes.SLOPE, GetZenSlopeStaminaConfig().SlopeDepletionModifier);
		
		//----------------- recovery --------------------
		m_RegisteredRecoveryModifiers.Insert(ZenSlopeStaminaMultiplierTypes.SLOPE, GetZenSlopeStaminaConfig().SlopeRecoveryModifier);
		#endif
	}
}