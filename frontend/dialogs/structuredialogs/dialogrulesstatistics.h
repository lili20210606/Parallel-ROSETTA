// dialogrulesstatistics.h : header file
//

#include <frontend\dialogs\mylistctrl.h>

#include <kernel\structures\rules.h>

/////////////////////////////////////////////////////////////////////////////
// CDialogRulesStatistics dialog

class CDialogRulesStatistics : public CDialog
{
// Attributes
private:

  Handle<Rules> m_Rules;

// Operations
private:

  void CalculateStatistics();

public:

  void SetRules(Rules *Rules);

// Construction
public:
	CDialogRulesStatistics(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogRulesStatistics)
	enum { IDD = IDD_RULES_STATISTICS };
	CMyListCtrl	m_DescriptorStats;
	CString	m_Size;
	CString	m_Name;
	CString m_MeanStrength;
	CString	m_StdDevStrength;
	CString	m_MedianStrength;
	CString	m_MinimumStrength;
	CString	m_MaximumStrength;
	CString	m_NoDeterministic;
	CString	m_MaximumLength;
	CString	m_MeanLength;
	CString	m_MedianLength;
	CString	m_MinimumLength;
	CString	m_StdDevLength;
	CString	m_NoTotalLHSDescriptors;
	CString	m_NoUniqueLHSDescriptors;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogRulesStatistics)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogRulesStatistics)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
 
