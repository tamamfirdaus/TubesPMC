#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include "routing_manual_lib.h"


void routing_manual(){
    //Deklarasi variable
    int i=0, j=0, k=0, l=0, IndKoma, InKoorLength;
    char simbol[160];
    char InKoor[5],s1[2],s2[2];
    koordinat_t koordinat_routing[40][40];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){           
            matriksPCB[j][i]=' ';
        }
    }

    i=0;
    printf("[Mode Routing]\n");
    printf("Isi `q` atau `Q` untuk kembali ke menu\n");
    printf("Isi `n` atau `N` untuk memulai pada simpul (node) baru\n");
    simbol[i]='a';

    //Ngebaca simbolll
    //Kalo simbol salah baca lagi
    InKoor[0]='a';
    do{
        j=0;
        do{
            printf("Pilih Simbol (! , @ , #, $ , % , ^ , & , * , ( , ) ): ");
            scanf(" %c", &simbol[i]);
        }
        while (!(  simbol[i] == '!' ||
            simbol[i] == '@' ||
            simbol[i] == '#' ||
            simbol[i] == '$' ||
            simbol[i] == '%' ||
            simbol[i] == '^' ||
            simbol[i] == '&' ||
            simbol[i] == '*' ||
            simbol[i] == ',' ||
            simbol[i] == 'n' ||
            simbol[i] == 'N' ||
            simbol[i] == 'q' ||
            simbol[i] == 'Q'     ));

            // //Tes hasil simbol
            // printf("hasil %c\n",simbol[i]);
            // //

            //Ngebaca koordinat_routing
            do{
            printf("Koordinat %d: ", (j+1));
            scanf(" %s", InKoor);
                    InKoorLength=strlen(InKoor);
                    if (InKoorLength!=1){
                    // mengubah string menjadi integer
                    for (l = 0; InKoor[l] != ','; ++l) {
                        // copying the characters by
                        // character to str2 from str1
                        s1[l] = InKoor[l];
                        IndKoma=l;
                    }
                    s1[IndKoma+1] = '\0';
                     for (l = (IndKoma+2); InKoor[l] != '\0'; ++l) {
                        // copying the characters by
                        // character to str2 from str1
                        s2[k] = InKoor[l];
                        k=k+1;
                    }
                    s2[k] = '\0';
                    k=0;
                    // printing the destination string
                    // printf("String s1 : %s\n", s1);
                    // printf("String s2 : %s\n", s2);

                    koordinat_routing[i][j].x= atoi(s1)-1;
                    koordinat_routing[i][j].y= atoi(s2)-1;

                    matriksPCB[koordinat_routing[i][j].x][koordinat_routing[i][j].y] = simbol[i];

                    // printf("koordinat x [%d][%d] : %d\n", (i+1), (j+1), koordinat_routing[i][j].x);
                    // printf("koordinat y [%d][%d] : %d\n", (i+1), (j+1), koordinat_routing[i][j].y);
                    }

            j=j+1;
            if (InKoor[0]=='n' || InKoor[0]=='N' ){
            i=i+1;
            }

        }
        while (!(InKoor[0]=='n' || InKoor[0]=='N' || InKoor[0]=='q' || InKoor[0]=='Q'));

   }
   while(!(InKoor[0]=='q' || InKoor[0]=='Q'));
   i=0;j=0;
                //Buat matriks
                j=0;i=0;
                printf("\t");
                for(j=0;j<n;j++){
                printf("%d ", (j+1));
                }
                printf("\n");
                for(i=0;i<m;i++){
                    printf("%d ", (i+1));
                    for(j=0;j<n;j++){
                        printf("%c ", matriksPCB[j][i]);
                    }
                printf("\n");
                }

}
