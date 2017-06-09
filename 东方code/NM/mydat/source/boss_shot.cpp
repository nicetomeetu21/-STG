#include "../include/GV.h"
#include "../include/func.h"

#define V0 10.0

//������ĳ���ָ��������������ĵ�¼����ָ��ʱ��t�ڻص��̶�λ�ã�
void input_phy_pos(double x,double y,int t){//�ƶ�����ʱ��
	double ymax_x,ymax_y;
	if(t==0)t=1;
	boss.phy.flag=1;//��¼��Ч
	boss.phy.cnt=0;//��ʱ����ʼ��
	boss.phy.set_t=t;//�����ƶ�����ʱ��
	ymax_x=boss.x-x;//��Ҫ�ƶ���ˮƽ����
	boss.phy.v0x=2*ymax_x/t;//ˮƽ�����ĳ��ٶ�
	boss.phy.ax =2*ymax_x/(t*t);//ˮƽ�����ļ��ٶ�
	boss.phy.prex=boss.x;//��ʼx����
	ymax_y=boss.y-y;//��Ҫ�ƶ�����ֱ����
	boss.phy.v0y=2*ymax_y/t;//��ֱ�����ĳ��ٶ�
	boss.phy.ay =2*ymax_y/(t*t);//��ֱ�����ļ��ٶ�
	boss.phy.prey=boss.y;//��ʼy����
}


void input_lphy(lazer_t *laz, int time, double angle){
	laz->lphy.angle   =angle;
	laz->lphy.base_ang=laz->angle;
	laz->lphy.time    =time;
}

//��t�μ����дӵ�ǰλ�õ��뿪dist��ôԶ��λ���ƶ�
int move_boss_pos(double x1,double y1,double x2,double y2,double dist, int t){
	int i=0;
	double x,y,angle;
	for(i=0;i<1000;i++){
		x=boss.x,y=boss.y;//���õ�ǰBoss��λ��
		angle=rang(PI);//����ؾ���ǰ������
		x+=cos(angle)*dist;//�����Ǹ��ط��ƶ�
		y+=sin(angle)*dist;
		if(x1<=x&&x<=x2 && y1<=y&&y<=y2){//����Ǹ������ƶ����ܵķ�Χ�ڵĻ�
			input_phy_pos(x,y,t);
			return 0;
		}
	}
	return -1;//1000���1000�γ��Զ����ܵĻ��ͷ��ش���
}

int search_boss_shot(){//���ؿձ��
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
double bossatan2(){//�Ի��͵������ɵļн�
	return atan2(ch.y-boss.y,ch.x-boss.x);
}
double bossatan3(int k,double x,double y){
	return atan2(y-boss_shot.bullet[k].y,x-boss_shot.bullet[k].x);
}
//�����������ĵ�¼����ָ��ʱ��t�ڻص��̶�λ�ã�
void input_phy(int t){//t= �������ƶ��ϵ�ʱ�� 
	double ymax_x,ymax_y;
	if(t==0)t=1;
	boss.phy.flag=1;//��¼��Ч
	boss.phy.cnt=0;//��������ʼ��
	boss.phy.set_t=t;//���ø����ƶ�ʱ��
	ymax_x=boss.x-BOSS_POS_X;//��Ҫ�ƶ���ˮƽ����
	boss.phy.v0x=2*ymax_x/t;//ˮƽ�����ĳ��ٶ�
	boss.phy.ax =2*ymax_x/(t*t);//ˮƽ�����ļ��ٶ�
	boss.phy.prex=boss.x;//��ʼx����
	ymax_y=boss.y-BOSS_POS_Y;//��Ҫ�ƶ�����ֱ����
	boss.phy.v0y=2*ymax_y/t;//��ֱ�����ĳ��ٶ�
	boss.phy.ay =2*ymax_y/(t*t);//��ֵ�����ļ��ٶ�
	boss.phy.prey=boss.y;//��ʼy����
}
//�����ϵĽ�ɫ�ƶ�����
void calc_phy(){
	double t=boss.phy.cnt;
	boss.x=boss.phy.prex-((boss.phy.v0x*t)-0.5*boss.phy.ax*t*t);//���㵱ǰӦ�����ڵ�x����
	boss.y=boss.phy.prey-((boss.phy.v0y*t)-0.5*boss.phy.ay*t*t);//���㵱ǰӦ�����ڵ�y����
	boss.phy.cnt++;
	if(boss.phy.cnt>=boss.phy.set_t)//������������ƶ���ʱ��Ļ�
		boss.phy.flag=0;// �����ƶ�Ϊ��Ч
}
//����Boss�ĵ�Ļ
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
//���õ�Ļ
void enter_boss_shot(){
	memset(&boss_shot , 0, sizeof(boss_shot_t));//�ӵ���Ϣ��ʼ��
	boss_shot.flag=1;
	boss.wtime=0;//����ʱ��0
	boss.state=2;//����Ϊ��Ļ�е�״̬
	boss.hp=boss.set_hp[boss.knd];//HP�趨
	boss.hp_max=boss.hp;
}

//����Boss
void enter_boss(int num){
	if(num==0){//��·Boss��ʼʱ�����
		memset(enemy,0,sizeof(enemy_t)*ENEMY_MAX);//�����ӱ�
		memset(shot,0,sizeof(shot_t)*SHOT_MAX);//���ٵ�Ļ
		boss.x=FMX/2;//����Boss�ĳ�ʼ����
		boss.y=-30;
		if(theone==0)//��Ļ������
		boss.knd=1;
		else boss.knd=-1;
	}
	boss.flag=1;
	boss.hagoromo=0;//�Ƿ���״��ɢ��flag
	boss.endtime=99*60;//ʣ��ʱ��
	boss.state=1;//����״̬Ϊ������
	boss.cnt=0;
	
              // bgm_main();      //enter_func_tm("BGMmain");
	boss.graph_flag=0;//�ָ�����flag
	boss.knd++;
	boss.wtime=0;//��ʼ������ʱ��
	memset(lazer,0,sizeof(lazer_t)*LAZER_MAX);
	memset(&boss_shot,0,sizeof(boss_shot_t));//��ʼ��Boss�ĵ�Ļ��Ϣ
	input_phy(60);//������60�μ�������������лص��̶�λ��
}

//Boss�Ĵ�������
void waitandenter(){
	int t=400;
	boss.wtime++;
	if(boss.wtime>t)//�������140�μ����Ļ����õ�Ļ
		enter_boss_shot();
}

void calc_boss(){
	boss.dx=boss.x;
	boss.dy=boss.y+sin(PI2/130*(count%130))*10;
}




	//Boss�ĵ�Ļmain
void boss_shot_main(){
	
	if(stage_count==boss.appear_count[0]+2 && boss.flag==0){//������˿�ʼʱ��Ļ�
		enter_boss(0);//��ʼ
		//PlaySoundMem(sound_se[99],DX_PLAYTYPE_BACK);
	}
	if(boss.flag==0)
		return;
	calc_boss();
	if(boss.phy.flag==1)//��������ƶ�������Ч
		calc_phy();//�����������
	if(boss.state==2 && (boss.hp<=0 || boss.endtime<=0)){//����ڵ�Ļ������Ϊ0�Ļ�
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
			
	if(boss.state==1){//��Ļ֮��Ĵ���ʱ��
		waitandenter();
	}
	if(boss.state==2){//����ڵ�Ļ��
		boss_shot_bullet[theone]();//���뵯Ļ����
		//if(theone==0)
		//W	boss.knd=2;
		boss_shot_calc();//���㵯Ļ
	}
	boss.cnt++;
}



