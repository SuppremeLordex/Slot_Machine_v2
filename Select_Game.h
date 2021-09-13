#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "PrintGameName.h"
#include "CreditField.h"
#include "Bet.h"
#include "Matrix.h"
#include "MatrixPharaohs.h"
#include "Start.h"
#include <chrono>
#include <thread>
class SelectGame {
private:
	std::vector<std::vector<std::string>> _selectGameMatrix;
	double _credits;
public:
	SelectGame(std::vector<std::vector<std::string>> selectGameMatrix, double credits);
	~SelectGame();
	SelectGame();
	void selectGame_Games();
	void selectGame_Welcome();
	double selectGame_Option(double &credits);
};