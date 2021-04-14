#include<vector>
#include<string>

using namespace std;

class Escalonamento{
public:
    void readInstance(string arquivo);
    unsigned int getNumberTasks();
    unsigned int getNumberMachines();
    unsigned int getMakeSpan();
    vector<unsigned int>* getTasks();
    void printMachine();
    void setOrder(bool pOrder);
    void setRelativize(bool pRelativize);
    bool getRelativize();
    void setSubtract(bool pSubtract);

    //sensores
    unsigned int getNextTask();
    unsigned int getNumberNextTask();
    double getSensorMachine(unsigned int i);
    bool escalando();
    void reset();
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
    unsigned int makeSpan;
    bool escal;
    bool order;
    bool relativize;
    bool subtract;
};
