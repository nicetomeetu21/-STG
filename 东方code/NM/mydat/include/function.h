//boss_shot.cpp
	GLOBAL void boss_shot_main();

//enemy.cpp
	GLOBAL void enemy_main();

//enemy_act_pattern.cpp
	GLOBAL double rang(double);

//cshot.cpp
	GLOBAL void cshot_main();

//char.cpp
	GLOBAL void calc_ch();
	GLOBAL void ch_move();

//effect.cpp
	GLOBAL void effect_main();
	
//graph.cpp
	//
	GLOBAL void graph_main();

//ini.cpp
	GLOBAL void first_ini();
	GLOBAL void ini();

//shot.cpp
	GLOBAL double shotatan2(int n);
	GLOBAL int shot_search(int n);
	GLOBAL void shot_main();

//key.cpp
	//����ǰ�İ�������
	GLOBAL int GetHitKeyStateAll_2();
	//���ش���İ����ı�ŵĵ�ǰ״̬
	GLOBAL int CheckStateKey(unsigned char Handle);

	//
	GLOBAL void GetHitPadStateAll();
	//
	GLOBAL int CheckStatePad(unsigned int Handle);

//laod.cpp
	//����
	GLOBAL void load();
	GLOBAL void load_story();

//music.cpp
	GLOBAL void music_ini();
	GLOBAL void music_play();

//out.cpp
	GLOBAL void out_main();

	    GLOBAL void delete_bgm();
        GLOBAL void bgm_main();

	//GLOBAL void	graph_theone()