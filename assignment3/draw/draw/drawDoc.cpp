// drawDoc.cpp : CdrawDoc 类的实现
//

#include "stdafx.h"
#include "draw.h"

#include "drawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawDoc

IMPLEMENT_DYNCREATE(CdrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CdrawDoc, CDocument)
END_MESSAGE_MAP()


// CdrawDoc 构造/析构

CdrawDoc::CdrawDoc()
{
	// TODO: 在此添加一次性构造代码

}

CdrawDoc::~CdrawDoc()
{
}

BOOL CdrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CdrawDoc 序列化

void CdrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CdrawDoc 诊断

#ifdef _DEBUG
void CdrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdrawDoc 命令
