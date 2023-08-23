#include <stdio.h>
#include <stdlib.h>

int main (){
 //inicializa��o das vari�veis
int tabjogador1[10][10], tabjogador2[10][10];
int naviosjog1,naviosjog2,numatq;
int tamnavio=0,coordx=0,coordy=0,contadorEsp1=0,contadorEsp2=0,contadordebarcosrestantes1=0,contadordebarcosrestantes2=0,numero_especiais1=5,numero_especiais2=5;
char orientacao,tipoataque1,tipoataque2,n,e,v,h;


//inicializa as matrizes
for (int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        tabjogador1[i][j]=0;
        tabjogador2[i][j]=0;
    }
}

    // inicia os navios do jogador 1
scanf("%d",&naviosjog1);// l� o numero de navios do jogador 1
    for(int a=1;a<=naviosjog1;a++){//cria um loop que vai rodar enquanto o numero de navios n�o for atingido
        scanf("%d %c %d %d",&tamnavio,&orientacao,&coordx,&coordy);//l� o tamanho,orienta��o e as coordenadas dos navios

        switch(orientacao){
                case 'h': // roda esse trecho caso o usu�rio insira um navio na horizontal

                    for (int c=0;c<tamnavio;c++){// cria um loop que cria os navios na matriz
                        tabjogador1[coordx][coordy]=1;
                        coordy++;
                        if(coordy>9){ // caso o navio chegue na extremidade do tabuleiro recome�a da posi��o 0 da linha
                            coordy = 0;
                        }
                   }
                break;

                case 'v':
                    for(int c=0;c<tamnavio;c++){// cria um loop que cria os navios na matriz
                        tabjogador1[coordx][coordy]=1;
                        coordx++;
                            if(coordx>9){ // caso o navio chegue na extremidade do tabuleiro recome�a da posi��o 0 da coluna
                                coordx=0;
                            }
                    }
                break;

        }
    }

   // inicia os navios do jogador 2
scanf("%d",&naviosjog2);// l� o numero de navios do jogador 2
for(int a=1;a<=naviosjog2;a++){//cria um loop que vai rodar enquanto o numero de navios n�o for atingido
    scanf("%d %c %d %d",&tamnavio,&orientacao,&coordx,&coordy);//l� o tamanho,orienta��o e as coordenadas dos navios

        switch(orientacao){
            case 'h': // roda esse trecho caso o usu�rio insira um navio na horizontal
                for(int c=0;c<tamnavio;c++){// cria um loop que cria os navios na matriz
                    tabjogador2[coordx][coordy]=1;
                    coordy++;
                        if(coordy>9){  // caso o navio chegue na extremidade do tabuleiro recome�a da posi��o 0 da linha
                            coordy = 0;
                        }
                }
            break;

            case 'v':
                for(int c=0;c<tamnavio;c++){// cria um loop que cria os navios na matriz
                    tabjogador2[coordx][coordy]=1;
                    coordx++;
                        if(coordx>9){ // caso o navio chegue na extremidade do tabuleiro recome�a da posi��o 0 da coluna
                            coordx=0;
                        }
                }
            break;

        }
}

    //inicia os ataques
int rodada=1;

scanf("%d",&numatq);//le o numero de ataques da rodada
for(int ataques=1;ataques<=numatq;ataques++){//cria um loop para que o programa rode de acordo com a quantidade de ataques

int x=0,y;//inicializa as variaveis que ser�o usadas para as coordenadas dos ataques

    if(ataques%2!=0){ //condi��o para o jogador 1 sempre ser o primeiro
        scanf(" %c ", &tipoataque1);//le o tipo de ataque
            switch(tipoataque1){
                case 'n'://condi��o se o ataque for normal
                    scanf("%d %d",&x,&y);// le as coordenadas do ataque

                    if(tabjogador2[x][y]==1){
                        contadorEsp1++; // verifica se o jogagor acertou e incrementa o contador de acertos seguidos
                    }
                    else if(tabjogador2[x][y]==0){
                    contadorEsp1=0; // condi��o para zerar o contador de acertos caso o jogador erre
                    }

                    tabjogador2[x][y]=0;// zera as coordenadas dadas
                break;

                case 'e'://condi��o se o ataque for especial
                    scanf(" %c ", &orientacao); // le a orienta��o do ataque especial
                    scanf("%d",&y); // le a coordenada do ataque
                        if(numero_especiais1>=1 && numero_especiais1 <=5){ // avalia se o jogador ainda tem ataques especiais
                            if(contadorEsp1>=2){ // condi��es para que o ataque especial seja executado
                                // se o jogador tiver acertado dois ou mais ataques consecutivos, executa essa parte
                                if(orientacao=='v'){
                                    for(int x=0;x<10;x++){ //zera a coluna escolhida
                                    tabjogador2[x][y]=0;
                                    }
                                }
                                else if(orientacao=='h'){ // zera a linha escolhida
                                    for(int x=0;x<10;x++){
                                    tabjogador2[y][x]=0;
                                    }
                                }
                                contadorEsp1=0; // zera o contador de especiais ap�s ele ser usado
                                numero_especiais1--; // diminui o numero de especiais restantes ap�s seu uso
                            }

                                else{ // condi��o caso o jogador solicite ataque especial sem ter feito dois ou mais acertos consecutivos
                                    contadorEsp1=0; // zera o contador caso o ataque especial seja feito indevidamente
                                }
                        }
                break;
            }
    }
        // vez do jogador 2
    else {
        scanf(" %c ", &tipoataque2); // le o tipo de ataque do jogador 2

        switch(tipoataque2){
            case 'n': // caso o ataque seja normal...
                scanf("%d %d",&x,&y);// le as coordenadas do ataque normal
                    if(tabjogador1[x][y]==1){ //se o jogador acertar um navio, o contador � incrementado
                        contadorEsp2++;
                    }
                    else if(tabjogador1[x][y]==0){ // se o jogador errar um navio, o contador � zerado
                        contadorEsp2=0;
                    }
                tabjogador1[x][y]=0; // zera a posi��o escolhida
            break;

            case 'e'://condi��o se o ataque for especial
                scanf(" %c ", &orientacao); // le a orienta��o do ataque especial
                scanf("%d",&y); // le a coordenada do ataque

                if(numero_especiais2>=1 && numero_especiais2 <=5){ // avalia se o jogador ainda tem ataques especiais disponiveis
                    if(contadorEsp2>=2){ // avalia se o jogaodor acertou pelo menos duas jogadas consecutivas

                        if(orientacao=='v'){
                            for(int x=0;x<10;x++){ // zera a coluna escolhida
                                tabjogador1[x][y]=0;
                            }
                        }
                        else if(orientacao=='h'){
                            for(int x=0;x<10;x++){ // zera a linha escolhida
                                tabjogador1[y][x]=0;
                            }
                        }
                        contadorEsp2=0; // zera o contador de acertos seguidos
                        numero_especiais2--; // diminui o numero de especiais restantes
                    }
                    else{ // executa se o jogador n�o tiver acertado pelo menos dois ataques consecutivos
                        contadorEsp2=0;  // zera o contador de acertos seguidos
                    }
                }

            break;
        }
    } //fim dos ataques
    rodada++; // incrementa a rodada
}

//impress�o dos tabuleiros dos jogadores

// tabuleiro jogador 1
printf("  |");
for (int j = 0; j < 10; j++){
    printf(" %d", j);
}
printf("\n");
printf("--+");
for(int j = 0; j < 10-3; j++){
    printf("---");
}
putchar('\n');

for (int i = 0; i < 10; ++i){
    printf("%d |", i);
    for (int j = 0; j < 10; ++j){
        printf(" %d",tabjogador1[i][j]);
    }
    putchar('\n');
}
putchar('\n');

// tabuleiro jogador 2
printf("  |");
for (int j = 0; j < 10; j++){
    printf(" %d", j);
}
printf("\n");
printf("--+");
for(int j = 0; j < 10-3; j++){
    printf("---");
}
putchar('\n');

for (int i = 0; i < 10; ++i){
    printf("%d |",i);
    for (int j = 0; j < 10; ++j){
        printf(" %d",tabjogador2[i][j]);
    }
    putchar('\n');
}
putchar('\n');

// procura o ganhador

for(int i=0;i<10;i++){
    for (int j=0;j<10;j++){ //percorre pelas linhas e pelas colunas da matriz
        if(tabjogador1[i][j]==1){ // caso for encontrado algum navio no tabuleiro do jogador 1, o contador de barcos restantes do jog 2 � incrementado
            contadordebarcosrestantes2++;
        }
        if(tabjogador2[i][j]==1){ // caso for encontrado algum navio no tabuleiro do jogador 2, o contador de barcos restantes do jog 1 � incrementado
            contadordebarcosrestantes1++;
        }
    }
}

if(contadordebarcosrestantes1>0){ // se o tabuleiro do jogador 2 ainda tiver barcos...
    if(contadordebarcosrestantes2>0){ // se o tabuleiro do jogador 1 tamb�m tiver barcos...
        printf("0\n");
    }
    else if(contadordebarcosrestantes2==0){ // caso apenas o tabuleiro do jogador 2 ainda tiver navios e o do jogador 1 n�o
        printf("2\n");
    }
}
else if(contadordebarcosrestantes1==0){ // caso o tabuleiro do jogador 2 n�o tiver navios
     if(contadordebarcosrestantes2>0){ // caso o tabuleiro do jogador 1 ainda tiver navios
        printf("1\n");
     }
    else if(contadordebarcosrestantes2==0){ // caso os dois ainda tiverem navios
        printf("0\n");
    }
}

return 0;
}

