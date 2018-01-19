#include<iostream>
#include<stdio.h>
#include<graphics.h>

using namespace std;

void ellipse(float x, float y){
    putpixel(x + 100, y + 100, 7);
    putpixel(x + 100, -y + 100, 7);
    putpixel(-x + 100, y + 100, 7);
    putpixel(-x + 100, -y + 100, 7);
}
void completeellipse(float r, float g, float u, float v){
    int x = 0;
    int y = g;
    float p  = pow(g,2) - pow(r,2)*g + pow(r,2)/4;
    while(2.0*x*pow(g,2)<2.0*y*pow(r,2)){
        if(p<0){
            x++;
            p = p + 2*pow(g,2)*x + pow(g,2);
            //p = p + 2*pow(g,2)*x + pow(g,2) - 2*pow(r,2)*y;
        }
        else{
            x++;
            y--;
            p = p + 2*pow(g,2)*x + pow(g,2) - 2*pow(r,2)*y;   
        }
        ellipse(x,y);
    }
    p = pow(x+0.5,2)*pow(g,2) + pow(y-1,2)*pow(r,2) - pow(g,2)*pow(r,2);
    while(y>=0){
        if(p>0){
            y--;
            p = p - 2*pow(r,2)*y + pow(r,2);
        } else {
            y--;
            x++;
            p = p+2*g*g*x-2*r*r*y+r*r;
        }
        ellipse(x,y);
    }
}

int main(){
 
 	float r,g,u,v;
    r = 40;
    g = 20;
    u = 100;
    v = 50;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    completeellipse(r,g,u,v);
    delay(50000);
    closegraph();
    return 0;
}