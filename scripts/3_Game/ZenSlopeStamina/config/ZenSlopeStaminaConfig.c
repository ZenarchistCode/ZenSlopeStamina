class ZenSlopeStaminaConfig
{
	private const static string zenModFolder = "$profile:\\Zenarchist\\";
	private const static string zenConfigName = "ZenSlopeStaminaConfig.json";

    float SlopeDepletionModifier = 2.0;
	float SlopeRecoveryModifier = 0.0;

	void Load()
	{
		if (!GetGame().IsDedicatedServer())
			return;

		if (FileExist(zenModFolder + zenConfigName))
		{
			JsonFileLoader<ZenSlopeStaminaConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);
			return;
		}

		Save();
	}

	void Save()
	{
		// If config folder doesn't exist, create it.
		if (!FileExist("$profile:\\Zenarchist"))
		{
			MakeDirectory(zenModFolder);
		}

		if (!FileExist(zenModFolder))
		{
			MakeDirectory(zenModFolder);
		}

		JsonFileLoader<ZenSlopeStaminaConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}
}

ref ZenSlopeStaminaConfig m_ZenSlopeStaminaConfig;

static ZenSlopeStaminaConfig GetZenSlopeStaminaConfig()
{
	if (!m_ZenSlopeStaminaConfig)
	{
		Print("[ZenSlopeStaminaConfig] Init");
		m_ZenSlopeStaminaConfig = new ZenSlopeStaminaConfig;
		m_ZenSlopeStaminaConfig.Load();
	}

	return m_ZenSlopeStaminaConfig;
}