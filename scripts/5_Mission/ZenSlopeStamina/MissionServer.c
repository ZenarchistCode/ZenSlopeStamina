modded class MissionServer 
{
#ifdef SERVER
    override void OnInit()
	{
		super.OnInit();

        #ifdef ZenModPack
        PlayerBase.ZEN_SLOPE_ENABLED = ZenModEnabled("ZenStaminaSlope");
        #endif
    }
#endif
}