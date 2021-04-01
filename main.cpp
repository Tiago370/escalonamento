#include <iostream>
#include "escalonamento.h"
#define DEBUG 0

using namespace std;
int main() {
	Escalonamento escalonamento = Escalonamento();
	escalonamento.readInstance("instancias/sched_11_1009_crescente");
	return 0;
}
