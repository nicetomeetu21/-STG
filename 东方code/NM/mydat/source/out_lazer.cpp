#include "../include/GV.h"
#include <math.h>
#include <stdio.h>

typedef struct {
    double x, y;
} Vector2_t;

void Vector2Diff(Vector2_t *diff, const Vector2_t *p, const Vector2_t *q){
    diff->x = p->x - q->x;
    diff->y = p->y - q->y;
}

double Vector2InnerProduct(const Vector2_t *p, const Vector2_t *q){
    return p->x * q->x + p->y * q->y;
}

double Vector2OuterProduct(const Vector2_t *p, const Vector2_t *q){
    return p->x * q->y - p->y * q->x;
}

double get_distance(double x, double y, double x1, double y1, 
                    double x2, double y2){
    double dx,dy,a,b,t,tx,ty;
    double distance;
    dx = (x2 - x1); dy = (y2 - y1);
    a = dx*dx + dy*dy;
    b = dx * (x1 - x) + dy * (y1 - y);
    t = -b / a;
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    tx = x1 + dx * t;
    ty = y1 + dy * t;
    distance = sqrt((x - tx)*(x - tx) + (y - ty)*(y - ty));
    return distance;
}

double get_pt_and_pt(pt_t p1, pt_t p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double question_point_and_circle(pt_t p, pt_t rp,double r){
    double dx=p.x-rp.x,dy=p.y-rp.y;
    if(dx*dx + dy*dy < r*r)    return 1;
    else                    return 0;
}

void swap_double(double *n, double *m){
    double t=*m;
    *m=*n;*n=t;
}

double get_sita(pt_t pt0,pt_t pt1,pt_t rpt){

    Vector2_t c, p, q; 
    Vector2_t cp;      
    Vector2_t cq;      
    double s;          
    double t;          
    double theta;      

 
    c.x = pt0.x;    c.y = pt0.y;
    p.x = pt1.x;    p.y = pt1.y;
    q.x = rpt.x;    q.y = rpt.y;


    Vector2Diff(&cp, &p, &c);          
    Vector2Diff(&cq, &q, &c);          
    s = Vector2OuterProduct(&cp, &cq); 
    t = Vector2InnerProduct(&cp, &cq); 
    theta = atan2(s, t);
    return theta;
}

int hitjudge_square_and_circle(pt_t pt[4], pt_t rpt, double r){
    int i;
    double a[4],b[4];
    double x=rpt.x,y=rpt.y;
	double theta,theta2;

    for(i=0;i<4;i++){
        if(question_point_and_circle(pt[i],rpt,r)==1)
            return 1;
    }
  

   

    theta =get_sita(pt[0],pt[1],rpt);
    theta2=get_sita(pt[2],pt[3],rpt);

    if(0<=theta && theta<=PI/2 && 0<=theta2 && theta2<=PI/2)
        return 1;


    for(i=0;i<4;i++){
        if(get_distance(rpt.x,rpt.y,pt[i].x,pt[i].y,pt[(i+1)%4].x,pt[(i+1)%4].y)<r)
            return 1;
    }
   
    return 0;
}


int out_lazer(){
    int i,j;
    pt_t sqrp[4],rpt={ch.x,ch.y};
    
    for(i=0;i<LAZER_MAX;i++){
        
        if(lazer[i].flag>0 && lazer[i].hantei!=0){
            for(j=0;j<4;j++){
                sqrp[j].x=lazer[i].outpt[j].x;
                sqrp[j].y=lazer[i].outpt[j].y;
            }
            
            if(hitjudge_square_and_circle(sqrp,rpt,CRANGE))
                return 1;
        }
    }
    return 0;
}