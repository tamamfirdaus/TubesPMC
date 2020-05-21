#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include "layout_manual_lib.h"

#define syaratR 3
#define syaratCT 1
#define syaratJ 0

//fungsi 
int cekKoordinat2 (int x1, int x2, int y1, int y2) {
	if((x1==x2) || (y1==y2)){
		return 1;
	} else {
		return 0;
	}
}

int cekRC(int x1, int x2, int y1, int y2, int syarat){
	float abs1, abs2;
	abs1 = abs(x1-x2);
	abs2 = abs(y1-y2);
	if((abs1>syarat) || (abs2>syarat)){
		return 1;
	} else {
		return 0;
	}
}

int cekT(int x1, int x2,int x3, int y1, int y2, int y3, int syarat){
	if(((abs(x1-x2)>syarat)||(abs(y1-y2)>syarat)) && ((abs(x1-x3)>syarat) || (abs(y1-y3)>syarat)) && ((abs(x3-x2)>syarat) || (abs(y3-y2)>syarat))){
		return 1;
	} else {
		return 0;
	}
}

int cekPCB(int x, int y, int N, int M){
	if ((x>=1) && (x<=N) && (y>=1) && (y<=M)){
		return 1;
	}  else {
		return 0;
	}
}

void layout_manual() {
	char komponen[10];
	int x1, x2,x3,y1,y2,y3,i,c,d;
	char cekKomp[40][10];
	int x =0;
	int sum = 0;
	int cek;
	printf("[Mode Layout]\n"); 
	printf("Isi q atau Q untuk kembali ke menu \n"); 
	
	while (strcmp(komponen,"Q") && strcmp(komponen,"q")) {
		printf("Pilih Komponen (R,C,T,J) : ");scanf("%s", komponen);
		if((strcmp(komponen,"Q")) && (strcmp(komponen,"q"))){
			while(!strcmp(cekKomp[i], komponen)){
			printf("Pilih Komponen (R,C,T,J) : ");scanf("%s", komponen);
			}
			for (i=0; i<= x; i++){
				if(strcmp(cekKomp[i], komponen)){
					sum = sum;
				}else{
					printf("Input komponen sudah ada");
					sum = sum +1;
				}
			}
			if (sum == 0){
				if (komponen[0] == 'J'){
					printf("Koordinat Kaki 1 : ");
					scanf("%d,%d", &x1, &y1);
					cek = cekPCB(x1,y1,n,m);
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 1 : ");
						scanf("%d,%d", &x1, &y1);
						cek = cekPCB(x1,y1,n,m);
					}
					printf("Koordinat Kaki 2 : ");
					scanf("%d,%d", &x2, &y2);
					cek = ((cekPCB(x2,y2,n,m))&& (cekKoordinat2(x1,x2,y1,y2)));
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
						cek = ((cekPCB(x2,y2,n,m))&& (cekKoordinat2(x1,x2,y1,y2)));
					}
					cek = cekRC(x1, x2,y1,y2, syaratJ);
					if(cek == 1){
						strcpy(pcb_layout[x1][y1].nama,komponen);
						strcpy(pcb_layout[x2][y2].nama,komponen);
						for (c = 0; c <= n; c++) {
							printf("%d", c);
							for (d = 0 ; d <= m; d++) {
								if(c == 0 && d == 0){
								printf("\t");
								}else{
									if(c==0){
										printf("%d\t", d);
									}else{
										printf("%s\t", pcb_layout[c][d].nama);
									}
								}
							}     
							printf("\n");
						}
						strcpy(cekKomp[i],komponen);
						x = x+1;
					}else{
						printf("Input Koordinat Salah");
					}
				}
				else if(komponen[0] == 'R')
				{
					printf("Koordinat Kaki 1 : ");scanf("%d,%d", &x1, &y1);
					cek = cekPCB(x1,y1,n,m);
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 1 : ");scanf("%d,%d", &x1, &y1);
						cek = cekPCB(x1,y1,n,m);
					}
					printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
					cek = ((cekPCB(x2,y2,n,m))&& (cekKoordinat2(x1,x2,y1,y2)));
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
						cek = ((cekPCB(x2,y2,n,m))&& (cekKoordinat2(x1,x2,y1,y2)));
					}
					cek = cekRC(x1, x2,y1,y2, syaratR);
					if(cek == 1){
						strcpy(pcb_layout[x1][y1].nama,komponen);
						strcpy(pcb_layout[x2][y2].nama,komponen);
						for (c = 0; c <= n; c++) {
							printf("%d", c);
							for (d = 0 ; d <= m; d++) {
								if(c == 0 && d == 0){
									printf("\t");
								}else{
									if(c==0){
										printf("%d\t", d);
									}else{
										printf("%s\t", pcb_layout[c][d].nama);
									}
								}
							}     
							printf("\n");
						}
						strcpy(cekKomp[i],komponen);
						x = x+1;
					}else{
						printf("Koordinat kaki salah\n");
					}
				}
				else if(komponen[0] == 'C')
				{
					printf("Koordinat Kaki 1 : ");scanf("%d,%d", &x1, &y1);
					cek = cekPCB(x1,y1,n,m);
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 1 : ");scanf("%d,%d", &x1, &y1);
						cek = cekPCB(x1,y1,n,m);
					}
						printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
						cek = ((cekPCB(x2,y2,n,m))&& (cekKoordinat2(x1,x2,y1,y2)));
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
						cek = ((cekPCB(x2,y2,n,m))&& (cekKoordinat2(x1,x2,y1,y2)));
					}
					cek = cekRC(x1, x2,y1,y2, syaratCT);
					if(cek == 1){
						strcpy(pcb_layout[x1][y1].nama,komponen);
						strcpy(pcb_layout[x2][y2].nama,komponen);
						for (c = 0; c <= n; c++) {
						printf("%d", c);
						for (d = 0 ; d <= m; d++) {
							if(c == 0 && d == 0){
								printf("\t");
							}else{
								if(c==0){
								printf("%d\t", d);
								}else{
								printf("%s\t", pcb_layout[c][d].nama);
								}
							}
						}
						printf("\n");
						}
						strcpy(cekKomp[i],komponen);
						x = x+1;
					}else {
						printf("Koordinat kaki salah");
					}
				}
				else if(komponen[0] == 'T')
				{
					printf("Koordinat Kaki 1 : ");scanf("%d,%d", &x1, &y1);
					cek = cekPCB(x1,y1,n,m);
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 1 : ");scanf("%d,%d", &x1, &y1);
						cek = cekPCB(x1,y1,n,m);
					}
					printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
					cek = cekPCB(x2,y2,n,m);
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 2 : ");scanf("%d,%d", &x2, &y2);
						cek = cekPCB(x2,y2,n,m);
					}
					printf("Koordinat Kaki 3 : ");scanf("%d,%d", &x3, &y3);
					cek = cekPCB(x3,y3,n,m);
					while (cek!=1){
						printf("input salah\n");
						printf("Koordinat Kaki 3 : ");scanf("%d,%d", &x3, &y3);
						cek = cekPCB(x3,y3,n,m);
					}
					cek = cekT(x1, x2,x3, y1,y2,y3, syaratCT);
					if(cek == 1){
						strcpy(pcb_layout[x1][y1].nama,"Te");
						strcpy(pcb_layout[x2][y2].nama,"Tb");
						strcpy(pcb_layout[x3][y3].nama,"Tc");
						for (c = 0; c <= n; c++) {
							printf("%d", c);
							for (d = 0 ; d <= m; d++) {
								if(c == 0 && d == 0){
									printf("\t");
								}else{
									if(c==0){
										printf("%d\t", d);
									}else{
										printf("%s\t", pcb_layout[c][d].nama);
									}
								}
							}
							printf("\n");
						}
						strcpy(cekKomp[i],komponen);
						x = x+1;
					}else {printf("Koordinat kaki salah");}
				} else {
					printf("komponen tidak ada");
				}
			} else {       //komponen sudah ada
				x = x;
				sum = 0;
				printf("Komponen sudah ada\n");
			}
			printf("\n");
		}
	}
	printf("quit");	
}
	
