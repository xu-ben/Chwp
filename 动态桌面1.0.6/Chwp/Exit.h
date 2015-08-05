#pragma once


// CExit 对话框

class CExit : public CDialog
{
	DECLARE_DYNAMIC(CExit)

public:
	CExit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CExit();

// 对话框数据
	enum { IDD = IDD_DIALOGEXIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	bool IFEXIT;
};
