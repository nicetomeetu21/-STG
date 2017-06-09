#include "../include/GV.h"

//返回-ang～ang的随机角度
double rang(double ang){
    return ( -ang + ang*2 * GetRand(10000)/10000.0 );
}

//移动模式0
//向下移动后停止然后往上移动
void enemy_pattern0(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=3;//向下移动
    if(t==40)
        enemy[i].vy=0;//停止
    if(t==40+enemy[i].wait)//在登录的时间区间内停止
        enemy[i].vy=-3;//向上移动
}

//移动模式1
//向下移动然后停止然后向左下移动
void enemy_pattern1(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=3;//向下移动
    if(t==40)
        enemy[i].vy=0;//停止
    if(t==40+enemy[i].wait){//在登录的时间区间内停止
        enemy[i].vx=-1;//向左
        enemy[i].vy=2;//向下移动
        enemy[i].muki=0;//设置方向为左
    }
}



void enemy_pattern2(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=3;
    if(t==40)
        enemy[i].vy=0;
    if(t==40+enemy[i].wait){
        enemy[i].vx=1;
        enemy[i].vy=2;
        enemy[i].muki=2;
    }
}



void enemy_pattern3(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=5;
    if(t==30){
        enemy[i].muki=0;
    }
    if(t<100){
        enemy[i].vx-=5/100.0;
        enemy[i].vy-=5/100.0;
    }
}



void enemy_pattern4(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=5;
    if(t==30){
        enemy[i].muki=2;
    }
    if(t<100){
        enemy[i].vx+=5/100.0;
        enemy[i].vy-=5/100.0;
    }
}



void enemy_pattern5(int i){
    int t=enemy[i].cnt;
    if(t==0){
        enemy[i].vx-=1;
        enemy[i].vy=2;
        enemy[i].muki=0;
    }
}



void enemy_pattern6(int i){
    int t=enemy[i].cnt;
    if(t==0){
        enemy[i].vx+=1;
        enemy[i].vy=2;
        enemy[i].muki=2;
    }
}



void enemy_pattern7(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait){
        enemy[i].vx=-0.7;
        enemy[i].vy=-0.3;
        enemy[i].muki=0;
    }
}



void enemy_pattern8(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait){
        enemy[i].vx=+0.7;
        enemy[i].vy=-0.3;
        enemy[i].muki=2;
    }
}



void enemy_pattern9(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait)
        enemy[i].vy=-1;
}




void enemy_pattern10(int i){
    int t=enemy[i].cnt;
    if(t==0) enemy[i].vy=4;
    if(t==40)enemy[i].vy=0;
    if(t>=40){
        if(t%60==00){
            int r=cos(enemy[i].ang)< 0 ? 0 : 1;
            enemy[i].sp=6+rang(2);
            enemy[i].ang=rang(PI/4)+PI*r;
            enemy[i].muki=2-2*r;
        }
        enemy[i].sp*=0.95;
    }
    if(t>=40+enemy[i].wait){
        enemy[i].vy-=0.05;
    }
}

