#include<iostream>
#include<stdio.h>
#include<graphics.h>

using namespace std;

int main(){
 
 	int x1,x2,y1,y2,p,x,dx,dy,y;
    cout<<"Enter x1 => ";
    cin>>x1;
    cout<<"Enter x2 => ";
    cin>>x2;
    cout<<"Enter y1 => ";
    cin>>y1;
    cout<<"Enter y2 => ";
    cin>>y2;
    x = x1;
    y = y1;
    dx = x2-x1;
    dy = y2-y1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout<<"("<<x<<", "<<y<<")"<<endl;
    putpixel(x,y,2);
    p = 2*(dy) - (dx);
    while(x<x2){
    	if(p<0){
    		x++;
    		p = 2*x - dx;
    	} else {
    		x++;
    		y++;
    		p = p + 2*(dy);
    	}
    	cout<<"("<<x<<", "<<y<<")"<<endl;
    	putpixel(x,y,7);
    	delay(100);
    }

 
    //delay(500000);
    closegraph();
    return 0;
}