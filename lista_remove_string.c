#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char* str; /* string armazenada */
    struct lista* prox; /* ponteiro para próximo elemento */
};
typedef struct lista Lista;

Lista* lst_cria();
Lista* lst_insere (Lista* lst, char* nome);
Lista* retira (Lista* lst, char* nome);
void imprime (Lista* lst);


int main (void) {

    Lista* lst;
    lst = lst_cria();

    lst = lst_insere (lst, "Victor");
    lst = lst_insere (lst, "Victor");
    lst = lst_insere (lst, "Victor");
    lst = lst_insere (lst, "eduardo");
    lst = lst_insere (lst, "eduardo");
    lst = lst_insere (lst, "augusto");

    retira (lst, "eduardo");

    imprime (lst);

    return 0;
}


Lista* lst_cria()
{
    return NULL;
}

Lista* lst_insere (Lista* lst, char* nome)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->str = nome;
    novo->prox = lst;

    return novo;
}

Lista* retira (Lista* lst, char* nome)
{
    Lista* p = lst;
    Lista* ant = NULL;

    while (p != NULL)
    {
        if (strcmp(p->str, nome) == 0) //se for igual da 0. diferente da 1.
        {
            if (ant == NULL)
            {
                lst = p->prox;
            }
            else
            {
                ant->prox = p->prox;
                p = ant->prox;
            }
        }
        else
        {
            ant = p;
            p = p->prox;
        }
    }
    return lst;
}

void imprime (Lista* lst)
{
    Lista* p;

    for (p = lst; p != NULL; p = p->prox)
    {
        printf("\n%s", p->str);
    }
    
}
