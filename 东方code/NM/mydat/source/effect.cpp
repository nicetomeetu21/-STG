#include "../include/GV.h"

//������¼Ϊ�յ���Ч���
int search_effect(){
    for(int i=0;i<EFFECT_MAX;i++){
        if(effect[i].flag==0)
            return i;
    }
    return -1;
}

//������Ч
void calc_effect(){
    for(int i=0;i<EFFECT_MAX;i++){
        if(effect[i].flag>0){//�����Ч�Ѿ�����¼��
            effect[i].x+=cos(effect[i].mvang)*effect[i].spd;//�������
            effect[i].y+=sin(effect[i].mvang)*effect[i].spd;
            switch(effect[i].knd){//������Ч��������з���	
                case 0://���˵�������Ч
                    effect[i].cnt++;
                    effect[i].r+=0.08;//��Ч�Ĵ�С�𽥱��
                    if(effect[i].cnt>10)//�������������10
                        effect[i].brt-=25;//�����ȱ䰵
                    if(effect[i].cnt>20)//�������������20
                        effect[i].flag=0;//����
                    break;
                case 1:// Boom����Ч
                    //�ٶȼ���
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
                    //���Ⱥʹ�С�ļ���
                    effect[i].r+=0.015;
                    if(effect[i].cnt<51)
                        effect[i].brt+=5;
                    if(effect[i].cnt>=60){
                        effect[i].r+=0.04;
                        effect[i].brt-=255/30.0;
                    }
                    //�����������Լ���ȥ����
                    effect[i].cnt++;
                    if(effect[i].cnt>=90)
                        effect[i].flag=0;
                    break;
                case 2:// Boom��Ч����ɫ��
                    //���ȼ���
                    if(effect[i].cnt<51)
                        effect[i].brt+=4;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=4;
                    //��������������ȥ����
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;
                case 3://Boom����Ч���ߣ�
                    //���ȼ���
                    if(effect[i].cnt<51)
                        effect[i].brt+=2;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=2;
                    //��������������ȥ����
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;                
                case 4://������Ч
                    //���ȼ���
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

//������¼Ϊ�յ�������Ч�ı��
int search_del_effect(){
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag==0)
            return i;
    }
    return -1;
}

//��¼������Ч
void enter_del_effect(int s){
    int k=search_del_effect();
    if(k!=-1){
        del_effect[k].flag=1;//����flagΪ��Ч
        del_effect[k].cnt=0;
        del_effect[k].col=enemy[s].back_col;//�����˵ı���ɫ�趨Ϊ����ɫ
        del_effect[k].x=enemy[s].x;//�����˵���������Ϊ����λ��
        del_effect[k].y=enemy[s].y;
    }
}

//����������Ч����¼��Ч
void calc_del_effect(){
    int k;
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag>0){
            if(del_effect[i].cnt%2==0){//ÿ1/30���趨һ��
                if((k=search_effect())!=-1){//�����ձ��
                    memset(&effect[k],0,sizeof(effect_t));//��ʼ��
                    effect[k].flag=1;//����flagΪ��Ч
                    effect[k].brt=255;//��������Ϊ���ֵ
                    effect[k].ang=rang(PI);//����Ƕ�
                    effect[k].col=del_effect[i].col;//������ɫ
                    effect[k].eff=1;// 1��������Ч��������ЧΪ1.
                    effect[k].img=img_del_effect[effect[k].col];//��������ͼ��
                    effect[k].knd=0;//��Ч��������0�ţ�������ЧΪ0��
                    effect[k].x=del_effect[i].x;//��������
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

//��¼Boom
void enter_bom(){
    int k;
    bom.flag=1;
    bom.cnt=0;
    bom.knd=0;
    ch.flag=0;
    ch.mutekicnt=1;//����Ϊ�޵�
    se_flag[14]=1;//����ȷ����
    //����
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;// Boom���ߵ���Ч
        effect[k].brt=0;//��ֵ
        effect[k].ang=PI/2;//ͼ��ķ���
        effect[k].mvang=-PI/2;//��Чǰ���ķ���
        effect[k].spd=1;//�ٶ�
        effect[k].r=1;//��С
        effect[k].eff=2;//�����
        effect[k].img=img_eff_bom[3];
        effect[k].x=70;//����
        effect[k].y=300;
    }
    //����
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;// Boom���ߵ���Ч
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
   //��ɫ
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=2;//Boom�Ľ�ɫ���ߵ���Ч
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
//�˰��ҡ������Ĵ���
void dn_calc(){
    if(dn.flag==1){
        dn.x=(int)rang(dn.size);
        dn.y=(int)rang(dn.size);
        dn.cnt++;
        if(dn.cnt>dn.time){//���������Ԥ���ʱ��Ļ��ͽ���
            dn.flag=0;
            dn.x=0;
            dn.y=0;
        }
    }
}

//Boom����
void bom_calc(){
    int n,k;
	double shot_angle[4]={0,PI,PI/2,PI*1.5};//4����Ч���еĽǶ�
    if((ch.flag==0||ch.flag==1) && bom.flag==0){//��ɫ�����ͨ��״̬��û�з�Boom
        if(CheckStatePad(configpad.bom)==1){//���Boom��������
            if(ch.limit<=0){
			printf("NO MORE BOOM");
			}
			else{
            enter_bom();
			ch.limit--;
			}
        }
    }
    if(bom.flag==1){//���Boom�Ѿ�����¼
        if(bom.cnt%10==0){//1/6��һ��
            n=(bom.cnt/10);
            if(n<4 && (k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=1;//��Ч���1��Boom����Ч
                effect[k].brt=0;
                effect[k].ang=rang(PI);//�����ͼ����
                effect[k].mvang=shot_angle[n]-PI/4;//���з���
                effect[k].spd=13+rang(2);//�ٶ�
                effect[k].r=0.5;//��С
                effect[k].eff=2;//�����
                effect[k].img=img_eff_bom[(bom.cnt/10)/3];//ͼ��
                effect[k].x=ch.x;//����
                effect[k].y=ch.y;
            }
        }
        bom.cnt++;
        if(bom.cnt<40)
            bright_set.brt=255-bom.cnt*5;//�趨��������ȣ�����
        if(bom.cnt>90)
            bright_set.brt=255-40*5+(bom.cnt-90)*5;//�趨����ĵ����ȣ�����
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
                effect[k].knd=4;//������Ч
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
    dn_calc();//�˰��ҡ�λ���Ĵ���
    calc_del_effect();//������Ч�ļ���
    calc_effect();//��Ч�ļ���
    bom_calc();//Boom����
    enter_crybom_effect();
}