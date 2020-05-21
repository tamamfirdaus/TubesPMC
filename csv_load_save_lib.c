//***********************************************************//
// 								[ Source Code]
// 
// Institution : Institut Teknologi Bandung 
// Name : Moh. Tamamul Firdaus
// File Name : main.c 
// Dependency : lib.h
// // Description: 
// file 
// 
// Status: 
// 1. Moh. Tamamul Firdaus - 13217062 : Create the file 
//2. Andi Muhammad Riyadhus Ilmy - 13217053 : add newfile function dan strcat
//***********************************************************//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_load_save_lib.h"
#define max_string 20


void load_layout(char *filename){
    FILE *file;
    strcat(filename,"_layout.csv");
	file = fopen(filename, "r");
    if (!file){
		printf("File belum ada!");
    } else {
		int i=0;
		char line[4098];
		int row=40;

		while (fgets(line, 4098, file) && (i < row)){
			char* tmp = strdup(line);
			int j = 0;
			const char* tok;
			for (tok = strtok(line, ";"); tok && *tok; j++, tok = strtok(NULL, ";\n"))
			{
				strcpy(pcb_layout[i][j].nama,tok);
				printf("%s\t", pcb_layout[i][j].nama);
			}
			printf("\n");

			free(tmp);
			i++;
		}
	}
}

void load_routing(char *filename){
	FILE *file;
	strcat(filename,"_routing.csv");
	file = fopen(filename, "r");
    if (!file){
		printf("File belum ada!");
		
    } else {
		int i=0;
		char line[4098];
		int row=40;

		while (fgets(line, 4098, file) && (i < row)){
			char* tmp = strdup(line);
			int j = 0;
			const char* tok;
			for (tok = strtok(line, ";"); tok && *tok; j++, tok = strtok(NULL, ";\n"))
			{
				matriksPCB[i][j]=*tok;
				printf("%c\t", matriksPCB[i][j]);
			}
			printf("\n");

			free(tmp);
			i++;
		}
	}
}

void save_layout(char *filename){
    FILE *fp;
    strcat(filename,"_layout.csv");
    fp=fopen(filename,"w+");

	for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            fprintf(fp,"%s;",pcb_layout[i][j].nama);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}

void save_routing(char *filename){
    FILE *fp;
    strcat(filename,"_routing.csv");
    fp=fopen(filename,"w+");

    strcpy(pcb_layout[1][1].nama,"DE");
	for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            fprintf(fp,"%c;",matriksPCB[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}

void newfile(char *nama){
	char copy1[max_string], copy2[max_string], temp[max_string];
	strcpy(copy1,nama);
	strcpy(copy2,nama);
	strcpy(temp,nama);
	strcat(temp,"_layout.csv");
	FILE *in=fopen(temp,"r");
	if(!in){  //cek apakah filenya ada atau tidak
	   strcat(copy1,"_layout.csv");
	   strcat(copy2,"_routing.csv");
	   FILE *new1=fopen(copy1,"w");
	   fclose(new1);
	   FILE *new2=fopen(copy2,"w");
	   fclose(new2);
	}else{
	   printf("File dengan nama yang sama sudah ada!");
	   fclose(in);
	}
}
