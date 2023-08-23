#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lua{
    char nome_lua[101];
    int raio_lua;
}sis_lua;

typedef struct planetas{
    char nome_planeta[101];
    int raio_planeta;
    int qnt_luas;
    sis_lua* lua;
}sis_planetas;

typedef struct sistemas{
    int tempo_descoberta;
    char nome_sistema[101];
    int raio_sol;
    int qnt_planetas;
    sis_planetas* planetas;
}sis_solares;


void le_luas(sis_solares*sistemas, int qnt_luas, int i, int j){ //lê as luas dos planetas

    for(int k = 0; k < qnt_luas; k++){
        scanf("\t\t%s",sistemas[i].planetas[j].lua[k].nome_lua);
        scanf("%d",&sistemas[i].planetas[j].lua[k].raio_lua); 
    }

}

void le_planetas(sis_solares*sistemas, int qnt_planetas, int i){ //Lê os planetas dos sistemas
    for(int j = 0; j < qnt_planetas; j++){ 
    scanf("\t%s",sistemas[i].planetas[j].nome_planeta);
    scanf("%d",&sistemas[i].planetas[j].raio_planeta);
    scanf("%d",&sistemas[i].planetas[j].qnt_luas);
    sistemas[i].planetas[j].lua = (sis_lua*) malloc(sistemas[i].planetas[j].qnt_luas * sizeof(sis_lua)); //aloca dinamicamente vetores para guardar as luas
    le_luas(sistemas, sistemas[i].planetas[j].qnt_luas,i,j); // chama a função que irá ler as luas
    }
}

void le_sistemas(sis_solares*sistemas, int qnt_sistemas){ //le os sistemas
for(int i = 0; i < qnt_sistemas; i++){
    scanf("%d",&sistemas[i].tempo_descoberta);
    scanf("%s",sistemas[i].nome_sistema);
    scanf("%d",&sistemas[i].raio_sol);
    scanf("%d",&sistemas[i].qnt_planetas);
    sistemas[i].planetas = (sis_planetas*) malloc(sistemas[i].qnt_planetas * sizeof(sis_planetas)); //aloca dinamicamente vetores para guardar os planetas
    le_planetas(sistemas, sistemas[i].qnt_planetas,i); //chama a função que irá ler os planetas
}
}
int maior_lua(sis_solares*sistemas, int a){ //função que descobrirá qual a maior lua de cada sistema
int num_luas = 0; //número de luas totais do sistema
int maior_lua = 0; //variável que irá guardar a maior lua

for(int j = 0; j < sistemas[a].qnt_planetas; j++){ //conta as luas do sistema
        num_luas += sistemas[a].planetas[j].qnt_luas;
}
if(num_luas == 0){ //se a quantidade de luas for zero...
    return -1;
}
else{
    for(int i = 0; i < sistemas[a].qnt_planetas; i++){ //procura pela maior lua em todos os planetas do sistema
    for(int j = 0; j < sistemas[a].planetas[i].qnt_luas; j++){
        if(sistemas[a].planetas[i].lua[j].raio_lua > maior_lua){
            maior_lua = sistemas[a].planetas[i].lua[j].raio_lua;
        }
    }
    }
return maior_lua;
    }
}

int mais_luas(sis_solares*sistemas, int i){ //conta a quantidade de luas do sistema e retorna
int num_luas = 0;

for(int j = 0; j < sistemas[i].qnt_planetas; j++){
    num_luas += sistemas[i].planetas[j].qnt_luas;
}
return num_luas;
}

int maior_planeta(sis_solares*sistemas, int i){ //procura pelo maior planeta do sistema e retorna seu índice
int maior = 0;
int indice = 0;

if(sistemas[i].qnt_planetas == 0){ //condição para caso não haja planetas no sistema
    return 0;
}
for(int k = 0; k < sistemas[i].qnt_planetas; k++){
    if(sistemas[i].planetas[k].raio_planeta > maior){
        maior = sistemas[i].planetas[k].raio_planeta;
        indice = k;

    }
}
return indice;
}

int melhor_sistema(sis_solares*sistema, int i, int j){ //compara dois sistemas e retorna 1 se o sistema "i" for melhor e -1 se o sistema "j" for melhor
    int indice1 = maior_planeta(sistema, i); //índice do maior planeta do sistema "i" retornado pela função maior planeta
    int indice2 = maior_planeta(sistema, j); //índice do maior planeta do sistema "j" retornado pela função maior planeta

    if(sistema[i].raio_sol > sistema[j].raio_sol){ // compara o raio do sol
        return 1;
    }
    else if(sistema[j].raio_sol > sistema[i].raio_sol){ 
        return -1;
    }
    else if(sistema[i].qnt_planetas > sistema[j].qnt_planetas){ //compara a quantidade de planetas
        return 1;
    }
    else if(sistema[j].qnt_planetas > sistema[i].qnt_planetas){
        return -1;
    }
    else if(sistema[i].planetas[indice1].raio_planeta > sistema[j].planetas[indice2].raio_planeta){ //compara os maiores planetas de cada sistema
    return 1;
    }
    else if(sistema[j].planetas[indice2].raio_planeta > sistema[i].planetas[indice1].raio_planeta){
    return -1;
    }
    

    else if(mais_luas(sistema,i) > mais_luas(sistema,j)){ //compara a quantidade de luas de cada sistema, a função mais_luas retorna a quantidade de luas de cada sistema
        return 1;
    }
    else if(mais_luas(sistema,j) > mais_luas(sistema,i)){
        return -1;
    }
    else if(maior_lua(sistema,i) > maior_lua(sistema,j)){ //compara a maiores luas de cada sistema retornada pela função maior_lua
    return 1;
    }
    else if(maior_lua(sistema,j) > maior_lua(sistema,i)){
    return -1;
    }

   
    else if(sistema[i].tempo_descoberta < sistema[j].tempo_descoberta){ //compara o tempo de descoberta
        return 1;
    }
    else if((sistema[j].tempo_descoberta < sistema[i].tempo_descoberta)){
        return -1;
    }

}

void ritacao(sis_solares*sistemas, int esquerda, int fim_esquerda,int inicio_direita, int direita){
int tamanho = (direita - esquerda);
sis_solares* vetor_organizado = (sis_solares*) malloc((10*tamanho)*sizeof(sis_solares)); // aloca dinamicamente um vetor que irá guardar os sistemas organizados 

for(int i = esquerda, j = inicio_direita, k = 0; i < fim_esquerda || j < direita; k++ ){ // organiza os sistemas
    if(i == fim_esquerda){ // se i == fim esquerda, não há mais sistemas para serem comparados em i, então serão adicionados os de j. O mesmo acontece ao contráio
        vetor_organizado[k] = sistemas[j];
        j++; 
    }
    else if(j == direita){
        vetor_organizado[k] = sistemas[i];
        i++; 
    }

    else if(melhor_sistema(sistemas,i,j)==1){ // se o sistema i for melhor que o j ele é adicionado ao vetor organizado
        vetor_organizado[k] = sistemas[i];
        i++;
    }
   
    else{ // se o sistema j for melhor que o i ele é adicionado ao vetor organizado
        vetor_organizado[k] = sistemas[j];
        j++;
    }
    
}
for(int l = esquerda, k = 0; l < direita; k++, l++){ // o vetor sistema recebe os sistema de forma ordenada
    sistemas[l] = vetor_organizado[k];
}
 free(vetor_organizado); // desaloca a memória do vetor organizado
}

void bromero_sort(sis_solares* sistemas, int esquerda, int direita){   
if(direita - esquerda == 1){ // se direta - esquerda == 1 o vetor já está organizado
    return;
}
if((direita - esquerda) % 2 == 1){ //caso o tamanho do vetor seja ímpar
    bromero_sort(sistemas, esquerda, direita - 1); // chama a função recursivamente
    ritacao(sistemas, esquerda, direita-1, direita-1, direita);
    return;
}
int meio = (direita + esquerda) /2;
bromero_sort(sistemas, esquerda, meio); // chama função recursivamente do início do vetor até o meio
bromero_sort(sistemas, meio , direita); // chama a função recursivamente do meio até o fim
ritacao(sistemas, esquerda, meio, meio, direita); //faz a ritação dos vetores
}

int main(){
    int qnt_sistemas;
    sis_solares* sistemas;

    scanf("%d",&qnt_sistemas);
    sistemas = (sis_solares*) malloc(qnt_sistemas*sizeof(sis_solares)); //aloca dinamicamente o vetor de structs

    le_sistemas(sistemas, qnt_sistemas); // chama a função que irá ler os sistema
    bromero_sort(sistemas,0,qnt_sistemas); // chama a função que irá ordenar os sistemas

    for(int i = 0; i < qnt_sistemas; i++){ // imprime o resultado final
        printf("%s\n",sistemas[i].nome_sistema);
    }

    for(int i = 0; i < qnt_sistemas; i++){ //desaloca a memória alocada de dentro para fora
        for(int j = 0; sistemas[i].qnt_planetas; j++){  
            free(sistemas[i].planetas[j].lua);
        }
        free(sistemas[i].planetas);
    }
    free(sistemas);

    return 0;
}