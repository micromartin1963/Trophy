class TrophyMenu extends UIScriptedMenu
{

	protected static ref TrophyMenu instance;
    private bool m_Initialized = false;
    private bool m_IsMyMenuOpen;

    MultilineTextWidget m_InfoBox;
    ButtonWidget m_Btnenable;
	ButtonWidget m_Btndisable;
	ButtonWidget m_BtnCancel;
	protected TextWidget m_TextCenter;

	bool m_active = false;

	void TrophyMenu()
	{		

	}	
	
	void ~TrophyMenu()
	{
        //GetGame().GetUIManager().Back();
       // g_Game.GetUIManager().ShowCursor(true);
       // g_Game.GetUIManager().ShowUICursor(false);
       // GetGame().GetInput().ResetGameFocus();
       // GetGame().GetMission().PlayerControlEnable(false);
      //  GetGame().GetMission().GetHud().Show( true );
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);

	}


		static TrophyMenu GetInstance()
	{
		if (!instance)
        {
            instance = new TrophyMenu();
			instance.Init();
        }
		return instance;
	}
	
	static void ClearInstance()
	{
		instance = null;
	}


    override Widget Init()
    {

	layoutRoot = GetGame().GetWorkspace().CreateWidgets( "TrophyMenu/GUI/layouts/TrophyMenu.layout" );
	m_TextCenter = TextWidget.Cast(layoutRoot.FindAnyWidget("TextCenter"));
        m_Btnenable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_enable" ) );
	m_Btndisable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_disable" ) );
	m_BtnCancel = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_cancel" ) );


	m_active = true;
		
        return layoutRoot;
    }
	



	override void Update(float timeslice)
	{
	super.Update(timeslice);

        autoptr Widget underCursor = GetWidgetUnderCursor();
        if (underCursor == null) return;


		if (!m_active)
		GetGame().GetUIManager().Back();
		GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
	}


	override void OnShow()
	{
		super.OnShow();

		//PPEffects.SetBlurMenu(0.5);
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);

		//GetGame().GetInput().ChangeGameFocus(1);

		//SetFocus( layoutRoot );
	}

	override void OnHide()
	{
		super.OnHide();

		PPEffects.SetBlurMenu(0);

		//GetGame().GetInput().ResetGameFocus();
		
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);


		Close();
	}


	override bool OnClick( Widget w, int x, int y, int button )
	{
		super.OnClick(w, x, y, button);

		//PlayerBase m_Player = g_Game.GetPlayer();
		
		
		if ( w == m_BtnCancel )
		{
			GetGame().GetUIManager().Back();
			GetGame().GetUIManager().HideScriptedMenu(this);
			//UIManager uiManager = GetGame().GetUIManager();
			//uiManager.CloseAll();
			return true;
		}
		


		return false;
	}
	

	


    void SetMenuOpen(bool isMenuOpen) {
        m_IsMyMenuOpen = isMenuOpen;
        if (m_IsMyMenuOpen)
            PPEffects.SetBlurMenu( 0.5 );
        else
            PPEffects.SetBlurMenu( 0 );
    }


	




}