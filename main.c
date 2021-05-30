/* 




*/

/* Neste algorítmo iremos utilizar algumas funções de bibliotecas do C
A primeira e mais básica é a printf que pertence a biblioteca stdlib é utilizada para printar valores
A segunda função é a função srand que seleciona valores aleatórios que pertence a biblioteca stdlib
A terceira função é a função time que pertence a biblioteca time mas que será usado com uma finalidade diferente
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A função printArray recebe um vetor do tipo inteiro e um inteiro n que é a quantidade de elementos do vetor
Essa função tem como objetivo imprimir na tela os n elementos do vetor stream */
void printArray(int stream[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", stream[i]);
	printf("\n");
}

/* A função selectKItems recebe um vetor do tipo inteiro, um inteiro n que é a quantidade de elementos do vetor e
um inteiro k que é a quantidade de itens que iremos selecionar desse vetor
Essa função tem como objetivo imprimir na tela os n elementos do vetor stream */
void selectKItems(int stream[], int n, int k)
{
	int i; 

	//reservoir é o array em que teremos nossa saída
	//iremos inicializá-lo com os k primeiros itens do array stream
	int reservoir[k];
	for (i = 0; i < k; i++)
	{
		reservoir[i] = stream[i];
	}
		

	/* Para fazer com que os valores gerados não se repitam precisamos usar a função srand a fim de inicializar a função rand com um valor “semente” 
	para que se produza um valor aleatório na faixa determinada. A função srand recebe um argumento do tipo inteiro sem sinal, ou seja unsigned int. 
	Já a função time(null) retorna um inteiro com o número de segundos passados desde 1 de janeiro de 1970, às 00:00 até hoje.*/
	srand(time(NULL));

	// A iterações começam a partir do i = k + 1
	for (; i < n; i++)
	{
		// Pega aleatóriamente um ínide de 0 a i
		int j = rand() % (i+1);

		//Se o índice escolhido aleatoriamente for menor que k, substituímos o elemento presente no índice por um novo elemento do array stream
		if (j < k)
		reservoir[j] = stream[i];
	}

	printf("Following are k randomly selected items \n");
	printArray(reservoir, k);
}

// Nossa função Main onde iremos testar o funcionamento correto de nossas funções, utilizando valores menores do que o proposto
int main()
{
	int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int n = sizeof(stream)/sizeof(stream[0]);
	int k = 5;
	selectKItems(stream, n, k);
	return 0;
}
