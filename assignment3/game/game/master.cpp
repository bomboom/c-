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
	
	//生成随机数
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
	//0-空事件，1-怪物-怪物死了，2-怪物-我死了，3-公主  2，3的概率最小
}

void master::randthing(int n)
{
	if(n==1)
	{
		::MessageBox(NULL,_T("天哪。你遇上了怪兽并打败了它。"),_T("事件"),MB_OK);
	}
	else if(n==2)
	{
		::MessageBox(NULL,_T("天哪。你遇上了怪兽。不幸地死去了。"),_T("事件"),MB_OK);
	}
	else if(n==3)
	{
		::MessageBox(NULL,_T("天哪。你看见了公主。现在你要走出这个地方。"),_T("事件"),MB_OK);
	}
}
