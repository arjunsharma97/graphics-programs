#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include <math.h>


#define PI 3.14159265

using namespace std;

void translate(int tf,int x1,int y1,int x2,int y2){
	rectangle(x1+tf,y1+tf,x2+tf,y2+tf);
	delay(100);
}

void scale(int sf,int x1,int y1,int x2,int y2){
	rectangle(x1,y1,x2+sf*abs(x2-x1),y2+sf*abs(x2-x1));
	delay(1000);
}

void shear(int sf,int x1,int y1,int x2,int y2){
	line(x1,y1,x1+sf,y2);
	line(x2,y1,x2+sf,y2);
	line(x1+sf,y2,x2+sf,y2);
	line(x1,y1,x2,y1);
	delay(1000);
}
void rotation(int theta,int x1,int y1,int x2,int y2){
	theta = theta*PI/180;
	float x3 = x1;
	float y3 = y2;
	float x4 = x2;
	float y4 = y1;
	x1 = x1*cos(theta) + y1*sin(theta) +50;
	x2 = x2*cos(theta) + y2*sin(theta)+50;
	x3 = x3*cos(theta) + y3*sin(theta)+50;
	x4 = x4*cos(theta) + y4*sin(theta)+50;
	y1 = -x1*sin(theta) + y1*cos(theta)+50;
	y2 = -x2*sin(theta) + y2*cos(theta)+50;
	y3 = -x3*sin(theta) + y3*cos(theta)+50;
	y4 = -x4*sin(theta) + y4*cos(theta)+50;
	line(x1,y1,x3,y3);
	line(x1,y1,x4,y4);
	line(x3,y3,x2,y2);
	line(x2,y2,x4,y4);
}


int main(){
 	float x1,x2,y1,y2,tf;
    cout<<"Enter x1 => ";
    cin>>x1;
    cout<<"Enter y1 => ";
    cin>>y1;
    cout<<"Enter x2 => ";
    cin>>x2;
    cout<<"Enter y2 => ";
    cin>>y2;
    cout<<"Enter translation factor => ";
    cin>>tf; 
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    rectangle(x1,y1,x2,y2);
    delay(1000);
    rotation(tf,x1,y1,x2,y2);
    //shear(tf,x1,y1,x2,y2);
    //scale(tf,x1,y1,x2,y2);
    //scale(tf*2,x1,y1,x2,y2);
    //translate(20,x1,y1,x2,y2);
    //translate(50,x1,y1,x2,y2);
    delay(50000);
    closegraph();
    return 0;

}