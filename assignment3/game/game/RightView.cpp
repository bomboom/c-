// RightView.cpp : ʵ���ļ�
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


// CRightView ��ͼ

void CRightView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	
	pDC->TextOutA(20,80,_T("LV.1"));
	pDC->TextOutA(20,100,_T("¥�㣺1"));
	pDC->TextOutA(20,120,_T("���䣺�в�"));
	pDC->TextOutA(20,140,_T("�����¼����շ���"));
	pDC->TextOutA(20,160,_T("�����ҵ�����"));
	
	/*
	strstream ss;
	string s;
	ss << mast.x;
	ss >> s;
	
	CString DIR;
	DIR.Format(_T("%s"),s.c_str());
	pDC->TextOutA(20,80,DIR);
	*/
	//::MessageBox(NULL,_T("����������ҵ��������Ǹ���ɫ�ķ��顣"),_T("ǰ��"),MB_OK);
}


// CRightView ���

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

//CRightView��Ϣ����


