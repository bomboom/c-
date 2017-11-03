class worker{
private:
	string worker_id, worker_psw;
	int state;
	bank work;
				/*state˵��:
					-1: login system(exit);
					 0: ��½;
					 1: ��������
					 2: ��ʼ��
					 6: ��ѯ��ˮ��
					 7: ��ӽ���
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
				cout<<"��������ֵ���ء�";
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
				cout<<"��������ֵ���ء�";
				cin>>k;
				this->state=1;
			}else if(this->state==9){
				string temp;
				temp="select * from transaction where state =2";
				MYDatabase a;
				a.select2(temp);
				string k;
				cout<<"��������ֵ���ء�";
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

	//��ӽ���
	void show()
	{
		string temp, from_id, go_id, money;
		string a;
		while(1)
		{
			system("cls");
			cout<<"1.��Ǯ  2.ȡǮ  3.ת��  4.����"<<endl;
			cin>>a;
			
			if(a.compare("1")==0)
			{	
				cout<<"��������Ҫ������˺�:";
				cin>>go_id;
				MYDatabase k;
				cout<<"��Ǯ��Ŀ:";
				cin>>money;
				for(int i = 100; i>0; i--)
				{
					temp="insert into transaction values('����',"+go_id+","+money+",now(),0)";	
					k.table_insert(temp);
				}
			}else if(a.compare("2")==0){
				cout<<"ҪȡǮ���˺�:";
				cin>>from_id;
				MYDatabase k;
				cout<<"ȡǮ��Ŀ��";
				cin>>money;
				temp="insert into transaction values("+from_id+",'ȡ��',"+money+",now(),0)";	
				k.table_insert(temp);
			}else if(a.compare("3")==0){
				cout<<"ת���˺�:";
				cin>>from_id;
				cout<<"ת���˺�:";
				cin>>go_id;
				cout<<"���:";
				cin>>money;
				temp="insert into transaction values("+from_id+","+go_id+","+money+",now(),0)";
				MYDatabase k;
				k.table_insert(temp);
			}else if(a.compare("4")==0)
			{
				this->state = 1;
				return;
			}else{
				cout<<"�������"<<endl;
				continue;
			}
			
		}
	}

	
	//�������
	
	void operation()
	{	
		string a;
		while(1){
			system("cls");
			cout<<"1.��ʼ��(�˻�)"<<endl<<"2.�Զ�����Ҫ��������"<<endl<<"3.��ѯ�˻���ˮ��"<<endl;
			cout<<"4.�ֶ�����账������"<<endl<<"5.��ѯҪ���������б�"<<endl<<"6.��ѯ����ʧ������"<<endl<<"7.�˳�"<<endl;
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
					if(recset.IsBOF()){	cout<<"���账������"<<endl;}
					else
					{
						CString str;
						while(!recset.IsEOF())
						{
							recset.GetFieldValue((short)0, str);			
							cout<<"��Դ:"<<str.GetBuffer(0);
							from_id = str.GetBuffer(0);
							recset.GetFieldValue(1, str);			
							cout<<"   ȥ��:"<<str.GetBuffer(0);
							go_id = str.GetBuffer(0);
							recset.GetFieldValue(2, str);
							cout<<"   ��Ŀ:"<<str.GetBuffer(0)<<endl;
							money = str.GetBuffer(0);
							
							if(from_id.compare("����")==0)
							{
								work.deposit(go_id,money);
							}else if(go_id.compare("ȡ��")==0)
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
				cout<<"��������ֵ���ء�";
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