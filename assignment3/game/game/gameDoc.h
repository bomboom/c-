// gameDoc.h : CgameDoc ��Ľӿ�
//


#pragma once


class CgameDoc : public CDocument
{
protected: // �������л�����
	CgameDoc();
	DECLARE_DYNCREATE(CgameDoc)

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
	virtual ~CgameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


