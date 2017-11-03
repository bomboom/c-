// gameView.h : CgameView 类的接口
//


#pragma once


class CgameView : public CView
{
protected: // 仅从序列化创建
	CgameView();
	DECLARE_DYNCREATE(CgameView)

// 属性
public:
	CgameDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	void oninit();
	virtual ~CgameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	void CgameView::show(CDC *pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//afx_msg void OnStart();
};

#ifndef _DEBUG  // gameView.cpp 中的调试版本
inline CgameDoc* CgameView::GetDocument() const
   { return reinterpret_cast<CgameDoc*>(m_pDocument); }
#endif

