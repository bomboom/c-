// drawDoc.cpp : CdrawDoc ���ʵ��
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


// CdrawDoc ����/����

CdrawDoc::CdrawDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CdrawDoc::~CdrawDoc()
{
}

BOOL CdrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CdrawDoc ���л�

void CdrawDoc::Serialize(CArchive& ar)
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


// CdrawDoc ���

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


// CdrawDoc ����
