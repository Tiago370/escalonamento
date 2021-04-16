CXXFLAGS += -O3 -std=c++11 -Wall -Wextra -pedantic-errors

all: build/escalonamento

build/escalonamento: build/Neuron.o build/Net.o build/escalonamento.o build/main.o build/Util.o build/training.o
	$(CXX) $(CXXFLAGS) -o build/escalonamento build/*.o

build/Neuron.o: src/Neuron.cpp src/Neuron.h
	$(CXX) $(CXXFLAGS) -c src/Neuron.cpp -o build/Neuron.o

build/Net.o: src/Net.cpp src/Net.h
	$(CXX) $(CXXFLAGS) -c src/Net.cpp -o build/Net.o
	
build/escalonamento.o: src/escalonamento.cpp src/escalonamento.h
	$(CXX) $(CXXFLAGS) -c src/escalonamento.cpp -o build/escalonamento.o

build/Util.o: src/Util.cpp src/Util.h
	$(CXX) $(CXXFLAGS) -c src/Util.cpp -o build/Util.o

build/training.o: src/training.cpp src/training.h
	$(CXX) $(CXXFLAGS) -c src/training.cpp -o build/training.o

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o

clean:
	$(RM) build/*.o build/rand-muta-neural-network
