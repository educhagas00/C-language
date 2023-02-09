#include<stdio.h>

int main()
{
    
    int i, n, j;
    char expressao[1000];

    scanf("%d", &n); 
    for (i = 0; i < n; i++)
    {
        scanf(" %[^\n]", expressao); 
        int cont = 0; 
        for (j = 0; expressao[j] != '\0'; j++)
        {
            if(expressao[j] == '(')
            {
                cont++;
            }
            else if(expressao[j] == ')')
            {
                cont--;
            }
            if(cont < 0)
            {
                break;
            }
        }
        if(cont == 0)
            {
                printf("correct\n");
            }
            else
            {
                printf("incorrect\n");
            }
    }        
    return 0;
}
