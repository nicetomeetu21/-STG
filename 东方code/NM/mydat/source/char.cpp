#include "../include/GV.h"

void calc_ch(){
    if(ch.flag==1){//如果正在进行决死处理
        bright_set.brt=80;//变暗
        if(ch.cnt>20){//0.33秒中进行决死处理
            ch.flag   =2;    //1：正在进行决死处理 2：被击毁正在上浮中
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }
    if(ch.cnt==0 && ch.flag==2){//如果当前瞬间死掉的话
		
		memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);
		memset(&boss_shot,0,sizeof(boss_shot_t));
		memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);
		memset(shot,0,sizeof(shot_t)*SHOT_MAX);
		cc++;
		if(cc==100)
			func_state=-1;
        //ch.x=FMX/2;//
        //ch.y=FMY+30;
        //ch.mutekicnt++;//
		return;
    }
    if(ch.flag==2){//如果已经死掉正在上浮的话
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//将角色往上移动
        //1秒以上，或者角色已经到达某个的位置且按下了某个键
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//将角色的状态还原
        }
    }
    if(ch.mutekicnt>0){//如果无敌状态不为0的话
        ch.mutekicnt++;
        if(ch.mutekicnt>150)//如果已经2.5秒以上的话
            ch.mutekicnt=0;//还原
    }
    ch.cnt++;//角色计数器自增
    ch.img=(ch.cnt%24)/6;//决定当前的图像
}

void ch_move(){//控制角色的移动
    int i,sayu_flag=0,joge_flag=0;
    double x,y,mx,my,naname=1;
    double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};//{左,右,下,上}的速度
    int inputpad[4];
    inputpad[0]=CheckStatePad(configpad.left); inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down); inputpad[3]=CheckStatePad(configpad.up);

    if(ch.flag==1)return;//如果正在进行决死处理就不能移动

    if(CheckStatePad(configpad.left)>0)//左键按下的情况
        ch.img+=4*2;//图像左移
    else if(CheckStatePad(configpad.right)>0)//右键按下的情况
        ch.img+=4*1;//图像右移

    for(i=0;i<2;i++)//左右部分
        if(inputpad[i]>0)//如果左右方向上有输入
            sayu_flag=1;//设置左右移动的标志
    for(i=2;i<4;i++)//上下部分
        if(inputpad[i]>0)//如果上下方向有输入
            joge_flag=1;//设置上下移动的标志
    if(sayu_flag==1 && joge_flag==1)//如果左右、上下方向都有输入说明斜向移动
        naname=sqrt(2.0);//将移动速度变为1/√2

    for(int i=0;i<4;i++){//4方向分量循环
        if(inputpad[i]>0){//i方向的键盘或者手柄有输入
            x=ch.x , y=ch.y;//暂时存入当前的坐标
            mx=move_x[i];    my=move_y[i];//将移动分量带入mx和my  
            if(CheckStatePad(configpad.slow)>0){//如果低速运动
                mx=move_x[i]/3;    my=move_y[i]/3;//将移动速度变为1/3
            }
            x+=mx/naname , y+=my/naname;//为当前坐标加上移动分量
            if(!(x<10 || x>FMX-10 || y<5 || y>FMY-5)){//如果计算结果在可移动范围内
                ch.x=x , ch.y=y;//进行实际的移动
            }
        }
    }
}

