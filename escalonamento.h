#include<vector>
#include<string>

using namespace std;

class Escalonamento{
public:
    void readInstance(string arquivo);
    unsigned int getNumberTask();

    //sensores
    unsigned int getNextTask();
    unsigned int getNumberNextTask();
    unsigned int getSensorMachine(unsigned int i);

    //controles
    void putTaskOnTheMachine(unsigned int i);
	Escalonamento();

	~Escalonamento();


private:
	vector<unsigned int> machine;
    vector<unsigned int> task;
	int nMachines;
	int nTasks;
    int nextTask;
    int numberNextTask;
};
