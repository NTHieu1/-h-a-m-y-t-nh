#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

// Hàm ve diem trên cua so 
void drawPixel(int x, int y) {
    putpixel(x, y, RED);
}

// Hàm ve duong cong parabol bang thuat toán Bresenham
void drawParabolaBresenham(int xc, int yc, int a) {
    int x = 0;
    int y = a;
    int d = 1 - 2 * a;
    int d1 = 3;
    int d2 = -2 * a + 5;

    while (x <= y) {
        drawPixel(x + xc, y + yc);
        drawPixel(-x + xc, y + yc);

        if (d >= 0) {
            d += d2;
            d2 += 4;
            y--;
        } else {
            d += d1;
            d2 += 2;
        }

        d1 += 2;
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, a;
    int mouseClicks = 0;

    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (mouseClicks == 0) {
                getmouseclick(WM_LBUTTONDOWN, xc, yc);
                mouseClicks++;
            } else if (mouseClicks == 1) {
                getmouseclick(WM_LBUTTONDOWN, a, yc);
                mouseClicks++;
                a = abs(a - yc);
                drawParabolaBresenham(xc, yc, a);
                mouseClicks = 0;
            }
        }

        delay(100);
    }

    closegraph();
    return 0;
}

