// gameView.h : CgameView ��Ľӿ�
//


#pragma once


class CgameView : public CView
{
protected: // �������л�����
	CgameView();
	DECLARE_DYNCREATE(CgameView)

// ����
public:
	CgameDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	void oninit();
	virtual ~CgameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	void CgameView::show(CDC *pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//afx_msg void OnStart();
};

#ifndef _DEBUG  // gameView.cpp �еĵ��԰汾
inline CgameDoc* CgameView::GetDocument() const
   { return reinterpret_cast<CgameDoc*>(m_pDocument); }
#endif

