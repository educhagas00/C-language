#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista* prox;
} Lista;

typedef struct fila{
    Lista* ini;
    Lista* fim;
} Fila;

Fila* fila_cria();
Fila* fila_insere(Fila* f, int val);
int fila_retira(Fila* f);
int fila_vazia(Fila* f);

int main()
{
    Fila* fila;

    fila = fila_cria();

    return 0;
}

Fila* fila_cria()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

Fila* fila_insere(Fila* f, int val)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->info = val;
    novo->prox = NULL;
    
    if(f->fim != NULL) // testa se a fila ta vazia
    {
        f->fim->prox = novo;
    }
    else
    {
        f->ini = novo; // primeiro cara
    }

    f->fim = novo;
}

int fila_retira(Fila* f)
{
    Lista* aux;
    int val;

    if(fila_vazia(f))
    {
        printf("fila vazia.\n");
        exit(1);
    }

    aux = f->ini;
    val = aux->info;
    f->ini = aux->prox;

    if(f->ini == NULL)
    {
        f->fim = NULL;
    }

    free(aux);

    return val;
}

