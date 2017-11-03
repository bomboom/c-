struct mast
{
	int x;
	int y;   //坐标
	int r;   //判断是否找到公主
	int i;   //发生什么事件
	int f;	 //几楼
	int numE;  //正-东1东2 负-西1西2
	int numN;	//正-北1北2 负-南1南2
	int lv;    //等级
};

class master
{
public:
	
	int randint(int n);  //生成随机事件
	bool Gen(int n);      
	void randthing(int n);
	

};