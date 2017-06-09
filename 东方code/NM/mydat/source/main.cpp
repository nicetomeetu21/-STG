#define GLOBAL_INSTANCE 
#include "../include/GV.h"

extern void graph_theone();

//循环中必须执行的三大处理
int ProcessLoop(){
    if(ProcessMessage()!=0)return -1;//过程处理如果发生错误返回 -1
    if(ClearDrawScreen()!=0)return -1;//如果画面清空错误返回-1
    GetHitKeyStateAll_2();//进行当前处理
    GetHitPadStateAll();  //处理当前的手柄输入
    return 0;
}
                    //当前实例句柄       之前的句柄            命令参数          显示状态
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    ChangeWindowMode(TRUE);//窗口模式
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初始化和里画面化
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
                load();         //载入数据
                first_ini();//最开始的初始化
                func_state=99;
                break;
            case 99://STG开始前进行的初始化 
                ini();
				load_story();
                func_state=100;
                break;
           case 100://通常处理
			   //enter_func_tm("最初");
			   
               calc_ch();       //enter_func_tm("角色计算");
               ch_move();       //enter_func_tm("角色移动");
               cshot_main();    //enter_func_tm("自机射击main");
               //enemy_main();    //enter_func_tm("敌人处理main");
               if(theone!=-1)
				   boss_shot_main();//enter_func_tm("Boss射击main");
               shot_main();     //enter_func_tm("射击main");
               out_main();      //enter_func_tm("碰撞判定");
               effect_main();   //enter_func_tm("特效main");
               //calc_main();     //enter_func_tm("计算main");
               graph_main();    //enter_func_tm("绘制main");

//graph_theone();
			   //StopSoundMem(area.bgm.handle);
               bgm_main();      //enter_func_tm("BGMmain");

               //if(boss.flag==0)
                   stage_count++;
               break;
           default:
               printfDx("错误的func_state\n");
               break;
        }
		music_play();
        if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;//如果按下ESC跳出循环
        ScreenFlip();//里外画面翻转
		count++;
    }

    DxLib_End();//DX library 终止处理
    return 0;
}
