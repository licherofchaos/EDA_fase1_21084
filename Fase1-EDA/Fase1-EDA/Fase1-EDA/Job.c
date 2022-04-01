#define _CRT_SECURE_NO_WARNINGS
#include "Job.h"
#include "Operation.h"
#include <stdbool.h>

void CreateJob(Job** job, int iD) {
	
	Job* newJob = (Job*)malloc(sizeof(Job));
	Job* last = *job;

	newJob->ID = iD;
	newJob->OperationsList = NULL;
	newJob->next = NULL;

	if (IsEmpty(*job))
	{
		*job = newJob;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = newJob;


}

void AddOperations(Job* job, int iD, Operation* operations)
{
	// variaveis
	Job* actual;
	bool edited = false;

	// igualar a atual a recebida
	actual = job;

	// encontrar a maquina pretendida
	while (actual != NULL && edited == false)
	{
		if (actual->ID == iD)
		{
			actual->OperationsList = operations;
			edited = true;
		}
		actual = actual->next;
	}
}


bool IsEmpty(Job* job)
{
	// verificar se a lista está vazia
	if (job == NULL)
		return true;
	else
		return false;
}

// mostrar produtos head para tail
void ShowJobs(Job* job)
{
	// variaveis
	Job* actual;

	// titulo
	printf("\n Job forma ascendente...\n");

	// inicializar a variavel actual
	actual = job;

	// mostrar estudantes na lista
	while (actual != NULL)
	{
		// apresentar produtos
		printf("Codigo: %d \n", actual->ID);

		if (actual->OperationsList == NULL)
		{
			printf("No Operations");
		}
		else
		{
			ShowOperations(actual->OperationsList);
		}

		// passar para o proximo produto
		actual = actual->next;
	}

	
}

void Readfile() {

	FILE* read;
	char texto_str[50];

	read = fopen("Process.txt", "r");
	if (read == NULL)
	{
		printf("ERROR: couldnt load file.txt\n");
	}

	while (fgets(texto_str, 50, read) != NULL)
	{
		printf("%s", texto_str);
	}

	fclose(read);

}
