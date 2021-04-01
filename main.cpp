#include <iostream>
#include "escalonamento.h"
#define DEBUG 0

using namespace std;
int main() {
	Escalonamento escalonamento = Escalonamento();
	escalonamento.readInstance("instancias/sched_11_1009_crescente");
	for(unsigned i = 0; i < escalonamento.getNumberTask(); i++){
		escalonamento.putTaskOnTheMachine(0);
	}
	cout << escalonamento.getSensorMachine(1) << endl;
	return 0;
}
