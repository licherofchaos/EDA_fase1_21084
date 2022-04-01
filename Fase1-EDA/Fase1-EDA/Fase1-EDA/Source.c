#define _CRT_SECURE_NO_WARNINGS

#include "Job.h"
#include "Operation.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {

	// variaveis
	Job* jobs;
	Operation* operation;
	Operation operation1;

	// inicializar listas
	jobs = NULL;
	operation = NULL;

	// Criar o job
	CreateJob(&jobs, 1);

	// Criar as operations e adicionar aos jobs
	CreateOperations(&operation, 1, "Cantar",1,3);
	CreateOperations(&operation, 2, "Comer", 2,2);
	CreateOperations(&operation, 3, "correr",3,4);
	AddOperations(jobs, 1, operation);
	
	// mostrar os jobs
	ShowJobs(jobs);

	// modificar a operação 1
	operation1 = getOperation(jobs->OperationsList, 1);

	ModifyOperation(jobs->OperationsList, operation1);

	//Remover operação
	removeOperation(jobs->OperationsList, 3);
	ShowOperations(jobs->OperationsList);

	// Calcular Media
	float calculaMedia = calcularMediaOperations(operation);
	printf("Tempo medio operacoees %.2f \n", calculaMedia);
	float calculamaximo = Maximo(operation, operation->ID);

	float calculaminimo = Minimo(operation, operation->ID);
	Readfile();

	return 0;
}