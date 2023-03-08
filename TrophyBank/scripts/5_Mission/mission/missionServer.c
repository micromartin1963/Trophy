modded class MissionServer
{
	static const string Fods_FilePath = "$profile:TrophyBank/";
	ref array<string> TrophyArray;
	float m_Trader_StatUpdateTimeMax = 1;
	float m_Trader_StatUpdateTime = m_Trader_StatUpdateTimeMax;
	bool HaveWeSteppedIntoArea = false;	

	override void OnInit()
	{		
		super.OnInit();
		//PlayerBase player;
		//PlayerIdentity id;	
		//id = player.GetIdentity()
		//ReadTrophyFile(id);
	}


	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player,identity);
		string id = identity.GetPlainId();
		string name = player.GetIdentity().GetName();
		string FilenameStr = Fods_FilePath + id + ".txt";
		if (!FileExist(FilenameStr))
		{
		createPlayerTrophyFile(FilenameStr,id);
		}
	}


	void StoreAllItems(PlayerBase player,array<string> ItemsArray)
	{
		string name = player.GetIdentity().GetName();
		string FilenameStr = Fods_FilePath + name + ".txt";
		FileHandle logFile = OpenFile(FilenameStr, FileMode.APPEND);
		if (logFile != 0)
		{
			for (int y = 0; y < ItemsArray.Count(); y++)
			{
			FPrintln(logFile,ItemsArray[y]);
			}

			CloseFile(logFile);
		} else 
		{

		}
	}	


	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);


	}

	void ReadTrophyFile(PlayerIdentity id)    // use this stuff later
	{
	
		string fullfilename = Fods_FilePath + id + ".txt";

		FileHandle file_index = OpenFile(fullfilename, FileMode.READ);
		
		if ( file_index == 0 )
		{
			return;
		}	
			string line_content = "";
			int char_count = FGets( file_index,  line_content );
			Print("xxxxxxxxxxxxxxxxxxxxxxxxx  doing it reading xxxxxxxxxxxxxxxxxxxxxx " + line_content);

		CloseFile(file_index);
	}


	void createPlayerTrophyFile(string name , string id)
	{
	FileHandle file;
	string Filename = name;
        file = OpenFile(Filename, FileMode.WRITE);

 	    if (file)
            {
            string ex_script =  "trophycount:0" ;
            FPrintln(file, ex_script);
			Print("xxxxxxxxxxxxxxxxxxxxxxxxx  Creating new file for trophy xxxxxxxxxxxxxxxxxxxxxx ");
            CloseFile(file);
            }
	}


}  // end