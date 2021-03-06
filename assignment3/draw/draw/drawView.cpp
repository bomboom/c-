// drawView.cpp : CdrawView 类的实现
//

#include "stdafx.h"
#include "draw.h"

#include "drawDoc.h"
#include "drawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

people human;
// CdrawView

IMPLEMENT_DYNCREATE(CdrawView, CView)

BEGIN_MESSAGE_MAP(CdrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
//	ON_WM_LBUTTONDOWN()
//	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CdrawView 构造/析构

CdrawView::CdrawView()
{
	// TODO: 在此处添加构造代码

}

CdrawView::~CdrawView()
{
}

BOOL CdrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW, AfxGetApp()->LoadCursorA(IDC_ARROW), CreateSolidBrush(RGB(0,0,0)));
	return CView::PreCreateWindow(cs);
}

// CdrawView 绘制

void CdrawView::OnDraw(CDC* pDC)
{
	CdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawView 打印

BOOL CdrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CdrawView 诊断

#ifdef _DEBUG
void CdrawView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawDoc* CdrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawDoc)));
	return (CdrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawView 消息处理程序

void CdrawView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Rectangle(50,50,370,370);
	dc.Rectangle(30,180,51,260);
	dc.Rectangle(165,30,245,51);
	dc.Rectangle(369,180,390,260);
	dc.Rectangle(165,369,245,390);

	
	
	// 不为绘图消息调用 CView::OnPaint()

}




