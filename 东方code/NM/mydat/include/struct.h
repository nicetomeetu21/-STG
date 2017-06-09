//和角色相关的结构体
typedef struct{
	int flag;		//
	int cnt;		//计时器
	int power;		//
	int point;		//点数
	int score;		//分数
	int num;		//残机数
	int mutekicnt;	//无敌状态与计数变量
	int shot_mode;	//射击模式
	int money;		//
	int img;		//图像
	int slow;		//是否缓慢移动
	double x,y;		//坐标
	int shot_cnt;	//射击的计数器
	int limit;		//炸弹限制
	
}ch_t;

typedef struct{
	double x,y;
}pt_t;

//和敌人相关的结构体
typedef struct{
	int flag,cnt,pattern,muki,knd,hp,hp_max,item_n[6],img,back_col;
	//flag、计数器、移动模式、方向、敌人的种类、HP最大值、掉落道具、图像
	double x,y,vx,vy,sp,ang;
	//坐标、速度x分量、速度y分量、速度、角度
	int bltime,blknd,blknd2,col,state,wtime,wait;
	//弹幕开始时间、弹幕的种类、弹的种类、颜色、状态、待机时间、停止时间
}enemy_t;

//敌人出现信息
typedef struct{
	//计数器、移动模式、敌人的种类
	int cnt,pattern,knd;
	//初始化坐标和移动速度
	double x,y,sp;
	//弹幕开始时间、弹幕种类、颜色、体力、子弹的种类、停止时间、物品（6个种类）
	int bltime,blknd,col,hp,blknd2,wait,item_n[6];
}enemy_order_t;

//和手柄相关的参数
typedef struct{
	int key[PAD_MAX];
}pad_t;

//和config相关的文件,手柄配置
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;

//和子弹相关的结构体
typedef struct{
//flag、种类、计数器、颜色、状态、保证不消失的最短时间、效果的种类
	int flag,knd,cnt,col,state,till,eff,kaiten,eff_detail;
//坐标、角度、速度、基本角度、瞬间记忆速度
	double x,y,vx,vy,angle,spd,base_angle[1],rem_spd[1];
}bullet_t;

//和射击有关的结构体
typedef struct{
//flag、种类、计数器、发射的敌人的编号
	int flag,knd,cnt,num;
//基本角度、基本速度
	double base_angle[1],base_spd[1];
	bullet_t bullet[SHOT_BULLET_MAX];
}shot_t;

//和Boss射击相关的结构体
typedef struct{
//flag、种类、计数器、发射过来的敌人的编号、颜色
	int flag,knd,cnt,num;
//基本角度、基本速度
	double base_angle[10],base_spd[1];
	bullet_t bullet[BOSS_BULLET_MAX];
}boss_shot_t;

//和角色射击相关的结构体
typedef struct{
	int flag,power,cnt,knd;//flag、power、计数器、种类
	double x,y,angle,spd;//坐标、角度、速度
}cshot_t;
//特效
typedef struct{
	int flag,cnt,col,knd,img,eff;
	double x,y,r,ang,spd,mvang,brt;
}effect_t;
 //消灭特效
typedef struct{
	int flag,cnt,col;
	double x,y;
}del_effect_t;
//子弹的信息,自机碰撞相关
typedef struct{
	int size_x,size_y,col_num,kaiten;
	double range;
}bullet_info_t;
//Boom的信息
typedef struct{
	int flag,cnt,knd;
	double x,y;
}bom_t;
//画面亮度的信息
typedef struct{
	unsigned char brt;
}bright_set_t;
//咚！地晃动画面的信息
typedef struct{
	int flag,cnt,time,size;
	int x,y;
}dn_t;
//用于物理计算的结构体
typedef struct{
	int flag,cnt,set_t;
	double ax,v0x,ay,v0y,vx,vy,prex,prey;
}phy_t;
//
typedef struct{
	int conv_flag;
	double time,base_ang,angle;
	double conv_x,conv_y,conv_base_x,conv_base_y;
}lphy_t;
//Boos的信息
typedef struct{
	int flag,cnt,knd,wtime,state,endtime,hagoromo,graph_flag;
	int hp,hp_max;
	int appear_count[2],set_hp[DANMAKU_MAX],back_knd[DANMAKU_MAX];
	double x,y,dx,dy,ang,spd;
	phy_t phy;
}boss_t;
//
typedef struct{
	int flag,cnt,knd,col,state;//
	double haba,angle,length,hantei;//
	pt_t startpt,disppt[4],outpt[4];//
	lphy_t lphy;
}lazer_t;

//BGM信息(在area_t中使用(48)
typedef struct{
		//BGM的播放flag、播放句柄、播放时机的种类编号、循环位置
        int flag,handle,knd[2],loop_pos[2];
}bgm_t;
 
//区域所持有的信息
typedef struct{
        bgm_t bgm;
}area_t;