#include<iostream>
#include<stdio.h>
#include<graphics.h>

using namespace std;

void circlepoints(int x, int y){
    putpixel(x + 100, y + 100, 7);
    putpixel(x + 100, -y + 100, 7);
    putpixel(-x + 100, y + 100, 7);
    putpixel(-x + 100, -y + 100, 7);
    putpixel(y + 100, x + 100, 7);
    putpixel(y + 100, -x + 100, 7);
    putpixel(-y + 100, x + 100, 7);
    putpixel(-y + 100, -x + 100, 7);
}

int main(){
 
 	int r,p,x,y;
    cout<<"Enter the radius => ";
    cin>>r;
    x = 0;
    y = r;
    p = 1-r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    //cout<<"("<<x<<", "<<y<<")"<<endl;
    //putpixel(x,y,2);
    //p = 2*(dy) - (dx);
    while(x<y){
        x++;
    	if(p>0){
    		p += 2*(x-y) + 1;
            y--;
    	} else {
    		p += 2*x + 1;
    	}
    	circlepoints(x,y);
        delay(500);
    }

 
    delay(500000);
    closegraph();
    return 0;
}