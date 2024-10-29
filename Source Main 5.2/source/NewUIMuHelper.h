#pragma once
#include "NewUIBase.h"
#include "NewUIManager.h"
#include "NewUIButton.h"

namespace SEASON3B
{
    class CNewUIMuHelper : public CNewUIObj
    {
    public:
        enum IMAGE_LIST
        {
            IMAGE_BASE_WINDOW_BACK = CNewUIMessageBoxMng::IMAGE_MSGBOX_BACK,				//. newui_msgbox_back.jpg
            IMAGE_BASE_WINDOW_TOP = CNewUIMyInventory::IMAGE_INVENTORY_BACK_TOP,			//. newui_item_back01.tga	(190,64)
            IMAGE_BASE_WINDOW_LEFT = CNewUIMyInventory::IMAGE_INVENTORY_BACK_LEFT,		//. newui_item_back02-l.tga	(21,320)
            IMAGE_BASE_WINDOW_RIGHT = CNewUIMyInventory::IMAGE_INVENTORY_BACK_RIGHT,		//. newui_item_back02-r.tga	(21,320)
            IMAGE_BASE_WINDOW_BOTTOM = CNewUIMyInventory::IMAGE_INVENTORY_BACK_BOTTOM,	//. newui_item_back03.tga	(190,45)
            IMAGE_BASE_WINDOW_BTN_EXIT = CNewUIMyInventory::IMAGE_INVENTORY_EXIT_BTN,		//. newui_exit_00.tga
            //--
            IMAGE_TABLE_TOP_LEFT = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_TOP_LEFT,			//. newui_item_table01(L).tga (14,14)
            IMAGE_TABLE_TOP_RIGHT = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_TOP_RIGHT,			//. newui_item_table01(R).tga (14,14)
            IMAGE_TABLE_BOTTOM_LEFT = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_BOTTOM_LEFT,		//. newui_item_table02(L).tga (14,14)
            IMAGE_TABLE_BOTTOM_RIGHT = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_BOTTOM_RIGHT,	//. newui_item_table02(R).tga (14,14)
            IMAGE_TABLE_TOP_PIXEL = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_TOP_PIXEL,			//. newui_item_table03(up).tga (1, 14)
            IMAGE_TABLE_BOTTOM_PIXEL = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_BOTTOM_PIXEL,	//. newui_item_table03(dw).tga (1,14)
            IMAGE_TABLE_LEFT_PIXEL = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_LEFT_PIXEL,		//. newui_item_table03(L).tga (14,1)
            IMAGE_TABLE_RIGHT_PIXEL = CNewUIInventoryCtrl::IMAGE_ITEM_TABLE_RIGHT_PIXEL,		//. newui_item_table03(R).tga (14,1)
            //--
            IMAGE_WINDOW_TAB_BTN = CNewUIGuildInfoWindow::IMAGE_GUILDINFO_TAB_BUTTON,
            //--
            IMAGE_MACROUI_HELPER_RAGEMINUS = BITMAP_INTERFACE_MACROUI_BEGIN,		// newui_position02.tga			(70, 25)
            IMAGE_MACROUI_HELPER_OPTIONBUTTON = BITMAP_INTERFACE_MACROUI_BEGIN + 1,		// newui_position02.tga			(70, 25)
            IMAGE_MACROUI_HELPER_INPUTNUMBER = BITMAP_INTERFACE_MACROUI_BEGIN + 2,
            IMAGE_MACROUI_HELPER_INPUTSTRING = BITMAP_INTERFACE_MACROUI_BEGIN + 3,
            //-- Buttons
            IMAGE_CHAINFO_BTN_STAT = BITMAP_INTERFACE_NEW_CHAINFO_WINDOW_BEGIN + 1,
            IMAGE_CLEARNESS_BTN = BITMAP_CURSEDTEMPLE_BEGIN + 4,
            IMAGE_IGS_BUTTON = BITMAP_IGS_MSGBOX_BUTTON,

            //-- Skills
            IMAGE_SKILL1 = BITMAP_INTERFACE_NEW_SKILLICON_BEGIN,
            IMAGE_SKILL2,
            IMAGE_COMMAND,
            IMAGE_SKILL3,
            IMAGE_SKILLBOX,
            IMAGE_SKILLBOX_USE,
            IMAGE_NON_SKILL1,
            IMAGE_NON_SKILL2,
            IMAGE_NON_COMMAND,
            IMAGE_NON_SKILL3,
        };

        enum CLASS_LIST_ {
            Dark_Wizard = 0,
            Dark_Knight,
            Fairy_Elf,
            Magic_Gladiator,
            Dark_Lord,
            Summoner,
            Rage_Fighter,
        };
    private:
        static constexpr int MAX_SKILLS_SIZE = 6;
        static constexpr int WINDOW_WIDTH = 190;
        static constexpr int WINDOW_HEIGHT = 429;

        typedef struct
        {
            int iNumTab;
            BYTE class_character[MAX_CLASS];
            CNewUIButton* btn;
        } CButtonTap;

        typedef struct
        {
            int iNumTab;
            BYTE class_character[MAX_CLASS];
            CNewUICheckBox* box;
        } CheckBoxTap;

        typedef struct
        {
            int iNumTab;
            int s_ImgIndex;
            POINT m_Pos;
            POINT m_Size;
            BYTE class_character[MAX_CLASS];
        } cTexture;

        typedef struct
        {
            int iNumTab;
            POINT m_Pos;
            std::wstring m_Name;
            BYTE class_character[MAX_CLASS];
        } cTextName;

        typedef std::map<int, CButtonTap> cButtonMap;
        typedef std::map<int, CheckBoxTap> cCheckBoxMap;
        typedef std::map<int, cTexture> cTextureMap;
        typedef std::map<int, cTextName> cTextNameMap;

    private:
        CNewUIManager* m_pNewUIMng;
        POINT m_Pos;
        CNewUIRadioGroupButton m_TabBtn;
        int m_iNumCurOpenTab;
        cButtonMap m_ButtonList;
        cCheckBoxMap m_CheckBoxList;
        cTextNameMap m_TextNameList;
        cTextureMap m_IconList;
        int m_selectedIconIndex;
        int m_aiSelectedSkills[MAX_SKILLS_SIZE] = {-1, -1, -1, -1, -1, -1};
    public:
        void RenderBtnList();
        int UpdateMouseBtnList();
        void RegisterBtnCharacter(BYTE class_character, int Identifier);
        void RegisterButton(int Identifier, CButtonTap button);
        void InsertButton(int imgindex, int x, int y, int sx, int sy, bool overflg, bool isimgwidth, bool bClickEffect, bool MoveTxt,std::wstring btname,std::wstring tooltiptext, int Identifier, int iNumTab);
        //--
        void RenderBoxList();
        int UpdateMouseBoxList();
        void RegisterBoxCharacter(BYTE class_character, int Identifier);
        void RegisterCheckBox(int Identifier, CheckBoxTap button);
        void InsertCheckBox(int imgindex, int x, int y, int sx, int sy, bool overflg,std::wstring btname, int Identifier, int iNumTab);
        //--
        void RenderIconList();
        int UpdateMouseIconList();
        void RegisterIconCharacter(BYTE class_character, int Identifier);
        void RegisterIcon(int Identifier, cTexture button);
        void InsertIcon(int imgindex, int x, int y, int sx, int sy, int Identifier, int iNumTab);
        //--
        void RenderTextList();
        void RegisterTextCharacter(BYTE class_character, int Identifier);
        void RegisterTextur(int Identifier, cTextName button);
        void InsertText(int x, int y,std::wstring Name, int Identifier, int iNumTab);
    public:
        CNewUIMuHelper();
        virtual ~CNewUIMuHelper();

        bool Create(CNewUIManager* pNewUIMng, int x, int y);
        void Release();

        bool Render();
        bool Update();
        bool UpdateMouseEvent();
        bool UpdateKeyEvent();

        float GetLayerDepth();
        float GetKeyEventOrder();

        void InitText();
        void InitImage();
        void InitButtons();
        void InitCheckBox();
        void SetPos(int x, int y);
        void RenderBack(int x, int y, int width, int height);

        void AssignSkill(int skillIndex);
        void RenderSkillIcon(int iIndex, float x, float y, float width, float height);

    private:
        void LoadImages();
        void UnloadImages();
    };

    class CNewUIMuHelperSkillList : public CNewUIObj
    {
        enum EVENT_STATE
        {
            EVENT_NONE = 0,

            // currentskill
            EVENT_BTN_HOVER_CURRENTSKILL,
            EVENT_BTN_DOWN_CURRENTSKILL,

            // skillhotkey
            EVENT_BTN_HOVER_SKILLHOTKEY,
            EVENT_BTN_DOWN_SKILLHOTKEY,

            // skilllist
            EVENT_BTN_HOVER_SKILLLIST,
            EVENT_BTN_DOWN_SKILLLIST,
        };

    public:
        static constexpr int MAX_SKILLS_SIZE = 6;

        enum IMAGE_LIST
        {
            IMAGE_SKILL1 = BITMAP_INTERFACE_NEW_SKILLICON_BEGIN,
            IMAGE_SKILL2,
            IMAGE_COMMAND,
            IMAGE_SKILL3,
            IMAGE_SKILLBOX,
            IMAGE_SKILLBOX_USE,
            IMAGE_NON_SKILL1,
            IMAGE_NON_SKILL2,
            IMAGE_NON_COMMAND,
            IMAGE_NON_SKILL3,
        };

        CNewUIMuHelperSkillList();
        virtual ~CNewUIMuHelperSkillList();

        bool Create(CNewUIManager* pNewUIMng, CNewUI3DRenderMng* pNewUI3DRenderMng);
        void Release();

        bool UpdateMouseEvent();
        bool UpdateKeyEvent();
        bool Update();
        bool Render();
        void RenderSkillInfo();
        float GetLayerDepth();

        void Reset();

        int UpdateMouseSkillList();
        int GetSkillIndex(int iSkillType);

        static void UI2DEffectCallback(LPVOID pClass, DWORD dwParamA, DWORD dwParamB);


    private:
        void LoadImages();
        void UnloadImages();

        void RenderSkillIcon(int iIndex, float x, float y, float width, float height);

        void ResetMouseLButton();

    private:
        typedef struct
        {
            int index;
            POINT location;
            SIZE area;
        } cSkillIcon;

        std::map<int, cSkillIcon> m_skillIconMap;

        CNewUIManager* m_pNewUIMng;
        CNewUI3DRenderMng* m_pNewUI3DRenderMng;

        int m_aiAssignedSkill[MAX_SKILLS_SIZE];

        bool m_bShowSkillList;

        bool m_bRenderSkillInfo;
        int m_iRenderSkillInfoType;
        int m_iRenderSkillInfoPosX;
        int m_iRenderSkillInfoPosY;

        EVENT_STATE m_EventState;
    };

}