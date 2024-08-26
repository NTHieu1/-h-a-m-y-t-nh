 #include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

// Hàm ve diem trên cua so
void drawPixel(int x, int y) {
    putpixel(x, y, RED);
}

// Hàm ve duong ellipse bang thuat toán Bresenham
void drawEllipseBresenham(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;
    int p1 = ry * ry - rx * rx * ry + rx * rx / 4;
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;

    while (dx < dy) {
        drawPixel(xc + x, yc + y);
        drawPixel(xc - x, yc + y);
        drawPixel(xc + x, yc - y);
        drawPixel(xc - x, yc - y);

        x++;
        dx = dx + 2 * ry * ry;

        if (p1 < 0) {
            p1 = p1 + dx + ry * ry;
        } else {
            y--;
            dy = dy - 2 * rx * rx;
            p1 = p1 + dx + ry * ry - dy;
        }
    }

    int p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

    while (y >= 0) {
        drawPixel(xc + x, yc + y);
        drawPixel(xc - x, yc + y);
        drawPixel(xc + x, yc - y);
        drawPixel(xc - x, yc - y);

        y--;
        dy = dy - 2 * rx * rx;

        if (p2 > 0) {
            p2 = p2 + rx * rx - dy;
        } else {
            x++;
            dx = dx + 2 * ry * ry;
            p2 = p2 + rx * rx - dy + dx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, rx, ry;
    int mouseClicks = 0;

    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (mouseClicks == 0) {
                getmouseclick(WM_LBUTTONDOWN, xc, yc);
                mouseClicks++;
            } else if (mouseClicks == 1) {
                getmouseclick(WM_LBUTTONDOWN, rx, ry);
                mouseClicks++;
                rx = abs(rx - xc);
                ry = abs(ry - yc);
                drawEllipseBresenham(xc, yc, rx, ry);
                mouseClicks = 0;
            }
        }

        delay(100); 
    }

    closegraph();
    return 0;
}

