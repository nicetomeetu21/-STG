#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2
#define BRANGE 40.0

extern int out_lazer();

///敌人的碰撞判定范围
int enemy_range[ENEMY_RANGE_MAX]={16,30,16,50};
//自机射击的子弹的碰撞范围
int cshot_range[CSHOT_RANGE_MAX]={6,};

//
//射击的坐标：1 进行碰撞判定的物体：2
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;
    double x=x1-x2;//敌人和自机射击的子弹的距离
    double y=y1-y2;
    //敌人的碰撞判定和自机双色机的碰撞判定的合计范围
    double r=range1+range2;
    //如果有必要计算中间部分
    if(spd1>r){
        //保存1帧以前的位置
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;
        for(j=0;j<spd1/r;j++){//前进部分÷碰撞判定部分次循环
            px=pre_x-x2;
            py=pre_y-y2;
            if(px*px+py*py<r*r)
                return 1;
            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }
    if(x*x+y*y<r*r)//如果在碰撞判定内的话
        return 1;//碰撞
    return 0;
}

 //判断敌人和自机射击是否碰上
int out_judge_cshot(int i,int s){
    if(cshot[i].cnt>0){//射击的子弹的轨道如果至少计算过一次
        if(out_judge(cshot[i].x,cshot[i].y,enemy[s].x,enemy[s].y,
            cshot_range[cshot[i].knd],enemy_range[enemy[s].knd],
            cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//判定Boss是否和自机射击碰撞
int out_judge_cshot_boss(int i){
    if(cshot[i].cnt>0){//如果射击的子弹的轨道至少计算过一次
        if(out_judge(cshot[i].x,cshot[i].y,boss.x,boss.y,
            cshot_range[cshot[i].knd],BRANGE,cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//判定自机是否和敌人射击碰上
int out_judge_enemyshot(int s,int n){
    if(shot[s].bullet[n].cnt>0){//如果射击的子弹的轨道至少计算过一次
        if(out_judge(
            shot[s].bullet[n].x,shot[s].bullet[n].y,ch.x,ch.y,
            bullet_info[shot[s].bullet[n].knd].range,CRANGE,
            shot[s].bullet[n].spd,shot[s].bullet[n].angle
            )){
                return 1;
        }
    }
    return 0;
}

//是否自机是否和Boss射击碰上
int out_judge_bossshot(int n){
    if(boss_shot.bullet[n].cnt>0){//射击的子弹的轨道至少计算过一次的话
        if(out_judge(
            boss_shot.bullet[n].x,boss_shot.bullet[n].y,ch.x,ch.y,
            bullet_info[boss_shot.bullet[n].knd].range,CRANGE,
            boss_shot.bullet[n].spd,boss_shot.bullet[n].angle
            )){
                return 1;
        }
    }
    return 0;
}

extern void enter_del_effect(int);

//决定敌人是否击毁
void enemy_death_judge(int s){
    int i;
    se_flag[8]=1;//敌人被击中的声音
    if(enemy[s].hp<0){//如果敌人HP小于0
        enemy[s].flag=0;//消灭敌人
        se_flag[1]=1;//敌人击落声
        enter_del_effect(s);
        for(i=0;i<SHOT_MAX;i++){//敌人总数次循环
            if(shot[i].flag!=0){//如果有已经登录的弹幕数据
                if(s==shot[i].num){//并且那个敌人有登录了的弹幕
                    shot[i].flag=2;//将flag设置为不再继续
                    break;
                }
            }
        }
    }
	
}

//让s编号的敌人承受power的伤害
void hit_enemy(int s,int power){
    enemy[s].hp-=power;//减少子弹所有的power量的HP
    enemy_death_judge(s);//判断敌人是否击毁
}

//让Boss承受power伤害
void hit_boss(int power){
    boss.hp-=power;//让HP减少子弹所持有的power的量的
}


//自机射击和敌人的处理
void cshot_and_enemy(){
    int i,s;
    for(i=0;i<CSHOT_MAX;i++){//自机射击的子弹总数
        if(cshot[i].flag>0){
            for(s=0;s<ENEMY_MAX;s++){//敌人总数
                if(enemy[s].flag>0){
                    if(out_judge_cshot(i,s)){//如果自机射击的子弹和敌人碰上
                        cshot[i].flag=0;//将自己子弹销毁
                        hit_enemy(s,cshot[i].power);
                        break;
                    }
                }
            }
            //Boss出现且其不描绘flag为无效且在射击中
            if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
                if(out_judge_cshot_boss(i)){
                    cshot[i].flag=0;
                    hit_boss(cshot[i].power);
                }
            }
        }
    }
}

//敌人射击和自机的处理
void enemyshot_and_ch(){
    int s,n;
	if(ch.flag==0 && ch.mutekicnt==0 && out_lazer()==1){
        ch.cnt=0;
        ch.flag=1;
        se_flag[3]=1;
	}
    //杂兵的射击
    for(s=0;s<SHOT_MAX;s++){//敌人射击的子弹总数
        if(shot[s].flag>0){//如果当前射击被登录了的话
            for(n=0;n<SHOT_BULLET_MAX;n++){//子弹总数
                if(shot[s].bullet[n].flag==1){//如果子弹被登录了的话
					if(bom.flag!=0){
						shot[s].bullet[n].flag=0;//销毁子弹
						continue;
					}
                    if(out_judge_enemyshot(s,n)==1){//状态为一般状态，且不是无敌状态下
                        shot[s].bullet[n].flag=0;//
                        if(ch.flag==0 && ch.mutekicnt==0){
                            ch.cnt=0;
                            ch.flag=1;//1：正在进行决死处理 2：已经被击毁且新的自机正在从下浮起来
                            se_flag[3]=1;//击毁声
                        }
                    }
                }
            }
        }
    }
    //Boss射击
    if(boss_shot.flag>0){//如果射击已经登录
        for(n=0;n<BOSS_BULLET_MAX;n++){//子弹总数
            if(boss_shot.bullet[n].flag==1){//如果子弹已经登录
				if(bom.flag!=0){
					boss_shot.bullet[n].flag=0;
					continue;
				}
                if(out_judge_bossshot(n)==1){//如果子弹已经和自机接触
                    boss_shot.bullet[n].flag=0;//销毁子弹
                    if(ch.flag==0 && ch.mutekicnt==0){
                        ch.cnt=0;
                        ch.flag=1;
                        se_flag[3]=1;
                    }
                }
            }
        }
    }
}

//让敌人承受Boom的伤害
void cbom_and_enemy(){
    int s;
    if(bom.flag!=1)return;
    for(s=0;s<ENEMY_MAX;s++){//敌人总数
        if(enemy[s].flag>0)//如果敌人是存在的
            hit_enemy(s,ch.power/20);//给予伤害
    }
    //Boss存在且其不绘制flag为无效且在射击中
    if(boss.flag==1 && boss.graph_flag==0 && boss.state==2)
        hit_boss(ch.power/20);//嬺傜傢偡
}
//碰撞判定main
void out_main(){
    cbom_and_enemy();//
    cshot_and_enemy();//
    enemyshot_and_ch();//

}