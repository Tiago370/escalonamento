/*
 * Util.h
 *
 *  Created on: 12 de fev. de 2021
 *      Author: hokama
 */


#ifndef UTIL_H_
#define UTIL_H_

#include <vector>
#include <string>

using namespace std;

string vectorToString(vector<int>* v);
string doubleVectorToString(vector<double>* v);
void transferList(vector <int>* origem, vector <int>* destino);

int retira(vector<unsigned int> &v, unsigned int i);
void insereNoComeco(vector<unsigned int> &v, int value);
void empacota(vector<unsigned int> &v, int pos, int value);
void print(vector<unsigned int>* v);


#endif /* UTIL_H_ */
