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
    double p1, p2;
    float s = r;
    float k = g;
    float e = pow((s + 0.5),2);
    float f = pow((k-1),2);
    p2 = u*e + (v*f) - (u*v);
    ellipse(s,k);
    while(k>=0){
        if(p2>0){
            p2 = p2 + v - (2*v*s);
        } else {
            p2 += 2*u*(s+1) - 2*v*(k-1) + v;
            s++;
        }
        k--;
        ellipse(s,k);
    }
}

int main(){
 
 	float r,g,u,v;
    r = 10;
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