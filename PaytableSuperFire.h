#pragma once
#include <vector>
#include <iostream>
#include "Gamble.h"
class PaytableSuperFire {
private:
	std::vector<std::vector<int>>_myVectorInPaytableSuperFire;
	double _creditInPaytable;
	unsigned int _betInPaytable;
public:
	PaytableSuperFire(std::vector<std::vector<int>>myVectorInPaytableSuperFire, double creditInPaytable, unsigned int betInPaytable);
	double PaytableSuperFireWin(std::vector<std::vector<int>>&myVectorInPaytableSuperFire, double &creditInPaytable, unsigned int &betInPaytable);
	void PaytableSuperFireInfo();
	void PaytableSuperFireInfo10();
	double PaytableSuperFireWin10(std::vector<std::vector<int>>& myVectorInPaytableSuperFire, double& creditInPaytable, unsigned int& betInPaytable);
};