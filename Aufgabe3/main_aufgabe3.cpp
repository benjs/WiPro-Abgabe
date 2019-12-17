/*
 * main_aufgabe3.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */
// ggf hilfreiche Bibliotheken....
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>
#include <vector>
#include <array>
#include <cassert>

#include "MyQuaternion.h"
#include "MyFunctions.h"
#include "quarternion_functions.h"

int main(){
	//generate data:
	Vec4d tmp;
	int nmax;

	do{
		std::cout<<"Anzahl der Zufallsorientierungen eingeben:";
		std::cin>>nmax;
	}while(nmax<1);

	std::vector<MyQuaternion> QL(nmax);

	//random Initialisierung:
	for (auto &Q: QL) {
		random_vec4d(Q);
	}

	//AUFGABE 3:

	//TEIL A)
	std::cout<<"Aufgabe A:"<<std::endl;

	std::vector<double> misorientations;
	for(int i = 0; i < QL.size(); i++) {
		// Mit int j=i+1 wird verhindert dass zweimal die gleichen Elemente verglichen werden
		for (int j = i+1; j < QL.size(); j++) {
			misorientations.emplace_back(get_theta(QL[i]*QL[j].conj()));
		}
	}

	saveData("Aufgabe3/ergebnis_random.dat", misorientations);

	auto hist = getNormalizedHist(misorientations);
	saveData("Aufgabe3/hist_random.dat", hist);

	//TEIL B)
	std::cout<<"Aufgabe B:"<<std::endl;
	/*some code; calls
	 *
	 */
	std::vector<double> misorientations_sym;
	for(int i = 0; i < QL.size(); i++) {
		// Mit int j=i+1 wird verhindert dass zweimal die gleichen Elemente verglichen werden
		for (int j = i+1; j < QL.size(); j++) {
			misorientations_sym.emplace_back(get_theta_cubic(QL[i]*QL[j].conj()));
		}
	}

	saveData("Aufgabe3/ergebnis_cube.dat", misorientations_sym);

	auto hist_sym = getNormalizedHist(misorientations_sym);
	saveData("Aufgabe3/hist_cube.dat", hist_sym);

	double sum = 0;
	for (auto &el : hist_sym) {
		sum += el.second;
	}

	std::cout<<"DONE"<<std::endl;

	return 0;
}

