#include <vector>
#include "Net.h"
#include "escalonamento.h"
void escalonamento_training();
void play(Net *net, Escalonamento *escalonamento, int nInputs, int nOutputs);
void squareRandom_mutation(int nInputs, int nHiddenLayers, int nHiddenNeurons, int nOutputs,
		int nPopulation, int nGenerations, vector<Escalonamento>* escalonamentos, int nTrainingSet);
bool squareCompareByFitness(Net &a, Net &b);
void generateTrainingSet(vector<Escalonamento>* escalonamentos, unsigned int nTrainingSet);