#include <stdio.h>
#include <string.h>

#define TAMANHO_NOME 50
#define TAMANHO_LISTA 100

typedef struct ferramenta{
  int id;
  char nome[TAMANHO_NOME];
} FERRAMENTA;

typedef struct lista{
  int tamanhoLista;
  FERRAMENTA ferramentas[TAMANHO_LISTA];
}LISTA;

FERRAMENTA criaFerramenta(char* nome);
void adicionaFerramenta(LISTA* lista, FERRAMENTA ferramenta);
void listaFerramentas(LISTA lista);
void buscaFerramenta(char* nome, LISTA lista);
void deletaFerramenta(char* nome, LISTA* lista);
void AtualizaFerramenta(char* nome, LISTA* lista, char* novoNome);

int main(){

  char* nomes[4] = {"Martelo", "Alicate", "Chave phillips", "Ferro de solda"};

  LISTA listaDeFerramentas = {.tamanhoLista = 0};

  for(int i = 0; i < 4; i++){
    adicionaFerramenta(&listaDeFerramentas, criaFerramenta(nomes[i]));
  }

  listaFerramentas(listaDeFerramentas);

  buscaFerramenta("Alicate", listaDeFerramentas);

  deletaFerramenta("Chave phillips", &listaDeFerramentas);

  AtualizaFerramenta("Martelo", &listaDeFerramentas, "Serra");

  buscaFerramenta("Chave phillips", listaDeFerramentas);

  listaFerramentas(listaDeFerramentas);



}

FERRAMENTA criaFerramenta(char* nome){
  
  FERRAMENTA f;
  
  static int proximoId = 0;

  printf("gerando %s...\n\n", nome);

  strlcpy(f.nome, nome, TAMANHO_NOME);
  f.id = proximoId++;
  
  return f;
}

void adicionaFerramenta(LISTA* lista, FERRAMENTA ferramenta){
  
  lista->ferramentas[lista->tamanhoLista] = ferramenta;
  lista->tamanhoLista++;
  printf("Ferramenta adicionada com sucesso!\n\n");

}

void listaFerramentas(LISTA lista){

  printf("Listando...\n");
  for(int i = 0; i < lista.tamanhoLista; i++){
    printf("ID: %d,  NOME: %s\n", lista.ferramentas[i].id, lista.ferramentas[i].nome);
  }
  printf("\n");
}

void buscaFerramenta(char* nome, LISTA lista){
  
  printf("Buscando...\n");
  for(int i = 0; i < lista.tamanhoLista; i++){
    if(strcmp(nome, lista.ferramentas[i].nome) == 0){
      printf("%d || %s\n\n", lista.ferramentas[i].id, lista.ferramentas[i].nome);
      return;
    }
  }
  printf("Parece que a ferramenta que está tentando buscar não existe!\n\n");
}

void deletaFerramenta(char* nome, LISTA* lista){

  int achou = 0;
  
  int i = 0;
  while(!achou){
      if(strncmp(nome, lista->ferramentas[i].nome, TAMANHO_NOME) == 0){
        printf("Deletando %s\n", nome);
        for(int j = i; j < lista->tamanhoLista -1; j++){
          lista->ferramentas[j] = lista->ferramentas[j+1];
        }
        achou = !achou;
        lista->tamanhoLista--;
        printf("Ferramenta deletada com sucesso.\n\n");
        return;
      }  
    i++;
    if(i > lista->tamanhoLista)
      break;
  }
  printf("Nada foi deletado, tente novamente.\n");
}

void AtualizaFerramenta(char* nome, LISTA* lista, char* novoNome){

  for(int i = 0; i < lista->tamanhoLista; i++){
    if(strncmp(nome, lista->ferramentas[i].nome, TAMANHO_NOME) == 0){
      printf("Atualizando...\n");
      for(int j = i; j < lista->tamanhoLista - 1; j++){
        strlcpy(lista->ferramentas[j].nome, novoNome, TAMANHO_NOME);
        printf("Ferramenta atualizada com sucesso!\n\n");
        return;
      }
    }
  }
  printf("Nada foi alterado.\n");
}
