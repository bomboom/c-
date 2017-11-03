class admin{
private:
	string admin_id,admin_psw;
	int state;
public:
	//初始化
	admin() {
		this->state = 0;
	}

								/*state说明:
								    -1:退出到login system
									 0：登陆
									 1：导引界面
									 2：借出情况
									 3：卖出情况
									 4：搜书
									 


							    */

	
	//控制器
	void controller(string id,string psw) {
		while(this->state != -1) {
			system("cls");
			if(this->state==0) {
				this->state = this->login(id, psw);
			} else
			if(this->state==1) {
				this->show();
			} else
			if(this->state==2) {
				this->lend_out();
			} else
			if(this->state==3) {
				this->sell();
			} else
			if(this->state==4) {
				this->search();
			} 
			
		
		}
	}
	
	

	
	//登入
	int login(string id,string psw){                        
		this->admin_id=id;
		this->admin_psw=psw;
		CDatabase database;       //数据库实例
		database.OpenEx(_T("DSN=mysql"),CDatabase::noOdbcDialog);   //open
		CRecordset recset(&database);                //接收返回值
        
		string temp;
		temp="select admin_psw from admin where admin_id="+this->admin_id;
		

		CString SQL;
		SQL.Format(_T("%s"),temp.c_str());                //转成CSring，以用CDatabase里的方法

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	
			   return -1;
			}

			if(recset.IsBOF()){
				cout<<"error!"<<endl;
				return -1;
			}
			else
			   {
				while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      //接收student_psw
					if(!this->admin_psw.compare(str.GetBuffer(0))){
						cout<<"login successful!"<<endl;                     //判断
						//this->show();
						
						return 1;
					}
				}
				return -1;
			}
					
		
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); 
		}
	
        return -1;
	
		
	}


//导引
void show(){
		string a,c;
		while(1){
		system("cls");
		cout<<"1.查询书籍借卖情况  2.搜索书籍或修改信息  3.退出登陆 （按1 2……即可） "<<endl;
		cin>>a;
		
		if(a.compare("1")==0){
				cout<<"1.出借情况  2.卖出情况  3.退出 "<<endl;
				
				cin>>c;
				if(c.compare("1")==0){ 
					this->state=2;
					return;
				}
				else if(c.compare("2")==0){ 
					this->state=3;
					return;
						
				}
				else if(c.compare("3")==0){
					this->state=1;
				}
				else{
					cout<<"error!"<<endl;
					continue;
				}
		}	
		else if(a.compare("2")==0){ 
			this->state=4;
			return;
		}
		else if(a.compare("3")==0){
			this->state=-1;
			return;
		}else{
		    cout<<"error!"<<endl;
			continue;
		}
						
		}


}
	
	//增加书籍
	void add_book(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		string number, book_title, author, publisher,margin,lend,price;
	
		
		cout<<"书籍编号:";
		cin>>number;

		temp="select number from book where number="+number;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(recset.IsBOF()){
				cout<<"书名:";
				cin>>book_title;
				cout<<"作者:";
				cin>>author;
				cout<<"出版社:";
				cin>>publisher;
				cout<<"价格:";
				cin>>price;
				cout<<"余量(未卖出):";
				cin>>margin;
				lend="0";
				
				string emp;
				CString QL;
				emp="insert into book values("+number+",'"+book_title+"','"+author+"','"+publisher+"',"+price+","+margin+","+lend+")";
				QL.Format(_T("%s"),emp.c_str());
				database.ExecuteSQL(QL);
				cout<<"增加成功！"<<endl;
			}
			else cout<<"number has been exited!"<<endl;
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); 
		}
	}

	//删除书籍
	void delete_book(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		string number;
	
		cout<<"书籍编号:";
		cin>>number;
		CString SQL;

		
	    temp="select * from borrow where number="+number;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(!recset.IsBOF()){
					cout<<"还有学生未还书！"<<endl;
			}else{
			
				temp="delete from book where number="+number;
				
				SQL.Format(_T("%s"),temp.c_str()); 
				database.ExecuteSQL(SQL);
				cout<<"删除成功"<<endl;
			}
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }

	
	
	}
	//修改书籍信息
	void update_book(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		string number,book_title,author,publisher,price,margin,lend;
	
		cout<<"书籍编号:";
		cin>>number;
		temp="select * from book where number="+number;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(recset.IsBOF()){
				cout<<"没有此书!"<<endl;}
			else{
			 while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      
					cout<<"书号:"<<str.GetBuffer(0)<<endl;	
					recset.GetFieldValue(1, str);			
					cout<<"书名:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(2, str);			
					cout<<"作者:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(3, str);			
					cout<<"出版社:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(4, str);			
					cout<<"价格:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(5, str);			
					cout<<"余量:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(6, str);
					cout<<"已借出:"<<str.GetBuffer(0)<<endl;
					recset.MoveNext();			
					cout<<endl;
				}

				cout<<"请修改，不变按原来输入"<<endl;
				cout<<"书名:";
				cin>>book_title;
				cout<<"作者:";
				cin>>author;
				cout<<"出版社:";
				cin>>publisher;
				cout<<"价格:";
				cin>>price;
				cout<<"余量(未卖出):";
				cin>>margin;
				cout<<"已借出:";
				cin>>lend;
				
				string emp;
				CString QL;
				emp="update book set book_title='"+book_title+"',author='"+author+"',publisher='"+publisher+"',price="+price+",margin="+margin+",lend="+lend+" where number="+number;
				//cout<<emp;
				QL.Format(_T("%s"),emp.c_str());
				database.ExecuteSQL(QL);
				cout<<"修改完成"<<endl;
			
			}
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
	
	
	}
	
	//借出情况
	void lend_out(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		string temp;
		temp="select * from borrow,book where borrow.number=book.number";
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str());
		
		try{
				if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
				{
				   cout<<"NULL"<<endl;
				   
				}

				if(recset.IsBOF()){
					cout<<"无借出！"<<endl;}
				else{
				 while(!recset.IsEOF())
					{
						CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"student_id:"<<str.GetBuffer(0);	
						recset.GetFieldValue(1, str);			
						cout<<"   书号:"<<str.GetBuffer(0);
						recset.GetFieldValue(5, str);			
						cout<<"   书名:"<<str.GetBuffer(0);
						recset.GetFieldValue(2, str);			
						cout<<"   借出时间:"<<str.GetBuffer(0);
						recset.GetFieldValue(3, str);			
						cout<<"   应还时间："<<str.GetBuffer(0);
						recset.GetFieldValue(9, str);			
						cout<<"   余量:"<<str.GetBuffer(0);
						recset.MoveNext();		
						cout<<endl;
					}
				}
					
			}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
			
		string c;
		cout<<"输入任意值返回"<<endl;
		cin>>c;
		this->state = 1;
	
	}

	//卖出情况
	void sell(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		string temp;
		temp="select * from buy,book where buy.number=book.number";
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str());
		CString k,r;
		double a,b,d;
		
		try{
				if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
				{
				   cout<<"NULL"<<endl;	
				   
				}

				if(recset.IsBOF()){
					cout<<"无卖出！"<<endl;}
				else{
				 while(!recset.IsEOF())
					{
						CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"student_id:"<<str.GetBuffer(0);	
						recset.GetFieldValue(1, str);			
						cout<<"   书号:"<<str.GetBuffer(0);
						recset.GetFieldValue(5, str);			
						cout<<"   书名:"<<str.GetBuffer(0);
						recset.GetFieldValue(2, str);			
						cout<<"   购买时间:"<<str.GetBuffer(0);
						recset.GetFieldValue(3, str);			
						cout<<"   数目:"<<str.GetBuffer(0);
						r=str;
						recset.GetFieldValue(9, str);			
						cout<<"   余量:"<<str.GetBuffer(0);
						recset.GetFieldValue(8, str);			
						cout<<"   价格:"<<str.GetBuffer(0);
						k=str;
						a=atof(k.GetBuffer(0));
						b=atof(r.GetBuffer(0));
						d=a*b;
						cout<<"   总价:"<<d;
						recset.MoveNext();			
						cout<<endl;
					}
				}
					
			}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
		
		string c;
		cout<<"输入任意值返回"<<endl;
		cin>>c;
		this->state = 1;
	
	}

	//查询书库
	void search(){
	     system("cls");
		 
		 
		 while(1){	//这里不涉及 SQL连接，连接在show_book里..这里只做拼接
			 string temp;
			 string a;
			 string c;
			 cout<<"1.展示所有 2.按书号 3.按书名 4.按作者 5.按出版社 6.增加书籍 7.删除书籍 8.修改书籍信息 9.返回（按1 2 3即可）"<<endl;
			 cin>>a;
			 if(a.compare("1")==0) {
				 temp="select * from book";
				 this->show_book(temp);
			 }
			 else if(a.compare("2")==0) {
				 cout<<"请输入书号：";
				 cin>>c;
				 temp="select * from book where number="+c;
				 this->show_book(temp);
				 }
			 else if(a.compare("3")==0){
				 cout<<"请输入书名：";
				 cin>>c;
				 temp="select * from book where book_title='"+c+"'";
				 this->show_book(temp);
			 }
			 else if(a.compare("4")==0){
				 cout<<"请输入作者名：";
				 cin>>c;
				 temp="select * from book where author='"+c+"'";
				 this->show_book(temp);
			 }
			 else if(a.compare("5")==0){
				 cout<<"请输入出版社：";
				 cin>>c;
				 temp="select * from book where publisher='"+c+"'";
				 this->show_book(temp);
			 }
			 else if(a.compare("6")==0){
				 this->add_book();
			 }
			 else if(a.compare("7")==0){
				 this->delete_book();
			 }
			 else if(a.compare("8")==0){
				 this->update_book();
			 }
			 else if(a.compare("9")==0) {
				 this->state = 1;
				 return;
			 }
			 else {
				 cout<<"error!"<<endl;
				 continue ;
			 }

		 }
	}
	void show_book(string temp) {
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);

		CString SQL;
		SQL.Format(_T("%s"), temp.c_str());

		try{
				if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
				{
				   cout<<"NULL"<<endl;	
				   
				}

				if(recset.IsBOF()){
					cout<<"不存在！"<<endl;}
				else{
				 while(!recset.IsEOF())
					{
						CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"书号:"<<str.GetBuffer(0);	
						recset.GetFieldValue(1, str);			
						cout<<"   书名:"<<str.GetBuffer(0);
						recset.GetFieldValue(2, str);			
						cout<<"   作者:"<<str.GetBuffer(0);
						recset.GetFieldValue(3, str);			
						cout<<"   出版社:"<<str.GetBuffer(0);
						recset.GetFieldValue(4, str);			
						cout<<"   价格:"<<str.GetBuffer(0);
						recset.GetFieldValue(5, str);			
						cout<<"   余量:"<<str.GetBuffer(0);
						recset.GetFieldValue(6, str);
						cout<<"   已借出:"<<str.GetBuffer(0);
						recset.MoveNext();			
						cout<<endl;
					}
				}
					
			}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
	}
	
};
