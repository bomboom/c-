class admin{
private:
	string admin_id,admin_psw;
	int state;
public:
	//��ʼ��
	admin() {
		this->state = 0;
	}

								/*state˵��:
								    -1:�˳���login system
									 0����½
									 1����������
									 2��������
									 3���������
									 4������
									 


							    */

	
	//������
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
	
	

	
	//����
	int login(string id,string psw){                        
		this->admin_id=id;
		this->admin_psw=psw;
		CDatabase database;       //���ݿ�ʵ��
		database.OpenEx(_T("DSN=mysql"),CDatabase::noOdbcDialog);   //open
		CRecordset recset(&database);                //���շ���ֵ
        
		string temp;
		temp="select admin_psw from admin where admin_id="+this->admin_id;
		

		CString SQL;
		SQL.Format(_T("%s"),temp.c_str());                //ת��CSring������CDatabase��ķ���

		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
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
					recset.GetFieldValue((short)0,str);                      //����student_psw
					if(!this->admin_psw.compare(str.GetBuffer(0))){
						cout<<"login successful!"<<endl;                     //�ж�
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


//����
void show(){
		string a,c;
		while(1){
		system("cls");
		cout<<"1.��ѯ�鼮�������  2.�����鼮���޸���Ϣ  3.�˳���½ ����1 2�������ɣ� "<<endl;
		cin>>a;
		
		if(a.compare("1")==0){
				cout<<"1.�������  2.�������  3.�˳� "<<endl;
				
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
	
	//�����鼮
	void add_book(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		string number, book_title, author, publisher,margin,lend,price;
	
		
		cout<<"�鼮���:";
		cin>>number;

		temp="select number from book where number="+number;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(recset.IsBOF()){
				cout<<"����:";
				cin>>book_title;
				cout<<"����:";
				cin>>author;
				cout<<"������:";
				cin>>publisher;
				cout<<"�۸�:";
				cin>>price;
				cout<<"����(δ����):";
				cin>>margin;
				lend="0";
				
				string emp;
				CString QL;
				emp="insert into book values("+number+",'"+book_title+"','"+author+"','"+publisher+"',"+price+","+margin+","+lend+")";
				QL.Format(_T("%s"),emp.c_str());
				database.ExecuteSQL(QL);
				cout<<"���ӳɹ���"<<endl;
			}
			else cout<<"number has been exited!"<<endl;
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); 
		}
	}

	//ɾ���鼮
	void delete_book(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		string number;
	
		cout<<"�鼮���:";
		cin>>number;
		CString SQL;

		
	    temp="select * from borrow where number="+number;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(!recset.IsBOF()){
					cout<<"����ѧ��δ���飡"<<endl;
			}else{
			
				temp="delete from book where number="+number;
				
				SQL.Format(_T("%s"),temp.c_str()); 
				database.ExecuteSQL(SQL);
				cout<<"ɾ���ɹ�"<<endl;
			}
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }

	
	
	}
	//�޸��鼮��Ϣ
	void update_book(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		
		string temp;
		string number,book_title,author,publisher,price,margin,lend;
	
		cout<<"�鼮���:";
		cin>>number;
		temp="select * from book where number="+number;
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str()); 
		
		try{
			if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
			{
			   cout<<"NULL"<<endl;	
			   
			}

			if(recset.IsBOF()){
				cout<<"û�д���!"<<endl;}
			else{
			 while(!recset.IsEOF())
				{
					CString str;
					recset.GetFieldValue((short)0,str);                      
					cout<<"���:"<<str.GetBuffer(0)<<endl;	
					recset.GetFieldValue(1, str);			
					cout<<"����:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(2, str);			
					cout<<"����:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(3, str);			
					cout<<"������:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(4, str);			
					cout<<"�۸�:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(5, str);			
					cout<<"����:"<<str.GetBuffer(0)<<endl;
					recset.GetFieldValue(6, str);
					cout<<"�ѽ��:"<<str.GetBuffer(0)<<endl;
					recset.MoveNext();			
					cout<<endl;
				}

				cout<<"���޸ģ����䰴ԭ������"<<endl;
				cout<<"����:";
				cin>>book_title;
				cout<<"����:";
				cin>>author;
				cout<<"������:";
				cin>>publisher;
				cout<<"�۸�:";
				cin>>price;
				cout<<"����(δ����):";
				cin>>margin;
				cout<<"�ѽ��:";
				cin>>lend;
				
				string emp;
				CString QL;
				emp="update book set book_title='"+book_title+"',author='"+author+"',publisher='"+publisher+"',price="+price+",margin="+margin+",lend="+lend+" where number="+number;
				//cout<<emp;
				QL.Format(_T("%s"),emp.c_str());
				database.ExecuteSQL(QL);
				cout<<"�޸����"<<endl;
			
			}
					
		}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
	
	
	}
	
	//������
	void lend_out(){
		CDatabase database;				
		database.OpenEx( _T( "DSN=mysql" ),CDatabase::noOdbcDialog);		
		CRecordset recset(&database);
		string temp;
		temp="select * from borrow,book where borrow.number=book.number";
		CString SQL;
		SQL.Format(_T("%s"),temp.c_str());
		
		try{
				if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
				{
				   cout<<"NULL"<<endl;
				   
				}

				if(recset.IsBOF()){
					cout<<"�޽����"<<endl;}
				else{
				 while(!recset.IsEOF())
					{
						CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"student_id:"<<str.GetBuffer(0);	
						recset.GetFieldValue(1, str);			
						cout<<"   ���:"<<str.GetBuffer(0);
						recset.GetFieldValue(5, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.GetFieldValue(2, str);			
						cout<<"   ���ʱ��:"<<str.GetBuffer(0);
						recset.GetFieldValue(3, str);			
						cout<<"   Ӧ��ʱ�䣺"<<str.GetBuffer(0);
						recset.GetFieldValue(9, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.MoveNext();		
						cout<<endl;
					}
				}
					
			}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
			
		string c;
		cout<<"��������ֵ����"<<endl;
		cin>>c;
		this->state = 1;
	
	}

	//�������
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
				if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
				{
				   cout<<"NULL"<<endl;	
				   
				}

				if(recset.IsBOF()){
					cout<<"��������"<<endl;}
				else{
				 while(!recset.IsEOF())
					{
						CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"student_id:"<<str.GetBuffer(0);	
						recset.GetFieldValue(1, str);			
						cout<<"   ���:"<<str.GetBuffer(0);
						recset.GetFieldValue(5, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.GetFieldValue(2, str);			
						cout<<"   ����ʱ��:"<<str.GetBuffer(0);
						recset.GetFieldValue(3, str);			
						cout<<"   ��Ŀ:"<<str.GetBuffer(0);
						r=str;
						recset.GetFieldValue(9, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.GetFieldValue(8, str);			
						cout<<"   �۸�:"<<str.GetBuffer(0);
						k=str;
						a=atof(k.GetBuffer(0));
						b=atof(r.GetBuffer(0));
						d=a*b;
						cout<<"   �ܼ�:"<<d;
						recset.MoveNext();			
						cout<<endl;
					}
				}
					
			}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
		
		string c;
		cout<<"��������ֵ����"<<endl;
		cin>>c;
		this->state = 1;
	
	}

	//��ѯ���
	void search(){
	     system("cls");
		 
		 
		 while(1){	//���ﲻ�漰 SQL���ӣ�������show_book��..����ֻ��ƴ��
			 string temp;
			 string a;
			 string c;
			 cout<<"1.չʾ���� 2.����� 3.������ 4.������ 5.�������� 6.�����鼮 7.ɾ���鼮 8.�޸��鼮��Ϣ 9.���أ���1 2 3���ɣ�"<<endl;
			 cin>>a;
			 if(a.compare("1")==0) {
				 temp="select * from book";
				 this->show_book(temp);
			 }
			 else if(a.compare("2")==0) {
				 cout<<"��������ţ�";
				 cin>>c;
				 temp="select * from book where number="+c;
				 this->show_book(temp);
				 }
			 else if(a.compare("3")==0){
				 cout<<"������������";
				 cin>>c;
				 temp="select * from book where book_title='"+c+"'";
				 this->show_book(temp);
			 }
			 else if(a.compare("4")==0){
				 cout<<"��������������";
				 cin>>c;
				 temp="select * from book where author='"+c+"'";
				 this->show_book(temp);
			 }
			 else if(a.compare("5")==0){
				 cout<<"����������磺";
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
				if(!recset.Open(CRecordset::snapshot,SQL,CRecordset::readOnly))    //ִ��
				{
				   cout<<"NULL"<<endl;	
				   
				}

				if(recset.IsBOF()){
					cout<<"�����ڣ�"<<endl;}
				else{
				 while(!recset.IsEOF())
					{
						CString str;
						recset.GetFieldValue((short)0,str);                      
						cout<<"���:"<<str.GetBuffer(0);	
						recset.GetFieldValue(1, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.GetFieldValue(2, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.GetFieldValue(3, str);			
						cout<<"   ������:"<<str.GetBuffer(0);
						recset.GetFieldValue(4, str);			
						cout<<"   �۸�:"<<str.GetBuffer(0);
						recset.GetFieldValue(5, str);			
						cout<<"   ����:"<<str.GetBuffer(0);
						recset.GetFieldValue(6, str);
						cout<<"   �ѽ��:"<<str.GetBuffer(0);
						recset.MoveNext();			
						cout<<endl;
					}
				}
					
			}catch(CDBException* pe){			
			//pe->ReportError();  
			pe->Delete(); }
	}
	
};
