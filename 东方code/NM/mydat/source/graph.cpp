#include "../include/GV.h"

extern void graph_back_main();
extern void graph_talk_main();

int DrawGraphFd( int xd, int yd, int GrHandle, int TransFlag) {
	return DrawGraph(xd+FX+dn.x,yd+FY+dn.y,GrHandle,TransFlag);
}

void graph_effect(int knd){
	for(int i=0;i<EFFECT_MAX;i++){
		if(effect[i].flag>0 && effect[i].knd==knd){
			if(effect[i].eff==1)//�����Ч�ǹ���Ч
				SetDrawBlendMode( DX_BLENDMODE_ADD, effect[i].brt) ;
			if(effect[i].eff==2)//��Ч�Ǧ���Ч�������
				SetDrawBlendMode( DX_BLENDMODE_ALPHA, effect[i].brt) ;
			DrawRotaGraphF(effect[i].x+FX+dn.x,effect[i].y+FY+dn.y,effect[i].r,effect[i].ang,effect[i].img,TRUE);
			if(effect[i].eff==1 || effect[i].eff==2)
				SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
		}
	}
}

//ͼ������
void graph_enemy(){
	int i;
	for(i=0;i<ENEMY_MAX;i++){
		if(enemy[i].flag==1){
			DrawRotaGraphF(enemy[i].x+FX+dn.x,enemy[i].y+FY+dn.y,1.0f,0.0f,img_enemy[0][enemy[i].img],TRUE);
		}
	}
}

void graph_boss_effect(){
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, 150) ;
	DrawRotaGraphF(boss.dx+FX,   boss.dy+FY,
				   (0.4+0.05*sin(PI2/360*(count%360)))*3,
				   2*PI*(count%580)/580,
				   img_etc[5], TRUE);
	DrawRotaGraphF(boss.dx+FX,   boss.dy+FY,
				   (0.5+0.1*sin(PI2/360*(count%360)))*2,
				   2*PI*(count%340)/340,img_etc[2],	TRUE);
	DrawRotaGraphF(boss.dx+60*sin(PI2/153*(count%153))+FX,
				   boss.dy+80*sin(PI2/120*(count%120))+FY,
				   0.4+0.05*sin(PI2/120*(count%120)),
				   2*PI*(count%30)/30,img_etc[6],	TRUE);
	DrawRotaGraphF(boss.dx+60*sin(PI2/200*((count+20)%200))+FX,
				   boss.dy+80*sin(PI2/177*((count+20)%177))+FY,
				   0.3+0.05*sin(PI2/120*(count%120)), 
				   2*PI*(count%35)/35,img_etc[6],	TRUE);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
	DrawRotaGraphF(boss.dx+60*sin(PI2/230*((count+40)%230))+FX,
				   boss.dy+80*sin(PI2/189*((count+40)%189))+FY,
				   0.6+0.05*sin(PI2/120*(count%120)),
				   2*PI*(count%40)/40,img_etc[6],	TRUE);
}
//����Boss
void graph_boss(){
	int i;
	if(boss.flag==0)return;
	graph_boss_effect();
	DrawRotaGraphF(boss.dx+FX+dn.x,boss.dy+FY+dn.y,
		1.0f,0.0f,img_dot_riria[boss.knd],TRUE);
	if(boss.hp_max==0){printfDx("graph_boss�ﵽ����\n");return;}
	for(i=0;i<FMX*0.98*boss.hp/boss.hp_max;i++){
		if(boss.back_knd[boss.knd]==1)
			DrawGraph(3+FX+i+dn.x,2+FY+dn.y,img_etc[7],FALSE);
		else
			DrawGraph(3+FX+i+dn.x,2+FY+dn.y,img_etc[1],FALSE);
	}
}

//�Ի�����
void graph_ch(){
	double sx,sy,ny=(sin(2.0*PI*(count%50)/50)*3),ang=2.0*PI*(count%120)/120;

	if(CheckStatePad(configpad.slow)>0)//��������ƶ���
		sx=15,sy=15+ny;//����
	else
		sx=30,sy=30+ny;//����ͨ��λ���ƶ�

	DrawRotaGraphF( ch.x-sx+FX, ch.y+sy+FY, 1.0f,  ang, img_chetc[2], TRUE );
	DrawRotaGraphF( ch.x+sx+FX, ch.y+sy+FY, 1.0f, -ang, img_chetc[2], TRUE );

	if(ch.mutekicnt%2==0){//�޵��еĻ�����
		//�Ի���ʾ
		DrawRotaGraphF(ch.x+FX+dn.x,ch.y+FY+dn.y,1.0f,0.0f,img_ch[0][ch.img],TRUE);
		if(CheckStatePad(configpad.slow)>0)//��������ƶ��еĻ���ʾ����ײ�ж�
			DrawRotaGraphF( ch.x+FX, ch.y+FY, 1.0f, 2.0*PI*(count%120)/120, img_chetc[0], TRUE );
	}
}


void graph_cshot(){
	for(int i=0;i<CSHOT_MAX;i++){
		if(cshot[i].flag>0){
			DrawRotaGraphF(cshot[i].x+FX+dn.x,cshot[i].y+FY+dn.y,1,0,img_cshot[cshot[i].knd],TRUE);
		}
	}
}

void myDrawSquare(double x0, double y0,double x1, double y1,double x2, double y2,double x3, double y3){
	DrawTriangle(x0,y0,x1,y1,x2,y2,GetColor(255,0,0),TRUE);
	DrawTriangle(x0,y0,x3,y3,x2,y2,GetColor(255,0,0),TRUE);
}

void graph_lazer(){
	int i,j,eff;
	double disp_angle;
	SetDrawMode( DX_DRAWMODE_BILINEAR ) ;
	for(i=0;i<LAZER_MAX;i++){
		if(lazer[i].flag>0){
			SetDrawBlendMode( DX_BLENDMODE_ADD, 255) ;
			DrawRotaGraphF(
				lazer[i].startpt.x+FX,lazer[i].startpt.y+FY,1.0,0,
				img_lazer_moto[lazer[i].knd][lazer[i].col],TRUE
			);
			DrawModiGraph(
				lazer[i].disppt[0].x+FX, lazer[i].disppt[0].y+FY, 
				lazer[i].disppt[1].x+FX, lazer[i].disppt[1].y+FY, 
				lazer[i].disppt[2].x+FX, lazer[i].disppt[2].y+FY, 
				lazer[i].disppt[3].x+FX, lazer[i].disppt[3].y+FY, 
				img_lazer[lazer[i].knd][lazer[i].col],TRUE
			);
			//SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
			//myDrawSquare(
			//	lazer[i].outpt[0].x+FX,lazer[i].outpt[0].y+FY,
			//	lazer[i].outpt[1].x+FX,lazer[i].outpt[1].y+FY,
			//	lazer[i].outpt[2].x+FX,lazer[i].outpt[2].y+FY,
			//	lazer[i].outpt[3].x+FX,lazer[i].outpt[3].y+FY
			//);
		}
	}
}

//�����ӵ�
void graph_bullet(){
	int i,j,eff;
	double disp_angle;
	SetDrawMode( DX_DRAWMODE_BILINEAR ) ;//���Բ�ֵ����
	for(i=0;i<SHOT_MAX;i++){//���˵ĵ�Ļ������ѭ��
		if(shot[i].flag>0){//������˵ĵ�Ļ����Ϊ��Ч
			for(j=0;j<SHOT_BULLET_MAX;j++){//��Ļ��ӵ�е��ӵ������������ѭ��
				if(shot[i].bullet[j].flag!=0){//����ӵ�������Ϊ��Ч
					if(shot[i].bullet[j].eff==1)
						SetDrawBlendMode( DX_BLENDMODE_ADD, 255) ;
					if(bullet_info[shot[i].bullet[j].knd].kaiten==1)
						disp_angle=PI2*(shot[i].bullet[j].cnt%120)/120;
					else
						disp_angle=shot[i].bullet[j].angle+PI/2;

					DrawRotaGraphF(
						shot[i].bullet[j].x+FX+dn.x, shot[i].bullet[j].y+FY+dn.y,
						1.0, disp_angle,
						img_bullet[shot[i].bullet[j].knd][shot[i].bullet[j].col],TRUE);

					if(shot[i].bullet[j].eff==1)
						SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
				}
			}
		}
	}
	//Boss
	if(boss_shot.flag>0){//��Ļ������Ч�Ļ�
		for(j=0;j<BOSS_BULLET_MAX;j++){//��Ļ���е��ӵ����������ѭ��
			if(boss_shot.bullet[j].flag!=0){//�ӵ�������Ч�Ļ�
				eff=0;
				if(boss_shot.bullet[j].kaiten==1)
					disp_angle=PI2*(boss_shot.bullet[j].cnt%120)/120;
				else
					disp_angle=boss_shot.bullet[j].angle+PI/2;
				if(boss_shot.bullet[j].eff_detail==1){
					SetDrawBlendMode( DX_BLENDMODE_ADD, 100+GetRand(155)),eff=1 ;
					DrawRotaGraphF(
						boss_shot.bullet[j].x+FX+dn.x, boss_shot.bullet[j].y+FY+dn.y,
						1.3, disp_angle,
						img_bullet[boss_shot.bullet[j].knd][boss_shot.bullet[j].col],TRUE);
				}
				if(boss_shot.bullet[j].eff==1)
					SetDrawBlendMode( DX_BLENDMODE_ADD, 255),eff=1 ;
				if(boss_shot.bullet[j].eff==2)
					SetDrawBlendMode( DX_BLENDMODE_ADD, 255+GetRand(100)),eff=1 ;
				DrawRotaGraphF(
					boss_shot.bullet[j].x+FX+dn.x, boss_shot.bullet[j].y+FY+dn.y,
					1.0, disp_angle,
					img_bullet[boss_shot.bullet[j].knd][boss_shot.bullet[j].col],TRUE);

				if(eff==1)
					SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
			}
		}
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);//��ԭ����״̬
}


void graph_board(){
	DrawGraph(	0,	0,img_board[10],FALSE);
	DrawGraph(	0, 16,img_board[11],FALSE);
	DrawGraph(	0,464,img_board[12],FALSE);
	DrawGraph(416,	0,img_board[20],FALSE);
}

void graph_develop(){
	DrawFormatString(0,0,GetColor(255,255,255),"%d",stage_count);
}

void graph_main(){

	if(bright_set.brt!=255)SetDrawBright(bright_set.brt,bright_set.brt,bright_set.brt);

	graph_back_main();//�������main
	graph_talk_main();
	graph_effect(0);//���˻�����Ч

	if(bright_set.brt!=255)SetDrawBright(255,255,255);

	graph_effect(4);//������Ч

	if(bright_set.brt!=255)SetDrawBright(bright_set.brt,bright_set.brt,bright_set.brt);

	graph_boss();
	graph_enemy();//���˵����
	graph_cshot();//�Ի���������

	if(bright_set.brt!=255)SetDrawBright(255,255,255);

	graph_ch();//�Ի������

	if(bright_set.brt!=255)SetDrawBright(bright_set.brt,bright_set.brt,bright_set.brt);
	
	graph_lazer();
	graph_bullet();

	if(bright_set.brt!=255)SetDrawBright(255,255,255);

	graph_effect(1);//Boom����Ч
	graph_effect(2);//Boom�ߵ���Ч
	graph_effect(3);//Boom��ɫ����Ч
	graph_board();//������

	graph_develop();
}