// ChwpDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


static HRESULT hr;
static IActiveDesktop* pIAD;

// 线程处理函数
//void ThreadProc(void);
//用于存放墙纸路径的全局数组
static CString StrRam[1000];
//用于存放墙纸显示模式的全局数组
static int ModeRam[1000]={0};
//线程函数中的当前墙纸序号
static int RunPaper;
//线程函数中的更新时间
static int RunTime;
//指示程序是否应该结束
static bool IfExit=false;
//线程函数中的墙纸数量
static int Papernum;
//线程中的墙纸显示模式
static int mode;
//指示线程是否正在换桌面
static bool changing=false;
//线程中的当前墙纸路径
static CString str;
//指示随机模式是否选中
static BOOL Check;
	// 上次更新时的年份
static int m_lastupdateyear=0;
	// 上次更新时的天数
static int m_lastupdateday=0;
	// 上次更新的时的小时数
static int m_lastupdatehour=0;
	// 上次更新时的分钟数
static int m_lastupdateminute=0;
	// 上次更新时的秒钟数
static int m_lastupdatesecond=0;

// CChwpDlg 对话框
class CChwpDlg : public CDialog
{
// 构造
public:
	CChwpDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHWP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
protected:
	NOTIFYICONDATA data;
public:
	CSpinButtonCtrl m_spin1;
	CSpinButtonCtrl m_spin2;
	CSpinButtonCtrl m_spin3;
	CSpinButtonCtrl m_spin4;
	CListCtrl m_list1;
protected:
	CImageList m_image;
	LRESULT OnStatusIcon(WPARAM wparam, LPARAM lparam);
public:
	// 系统信息区图标的右键弹出菜单
	void OnContextMenu(CWnd* pWnd);
protected:
	// 弹出式菜单显示关于对话框
	void OnMenuAbout(void);
	// 弹出式菜单的退出按钮
	void OnMenuExit(void);
protected:
	afx_msg void OnAddpaper();
public:
	afx_msg void OnDeletepaper();
	// 组合框映射的变量，指示墙纸显示模式
	CComboBox m_dispmode;
protected:
	// 指示当前墙纸的序号
	int m_curpaper;
	// 日期
	COleDateTime m_date;
public:
	// 当前日期（天）
	int m_currentday;
	// 当前时间（小时）
	int m_currenthour;
	// 当前时间（分钟）
	int m_currentminute;
	// 当前时间（秒钟）
	int m_currentsecond;
	// 设置的更新时间中的天数
	int m_paperday;
	// 设置的更新时间的小时数
	int m_paperhour;
	// 设置的更新时间中的分钟数
	int m_paperminute;
	// 设置的更新时间的秒钟数
	int m_papersecond;
	// 当前时间的年份
	int m_currentyear;

protected:
	afx_msg void OnOk();
	// 隐藏主窗体
	BOOL OnHideWindow(void);
protected:
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	// 图片框变量
	CStatic m_picture;
public:
	// 实现选中图片的预览
	BOOL OnPreviewPaper(void);

//protected:
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	// 时钟触发器
//	UINT m_timer;

protected:
	afx_msg void OnChangeMode();
public:
	// 当前墙纸数量
	int num;
protected:
	// 当双击通知栏上的图标时调用的函数
	void OnShowMainDialog(void);
public:
	// 鼠标左键单击通知栏图标时调用的函数
	void OnContextMenu2(CWnd * pWnd);
protected:
	// “下一张桌面”菜单的响应函数
	void OnNext(void);
	// “上一张桌面”菜单的响应函数
	void OnLast(void);
	// 暂停菜单的响应函数
	void OnPause(void);
	// 继续菜单的响应函数
	void OnContinue(void);
	// 设置图片为桌面背景

public:
	 BOOL SetWallPaper();
	// 当前墙纸的显示模式
	DWORD curdispmode;
	// 当前墙纸的路径
	CString strPicFile;

public:
	// 指示时钟触发器是否开启
	bool RUN;

protected:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	// 颜色画刷
	CBrush m_brush;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	// 指示是否选中随机模式
	BOOL CheckRand;
public:
	CWinThread *pThread;
	// 当前屏幕分辨率横坐标
	int X;
	// 当前屏幕分辨率纵坐标
	int Y;
	afx_msg void OnBnClickedButtonhide();
	afx_msg void OnBnClickedButtonpause();
	afx_msg void OnBnClickedButtoncontinue();
	afx_msg void OnBnClickedButtonlast();
	afx_msg void OnBnClickedButtonnext();
};
	UINT ThreadProc(LPVOID pParam);
