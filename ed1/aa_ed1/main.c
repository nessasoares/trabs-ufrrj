/*
ATIVIDADE ACADEMICA ESTRUTURA DE DADOS 1
VANESSA SOARES E PATRÍCIA CASTRO
UFRRJ-2016.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME_LENGTH 81
#define TEL_LENGTH 11

struct contato {
  char nome[NOME_LENGTH]; /* nome do contato */
  char tel[TEL_LENGTH]; /* ddd+número de contato, ex. 21955557777*/
  struct contato *prox;
};
typedef struct contato Contato;



//variáveis
FILE *file;
Contato *final, *inicio;
//funções
void readFile(char path[]);
void init(Contato *lista);
Contato* createNode();
void insert(char nome[], char tel[]);
void show();
void choice();
void insertNew();
int empty();
void writeFile(char path[]);
void insertSort(char n[], char t[]);
Contato* search(int param);
void delete();

//main
int main()
{
    char path[] = "agenda.txt";
    int option = 3;
    Contato *lista = (Contato *)malloc(sizeof(Contato));
     init(lista);
    readFile(path);
    while(option<=4 && option>=0){
        choice();
        scanf("%d", &option);
        if(option>4 || option<0){
            printf("Opção não existe. \nTente novamente!\n");
            option = 3;
            choice();
        }else{

            switch(option){
                case 1: //inserir
                    insertNew();
                    printf("\n Contato inserido!\n\n");
                    break;
                case 2://buscar
                    search(1);
                    break;
                case 3://excluir
                    delete();
                    printf("\n Contato excluído!\n\n");
                    break;
                case 4://mostrar
                    show();
                    break;
                case 0: //sair
                    printf("SAINDO...\n");
                    exit(0);
                    break;
            }
            //show();
        }
            writeFile(path);
    }
    return 0;
}

//ler o arquivo
void readFile(char path[]){

    char ch[100], nome[81], telefone[11];

    file = fopen(path, "r");
    if(file == NULL){
        printf("Erro!");
    }else{//nome dddnumero
        while(fscanf(file, "%s %s", nome, telefone) != EOF){
            insert(nome, telefone);
        }
    }
    fclose(file);

}

//inicializar lista
void init(Contato *lista){
    lista->prox = NULL;
    final = lista;
    inicio = lista;
}

//criar novo nó
Contato* createNode(){
    Contato *node = (Contato *)malloc(sizeof(Contato));
    return node;
}

//inserir na lista
void insert(char n[], char t[]){
    Contato * novo = createNode();
    strcpy(novo->nome, n);
    strcpy(novo->tel, t);
    novo->prox = NULL;
    final->prox = novo;
    final = novo;
}

//exibir agenda
void show(){
    Contato *c = inicio;
    while(c != NULL){
        printf("%s %s\n", c->nome, c->tel);
        c = c->prox;
    }
}

//opções
void choice(){
    printf("\n\n OPÇÕES DISPONÍVEIS:\n\n");
    printf("1 - INSERIR\n");
    printf("2 - BUSCAR\n");
    printf("3 - EXCLUIR\n");
    printf("4 - MOSTRAR AGENDA\n");
    printf("0 - SAIR\n\n\n");
    printf("ESCOLHA UMA OPÇÃO:");

}

//inserir novo contato
void insertNew(){
    char n[81], t[11];
    int verificador  = 0;
    printf("INSERIR NOVO CONTATO:\n");
    printf("Nome:");
    scanf("%s", n);
    printf("Telefone:");
    scanf("%s", t);
    //insert(n, t);
    insertSort(n, t);
}

//inserir novo contato ordenadamente
void insertSort(char n[], char t[]){
    int adicionado = 0;
    Contato *novo = createNode();
    Contato *anterior = createNode();
    strcpy(novo->nome, n);
    strcpy(novo->tel, t);
    //novo->prox = NULL;
    Contato *corrente = inicio;
    //while(c != NULL && (strcoll(c->nome, n)== 0)){ //é ordenadamente
    //while (c->prox != NULL && (strcmp(c->nome,n) <= 0)){
    while(corrente->prox != NULL){ //nao é
      anterior = corrente;
      corrente = corrente->prox;
    //  printf(">>>> %s : %d\n", corrente->nome, strcmp(corrente->nome,n));
      if(strcmp(corrente->nome,n)>= 0){
        anterior->prox = novo;
        novo->prox = corrente;
        adicionado = 1;
        break;
      }
    }
    if(adicionado == 0 ){
      insert(n, t);
    }

}

//escrever no arquivo
void writeFile(char path[]){
    file = fopen(path, "w");
    Contato *c = inicio;
     if(file == NULL){
        printf("Erro!");
    }else{//nome dddnumero
        while(c != NULL){
            fprintf(file, "%s %s\n", c->nome, c->tel );
            //printf("%s %s\n", c->nome, c->tel);
            c = c->prox;
        }
    }
    fclose(file);


}

//verificar se ta vazio
int empty(){
    if(inicio == final){
        return 1;
    }
    return 0;
}

//liberar/excluir nó
void delete(){
  int resposta;
  Contato *prev = search(2);
  printf("Deseja excluir esse contato?\n 1-SIM \n 2-NÂO\n\n");
  scanf("%d", &resposta);
  if(resposta == 1){
    Contato *corrente = prev->prox;
    prev->prox = corrente->prox;
    free(corrente);
  }else{
    printf("Escolha outro contato\n");
  }
}


//buscar na lista
Contato* search(int param){
  char query[NOME_LENGTH];
  int achou = 0;
  if(param == 1){
    printf("\n Digite o nome a ser buscado:");
  }else{
    printf("\n Digite o nome a ser deletado:");
  }
  scanf("%s", query);
  Contato *anterior, *corrente = inicio;
  while(corrente != NULL){
    if( strcmp(corrente->nome, query) == 0){
      achou = 1;
      break;
    }
    anterior = corrente;
    corrente = corrente->prox;
  }

  if(achou == 1){
    printf("\n>> RESULTADO: \n\n Nome: %s \n Telefone: %s \n\n\n", corrente->nome, corrente->tel);
  }else{
    printf("\n Não foi encontrado nenhum resultado com esse nome.\n\n");
    return NULL;
  }
  return anterior; // retorna o anterior pq fica mais fácil

}
