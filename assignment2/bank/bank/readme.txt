/*
使用mySQL与VC一同完成。ODBC连接。

bank.h->存取款、转账功能
worker.h->worker login and 1.初始化 数据库中24个账户都无交易记录 账户余额为1000
			123  123   	  2.自动处理  transaction是一个待处理交易的列表 
											table中state=0是待处理  1是处理成功  2是处理失败
							  3.查询账户流水账  查一个账户的成功交易记录
							  4.手动添加交易事情 
							  5.查询待处理事务
							  6.查询处理失败记录
MYDatabase.h->继承CDatabase



*/