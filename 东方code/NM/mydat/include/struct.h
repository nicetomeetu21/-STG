//�ͽ�ɫ��صĽṹ��
typedef struct{
	int flag;		//
	int cnt;		//��ʱ��
	int power;		//
	int point;		//����
	int score;		//����
	int num;		//�л���
	int mutekicnt;	//�޵�״̬���������
	int shot_mode;	//���ģʽ
	int money;		//
	int img;		//ͼ��
	int slow;		//�Ƿ����ƶ�
	double x,y;		//����
	int shot_cnt;	//����ļ�����
	int limit;		//ը������
	
}ch_t;

typedef struct{
	double x,y;
}pt_t;

//�͵�����صĽṹ��
typedef struct{
	int flag,cnt,pattern,muki,knd,hp,hp_max,item_n[6],img,back_col;
	//flag�����������ƶ�ģʽ�����򡢵��˵����ࡢHP���ֵ��������ߡ�ͼ��
	double x,y,vx,vy,sp,ang;
	//���ꡢ�ٶ�x�������ٶ�y�������ٶȡ��Ƕ�
	int bltime,blknd,blknd2,col,state,wtime,wait;
	//��Ļ��ʼʱ�䡢��Ļ�����ࡢ�������ࡢ��ɫ��״̬������ʱ�䡢ֹͣʱ��
}enemy_t;

//���˳�����Ϣ
typedef struct{
	//���������ƶ�ģʽ�����˵�����
	int cnt,pattern,knd;
	//��ʼ��������ƶ��ٶ�
	double x,y,sp;
	//��Ļ��ʼʱ�䡢��Ļ���ࡢ��ɫ���������ӵ������ࡢֹͣʱ�䡢��Ʒ��6�����ࣩ
	int bltime,blknd,col,hp,blknd2,wait,item_n[6];
}enemy_order_t;

//���ֱ���صĲ���
typedef struct{
	int key[PAD_MAX];
}pad_t;

//��config��ص��ļ�,�ֱ�����
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;

//���ӵ���صĽṹ��
typedef struct{
//flag�����ࡢ����������ɫ��״̬����֤����ʧ�����ʱ�䡢Ч��������
	int flag,knd,cnt,col,state,till,eff,kaiten,eff_detail;
//���ꡢ�Ƕȡ��ٶȡ������Ƕȡ�˲������ٶ�
	double x,y,vx,vy,angle,spd,base_angle[1],rem_spd[1];
}bullet_t;

//������йصĽṹ��
typedef struct{
//flag�����ࡢ������������ĵ��˵ı��
	int flag,knd,cnt,num;
//�����Ƕȡ������ٶ�
	double base_angle[1],base_spd[1];
	bullet_t bullet[SHOT_BULLET_MAX];
}shot_t;

//��Boss�����صĽṹ��
typedef struct{
//flag�����ࡢ����������������ĵ��˵ı�š���ɫ
	int flag,knd,cnt,num;
//�����Ƕȡ������ٶ�
	double base_angle[10],base_spd[1];
	bullet_t bullet[BOSS_BULLET_MAX];
}boss_shot_t;

//�ͽ�ɫ�����صĽṹ��
typedef struct{
	int flag,power,cnt,knd;//flag��power��������������
	double x,y,angle,spd;//���ꡢ�Ƕȡ��ٶ�
}cshot_t;
//��Ч
typedef struct{
	int flag,cnt,col,knd,img,eff;
	double x,y,r,ang,spd,mvang,brt;
}effect_t;
 //������Ч
typedef struct{
	int flag,cnt,col;
	double x,y;
}del_effect_t;
//�ӵ�����Ϣ,�Ի���ײ���
typedef struct{
	int size_x,size_y,col_num,kaiten;
	double range;
}bullet_info_t;
//Boom����Ϣ
typedef struct{
	int flag,cnt,knd;
	double x,y;
}bom_t;
//�������ȵ���Ϣ
typedef struct{
	unsigned char brt;
}bright_set_t;
//�ˣ��ػζ��������Ϣ
typedef struct{
	int flag,cnt,time,size;
	int x,y;
}dn_t;
//�����������Ľṹ��
typedef struct{
	int flag,cnt,set_t;
	double ax,v0x,ay,v0y,vx,vy,prex,prey;
}phy_t;
//
typedef struct{
	int conv_flag;
	double time,base_ang,angle;
	double conv_x,conv_y,conv_base_x,conv_base_y;
}lphy_t;
//Boos����Ϣ
typedef struct{
	int flag,cnt,knd,wtime,state,endtime,hagoromo,graph_flag;
	int hp,hp_max;
	int appear_count[2],set_hp[DANMAKU_MAX],back_knd[DANMAKU_MAX];
	double x,y,dx,dy,ang,spd;
	phy_t phy;
}boss_t;
//
typedef struct{
	int flag,cnt,knd,col,state;//
	double haba,angle,length,hantei;//
	pt_t startpt,disppt[4],outpt[4];//
	lphy_t lphy;
}lazer_t;

//BGM��Ϣ(��area_t��ʹ��(48)
typedef struct{
		//BGM�Ĳ���flag�����ž��������ʱ���������š�ѭ��λ��
        int flag,handle,knd[2],loop_pos[2];
}bgm_t;
 
//���������е���Ϣ
typedef struct{
        bgm_t bgm;
}area_t;