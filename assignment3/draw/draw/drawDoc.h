// drawDoc.h : CdrawDoc ��Ľӿ�
//


#pragma once


class CdrawDoc : public CDocument
{
protected: // �������л�����
	CdrawDoc();
	DECLARE_DYNCREATE(CdrawDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CdrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


