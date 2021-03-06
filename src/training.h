#include <vector>
#include "Net.h"
#include "escalonamento.h"
#include <string>
void escalonamento_training(char* net_file, char* instance_list_file, bool order, bool relativize, bool subtract, unsigned int nGenerations, unsigned int nPopulation, unsigned int nHiddenLayers, unsigned int nHiddenNeurons);
void play(Net *net, Escalonamento *escalonamento, int nInputs, int nOutputs, bool imprime, unsigned int* makeSpan);
void squareRandom_mutation(int nInputs, int nHiddenLayers, int nHiddenNeurons, int nOutputs,
		int nPopulation, int nGenerations, vector<Escalonamento>* escalonamentos, int nTrainingSet, char* net_file);
bool squareCompareByFitness(Net &a, Net &b);
void generateTrainingSet(vector<Escalonamento>* escalonamentos, unsigned int nTrainingSet, char* instance_list_file, bool order, bool relativize, bool subtract);
void run(char* net_file, char* instance_file, bool order, bool relativize, bool subtract, bool print, char* data_file);