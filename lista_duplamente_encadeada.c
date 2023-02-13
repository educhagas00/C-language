#include<stdio.h>
#include<stdlib.h>


typedef struct lista2 Lista2;
struct lista2{
    int info;
    Lista2* ant;
    Lista2* prox;
};

Lista2* lst_cria();
Lista2* lst_insere(Lista2* lst, int val);
Lista2* lst_imprime(Lista2* lst);
Lista2* lst_busca(Lista2* lst, int val);
Lista2* lst_remove(Lista2* lst, int val);

int main()
{   
    Lista2* lst;
    lst = lst_cria();

    lst = lst_insere(lst, 4);
    lst = lst_insere(lst, 21);
    lst = lst_insere(lst, 30);

    lst_remove(lst, 2312);

    lst_imprime(lst);
    
    

    return 0;
}

Lista2* lst_cria(Lista2* lst)
{
    return NULL;
}

Lista2* lst_insere(Lista2* lst, int val)
{
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = val;
    novo->prox = lst;
    novo->ant = NULL;

    if(lst != NULL)
    {
        lst->ant = novo; //REVER
    }

    return novo;
}

Lista2* lst_imprime(Lista2* lst)
{
    Lista2* p;
    for(p = lst; p != NULL; p = p->prox)
    {
        printf("info = %d\n", p->info);
    }
}

Lista2* lst_busca(Lista2* lst, int val)
{
    Lista2* p;
    for(p = lst; p != NULL; p = p->prox);
    {
        if(p->info == val)
        {
            printf("elemento %d encontrado!", val);
            return p;
        }
    }
    printf("elemento %d nao encontrado.", val);
    return NULL;    
}

Lista2* lst_remove(Lista2* lst, int val)
{
    Lista2* p = lst_busca(lst, val);
    if(p == NULL)
    {
        return lst;
    }


    if(lst == p) //se eh o primeiro elemento
    {
        lst = p->prox;
    }
    else
    {
        p->ant->prox = p->prox;

        if(p->prox != NULL) //testa se eh o ultimo
        {
            p->prox->ant = p->ant;
        }
        free(p);

        return lst;
    }

}