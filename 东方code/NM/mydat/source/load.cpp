#include "../include/GV.h"

void load(){//在load.cpp中读入面板的图像数据。编号数字不连续方便更换图片
	int t;
	SetCreateSoundDataType( DX_SOUNDDATATYPE_MEMPRESS ) ;

	t=GetNowCount();
	img_board[10] = LoadGraph("../dat/img/board/10.png");
	img_board[11] = LoadGraph("../dat/img/board/11.png");
	img_board[12] = LoadGraph("../dat/img/board/12.png");
	img_board[20] = LoadGraph("../dat/img/board/20.png");

	img_chetc[0]	= LoadGraph( "../dat/img/char/atari.png" );//碰撞判定
	img_chetc[2]	= LoadGraph( "../dat/img/char/ball.png" );//球

	img_eff_bom[0] = LoadGraph( "../dat/img/effect/bom0.png" );
	img_eff_bom[1] = LoadGraph( "../dat/img/effect/bom1.png" );
	img_eff_bom[2] = LoadGraph( "../dat/img/char/body.png" );
	img_eff_bom[3] = LoadGraph( "../dat/img/bullet/bom_title0.png" );

	img_etc[1]	= LoadGraph( "../dat/img/enemy/hp.png" );
	img_etc[2]	= LoadGraph( "../dat/img/enemy/bossback.png" );
	img_etc[5]	= LoadGraph( "../dat/img/enemy/bossback3.png" );
	img_etc[6]	= LoadGraph( "../dat/img/enemy/bossback4.png" );
	img_etc[7]	= LoadGraph( "../dat/img/enemy/hp_boss.png" );//Boos 的HP
	


	theone_load	= LoadGraph( "../dat/img/board/bak.jpg" );
//读入子弹的图像文件
	LoadDivGraph( "../dat/img/bullet/b0.png" , 5 , 5 , 1 , 76 , 76 , img_bullet[0] ) ;
	LoadDivGraph( "../dat/img/bullet/b1.png" , 6 , 6 , 1 , 22 , 22 , img_bullet[1] ) ;
	LoadDivGraph( "../dat/img/bullet/b2.png" , 10 , 10 , 1 , 5 , 120 , img_bullet[2] ) ;
	LoadDivGraph( "../dat/img/bullet/b3.png" , 5 , 5 , 1 , 19 , 34 , img_bullet[3] ) ;
	LoadDivGraph( "../dat/img/bullet/b4.png" , 10 , 10 , 1 , 38 , 38 , img_bullet[4]  ) ;
	LoadDivGraph( "../dat/img/bullet/b5.png" , 3 , 3 , 1 , 14 , 16 , img_bullet[5] ) ;
	LoadDivGraph( "../dat/img/bullet/b6.png" , 3 , 3 , 1 , 14 , 18 , img_bullet[6] ) ;
	LoadDivGraph( "../dat/img/bullet/b7.png" , 10 , 10 , 1 , 16 , 16 , img_bullet[7] ) ;
	LoadDivGraph( "../dat/img/bullet/b8.png" , 10 , 10 , 1 , 12 , 18 ,img_bullet[8] ) ;
	LoadDivGraph( "../dat/img/bullet/b9.png" , 3 , 3 , 1 , 13 , 19 , img_bullet[9] ) ;
	LoadDivGraph( "../dat/img/bullet/b10.png" , 8 , 8 , 1 , 8 , 8 , img_bullet[10] ) ;
	LoadDivGraph( "../dat/img/bullet/b11.png" , 8 , 8 , 1 , 35 , 32 , img_bullet[11] ) ;

	LoadDivGraph( "../dat/img/bullet/l0.png" , 2 , 2 , 1 , 30 , 460 , img_lazer[0] ) ;
	LoadDivGraph( "../dat/img/bullet/l0_moto.png" , 2 , 2 , 1 , 70 , 70 , img_lazer_moto[0] ) ;

	LoadDivGraph( "../dat/img/enemy/hit_effect.png" , 5 , 5 , 1 , 140 , 140 , img_del_effect ); //特效信息;
	LoadDivGraph( "../dat/img/char/riria.png" , 8 , 8 , 1 , 100 , 100 , img_dot_riria ) ;
	LoadDivGraph( "../dat/img/char/0.png" , 12 , 4 , 3 , 73 , 73 , img_ch[0] ) ;//角色图片信息
	LoadDivGraph( "../dat/img/enemy/0.png" , 9 , 3 , 3 , 32 , 32 , img_enemy[0] ) ;//敌人图片信息

	img_cshot[0]=LoadGraph("../dat/img/char/bl_00.png");
	img_cshot[1]=LoadGraph("../dat/img/char/bl_01.png");
	//读入背景
	img_back[0] = LoadGraph("../dat/img/back/0/back0.png");
	
	img_back[10] = LoadGraph("../dat/img/back/10/kotei0.png");
	img_back[11] = LoadGraph("../dat/img/back/10/scroll0.png");
	//读入对话
	img_talk[11] = LoadGraph("../dat/img/talk/talk_1_1.png");
	img_talk[12] = LoadGraph("../dat/img/talk/talk_1_2.png");
	img_talk[13] = LoadGraph("../dat/img/talk/talk_1_3.png");
	img_talk[21] = LoadGraph("../dat/img/talk/talk_2_1.png");
	img_talk[22] = LoadGraph("../dat/img/talk/talk_2_2.png");
	img_talk[31] = LoadGraph("../dat/img/talk/talk_3_1.png");
	img_talk[32] = LoadGraph("../dat/img/talk/talk_3_2.png");
	img_talk[33] = LoadGraph("../dat/img/talk/talk_3_3.png");
	img_talk[41] = LoadGraph("../dat/img/talk/talk_4_1.png");
	img_talk[42] = LoadGraph("../dat/img/talk/talk_4_2.png");
	img_talk[43] = LoadGraph("../dat/img/talk/talk_4_3.png");
	img_talk[44] = LoadGraph("../dat/img/talk/talk_4_4.png");
	img_talk[51] = LoadGraph("../dat/img/talk/talk_5_1.png");
	img_talk[52] = LoadGraph("../dat/img/talk/talk_5_2.png");
	img_talk[53] = LoadGraph("../dat/img/talk/talk_5_3.png");
	img_talk[61] = LoadGraph("../dat/img/talk/talk_6_1.png");
	img_talk[62] = LoadGraph("../dat/img/talk/talk_6_2.png");
	img_talk[63] = LoadGraph("../dat/img/talk/talk_6_3.png");
	img_talk[71] = LoadGraph("../dat/img/talk/talk_7_1.png");
	img_talk[72] = LoadGraph("../dat/img/talk/talk_7_2.png");
	img_talk[73] = LoadGraph("../dat/img/talk/talk_7_3.png");
	img_talk[74] = LoadGraph("../dat/img/talk/talk_7_4.png");
	img_talk[81] = LoadGraph("../dat/img/talk/talk_8_1.png");
	img_talk[82] = LoadGraph("../dat/img/talk/talk_8_2.png");
	img_talk[83] = LoadGraph("../dat/img/talk/talk_8_3.png");
	img_talk[91] = LoadGraph("../dat/img/talk/talk_9_1.png");
	img_talk[92] = LoadGraph("../dat/img/talk/talk_9_2.png");
	img_talk[1] = LoadGraph("../dat/img/talk/talk_10_1.png");
	img_talk[2] = LoadGraph("../dat/img/talk/talk_10_2.png");
	img_face[1] = LoadGraph("../dat/img/talk/face_2.png");
	img_face[2] = LoadGraph("../dat/img/talk/face_3.png");
	img_face[3] = LoadGraph("../dat/img/talk/face_4.png");
	img_face[4] = LoadGraph("../dat/img/talk/face_5.png");
	img_face[5] = LoadGraph("../dat/img/talk/face_6.png");
	img_face[6] = LoadGraph("../dat/img/talk/face_7.png");
	img_face[7] = LoadGraph("../dat/img/talk/face_8.png");
	img_face[8] = LoadGraph("../dat/img/talk/face_9.png");
	img_face[9] = LoadGraph("../dat/img/talk/boss1.png");
	img_face[10] = LoadGraph("../dat/img/talk/boss2.png");

	sound_se[0]=LoadSoundMem("../dat/se/enemy_shot.wav");//读入敌人的射击音效
	sound_se[1]=LoadSoundMem("../dat/se/enemy_death.wav");//显然敌人死了
	sound_se[2]=LoadSoundMem("../dat/se/cshot.wav");//主角射击
	sound_se[3]=LoadSoundMem("../dat/se/char_death.wav");//自机被击毁的声音
	sound_se[8]=LoadSoundMem("../dat/se/hit.wav");
	sound_se[11]=LoadSoundMem("../dat/se/boss_change.wav");
	sound_se[14]=LoadSoundMem("../dat/se/bom0.wav");
	sound_se[15]=LoadSoundMem("../dat/se/bom1.wav");
	sound_se[33]=LoadSoundMem("../dat/se/lazer.wav");
	sound_se[34]=LoadSoundMem("../dat/se/item_get.wav");
	b0=LoadSoundMem("../dat/music/b0.mp3");
	//sound_se[99]=LoadSoundMem("../dat/music/youmu.wav");

	ChangeVolumeSoundMem( 64, sound_se[0] ) ;//设定各素材的重播音量
	ChangeVolumeSoundMem( 64, sound_se[1] ) ;
	ChangeVolumeSoundMem( 64, sound_se[2] ) ;
	ChangeVolumeSoundMem( 64, sound_se[3] ) ;
	ChangeVolumeSoundMem( 64, sound_se[8] ) ;
	ChangeVolumeSoundMem( 128, sound_se[9] ) ;
	ChangeVolumeSoundMem( 128, sound_se[11] ) ;
	ChangeVolumeSoundMem( 128, sound_se[14] ) ;
	ChangeVolumeSoundMem( 128, sound_se[15] ) ;
	ChangeVolumeSoundMem( 128, sound_se[33] ) ;
	ChangeVolumeSoundMem( 64, sound_se[34] ) ;
}

//将敌人出现的信息从Excel读入并保存的函数
void load_story(){
	int n,num,i,fp;
	char fname[32]={"../dat/csv/storyH0.csv"};
	int input[64];
	char inputc[64];

	fp = FileRead_open(fname);//读入文件
	if(fp == NULL){
		printfDx("read error\n");
		return;
	}
	for(i=0;i<2;i++)//丢掉最开始的两行
		while(FileRead_getc(fp)!='\n');

	n=0 , num=0;
	while(1){
		for(i=0;i<64;i++){
			inputc[i]=input[i]=FileRead_getc(fp);//读入1个字符 
			if(inputc[i]=='/'){//如果是斜杠
				while(FileRead_getc(fp)!='\n');//循环一直到换行
				i=-1;//重置计数器
				continue;
			}
			if(input[i]==',' || input[i]=='\n'){//如果是逗号或者换行
				inputc[i]='\0';//将到此的所有文字作为字符串
				break;
			}
			if(input[i]==EOF){//如果到了文件尾
				goto EXFILE;//终止
			}
		}
		switch(num){
			case 0:	enemy_order[n].cnt		=atoi(inputc);break;
			case 1:	enemy_order[n].pattern	=atoi(inputc);break;
			case 2:	enemy_order[n].knd		=atoi(inputc);break;
			case 3:	enemy_order[n].x		=atof(inputc);break;
			case 4:	enemy_order[n].y		=atof(inputc);break;
			case 5:	enemy_order[n].sp		=atof(inputc);break;
			case 6:	enemy_order[n].bltime	=atoi(inputc);break;
			case 7:	enemy_order[n].blknd	=atoi(inputc);break;
			case 8:	enemy_order[n].col		=atoi(inputc);break;
			case 9:	enemy_order[n].hp		=atoi(inputc);break;
			case 10:enemy_order[n].blknd2	=atoi(inputc);break;
			case 11:enemy_order[n].wait		=atoi(inputc);break;
			case 12:enemy_order[n].item_n[0]=atoi(inputc);break;
			case 13:enemy_order[n].item_n[1]=atoi(inputc);break;
			case 14:enemy_order[n].item_n[2]=atoi(inputc);break;
			case 15:enemy_order[n].item_n[3]=atoi(inputc);break;
			case 16:enemy_order[n].item_n[4]=atoi(inputc);break;
			case 17:enemy_order[n].item_n[5]=atoi(inputc);break;
		}
		num++;
		if(num==18){
			num=0;
			n++;
		}
	}
EXFILE:
	FileRead_close(fp);
}
