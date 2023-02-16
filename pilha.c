#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
int info;
struct elemento* prox; 
}Elemento;

typedef struct pilha{
Elemento* topo;
}Pilha;

Pilha* pilha_cria();
void pilha_push(Pilha* p, int val);
int pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void imprime(Pilha* p);

int main()
{
    Pilha* p;
    p = pilha_cria();

    pilha_push(p, 12);
    pilha_push(p, 21);
    pilha_push(p, 4);
    
    pilha_pop(p);

    imprime(p);

    return 0;
}

Pilha* pilha_cria()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_push(Pilha* p, int val)
{
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = val;
    novo->prox = p->topo; // novo->prox vai receber NULL;
    p->topo = novo; // topo atualizado
}

int pilha_pop(Pilha* p)
{
    Elemento* aux;
    int val;
    if(pilha_vazia(p))
    {
        exit(1);
    }
    aux = p->topo;
    val = aux->info;
    p->topo = aux->prox;

    free(aux);

    return val;
}

int pilha_vazia(Pilha* p)
{
    if(p->topo == NULL)
    {
        return 1;
    }
    return 0;
}
void imprime(Pilha* p)
{
    Elemento* aux;
    for(aux = p->topo; aux != NULL; aux = aux->prox)
    {
        printf("%d\n", aux->info);
    } 
}