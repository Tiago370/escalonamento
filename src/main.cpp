#include <iostream>
#include "training.h"
#include <string.h>
#define DEBUG 0

using namespace std;
int main(int argc, char **argv) {
	//escalonamento_training();
	//run("instancias/sched_11_103_embaralhado2");
	bool order = false;
	bool relativize = false;
	bool subtract = false;
	bool print = false;

	char *net_file = (char*) malloc(sizeof(char)*100);
	char *instance_list_file = (char*) malloc(sizeof(char)*100);
	char *instance_file = (char*) malloc(sizeof(char)*100);
	char *data_file = (char*) malloc(sizeof(char)*100);
	unsigned int nGenerations = 1000;
	unsigned int nPopulation = 100;
	unsigned int nHiddenLayers = 2;
	unsigned int nHiddenNeurons = 13;

	if (argc < 2){
        printf("Argumentos insuficientes. Informe a função a ser executada: 'train' ou 'run'. Ex:\n");
        printf("    ./build/escalonamento <função>\n");
        exit(1);
    }else if (strcmp("run", argv[1]) == 0){
		for(int i = 2; i < argc; i++){
			if(strcmp("-order", argv[i]) == 0){
				order = true;
			}else if(strcmp("-relativize", argv[i]) == 0){
				relativize = true;
			}else if(strcmp("-subtract", argv[i]) == 0){
				subtract = true;
			}else if(strcmp("-net", argv[i]) == 0){
				strcpy(net_file, argv[i+1]);
				//printf("%s\n", net_file);
			}else if(strcmp("-instance", argv[i]) == 0){
				//printf("instance\n");
				strcpy(instance_file, argv[i+1]);
				//printf("%s\n", instance_list_file);
			}else if(strcmp("-print", argv[i]) == 0){
				//printf("printando\n");
				print = true;
			}else if(strcmp("-data", argv[i]) == 0){
				strcpy(data_file, argv[i+1]);
			}else{}
		}
		run(net_file, instance_file, order, relativize, subtract, print, data_file);
        exit(0);
    }else if (strcmp("train", argv[1]) == 0){
		for(int i = 2; i < argc; i++){
			if(strcmp("-order", argv[i]) == 0){
				order = true;
			}else if(strcmp("-relativize", argv[i]) == 0){
				relativize = true;
			}else if(strcmp("-subtract", argv[i]) == 0){
				subtract = true;
			}else if(strcmp("-net", argv[i]) == 0){
				strcpy(net_file, argv[i+1]);
				//printf("%s\n", net_file);
			}else if(strcmp("-instance", argv[i]) == 0){
				//printf("instance\n");
				strcpy(instance_list_file, argv[i+1]);
				//printf("%s\n", instance_list_file);
			}else if(strcmp("-generations", argv[i]) == 0){
				nGenerations = atoi(argv[i+1]);
				printf("nGenerations: %d\n", nGenerations);
			}else if(strcmp("-population", argv[i]) == 0){
				nPopulation = atoi(argv[i+1]);
			}else if(strcmp("-hidden-layers", argv[i]) == 0){
				nHiddenLayers = atoi(argv[i+1]);
				printf("nHiddenLayers: %d\n", nHiddenLayers);
			}else if(strcmp("-hidden-neurons", argv[i]) == 0){
				nHiddenNeurons = atoi(argv[i+1]);
			}else{}
		}
		escalonamento_training(net_file, instance_list_file, order, relativize, subtract, nGenerations, nPopulation, nHiddenLayers, nHiddenNeurons);
		//exit(1);
	}else{}
	//free(net_file);
	//free(instance_list_file);
	return 0;
}
