// drawView.h : CdrawView 类的接口
//


#pragma once


class CdrawView : public CView
{
protected: // 仅从序列化创建
	CdrawView();
	DECLARE_DYNCREATE(CdrawView)

// 属性
public:
	CdrawDoc* GetDocument() const;

// 操作
public:
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CdrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	
};

#ifndef _DEBUG  // drawView.cpp 中的调试版本
inline CdrawDoc* CdrawView::GetDocument() const
   { return reinterpret_cast<CdrawDoc*>(m_pDocument); }
#endif

