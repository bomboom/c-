// gameDoc.cpp : CgameDoc ���ʵ��
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


// CgameDoc ����/����

CgameDoc::CgameDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CgameDoc::~CgameDoc()
{
}

BOOL CgameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CgameDoc ���л�

void CgameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CgameDoc ���

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


// CgameDoc ����
