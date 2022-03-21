#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int dados(int l){
	l = 1 + rand()%5;
    return l;
}

void prologo(void){
	printf("---SEJAM BEM VINDOS AO OLHO DE COBRA---\n");
	getchar();
	printf("O objetivo desse jogo eh acumular o total de 50 pontos\n");
	printf("disputados por 2 jogadores, o primeiro eh o vencedor!!\n");
	getchar();
	printf("Como sera feito?\n");
	getchar();
	printf("O jogo eh em turnos, em cada um o jogador tera a opcao\n");
	printf("de jogar os dados ou passar a vez e a soma dos valores\n");
	printf("desses dados sera adicionado ao valor total do jogador\n");
	printf("Porem, se em um dado cair o numero 1 ele perde o total\n");
	printf("de pontos do turno, se ambos dados cairem em 1 o total\n");
	printf("de pontos acumulados durante o jogo eh zerado.\n");
	getchar();
	printf("Boa sorte!\n");
	getchar();
	system("cls");
}

int main(void){
	char jg1[20];
	char jg2[20];
	int l=0;
	int vez;
	int turno=0;
	int j1,j2,opcao =0;
	int pts1=0,pts2=0;
	srand(time(NULL));
	
	prologo();//função para imprimir as instruções do jogo
	
	printf("Jogador 1:\n");
	scanf("%s",jg1);	
	printf("Jogador 2:\n");
	scanf("%s",jg2);
	
	printf("Os dados serao jogados para decidir quem ira comecar!\n");
	getchar();
	printf("De 1 a 3, %s vence, de 4 a 6, %s vence\n",jg1,jg2);
	getchar();
	l = dados(l);
	printf("%d\n",l);
	if(l<4){
		vez = 1;
		printf("%s joga primeiro\n",jg1);
	}else{
		vez = 2;
		printf("%s joga primeiro\n",jg2);
	}
	
	while(opcao!=3){
		if(vez==1){
			printf("Vez de %s\n",jg1);
		}else{
			printf("Vez de %s\n",jg2);
		}
		printf("1-Jogar?\n");
		printf("2-Finalizar turno?\n");
		scanf("%d",&opcao);
		switch(opcao){
		case 1:{
			j1 = dados(l);
			printf("Dado 1:%d\n",j1);
			getchar();
			j2 = dados(l);
	   	   	printf("Dado 2:%d\n",j2);
	   	   	getchar();
	   	   	if(j1<2 && j2<2){
	   	   		    if(vez==1){
  		   	 	   	    vez = 2;
						printf("%s perdeu seu total de pontos\n",jg1);
  				  	    pts1 = 0;
					}else if(vez==2){
						vez = 1;
						printf("%s perdeu seu total de pontos\n",jg2);
		   				  pts2 = 0;
					}	    
			}else if(j1<2||j2<2){
				    if(vez==1){
				    	vez = 2;
						printf("%s perdeu sua vez e nao pontuou\n",jg1);
			  			turno = 0;
					}else if(vez==2){
						vez = 1;
						printf("%s perdeu sua vez e nao pontuou\n",jg2);
			  			turno = 0;
					}
			}else{
				if(vez==1){
					turno += (j1+j2);
					if((turno+pts1)<50){
						printf("Total de pontos %s:%d\n",jg1,pts1);
						printf("%s pontua + %d\n",jg1,turno);
					}else{
						printf("%s ganhou o jogo!!!\n",jg1);
						opcao = 3;
					}	
 	   			}else if(vez==2){
 	   				if((turno+pts2)<50){
						turno += (j1+j2);
 	   					printf("%s pontua + %d\n",jg2,turno);
						printf("Total de pontos %s:%d\n",jg2,pts2);	
					}else{
						printf("%s ganhou o jogo!!!\n",jg2);
						opcao = 3;
						}
 	   				
			}	
			}
			break;
  	    }
  	    
		case 2:
			if(vez==1){
				pts1 += turno;
				vez = 2;
			}else{
				pts2 += turno;
				vez = 1;
			}
			turno = 0;
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}

