#pragma once
#include <stdbool.h>
#include <string.h> 

#define MAX 40
#define MMAX 8
typedef struct operation {
	int ID;
	char Name[MAX];
	int IDmaquina;
	int tempo;
	struct operation* next;
	
} Operation;



void CreateOperations(Operation** operation, int iD, int time, char* name);
void ModifyOperation(Operation* actualOperation, Operation newOperation);
Operation getOperation(Operation* operationHead, int id);
void ShowOperations(Operation* operation);
bool isEmpty(Operation* operation);
void removeOperation(Operation* operationHead, int id);
float calcularMediaOperations(Operation* operation);
float Minimo(Operation* operation, int id);
float Maximo(Operation* operation, int id);

