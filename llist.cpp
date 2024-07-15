#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <string.h>

void rect(int, int, int);
int l = 5, r = 34, t = 50, b = 60;

struct ll {
    int data;
    struct ll *link;
} *first = NULL, *tt, *nn, *temp = NULL, rrr;

int main() {
    int n = 0, l = 0, uq = 0, t = 0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Use an empty string for the BGI path with WinBGIm
    scanf("%d", &n);
    while (n--) {
        nn = (struct ll *)malloc(sizeof(struct ll));
        scanf("%d", &nn->data);
        if (first == NULL) {
            first = nn;
            temp = nn;
        } else {
            temp->link = nn;
            temp = nn;
        }
        temp->link = NULL;
        tt = first;
        while (tt != NULL) { // for each nn traversal
            l = tt->data;
            uq = (int)(tt->link);  // Typecasting to int
            rect(l, uq, t); // function call
            tt = tt->link;
        }
        t++;
    }
    getch();
    closegraph();
    return 0;
}

void rect(int mm, int mo, int tb) {
    int i, gd = 0, gm, xma, yma, z, zz, p = mm, al = mo;
    struct ll *flop = first, *satvika = tt;
    char pq[5], sq[7], f[6], nt[6], cor[12];
    cor[0] = 'n';
    cor[1] = 'n';
    cor[2] = '=';
    cor[3] = '\0';
    sprintf(pq, "%d", p); // int to string conversion
    sprintf(sq, "%d", al);
    sprintf(f, "%p", (void *)flop);  // Printing pointer address
    sprintf(nt, "%p", (void *)satvika);  // Printing pointer address
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    if (tt == first) { // to reset rectangles next line
        l = 6;
        r = 60 + (70 * tb);
        t = 45;
        b = 90 + (70 * tb);
        line(l + 15, r - 15, l + 10, r);
        line(l + 30, r - 20, l + 10, r);
        line(l + 30, r - 10, l + 10, r);
        outtextxy(l + 30, r - 20, (char *)"FIRST");
        if (tt->link == NULL) {
            line(l + 65, r - 15, l + 60, r);
            line(l + 80, r - 20, l + 60, r);
            line(l + 80, r - 10, l + 60, r);
            outtextxy(l + 80, r - 20, (char *)"TEMP");
        }
    }
    if (tt->link == NULL && tt != first) {
        line(l + 15, r - 15, l + 10, r);
        line(l + 30, r - 20, l + 10, r);
        line(l + 30, r - 10, l + 10, r); // bottom
        outtextxy(l + 30, r - 30, (char *)"TEMP");
    }
    rectangle(l, r, t, b);
    floodfill(l + 1, r + 1, WHITE);
    setfillstyle(SOLID_FILL, CYAN);
    l = t;
    t = t + 50;
    rectangle(l, r, t, b);
    floodfill(l + 1, r + 1, WHITE);
    if (tt->link != NULL) {
        line(t, b - 14, t + 40, (b - 14)); // middle
        line(t + 20, b - 24, t + 40, b - 14); // top
        line(t + 20, b, t + 40, b - 14); // bottom
    }
    z = l - 30;
    zz = r + 12;
    outtextxy(z, zz, pq); // for temp->data
    if (tt->link == NULL) { // for NULL address
        outtextxy(z + 40, zz, (char *)"NULL");
    } else {
        outtextxy(z + 40, zz, sq); // next address
    }
    strcat(cor, nt);
    outtextxy(z + 5, zz + 22, cor);
    for (i = 0; i < 12; i++) cor[i] = '\0';
    l = l + 90;
    t = t + 90;
    getch();
}
