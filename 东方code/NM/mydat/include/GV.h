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
GLOBAL int img_ch[2][12];	//��ɫͼƬ12��*2
GLOBAL int img_chetc[10];	//�ͽ�ɫ��ص�����ͼ��
GLOBAL int img_enemy[3][9];	//���˵�ͼ��ÿ��9�š�X3�ֵ���
GLOBAL int img_board[40];	//�������ͼƬ
GLOBAL int img_bullet[20][10];//�ӵ���ͼ��
GLOBAL int img_lazer[10][10],img_lazer_moto[10][10];//
GLOBAL int img_cshot[2];	//�Ի�����õ�ͼ��
GLOBAL int img_del_effect[5];//
GLOBAL int img_back[20];//������ͼƬ
GLOBAL int img_face[200]; //������ͼƬ
GLOBAL int img_talk[200];//�Ի���ͼƬ

GLOBAL int img_eff_bom[5];	//Boom����Чͼ��
GLOBAL int img_dot_riria[8];//���򰲵����ػ�
GLOBAL int img_etc[50];//����ͼ��

//�����ļ��õı�������
GLOBAL int sound_se[SE_MAX];

GLOBAL int b0;

//�t���O�E�X�e�[�^�X�ϐ�
GLOBAL int func_state,stage_count,count,stage;	//��ʾ״̬��ֵ���Դ�Ϊ���ݽ�����������
GLOBAL int se_flag[SE_MAX];			//SE��flag

//�ṹ���������
GLOBAL ch_t ch;			//��ɫ����
GLOBAL enemy_t enemy[ENEMY_MAX];//
GLOBAL configpad_t configpad;//��õ�ǰ�ֱ�������״̬
GLOBAL enemy_order_t enemy_order[ENEMY_ORDER_MAX];//���˵ĳ�����Ϣ
GLOBAL shot_t shot[SHOT_MAX];//�����Ϣ
GLOBAL boss_shot_t boss_shot;// Boss�������Ϣ
GLOBAL cshot_t cshot[CSHOT_MAX];//�Ի�����õı���
GLOBAL del_effect_t del_effect[DEL_EFFECT_MAX];//������Ч
GLOBAL effect_t effect[EFFECT_MAX];//��Ч
GLOBAL bullet_info_t bullet_info[20];//�ӵ�����Ϣ
GLOBAL bom_t bom;				//Boom
GLOBAL bright_set_t bright_set; //���Ƶ�����
GLOBAL dn_t dn;					//�˵�ҡ��
GLOBAL boss_t boss;				//Boss����Ϣ
GLOBAL lazer_t lazer[LAZER_MAX];//

GLOBAL area_t area;//���������е����� (48)

GLOBAL int theone;
GLOBAL int theone_load;

GLOBAL int cc;