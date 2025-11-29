/*
	(c) 2025 | ZenSlopeStamina | Zenarchist
*/

class CfgPatches
{
	class ZenSlopeStamina
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class ZenSlopeStamina
	{
		author = "Zenarchist";
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenSlopeStamina/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenSlopeStamina/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = 
				{ 
					"ZenSlopeStamina/scripts/5_Mission"
				};
			};
		};
	};
};