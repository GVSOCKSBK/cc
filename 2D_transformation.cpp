#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int mapx(int x){
	return getmaxx()/2+x;
}
int mapy(int y){
	return getmaxy()/2-y;
}

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void translate(int &x, int &y, int tx, int ty) {
    x = x + tx;
    y = y + ty;
}

void rotate(int &x, int &y, float angle) {
    float radian = angle * (3.1416 / 180);
    int tempX = x;
    x = int(x * cos(radian) - y * sin(radian));
    y = int(tempX * sin(radian) + y * cos(radian));
}

void scale(int &x, int &y, float sx, float sy) {
    x = int(x * sx);
    y = int(y * sy);
}

void shear(int &x, int &y, float shx, float shy) {
    int tempX = x;
    x = int(x + tempX * shx);
    y = int(y + tempX * shy);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    int maxx = getmaxx();
    int maxy = getmaxy();
    line(maxx/2, 0,maxx/2, maxy);
    line(0,maxy/2, maxx, maxy/2);

    // Original rectangle
    drawRectangle(x1, y1, x2, y2);

    // Translation
    int tx = 50, ty = 50;
    translate(x1, y1, tx, ty);
    translate(x2, y2, tx, ty);
    setcolor(RED);
    drawRectangle(x1, y1, x2, y2);

    // Rotation
    float angle = 45.0;
    rotate(x1, y1, angle);
    rotate(x2, y2, angle);
    setcolor(GREEN);
    drawRectangle(x1, y1, x2, y2);

    // Scaling
    float sx = 1.5, sy = 1.5;
    scale(x1, y1, sx, sy);
    scale(x2, y2, sx, sy);
    setcolor(BLUE);
    drawRectangle(x1, y1, x2, y2);

    // Shearing
    float shx = 0.5, shy = 0;
    shear(x1, y1, shx, shy);
    shear(x2, y2, shx, shy);
    setcolor(YELLOW);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
