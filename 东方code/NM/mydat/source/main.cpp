#define GLOBAL_INSTANCE 
#include "../include/GV.h"

extern void graph_theone();

//ѭ���б���ִ�е�������
int ProcessLoop(){
    if(ProcessMessage()!=0)return -1;//���̴�������������󷵻� -1
    if(ClearDrawScreen()!=0)return -1;//���������մ��󷵻�-1
    GetHitKeyStateAll_2();//���е�ǰ����
    GetHitPadStateAll();  //����ǰ���ֱ�����
    return 0;
}
                    //��ǰʵ�����       ֮ǰ�ľ��            �������          ��ʾ״̬
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    ChangeWindowMode(TRUE);//����ģʽ
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//��ʼ�����ﻭ�滯
	func_state=-3;
	//int cc;
    while(ProcessLoop()==0){//
		music_ini();
		//if(theone==-1)
		//{
		//	if(CheckStateKey(KEY_INPUT_0)==1)
		//	{
		//		theone=0;
		//	}
		//	graph_theone();
		//}
		//else
		
        switch(func_state){
			case -3:
				func_state=-1;
				load();
			case -1:
				StopSoundMem(area.bgm.handle);
				cc=0;
				//load(); 
				bgm_main();
				if(CheckStateKey(KEY_INPUT_0)==1)
				{
					func_state=0;
					theone=0;
					break;
				}
				if(CheckStateKey(KEY_INPUT_1)==1)
				{
					func_state=0;
					theone=1;
					break;
				}
				if(CheckStateKey(KEY_INPUT_2)==1)
				{
					func_state=0;
					theone=2;
					break;
				}
				if(CheckStateKey(KEY_INPUT_3)==1)
				{
					func_state=0;
					theone=3;
					break;
				}
				if(CheckStateKey(KEY_INPUT_4)==1)
				{
					func_state=0;
					theone=4;
					break;
				}
				if(CheckStateKey(KEY_INPUT_5)==1)
				{
					func_state=0;
					theone=5;
					break;
				}
				if(CheckStateKey(KEY_INPUT_6)==1)
				{
					func_state=0;
					theone=6;
					break;
				}
				if(CheckStateKey(KEY_INPUT_7)==1)
				{
					func_state=0;
					theone=7;
					break;
				}
				if(CheckStateKey(KEY_INPUT_8)==1)
				{
					func_state=0;
					theone=8;
					break;
				}
				if(CheckStateKey(KEY_INPUT_9)==1)
				{
					func_state=0;
					theone=9;
					break;
				}
				graph_theone();
				break;
            case 0://
                load();         //��������
                first_ini();//�ʼ�ĳ�ʼ��
                func_state=99;
                break;
            case 99://STG��ʼǰ���еĳ�ʼ�� 
                ini();
				load_story();
                func_state=100;
                break;
           case 100://ͨ������
			   //enter_func_tm("���");
			   
               calc_ch();       //enter_func_tm("��ɫ����");
               ch_move();       //enter_func_tm("��ɫ�ƶ�");
               cshot_main();    //enter_func_tm("�Ի����main");
               //enemy_main();    //enter_func_tm("���˴���main");
               if(theone!=-1)
				   boss_shot_main();//enter_func_tm("Boss���main");
               shot_main();     //enter_func_tm("���main");
               out_main();      //enter_func_tm("��ײ�ж�");
               effect_main();   //enter_func_tm("��Чmain");
               //calc_main();     //enter_func_tm("����main");
               graph_main();    //enter_func_tm("����main");

//graph_theone();
			   //StopSoundMem(area.bgm.handle);
               bgm_main();      //enter_func_tm("BGMmain");

               //if(boss.flag==0)
                   stage_count++;
               break;
           default:
               printfDx("�����func_state\n");
               break;
        }
		music_play();
        if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;//�������ESC����ѭ��
        ScreenFlip();//���⻭�淭ת
		count++;
    }

    DxLib_End();//DX library ��ֹ����
    return 0;
}
