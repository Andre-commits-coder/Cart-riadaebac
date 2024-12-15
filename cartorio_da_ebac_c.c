#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro() // Função resposável por cadastrar os usuários no sistema
{
	//ínicio criação de variáveis/string
    char arquivo[40];
	char cpf[40];
    char nome [40];
    char sobrenome[40];
    char cargo[40];
    	//final criação de variáveis/string
    
	printf("Digite o cpf a ser cadastrado: ");//coletando informações do usuário  
	scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo,"w"); // cria o arquivo em uma pasta, e o W e escrever. 
    fprintf(file,cpf); // salva o valor da variável no arquivo 
	fclose(file);    // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen (arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");  
       
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //abrir e ler o arquivo
    
    if(file == NULL) 
    {
    	printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
   
    system("pause");    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL )
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main() 
{
    int opcao = 0; // Definindo as Variáveis 
    int laco = 1;

    for (laco = 1; laco == 1;)
	{ 
		
		system("cls"); 

        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

        printf("### Cartório da EBAC ###\n\n"); // Início do Menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar\n");
        printf("\t4 - sair do sistema\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário
        
        system("cls");//responsável por limpar a tela

        switch (opcao) // Início da Seleção do menu
		{ 
            case 1:
            registro(); //chamado de funções 
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;
            
            case 4:
            printf ("Obrigado por utilizar o sistema!\n");
            return 0;
            break;

            default:
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;   
        } //fim da seleçõa
        
    }
}

