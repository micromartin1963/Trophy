class FODTrophyMenu : UIScriptedMenu
{
	protected static ref FODTrophyMenu Instance;

	MultilineTextWidget m_InfoBox;
    ButtonWidget m_Btnenable;
	ButtonWidget m_Btndisable;
	ButtonWidget m_BtnCancel;
	protected TextWidget m_TextCenter;
	
	void FODTrophyMenu()
	{
	}
	
	void ~FODTrophyMenu()
	{
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
	}
	
	static FODTrophyMenu GetInstance()
	{
		if (!Instance)
        {
            Instance = new FODTrophyMenu();
			Instance.Init();
        }
		return Instance;
	}
	
	static void ClearInstance()
	{
		Instance = null;
	}
		
	
	override Widget Init()
    {		
	layoutRoot = GetGame().GetWorkspace().CreateWidgets("TrophyMenu/Scripts/4_World/layouts/FODTrophyMenu.layout");
	m_TextCenter = TextWidget.Cast(layoutRoot.FindAnyWidget("TextCenter"));
    m_Btnenable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_enable" ) );
	m_Btndisable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_disable" ) );
	m_BtnCancel = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_cancel" ) );
	layoutRoot.Show(false);		
    return layoutRoot;
    }
	
	override void OnShow()
	{
		super.OnShow();	
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
	
	}
	
	override void OnHide()
	{
		super.OnHide();
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
		Close();
	}
	
	override void Update(float timeslice)
	{
		super.Update(timeslice);

	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		super.OnClick(w, x, y, button);
	
		switch(w)
		{		
			case m_BtnCancel:
				GetGame().GetUIManager().HideScriptedMenu(this);
				return true;
				break;
		}
		return false;
	}
	
	override bool OnDoubleClick( Widget w, int x, int y, int button )
	{
		super.OnDoubleClick(w, x, y, button);
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		super.OnMouseEnter(w, x, y);
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		super.OnMouseLeave(w, enterW, x, y);
		return false;
	}
	
	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		super.OnChange(w,x,y,finished);
        return false;
	}

	

	

}