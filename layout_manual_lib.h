#ifndef LAYMAN_H
#define LAYMAN_H
#include "variabel_tubes.h"

int cekKoordinat2 (int x1, int x2, int y1, int y2);
int cekRC(int x1, int x2, int y1, int y2, int syarat);
int cekT(int x1, int x2,int x3, int y1, int y2, int y3, int syarat);
int cekPCB(int x, int y, int N, int M);		
void layout_manual();

#endif
