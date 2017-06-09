#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2
#define BRANGE 40.0

extern int out_lazer();

///���˵���ײ�ж���Χ
int enemy_range[ENEMY_RANGE_MAX]={16,30,16,50};
//�Ի�������ӵ�����ײ��Χ
int cshot_range[CSHOT_RANGE_MAX]={6,};

//
//��������꣺1 ������ײ�ж������壺2
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;
    double x=x1-x2;//���˺��Ի�������ӵ��ľ���
    double y=y1-y2;
    //���˵���ײ�ж����Ի�˫ɫ������ײ�ж��ĺϼƷ�Χ
    double r=range1+range2;
    //����б�Ҫ�����м䲿��
    if(spd1>r){
        //����1֡��ǰ��λ��
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;
        for(j=0;j<spd1/r;j++){//ǰ�����֡���ײ�ж����ִ�ѭ��
            px=pre_x-x2;
            py=pre_y-y2;
            if(px*px+py*py<r*r)
                return 1;
            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }
    if(x*x+y*y<r*r)//�������ײ�ж��ڵĻ�
        return 1;//��ײ
    return 0;
}

 //�жϵ��˺��Ի�����Ƿ�����
int out_judge_cshot(int i,int s){
    if(cshot[i].cnt>0){//������ӵ��Ĺ��������ټ����һ��
        if(out_judge(cshot[i].x,cshot[i].y,enemy[s].x,enemy[s].y,
            cshot_range[cshot[i].knd],enemy_range[enemy[s].knd],
            cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//�ж�Boss�Ƿ���Ի������ײ
int out_judge_cshot_boss(int i){
    if(cshot[i].cnt>0){//���������ӵ��Ĺ�����ټ����һ��
        if(out_judge(cshot[i].x,cshot[i].y,boss.x,boss.y,
            cshot_range[cshot[i].knd],BRANGE,cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//�ж��Ի��Ƿ�͵����������
int out_judge_enemyshot(int s,int n){
    if(shot[s].bullet[n].cnt>0){//���������ӵ��Ĺ�����ټ����һ��
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

//�Ƿ��Ի��Ƿ��Boss�������
int out_judge_bossshot(int n){
    if(boss_shot.bullet[n].cnt>0){//������ӵ��Ĺ�����ټ����һ�εĻ�
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

//���������Ƿ����
void enemy_death_judge(int s){
    int i;
    se_flag[8]=1;//���˱����е�����
    if(enemy[s].hp<0){//�������HPС��0
        enemy[s].flag=0;//�������
        se_flag[1]=1;//���˻�����
        enter_del_effect(s);
        for(i=0;i<SHOT_MAX;i++){//����������ѭ��
            if(shot[i].flag!=0){//������Ѿ���¼�ĵ�Ļ����
                if(s==shot[i].num){//�����Ǹ������е�¼�˵ĵ�Ļ
                    shot[i].flag=2;//��flag����Ϊ���ټ���
                    break;
                }
            }
        }
    }
	
}

//��s��ŵĵ��˳���power���˺�
void hit_enemy(int s,int power){
    enemy[s].hp-=power;//�����ӵ����е�power����HP
    enemy_death_judge(s);//�жϵ����Ƿ����
}

//��Boss����power�˺�
void hit_boss(int power){
    boss.hp-=power;//��HP�����ӵ������е�power������
}


//�Ի�����͵��˵Ĵ���
void cshot_and_enemy(){
    int i,s;
    for(i=0;i<CSHOT_MAX;i++){//�Ի�������ӵ�����
        if(cshot[i].flag>0){
            for(s=0;s<ENEMY_MAX;s++){//��������
                if(enemy[s].flag>0){
                    if(out_judge_cshot(i,s)){//����Ի�������ӵ��͵�������
                        cshot[i].flag=0;//���Լ��ӵ�����
                        hit_enemy(s,cshot[i].power);
                        break;
                    }
                }
            }
            //Boss�������䲻���flagΪ��Ч���������
            if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
                if(out_judge_cshot_boss(i)){
                    cshot[i].flag=0;
                    hit_boss(cshot[i].power);
                }
            }
        }
    }
}

//����������Ի��Ĵ���
void enemyshot_and_ch(){
    int s,n;
	if(ch.flag==0 && ch.mutekicnt==0 && out_lazer()==1){
        ch.cnt=0;
        ch.flag=1;
        se_flag[3]=1;
	}
    //�ӱ������
    for(s=0;s<SHOT_MAX;s++){//����������ӵ�����
        if(shot[s].flag>0){//�����ǰ�������¼�˵Ļ�
            for(n=0;n<SHOT_BULLET_MAX;n++){//�ӵ�����
                if(shot[s].bullet[n].flag==1){//����ӵ�����¼�˵Ļ�
					if(bom.flag!=0){
						shot[s].bullet[n].flag=0;//�����ӵ�
						continue;
					}
                    if(out_judge_enemyshot(s,n)==1){//״̬Ϊһ��״̬���Ҳ����޵�״̬��
                        shot[s].bullet[n].flag=0;//
                        if(ch.flag==0 && ch.mutekicnt==0){
                            ch.cnt=0;
                            ch.flag=1;//1�����ڽ��о������� 2���Ѿ����������µ��Ի����ڴ��¸�����
                            se_flag[3]=1;//������
                        }
                    }
                }
            }
        }
    }
    //Boss���
    if(boss_shot.flag>0){//�������Ѿ���¼
        for(n=0;n<BOSS_BULLET_MAX;n++){//�ӵ�����
            if(boss_shot.bullet[n].flag==1){//����ӵ��Ѿ���¼
				if(bom.flag!=0){
					boss_shot.bullet[n].flag=0;
					continue;
				}
                if(out_judge_bossshot(n)==1){//����ӵ��Ѿ����Ի��Ӵ�
                    boss_shot.bullet[n].flag=0;//�����ӵ�
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

//�õ��˳���Boom���˺�
void cbom_and_enemy(){
    int s;
    if(bom.flag!=1)return;
    for(s=0;s<ENEMY_MAX;s++){//��������
        if(enemy[s].flag>0)//��������Ǵ��ڵ�
            hit_enemy(s,ch.power/20);//�����˺�
    }
    //Boss�������䲻����flagΪ��Ч���������
    if(boss.flag==1 && boss.graph_flag==0 && boss.state==2)
        hit_boss(ch.power/20);//���킷
}
//��ײ�ж�main
void out_main(){
    cbom_and_enemy();//
    cshot_and_enemy();//
    enemyshot_and_ch();//

}