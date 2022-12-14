#include<stdio.h>

void insertion(int* v, int n);

int main()
{
    int n;
    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    insertion(vetor, n);
    
    for(int i = 0; i < n; i++)
    {
        printf("%d", vetor[i]);
    }

    return 0;
}

void insertion(int* v, int n)
{
    int j;
    int temp;
    for(int i = 1; i < n; i++)
    {
        j = i;
        while(j > 0 && v[j-1] > v[j])
        {
            temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
            j--;
        }
    }
}
