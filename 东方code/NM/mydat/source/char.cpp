#include "../include/GV.h"

void calc_ch(){
    if(ch.flag==1){//������ڽ��о�������
        bright_set.brt=80;//�䰵
        if(ch.cnt>20){//0.33���н��о�������
            ch.flag   =2;    //1�����ڽ��о������� 2�������������ϸ���
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }
    if(ch.cnt==0 && ch.flag==2){//�����ǰ˲�������Ļ�
		
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
    if(ch.flag==2){//����Ѿ����������ϸ��Ļ�
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//����ɫ�����ƶ�
        //1�����ϣ����߽�ɫ�Ѿ�����ĳ����λ���Ұ�����ĳ����
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//����ɫ��״̬��ԭ
        }
    }
    if(ch.mutekicnt>0){//����޵�״̬��Ϊ0�Ļ�
        ch.mutekicnt++;
        if(ch.mutekicnt>150)//����Ѿ�2.5�����ϵĻ�
            ch.mutekicnt=0;//��ԭ
    }
    ch.cnt++;//��ɫ����������
    ch.img=(ch.cnt%24)/6;//������ǰ��ͼ��
}

void ch_move(){//���ƽ�ɫ���ƶ�
    int i,sayu_flag=0,joge_flag=0;
    double x,y,mx,my,naname=1;
    double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};//{��,��,��,��}���ٶ�
    int inputpad[4];
    inputpad[0]=CheckStatePad(configpad.left); inputpad[1]=CheckStatePad(configpad.right);
    inputpad[2]=CheckStatePad(configpad.down); inputpad[3]=CheckStatePad(configpad.up);

    if(ch.flag==1)return;//������ڽ��о�������Ͳ����ƶ�

    if(CheckStatePad(configpad.left)>0)//������µ����
        ch.img+=4*2;//ͼ������
    else if(CheckStatePad(configpad.right)>0)//�Ҽ����µ����
        ch.img+=4*1;//ͼ������

    for(i=0;i<2;i++)//���Ҳ���
        if(inputpad[i]>0)//������ҷ�����������
            sayu_flag=1;//���������ƶ��ı�־
    for(i=2;i<4;i++)//���²���
        if(inputpad[i]>0)//������·���������
            joge_flag=1;//���������ƶ��ı�־
    if(sayu_flag==1 && joge_flag==1)//������ҡ����·���������˵��б���ƶ�
        naname=sqrt(2.0);//���ƶ��ٶȱ�Ϊ1/��2

    for(int i=0;i<4;i++){//4�������ѭ��
        if(inputpad[i]>0){//i����ļ��̻����ֱ�������
            x=ch.x , y=ch.y;//��ʱ���뵱ǰ������
            mx=move_x[i];    my=move_y[i];//���ƶ���������mx��my  
            if(CheckStatePad(configpad.slow)>0){//��������˶�
                mx=move_x[i]/3;    my=move_y[i]/3;//���ƶ��ٶȱ�Ϊ1/3
            }
            x+=mx/naname , y+=my/naname;//Ϊ��ǰ��������ƶ�����
            if(!(x<10 || x>FMX-10 || y<5 || y>FMY-5)){//����������ڿ��ƶ���Χ��
                ch.x=x , ch.y=y;//����ʵ�ʵ��ƶ�
            }
        }
    }
}

