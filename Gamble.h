#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
class Gamble {
private:
	double _creditGamble;
public:
	Gamble(double creditGamble);
	~Gamble();
	Gamble();
	double CallGamble(double &creditGamble);
	void GambleInfoScreen();
};