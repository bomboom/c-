class bank{
public:
	/*create worker_id, this->state=3
	void add()
	{
		string temp, id, psw;
		cout<<"������ID:";
		cin>>id;
		if(id.compare("0")==0)
		{cout<<"����Ϊ0�����������룺";
		cin>>id;}

		temp="select customer_id from account where customer_id=" + id;
		MYDatabase a;
		if(a.select_exist(temp)==-1)
		{
			cout<<"����������:";
			cin>>psw;
			temp="insert into account values("+id+","+psw+",0,0)";
			a.table_insert(temp);

			string k;
			cout<<"��������ֵ����~~";
			cin>>k;
			
			
		}else{
			string k;
			cout<<"��������ֵ����~~";
			cin>>k;
			
		}
	}
*/
	//deposit money, this->state = 3

	void begin()
	{
		string temp;
		temp = "update account set transaction_num=0, current_balance=1000";
		MYDatabase a;
		a.table_update(temp);
		temp = "update transaction set state=0";
		a.table_update(temp);
		cout<<"��ʼ��25���˻���������������б�"<<endl;
	
	
	}
	void deposit(string id, string money)
	{
		MYDatabase a;
		string temp;
		temp="select * from account where customer_id="+id;
		if(a.select_exist(temp)==1){
			temp="update account set current_balance=current_balance+"+money+", transaction_num=transaction_num+1 where customer_id="+id;
			a.table_update(temp);
			temp="update transaction set state=1 where go_id='"+id+"' and money="+money+" and from_id='����' and state=0";
			a.table_update(temp);
			cout<<"����ɹ���";
		}else{	
			temp="update transaction set state=2 where go_id='"+id+"' and money="+money+" and from_id='����' and state=0";
			a.table_update(temp);
			cout<<"����ʧ��";
		}
	
	}
	//withdraw money, this->state = 4
	void withdraw(string from_id, string money)
	{
		string temp;
		double money2;
		temp="select customer_id from account where customer_id=" + from_id;
		MYDatabase a;
		if(a.select_exist(temp)==1)
		{
			temp="select current_balance from account where customer_id="+from_id;
			money2=atof(money.c_str());
			MYDatabase b;
			if(b.select_limit(temp,money2)==1)
			{
				MYDatabase c;
				temp="update account set current_balance=current_balance-"+money+",transaction_num=transaction_num+1 where customer_id="+from_id;
				c.table_update(temp);
				temp="update transaction set state=1 where from_id='"+from_id+"' and money="+money+" and go_id='ȡ��' and state=0";
				c.table_update(temp);
				cout<<"����ɹ���";
				
			}else{	
				temp="update transaction set state=2 where from_id='"+from_id+"' and money="+money+" and go_id='ȡ��' and state=0";
				a.table_update(temp);
				cout<<"����ʧ��";
			}
		}else{	
			temp="update transaction set state=2 where from_id='"+from_id+"' and money="+money+" and go_id='ȡ��' and state=0";
			a.table_update(temp);
			cout<<"����ʧ��";
		}
	
	}
	//transfer accounts, this->state = 5
	void transfer(string from_id, string go_id, string money)
	{
		string temp;
		double money2;
		temp="select customer_id from account where customer_id="+from_id;
		MYDatabase a;
		if(a.select_exist(temp)==1)
		{
			temp="select customer_id from account where customer_id="+go_id;
			MYDatabase b;
			if(b.select_exist(temp)==1)
			{
				temp="select current_balance from account where customer_id="+from_id;
				money2=atof(money.c_str());
				MYDatabase c;
				if(c.select_limit(temp,money2)==1)
				{
					temp="update account set transaction_num=transaction_num+1,current_balance=current_balance-"+money+" where customer_id="+from_id;
					c.table_update(temp);
					temp="update account set transaction_num=transaction_num+1,current_balance=current_balance+"+money+" where customer_id="+go_id;
					c.table_update(temp);
					temp="update transaction set state=1 where from_id='"+from_id+"' and go_id='"+go_id+"' and money="+money+" and state=0";
					c.table_update(temp);
					cout<<"����ɹ���";
				}else{	
					temp="update transaction set state=2 where from_id='"+from_id+"' and money="+money+" and go_id='"+go_id+"' and state=0";
					a.table_update(temp);
					cout<<"����ʧ��";
				
				}
			}else{	
				temp="update transaction set state=2 where from_id='"+from_id+"' and money="+money+" and go_id='"+go_id+"' and state=0";
				a.table_update(temp);
				cout<<"����ʧ��";
			}
		}else{
			temp="update transaction set state=2 where from_id='"+from_id+"' and money="+money+" and go_id='"+go_id+"' and state=0";
			a.table_update(temp);
			cout<<"����ʧ��";
		}
	}

	//��ѯ��ˮ��, this->state=6
	void search()
	{
		string temp, id;
		cout<<"����Ҫ��ѯ���˻���";
		cin>>id;
		temp="select * from account, transaction where account.customer_id="+id+" and (account.customer_id=transaction.go_id or account.customer_id=transaction.from_id) and transaction.state=1";
		MYDatabase a;
		a.select(temp);
		string k;
		cout<<"��������ֵ����~~";
		cin>>k;
	}
	
	/*����
	void delete_id()
	{
		string temp, id;
		cout<<"Ҫɾ�����˻���";
		cin>>id;
		temp="delete from account where customer_id="+id;
		MYDatabase a;
		a.table_delete(temp);
		string k;
		cout<<"��������ֵ����~~";
		cin>>k;
	}
*/
};