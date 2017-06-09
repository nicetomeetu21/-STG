#include "../include/GV.h"

extern int DrawGraphFd( int xd, int yd, int GrHandle, int TransFlag);

void graph_theone(){
        //SetDrawArea( 0 , 0 ,640 , 480 ) ;//设定可以绘制的区域
		DrawGraph(0,0,theone_load,FALSE);
        //SetDrawArea( 0, 0, 640, 480);//重置区域
}

void graph_back00(){
	SetDrawArea( 32 , 16 , 416 , 464 ) ;
	//DrawGraph(FX,count%700+FY-700,img_back[0],FALSE);
	//DrawGraph(FX,count%700+FY    ,img_back[0],FALSE);
	SetDrawArea( 0, 0, 640, 480);
	DrawGraphFd(0,0,img_back[0],TRUE);

}

void graph_back01(){
	SetDrawArea( 32 , 16 , 416 , 464 ) ;

	DrawGraph(FX,FY-count%480,img_back[11],FALSE);
	DrawGraph(FX,FY-count%480+480,img_back[11],FALSE);
	DrawGraph(FX,FY,img_back[10],TRUE);

	SetDrawArea( 0, 0, 640, 480);
}

void graph_back_main(){
	
	if(boss.flag==1 && boss.back_knd[boss.knd]==1)
		graph_back01();
	else
		graph_back00();
}