
#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#define ROUND(a) ((int)(a+0.5))

int mapx(int x){
	return getmaxx()/2+x;
}
int mapy(int y){
	return getmaxy()/2-y;
}

void lineDDA(int xa, int ya, int xb, int yb){
    int dx=xb-xa, dy=yb-ya, steps, k;
    float xIncrement, yIncrement,x=xa, y=ya;

    if (abs(dx)>abs(dy)){
	steps=abs(dx);
    } else {
	steps=abs(dy);
    }

    xIncrement=dx/(float)steps;
    yIncrement=dy/(float)steps;

    putpixel(ROUND(x),ROUND(y), WHITE);

    for(k=0;k<steps;k++){
	x+=xIncrement;
	y+=yIncrement;
	putpixel(ROUND(x), ROUND(y), WHITE);
    }
}

void drawline(int x1, int y1, int x2, int y2){
    lineDDA(getmaxx()/2+x1, getmaxy()/2-y1, getmaxx()/2+x2, getmaxy()/2-y2);
}

void drawpoint(int x1, int y1){
    putpixel(getmaxx()/2+x1, getmaxy()/2-y1, WHITE);
}

void circlePlotPoints(int xCenter, int yCenter, int x, int y){
    drawpoint(xCenter + x, yCenter + y);
    drawpoint(xCenter - x, yCenter + y);
    drawpoint(xCenter + x, yCenter - y);
    drawpoint(xCenter - x, yCenter - y);
    drawpoint(xCenter + y, yCenter + x);
    drawpoint(xCenter - y, yCenter + x);
    drawpoint(xCenter + y, yCenter - x);
    drawpoint(xCenter - y, yCenter - x);

}

void circleMidpoint(int xCenter, int yCenter, int radius){
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x < y){
	x++;

	if (p < 0)
	    p += 2*x + 1;
	else{
	    y--;
	    p += 2*(x-y) + 1;
	}

	circlePlotPoints(xCenter, yCenter, x, y);
    }

}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int maxx=getmaxx();
    int maxy=getmaxy();
    line(maxx/2, 0,maxx/2, maxy);
    line(0,maxy/2, maxx, maxy/2);


    int x1, y1, r;

    cout << "Enter centre coordinates x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter radius: ";
    cin >> r;

    textcolor(BLACK);
    clrscr();

    lineDDA(maxx/2,0,maxx/2,maxy);
    lineDDA(0,maxy/2,maxx,maxy/2);

    circleMidpoint(x1, y1, r);

    getch();
    closegraph();
    return 0;

}