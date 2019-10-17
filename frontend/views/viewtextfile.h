#ifndef __VIEWTEXTFILE_H__
#define __VIEWTEXTFILE_H__

#include <frontend\views\viewgrid.h>

#include <kernel\structures\textfile.h>

/////////////////////////////////////////////////////////////////////////////
// CViewTextFile view

class CViewTextFile : public CViewGrid
{
// Attributes
protected:

  enum
  {
    CVIEWTEXTFILE_FIRSTVALUE = CViewGrid::CVIEWGRID_LASTVALUE + 1,
    CVIEWTEXTFILE_LASTVALUE
  };

// Attributes
protected:

  Handle<TextFile> m_File;

// Operations
private:

// Operations
protected:

	CViewTextFile();

	DECLARE_DYNCREATE(CViewTextFile)

	virtual CMenu *CreateGridMenu(CMenu *menu);
	virtual CMenu *CreateColumnMenu(CMenu *menu, ROWCOL nCol);
	virtual void   InitializeGridAppearance();
	virtual void   LoadDataIntoGrid();

// Attributes
public:

// Operations
public:

	virtual void   SetStructure(Structure *structure);

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewTextFile)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CViewTextFile();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CViewTextFile)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
/////////////////////////////////////////////////////////////////////////////
 
