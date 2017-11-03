// RightView.cpp : 实现文件
//

#include "stdafx.h"
#include "game.h"
#include "RightView.h"

#include "master.h"

extern struct mast mast;

// CRightView

IMPLEMENT_DYNCREATE(CRightView, CView)

CRightView::CRightView()
{
	
}

CRightView::~CRightView()
{
}

BEGIN_MESSAGE_MAP(CRightView, CView)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRightView 绘图

void CRightView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	
	pDC->TextOutA(20,80,_T("LV.1"));
	pDC->TextOutA(20,100,_T("楼层：1"));
	pDC->TextOutA(20,120,_T("房间：中部"));
	pDC->TextOutA(20,140,_T("房间事件：空房间"));
	pDC->TextOutA(20,160,_T("任务：找到公主"));
	
	/*
	strstream ss;
	string s;
	ss << mast.x;
	ss >> s;
	
	CString DIR;
	DIR.Format(_T("%s"),s.c_str());
	pDC->TextOutA(20,80,DIR);
	*/
	//::MessageBox(NULL,_T("你的任务是找到公主，是个黑色的方块。"),_T("前言"),MB_OK);
}


// CRightView 诊断

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG

//CRightView消息处理


