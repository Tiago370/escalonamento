CXXFLAGS += -O3 -std=c++11 -Wall -Wextra -pedantic-errors

all: build/escalonamento

build/escalonamento: build/Neuron.o build/Net.o build/escalonamento.o build/main.o build/Util.o build/training.o
	$(CXX) $(CXXFLAGS) -o build/escalonamento build/*.o

build/Neuron.o: Neuron.cpp Neuron.h
	$(CXX) $(CXXFLAGS) -c Neuron.cpp -o build/Neuron.o

build/Net.o: Net.cpp Net.h
	$(CXX) $(CXXFLAGS) -c Net.cpp -o build/Net.o
	
build/escalonamento.o: escalonamento.cpp escalonamento.h
	$(CXX) $(CXXFLAGS) -c escalonamento.cpp -o build/escalonamento.o

build/Util.o: Util.cpp Util.h
	$(CXX) $(CXXFLAGS) -c Util.cpp -o build/Util.o

build/training.o: training.cpp training.h
	$(CXX) $(CXXFLAGS) -c training.cpp -o build/training.o

build/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

clean:
	$(RM) build/*.o build/rand-muta-neural-network
