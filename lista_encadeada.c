#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;

struct lista{

    int info;
    Lista* prox;

};



Lista* lst_cria ();
Lista* lst_insere(Lista* lst, int val);
void lst_imprime(Lista* lst);
Lista* lst_remove(Lista* lst, int val);
Lista* lst_busca(Lista* lst, int v);

int main()
{
    Lista* lst; //declara a lista
    lst = lst_cria(); //inicializa a lista

    lst = lst_insere(lst, 12); //insere na lista
    lst = lst_insere(lst, 21);
    lst = lst_insere(lst, 4);

    //lst = lst_remove(lst, 21);
    
    lst_imprime(lst);

    lst_busca(lst, 132);

    return 0;
}

//retorna uma lista vazia
Lista* lst_cria()
{
    return NULL;
}

Lista* lst_insere(Lista* lst, int val)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = val;
    novo->prox = lst; //a lista nova agr aponta para a anterior criada
    return novo;
} 

void lst_imprime(Lista* lst)
{
    Lista* p;
    for(p = lst; p != NULL; p = p->prox)
    {
        printf("info = %d\n", p->info);
    }
}

Lista* lst_remove(Lista* lst, int val)
{
    Lista* ant = NULL; //ponteiro para o elemento anterior
    Lista* p = lst; //ponteiro q percorre a lsita

    while(p != NULL && p->info != val)
    {
        ant = p;
        p = p->prox;
    }

    //verificar se o elemento esta no começo, no meio ou no fim da lista
    if(p == NULL)
    {
        return lst; //se n achou, retorna a lista original
    }
    if(ant == NULL)
    {
        lst = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p);
    return lst;
}

Lista* lst_busca(Lista* lst, int v)
{
    Lista* p;
    for(p = lst; p != NULL; p = p->prox)
    {
        if(p->info == v)
        {
            printf("elemento %d encontrado!", v);
            return p;
        }
    }
    printf("elemento %d nao encontrado", v);
    return NULL; //não achou o elemento
}
