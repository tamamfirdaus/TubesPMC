#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "layout_otomatis_lib.h"


#define jarak_min_R 3
#define jarak_min_C 1
#define jarak_min_T 1
#define jarak_min_J 0



//Variabel Global
grid_t pcb_layout[40][40];
int n,m;


//Implementasi procedure
void layout_otomatis(){
    komponen_t komponen_layout_otomatis[10];
    char *temp;
    char komponen_list[100];
    int i=0;
    int jumlah_komponen=0;
    char cek_tambah_komponen[10];

    printf("Masukkan Komponen-komponen yang akan digunakan:");
    scanf(" %[^\n]%*c", komponen_list);
    temp=strtok(komponen_list," ");
    while(temp!=NULL){
        strcpy(komponen_layout_otomatis[i].nama,temp);
        printf("%s\n", komponen_layout_otomatis[i].nama);
        temp=strtok(NULL," ");
        i++;
    }
    jumlah_komponen=i;
    printf("Jumlah komponen yang digunakan: %d\n", jumlah_komponen);
    printf("Apakaah ingin menambah jumlah komponen lagi? (YA/TIDAK)");
    scanf(" %[^\n]%*c", cek_tambah_komponen);
    while(strcmp(cek_tambah_komponen,"YA")==0){
        printf("Masukkan Komponen-komponen yang akan digunakan:");
        scanf(" %[^\n]%*c", komponen_list);
        temp=strtok(komponen_list," ");
        i=jumlah_komponen;
        while(temp!=NULL){
            strcpy(komponen_layout_otomatis[i].nama,temp);
            printf("%s\n", komponen_layout_otomatis[i].nama);
            temp=strtok(NULL," ");
            i++;
        }
        jumlah_komponen=i;
        printf("Jumlah komponen yang digunakan: %d\n", jumlah_komponen);
        printf("Apakaah ingin menambah jumlah komponen lagi? (YA/TIDAK)");
        scanf(" %[^\n]%*c", cek_tambah_komponen);
    }

    printf("%d\n",jumlah_komponen);
    //Algoritma Layout Otomatis
    int grid_x=0;
    int grid_y=0;
    for(int j=0;j<jumlah_komponen;j++){
        if(komponen_layout_otomatis[j].nama[0]=='T'){
            komponen_layout_otomatis[j].kaki_1.x=grid_x;
            komponen_layout_otomatis[j].kaki_1.y=grid_y;
            grid_y+=jarak_min_T;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            komponen_layout_otomatis[j].kaki_2.x=grid_x;
            komponen_layout_otomatis[j].kaki_2.y=grid_y;
            grid_y+=jarak_min_T;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            komponen_layout_otomatis[j].kaki_3.x=grid_x;
            komponen_layout_otomatis[j].kaki_3.y=grid_y;
            grid_y+=jarak_min_T;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_1.x][komponen_layout_otomatis[j].kaki_1.y].nama,komponen_layout_otomatis[j].nama);
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_2.x][komponen_layout_otomatis[j].kaki_2.y].nama,komponen_layout_otomatis[j].nama);
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_3.x][komponen_layout_otomatis[j].kaki_3.y].nama,komponen_layout_otomatis[j].nama);
            grid_y+=2;
        }else if(komponen_layout_otomatis[j].nama[0]=='R'){
            komponen_layout_otomatis[j].kaki_1.x=grid_x;
            komponen_layout_otomatis[j].kaki_1.y=grid_y;
            grid_y+=jarak_min_R;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            komponen_layout_otomatis[j].kaki_2.x=grid_x;
            komponen_layout_otomatis[j].kaki_2.y=grid_y;
            grid_y+=jarak_min_R;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_1.x][komponen_layout_otomatis[j].kaki_1.y].nama,komponen_layout_otomatis[j].nama);
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_2.x][komponen_layout_otomatis[j].kaki_2.y].nama,komponen_layout_otomatis[j].nama);
            grid_y+=2;
        }else if(komponen_layout_otomatis[j].nama[0]=='C'){
            komponen_layout_otomatis[j].kaki_1.x=grid_x;
            komponen_layout_otomatis[j].kaki_1.y=grid_y;
            grid_y+=jarak_min_C;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            komponen_layout_otomatis[j].kaki_2.x=grid_x;
            komponen_layout_otomatis[j].kaki_2.y=grid_y;
            grid_y+=jarak_min_C;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_1.x][komponen_layout_otomatis[j].kaki_1.y].nama,komponen_layout_otomatis[j].nama);
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_2.x][komponen_layout_otomatis[j].kaki_2.y].nama,komponen_layout_otomatis[j].nama);
            grid_y+=2;
        }else if(komponen_layout_otomatis[j].nama[0]=='J'){
            komponen_layout_otomatis[j].kaki_1.x=grid_x;
            komponen_layout_otomatis[j].kaki_1.y=grid_y;
            grid_y+=jarak_min_C;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            komponen_layout_otomatis[j].kaki_2.x=grid_x;
            komponen_layout_otomatis[j].kaki_2.y=grid_y;
            grid_y+=jarak_min_C;
            if(grid_y>(m-1)){
                grid_y=0;
                grid_x+=2;
            }
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_1.x][komponen_layout_otomatis[j].kaki_1.y].nama,komponen_layout_otomatis[j].nama);
            strcpy(pcb_layout[komponen_layout_otomatis[j].kaki_2.x][komponen_layout_otomatis[j].kaki_2.y].nama,komponen_layout_otomatis[j].nama);
            grid_y+=2;
        }
    }

    //Tampilakn layout
    printf("   ");
    for(int a=0;a<n;a++){
            printf("%2d ", (a+1));
        }
    printf("\n");
    for(int b=0;b<m;b++){
        printf("%d  ",(b+1));
        for(int a=0;a<n;a++){
            printf("%s ", pcb_layout[a][b].nama);
        }
        printf("\n");
    }
}