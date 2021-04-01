#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include "training.h"
//#include "escalonamento.h"
#include "Net.h"
using namespace std;
void play(Net *net, Escalonamento *escalonamento, int nInputs, int nOutputs){
	//estruturas auxiliares
    vector<double> inputs(nInputs);
	vector<double> outputs(nOutputs);
    for(unsigned int s = 0; s < escalonamento->getNumberTasks() ; s++){
        for(unsigned int i = 0; i < escalonamento->getNumberMachines(); i++){
            inputs[i] = escalonamento->getSensorMachine(i);
        }
        inputs[11] = escalonamento->getNumberNextTask();
        inputs[12] = escalonamento->getNextTask();

        net->activateLayers(&(inputs), &outputs);
        bool flag = false;
        for(unsigned int j = 0; j < outputs.size(); j++){
            if(outputs[j] > 0){
                escalonamento->putTaskOnTheMachine(j);
                flag = true;
                break;
            }
        }
        if(!flag) escalonamento->putTaskOnTheMachine(0);
        //cout << escalonamento->getNumberMachines() << endl;
    }
//    double fitness = (double)net->getFitness() + (double)square->fitness();
    net->setFitness(net->getFitness() + escalonamento->getMakeSpan());
    escalonamento->reset();
}

void escalonamento_training(){
	srand(666); //Fixar uma seed para permitir a reprodutibulidade

	int nInputs = 13;// 11 maquinas + numero da tarefa + tarefa
	int nHiddenLayers = 10;
	int nHiddenNeurons = 10;
	int nOutputs = 11;

	int nGenerations = 1000;
	int nPopulation = 50;

    //criar o conjuto de pares
    unsigned int nTrainingSet = 5;
    vector<Escalonamento> escalonamentos;
    generateTrainingSet(&escalonamentos, nTrainingSet);
	squareRandom_mutation(nInputs, nHiddenLayers, nHiddenNeurons, nOutputs, nPopulation, nGenerations, &escalonamentos, nTrainingSet);
}
void squareRandom_mutation(int nInputs, int nHiddenLayers, int nHiddenNeurons, int nOutputs,
		int nPopulation, int nGenerations, vector<Escalonamento>* escalonamentos, int nTrainingSet){
	Net champion(nInputs, nHiddenLayers, nHiddenNeurons, nOutputs);
    champion.setFitness(__DBL_MAX__);
	vector<Net> populacao;
	for(int i = 0; i < nPopulation; i++){
		populacao.push_back(Net(nInputs, nHiddenLayers, nHiddenNeurons, nOutputs));
	}
	int generation_number = 0;
    long long fitness = LONG_LONG_MAX;
    int nElite = nPopulation*0.05;
	//Criterio de parada
	while(generation_number < nGenerations){
        //cerr << "aqui começo" << endl;
		//Para cada individuo da populacao
		for(int i = 0; i < nPopulation; i++){
			if(i >= nElite) populacao[i].mutation();
            populacao[i].setFitness(0);
            //Para cada caso de teste
            for(int j = 0; j < nTrainingSet; j++){
                play(&populacao[i], &(escalonamentos->at(j)), nInputs, nOutputs);
                //if(j == 0) exit(0);
            }
            if(populacao[i].getFitness() < fitness){
                champion.copiar_rede(&populacao[i]);
                champion.setFitness(populacao[i].getFitness());
                fitness = populacao[i].getFitness();
                cout << "Melhor Fitness: " << fitness << endl;
            }

        }

		//Tentativa 1: os piores individuos serao refeitos, isso introduz aleatoriedade
		sort(populacao.begin(), populacao.end(), squareCompareByFitness);
        for(unsigned int i = 0 ; i < populacao.size(); i++){
            //cout << i << ": "<< populacao[i].getFitness() << endl;
        }
        double rDesc = (double)generation_number/nGenerations;
        if(rDesc < 0.1) rDesc = 0.1;
        if(rDesc > 0.9) rDesc = 0.9;
        cout << "Relite: " << rDesc << endl;
		for(int i = nElite; i < (int)nPopulation*rDesc; i++){
            populacao[i].copiar_rede(&(populacao[i%nElite]));
		}
		for(int i = (int)nPopulation*rDesc; i < nPopulation; i++){
			populacao[i].rerandom();
		}

		//Tentativa 2: a cada 100 geracoes eu coloco o campeao de volta na populacao
		if(generation_number%1 == 0){
			//campeao se reproduz
			//populacao[nPopulation-1].copiar_rede(&champion);
		}
		generation_number++;
        //cerr << "aqui fim" << endl;

	}
    cout << "Fitness do campeão " << champion.getFitness() << endl;
    champion.saveNet("champion.txt");
}

bool squareCompareByFitness(Net &a, Net &b){
    if(a.getFitness() < b.getFitness()){
        return true;
    }
	return false;
}

void generateTrainingSet(vector<Escalonamento>* escalonamentos, unsigned int nTrainingSet){
    string pasta = "instancias/";
    vector <string> arquivos = {"sched_11_1009_crescente","sched_11_1009_decrescente","sched_11_1009_embaralhado1","sched_11_1009_embaralhado2","sched_11_1009_embaralhado3"};
    for(unsigned int i = 0; i < nTrainingSet; i++){
        string caminho = pasta + arquivos[i];
        char *arqui = (char*) malloc((caminho.size() + 1)*sizeof(char));
        caminho.copy(arqui, caminho.size() + 1);
        arqui[caminho.size()] = '\0';
        Escalonamento escalonamento = Escalonamento();
	    escalonamento.readInstance(arqui);
        escalonamentos->push_back(escalonamento);
    }
 }