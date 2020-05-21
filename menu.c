//***********************************************************//
// 								[ Source Code]
// 
// Institution : Institut Teknologi Bandung 
// Name : Andi Muhammad Riyadhus Ilmy
// File Name : main.c 
// Dependency : lib.h
// // Description: 
// main program untuk tugas besar PPMC
// 
// Status: 
// 1. Andi Muhammad Riyadhus Ilmy - 13217053 : Create the file 
//2. Tamam - <NIM> : Menambahkan routing dan layout
//3. Andi Muhammad Riyadhus Ilmy - 13217053 :
//***********************************************************//
//Update 01.03.19 Menambahkan prosedur in_pcb_size dan Fungsi  print layout
//Update by Tamam
//Update by Amri

//Library
//#include "lib.h"
//#include "menu.h"
#include "layout_otomatis_lib.c"
#include "layout_manual_lib.c"
#include "routing_manual_lib.c"
#include "csv_load_save_lib.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max_string 20


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

int main() {
	int input;
	int isExit = 0;
	char nama[max_string];
	
	while (isExit == 0) {	
		menu_utama(&input);
		
		switch(input){
			case 1: //Buat Proyek Baru
				printf("\n====== Membuat Proyek Baru ======");
				printf("\nMasukkan nama proyek: ");
				scanf("%s",nama);
				newfile(nama);
				in_pcb_size(&n,&m);
				submenu(n,m,nama);
				break;
				
			case 2: // Muat Proyek dari Berkas
				printf("====== Memuat Proyek ======");
				printf("\nMasukkan nama proyek: ");
				scanf("%s",nama);
				in_pcb_size(&n,&m);
				submenu(n,m,nama);
				break;
				
			case 3: //Keluar
				isExit = keluar("Keluar...");
				break;
		}
		printf("\n\n\n");
	}
	
	return 0;
}

void menu_utama(int * in) {
	print_menu_utama();
	*in = input_validation("Masukan: ",1,3);
}

void submenu(int n, int m, char *nama) {
	int input;
	int isExit = 0;
	load_layout(nama);
	load_routing(nama);
	while (isExit == 0) {
		//system("cls");
		print_sub_menu();
		input = input_validation("Pilih Mode: ",1,8);
		
		switch(input){
			case 1: //Tampilkan Layout
				printf("\n[Layout Rangkaian pada PCB Dot Matriks]\n");
				print_layout(n,m);
				break;
				
			case 2: // Layout Manual
				layout_manual();
				break;
				
			case 3: // Tampilkan Routing
				printf("\n[Routing Rangkaian pada PCB Dot Matriks]\n");
				print_routing(n,m);
				break;
				
			case 4: // Routing Manual
				printf("\n[Mode Routing]\n");
				routing_manual();
				break;
				
			case 5: // Layout Otomatis
				printf("\n[Mode Auto-Layout]\n");
				layout_otomatis();
				break;
				
			case 6: // Routing Otomatis
				//printf("\n[Mode Auto-Routing]\n"); 
				maintenance();
				break;
				
			case 7: //  Design Rule Checker
				//printf("\n[DRC]\n");
				maintenance();
				break;
				
			case 8: //Simpan Proyek dan Keluar
				save_layout(nama);
				save_routing(nama);
				isExit = keluar("Kembali...");
				break;
		}
	}
}

void print_menu_utama() {
	printf("Menu :\n");
	printf("\t1. Buat Proyek Baru\n");
	printf("\t2. Muat Proyek dari Berkas\n");
	printf("\t3. Keluar\n");
}

void print_sub_menu() {
	printf("\n\n [Menu Utama]\n");
	printf("Pilih Mode:\n");
	printf("\t1. Tampilkan Layout \n");
	printf("\t2. Layout Manual\n");
	printf("\t3. Tampilkan Routing \n");
	printf("\t4. Routing Manual \n");
	printf("\t5. Layout Otomatis\n");
	printf("\t6. Routing Otomatis \n");
	printf("\t7. Design Rule Checker \n");
	printf("\t8. Simpan Proyek dan Keluar \n");
}

/*Fungsi Print Layout */
void print_layout(int x, int y) {
	printf("\t");
    for(int a=1;a<=x;a++){
            printf("%d\t", (a));
        }
    printf("\n");
    for(int b=1;b<=y;b++){
        printf("%d\t",(b));
        for(int a=1;a<=x;a++){
            printf("%s\t", pcb_layout[a][b].nama);
        }
        printf("\n");
    }
}

void print_routing(int x, int y){
	printf("\t");
    for(int a=0;a<x;a++){
            printf("%d\t", (a+1));
        }
    printf("\n");
    for(int b=0;b<y;b++){
        printf("%d\t",(b+1));
        for(int a=0;a<x;a++){
            printf("%c\t", matriksPCB[a][b]);
        }
        printf("\n");
    }
}

/*Fungsi input dengan validasi range input dan pesan custom */
int input_validation(char * line, int range_bawah, int range_atas){
	int isValid = 0;
	int in;
	while (isValid == 0) {
		printf("%s",line);
		scanf("%d", &in);
		if (in >= range_bawah && in <=range_atas) {
			isValid = 1;
		} else {
			printf("Error! %d bukan input yang valid.\n",in);
		}
	}
	return in;
}

void in_pcb_size(int * n,int * m) {
	int valid_n = 0;
	int valid_m = 0;
	while (valid_n == 0 || valid_m == 0) {
		printf("\nMasukkan ukuran PCB NxM (N,M<=40): ");
		scanf("%d %d",n,m);
		if (*n > 0 && *n < 41) {
			valid_n = 1;
		} else {
			printf("Input N salah!");
			valid_n = 0;
		}	
		if (*m > 0 && *m < 41) {
			valid_m = 1;
		} else {
			printf("Input M salah!");
			 valid_m = 0;
		}
	}
	printf("Membuat PCB dengan ukuran %dx%d",*n,*m);
}

/*Fungsi keluar(mengubah validasi keluar menjadi 1) dengan pesan custom*/
int keluar(char * line) { 
	printf("%s",line);
	return 1;
}

void maintenance() {
	printf("\n==========================\n");
	printf("===Fitur Belum Tersedia===\n");
	printf("==========================\n");
}
