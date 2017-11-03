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
	//返回添加成功字样
	void table_insert(string emp)
	{	
		
		this->temp = emp;
		SQL.Format(_T("%s"), this->temp.c_str());
		database.ExecuteSQL(SQL);
		cout<<"添加成功！"<<endl;
	
	}

	
	void table_delete(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		database.ExecuteSQL(SQL);
		cout<<"删除成功！"<<endl;
	}

	//处理insert update，不返回添加成功
	void table_update(string emp)
	{
		this->temp = emp;
		SQL.Format(_T("%s"),this->temp.c_str());
		database.ExecuteSQL(SQL);
		
	}

	
	//判断是否存在账号,select id 
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
				cout<<"无此ID号,";
				return -1;
			}else
			{
				cout<<"有此ID号,";
				return 1;
			}
		}catch(CDBException* pe){pe->Delete();}	
	return 0;
	}


	//判断账号密码是否一致,select psw
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
				cout<<"账号不存在"<<endl;
				return -1;
			}
			else{
				while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      
					if(!psw.compare(str.GetBuffer(0))){
						cout<<"密码正确！"<<endl;                   
						return 1;
					}else{	
						cout<<"密码错误！"<<endl;
						return -1;
					}
				}
				return -1;
			}
					
		}catch(CDBException* pe){	pe->Delete();}
        return -1;
	}
	
	//判断交易的money是不是超出current_balance, select money from account
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
				cout<<"没有这个账户.";
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
					cout<<"余额不足！";
					return -1;
				}else{
					return 1;
				}
			}
		}catch(CDBException* pe){	pe->Delete();}
	return 0;
	}


	//查询记录，流水账
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
				cout<<"用户ID:"<<str.GetBuffer(0);	
				recset.GetFieldValue(3, str);			
				cout<<"   余额:"<<str.GetBuffer(0);
				recset.GetFieldValue(2, str);			
				cout<<"   交易条数:"<<str.GetBuffer(0)<<endl;
		
				while(!recset.IsEOF())
				{
				recset.GetFieldValue(4, str);			
				cout<<"   来源:"<<str.GetBuffer(0);
				recset.GetFieldValue(5, str);			
				cout<<"   去处:"<<str.GetBuffer(0);
				recset.GetFieldValue(6, str);
				cout<<"   数目:"<<str.GetBuffer(0);
				recset.GetFieldValue(7, str);
				cout<<"   时间:"<<str.GetBuffer(0)<<endl;
				recset.MoveNext();
				}
			}	
		
		
		}catch(CDBException* pe){	pe->Delete();}
	}


	//查询事务列表
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
				cout<<"   来源:"<<str.GetBuffer(0);
				recset.GetFieldValue(1, str);			
				cout<<"   去处:"<<str.GetBuffer(0);
				recset.GetFieldValue(2, str);
				cout<<"   数目:"<<str.GetBuffer(0);
				recset.GetFieldValue(3, str);
				cout<<"   时间:"<<str.GetBuffer(0)<<endl;
				recset.MoveNext();
				}
			}	
		
		
		}catch(CDBException* pe){	pe->Delete();}
	
	
	}
	/*叫号
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
			if(recset.IsBOF()){	cout<<"没号啦~"<<endl;}
			else
			{
				CString str;
				recset.GetFieldValue((short)0,str);                     
				cout<<"要处理号码:"<<str.GetBuffer(0)<<endl;	
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