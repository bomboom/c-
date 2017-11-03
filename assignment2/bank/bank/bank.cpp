
#include"stdafx.h"

int main()
{
	string id, psw;
	int quit_flag = 1;
	while(quit_flag)
	{
		worker wor1;
		cout<<"worker login system"<<endl;
		cout<<"worker id:";
		cin>>id;
		cout<<"password:";
		cin>>psw;
		
		quit_flag = wor1.controller(id, psw);
			
	}

	return 0;
}
