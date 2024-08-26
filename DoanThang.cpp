#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p;
    int x, y;
    int xEnd, yEnd;

    // Trý?ng h?p 1: 0 <= m <= 1, ði lên t? trái sang ph?i
    if (dx > dy) {
        if (x1 > x2) {
            x = x2;
            y = y2;
            xEnd = x1;
        } else {
            x = x1;
            y = y1;
            xEnd = x2;
        }
        p = 2 * dy - dx;
        putpixel(x, y, WHITE);
        while (x < xEnd) {
            x++;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y++;
                p += 2 * (dy - dx);
            }
            putpixel(x, y, WHITE);
        }
    } 
    // Trý?ng h?p 2: m > 1, ði lên t? trái sang ph?i
    else if (dy > dx) {
        if (y1 > y2) {
            x = x2;
            y = y2;
            yEnd = y1;
        } else {
            x = x1;
            y = y1;
            yEnd = y2;
        }
        p = 2 * dx - dy;
        putpixel(x, y, WHITE);
        while (y < yEnd) {
            y++;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x++;
                p += 2 * (dx - dy);
            }
            putpixel(x, y, WHITE);
        }
    } 
    // Trý?ng h?p 3: -1 <= m < 0, ði xu?ng t? trái sang ph?i
    else if (dx > dy && x1 > x2) {
        if (y1 > y2) {
            x = x1;
            y = y1;
            xEnd = x2;
        } else {
            x = x2;
            y = y2;
            xEnd = x1;
        }
        p = 2 * dy - dx;
        putpixel(x, y, WHITE);
        while (x > xEnd) {
            x--;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y++;
                p += 2 * (dy - dx);
            }
            putpixel(x, y, WHITE);
        }
    } 
    // Trý?ng h?p 4: m < -1, ði xu?ng t? trái sang ph?i
    else if (dy > dx && y1 > y2) {
        if (x1 > x2) {
            x = x1;
            y = y1;
            yEnd = y2;
        } else {
            x = x2;
            y = y2;
            yEnd = y1;
        }
        p = 2 * dx - dy;
        putpixel(x, y, WHITE);
        while (y > yEnd) {
            y--;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x++;
                p += 2 * (dx - dy);
            }
            putpixel(x, y, WHITE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (!kbhit()) {
        int x1, y1, x2, y2;

        printf("Click the starting point of the line.\n");
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(200);
        getmouseclick(WM_LBUTTONDOWN, x1, y1);

        printf("Click the ending point of the line.\n");
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(200);
        getmouseclick(WM_LBUTTONDOWN, x2, y2);

        drawLineBresenham(x1, y1, x2, y2);
    }

    closegraph();
    return 0;
}

