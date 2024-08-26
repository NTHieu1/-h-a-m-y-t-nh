#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

void drawCirclePoints(int x, int y, int xc, int yc) {
    putpixel(x + xc, y + yc, WHITE);
    putpixel(-x + xc, y + yc, WHITE);
    putpixel(x + xc, -y + yc, WHITE);
    putpixel(-x + xc, -y + yc, WHITE);
    putpixel(y + xc, x + yc, WHITE);
    putpixel(-y + xc, x + yc, WHITE);
    putpixel(y + xc, -x + yc, WHITE);
    putpixel(-y + xc, -x + yc, WHITE);
}

void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCirclePoints(x, y, xc, yc);

    while (x <= y) {
        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
        drawCirclePoints(x, y, xc, yc);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, r;
    int mouseClicks = 0;

    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (mouseClicks == 0) {
                getmouseclick(WM_LBUTTONDOWN, xc, yc);
                mouseClicks++;
            } else if (mouseClicks == 1) {
                getmouseclick(WM_LBUTTONDOWN, r, yc);
                mouseClicks++;
                r = r - xc; // Tính bán kính tu diem bat dau den diem ket thúc
                bresenhamCircle(xc, yc, r);
                mouseClicks = 0; // Ðat lai so lan click chuot
            }
        }

        delay(100); 
    }

    closegraph();
    return 0;
}

