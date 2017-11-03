

class people
{
public:
	void initData(); //初始化运动区域和位置
	bool move(const int &dir);  //运动方向
	
public:
	void game();
	int move_map[ROW][COL];  //运动区域
	
	bool game_start;
	bool game_end;
	
	CPoint m_head;
	int Dir;
	
};

void people::initData()
{
	game_start = true;
	game_end = false;
	int i = 0;
	int k = 0;
	for(i=50;i<ROW;i++)
	{
		for(k=50;k<COL;k++)
		{
			move_map[i][k]=0;
		}
	}
	move_map[50][50] = RIGHT;
	m_head.x = 2;
	m_head.y = 0;
	Dir = RIGHT;
}

bool people::move(const int &dir)
{
	switch(dir)
	{
	case RIGHT:
		move_map[m_head.y][m_head.x] = RIGHT;
		m_head.x++;
		break;
	case LEFT:
		move_map[m_head.y][m_head.x] = LEFT;
		m_head.x--;
		break;
	case UP:
		move_map[m_head.y][m_head.x] = UP;
		m_head.y++;
		break;
	case DOWN:
		move_map[m_head.y][m_head.x] = DOWN;
		m_head.y--;
		break;
	default:
		break;
	}
	//判断进入哪个房间
	return true;
}

