// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	[!if CHECKBOX_MAXIMIZE_BOX]
	void OnSize(UINT nType, CSize size);
	[!endif]

	void OnBtnMsgBox();
	[!if CHECKBOX_SHELLNOTIFYICON]
	//托盘通知消息处理函数
	LRESULT OnIconNotify(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL/* bHandled*/);
	//演示如何响应菜单事件
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);
	[!endif]
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);


protected:
	[!if CHECKBOX_DYNAMIC_TRANSLATOR_SUPPORT]
	void OnLanguage(int nID);
	void OnLanguageBtnCN();
	void OnLanguageBtnJP();
	[!endif]
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		[!if CHECKBOX_DYNAMIC_TRANSLATOR_SUPPORT]
		EVENT_NAME_COMMAND(L"zh_cn", OnLanguageBtnCN)
		EVENT_NAME_COMMAND(L"jp", OnLanguageBtnJP)
		[!endif]
	EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		[!if CHECKBOX_MAXIMIZE_BOX]
		MSG_WM_SIZE(OnSize)
		[!endif]
		[!if CHECKBOX_SHELLNOTIFYICON]
	//托盘消息处理
		MESSAGE_HANDLER(WM_ICONNOTIFY, OnIconNotify)
		MSG_WM_COMMAND(OnCommand)
		[!endif]
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	[!if CHECKBOX_SHELLNOTIFYICON]
	SShellNotifyIcon shellNotifyIcon;
	[!endif]
};
