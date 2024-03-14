#include <stdio.h>
#include <string.h>

typedef struct ferramenta{

  int id;
  char nome[50];

} FERRAMENTA;

typedef struct lista{

  int tamanhoLista;
  FERRAMENTA ferramentas[10];

} LISTA;

LISTA lista = {.tamanhoLista = 0};

void adicionaFerramenta();
void deletaFerramenta();
void listaFerramentas();
void atualizaFerramenta();

int main(){

  adicionaFerramenta();
  adicionaFerramenta();
  adicionaFerramenta();
  listaFerramentas();
  deletaFerramenta();
  atualizaFerramenta();
  listaFerramentas();
  

  return 0;

}
void adicionaFerramenta(){

  char nome[50];

  printf("Digite um nome:");

  scanf(" %s", nome);
  
  lista.ferramentas[lista.tamanhoLista].id = lista.tamanhoLista+1;
  strncpy(lista.ferramentas[lista.tamanhoLista].nome, nome, 50);

  lista.tamanhoLista++;
}


/*void adicionaFerramenta(){
  
  FERRAMENTA f = {.id = 0};

  char nome[sizeof(f.nome)];

  while(f.id == 0){
  
    printf("Por favor, digite o nome da ferramenta\n");
    scanf(" %[^\n]", nome);

    if(strlen(nome) <= 0){
      printf("Nome inválido, digite novamente\n");
    }else{
     f.id = lista.tamanhoLista +1;
     strlcpy(f.nome, nome, sizeof(f.nome));
    }
  }
  if(f.id != 0){
    lista.ferramentas[lista.tamanhoLista] = f;
    lista.tamanhoLista++;
  }
}*/

void deletaFerramenta(){

  char delete[50] = "\0";

  while(strlen(delete) == 0){
      
    printf("Digite o nome do objeto para deletar:");
    scanf(" %s", delete);

    for(int i = 0; i < lista.tamanhoLista; i++){
      if(strcmp(lista.ferramentas[i].nome, delete) == 0){ 
        for(int j = i; j < lista.tamanhoLista -1; j++){
          lista.ferramentas[j] = lista.ferramentas[j+1];
        }
        lista.tamanhoLista--;
        printf("Deletado com sucesso!\n");
        return;
      }
    }
  strncpy(delete, "\0", 50);
  }
}

void listaFerramentas(){
  
  int i = 0;
  while(i < lista.tamanhoLista){
    printf("%s\n", lista.ferramentas[i++].nome);
  }
}

void atualizaFerramenta(){

  char nome[50] = "\0";

  while(strlen(nome) == 0){

    printf("Digite o nome do objeto para atualizar:");
    scanf(" %s", nome);

    for(int i = 0; i < lista.tamanhoLista; i++){
      if(strcmp(nome, lista.ferramentas[i].nome) == 0){
        printf("Deseja substituir %s ->[s/n]?\n", lista.ferramentas[i].nome);
        char decisao = 'n';
        scanf(" %c", &decisao);
        if(decisao == 's'){
          printf("digite o novo nome da ferramenta:");
          scanf(" %s", nome);
          strncpy(lista.ferramentas[i].nome, nome, 50);
          printf("Atualizado com sucesso.\n");
          return;
        }else{
          printf("Nada foi feito.");
          return;
        }
      }
    }
    strcpy(nome, "\0");
  }
}


