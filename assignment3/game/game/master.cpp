#include "stdafx.h"
#include "master.h"

bool master::Gen(int n)
{
	srand((unsigned)time(0));

	int i= rand() % 100;

	if( i<n )
	  return true;
	else
	  return false;

}

int master::randint(int n)
{
	
	//���������
	if(n==2)
	{
		if(master::Gen(80))
		{
			if(master::Gen(30))
			{
				if(master::Gen(15))
				{
					return 2;
				}
				else
				{
					return 1;	
			
				}
			}
			else 
			{
				return 0;
			}
		}
		else
		{
			return 3;
		}
	}
	else if(n==1)
	{
		if(master::Gen(30))
		{
			if(master::Gen(4))
			{
				return 2;
			}
			else
			{
				return 1;	
		
			}
		}
		else 
		{
			return 0;
		}
	}
	return 0;
	//0-���¼���1-����-�������ˣ�2-����-�����ˣ�3-����  2��3�ĸ�����С
}

void master::randthing(int n)
{
	if(n==1)
	{
		::MessageBox(NULL,_T("���ġ��������˹��޲����������"),_T("�¼�"),MB_OK);
	}
	else if(n==2)
	{
		::MessageBox(NULL,_T("���ġ��������˹��ޡ����ҵ���ȥ�ˡ�"),_T("�¼�"),MB_OK);
	}
	else if(n==3)
	{
		::MessageBox(NULL,_T("���ġ��㿴���˹�����������Ҫ�߳�����ط���"),_T("�¼�"),MB_OK);
	}
}
