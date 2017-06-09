extern void boss_shot_bulletH0000();
extern void boss_shot_bulletH0001();
extern void boss_shot_bulletH0001ex();
extern void boss_shot_bulletH0002();
extern void boss_shot_bulletH0003();
extern void boss_shot_bulletH0004();
extern void boss_shot_bulletH0004ex();
extern void boss_shot_bulletH0004ex_0();
extern void boss_shot_bulletH0004ex_1();
extern void boss_shot_bulletH0004ex_2();
//extern void boss_shot_bulletH0005();
//extern void boss_shot_bulletH0006();
//extern void boss_shot_bulletH0007();
//extern void boss_shot_bulletH0008();

void (*boss_shot_bullet[DANMAKU_MAX])() =
{
	boss_shot_bulletH0004ex_0,	//0
	boss_shot_bulletH0000,   //1
	boss_shot_bulletH0001,	//2
	boss_shot_bulletH0001ex,	//3
	boss_shot_bulletH0002,	//4
	boss_shot_bulletH0003,	//5
	boss_shot_bulletH0004,	//6
	boss_shot_bulletH0004ex,	//7
	boss_shot_bulletH0004ex_1,	//8
	boss_shot_bulletH0004ex_2,	//9
	//boss_shot_bulletH0005,
	//boss_shot_bulletH0006,
	//boss_shot_bulletH0007,
	//boss_shot_bulletH0008,
};