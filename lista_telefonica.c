#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inserir();
int remover();
void visualizar();
int buscar();


#define MAX_CONTATOS 100
int contador = 0;

typedef struct contato
{

    char nome[81];
    float telefone;

} Contato;

Contato contatos[MAX_CONTATOS];


int main()
{
	int k, l, i;
    int op;
    do
    {
        
            
        printf("\nBem vindo a lista telefoncia!");
        printf("\nselecione a opcao desejada:");
        printf("\n1 - visualizar lista:");
        printf("\n2 - Inserir Contato:");
        printf("\n3 - Remover Contato:");
        printf("\n4 - Buscar Contato:");
        printf("\n0 - Sair:\n");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            visualizar(); 
            break;
        case 2:
            inserir();
            break;
        case 3:
			l = remover();
			if(l == 0)
			{
				printf("Usuario nao encontrado.\n");
			}
			else
			{
			
				for(i = l; i < contador; i++)
        		{
            		contatos[i] = contatos[i + 1];
        		}
        		contador--;
        		printf("\nContato removido.\n");
        	}
			break;    
        case 4:
			k = buscar();
			if(k == 0)
			{
				printf("Usario nao encontrado.\n");
			}
			else
			{
           		printf("\nUsuario encontrado! Nome: %s - Telefone: %.0f\n", contatos[k].nome, contatos[k].telefone);
        	}
            break;
        }
        
    }while(op != 0);

    return 0;
}

void inserir()
{
    char nome[81];
    float telefone;
    
    if(contador > 0)
    {
        int i = 0;
        int j;
    
        
            printf("\nDigite o nome do contato:\n");
            scanf(" %[^\n]", nome);
    
            printf("\nDigite o numero de telefone do contato\n");
            scanf("%f", &telefone);
    
            
            while(strcmp(nome, contatos[i].nome) >= 0 && i < contador)
            {
                i++;
            }  
            for(j = contador; j > i; j--)
            {
                contatos[j] = contatos[j-1];
            }
    
            strcpy(contatos[i].nome, nome);
            contatos[i].telefone = telefone;
            contador++;               
    }
    else
    {
        printf("\nDigite o nome do contato:\n");
        scanf(" %[^\n]", nome);
    
        printf("\nDigite o numero de telefone do contato\n");
        scanf("%f", &telefone);
        
        strcpy(contatos[0].nome, nome);
        contatos[0].telefone = telefone;
        contador++;
    }
}

void visualizar()
{
    
    int i;
    
    for(i = 0; i < contador; i++)
    {
        printf("\n%d| %s - %0.f\n", i, contatos[i].nome, contatos[i].telefone);
    }
    
}

int buscar()
{
	char nome[81];
	printf("\nDigite o nome do contato a ser buscado:\n");
	scanf(" %[^\n]", nome);
	
	
	int ini = 0;
	int fim = contador - 1;
	
	while(ini <= fim && fim >= 0)
	{
		int meio = (ini + fim) / 2;
		switch (strcmp(nome, contatos[meio].nome))
        {
            case -1:
                fim = meio - 1;
            break;

            case 1:
                ini = meio + 1;
            break;

            case 0:
                return meio;
            break;
    	}
    	
	}
	return 0;
}

int remover()
{
	char nome[81];
	int i;
	
	printf("\nDigite o contato a ser apagado: ");
	scanf(" %[^\n]", nome);
	
	int ini = 0;
	int fim = contador - 1;
	
	while(ini <= fim && fim >= 0)
	{
		int meio = (ini + fim) / 2;
		switch (strcmp(nome, contatos[meio].nome))
        {
            case -1:
                fim = meio - 1;
            break;

            case 1:
                ini = meio + 1;
            break;

            case 0:
                return meio;
            break;
          	
    	}
    	
	}
	return 0;
	
}


