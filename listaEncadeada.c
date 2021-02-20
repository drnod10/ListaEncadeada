#include <stdio.h>
#include <stdlib.h>

struct NO {
	int valor;
	struct NO *prox;
};

typedef struct {
	struct NO *inicio;
} LISTA;

// Inicializa a lista encadeada
void init (LISTA *ls) {
	ls->inicio = NULL;
}
// Informa se a lista está vazia
int empty (LISTA *ls) {
	if (ls->inicio == NULL) 
		return 1;
	else
		return 0;
}
// insere novo elemento no inicio da lista
void insere(LISTA *ls, int info) {
	struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
    novo->valor = info; 
	novo->prox = ls->inicio;
	ls->inicio = novo; 	
}

void exibeLista(struct NO *elem) {    
   printf("%i\n", elem->valor); 
   if (elem->prox != NULL)
      exibeLista(elem->prox);
}
int main() {
   LISTA lista1;   
   int valor;
   	
   init(&lista1);  // Inicializa a lista
   do {
      printf("Digite um valor (0 para sair): \n");
      scanf("%i",&valor);
      fflush(stdin);
      if (valor != 0)
         insere(&lista1, valor);  // Insere o elemento digitado
  } while (valor != 0); 
   exibeLista(lista1.inicio);      
}
