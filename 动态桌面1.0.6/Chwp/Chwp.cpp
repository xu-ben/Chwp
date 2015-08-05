// Chwp.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Chwp.h"
#include "ChwpDlg.h"

#include <shlobj.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChwpApp

BEGIN_MESSAGE_MAP(CChwpApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CChwpApp 构造

CChwpApp::CChwpApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CChwpApp 对象

CChwpApp theApp;


// CChwpApp 初始化

BOOL CChwpApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();
	AfxOleInit();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
/////////////////////////////////////////////////////////

	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	_splitpath(__argv[0],drive,dir,fname,ext);//拆分文件名，将完整路径拆分为四个部分，分别处理
	if(drive[0]>96&&drive[0]<123)
		drive[0]-=32;
	CString path(drive);
	path+=dir;
	path+="动态桌面.exe";
	TCHAR m_path[MAX_PATH];
	wsprintf(m_path,path);

	//设置本程序为开机启动
	HKEY hkey;
	RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Microsoft\\Windows\\Currentversion\\Run",0,KEY_WRITE,& hkey);//打开注册表项
	RegSetValueEx(hkey,"动态桌面",0,REG_SZ,(LPBYTE)m_path,lstrlen(m_path)+1);//设置注册表键值
	RegCloseKey(hkey);							//释放指定注册键的句柄
	SetRegistryKey(_T("动态桌面"));//在注册表中写入本程序名
	LoadStdProfileSettings(1000);			//确保并且加载最近使用的文件和最后浏览的状态
////////////////////////////////////////////
///////////////////////////////////////////
	CChwpDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}
