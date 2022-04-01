#define _CRT_SECURE_NO_WARNINGS
#include "Operation.h"
#include "Job.h"
#include <stdbool.h>
#include <string.h> 

#define MMAX 8
void CreateOperations(Operation** operation, int iD, char* name, int IDmaquina, int tempo ){

	// variaveis
	Operation* newOperation = (Operation*)malloc(sizeof(Operation));
	Operation* last = *operation;
	int aux;
	int aux1;
	// initializar a nova maquina
	newOperation->tempo = tempo;
	newOperation->IDmaquina = IDmaquina;
	newOperation->ID = iD;
	strcpy(newOperation->Name, name);
	newOperation->next = NULL;


	// verificar se esta nula
	if (isEmpty(*operation))
	{
		*operation = newOperation;
		return;
	}

	// se nao estiver nula encontrar a ultima
	while (last->next != NULL)
	{
		last = last->next;
	}
	// igualar a ultima a nova maquina
	last->next = newOperation;
}

void ModifyOperation(Operation *actualOperation, Operation newOperation)
{
	// variaveis
	Operation* actual;
	bool edited = false;

	// igualar a atual a recebida
	actual = actualOperation;

	// encontrar a maquina pretendida
	while (actual != NULL && edited == false)
	{
		if (actual->ID == newOperation.ID)
		{
			// modificar a maquina
			*actual = newOperation;
			edited = true;
		}

		actual = actual->next;
	}
}

// mostrar produtos head para tail
void ShowOperations(Operation* operation)
{
	// variaveis
	Operation* actual;

	// titulo
	printf("\n Operations forma ascendente...\n");

	// inicializar a variavel actual
	actual = operation;

	//escrever file
	FILE* in;

	in = fopen("Process_Plan.txt", "w");
	if (in == NULL)
	{
		printf("ERROERROR: couldnt load file.txt\n");
	}

	// mostrar estudantes na lista
	while (actual != NULL)
	{
		// apresentar produtos
		fprintf(in, "\nOp: %d, Time: %d, Name: %s \n", actual->ID, actual->tempo, actual->Name);

		// passar para o proximo produto
		actual = actual->next;
	}

	fclose(in);
	
}

// obter a operation
Operation getOperation(Operation* operationHead, int id) 
{
	// variaveis
	Operation *actual, *operationFound;

	// inicializar
	operationFound = NULL;

	// inicializar a variavel atual
	actual = operationHead;

	// precorer operations
	while (actual != NULL && operationFound == NULL)
	{
		// verificar se é o produto pretendido
		if (actual->ID == id)
			operationFound = actual;

		// ir para o proximo produto
		actual = actual->next;
	}

	// se não encontrar nenhum produto
	if (operationFound == NULL)
	{
		printf("\nThe operation %d dont exist\n", id);
		return;
	}

	// retornar o produto
	return *operationFound;

}

void removeOperation(Operation* operationHead, int id) {
	
	if (isEmpty(operationHead)) {
		printf("\na lista está vazia...\n");
		return;
	}

	if (operationHead->ID == id) {	
		//remove no inicio da lista
		Operation* aux = operationHead;
		operationHead = operationHead->next;
		free(aux);
	}
	else
	{
		Operation* aux = operationHead;
		Operation* auxAnt = aux;
		while (aux && aux->ID != id) {	//procura para revover
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->next = aux->next;
			free(aux);
		}
	}
}

 /*mostrar produtos head para tail*/
float calcularMediaOperations(Operation* operation)
{
	// variaveis
	Operation* actual;
	int sumTime = 0;
	int numberOfOperations = 0;

	// inicializar a variavel actual
	actual = operation;

	// mostrar estudantes na lista
	while (actual != NULL)
	{
		sumTime += actual->tempo;
		numberOfOperations += 1;

		// passar para o proximo produto
		actual = actual->next;
	}

	float media = sumTime / (float)numberOfOperations;

	return media;
}

bool isEmpty(Operation* operation)
{
	// verificar se a lista está vazia
	if (operation == NULL)
		return true;
	else
		return false;
}

float Minimo(Operation* operation, int id)
{
	// variaveis
	Operation* actual;
	int sumTime = 0;
	int numberOfOperations = 0;

	// inicializar a variavel actual
	actual = operation;

	int minimo = 9999;

	//calcular o minimo
	while (actual != NULL)
	{
		if (actual->ID == id)
		{
			if (actual->tempo < minimo)
			{
				minimo = actual->tempo;
			}
			actual = actual->next;
		}
		else
		{
			actual = actual->next;
		}
	}


	return minimo;
}
float Maximo(Operation* operation, int id)
{
	// variaveis
	Operation* actual;
	int sumTime = 0;
	int numberOfOperations = 0;

	// inicializar a variavel actual
	actual = operation;

	int maximo = 0;

	// mostrar estudantes na lista
	while (actual != NULL)
	{
		if (actual->ID == id)
		{
			if (actual->tempo > maximo)
			{
				maximo = actual->tempo;
			}
			// passar para o proximo produto
			actual = actual->next;
		}
		else
		{

			// passar para o proximo produto
			actual = actual->next;
		}
	}


	return maximo;
}