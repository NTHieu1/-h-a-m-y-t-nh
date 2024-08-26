#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

// Hàm ve diem trên cua so 
void drawPixel(int x, int y) {
    putpixel(x, y, RED);
}

// Hàm ve duong hyperbol bang thuat toán Bresenham
void drawHyperbolaBresenham(int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;
    int a_sqr = a * a;
    int b_sqr = b * b;
    int d1 = b_sqr - a_sqr * b + a_sqr / 4;
    int d2 = b_sqr * (x + 1) * (x + 1) + a_sqr * (y - 0.5) * (y - 0.5) - a_sqr * b_sqr;

    while (x * b_sqr < y * a_sqr) {
        drawPixel(x + xc, y + yc);
        drawPixel(-x + xc, y + yc);
        drawPixel(x + xc, -y + yc);
        drawPixel(-x + xc, -y + yc);

        if (d1 < 0) {
            d1 += b_sqr * (2 * x + 3);
        } else {
            d1 += b_sqr * (2 * x + 3) + a_sqr * (-2 * y + 2);
            y--;
        }
        x++;
    }

    while (y > 0) {
        drawPixel(x + xc, y + yc);
        drawPixel(-x + xc, y + yc);
        drawPixel(x + xc, -y + yc);
        drawPixel(-x + xc, -y + yc);

        if (d2 > 0) {
            d2 += a_sqr * (-2 * y + 3);
        } else {
            d2 += b_sqr * (2 * x + 2) + a_sqr * (-2 * y + 3);
            x++;
        }
        y--;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, a, b;
    int mouseClicks = 0;

    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (mouseClicks == 0) {
                getmouseclick(WM_LBUTTONDOWN, xc, yc);
                mouseClicks++;
            } else if (mouseClicks == 1) {
                getmouseclick(WM_LBUTTONDOWN, a, b);
                mouseClicks++;
                a = abs(a - xc);
                b = abs(b - yc);
                drawHyperbolaBresenham(xc, yc, a, b);
                mouseClicks = 0;
            }
        }

        delay(100); 
    }

    closegraph();
    return 0;
}

