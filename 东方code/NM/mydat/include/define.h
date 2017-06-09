//圆周率
#define PI 3.1415926535898
#define PI2 (PI*2)
//区域的尺寸
//角色可运动的区域：从（32,16）坐标开始，横向384纵向448像素的区域
#define FMX 384
#define FMY 448
//区域的左上角坐标
#define FX 32
#define FY 16
//Boss的固定位置
#define BOSS_POS_X (FMX/2)
#define BOSS_POS_Y 120.0

//效果音种类的的最大数量
#define SE_MAX 100

//手柄按键的最大数量
#define PAD_MAX 16

//表示的同一时间最大敌人数
#define ENEMY_MAX 30
//敌人出现信息的最大数量
#define ENEMY_ORDER_MAX 500
//敌人的行动模式的最大数量
#define ENEMY_PATTERN_MAX 11
//
#define CRANGE 2.0
//一个敌人所拥有的最大子弹的数量
#define SHOT_BULLET_MAX 1000
//Boss所有的子弹的最大数量
#define BOSS_BULLET_MAX 3000
//画面中一帧所能表示的最大的敌人的弹幕数
#define SHOT_MAX 30
//弹幕的最大数量
#define SHOT_KND_MAX 18
//自机射击的子弹的登录最大数
#define CSHOT_MAX 200
//特效登录最大数
#define EFFECT_MAX 100
//消灭特效登录最大数
#define DEL_EFFECT_MAX 30
//
#define DANMAKU_MAX 50
//弹幕的最大数
#define LAZER_MAX 100

#include "struct.h"