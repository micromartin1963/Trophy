class CfgPatches
{
	class TrophyBank
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Characters"};
	};
};
class CfgMods
{
	class TrophyBank
	{
		author = "FodnBrew";
		type = "mod";
		dependencies[] = {"Game","World"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"TrophyBank/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"TrophyBank/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"TrophyBank/scripts/5_Mission"};
			};

		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class AlarmClock_ColorBase;

	class Trophy: AlarmClock_ColorBase
	{
		scope=2;
		displayName="Trophy";
		descriptionShort="Trophy";
		itemSize[]={1,1};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\tools\data\alarmclock_co.paa"
		};
	};
};

