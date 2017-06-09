#include "../include/GV.h"

extern void shot_bullet_H000(int);extern void shot_bullet_H001(int);extern void shot_bullet_H002(int);
extern void shot_bullet_H003(int);extern void shot_bullet_H004(int);extern void shot_bullet_H005(int);
extern void shot_bullet_H006(int);extern void shot_bullet_H007(int);extern void shot_bullet_H008(int);
extern void shot_bullet_H009(int);extern void shot_bullet_H010(int);extern void shot_bullet_H011(int);
extern void shot_bullet_H012(int);extern void shot_bullet_H013(int);extern void shot_bullet_H014(int);
extern void shot_bullet_H015(int);extern void shot_bullet_H016(int);extern void shot_bullet_H017(int);

void (*shot_bullet[SHOT_KND_MAX])(int) ={
	shot_bullet_H000,shot_bullet_H001,shot_bullet_H002,shot_bullet_H003,shot_bullet_H004,
	shot_bullet_H005,shot_bullet_H006,shot_bullet_H007,shot_bullet_H008,shot_bullet_H009,
	shot_bullet_H010,shot_bullet_H011,shot_bullet_H012,shot_bullet_H013,shot_bullet_H014,
	shot_bullet_H015,shot_bullet_H016,shot_bullet_H017,
};


double shotatan2(int n){
	return atan2(ch.y-enemy[shot[n].num].y,ch.x-enemy[shot[n].num].x);
}


void conv_pos0(double *x, double *y, double x0, double y0, double mx, double my,double ang){
	double ox=x0-mx,oy=y0-my;
	*x=ox*cos(ang) +oy*sin(ang);
	*y=-ox*sin(ang)+oy*cos(ang);
	*x+=mx;
	*y+=my;
}


int shot_search(int n){
	int i;
	for(i=0;i<SHOT_BULLET_MAX;i++){
		if(shot[n].bullet[i].flag==0){
			return i;
		}
	}
	return -1;
}

void shot_calc(int n){
	int i,max=0;
	if(enemy[shot[n].num].flag!=1)
		shot[n].flag=2;
	for(i=0;i<SHOT_BULLET_MAX;i++){
		if(shot[n].bullet[i].flag>0){
			shot[n].bullet[i].x+=cos(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
			shot[n].bullet[i].y+=sin(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
			shot[n].bullet[i].cnt++;
			if(shot[n].bullet[i].x<-60 || shot[n].bullet[i].x>FMX+60 ||
				shot[n].bullet[i].y<-60 || shot[n].bullet[i].y>FMY+60){
				if(shot[n].bullet[i].till<shot[n].bullet[i].cnt)
					shot[n].bullet[i].flag=0;
			}
		}
	}
	//���ݕ\�����̒e����ł����邩�ǂ������ׂ�
	for(i=0;i<SHOT_BULLET_MAX;i++)
		if(shot[n].bullet[i].flag>0)
			return;
	//���ݕ\�����̒e������Ȃ����
	if(enemy[shot[n].num].flag!=1){
		shot[n].flag=0;//�I��
		enemy[shot[n].num].flag=0;
	}
}

void lazer_calc(){
	int i;
	for(i=0;i<LAZER_MAX;i++){
		if(lazer[i].flag>0){
			//�\���ʒu��ݒ�
			lazer[i].disppt[0].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*lazer[i].haba;
			lazer[i].disppt[0].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*lazer[i].haba;
			lazer[i].disppt[1].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*lazer[i].haba;
			lazer[i].disppt[1].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*lazer[i].haba;
			lazer[i].disppt[2].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*lazer[i].haba+cos(lazer[i].angle)*lazer[i].length;
			lazer[i].disppt[2].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*lazer[i].haba+sin(lazer[i].angle)*lazer[i].length;
			lazer[i].disppt[3].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*lazer[i].haba+cos(lazer[i].angle)*lazer[i].length;
			lazer[i].disppt[3].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*lazer[i].haba+sin(lazer[i].angle)*lazer[i].length;
			//������͈͂�ݒ�
			lazer[i].outpt[0].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[0].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[1].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[1].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[2].x=lazer[i].startpt.x+cos(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*lazer[i].hantei+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[2].y=lazer[i].startpt.y+sin(lazer[i].angle-PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*lazer[i].hantei+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[3].x=lazer[i].startpt.x+cos(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+cos(lazer[i].angle)*lazer[i].length*lazer[i].hantei+cos(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			lazer[i].outpt[3].y=lazer[i].startpt.y+sin(lazer[i].angle+PI/2)*(lazer[i].haba*lazer[i].hantei)+sin(lazer[i].angle)*lazer[i].length*lazer[i].hantei+sin(lazer[i].angle)*lazer[i].length*((1-lazer[i].hantei)/2);
			
			double ymax=lazer[i].lphy.angle,ty=lazer[i].lphy.time,t=lazer[i].cnt;
			double delt=(2*ymax*t/ty - ymax*t*t/(ty*ty));
			if(lazer[i].lphy.time!=0)//��]�ړ����ԓ��Ȃ�
				lazer[i].angle=lazer[i].lphy.base_ang+delt;//��]����
			if(lazer[i].lphy.conv_flag==1){//���W�ϊ������邩
				conv_pos0(&lazer[i].startpt.x,&lazer[i].startpt.y,
					lazer[i].lphy.conv_x,lazer[i].lphy.conv_y,
					lazer[i].lphy.conv_base_x,lazer[i].lphy.conv_base_y,
					-delt);
			}
			if(lazer[i].cnt>lazer[i].lphy.time){//��]���Ԃ��߂���Ƃ�߂�
				lazer[i].lphy.time=0;
				lazer[i].lphy.conv_flag=0;
			}
			lazer[i].cnt++;
		}
	}
}

void shot_main(){
	int i;
	for(i=0;i<SHOT_MAX;i++){//�e���f�[�^�v�Z
		//�t���O�������Ă��āA�ݒ肵����ނ��Ԉ���Ă��Ȃ����(�I�[�o�[�t���[�΍�)
		if(shot[i].flag!=0 && 0<=shot[i].knd && shot[i].knd<SHOT_KND_MAX){
			shot_bullet[shot[i].knd](i);//.knd�̒e���v�Z�֐����ĂԊ֐��|�C���^
			shot_calc(i);//i�Ԗڂ̒e�����v�Z
			shot[i].cnt++;
		}
	}
	lazer_calc();
}
