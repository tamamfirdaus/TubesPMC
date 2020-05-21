#ifndef menu_H
#define menu_H

void menu_utama(int * in);
void submenu(int n, int m, char *nama);
void print_menu_utama();
void print_sub_menu();
void print_layout(int x, int y);
void print_routing(int x, int y);
int input_validation(char * line, int range_bawah, int range_atas);
void in_pcb_size(int * n,int * m);
int keluar(char * line);
void maintenance();
#include "menu.c"

#endif
