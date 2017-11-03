// gameDoc.cpp : CgameDoc 类的实现
//

#include "stdafx.h"
#include "game.h"

#include "gameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CgameDoc

IMPLEMENT_DYNCREATE(CgameDoc, CDocument)

BEGIN_MESSAGE_MAP(CgameDoc, CDocument)
END_MESSAGE_MAP()


// CgameDoc 构造/析构

CgameDoc::CgameDoc()
{
	// TODO: 在此添加一次性构造代码

}

CgameDoc::~CgameDoc()
{
}

BOOL CgameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CgameDoc 序列化

void CgameDoc::Serialize(CArchive& ar)
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


// CgameDoc 诊断

#ifdef _DEBUG
void CgameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CgameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CgameDoc 命令
