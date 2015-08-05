// Exit.cpp : 实现文件
//

#include "stdafx.h"
#include "Chwp.h"
#include "ChwpDlg.h"
#include "Exit.h"

// CExit 对话框

IMPLEMENT_DYNAMIC(CExit, CDialog)

CExit::CExit(CWnd* pParent /*=NULL*/)
	: CDialog(CExit::IDD, pParent)
	, IFEXIT(false)
{
	
}

CExit::~CExit()
{
}

void CExit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExit, CDialog)
	ON_BN_CLICKED(IDOK, &CExit::OnBnClickedOk)
END_MESSAGE_MAP()


// CExit 消息处理程序

void CExit::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	IFEXIT=true;
	OnOK();
}

//void CExit::OnBnClickedButton1()
//{
//	IfExit=true;
//	OnOK();
//	// TODO: 在此添加控件通知处理程序代码
//}
