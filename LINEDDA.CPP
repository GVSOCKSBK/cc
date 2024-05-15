#include<iostream.h>

#include<math.h>
#include<graphics.h>
#include<conio.h>
#define ROUND(a) ((int)(a+0.5))

int mapx(int x){
	return getmaxx()/2+x;
}
int mapy(int y){
	return getmaxy()/2-y;
}
void lineDDA(int xa,int ya, int xb, int yb)
{
    int dx = xb-xa, dy =yb-ya, steps, k;
    float xIncrement, yIncrement, x = xa, y = ya;

    if(abs(dx)>abs(dy)) steps =abs(dx);
    else steps = abs(dy);

    xIncrement = dx/float(steps);
    yIncrement = dy/float(steps);

    putpixel(ROUND(mapx(x)), ROUND(mapy(y)), RED);
    for(k=0; k<steps;k++){
	x += xIncrement;
	y += yIncrement;
	putpixel(ROUND(mapx(x)), ROUND(mapy(y)), RED);
    }
}
int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
int xa,ya,xb,yb;
int maxx = getmaxx();
int maxy = getmaxy();
line(maxx/2, 0,maxx/2, maxy);
line(0,maxy/2, maxx, maxy/2);
cout<<"ENTER coordinates:";
cin>>xa;
cin>>ya;
cin>>xb;
cin>>yb;
lineDDA(xa,ya,xb,yb);
getch();
closegraph();
return 0;
}