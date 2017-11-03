class MYDatabase{
private:
	string temp;

public:
	CDatabase database;
	CString SQL;
	CRecordset recset;

	MYDatabase()
	{    
		database.OpenEx(_T("DSN=mysql"),CDatabase::noOdbcDialog);
		this->recset.m_pDatabase = &database;
	}
	//������ӳɹ�����
	void table_insert(string emp)
	{	
		
		this->temp = emp;
		SQL.Format(_T("%s"), this->temp.c_str());
		database.ExecuteSQL(SQL);
		cout<<"��ӳɹ���"<<endl;
	
	}

	
	void table_delete(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		database.ExecuteSQL(SQL);
		cout<<"ɾ���ɹ���"<<endl;
	}

	//����insert update����������ӳɹ�
	void table_update(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		database.ExecuteSQL(SQL);
		
	}

	
	//�ж��Ƿ�����˺�,select id 
	int select_exist(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
			{	cout<<"ERROR!"<<endl;
				return 0;
			}
			if(recset.IsBOF())
			{	
				cout<<"�޴�ID��,";
				return -1;
			}else
			{
				cout<<"�д�ID��,";
				return 1;
			}
		}catch(CDBException* pe){pe->Delete();}	
	return 0;
	}


	//�ж��˺������Ƿ�һ��,select psw
	int select_psw(string emp, string psw)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    
			{
			   cout<<"ERROR!"<<endl;	
			   return -1;
			}

			if(recset.IsBOF()){
				cout<<"�˺Ų�����"<<endl;
				return -1;
			}
			else{
				while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      
					if(!psw.compare(str.GetBuffer(0))){
						cout<<"������ȷ��"<<endl;                   
						return 1;
					}else{	
						cout<<"�������"<<endl;
						return -1;
					}
				}
				return -1;
			}
					
		}catch(CDBException* pe){	pe->Delete();}
        return -1;
	}
	
	//�жϽ��׵�money�ǲ��ǳ���current_balance, select money from account
	int select_limit(string emp, double money)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		double current_balance;

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
			{
				cout<<"ERROR!"<<endl;
				return 0;
			}
			if(recset.IsBOF())
			{
				cout<<"û������˻�.";
				return 0;
			}else{
				while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);
					current_balance=atof(str.GetBuffer(0));
					recset.MoveNext();
				}
				if(current_balance<money)
				{
					cout<<"���㣡";
					return -1;
				}else{
					return 1;
				}
			}
		}catch(CDBException* pe){	pe->Delete();}
	return 0;
	}


	//��ѯ��¼����ˮ��
	void select(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
			{
				cout<<"ERROR!"<<endl;
			}
			if(recset.IsBOF()){	cout<<"NULL"<<endl;}
			else
			{
				CString str;
				recset.GetFieldValue((short)0,str);                     
				cout<<"�û�ID:"<<str.GetBuffer(0);	
				recset.GetFieldValue(3, str);			
				cout<<"   ���:"<<str.GetBuffer(0);
				recset.GetFieldValue(2, str);			
				cout<<"   ��������:"<<str.GetBuffer(0)<<endl;
		
				while(!recset.IsEOF())
				{
				recset.GetFieldValue(4, str);			
				cout<<"   ��Դ:"<<str.GetBuffer(0);
				recset.GetFieldValue(5, str);			
				cout<<"   ȥ��:"<<str.GetBuffer(0);
				recset.GetFieldValue(6, str);
				cout<<"   ��Ŀ:"<<str.GetBuffer(0);
				recset.GetFieldValue(7, str);
				cout<<"   ʱ��:"<<str.GetBuffer(0)<<endl;
				recset.MoveNext();
				}
			}	
		
		
		}catch(CDBException* pe){	pe->Delete();}
	}


	//��ѯ�����б�
	void select2(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
			{
				cout<<"ERROR!"<<endl;
			}
			if(recset.IsBOF()){	cout<<"NULL"<<endl;}
			else
			{
				CString str;
				while(!recset.IsEOF())
				{
				recset.GetFieldValue((short)0, str);			
				cout<<"   ��Դ:"<<str.GetBuffer(0);
				recset.GetFieldValue(1, str);			
				cout<<"   ȥ��:"<<str.GetBuffer(0);
				recset.GetFieldValue(2, str);
				cout<<"   ��Ŀ:"<<str.GetBuffer(0);
				recset.GetFieldValue(3, str);
				cout<<"   ʱ��:"<<str.GetBuffer(0)<<endl;
				recset.MoveNext();
				}
			}	
		
		
		}catch(CDBException* pe){	pe->Delete();}
	
	
	}
	/*�к�
	int queue_select()
	{
		this->temp = "select * from queue";
		SQL.Format(_T("%s"),this->temp.c_str());

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
			{
				cout<<"ERROR!"<<endl;
				return 0;
			}
			if(recset.IsBOF()){	cout<<"û����~"<<endl;}
			else
			{
				CString str;
				recset.GetFieldValue((short)0,str);                     
				cout<<"Ҫ�������:"<<str.GetBuffer(0)<<endl;	
				return atoi(str.GetBuffer(0));
			}			
		}catch(CDBException* pe){	pe->Delete();}
		return 0;
	}
	int queue_max()
	{
	
		this->temp = "select max(number) from queue";
		SQL.Format(_T("%s"),this->temp.c_str());

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))
			{
				cout<<"ERROR!"<<endl;
				return 1000;
			}
			if(!recset.IsBOF())
			{
				CString str;
				recset.GetFieldValue((short)0,str);                     
				return atoi(str.GetBuffer(0));
			}	
			return 1000;
		}catch(CDBException* pe){	pe->Delete();}
		return 1000;
	
	}

*/
	
};