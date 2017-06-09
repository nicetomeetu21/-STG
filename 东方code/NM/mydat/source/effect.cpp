#include "../include/GV.h"

//搜索登录为空的特效编号
int search_effect(){
    for(int i=0;i<EFFECT_MAX;i++){
        if(effect[i].flag==0)
            return i;
    }
    return -1;
}

//计算特效
void calc_effect(){
    for(int i=0;i<EFFECT_MAX;i++){
        if(effect[i].flag>0){//如果特效已经被登录了
            effect[i].x+=cos(effect[i].mvang)*effect[i].spd;//坐标计算
            effect[i].y+=sin(effect[i].mvang)*effect[i].spd;
            switch(effect[i].knd){//按照特效的种类进行分歧	
                case 0://敌人的消灭特效
                    effect[i].cnt++;
                    effect[i].r+=0.08;//特效的大小逐渐变大
                    if(effect[i].cnt>10)//如果计数超过了10
                        effect[i].brt-=25;//将亮度变暗
                    if(effect[i].cnt>20)//如果计数超过了20
                        effect[i].flag=0;//销毁
                    break;
                case 1:// Boom的特效
                    //速度计算
                    if(effect[i].cnt<60)
                        effect[i].spd-=(0.2+effect[i].cnt*effect[i].cnt/3000.0);
                    if(effect[i].cnt==60){
                        effect[i].spd=0;
                        se_flag[15]=1;
                        dn.flag=1;
                        dn.cnt=0;
                        dn.size=11;
                        dn.time=20;
                    }
                    //亮度和大小的计算
                    effect[i].r+=0.015;
                    if(effect[i].cnt<51)
                        effect[i].brt+=5;
                    if(effect[i].cnt>=60){
                        effect[i].r+=0.04;
                        effect[i].brt-=255/30.0;
                    }
                    //计数器自增以及消去计算
                    effect[i].cnt++;
                    if(effect[i].cnt>=90)
                        effect[i].flag=0;
                    break;
                case 2:// Boom特效（角色）
                    //亮度计算
                    if(effect[i].cnt<51)
                        effect[i].brt+=4;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=4;
                    //计数器自增及消去计算
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;
                case 3://Boom的特效（线）
                    //亮度计算
                    if(effect[i].cnt<51)
                        effect[i].brt+=2;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=2;
                    //计数器自增与消去计算
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;                
                case 4://决死特效
                    //亮度计算
                    if(effect[i].cnt>=6)
                        effect[i].brt-=255/6;
                    effect[i].r+=0.12;
                    effect[i].cnt++;
                    if(effect[i].cnt>=12 || ch.flag!=1)
                        effect[i].flag=0;
                    break;                
                default:
                    printfDx("effect error\n");
                    break;
            }
        }
    }
}

//搜索登录为空的消灭特效的编号
int search_del_effect(){
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag==0)
            return i;
    }
    return -1;
}

//登录消灭特效
void enter_del_effect(int s){
    int k=search_del_effect();
    if(k!=-1){
        del_effect[k].flag=1;//设置flag为有效
        del_effect[k].cnt=0;
        del_effect[k].col=enemy[s].back_col;//将敌人的背景色设定为消灭色
        del_effect[k].x=enemy[s].x;//将敌人的坐标设置为消灭位置
        del_effect[k].y=enemy[s].y;
    }
}

//计算消灭特效、登录特效
void calc_del_effect(){
    int k;
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag>0){
            if(del_effect[i].cnt%2==0){//每1/30秒设定一次
                if((k=search_effect())!=-1){//搜索空编号
                    memset(&effect[k],0,sizeof(effect_t));//初始化
                    effect[k].flag=1;//设置flag为有效
                    effect[k].brt=255;//亮度设置为最大值
                    effect[k].ang=rang(PI);//随机角度
                    effect[k].col=del_effect[i].col;//设置颜色
                    effect[k].eff=1;// 1是闪光特效。闪光特效为1.
                    effect[k].img=img_del_effect[effect[k].col];//设置消灭图像
                    effect[k].knd=0;//特效的种类是0号（消灭特效为0）
                    effect[k].x=del_effect[i].x;//设置坐标
                    effect[k].y=del_effect[i].y;
                    effect[k].spd=0;
                }
            }
            if(del_effect[i].cnt>8){
                del_effect[i].flag=0;
            }
            del_effect[i].cnt++;
        }
    }
}

//登录Boom
void enter_bom(){
    int k;
    bom.flag=1;
    bom.cnt=0;
    bom.knd=0;
    ch.flag=0;
    ch.mutekicnt=1;//设置为无敌
    se_flag[14]=1;//播放确定声
    //竖线
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;// Boom的线的特效
        effect[k].brt=0;//α值
        effect[k].ang=PI/2;//图像的方向
        effect[k].mvang=-PI/2;//特效前进的方向
        effect[k].spd=1;//速度
        effect[k].r=1;//大小
        effect[k].eff=2;//α混合
        effect[k].img=img_eff_bom[3];
        effect[k].x=70;//坐标
        effect[k].y=300;
    }
    //横线
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;// Boom的线的特效
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=0;
        effect[k].spd=1;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[3];
        effect[k].x=100;
        effect[k].y=350;
    }
   //角色
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=2;//Boom的角色、线的特效
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=-PI/2;
        effect[k].spd=0.7;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[2];
        effect[k].x=260;
        effect[k].y=300;
    }
}
//咚梆地摇动画面的处理
void dn_calc(){
    if(dn.flag==1){
        dn.x=(int)rang(dn.size);
        dn.y=(int)rang(dn.size);
        dn.cnt++;
        if(dn.cnt>dn.time){//如果超过了预设的时间的话就结束
            dn.flag=0;
            dn.x=0;
            dn.y=0;
        }
    }
}

//Boom计算
void bom_calc(){
    int n,k;
	double shot_angle[4]={0,PI,PI/2,PI*1.5};//4发特效飞行的角度
    if((ch.flag==0||ch.flag==1) && bom.flag==0){//角色如果是通常状态且没有放Boom
        if(CheckStatePad(configpad.bom)==1){//如果Boom键被按下
            if(ch.limit<=0){
			printf("NO MORE BOOM");
			}
			else{
            enter_bom();
			ch.limit--;
			}
        }
    }
    if(bom.flag==1){//如果Boom已经被登录
        if(bom.cnt%10==0){//1/6秒一次
            n=(bom.cnt/10);
            if(n<4 && (k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=1;//特效编号1：Boom的特效
                effect[k].brt=0;
                effect[k].ang=rang(PI);//随机的图像方向
                effect[k].mvang=shot_angle[n]-PI/4;//飞行方向
                effect[k].spd=13+rang(2);//速度
                effect[k].r=0.5;//大小
                effect[k].eff=2;//α混合
                effect[k].img=img_eff_bom[(bom.cnt/10)/3];//图像
                effect[k].x=ch.x;//坐标
                effect[k].y=ch.y;
            }
        }
        bom.cnt++;
        if(bom.cnt<40)
            bright_set.brt=255-bom.cnt*5;//设定画面的亮度（暗）
        if(bom.cnt>90)
            bright_set.brt=255-40*5+(bom.cnt-90)*5;//设定画面的的亮度（亮）
        if(bom.cnt>130){
            bom.flag=0;
            bright_set.brt=255;
        }
    }
}


void enter_crybom_effect(){
    int k;
    if(ch.flag==1){
        if(ch.cnt%2==0){
            if((k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=4;//决死特效
                effect[k].brt=255;
                effect[k].ang=rang(PI);
                effect[k].spd=0;
                effect[k].r=0;
                effect[k].eff=2;
                effect[k].img=img_del_effect[GetRand(4)];
                effect[k].x=ch.x;
                effect[k].y=ch.y;
            }
        }
    }
}

void effect_main(){
    dn_calc();//咚梆地摇晃画面的处理
    calc_del_effect();//消灭特效的计算
    calc_effect();//特效的计算
    bom_calc();//Boom计算
    enter_crybom_effect();
}