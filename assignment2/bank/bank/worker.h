class worker{
private:
	string worker_id, worker_psw;
	int state;
	bank work;
				/*state说明:
					-1: login system(exit);
					 0: 登陆;
					 1: 导引界面
					 2: 初始化
					 6: 查询流水账
					 7: 添加界面
				*/
public:
	worker(){	this->state = 0;}

	int controller(string id, string psw)
	{	
		while(this->state!=-1)
		{
			
			system("cls");
			if(this->state==0){ 
				this->state=this->login(id,psw);
				if (this->state==-1) return 1;
			}
			else if(this->state==1){	this->operation();}
			else if(this->state==2){
				work.begin();
				this->state = 1;
				string k;
				cout<<"输入任意值返回。";
				cin>>k;
			}else if(this->state==6){
				work.search();
				this->state = 1;
			}else if(this->state==7){
				this->show();
			}else if(this->state==8){
				string temp;
				temp="select * from transaction where state =0";
				MYDatabase a;
				a.select2(temp);
				string k;
				cout<<"输入任意值返回。";
				cin>>k;
				this->state=1;
			}else if(this->state==9){
				string temp;
				temp="select * from transaction where state =2";
				MYDatabase a;
				a.select2(temp);
				string k;
				cout<<"输入任意值返回。";
				cin>>k;
				this->state=1;
			}
		}
		return 0;
	}

	int login(string id, string psw)
	{
		string temp;
		temp = "select worker_psw from worker where worker_id="+id;
		MYDatabase a;
		return a.select_psw(temp, psw);

	}

	//添加界面
	void show()
	{
		string temp, from_id, go_id, money;
		string a;
		while(1)
		{
			system("cls");
			cout<<"1.存钱  2.取钱  3.转账  4.返回"<<endl;
			cin>>a;
			
			if(a.compare("1")==0)
			{	
				cout<<"请输入您要存入的账号:";
				cin>>go_id;
				MYDatabase k;
				cout<<"存钱数目:";
				cin>>money;
				for(int i = 100; i>0; i--)
				{
					temp="insert into transaction values('存入',"+go_id+","+money+",now(),0)";	
					k.table_insert(temp);
				}
			}else if(a.compare("2")==0){
				cout<<"要取钱的账号:";
				cin>>from_id;
				MYDatabase k;
				cout<<"取钱数目：";
				cin>>money;
				temp="insert into transaction values("+from_id+",'取出',"+money+",now(),0)";	
				k.table_insert(temp);
			}else if(a.compare("3")==0){
				cout<<"转出账号:";
				cin>>from_id;
				cout<<"转入账号:";
				cin>>go_id;
				cout<<"金额:";
				cin>>money;
				temp="insert into transaction values("+from_id+","+go_id+","+money+",now(),0)";
				MYDatabase k;
				k.table_insert(temp);
			}else if(a.compare("4")==0)
			{
				this->state = 1;
				return;
			}else{
				cout<<"输入错误！"<<endl;
				continue;
			}
			
		}
	}

	
	//处理界面
	
	void operation()
	{	
		string a;
		while(1){
			system("cls");
			cout<<"1.初始化(账户)"<<endl<<"2.自动处理要交易事务"<<endl<<"3.查询账户流水账"<<endl;
			cout<<"4.手动添加需处理事务"<<endl<<"5.查询要处理事务列表"<<endl<<"6.查询处理失败事务"<<endl<<"7.退出"<<endl;
			cin>>a;
			if(a.compare("1")==0)
			{
				this->state = 2;
				return;
			}else if(a.compare("2")==0){
				
				string temp, from_id, go_id, money;
				temp="select * from transaction where state = 0";
				CDatabase database;
				CString SQL;
				database.OpenEx(_T("DSN=mysql"),CDatabase::noOdbcDialog);
				CRecordset recset(&database);
				
				SQL.Format(_T("%s"),temp.c_str());
				system("cls");
				try{
					if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
					{
						cout<<"ERROR!"<<endl;
					}
					if(recset.IsBOF()){	cout<<"无需处理事务"<<endl;}
					else
					{
						CString str;
						while(!recset.IsEOF())
						{
							recset.GetFieldValue((short)0, str);			
							cout<<"来源:"<<str.GetBuffer(0);
							from_id = str.GetBuffer(0);
							recset.GetFieldValue(1, str);			
							cout<<"   去处:"<<str.GetBuffer(0);
							go_id = str.GetBuffer(0);
							recset.GetFieldValue(2, str);
							cout<<"   数目:"<<str.GetBuffer(0)<<endl;
							money = str.GetBuffer(0);
							
							if(from_id.compare("存入")==0)
							{
								work.deposit(go_id,money);
							}else if(go_id.compare("取出")==0)
							{
								work.withdraw(from_id,money);
							}else{
								work.transfer(from_id,go_id,money);
							}
							recset.MoveNext();
							cout<<endl;
						}
					}	
				
				
				}catch(CDBException* pe){	pe->Delete();}

				string k;
				cout<<"输入任意值返回。";
				cin>>k;
				return;
			}else if(a.compare("3")==0){
				this->state = 6;
				return;
			}else if(a.compare("4")==0){
				this->state = 7;
				return;
			}else if(a.compare("5")==0){
				this->state = 8;
				return;
			}else if(a.compare("6")==0){
				this->state = 9;
				return;
			}else if(a.compare("7")==0){
				this->state = -1;
				system("cls");
				return;
			}
			else{
				cout<<"ERROR!"<<endl;
				continue;
			}	
		}
	}


};