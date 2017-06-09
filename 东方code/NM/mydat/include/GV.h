#include "../../../include/DxLib.h"
#include "define.h"
#include "math.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 
#endif

#include "function.h"

//
GLOBAL int img_ch[2][12];	//角色图片12张*2
GLOBAL int img_chetc[10];	//和角色相关的其它图像
GLOBAL int img_enemy[3][9];	//敌人的图像每种9张　X3种敌人
GLOBAL int img_board[40];	//保存面板图片
GLOBAL int img_bullet[20][10];//子弹的图像
GLOBAL int img_lazer[10][10],img_lazer_moto[10][10];//
GLOBAL int img_cshot[2];	//自机射击用的图像
GLOBAL int img_del_effect[5];//
GLOBAL int img_back[20];//背景用图片
GLOBAL int img_face[200]; //脸部用图片
GLOBAL int img_talk[200];//对话用图片

GLOBAL int img_eff_bom[5];	//Boom的特效图像
GLOBAL int img_dot_riria[8];//莉莉安的像素画
GLOBAL int img_etc[50];//其它图像

//音乐文件用的变量部分
GLOBAL int sound_se[SE_MAX];

GLOBAL int b0;

//僼儔僌丒僗僥乕僞僗曄悢
GLOBAL int func_state,stage_count,count,stage;	//表示状态的值，以此为依据进行条件分歧
GLOBAL int se_flag[SE_MAX];			//SE的flag

//结构体变量声明
GLOBAL ch_t ch;			//角色声明
GLOBAL enemy_t enemy[ENEMY_MAX];//
GLOBAL configpad_t configpad;//获得当前手柄的输入状态
GLOBAL enemy_order_t enemy_order[ENEMY_ORDER_MAX];//敌人的出现信息
GLOBAL shot_t shot[SHOT_MAX];//射击信息
GLOBAL boss_shot_t boss_shot;// Boss射击的信息
GLOBAL cshot_t cshot[CSHOT_MAX];//自机射击用的变量
GLOBAL del_effect_t del_effect[DEL_EFFECT_MAX];//消灭特效
GLOBAL effect_t effect[EFFECT_MAX];//特效
GLOBAL bullet_info_t bullet_info[20];//子弹的信息
GLOBAL bom_t bom;				//Boom
GLOBAL bright_set_t bright_set; //绘制的亮度
GLOBAL dn_t dn;					//咚地摇动
GLOBAL boss_t boss;				//Boss的信息
GLOBAL lazer_t lazer[LAZER_MAX];//

GLOBAL area_t area;//区域所持有的数据 (48)

GLOBAL int theone;
GLOBAL int theone_load;

GLOBAL int cc;