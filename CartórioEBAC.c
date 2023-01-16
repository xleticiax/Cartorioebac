#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��o dos usu�rios
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n"); //coletando informa��es dos usu�rios
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome);
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: \n"); //coletando informa��es dos usu�rios
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,sobrenome);
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,",");
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: \n"); //coletando informa��es dos usu�rios
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre arquivo
	fprintf(file,cargo);
	fclose(file); //fecha arquivo
	
	system("pause"); 
		
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF que deseja consultar: \n"); //coletando informa��es dos usu�rios
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e o r significa ler
	
	if(file == NULL) //para caso n�o encontre dados no sistema
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); //para os dados que foram encontrados no sistema
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��es dos usu�rios
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //para deletar
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o r significa ler
	
	if(file == NULL); //para caso n�o encontre dados no sistema
		{
			printf("O usu�rio n�o se encontra no sistema. \n");
			system("pause");
		}
}

int main()
	{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); 
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu 
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			default: //para caso o usu�rio digite uma op��o inexistente
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
		}

	}
}
