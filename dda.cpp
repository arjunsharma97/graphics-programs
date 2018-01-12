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
    dx = x2-x1;
    dy = y2-y1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int m = dy/dx;
    if(m<=1){
        x = x1;
        y = y1;
        for(;x<=x2;x++){
            cout<<"("<<x<<", "<<y<<")"<<endl;
            putpixel(x,round(y),7);
            y+=m;
            delay(5);
        }
    } else {
        x = x1;
        y = y1;
        for(;y<=y2;y++){
            cout<<"("<<x<<", "<<y<<")"<<endl;
            putpixel(y,round(x),7);
            x+=m;
            delay(5);   
        }
    }
    delay(2000);
    closegraph();
    return 0;
}