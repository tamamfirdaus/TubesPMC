//Last Edit:    01 April 2019 16:44
//Library
#ifndef VAR_H
#define VAR_H
#include <stdio.h>
#include <stdlib.h>


//Tipe bentukan
typedef struct koordinat{
    int x;
    int y;
}koordinat_t;

typedef struct komponen{
    char nama[10];
    koordinat_t kaki_1;
    koordinat_t kaki_2;
    koordinat_t kaki_3;                                 //Hanya untuk transistor
}komponen_t;

typedef struct grid{                                    //Variabel untuk grid matriks pcb
    char nama[10];
    char node[10];
}grid_t;

//Variabel-variabel Global
grid_t pcb_layout[40][40];
int m,n;
char matriksPCB[40][40];


#endif