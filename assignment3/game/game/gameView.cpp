// gameView.cpp : CgameView 类的实现
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
	// 标准打印命令
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

// CgameView 构造/析构

CgameView::CgameView()
{
	// TODO: 在此处添加构造代码

}

CgameView::~CgameView()
{
}

BOOL CgameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CgameView 绘制

void CgameView::OnDraw(CDC* pDC)
{
	CgameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//双缓冲防止闪屏
	CRect rc;
	CDC dcMem;
	GetClientRect(&rc);
	CBitmap bmp; //内存中承载临时图象的位图


	dcMem.CreateCompatibleDC(pDC); 
	bmp.CreateCompatibleBitmap(pDC,rc.Width(),rc.Height());
	CBitmap *pOldBit=dcMem.SelectObject(&bmp);
	 //按原来背景填充客户区，不然会是黑色
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
	pDC->TextOutA(520,100,_T("楼层：1"));
	pDC->TextOutA(520,120,_T("房间：中部"));
	pDC->TextOutA(520,140,_T("房间事件：空房间"));
	pDC->TextOutA(520,160,_T("任务：找到公主"));
	oninit();
	dcMem.DeleteDC();     
	bmp.DeleteObject(); 

	// TODO: 在此处为本机数据添加绘制代码
}


// CgameView 打印

BOOL CgameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CgameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CgameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CgameView 诊断

#ifdef _DEBUG
void CgameView::AssertValid() const
{
	CView::AssertValid();
}

void CgameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CgameDoc* CgameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CgameDoc)));
	return (CgameDoc*)m_pDocument;
}
#endif //_DEBUG


// CgameView 消息处理程序
BOOL CgameView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

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
	::MessageBox(NULL,_T("这里的房间有可数多个，你的任务是找到公主。"),_T("前言"),MB_OK);
}


void CgameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	
	
	//到另一个房间
	
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
	s2="楼层："+s;
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
			s3="房间：东"+s4+" 北"+s3;
		}
		else if(mast.numN == 0)
		{
			ss4<< mast.numE;
			ss4>> s4;
			s3="房间：东"+s4+" 中部";
			
		}
		else
		{
			ss4<< mast.numE;
			ss4>> s4;
			k=-mast.numN;
			ss3<< k;
			ss3>> s3;
			s3="房间：东"+s4+" 南"+s3;
		}
	}
	else if(mast.numE == 0)
	{
		if(mast.numN == 0)
		{
			s3="房间：中部";
			if(mast.r == 1 && mast.f == 1)
			{
				::MessageBox(NULL,_T("天哪。你逃出去了。"),_T("厉害"),MB_OK);	
				OnInitialUpdate();
			}
		}
		else if(mast.numN > 0)
		{
			ss4<< mast.numN;
			ss4>> s4;
			s3="房间：中部 北"+s4;
		}
		else
		{
			k=-mast.numN;
			ss4<< k;
			ss4>> s4;
			s3="房间：中部 南"+s4;
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
				s3="房间：西"+s4+" 北"+s3;
			}
			else if(mast.numN == 0)
			{
				k=-mast.numE;
				ss4<< k;
				ss4>> s4;
				s3="房间：西"+s4+" 中部";
				
			}
			else
			{
				k=-mast.numE;
				ss4<< k;
				ss4>> s4;
				k=-mast.numN;
				ss3<< k;
				ss3>> s3;
				s3="房间：西"+s4+" 南"+s3;
			}
	}
	DIR.Format(_T("%s"),s3.c_str());
	pDC->TextOutA(520,120,DIR);
	
	if(mast.i == 0)
	{
		pDC->TextOutA(520,140,_T("房间事件：空房间"));
	}
	else if(mast.i == 1)
	{
		pDC->TextOutA(520,140,_T("房间事件：有怪兽"));
	}
	else if(mast.i == 3)
	{
		pDC->TextOutA(520,140,_T("房间事件：公主房"));
	}
	
	if(mast.r == 2)
	{
		pDC->TextOutA(520,160,_T("任务：找到公主"));
	}
	else
	{
		pDC->TextOutA(520,160,_T("任务：走出城堡"));
	}

}


/*
void CgameView::OnStart()
{
	// TODO: Add your command handler code here
	
	::MessageBox(NULL,_T("你的任务是找到公主，是个黑色的方块。"),_T("前言"),MB_OK);
}
*/
