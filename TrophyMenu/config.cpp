
#define _ARMA_

class CfgPatches
{
	class FODTrophy
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts"};
	};
};
class CfgMods
{
	class FODTrophy
	{
		dir = "TrophyMenu";
		name = "Trophy";

		type = "mod";
		dependencies[] = {"World","Mission"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"TrophyMenu/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"TrophyMenu/Scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;

	class FOD_Vending_TEST: HouseNoDestruct
	{
		scope = 1;
		displayName = "Vending Machine ";
		model = "TrophyMenu\models\revo_bottle_drinks.p3d";

	};

};
