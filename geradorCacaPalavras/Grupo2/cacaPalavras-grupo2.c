#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	int pos;
	char letra;
} palavra;

void geraEsp(int *esq,int *dir,int *cim,int *baix,int *esq_cim,int *dir_cim,int *esq_baix,int *dir_baix,int *num,int *qtdC,int *qtdL,int *l,int *c,int *max,int *tamP, palavra *pal,int *start, char *p){

	int i = 0, j = 0, x = 0;

	*num = rand() % *max;
	*esq = *num % *qtdC + 1;
	*dir = *qtdC - *num % *qtdC;
	*cim = *num / *qtdC + 1;
	*baix = *qtdL - *cim + 1;
		
	*l = *num / *qtdC;
	*c = *num % *qtdC;
		
	if(*l > *c){ *esq_cim = *c +1;*dir_baix = *qtdL-*l;}
	if(*c > *l) {*esq_cim = *l +1;*dir_baix = *qtdC-*c;}
	if(*c == *l) {*esq_cim = *l + 1;*dir_baix = *qtdL-*l;}
	if(*l < *qtdC-*c)*dir_cim = *l +1;
	if(*l > *qtdC-*c)*dir_cim = *qtdC - *c ;
	if(*l == *qtdC-*c)*dir_cim = *qtdC - *c;
	if(*c > *qtdL-*l)*esq_baix = *qtdL-*l;
	if(*c < *qtdL-*l)*esq_baix = *c+1;
	if(*c == *qtdL-*l)*esq_baix = *qtdL-*l;

    for (i = *num; i > *num - *tamP; i--){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *esq = 0;
                }
            }

        }
        x++;
	}
    x = 0;
	for (i = *num; i < *num + *tamP; i++){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *dir = 0;
                }
            }

        }
        x++;
	}
    x = 0;
	for (i = *num; i >= *num % *qtdL; i = i - *qtdC){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *cim = 0;
                }
            }

        }
        x++;
    }
    x = 0;
    for (i = *num; i < *max; i = i + *qtdC){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *baix = 0;
                }
            }

        }
        x++;
    }
    x = 0;
	for (i = *num; i >= *num % *qtdL; i = i - *qtdC-1){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *esq_cim = 0;
                }
            }

        }
        x++;
    }
    x = 0;
	for (i = *num; i >= *num % *qtdL; i = i - *qtdC+1){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *dir_cim = 0;
                }
            }

        }
        x++;
    }
    x = 0;
	for (i = *num; i < *max; i = i + *qtdC-1){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *esq_baix = 0;
				}
            }

        }
        x++;
    }
	x = 0;
	for (i = *num; i < *max; i = i + *qtdC+1){
        for(j = 0;j<*start+1;j++){
            if(i == (pal+j)->pos){
                if((pal+j)->letra != *(p+x)){
                    *dir_baix = 0;
                }
            }
        }
    x++;
    }
    x = 0;	
		
	if (*esq < *tamP && *dir < *tamP && *cim < *tamP && *baix < *tamP && *esq_cim < *tamP && *dir_cim < *tamP && *esq_baix < *tamP && *dir_baix < *tamP) geraEsp(esq,dir,cim,baix,esq_cim,dir_cim,esq_baix,dir_baix,num,qtdC,qtdL,l,c,max,tamP,pal,start, p);
}

void coloca(int *esq,int *dir,int *cim,int *baix,int *esq_cim,int *dir_cim,int *esq_baix,int *dir_baix,int *num,int *qtdC,int *qtdL,int *max,int *tamP,char *b, char *p, palavra *pal, int *start){
		
	int i = 0, j=0;

    for(i = 0;i < *tamP;i++){
        (pal + *start + i)->letra = *(p+j);
		j++;
    }
	j = 0;

	while (j > -20){
		int aleat = rand() % 8;
		if (aleat == 0){
			if (*esq >= *tamP){
				for (i = *num; i > *num - *tamP; i--){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
				}
				j = 0;
				break;
			}
			if (*esq < *tamP)
				aleat = rand() % 8;
		}
		if (aleat == 1){
			if (*dir >= *tamP){
				for (i = *num; i < *num + *tamP; i++){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
				}
				j = 0;
				break;
			}
			if (*dir < *tamP)
				aleat = rand() % 8;
		}
		if (aleat == 2){
			if (*cim >= *tamP){
				for (i = *num; i >= *num % *qtdL; i = i - *qtdC){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
					if (j == *tamP) break;
				}
				j = 0;
				break;
			}
			if (*cim < *tamP)
				aleat = rand() % 8;
		}
		if (aleat == 3){
			if (*baix >= *tamP){
				for (i = *num; i < *max; i = i + *qtdC){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
					if (j == *tamP) break;
				}
				j = 0;
				break;
			}
			if (*baix < *tamP)
				aleat = rand() % 8;
		}
		if(aleat == 4){
			if (*esq_cim >= *tamP){
				for (i = *num; i >= *num % *qtdL; i = i - *qtdC-1){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
					if (j == *tamP) break;
				}
				j = 0;
				break;
			}
			if (*esq_cim < *tamP)
				aleat = rand() % 8;
		}
		if(aleat == 5){
			if (*dir_cim >= *tamP){
				for (i = *num; i >= *num % *qtdL; i = i - *qtdC+1){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
					if (j == *tamP) break;
				}
				j = 0;
				break;
			}
			if (*dir_cim < *tamP)
				aleat = rand() % 8;
		}
		if(aleat == 6){
			if (*esq_baix >= *tamP){
				for (i = *num; i < *max; i = i + *qtdC-1){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
					if (j == *tamP) break;
				}
				j = 0;
				break;
			}
			if (*esq_baix < *tamP)
				aleat = rand() % 8;
		}
		if(aleat == 7){
			if (*dir_baix >= *tamP){
				for (i = *num; i < *max; i = i + *qtdC+1){
					*(b+i) = *(p+j);

					(pal+ *start + j)->pos = i;

					j++;
					if (j == *tamP) break;
				}
				j = 0;
				break;
			}
			if (*dir_baix < *tamP)
				aleat = rand() % 8;
		}
	}
	*start = *start + *tamP;
}

int main(){
	
	srand(time(NULL));

	palavra pal[200];
	
	char p[20], *pa = p;
	int esq = 0, dir = 0, cim = 0, baix = 0, esq_cim = 0,dir_cim = 0,esq_baix = 0, dir_baix = 0;
	int qtdL, qtdC, i,j, tamP, num, l, c, start = 0;
	char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int ralf;
	
	FILE *arq = fopen("dados.txt","r");
	if(arq == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    fscanf(arq,"%d %d",&qtdL,&qtdC);
    int max = qtdL * qtdC;
    char b[max];
     
	for (i = 0; i < max; i++){
		ralf = rand() % 26;
		b[i] = alf[ralf];
	}
	
	while(!feof(arq)){
	fscanf(arq,"%s",pa);
	tamP = strlen(p);

    printf("\n%d\n",tamP);
    printf("\n%s\n",p);
	if(tamP > qtdL && tamP >qtdC) printf("\nPalavra invalida: %s",p);
	
	geraEsp(&esq,&dir,&cim,&baix,&esq_cim,&dir_cim,&esq_baix,&dir_baix,&num,&qtdC,&qtdL,&l,&c,&max,&tamP, &pal[0], &start, pa);
	coloca(&esq,&dir,&cim,&baix,&esq_cim,&dir_cim,&esq_baix,&dir_baix,&num,&qtdC,&qtdL,&max,&tamP,b,p, &pal[0], &start);
	}
	fclose(arq);
	
    FILE *file = fopen("caca_palavra.txt", "w");
    if(file == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for (i = 0; i < max; i++) 
    {
        fputc(toupper(b[i]), file);
        if ((i + 1) % qtdC == 0) {
            fputc('\n', file);
        }
        else {
            fputc(' ', file);
        }
    }

	for(i = 0; i<start;i++){
		printf("\nposicao: %d \n letra: %c\n", pal[i].pos, pal[i].letra);
	}
	int count = 0;

	for(i = 0; i<start;i++){
		for(j = 0; j<start;j++){
			if(pal[i].pos == pal[j].pos){
				count++;
				if(count >= 2) {
					printf("\n\nposicao em que palavras se cruzam: %d\n\n",pal[i].pos);
				}
			}
		}
		count = 0;
	}
    
    fclose(file);

	return 0;
}