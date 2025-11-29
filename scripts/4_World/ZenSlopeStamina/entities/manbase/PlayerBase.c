modded class PlayerBase 
{
#ifdef SERVER
	static bool ZEN_SLOPE_ENABLED = true;

	protected bool m_ZenIsSlopeDepletionActive;
	
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);

		CheckZenSlopeStaminaDeletionModifier();
	}
	
	static float ZenSlopeGetHeightDifferenceAhead(PlayerBase player, float distance = 1.0) 
	{
        vector pos 			= player.GetPosition();
        vector dir 			= player.GetDirection();
        vector aheadPos 	= pos + (dir * distance);
        float currentY 		= GetGame().SurfaceY(pos[0], pos[2]);
        float aheadY 		= GetGame().SurfaceY(aheadPos[0], aheadPos[2]);
        
        return aheadY - currentY;
    }

	void CheckZenSlopeStaminaDeletionModifier()
	{
		if (!ZEN_SLOPE_ENABLED)
			return;
			
		if (m_MovementState.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_IDLE)
		{
			DeactivateZenSlopeModifier();
			return;
		}

		float slopeMultiplier = 1.0;

		// Positive = incline; Negative = downhill
		float slopeDiff = ZenSlopeGetHeightDifferenceAhead(this);

		if (slopeDiff > 0.2)
		{
			float movementModifier = 1.0;
			switch (m_MovementState.m_iMovement)
			{
				case DayZPlayerConstants.MOVEMENTIDX_RUN: 			movementModifier = 1.5; break;
				case DayZPlayerConstants.MOVEMENTIDX_SPRINT: 		movementModifier = 2.0; break;
				case DayZPlayerConstants.MOVEMENTIDX_CROUCH_RUN: 	movementModifier = 3.0; break;
			}

			if (slopeDiff < 1)
				slopeDiff = 1 + slopeDiff;

			slopeMultiplier = Math.Clamp(Math.AbsFloat(slopeDiff), 1.0, 5.0) * movementModifier;
			GetStaminaHandler().m_RegisteredDepletionModifiers.Set(ZenSlopeStaminaMultiplierTypes.SLOPE, slopeMultiplier);

			if (!m_ZenIsSlopeDepletionActive)
			{
				GetStaminaHandler().ActivateDepletionModifier(ZenSlopeStaminaMultiplierTypes.SLOPE);

				if (slopeDiff > 1)
				{
					GetStaminaHandler().ActivateRecoveryModifier(ZenSlopeStaminaMultiplierTypes.SLOPE);
				}
				
				m_ZenIsSlopeDepletionActive = true;
			}
		}
		else 
		{
			DeactivateZenSlopeModifier();
		}
	}

	void DeactivateZenSlopeModifier()
	{
		if (!m_ZenIsSlopeDepletionActive)
			return;

		GetStaminaHandler().DeactivateDepletionModifier(ZenSlopeStaminaMultiplierTypes.SLOPE);
		GetStaminaHandler().DeactivateRecoveryModifier(ZenSlopeStaminaMultiplierTypes.SLOPE);
		m_ZenIsSlopeDepletionActive = false;
	}
#endif
}