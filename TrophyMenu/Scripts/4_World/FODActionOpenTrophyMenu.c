class FODActionOpenTrophyMenu: ActionInteractBase
{
	void FODActionOpenTrophyMenu()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_HUDCursorIcon = CursorIcons.None;
	}

	override string GetText()
	{
		return "Open Trophy menu";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}
	
	override void OnExecuteClient(ActionData action_data)
	{
		super.OnExecuteClient(action_data);
		
		if(!FODTrophyMenu.GetInstance().IsVisible())
		{
			UIManager uiManager = GetGame().GetUIManager();
			uiManager.CloseAll();
			uiManager.ShowScriptedMenu(FODTrophyMenu.GetInstance(), null);
		}
	}
	
	
	override void OnExecuteServer(ActionData action_data)
	{
	}
}