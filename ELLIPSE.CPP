#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int mapx(int x){
	return (getmaxx()/2)+x;
}
int mapy(int y){
	return (getmaxy()/2)-y;
}

void drawEllipse(int xc, int yc, int rx, int ry) {
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x = 0, y = ry;
    int rxSquare = rx * rx;
    int rySquare = ry * ry;
    int twoRxSquare = 2 * rxSquare;
    int twoRySquare = 2 * rySquare;
    int p;

    // Region 1
    p = rySquare - rxSquare * ry + 0.25 * rxSquare;
    while (twoRySquare * x < twoRxSquare * y) {
	putpixel(mapx(xc + x), mapy(yc - y), WHITE);
	putpixel(mapx(xc - x), mapy(yc + y), WHITE);
	putpixel(mapx(xc + x), mapy(yc + y), WHITE);
	putpixel(mapx(xc - x), mapy(yc - y), WHITE);

	x++;
	if (p < 0)
	    p += twoRySquare * x + rySquare;
	else {
	    y--;
	    p += twoRySquare * x - twoRxSquare * y + rySquare;
	}
    }

    // Region 2
    p = rySquare * (x + 0.5) * (x + 0.5) + rxSquare * (y - 1) * (y - 1) - rxSquare * rySquare;
    while (y >= 0) {
	putpixel(mapx(xc + x), mapy(yc - y), WHITE);
	putpixel(mapx(xc - x), mapy(yc + y), WHITE);
	putpixel(mapx(xc + x), mapy(yc + y), WHITE);
	putpixel(mapx(xc - x), mapy(yc - y), WHITE);

	y--;
	if (p > 0)
	    p += -twoRxSquare * y + rxSquare;
	else {
	    x++;
	    p += twoRySquare * x - twoRxSquare * y + rxSquare;
	}
    }

   // getch();
    //closegraph();
}

int main() {
    int xc, yc,rx, ry;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    int maxx=getmaxx();
    int maxy=getmaxy();
    line(maxx/2, 0,maxx/2, maxy);
    line(0,maxy/2, maxx, maxy/2);

    cout << "Enter the coordinates of the center (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter the semi-major axis (rx): ";
    cin >> rx;

    cout << "Enter the semi-minor axis (ry): ";
    cin >> ry;
    

    drawEllipse(xc, yc, rx, ry);
    getch();
    closegraph();

    return 0;
}
