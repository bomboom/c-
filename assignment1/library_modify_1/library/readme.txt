
/*
ʹ��SQL��C++��ͬ��ɡ�
�ȴ��������ݿ⣬Ȼ��ͨ��ODBC���ӣ�ʹ���ܹ�ͨ��C++�������ݿ⣻
����ʱ��ʹ��
student  ->  student_id=123  student_psw=123
admin    ->  456   456
controller:
  ��ʼ����->student����->(clear) show basic info
  ->1.search borrow->1.return book ->if refund  
					 2.back to info (clear)
	2.search buy->1.back to info (clear)
	3.search book->1.show all 2.num 3.title 4.author 5.publisher 
	               6.buy book->(clear) 1.buy
				                       2.back to search book
				   7.borrow book->(clear) 1.borrow
										  2.back to search book
				   8.back to info (clear)
    4.quit->(clear) back to ��ʼ����
  
   ��ʼ����->admin����->(clear) 
	   1.��ѯ�鼮�������->��clear��1.������
									2.�������
									3.������һ��
	   2.�����鼮���޸���Ϣ->1.show all 2.num 3.title 4.author 5.publisher 6.�����鼮 7.ɾ���鼮 8.�޸��鼮��Ϣ 9.������һ��
	   3.�˳���½
*/