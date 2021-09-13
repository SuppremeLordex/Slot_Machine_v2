#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include "Gamble.h"
#include "Keno_HotAndCold.h"
#include <unordered_set>
class Keno {
private:
	double _credits;
	unsigned _bet;
	std::vector<std::vector<int>> _kenoVector;
public:
	//Keno();
	Keno(std::vector<std::vector<int>> kenoVector, double credits, unsigned bet);
	~Keno();
	std::vector<std::vector<double>> fillKenoVector();
	std::vector<int> selectNumbers();
	void outputGeneratedNumbers(std::vector<int>& outputVector);
	std::vector<int> generate20Numbers();
	double checkForHits(double &credits, unsigned int &bet);
	void infoPageKeno();
};