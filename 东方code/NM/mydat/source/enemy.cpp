#include "../include/GV.h"

extern void enemy_pattern0(int);extern void enemy_pattern1(int);extern void enemy_pattern2(int);
extern void enemy_pattern3(int);extern void enemy_pattern4(int);extern void enemy_pattern5(int);
extern void enemy_pattern6(int);extern void enemy_pattern7(int);extern void enemy_pattern8(int);
extern void enemy_pattern9(int);extern void enemy_pattern10(int);

void (*enemy_pattern[ENEMY_PATTERN_MAX])(int) = {
    enemy_pattern0,    enemy_pattern1,    enemy_pattern2,    enemy_pattern3,    enemy_pattern4,
    enemy_pattern5,    enemy_pattern6,    enemy_pattern7,    enemy_pattern8,    enemy_pattern9,
    enemy_pattern10,
};

//检查空的敌人编号
int enemy_num_search(){
    for(int i=0;i<ENEMY_MAX;i++){//查询flag为无效的enemy
        if(enemy[i].flag==0){
            return i;//返回使用可能的编号
        }
    }
    return -1;//如果全部被使用返回错误
}

//登录敌人情报
void enemy_enter(){//控制、登录敌人行动的函数
    int i,j,t;
	if(boss.flag!=0)return;
    for(t=0;t<ENEMY_ORDER_MAX;t++){
        if(enemy_order[t].cnt==stage_count){//如果当前计数是是顺序的计数的瞬间
            if((i=enemy_num_search())!=-1){
                enemy[i].flag    =1;//flag
                enemy[i].cnt    =0;//计数器
                enemy[i].pattern=enemy_order[t].pattern;//移动模式
                enemy[i].muki    =1;//方向
                enemy[i].knd    =enemy_order[t].knd;//敌人的种类
                enemy[i].x        =enemy_order[t].x;//坐标
                enemy[i].y        =enemy_order[t].y;
                enemy[i].sp        =enemy_order[t].sp;//速度
                enemy[i].bltime    =enemy_order[t].bltime;//子弹的发射时间
                enemy[i].blknd    =enemy_order[t].blknd;//弹幕的种类
                enemy[i].blknd2    =enemy_order[t].blknd2;//子弹的种类
                enemy[i].col    =enemy_order[t].col;//颜色
                enemy[i].wait    =enemy_order[t].wait;//停止时间
                enemy[i].hp        =enemy_order[t].hp;//体力
                enemy[i].hp_max =enemy[i].hp;//体力最大值
				enemy[i].back_col=GetRand(4);//特效
                enemy[i].vx     =0;//水平分量的速度
                enemy[i].vy     =0;//竖直分量的速度
                enemy[i].ang    =0;//角度
                for(j=0;j<6;j++)
                    enemy[i].item_n[j]=enemy_order[t].item_n[j];//掉落的道具
            }
        }
    }
}

void enter_shot(int i){
	int j;
	for(j=0;j<SHOT_MAX;j++){//搜索flag为无效的敌人
		if(shot[j].flag==0){//如果有没有使用过的弹幕数据
			memset(&shot[j],0,sizeof(shot_t));//初始化并登录之
			shot[j].flag=1;//设置flag为有效
			shot[j].knd=enemy[i].blknd;//子弹的种类
			shot[j].num=i;//num=是哪个敌人发射过来的
			shot[j].cnt=0;
			return ;
		}
	}
}

//控制敌人的行动
void enemy_act(){
    int i;
    for(i=0;i<ENEMY_MAX;i++){
        if(enemy[i].flag==1){//如果敌人的flag为有效
            if(0<=enemy[i].pattern && enemy[i].pattern<ENEMY_PATTERN_MAX){
                enemy_pattern[enemy[i].pattern](i);
                enemy[i].x+=cos(enemy[i].ang)*enemy[i].sp;
                enemy[i].y+=sin(enemy[i].ang)*enemy[i].sp;
                enemy[i].x+=enemy[i].vx;
                enemy[i].y+=enemy[i].vy;
                enemy[i].cnt++;
                enemy[i].img=enemy[i].muki*3+(enemy[i].cnt%18)/6;
                //敌人跑到画面外面的话销毁
                if(enemy[i].x<-20 || FMX+20<enemy[i].x || enemy[i].y<-20 || FMY+20<enemy[i].y)
                    enemy[i].flag=0;
				if(enemy[i].bltime==enemy[i].cnt)
					enter_shot(i);
			}
            else
                printfDx("enemy[i].pattern error",enemy[i].pattern);
        }
    }
}

//敌人处理main
void enemy_main(){
    enemy_enter();
    enemy_act();
}