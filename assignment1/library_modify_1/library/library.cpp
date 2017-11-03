#include"stdafx.h"

int main(){
	string a;
	string admin_id, admin_psw;
	string student_id, student_psw;
	
	
	int run = 1;
	while(run == 1){
		cout<<"login system!"<<endl;
		cout<<"Please choose student or admin"<<endl;
		cin>>a;
		system("cls");
		if (!a.compare("admin")){
			admin ad1;
			cout<<"Please enter the id:";
			cin>>admin_id;
			cout<<"Please enter the password:";
			cin>>admin_psw;
			system("cls");
			//ad1.login(admin_id,admin_psw);
			ad1.controller(admin_id,admin_psw);
		
		}
		else if(!a.compare("student")){
			student st1;
			cout<<"Please enter the id:";
			cin>>student_id;
			cout<<"Please enter the password:";
			cin>>student_psw;
			system("cls");
			//st1.login(student_id,student_psw);
			st1.controller(student_id,student_psw);

		}
		else if(!a.compare("quit")) {
			run = 0;
		} else
			cout<<"error!";             
	}
return 0;
}




