modded class MissionServer 
{
#ifdef SERVER
    override void OnInit()
	{
		super.OnInit();

        GetZenSlopeStaminaConfig();

        #ifdef ZenModPack
        PlayerBase.ZEN_SLOPE_ENABLED = ZenModEnabled("ZenStaminaSlope");
        #endif
    }
#endif
}