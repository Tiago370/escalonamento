#include<stdio.h>
#include<iostream>
#include "escalonamento.h"

#define DEBUG 0

Escalonamento::Escalonamento(){
    nMachines = 0;
	nTasks = 0;
    nextTask = 0;
    numberNextTask = 0;
    makeSpan = 0;
    escal = true;
}

Escalonamento::~Escalonamento(){}

void Escalonamento::readInstance(string arquivo){
    FILE *arq;
    char *arqui = (char*) malloc((arquivo.size() + 1)*sizeof(char));
    arquivo.copy(arqui, arquivo.size() + 1);
    arqui[arquivo.size()] = '\0';
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(arqui, "rt");
	if (arq == NULL){  // Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
    	return;
  	}
    int erroLeitura;
  	//ler o número de máquinas e o número de tarefas
	erroLeitura = fscanf(arq, "%d %d", &nMachines, &nTasks);
    //ler as tarefas
    for(int i = 0; i < nTasks; i++){
        int itemTask;
        erroLeitura = fscanf(arq, "%d", &itemTask);
        task.push_back(itemTask);
    }
  	fclose(arq);
    nextTask = task[0];
    if(erroLeitura == EOF) cout << "Erro de leitura" << endl;
    //criar as maquinas
    for(int i = 0; i < nMachines; i++){
        machine.push_back(0);
    }
}
unsigned int Escalonamento::getNextTask(){
    return  nextTask;
}
unsigned int Escalonamento::getNumberNextTask(){
    return (unsigned int) numberNextTask;
}
unsigned int Escalonamento::getSensorMachine(unsigned int i){
    return machine[i];
}
void Escalonamento::putTaskOnTheMachine(unsigned int i){
    machine[i] += nextTask;
    if(machine[i] > makeSpan) makeSpan = machine[i];

    numberNextTask++;
    if(numberNextTask == nTasks){
        escal = false;
    }else{
        nextTask = task[numberNextTask];
    }
}
unsigned int Escalonamento::getNumberTasks(){
    return nTasks;
}
unsigned int Escalonamento::getNumberMachines(){
    return nMachines;
}
 unsigned int Escalonamento::getMakeSpan(){
     return makeSpan;
 }
 bool Escalonamento::escalando(){
     return escal;
 }
 void Escalonamento::reset(){
    nextTask = 0;
    numberNextTask = 0;
    makeSpan = 0;   
 }