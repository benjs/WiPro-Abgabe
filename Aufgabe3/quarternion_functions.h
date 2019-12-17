// Funktionen ausgelagert um Aufgabe 3 testbar zu machen.

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>
#include <vector>
#include <array>
#include <cassert>
#include <iterator>

#include "MyQuaternion.h"
#include "MyFunctions.h"

// Abkuerzungen fuer Datentypen:
typedef std::array<double,4> Vec4d;

// for seed of random number generator in C++11
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> zufall(-1.,1.); //C++11 documentation
//http://www.cplusplus.com/reference/random/uniform_real_distribution/


//Hilfsfunktion fuer random_vec4d:
void zufall_in_einheitskreis(double &a, double &b, double &s){
	do{
		a = zufall(mt);
		b = zufall(mt);
		s = (a*a+b*b);
	}while(s>=1.);
}

// Algorithm 4 of Marsaglia paper, The Annals of Math. Stat. 1972,645-6
// random point on a surface
// hier: Methode 4: point on unit 4d-sphere
//
void random_vec4d(MyQuaternion &Q){
	double v1,v2,v3,v4,s1,s2;
	zufall_in_einheitskreis(v1,v2,s1);
	zufall_in_einheitskreis(v3,v4,s2);
	//
	const double tmp = sqrt(std::max(0.,(1.-s1))/s2);
	Q[0]= v1;
	Q[1]= v2;
	Q[2]= v3*tmp;
	Q[3]= v4*tmp;
}


// Aufgabe 3.2.A:
double get_theta(const MyQuaternion &Q){
	// einfügen..
	return 2*acos(Q[3])/M_PI*180;
}

//Aufgabe 3.2.B:
double get_theta_cubic(const MyQuaternion &Q){
	// einfügen..
	MyQuaternion Q1(Q.sortAscending());
	MyQuaternion Q2 {Q1[0] - Q1[1], Q1[0] + Q1[1], Q1[2] - Q1[3], Q1[2] + Q1[3]};
	Q2 = Q2 * (1/sqrt(2));

	MyQuaternion Q3 {
		Q1[0] - Q1[1] - Q1[3] + Q1[2],
		Q1[0] + Q1[1] - Q1[3] - Q1[2],
		Q1[2] - Q1[3] - Q1[0] + Q1[1],
		Q1[0] + Q1[1] + Q1[3] + Q1[2]
	};
	Q3 = Q3 * (1/sqrt(2));

	std::array<double, 3> angles {get_theta(Q1*Q2), get_theta(Q1*Q3), get_theta(Q2*Q3)};
	return *std::min_element(angles.begin(), angles.end());
}

template<typename T>
void saveData(std::string filename, std::vector<T> vec) {
	// Daten abspeichern
	std::ofstream file;
	file.open(filename, std::ios::out);
	
	for (auto el : vec) {
		file << el << std::endl;
	}

	file.close();
}

// Little trick
class myPair : public std::pair<double, double> {
	public:
		friend std::ostream& operator<<(std::ostream& os, myPair& pair) {
			return os << pair.first << " " << pair.second;
		}
};

std::vector<myPair> getNormalizedHist(std::vector<double> vec, int num_bins=360, int max_val=360) {
	std::vector<myPair> hist(num_bins);
	
	for(int i=0; i < hist.size(); i++) {
		hist[i].first = i;
	}

	// Jeden Wert iterieren und bin zuweisen
	for(auto el : vec) {
		int bin = std::floor(el/max_val*num_bins);
		hist[bin].second++;
	}

	// Normieren
	for(auto &el: hist) {
		el.second /= vec.size();
	}

	return hist;
}
