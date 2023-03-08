modded class PlayerBase
{
	array<string> ListAllMyItems(PlayerBase player)
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
		array<string> FodsArray = new array<string>;
		ItemBase item;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		int count = itemsArray.Count();
		string MagCount = "";
		int MagCounter = 0;
		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			Class.CastTo(item, itemsArray.Get(i));
			
			if (item  &&  !item.IsInherited(SurvivorBase))	
			{
			FodsArray.Insert(item.ToString());
				if(IsItATrophy(item.ToString()) == true)
				{
					// call routine to update steamid file increase trophycount then detroy item
				}
				else
				{

				}
			}
		}
	return FodsArray;	

	}



	bool IsItATrophy(string str)
	{
	bool result = false;
	if(str.Contains("Trophy") )
	{
	result = true;
	}
	return result;
	}


}