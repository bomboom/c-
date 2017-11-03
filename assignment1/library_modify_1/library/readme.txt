
/*
使用SQL和C++共同完成。
先创建了数据库，然后通过ODBC连接，使得能够通过C++操纵数据库；
登入时可使用
student  ->  student_id=123  student_psw=123
admin    ->  456   456
controller:
  开始界面->student登入->(clear) show basic info
  ->1.search borrow->1.return book ->if refund  
					 2.back to info (clear)
	2.search buy->1.back to info (clear)
	3.search book->1.show all 2.num 3.title 4.author 5.publisher 
	               6.buy book->(clear) 1.buy
				                       2.back to search book
				   7.borrow book->(clear) 1.borrow
										  2.back to search book
				   8.back to info (clear)
    4.quit->(clear) back to 开始界面
  
   开始界面->admin登入->(clear) 
	   1.查询书籍借卖情况->（clear）1.借出情况
									2.卖出情况
									3.返回上一级
	   2.搜索书籍或修改信息->1.show all 2.num 3.title 4.author 5.publisher 6.增加书籍 7.删除书籍 8.修改书籍信息 9.返回上一级
	   3.退出登陆
*/