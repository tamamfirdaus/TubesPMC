#include <stdio.h>
#include <string.h>
typedef struct drc_komp{
	char nama[40];
	char kaki1[40];
	char kaki2[40];
}drc_t;
drc_t DRC[40];

typedef struct grid{
	char nama[40];
	char node[40];
}grid_t;
grid_t pcb_layout[40][40];

 struct point {
        int x,y;
    };
	struct point koordinat[40][40];
	
typedef struct koor_komp{
	int x1;
	int y1;
	int x2;
	int y2;
}koor_t;

koor_t koor[50];
 
int main () {
	char node1[40] = "GND";		//char yg harus dibandingkan
	char node2[40] = "Vin";		//char yg harus dibandingkan
	char nama_file[30];
	FILE *fp;
	int sum;
	printf("Masukkan nama file : ");
	scanf(" %[^\n]s", nama_file);
	fp = fopen(nama_file,"r");
	int jml_komp=1;
	int count=0;
	char array[40][40][20];		//array layout = pcb_layout.nama
	char key[20];
	int x[50];
	int y[50];
	int a =1;
    int i,j,c, d,N,M;
	while(!feof(fp)){
	fscanf(fp, "%s" ,DRC[jml_komp].nama);
	fscanf(fp, "%s" ,DRC[jml_komp].kaki1);
	fscanf(fp, "%s" ,DRC[jml_komp].kaki2);
      printf("%s %s %s ", DRC[jml_komp].nama, DRC[jml_komp].kaki1, DRC[jml_komp].kaki2);
	  jml_komp = jml_komp+1;
	  printf("\n");
  }
	//coba pake input matriks baru
        printf("Enter the size of an array (M,N) \n");
        scanf("%d,%d", &M, &N);
 
        printf("Enter the array elements\n");
        for (i = 1; i < M+1; i++) {
			for (j = 1; j < N+1; j++) {
            scanf("%s", &array[i][j]);
			}printf("\n");
		}
		
		for (i = 1; i < M+1; i++) {
			for (j = 1; j < N+1; j++) {
            printf("%s\t", &array[i][j]);
			}
			printf("\n");
		}
      //  printf("Enter the key\n");
       // scanf("%s", &key);		//nama komponen yang dicari
	       
		/*for (i = 1; i < M+1; i++) {
			for (j = 1; j < N+1; j++) {
				if (strcmp(array[i][j],key)==0){
				printf("Found %s\n",array[i][j]);
				x1[a] = i;
				y1[a] = j;
				printf("%d,%d\n",x1[a],y1[a]);
				a = a+1;
				}
			}
		}*/
		//searching koordinat
		int k=0;
		while(k< jml_komp-1){
		for (i = 1; i <= M; i++) {
			for (j = 1 ; j <= N; j++) {
				//cari koordinat kaki1 komponen
				printf(" %s\n", DRC[k].nama);
				if(strcmp((array[i][j]),(DRC[k].nama)) ){			
				count = count+1;	
				printf("Found %s\n",array[i][j]);
				koor[k].x1 = i;
				koor[k].y1 = j;
				printf("%d,%d\n",koor[k].x1,koor[k].y1);
				strcpy(array[koor[k].x1][koor[k].y1],"done");				//supaya tidak dicek lagi
				//cari koordinat kaki2 komponen
				for (c = i+1 ; c <= M; c++) {
					for (d = j ; d <= N; d++) {
						printf(DRC[k].nama, "\n");
						if((strcmp((array[c][d]),(DRC[k].nama))) ){			
						count = count+1;	//cek nama komponen ke variabel node 1
						printf("Found %s\n",array[c][d]);
						koor[k].x2 = c;
						koor[k].y2 = d;
						printf("%d,%d\n",koor[k].x2,koor[k].y2);
						strcpy(array[koor[k].x2][koor[k].y2],"done");		//supaya tidak dicek lagi
						k= k+1;
						}else {
						count = count;}
					}
				}if (count == 2){
					printf("benar");
					sum = sum+1;}
				else {
					printf("salah");
					sum = sum;}
					count =0;
				}else {count = count;}

			}
		}
		
		
		printf("%d\n",count);
		
  	printf("%d/%d", sum, jml_komp-1);printf(" Rule is checked\n");

	  fclose(fp);
   return(0);
		}
}