#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <fstream>
#include <time.h>
#include "training.h"
//#include "escalonamento.h"
#include "Net.h"
using namespace std;
void play(Net *net, Escalonamento *escalonamento, int nInputs, int nOutputs, bool imprime){
	//estruturas auxiliares
    vector<double> inputs(nInputs);
	vector<double> outputs(nOutputs);
    for(unsigned int s = 0; s < escalonamento->getNumberTasks() ; s++){
        for(unsigned int i = 0; i < escalonamento->getNumberMachines(); i++){
            inputs[i] = escalonamento->getSensorMachine(i);
        }
        //inputs[11] = escalonamento->getNumberNextTask();
        if(!escalonamento->getRelativize()){
            inputs[escalonamento->getNumberMachines()+1] = escalonamento->getNextTask();
        }
        if(imprime) cout << "index: " << escalonamento->getNumberNextTask() << " tam: " << escalonamento->getNextTask() << endl;
        net->activateLayers(&(inputs), &outputs);
        bool flag = false;
        for(unsigned int j = 0; j < outputs.size(); j++){
            if(outputs[j] > 0){
                escalonamento->putTaskOnTheMachine(j);
                if (imprime)escalonamento->printMachine();
                flag = true;
                break;
            }
        }
        if(!flag) escalonamento->putTaskOnTheMachine(nOutputs-1);
        //cout << escalonamento->getNumberMachines() << endl;
    }
//    double fitness = (double)net->getFitness() + (double)square->fitness();
    net->setFitness(net->getFitness() + escalonamento->getMakeSpan());
    if (imprime)escalonamento->printMachine();
    escalonamento->reset();
}

void escalonamento_training(char* net_file, char* instance_list_file, bool order, bool relativize, bool subtract, unsigned int nGenerations, unsigned int nPopulation, unsigned int nHiddenLayers, unsigned int nHiddenNeurons){
	srand(666); //Fixar uma seed para permitir a reprodutibulidade

	int nInputs = 10;// 11 maquinas + numero da tarefa + tarefa
    if(!relativize) nInputs++;
	int nOutputs = 10;

    //criar o conjuto de pares
    unsigned int nTrainingSet = 100;
    vector<Escalonamento> escalonamentos;
    generateTrainingSet(&escalonamentos, nTrainingSet, instance_list_file, order, relativize, subtract);
	squareRandom_mutation(nInputs, nHiddenLayers, nHiddenNeurons, nOutputs, nPopulation, nGenerations, &escalonamentos, nTrainingSet, net_file);
    exit(1);
}
void squareRandom_mutation(int nInputs, int nHiddenLayers, int nHiddenNeurons, int nOutputs,
		int nPopulation, int nGenerations, vector<Escalonamento>* escalonamentos, int nTrainingSet, char* net_file){
    cout << "nHiddenLayers: " << nHiddenLayers << " nHiddenNeurons: " << nHiddenNeurons << endl;
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
    unsigned int stop = 0;
    clock_t end,start;
    start = clock();
	while(generation_number < nGenerations && stop < 200){
        //cerr << "aqui começo" << endl;
		//Para cada individuo da populacao
		for(int i = 0; i < nPopulation; i++){
			if(i >= nElite) populacao[i].mutation();
            populacao[i].setFitness(0);
            //Para cada caso de teste
            for(int j = 0; j < nTrainingSet; j++){
                play(&populacao[i], &(escalonamentos->at(j)), nInputs, nOutputs, false);
                //if(j == 0) exit(0);
            }
            if(populacao[i].getFitness() < fitness){
                champion.copiar_rede(&populacao[i]);
                champion.setFitness(populacao[i].getFitness());
                fitness = populacao[i].getFitness();
                cout << "Melhor Fitness: " << fitness << endl;
                stop = 0;
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
        stop++;
        //cerr << "aqui fim" << endl;

	}
    end = clock();
    std::ofstream outfile;
    outfile.open("dados-treinamento-redes.csv", std::ios_base::app); // append instead of overwrite
    if(escalonamentos->at(0).getOrder()) outfile << "O";
    if(escalonamentos->at(0).getRelativize()) outfile << "R";
    if(escalonamentos->at(0).getSubtract()) outfile << "S";
    outfile << ",";
    outfile << nHiddenLayers;
    outfile << "x";
    outfile << nHiddenNeurons;
    outfile << ",";
    outfile << generation_number;
    outfile << ",";
    outfile << (double)(end-start)/(double)(CLOCKS_PER_SEC);
    outfile << endl;
    //outfile << "Configuraçao,Tamanho,nGerações,Tempo de Treinamento" << endl;
    outfile.close();
    cout << "Fitness do campeão " << champion.getFitness() << endl;
    //play(&champion, &(escalonamentos->at(0)), 13, 11, true);
    //play(&champion, &(escalonamentos->at(1)), 13, 11, true);
    //play(&champion, &(escalonamentos->at(2)), 13, 11, true);
    //play(&champion, &(escalonamentos->at(3)), nInputs, 10, true);
    //play(&champion, &(escalonamentos->at(4)), 13, 11, true);
    champion.saveNet(net_file);
}

bool squareCompareByFitness(Net &a, Net &b){
    if(a.getFitness() < b.getFitness()){
        return true;
    }
	return false;
}

void generateTrainingSet(vector<Escalonamento>* escalonamentos, unsigned int nTrainingSet,  char* instance_list_file, bool order, bool relativize, bool subtract){
    printf("Lendo instâncias da lista %s\n", instance_list_file);
    FILE *arq_instance_list_file;
    arq_instance_list_file = fopen(instance_list_file, "r");
    if (arq_instance_list_file == NULL){  // Se houve erro na abertura
        printf("Problemas na abertura do arquivo '%s'\n", instance_list_file);
  	}
    //string pasta = "instancias/";
    //vector <string> arquivos = {"sched_11_1009_crescente","sched_11_1009_decrescente","sched_11_1009_embaralhado1","sched_11_1009_embaralhado2","sched_11_1009_embaralhado3"};
    for(unsigned int i = 0; i < nTrainingSet; i++){
        char* instance = (char*) malloc(sizeof(char)*100);
        int retornoLeitura = fscanf(arq_instance_list_file, "%s", instance);
        if(!retornoLeitura) printf("Problemas na abertura do arquivo '%s'\n", instance);
        printf("%s\n", instance);
        Escalonamento escalonamento = Escalonamento();
	    escalonamento.readInstance(instance);
        escalonamento.setOrder(order);
        escalonamento.setRelativize(relativize);
        escalonamento.setSubtract(subtract);
        escalonamentos->push_back(escalonamento);
        free(instance);
    }
    fclose(arq_instance_list_file);
 }
 void run(char* net_file, char* instance_file, bool order, bool relativize, bool subtract){
    Escalonamento escalonamento = Escalonamento();
    printf("%s\n",instance_file);
	escalonamento.readInstance(instance_file);
    cout << "run" << endl;
    escalonamento.setOrder(order);
    escalonamento.setRelativize(relativize);
    escalonamento.setSubtract(subtract);
    cout << "run" << endl;
	Net net = Net(1,1,1,1);
    printf("%s\n",net_file);
	net.openNet(net_file);
    printf("%s\n",net_file);
    cout << "run" << endl;
    play(&net, &escalonamento, net.getNInputs(), net.getNOutput(), true);

}