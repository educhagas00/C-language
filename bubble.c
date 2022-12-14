#include<stdio.h>

void bubble(int n, int* v);

int main()
{
    int n;
    scanf("%d", &n);
    int vetor[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    bubble(n, vetor);

    for(int i = 0; i < n; i++)
    {
        printf("%d", vetor[i]);
    }



    return 0;
}

void bubble(int n, int* v)
{
    int fim;

    for(fim = n-1; fim > 0; fim--)
    {
        for(int i = 0; i < fim; i++)
        {
            if(v[i] > v[i + 1])
            {
                int temp;
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }

        }

    }
}
