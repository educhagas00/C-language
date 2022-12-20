#include<stdio.h>

int busca(int* vet, int inicio, int fim, int numero);

int main()
{
    int n, x;
    printf("tamanho do vetor:\n");
    scanf("%d", &n);
    
    int vet[n];
   
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    
    printf("qual numero quer buscar?\n");
    scanf("%d", &x);
    
    int k = busca(vet, 0, n, x);

    printf("esta na posicao : %d", k);

    return 0;
}

int busca(int* vet, int inicio, int fim, int numero)
{

    if(inicio <= fim)
    {
        int meio = (inicio + fim)/2;

        if(vet[meio] == numero)
        {
            return meio;
        }
        if(numero < vet[meio])
        {
            return busca(vet , inicio , meio-1 , numero);
        }
        else
        {
            return busca(vet , meio+1 , fim , numero);
        }
    }
    return -1;
}
