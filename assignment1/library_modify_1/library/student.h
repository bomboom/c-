class student{
private:
	string student_id,student_psw;
	int state;
	                            /*state说明：
		                           -1：退出到login system
									0：登陆
									1：show_basic_info	显示基本信息
									2: search_borrow	查找已经借的
									3：search_buy
									4: search			查找
										无状态：--显示书具体信息
									5: book_return		还书
								*/
public:
	//初始化
	student() {
		this->state = 0;
	}
	
	//控制器
	void controller(string id,string psw) {
		while(this->state != -1) {
			system("cls");
			if(this->state==0) {
				this->state = this->login(id, psw);
			} else
			if(this->state==1) {
				this->show_basic_info();
			} else
			if(this->state==2) {
				this->search_borrow();
			} else
			if(this->state==3) {
				this->search_buy();
			} else
			if(this->state==4) {
				this->search();
			} else
			if(this->state==5) {
				this->book_return();
			}
		}
	}
	
	//登入，state = 0;
	int login(string id,string psw){                        
		this->student_id=id;
		this->student_psw=psw;
		CDatabase database;       //数据库实例
		database.OpenEx(_T("DSN=mysql"),CDatabase::noOdbcDialog);   //open
		CRecordset recset(&database);                //接收返回值
        
		string temp;
		temp="select student_psw from student where student_id="+this->student_id;
		

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
					if(!this->student_psw.compare(str.GetBuffer(0))){
						cout<<"login successful!"<<endl;                     //判断
						//this->show_basic_info();
						
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



	//显示基本信息, state = 1;
	void show_basic_info() {
		CDatabase database;       //数据库实例
		database.OpenEx(_T("DSN=mysql"),CDatabase::noOdbcDialog);   //open
		CRecordset recset(&database);                //接收返回值

			string temp;
			temp="select * from student where student_id="+this->student_id;
			CString SQL;
			SQL.Format(_T("%s"),temp.c_str());  
			
			if (!recset.Open(CRecordset::snapshot, SQL, CRecordset::readOnly))		
			{
				cout<< "not exist"<<endl;
			}
			if (!recset.IsBOF()) {
	            while(!recset.IsEOF()){  
				CString str;
				recset.GetFieldValue((short)0, str);	
				cout<<"ID:"<<str.GetBuffer(0)<<endl;	
				recset.GetFieldValue(2, str);		
				cout<<"已借书:"<<str.GetBuffer(0)<<endl;	
				recset.GetFieldValue(3, str);		
				cout<<"已买书:"<<str.GetBuffer(0)<<endl;
				recset.GetFieldValue(4, str);		
				cout<<"账户余额:"<<str.GetBuffer(0)<<endl;
				recset.MoveNext();
				cout<<endl;
				int r=1;
				while(r==1){
					cout<<"1.查询已借书(还书)  2.查询已购书  3.查询书库或借买书 5.退出登陆(按1 2 3……即可)"<<endl;   //若借书0，购书0情况未写
					string a;
					cin>>a;                                                          
				
					if(a.compare("1")==0)  {
						this->state = 2;//this->search_borrow();
						return;
					}
					else if(a.compare("2")==0)  {
						this->state = 3; //this->search_buy();
						return;                  //跳出去到controller.否则死循环
					}
					else if(a.compare("3")==0){ 
						this->state = 4; //this->search();
						r=0;
						system("cls");
						return ;
					} else if (a.compare("5")==0) {
						this->state = -1;	//退出到登陆前状态
						system("cls");
						return;
					}
					else  cout<<"error!"<<endl;           
				}
				}													 					
			
			}
	}
	
	//查询已借书(还书)
	void search_borrow(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		temp="select * from book, borrow where book.number=borrow.number and borrow.student_id="+this->student_id;
		//cout<<temp<<endl;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    
			{
			   cout<<"NULL"<<endl;	
			  
			}
		if(recset.IsBOF()){
				cout<<"无！"<<endl;
				
			}
		else
			   {
				   cout<<"ID:"<<this->student_id<<endl;
				while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      
					cout<<"Book number:"<<str.GetBuffer(0)<<endl;	
					recset.GetFieldValue((short)1, str);			
					cout<<"Book name:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue((short)2, str);			
					cout<<"Author:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue((short)3, str);			
					cout<<"Publisher:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue((short)9, str);			
					cout<<"Borrow time:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue((short)10, str);			
					cout<<"Due time:"<<str.GetBuffer(0)<<endl;	
					cout<<endl<<endl;
					recset.MoveNext();
				}
		}

		string c;
		while (1) {
			cout<<"1.还书  2.返回"<<endl;
			cin>>c;
			if(c.compare("1")==0) {
				this->state = 5;	//state = 5 book_return;
				return;
			} else
			if(c.compare("2")==0) {
				this->state = 0;
				return;
			};
		}
				
	}
	
	//查询已购书
	void search_buy(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		temp="select * from book, buy where book.number=buy.number and buy.student_id="+this->student_id;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		CString k,r;
		double a,b,d;
		
		if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    
			{
			   cout<<"NULL"<<endl;	
			  
			}
		if(recset.IsBOF()){
				cout<<"无！"<<endl;
				
			}
		else
			   {   
				   cout<<"ID:"<<this->student_id;
				while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      
					cout<<"Book number:"<<str.GetBuffer(0);	
					recset.GetFieldValue(1, str);			
					cout<<"   Book name:"<<str.GetBuffer(0);
					recset.GetFieldValue(2, str);			
					cout<<"   Author:"<<str.GetBuffer(0);
					recset.GetFieldValue(3, str);			
					cout<<"   Publisher:"<<str.GetBuffer(0);
					recset.GetFieldValue(4, str);			
					cout<<"   Price:"<<str.GetBuffer(0);
					k=str;
					recset.GetFieldValue(9, str);			
					cout<<"   Buy time:"<<str.GetBuffer(0);
					recset.GetFieldValue(10, str);			
					cout<<"   count:"<<str.GetBuffer(0);
					r=str;
					a=atof(k.GetBuffer(0));
					b=atof(r.GetBuffer(0));
					d=a*b;
					cout<<"   total:"<<d;
					recset.MoveNext();	
					cout<<endl;
				}
		}

		string c;
		cout<<"输入任意值返回"<<endl;
		cin>>c;
		this->state = 1;
				
	}
	
	//查询书库->借买书
	void search(){
	     system("cls");
		 
		 
		 while(1){	//这里不涉及 SQL连接，连接在show_book里..这里只做拼接
			 string temp;
			 string a;
			 string c;
			 cout<<"1.展示所有 2.按书号 3.按书名 4.按作者 5.按出版社 6.借书 7.买书 8.返回（按1 2 3即可）"<<endl;
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
			 else if(a.compare("6")==0) {
				 this->borrow();
			 }
			 else if(a.compare("7")==0) {
				 this->buy();
			 }
			 else if(a.compare("8")==0) {
				 this->state = 1;
				 return;
			 }
			 else {
				 cout<<"error!"<<endl;
				 continue ;
			 }

		 }
	}
	
	//买书
	void buy(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		cout<<"请输入您要买的书的书号：";
		string number,count;
		cin>>number;
		cout<<"买多少本?：";
		cin>>count;
		
		string temp;
		temp="select * from book where number="+number;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(!recset.IsBOF()){
					CString k,r,g;
					while(!recset.IsEOF())
					{   CString str;
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
						g=str;
						recset.GetFieldValue(5, str);
						k = str;
						cout<<"余量："<<str.GetBuffer(0)<<endl;
						recset.GetFieldValue(6, str);			
						r = str;
						cout<<"已借出:"<<str.GetBuffer(0)<<endl;
						recset.MoveNext();		
						cout<<endl;}
					
					int a,b,c,d;
					a=atoi(k.GetBuffer(0));
					b=atoi(r.GetBuffer(0));
					d=atoi(count.c_str());
					c=a-b-d;
					if(c>=0)
					{   string emp;
						emp="insert into buy(student_id, number, count) values("+this->student_id+","+number+","+count+")";
						//cout<<emp<<endl;
						CString QL;
						QL.Format(_T("%s"),emp.c_str());
						database.ExecuteSQL(QL);

						emp="update book set margin=margin-"+count+" where number="+number;
						QL.Format(_T("%s"),emp.c_str());
						//cout<<emp<<endl;
						database.ExecuteSQL(QL);
						
						emp="update student set buy_num=buy_num+"+count+",money=money-"+count+"*"+g.GetBuffer()+" where student_id="+this->student_id;
						QL.Format(_T("%s"),emp.c_str());
						//cout<<emp<<endl;
						database.ExecuteSQL(QL);
						
						cout<<"买取成功！"<<endl
						
						
						;
					}
					else cout<<"没有余量！"<<endl;
			}
			else cout<<"没有这本书！"<<endl;
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
	
	
	}

	//还书+罚款
	void book_return(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);

		
		cout<<"请输入您要还的书的书号：";
		string number;
		cin>>number;
		
		string temp;
		string book_title, author, publisher,margin,lend,price;
		temp="select * from book,borrow where book.number="+number+" and borrow.student_id="+this->student_id+"and book.number=borrow.number";
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			string due_time;
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	 
			}

			if(!recset.IsBOF()){
				
				while(!recset.IsEOF())
				{   CString str;
					recset.GetFieldValue((short)0,str);                      
					cout<<"书号:"<<str.GetBuffer(0);	
					recset.GetFieldValue(1, str);			
					cout<<"   书名:"<<str.GetBuffer(0);
					recset.GetFieldValue(2, str);			
					cout<<"   作者:"<<str.GetBuffer(0);
					recset.GetFieldValue(3, str);			
					cout<<"   出版社:"<<str.GetBuffer(0);
					recset.GetFieldValue(9, str);			
					cout<<"   借书时间:"<<str.GetBuffer(0);
					recset.GetFieldValue(10, str);			
					cout<<"   应还日期:"<<str.GetBuffer(0);
					due_time=str.GetBuffer(0);
					recset.MoveNext();		
					cout<<endl;
				}
				//the second sql.

				CDatabase db2;				
				db2.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
				CRecordset rec(&db2); 
				
		
				temp="select timestampdiff( minute, (SELECT duetime FROM borrow where duetime=(select min(duetime) from borrow where student_id="+this->student_id+" and number="+number+")), now())";
					//cout<<temp;
				SQL.Format(_T("%s"),temp.c_str());
				int iType =-1;
				if(!rec.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
				{
				   cout<<"NULL"<<endl;	
				   
				}
					
				CString str;
				rec.GetFieldValue((short)0,str);
				iType = atoi(str);
				//cout<<iType;		
				cout<<endl;
						
				if(iType>0){
					//the third
					CDatabase db3;				
					db3.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
					CRecordset reca(&db3); 
					temp="select timestampdiff( day, (SELECT duetime FROM borrow where student_id="+this->student_id+" and number="+number+"), now())";
					//cout<<temp;
					SQL.Format(_T("%s"),temp.c_str());
					
					if(!reca.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
					{
						cout<<"NULL"<<endl;	
					}

					CString str;
					reca.GetFieldValue((short)0,str);                      
					double b;
					int c;
					c=atoi(str);
					b = 0.5 * c;
					cout<<"迟还"<<c<<"天"<<endl;
					cout<<"迟还需罚款（一天0.5元）："<<b<<endl;
					
					char buffer[1024];
					sprintf(buffer,"%.2f",b);
					string str2(buffer);

					temp="update student set money=money-"+str2+"where student_id="+this->student_id;
					SQL.Format(_T("%s"),temp.c_str());
					database.ExecuteSQL(SQL);

					cout<<"已自动在账户中扣除！^_^"<<endl;
				}
						

						
	
				temp="delete from borrow where student_id="+this->student_id+" and number="+number+" and duetime='"+due_time+"'";
				//cout<<temp;
				SQL.Format(_T("%s"),temp.c_str());
				database.ExecuteSQL(SQL);
				temp="update student set borrow_num=borrow_num-1 where student_id="+this->student_id;
				//cout<<temp;
				SQL.Format(_T("%s"),temp.c_str());
				database.ExecuteSQL(SQL);
				temp="update book set lend=lend-1 where number="+number;
				//cout<<temp;
				SQL.Format(_T("%s"),temp.c_str());
				database.ExecuteSQL(SQL);

				cout<<"还书成功!"<<endl;		
			}
			else cout<<"没有借这本书！"<<endl;
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); 
		}
		string c;
		while(1) {
			cout<<"继续还书？ 1.是  2.否，到主界面"<<endl;
			cin>>c;
			if (c.compare("1")==0) {
				this->state = 5;
				return;
			}
			if (c.compare("2")==0){
				this->state = 0;
				return;
			}
		}
	}
	
	//借书
	void borrow(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		cout<<"请输入您要借的书的书号：";
		string number;
		cin>>number;
		
		string temp;
		string book_title, author, publisher,margin,lend,price;
		temp="select * from book where number="+number;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		CString k,r;

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //执行
			{
			   cout<<"NULL"<<endl;	
			}

			if(!recset.IsBOF()){
					
					while(!recset.IsEOF())
					{   CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"书号:"<<str.GetBuffer(0)<<endl;	
						recset.GetFieldValue(1, str);			
						cout<<"书名:"<<str.GetBuffer(0)<<endl;
						recset.GetFieldValue(2, str);			
						cout<<"作者:"<<str.GetBuffer(0)<<endl;
						recset.GetFieldValue(3, str);			
						cout<<"出版社:"<<str.GetBuffer(0)<<endl;
						recset.GetFieldValue(5, str);
						k = str;
						cout<<"余量："<<str.GetBuffer(0)<<endl;
						recset.GetFieldValue(6, str);			
						r = str;
						cout<<"已借出:"<<str.GetBuffer(0)<<endl;
						recset.MoveNext();		
						cout<<endl;}
					}
			else {
				cout<<"没有这本书！"<<endl;
				return;	
			}	
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }

					int a,b,c;
					a=atoi(k.GetBuffer(0));
					b=atoi(r.GetBuffer(0));
					c=a-b;
					if(c>0)
					{   string emp;
						emp="insert into borrow(student_id, number, duetime) values("+this->student_id+","+number+", now()+ INTERVAL 14 DAY)";
						//cout<<emp;
						CString QL;
						QL.Format(_T("%s"),emp.c_str());
						database.ExecuteSQL(QL);

						emp="update book set lend=lend+1 where number="+number;
						QL.Format(_T("%s"),emp.c_str());
						database.ExecuteSQL(QL);
						emp="update student set borrow_num=borrow_num+1 where student_id="+this->student_id;
						
						QL.Format(_T("%s"),emp.c_str());
						database.ExecuteSQL(QL);
						
						cout<<"借取成功！"<<endl;
						
						
						
					}
					else cout<<"没有余量！"<<endl;
			
	
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
