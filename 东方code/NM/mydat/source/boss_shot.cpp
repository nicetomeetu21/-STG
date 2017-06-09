#include "../include/GV.h"
#include "../include/func.h"

#define V0 10.0

//进行与某点的指定距离的物理计算的登录（在指定时间t内回到固定位置）
void input_phy_pos(double x,double y,int t){//移动附加时间
	double ymax_x,ymax_y;
	if(t==0)t=1;
	boss.phy.flag=1;//登录有效
	boss.phy.cnt=0;//计时器初始化
	boss.phy.set_t=t;//设置移动附加时间
	ymax_x=boss.x-x;//想要移动的水平距离
	boss.phy.v0x=2*ymax_x/t;//水平分量的初速度
	boss.phy.ax =2*ymax_x/(t*t);//水平分量的加速度
	boss.phy.prex=boss.x;//初始x坐标
	ymax_y=boss.y-y;//想要移动的竖直距离
	boss.phy.v0y=2*ymax_y/t;//竖直分量的初速度
	boss.phy.ay =2*ymax_y/(t*t);//竖直分量的加速度
	boss.phy.prey=boss.y;//初始y坐标
}


void input_lphy(lazer_t *laz, int time, double angle){
	laz->lphy.angle   =angle;
	laz->lphy.base_ang=laz->angle;
	laz->lphy.time    =time;
}

//在t次计数中从当前位置到离开dist这么远的位置移动
int move_boss_pos(double x1,double y1,double x2,double y2,double dist, int t){
	int i=0;
	double x,y,angle;
	for(i=0;i<1000;i++){
		x=boss.x,y=boss.y;//设置当前Boss的位置
		angle=rang(PI);//随机地决定前进方向
		x+=cos(angle)*dist;//向着那个地方移动
		y+=sin(angle)*dist;
		if(x1<=x&&x<=x2 && y1<=y&&y<=y2){//如果那个点在移动可能的范围内的话
			input_phy_pos(x,y,t);
			return 0;
		}
	}
	return -1;//1000如果1000次尝试都不能的话就返回错误
}

int search_boss_shot(){//返回空编号
	for(int i=0;i<BOSS_BULLET_MAX;i++){
		if(boss_shot.bullet[i].flag==0)
			return i;
	}
	return -1;
}
int search_lazer(){
	for(int i=0;i<LAZER_MAX;i++){
		if(lazer[i].flag==0)
			return i;
	}
	return -1;
}
double bossatan2(){//自机和敌人所成的夹角
	return atan2(ch.y-boss.y,ch.x-boss.x);
}
double bossatan3(int k,double x,double y){
	return atan2(y-boss_shot.bullet[k].y,x-boss_shot.bullet[k].x);
}
//进行物理计算的登录（在指定时间t内回到固定位置）
void input_phy(int t){//t= 附加在移动上的时间 
	double ymax_x,ymax_y;
	if(t==0)t=1;
	boss.phy.flag=1;//登录有效
	boss.phy.cnt=0;//计数器初始化
	boss.phy.set_t=t;//设置附加移动时间
	ymax_x=boss.x-BOSS_POS_X;//想要移动的水平距离
	boss.phy.v0x=2*ymax_x/t;//水平分量的初速度
	boss.phy.ax =2*ymax_x/(t*t);//水平分量的加速度
	boss.phy.prex=boss.x;//初始x坐标
	ymax_y=boss.y-BOSS_POS_Y;//想要移动的竖直距离
	boss.phy.v0y=2*ymax_y/t;//竖直分量的初速度
	boss.phy.ay =2*ymax_y/(t*t);//数值分量的加速度
	boss.phy.prey=boss.y;//初始y坐标
}
//物理上的角色移动计算
void calc_phy(){
	double t=boss.phy.cnt;
	boss.x=boss.phy.prex-((boss.phy.v0x*t)-0.5*boss.phy.ax*t*t);//计算当前应当所在的x坐标
	boss.y=boss.phy.prey-((boss.phy.v0y*t)-0.5*boss.phy.ay*t*t);//计算当前应当所在的y坐标
	boss.phy.cnt++;
	if(boss.phy.cnt>=boss.phy.set_t)//如果超过附加移动的时间的话
		boss.phy.flag=0;// 设置移动为无效
}
//计算Boss的弹幕
void boss_shot_calc(){
	int i;
	boss.endtime--;
	if(boss.endtime<0)
		boss.hp=0;
	for(i=0;i<BOSS_BULLET_MAX;i++){
		if(boss_shot.bullet[i].flag>0){
			boss_shot.bullet[i].x+=cos(boss_shot.bullet[i].angle)*boss_shot.bullet[i].spd;
			boss_shot.bullet[i].y+=sin(boss_shot.bullet[i].angle)*boss_shot.bullet[i].spd;
			boss_shot.bullet[i].cnt++;
			if(boss_shot.bullet[i].cnt>boss_shot.bullet[i].till){
				if(boss_shot.bullet[i].x<-50 || boss_shot.bullet[i].x>FMX+50 ||
					boss_shot.bullet[i].y<-50 || boss_shot.bullet[i].y>FMY+50)
					boss_shot.bullet[i].flag=0;
			}
		}
	}
	boss_shot.cnt++;
}
//设置弹幕
void enter_boss_shot(){
	memset(&boss_shot , 0, sizeof(boss_shot_t));//子弹信息初始化
	boss_shot.flag=1;
	boss.wtime=0;//待机时间0
	boss.state=2;//设置为弹幕中的状态
	boss.hp=boss.set_hp[boss.knd];//HP设定
	boss.hp_max=boss.hp;
}

//设置Boss
void enter_boss(int num){
	if(num==0){//中路Boss开始时的情况
		memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);//销毁杂兵
		memset(shot,0,sizeof(shot_t)*SHOT_MAX);//销毁弹幕
		boss.x=FMX/2;//设置Boss的初始坐标
		boss.y=-30;
		if(theone==0)//弹幕的种类
		boss.knd=1;
		else boss.knd=-1;
	}
	boss.flag=1;
	boss.hagoromo=0;//是否扇状扩散的flag
	boss.endtime=99*60;//剩余时间
	boss.state=1;//设置状态为待机中
	boss.cnt=0;
	
              // bgm_main();      //enter_func_tm("BGMmain");
	boss.graph_flag=0;//恢复绘制flag
	boss.knd++;
	boss.wtime=0;//初始化待机时间
	memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);
	memset(&boss_shot,0,sizeof(boss_shot_t));//初始化Boss的弹幕信息
	input_phy(60);//附加上60次计数在物理计算中回到固定位置
}

//Boss的待机处理
void waitandenter(){
	int t=400;
	boss.wtime++;
	if(boss.wtime>t)//如果待机140次计数的话设置弹幕
		enter_boss_shot();
}

void calc_boss(){
	boss.dx=boss.x;
	boss.dy=boss.y+sin(PI2/130*(count%130))*10;
}




	//Boss的弹幕main
void boss_shot_main(){
	
	if(stage_count==boss.appear_count[0]+2 && boss.flag==0){//如果到了开始时间的话
		enter_boss(0);//开始
		//PlaySoundMem(sound_se[99],DX_PLAYTYPE_BACK);
	}
	if(boss.flag==0)
		return;
	calc_boss();
	if(boss.phy.flag==1)//如果物理移动计算有效
		calc_phy();//进行物理计算
	if(boss.state==2 && (boss.hp<=0 || boss.endtime<=0)){//如果在弹幕中体力为0的话
        se_flag[1]=1;
		se_flag[11]=1;
		//input_phy(30);
		//enter_boss(1);
		//func_state=-2;
		
		memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);
		memset(&boss_shot,0,sizeof(boss_shot_t));
		memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);
		memset(shot,0,sizeof(shot_t)*SHOT_MAX);
		cc++;
		if(cc==100)
			func_state=-1;
	}
			
	if(boss.state==1){//弹幕之间的待机时间
		waitandenter();
	}
	if(boss.state==2){//如果在弹幕中
		boss_shot_bullet[theone]();//进入弹幕函数
		//if(theone==0)
		//W	boss.knd=2;
		boss_shot_calc();//计算弹幕
	}
	boss.cnt++;
}



