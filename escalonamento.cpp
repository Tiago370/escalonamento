#include<stdio.h>
#include<iostream>
#include<limits.h>
#include "escalonamento.h"
#include "Util.h"

Escalonamento::Escalonamento(){
    nMachines = 0;
	nTasks = 0;
    nextTask = 0;
    numberNextTask = 0;
    makeSpan = 0;
    escal = true;
    order = false;
    relativize = false;
}

Escalonamento::~Escalonamento(){}

void Escalonamento::readInstance(char* arquiv){
    FILE *arq;
    //char *arqui = (char*) malloc((arquivo.size() + 1)*sizeof(char));
    //arquivo.copy(arqui, arquivo.size() + 1);
    //arqui[arquivo.size()] = '\0';
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(arquiv, "r");
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
double Escalonamento::getSensorMachine(unsigned int i){
    unsigned int smallestMachine;
    if(subtract){
        if(order){
            smallestMachine = machine[nMachines-1];
        }else{
            smallestMachine = INT32_MAX;
            for(int j = 0; j < nMachines; j++){
                if(machine[j] < smallestMachine) smallestMachine = machine[j];
            }
        }
    }else{
        smallestMachine = 0;
    }
    if(relativize){
        if(nextTask == 0) nextTask = 1;
        return (machine[i] - smallestMachine)/nextTask;    
    }else{
        return (machine[i] - smallestMachine);
    }
}
void Escalonamento::putTaskOnTheMachine(unsigned int i){
    if(order){
        empacota(machine, i, nextTask);
        makeSpan = machine[0];
    }else{
        machine[i] += nextTask;
        if(makeSpan < machine[i]){
            makeSpan = machine[i];  
        }
    }
    numberNextTask++;
    nextTask = task[numberNextTask];
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
    nextTask = task[0];
    numberNextTask = 0;
    makeSpan = 0;   
 
    for(int i = 0; i < nMachines; i++){
        machine[i] = 0;
    }

 }
 void Escalonamento::printMachine(){
     for(int i = 0; i < nMachines; i++){
         cout << machine[i] << " ";
     }
     cout << endl;
 }
 vector<unsigned int>* Escalonamento::getTasks(){
     return &task;
 }
 void Escalonamento::setOrder(bool pOrder){
     this->order = pOrder;
 }
 void Escalonamento::setRelativize(bool pRelativize){
    this->relativize = pRelativize;
 }
 bool Escalonamento::getRelativize(){
     return this->relativize;
 }
 void  Escalonamento::setSubtract(bool pSubtract){
     this->subtract = pSubtract;
 }