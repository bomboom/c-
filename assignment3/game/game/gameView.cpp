// gameView.cpp : CgameView ���ʵ��
//

#include "stdafx.h"
#include "game.h"

#include "gameDoc.h"
#include "gameView.h"

#include "master.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct mast mast;

// CgameView

IMPLEMENT_DYNCREATE(CgameView, CView)

BEGIN_MESSAGE_MAP(CgameView, CView)
	// ��׼��ӡ����
	//ON_COMMAND(IDM_START, OnStart)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYUP()
//	ON_WM_PAINT()
//	ON_WM_ERASEBKGND()
//ON_WM_TIMER()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CgameView ����/����

CgameView::CgameView()
{
	// TODO: �ڴ˴���ӹ������

}

CgameView::~CgameView()
{
}

BOOL CgameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CgameView ����

void CgameView::OnDraw(CDC* pDC)
{
	CgameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//˫�����ֹ����
	CRect rc;
	CDC dcMem;
	GetClientRect(&rc);
	CBitmap bmp; //�ڴ��г�����ʱͼ���λͼ


	dcMem.CreateCompatibleDC(pDC); 
	bmp.CreateCompatibleBitmap(pDC,rc.Width(),rc.Height());
	CBitmap *pOldBit=dcMem.SelectObject(&bmp);
	 //��ԭ���������ͻ�������Ȼ���Ǻ�ɫ
	dcMem.FillSolidRect(rc,RGB(0,0,0));

	dcMem.Rectangle(60,60,460,460);
	CBrush brush(RGB(255,0,0));
	CBrush brush1(RGB(0,255,255));
	CBrush brush2(RGB(255,255,255));
	dcMem.FillRect(CRect(60,60,460,460),&brush1);
	dcMem.Rectangle(40,200,61,300);
	dcMem.FillRect(CRect(40,200,61,300),&brush1);
	dcMem.Rectangle(200,40,300,61);
	dcMem.FillRect(CRect(200,40,300,61),&brush1);
	dcMem.Rectangle(459,200,480,300);
	dcMem.FillRect(CRect(459,200,480,300),&brush1);
	dcMem.Rectangle(200,459,300,480);
	dcMem.FillRect(CRect(200,459,300,480),&brush1);
	dcMem.Rectangle(400,40,460,61);
	dcMem.FillRect(CRect(400,40,460,61),&brush2);
	dcMem.Rectangle(400,459,460,480);
	dcMem.FillRect(CRect(400,459,460,480),&brush2);

	/*
	CBrush DrawBrush=(RGB(100,100,100));
	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	pDC->Rectangle(10*20,10*20,11*20,11*20);
	pDC->SelectObject(DrawBrush);
	*/


	pDC->BitBlt(0,0,rc.Width(),rc.Height(),&dcMem,0,0,SRCCOPY);
	pDC->TextOutA(520,80,_T("LV.1"));
	pDC->TextOutA(520,100,_T("¥�㣺1"));
	pDC->TextOutA(520,120,_T("���䣺�в�"));
	pDC->TextOutA(520,140,_T("�����¼����շ���"));
	pDC->TextOutA(520,160,_T("�����ҵ�����"));
	oninit();
	dcMem.DeleteDC();     
	bmp.DeleteObject(); 

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CgameView ��ӡ

BOOL CgameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CgameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CgameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CgameView ���

#ifdef _DEBUG
void CgameView::AssertValid() const
{
	CView::AssertValid();
}

void CgameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CgameDoc* CgameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CgameDoc)));
	return (CgameDoc*)m_pDocument;
}
#endif //_DEBUG


// CgameView ��Ϣ�������
BOOL CgameView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return true;
	//return CView::OnEraseBkgnd(pDC);
}

void CgameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	mast.x = 10;
	mast.y = 10;
	mast.f = 1;
	mast.r = 2;
	mast.numE = 0;
	mast.numN = 0;
	mast.i = 0;
	mast.lv = 1;
	::MessageBox(NULL,_T("����ķ����п������������������ҵ�������"),_T("ǰ��"),MB_OK);
}


void CgameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC=GetDC();
	pDC->Rectangle(60,60,460,460);	
	CBrush brush1(RGB(0,255,255));
	CBrush brush2(RGB(255,255,255));
	pDC->FillRect(CRect(60,60,460,460),&brush1);
	
	pDC->SelectStockObject(BLACK_PEN);

	CBrush DrawBrush=(RGB(100,100,100));
	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	
	switch(nChar)
	{
	case VK_UP:
		if(mast.y>3 || mast.y==3 && mast.x>=10 && mast.x<15 || mast.y==3 && mast.x>=20 && mast.x<23 )
		{mast.y--;}
		break;
	case VK_DOWN:
		if(mast.y<22 || mast.y==22 && mast.x>=10 && mast.x<15 || mast.y==22 && mast.x>=20 && mast.x<23 )
		{mast.y++;}
		break;
	case VK_LEFT:
		if(mast.x>3 || mast.x==3 && mast.y>=10 && mast.y<15)
		{mast.x--;}
		break;
	case VK_RIGHT:
		if(mast.x<22 || mast.x==22 && mast.y>=10 && mast.y<15)
		{mast.x++;}
		break;
	}
	pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
	pDC->SelectObject(DrawBrush);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	
	
	//����һ������
	
	master h;
	if(mast.y==2 && mast.x>=10 && mast.x<15)
	{	
		
		pDC->Rectangle(200,40,300,61);
		pDC->FillRect(CRect(200,40,300,61),&brush1);
		mast.y = 22;
		pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
		pDC->SelectObject(DrawBrush);
		
		mast.numN++;
		mast.i = h.randint(mast.r);
		h.randthing(mast.i);
		if(mast.i == 3){mast.r = 1;}
		if(mast.i == 2){OnInitialUpdate();}
		if(mast.i == 1){mast.lv ++;}
		show(pDC);
	}
	if(mast.y==2 && mast.x>=20 && mast.x<23)
	{
		pDC->Rectangle(400,40,460,61);
		pDC->FillRect(CRect(400,40,460,61),&brush2);
		mast.y = 22;
		pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
		pDC->SelectObject(DrawBrush);

		mast.f++;
		mast.i = h.randint(mast.r);
		h.randthing(mast.i);
		if(mast.i == 3){mast.r = 1;}
		if(mast.i == 2){OnInitialUpdate();}
		if(mast.i == 1){mast.lv ++;}
		show(pDC);
	}
	if(mast.y==23 && mast.x>=10 && mast.x<15)
	{
		pDC->Rectangle(200,459,300,480);
		pDC->FillRect(CRect(200,459,300,480),&brush1);
		mast.y = 3;
		pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
		pDC->SelectObject(DrawBrush);
		
		mast.numN--;
		mast.i = h.randint(mast.r);
		h.randthing(mast.i);
		if(mast.i == 3){mast.r = 1;}
		if(mast.i == 2){OnInitialUpdate();}
		if(mast.i == 1){mast.lv ++;}
		show(pDC);
	}
	if(mast.y==23 && mast.x>=20 && mast.x<23)
	{
		
		pDC->Rectangle(400,459,460,480);
		pDC->FillRect(CRect(400,459,460,480),&brush2);
		mast.y = 3;
		pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
		pDC->SelectObject(DrawBrush);
		
		mast.f--;
		mast.i = h.randint(mast.r);
		h.randthing(mast.i);
		if(mast.i == 3){mast.r = 1;}
		if(mast.i == 2){OnInitialUpdate();}
		if(mast.i == 1){mast.lv ++;}
		show(pDC);
	}
	if(mast.x==2)
	{
		pDC->Rectangle(40,200,61,300);
		pDC->FillRect(CRect(40,200,61,300),&brush1);
		mast.x = 22;
		pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
		pDC->SelectObject(DrawBrush);
		
		mast.numE--;
		mast.i = h.randint(mast.r);
		h.randthing(mast.i);
		if(mast.i == 3){mast.r = 1;}
		if(mast.i == 2){OnInitialUpdate();}
		if(mast.i == 1){mast.lv ++;}
		show(pDC);
	}
	if(mast.x==23)
	{
		pDC->Rectangle(459,200,480,300);
		pDC->FillRect(CRect(459,200,480,300),&brush1);
		mast.x = 3;
		pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
		pDC->SelectObject(DrawBrush);
		
		mast.numE++;
		mast.i = h.randint(mast.r);
		h.randthing(mast.i);
		if(mast.i == 3){mast.r = 1;}
		if(mast.i == 2){OnInitialUpdate();}
		if(mast.i == 1){mast.lv ++;}
		show(pDC);
	}

}

void CgameView::oninit()
{
	CDC *pDC=GetDC();
	CBrush DrawBrush=(RGB(100,100,100));
	CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	pDC->Rectangle(mast.x*20,mast.y*20,(mast.x+1)*20,(mast.y+1)*20);
	pDC->SelectObject(DrawBrush);

}


void CgameView::show(CDC *pDC)
{
	CBrush brush1(RGB(0,0,0));
	pDC->Rectangle(520,80,800,200);
	pDC->FillRect(CRect(520,80,800,200),&brush1);
	
	strstream ss,ss2,ss3,ss4;
	string s;
	string s2;
	string s3;
	string s4;
	string s5;
	int k;
	CString DIR;
	
	ss2 << mast.lv;
	ss2 >> s5;
	s5 = "LV."+s5;
	DIR.Format(_T("%s"),s5.c_str());
	pDC->TextOutA(520,80,DIR);
	
	
	ss << mast.f;
	ss >> s;
	s2="¥�㣺"+s;
	DIR.Format(_T("%s"),s2.c_str());
	pDC->TextOutA(520,100,DIR);
	
	if(mast.numE > 0)
	{
		if(mast.numN > 0)
		{
			ss4<< mast.numE;
			ss4>> s4;
			ss3<< mast.numN;
			ss3>> s3;
			s3="���䣺��"+s4+" ��"+s3;
		}
		else if(mast.numN == 0)
		{
			ss4<< mast.numE;
			ss4>> s4;
			s3="���䣺��"+s4+" �в�";
			
		}
		else
		{
			ss4<< mast.numE;
			ss4>> s4;
			k=-mast.numN;
			ss3<< k;
			ss3>> s3;
			s3="���䣺��"+s4+" ��"+s3;
		}
	}
	else if(mast.numE == 0)
	{
		if(mast.numN == 0)
		{
			s3="���䣺�в�";
			if(mast.r == 1 && mast.f == 1)
			{
				::MessageBox(NULL,_T("���ġ����ӳ�ȥ�ˡ�"),_T("����"),MB_OK);	
				OnInitialUpdate();
			}
		}
		else if(mast.numN > 0)
		{
			ss4<< mast.numN;
			ss4>> s4;
			s3="���䣺�в� ��"+s4;
		}
		else
		{
			k=-mast.numN;
			ss4<< k;
			ss4>> s4;
			s3="���䣺�в� ��"+s4;
		}
	}
	else
	{
		if(mast.numN > 0)
			{
				k=-mast.numE;
				ss4<< k;
				ss4>> s4;
				ss3<< mast.numN;
				ss3>> s3;
				s3="���䣺��"+s4+" ��"+s3;
			}
			else if(mast.numN == 0)
			{
				k=-mast.numE;
				ss4<< k;
				ss4>> s4;
				s3="���䣺��"+s4+" �в�";
				
			}
			else
			{
				k=-mast.numE;
				ss4<< k;
				ss4>> s4;
				k=-mast.numN;
				ss3<< k;
				ss3>> s3;
				s3="���䣺��"+s4+" ��"+s3;
			}
	}
	DIR.Format(_T("%s"),s3.c_str());
	pDC->TextOutA(520,120,DIR);
	
	if(mast.i == 0)
	{
		pDC->TextOutA(520,140,_T("�����¼����շ���"));
	}
	else if(mast.i == 1)
	{
		pDC->TextOutA(520,140,_T("�����¼����й���"));
	}
	else if(mast.i == 3)
	{
		pDC->TextOutA(520,140,_T("�����¼���������"));
	}
	
	if(mast.r == 2)
	{
		pDC->TextOutA(520,160,_T("�����ҵ�����"));
	}
	else
	{
		pDC->TextOutA(520,160,_T("�����߳��Ǳ�"));
	}

}


/*
void CgameView::OnStart()
{
	// TODO: Add your command handler code here
	
	::MessageBox(NULL,_T("����������ҵ��������Ǹ���ɫ�ķ��顣"),_T("ǰ��"),MB_OK);
}
*/
