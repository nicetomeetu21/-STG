#include "../include/GV.h"

void music_ini(){
	memset(se_flag,0,sizeof(int)*SE_MAX);
}

void music_play(){
	int i;
	for(i=0;i<SE_MAX;i++){
		if(se_flag[i]==1){
			if(CheckSoundMem(sound_se[i])!=0){
				if(i==8)continue;
				StopSoundMem(sound_se[i]);
			}
			PlaySoundMem(sound_se[i],DX_PLAYTYPE_BACK);
			//PlaySoundMem(b0,DX_PLAYTYPE_BACK);
		}
	}
}

void load_bgm(int flag){
        char str[64];
        sprintf(str,"../dat/music/%d_%d.mp3",stage,flag);
        area.bgm.handle=LoadSoundMem(str);
}
 
void delete_bgm(){
        DeleteSoundMem(area.bgm.handle);
}
 
void bgm_main(){
        if(area.bgm.flag==0 && theone!=0){//�ʼ����
                load_bgm(0);
                SetLoopPosSoundMem( area.bgm.loop_pos[0], area.bgm.handle );//����ѭ��λ��
                area.bgm.flag=1;
        }
        if(area.bgm.flag==1 && theone!=0){//�������࿪ʼ����
                switch(area.bgm.knd[0]){
                        case 0://����ǲ�������0�Ļ�
                                if(stage_count==60){//��ʼ60�μ�����ʼ����
                                        PlaySoundMem(area.bgm.handle,DX_PLAYTYPE_LOOP);
										
                                        //area.bgm.flag=2;
                                }
                                break;
                        default:
                                break;
                }
        }
        if(area.bgm.flag==0 && theone==0){//�ʼ����
                load_bgm(1);
                SetLoopPosSoundMem( area.bgm.loop_pos[1], area.bgm.handle );//����ѭ��λ��
                area.bgm.flag=1;
        }
        if(area.bgm.flag==1 && theone==0){//�������࿪ʼ����
                switch(area.bgm.knd[1]){
                        case 0:
                                if(stage_count==60){//��ʼ60�μ�����ʼ����
                                        PlaySoundMem(area.bgm.handle,DX_PLAYTYPE_LOOP);
										
                                        //area.bgm.flag=2;
                                }
                                break;
                        default:
                                break;
                }
        }
}
