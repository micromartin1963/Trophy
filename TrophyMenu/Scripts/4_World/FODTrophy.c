#define FODTrophy

class FODTrophy
{
	protected static ref FODTrophy Instance;
		
	void FODTrophy()
	{
	}
	
	static FODTrophy GetInstance()
	{
		if (!Instance)
        {
            Instance = new FODTrophy();
        }
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
	


}	