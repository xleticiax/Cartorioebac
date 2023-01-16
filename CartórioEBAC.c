#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informação dos usuários
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //coletando informações dos usuários
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //coletando informações dos usuários
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,sobrenome);
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,",");
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: \n"); //coletando informações dos usuários
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,cargo);
	fclose(file); //fecha arquivo
	
	system("pause"); 
		
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis/string
	
	printf("Digite o CPF que deseja consultar: \n"); //coletando informações dos usuários
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e o r significa ler
	
	if(file == NULL) //para caso não encontre dados no sistema
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); //para os dados que foram encontrados no sistema
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	//início da criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informações dos usuários
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //para deletar
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o r significa ler
	
	if(file == NULL); //para caso não encontre dados no sistema
		{
			printf("O usuário não se encontra no sistema. \n");
			system("pause");
		}
}

int main()
	{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); 
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu 
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			default: //para caso o usuário digite uma opção inexistente
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
				
		}

	}
}
