#include "../include/GV.h"

extern int search_boss_shot();
extern int search_lazer();
extern double bossatan2();
extern double bossatan3(int k,double x,double y);
extern int move_boss_pos(double x1,double y1,double x2,double y2,double dist, int t);
extern void input_phy_pos(double x,double y,int t);
extern void input_lphy(lazer_t *laz, int time, double angle);


void boss_shot_bulletH0000(){
#define TM000 120
	int i,k,t=boss_shot.cnt%TM000;
	double angle;
	if(t<60 && t%5==0){
		angle=bossatan2();
		for(i=0;i<50;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = boss.x;
				boss_shot.bullet[k].y     = boss.y;
				boss_shot.bullet[k].knd   = 8;
				boss_shot.bullet[k].angle = angle+PI2/50*i;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 3;
				se_flag[0]=1;
			}
		}
	}
	if(t%1==0){
		if((k=search_boss_shot())!=-1){
			boss_shot.bullet[k].col	  = 0;
			boss_shot.bullet[k].x     = GetRand(384);
			boss_shot.bullet[k].y     = GetRand(200);
			boss_shot.bullet[k].knd   = 8;
			boss_shot.bullet[k].angle = PI/2;
			boss_shot.bullet[k].flag  = 1;
			boss_shot.bullet[k].cnt	  = 0;
			boss_shot.bullet[k].spd	  = 1+rang(0.5);
			se_flag[0]=1;
		}
	}
	for(i=0;i<BOSS_BULLET_MAX;i++){
		if(boss_shot.bullet[i].flag>0){

		}
	}
}

void boss_shot_bulletH0001(){
#define TM0001 120
	int i,k,t=boss_shot.cnt%TM0001;
	double angle;
	if(t%5==0){
		angle=bossatan2();
		for(i=0;i<50;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = boss.x+150;
				boss_shot.bullet[k].y     = boss.y-20;
				boss_shot.bullet[k].knd   = 8;
				boss_shot.bullet[k].angle = angle+PI2/50*i;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 3;
				se_flag[0]=1;
			}
		}
		for(i=0;i<50;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = boss.x-150;
				boss_shot.bullet[k].y     = boss.y-20;
				boss_shot.bullet[k].knd   = 8;
				boss_shot.bullet[k].angle = angle+PI2/50*i;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 3;
				se_flag[0]=1;
			}
		}
	}
	if(t%3==0){
		if((k=search_boss_shot())!=-1){
			boss_shot.bullet[k].col	  = 0;
			boss_shot.bullet[k].x     = GetRand(384);
			boss_shot.bullet[k].y     = GetRand(200);
			boss_shot.bullet[k].knd   = 4;
			boss_shot.bullet[k].angle = PI/2;
			boss_shot.bullet[k].flag  = 1;
			boss_shot.bullet[k].cnt	  = 0;
			boss_shot.bullet[k].spd	  = 1+rang(0.5);
			se_flag[0]=1;
		}
	}
	for(i=0;i<BOSS_BULLET_MAX;i++){
		if(boss_shot.bullet[i].flag>0){

		}
	}
}

void boss_shot_bulletH0001ex(){
#define TM0001 120
	int i,k,t=boss_shot.cnt%TM0001;
	double angle; 
	if(t%4==0){
		angle=bossatan2();
		for(i=0;i<100;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = GetRand(FMX);
				boss_shot.bullet[k].y     = GetRand(200);
				boss_shot.bullet[k].knd   = 8;
				boss_shot.bullet[k].angle = angle+PI2/30*i;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 3+rang(1);
				se_flag[0]=1;
			}
		}
	}
}

void boss_shot_bulletH0002(){
#define TM0002 120
	int i,k,t=boss_shot.cnt%TM0002;
	double angle;
	if(5>=0 && t<=120 && t%10==0){
		angle=bossatan2();
		for(i=0;i<30;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = boss.x+cos(PI/2+PI/150*t)*100;
				boss_shot.bullet[k].y     = boss.y+sin(PI/2+PI/150*t)*100;
				boss_shot.bullet[k].knd   = 7;
				boss_shot.bullet[k].angle = PI2/30*i;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 1.5;
				se_flag[0]=1;
			}
		}
		for(i=0;i<30;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 8;
				boss_shot.bullet[k].x     = boss.x+cos(PI/2-PI/150*t)*100;
				boss_shot.bullet[k].y     = boss.y+sin(PI/2-PI/150*t)*100;
				boss_shot.bullet[k].knd   = 7;
				boss_shot.bullet[k].angle = PI2/30*i;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 1.5;
				se_flag[0]=1;
			}
		}
	}
}

void boss_shot_bulletH0003(){
#define TM0003 120
	int i,k,t=boss_shot.cnt%TM0003;
	double angle;
	if(t%1==0){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = GetRand(FMX);
				boss_shot.bullet[k].y     = 0;
				boss_shot.bullet[k].knd   = 7;
				boss_shot.bullet[k].angle = PI/2+rang(PI/6)-PI/12;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 4+rang(1.2);
				se_flag[0]=1;
			}
		
	}

}


void boss_shot_bulletH0004(){
#define TM0004 640
#define DIST 40
    int i,j,s,k,t=boss_shot.cnt%TM0004,t2=boss_shot.cnt;
	double angle;
	static int num=4;
	if(t%4==0){
		angle=bossatan2();
		for(i=0;i<10;i++){
			if((k=search_boss_shot())!=-1){
				boss_shot.bullet[k].col	  = 0;
				boss_shot.bullet[k].x     = GetRand(FMX);
				boss_shot.bullet[k].y     =	0;
				boss_shot.bullet[k].knd   = 8;
				boss_shot.bullet[k].angle = PI/2+rang(PI/6)+PI/12;
				boss_shot.bullet[k].flag  = 1;
				boss_shot.bullet[k].cnt	  = 0;
				boss_shot.bullet[k].spd	  = 2+rang(0.5);
			}
		}
	}
	if(t==0){
		for(int h=0;h<=LAZER_MAX;h++)
			lazer[h].flag=0;
        for(j=0;j<2;j++){;
            for(i=0;i<num;i++){
                //int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//�ӵ�����ɫ
                    lazer[k].knd      = 0;//�ӵ�������
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//�Ƕ�
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//��ʼ���ƵĽǶ�
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;//�Ƿ���ʾ��0:��1:��
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 6;//����
                    lazer[k].state    = j;//
                    lazer[k].length   = 240;//����
                    lazer[k].hantei      = 1;//�Ƿ���ײ�ж���0:�ǡ�1:��
                    lazer[k].lphy.conv_flag=1;//�Ƿ���ת��0:��1����
                    lazer[k].lphy.conv_base_x=boss.x;//��ת�Ļ�׼����
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;//��ת�ļ���λ��
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],240,4*PI/num);//��¼��Ϣ
					//lazer[k].flag=0;
                }
            }
        }
    }
	
	if(t==60){
		//for(int h=0;h<=LAZER_MAX;h++)
			//lazer[h].flag=0;
        for(j=0;j<2;j++){;
            for(i=0;i<num;i++){
                //int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//�ӵ�����ɫ
                    lazer[k].knd      = 0;//�ӵ�������
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//�Ƕ�
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//��ʼ���ƵĽǶ�
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;//�Ƿ���ʾ��0:��1:��
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 6;//����
                    lazer[k].state    = j;//
                    lazer[k].length   = 240;//����
                    lazer[k].hantei      = 1;//�Ƿ���ײ�ж���0:�ǡ�1:��
                    lazer[k].lphy.conv_flag=1;//�Ƿ���ת��0:��1����
                    lazer[k].lphy.conv_base_x=boss.x;//��ת�Ļ�׼����
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;//��ת�ļ���λ��
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],240,4*PI/num);//��¼��Ϣ
					//lazer[k].flag=0;
                }
            }
        }
    }
	if(t==120){
		//for(int h=0;h<=LAZER_MAX;h++)
			//lazer[h].flag=0;
        for(j=0;j<2;j++){;
            for(i=0;i<num;i++){
                //int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//�ӵ�����ɫ
                    lazer[k].knd      = 0;//�ӵ�������
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//�Ƕ�
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//��ʼ���ƵĽǶ�
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;//�Ƿ���ʾ��0:��1:��
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 6;//����
                    lazer[k].state    = j;//
                    lazer[k].length   = 240;//����
                    lazer[k].hantei      = 1;//�Ƿ���ײ�ж���0:�ǡ�1:��
                    lazer[k].lphy.conv_flag=1;//�Ƿ���ת��0:��1����
                    lazer[k].lphy.conv_base_x=boss.x;//��ת�Ļ�׼����
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;//��ת�ļ���λ��
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],240,4*PI/num);//��¼��Ϣ
					//lazer[k].flag=0;
                }
            }
        }
    }
	
	if(t==180){
		//for(int h=0;h<=LAZER_MAX;h++)
			//lazer[h].flag=0;
        for(j=0;j<2;j++){;
            for(i=0;i<num;i++){
                //int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//�ӵ�����ɫ
                    lazer[k].knd      = 0;//�ӵ�������
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//�Ƕ�
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//��ʼ���ƵĽǶ�
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;//�Ƿ���ʾ��0:��1:��
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 6;//����
                    lazer[k].state    = j;//
                    lazer[k].length   = 240;//����
                    lazer[k].hantei      = 1;//�Ƿ���ײ�ж���0:�ǡ�1:��
                    lazer[k].lphy.conv_flag=1;//�Ƿ���ת��0:��1����
                    lazer[k].lphy.conv_base_x=boss.x;//��ת�Ļ�׼����
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;//��ת�ļ���λ��
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],240,4*PI/num);//��¼��Ϣ;
					//lazer[k].flag=0;
                }
            }
        }
    }


}

//�˷ֆD
void boss_shot_bulletH0004ex(){
#define TM009 420
#define DIST 60
    int i,j,k,s,t=boss_shot.cnt%TM009,t2=boss_shot.cnt;
    double angle;
    static int num;
    if(t2==0)num=4;
    if(t==0){
        for(j=0;j<2;j++){
            for(i=0;i<num;i++){
                int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//�ӵ�����ɫ
                    lazer[k].knd      = 0;//�ӵ�������
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//�Ƕ�
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//��ʼ���ƵĽǶ�
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;//�Ƿ���ʾ��0:��1:��
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 2;//����
                    lazer[k].state    = j;//
                    lazer[k].length   = 240;//����
                    lazer[k].hantei      = 0;//�Ƿ���ײ�ж���0:�ǡ�1:��
                    lazer[k].lphy.conv_flag=1;//�Ƿ���ת��0:��1����
                    lazer[k].lphy.conv_base_x=boss.x;//��ת�Ļ�׼����
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;//��ת�ļ���λ��
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],80,PI/num*plmn);//��¼��k�ż�����80�μ�����ֻ��תPI/num*plmn�Ƕȵ���Ϣ
                }
            }
        }
        se_flag[33]=1;
    }
	//60�μ���һ��ÿ10�μ���1��
    if(t==50){
        angle=rang(PI);//�Ի���Boss���ɽǶ�
        for(s=0;s<2;s++){
            for(t=0;t<3;t++){
                for(j=0;j<3;j++){
                    for(i=0;i<30;i++){
                        if((k=search_boss_shot())!=-1){
                            boss_shot.bullet[k].col   = s;//�ӵ�����ɫ
                            boss_shot.bullet[k].x     = boss.x;//����
                            boss_shot.bullet[k].y     = boss.y;
                            boss_shot.bullet[k].knd   = 11;//�ӵ�������
                            boss_shot.bullet[k].angle = angle+PI2/30*i+PI2/60*s;//�Ƕ�
                            boss_shot.bullet[k].flag  = 1;
                            boss_shot.bullet[k].cnt   = 0;
                            boss_shot.bullet[k].spd   = 1.8-0.2*j+0.1*s;//�ٶ�
                            boss_shot.bullet[k].eff   = 0;
                            boss_shot.bullet[k].state   = t;
                        }
                        se_flag[0]=1;
                    }
                }
            }
        }
    }
    if(t>=170 && t<310 && (t-170)%35==0){
        int div=((t-170)%70==0) ? -1 : 1;
        angle=rang(PI);//�Ի���Boss���ɵĽǶ�
        for(s=0;s<2;s++){//�������ٶȲ�ͬ���ӵ�
            for(t=0;t<3;t++){//��һ���ط�һ��Ϊ��
                for(i=0;i<30;i++){//1��30��
                    if((k=search_boss_shot())!=-1){
                        boss_shot.bullet[k].col   = 2;//�ӵ�����ɫ
                        boss_shot.bullet[k].x     = boss.x;//����
                        boss_shot.bullet[k].y     = boss.y;
                        boss_shot.bullet[k].knd   = 11;//�ӵ�������
                        boss_shot.bullet[k].angle = angle+PI2/30*i;//�Ƕ�
                        boss_shot.bullet[k].flag  = 1;
                        boss_shot.bullet[k].cnt   = 0;
                        boss_shot.bullet[k].spd   = 2-0.3*s;//�ٶ�
                        boss_shot.bullet[k].eff   = 0;
                        boss_shot.bullet[k].state = 10+t;
                        boss_shot.bullet[k].base_angle[0] = PI/300*div;
                    }
                }
            }
            se_flag[0]=1;
        }
    }
    if(t==360){
        angle=rang(PI);//�Ի���Boss���ɵĽǶ�
        for(t=0;t<3;t++){//��һ���ط�һ��Ϊ��
            for(i=0;i<30;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = 1;//�ӵ�����ɫ
                    boss_shot.bullet[k].x     = boss.x;//����
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 0;//�ӵ�������
                    boss_shot.bullet[k].angle = angle+PI2/30*i;//�Ƕ�
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    boss_shot.bullet[k].spd   = 1.8;//�ٶ�
                    boss_shot.bullet[k].eff   = 1;
                    boss_shot.bullet[k].state = 20+t;
                }
            }
        }
        se_flag[0]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            int cnt=boss_shot.bullet[i].cnt;
            int state=boss_shot.bullet[i].state;
            if(state%10==0){
                if(cnt>90 && cnt<=100)
                    boss_shot.bullet[i].spd-=boss_shot.bullet[i].spd/220;
            }
            if(state%10==1){
                if(cnt>50)
                    boss_shot.bullet[i].spd+=boss_shot.bullet[i].spd/45;
            }
            if(state%10==2){
                if(cnt>65)
                    boss_shot.bullet[i].spd+=boss_shot.bullet[i].spd/90;
            }
            if(10<=state && state<=12){
                if(cnt>15 && cnt<=80)
                    boss_shot.bullet[i].angle+=boss_shot.bullet[i].base_angle[0];
            }
        }
    }
    for(i=0;i<LAZER_MAX;i++){
        if(lazer[i].flag>0){
            int cnt=lazer[i].cnt;
            int state=lazer[i].state;
            if(state==0 || state==1){
                if(cnt==80){
                    lazer[i].haba=30;
                    lazer[i].hantei=0.5;
                }
                if(cnt>=260 && cnt<=320){
                    if(cnt==280)
                        lazer[i].hantei=0;
                    lazer[i].haba=10*(60-(cnt-260))/60.0;
                    if(cnt==320)
                        lazer[i].flag=0;
                }
            }
        }
    }
    if(t==TM009-1)
        num=(++num);
}



//????
void boss_shot_bulletH0004ex_0(){
#define TM001 60
    int i,k,t=boss_shot.cnt%TM001,t2=boss_shot.cnt;
    static int cnum;
    double angle;
    if(t2==0)//�ʼ�ĳ�ʼ��
        cnum=0;
    if(t==0){//ÿ1�ε�Ļ�ʼ�ĳ�ʼ��
        boss_shot.base_angle[0]=bossatan2();//�Ի���Boss�ĽǶ�
        if(cnum%2==1){// 4�ε�Ļ�ƶ�һ��
            move_boss_pos(40,30,FMX-40,120,60, 60);
        }
    }
	if(t%2==0){
	boss_shot.base_angle[0]+=PI/TM001*t/10;
	if((k=search_boss_shot())!=-1){

                boss_shot.bullet[k].col   = 2;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 8;
                                //�ӻ����Ƕȿ�ʼ��ת20�β�����
                boss_shot.bullet[k].angle = boss_shot.base_angle[0];
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 2.7;//�ٶ�
                se_flag[0]=1;

	}
	if((k=search_boss_shot())!=-1){

                boss_shot.bullet[k].col   = 2;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 8;
                                //�ӻ����Ƕȿ�ʼ��ת20�β�����
                boss_shot.bullet[k].angle = boss_shot.base_angle[0]+PI;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 2.7;//�ٶ�
                se_flag[0]=1;

	}
	if((k=search_boss_shot())!=-1){

                boss_shot.bullet[k].col   = 2;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 8;
                                //�ӻ����Ƕȿ�ʼ��ת20�β�����
                boss_shot.bullet[k].angle = boss_shot.base_angle[0]+PI/2;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 2.7;//�ٶ�
                se_flag[0]=1;

	}
	if((k=search_boss_shot())!=-1){

                boss_shot.bullet[k].col   = 2;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 8;
                                //�ӻ����Ƕȿ�ʼ��ת20�β�����
                boss_shot.bullet[k].angle = boss_shot.base_angle[0]+PI/2*3;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 2.7;//�ٶ�
                se_flag[0]=1;

	}
	}
        //1�ε�Ļ���ʼ���Ի��ѣ�����һ��֮����Ի��Ѵ�
    //if(t==TM001/2-1)
      //  boss_shot.base_angle[0]+=PI2/20/2;
        //1�ε�Ļ����10��Բ���ӵ�
	//if(t%(TM001/10)==0){
      //  angle=bossatan2();//�Ի�-Boss֮��ĽǶ�
        //for(i=0;i<20;i++){//20��
          //  if((k=search_boss_shot())!=-1){
              //  boss_shot.bullet[k].col   = 2;
            //    boss_shot.bullet[k].x     = boss.x;
            //    boss_shot.bullet[k].y     = boss.y;
             //   boss_shot.bullet[k].knd   = 8;
             //                   //�ӻ����Ƕȿ�ʼ��ת20�β�����
             //  boss_shot.bullet[k].angle = boss_shot.base_angle[0]+PI2/20*i;
             //   boss_shot.bullet[k].flag  = 1;
             //   boss_shot.bullet[k].cnt   = 0;
             //   boss_shot.bullet[k].spd   = 2.7;//�ٶ�
             //   se_flag[0]=1;
          //  }
      //  }
   // }
		//4�μ�������һ�ε��ӵ��ĵ�¼
    if(t%4==0){
        if((k=search_boss_shot())!=-1){
            boss_shot.bullet[k].col   = 2;
            boss_shot.bullet[k].x     = GetRand(FMX);
            boss_shot.bullet[k].y     = GetRand(200);
            boss_shot.bullet[k].knd   = 4;
            boss_shot.bullet[k].angle = PI/2;//ֱ��
            boss_shot.bullet[k].flag  = 1;
            boss_shot.bullet[k].cnt   = 0;
            boss_shot.bullet[k].spd   = 1+rang(0.5);
            se_flag[0]=1;
        }
    }
    if(t==TM001-1)
        cnum++;
}

//��������
void boss_shot_bulletH0004ex_1(){
#define TM002 650
    int i,k,t=boss_shot.cnt%TM002;
    double angle;
    if(t==0 || t==210){
		//��40<x<FMX-40  50<y<150�ķ�Χ��80�μ������ƶ���100��λԶ�ĵط�
        move_boss_pos(40,50,FMX-40,150,100, 80);
    }
//�ʼ���������
    if(t<180){
        for(i=0;i<2;i++){//1�μ�������2��
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = GetRand(6);//�������7����ɫ
                boss_shot.bullet[k].x     = boss.x;//�����ʼ����ΪBoss������
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 7;//�ӵ�������
                boss_shot.bullet[k].angle = rang(PI2/20)+PI2/10*t;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3.2+rang(2.1);
                boss_shot.bullet[k].state = 0;//�ӵ���״̬
                boss_shot.bullet[k].kaiten= 1;//�����ӵ��Ƿ���ת��flag
            }
        }
        if(t%10==0)
            se_flag[0]=1;
    }
//�����Ի���λ����8��������
    if(210<t && t<270 && t%3==0){
        angle=bossatan2();
        for(i=0;i<8;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = 0;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 7;
				//���Ի���Boos���ɵļн�Ϊ��׼��8��������
                boss_shot.bullet[k].angle = angle-PI/2*0.8+PI*0.8/7*i+rang(PI/180);
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3.0+rang(0.3);
                boss_shot.bullet[k].state = 2;
                boss_shot.bullet[k].kaiten= 1;
            }
        }
        if(t%10==0)
            se_flag[0]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
			//t��190��ʱ�����е��ӵ���ֹͣ������Ȼ����ɫ�����ü�����
            if(boss_shot.bullet[i].state==0){
                if(t==190){
                    boss_shot.bullet[i].kaiten=0;//ֹͣ�ӵ�����ת
                    boss_shot.bullet[i].spd   =0;
                    boss_shot.bullet[i].col   =9;
                    boss_shot.bullet[i].cnt   =0;
                    boss_shot.bullet[i].state =1;//��״̬����Ϊ1
                }
            }
            //��ʼ����������ƶ�
            if(boss_shot.bullet[i].state==1){
                if(boss_shot.bullet[i].cnt==200){
                    boss_shot.bullet[i].angle=rang(PI);//ȫ�������
                    boss_shot.bullet[i].kaiten=1;//������תflagΪ��Ч
                }
                if(boss_shot.bullet[i].cnt>200)
                    boss_shot.bullet[i].spd+=0.01;//�𽥼���
            }
        }
    }
}

//��֮��·
void boss_shot_bulletH0004ex_2(){
#define TM003 600
#define DF003 20 
    int i,j,k,t=boss_shot.cnt%TM003,t2=boss_shot.cnt;
    static int tcnt,cnt,cnum;
    double angle;
    if(t2==0){
		//��40<x<FMX-40  50<y<150�ķ�Χ��80�μ������ƶ���100��λ���λ��
        input_phy_pos(FMX/2,FMY/2, 50);
        cnum=0;
    }
    if(t==0){
        boss_shot.base_angle[0]=bossatan2();
        cnt=0;
        tcnt=2;
    }
    if(t<540 && t%3){
        angle=bossatan2();
        if(tcnt-2==cnt || tcnt-1==cnt){
            if(tcnt-1==cnt){
                boss_shot.base_angle[1]=boss_shot.base_angle[0]+PI2/DF003*cnt*(cnum?-1:1)-PI2/(DF003*6)*3;
                tcnt+=DF003-2;
            }
        }
        else{
            for(i=0;i<6;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = cnum?1:4;
                    boss_shot.bullet[k].x     = boss.x;
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 8;
                    boss_shot.bullet[k].angle 
                     = boss_shot.base_angle[0]+PI2/DF003*cnt*(cnum?-1:1)+PI2/(DF003*6)*i*(cnum?-1:1);
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    boss_shot.bullet[k].spd   = 2;
                    se_flag[0]=1;
                }
            }
        }
        cnt++;
    }
    if(40<t&&t<540 && t%30==0){
        for(j=0;j<3;j++){
            angle=boss_shot.base_angle[1]-PI2/36*4;
            for(i=0;i<27;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col      = cnum?6:0;
                    boss_shot.bullet[k].x     = boss.x;
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 7;
                    boss_shot.bullet[k].angle = angle;
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt      = 0;
                    boss_shot.bullet[k].spd      = 4-1.6/3*j;
                    se_flag[0]=1;
                }
                angle-=PI2/36;
            }
        }
    }
//    for(i=0;i<BOSS_BULLET_MAX;i++){
//        if(boss_shot.bullet[i].flag>0){
//
//        }
//    }
    if(t==TM003-1)
        cnum++;
}