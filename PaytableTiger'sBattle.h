#pragma once
#include <vector>
#include <iostream>
#include "Gamble.h"
class PaytableTigersBattle {
private:
	std::vector<std::vector<int>>_myVectorInPaytableTigersBattle;
	double _creditInPaytable;
	unsigned int _betInPaytable;
public:
	PaytableTigersBattle(std::vector<std::vector<int>>_myVectorInPaytableTigersBattle, double creditInPaytable, unsigned int betInPaytable);
	double PaytableTigersBattleWin5(std::vector<std::vector<int>>& _myVectorInPaytableTigersBattle, double& creditInPaytable, unsigned int& betInPaytable);
	double PaytableTigersBattleWin10(std::vector<std::vector<int>>& _myVectorInPaytableTigersBattle, double& creditInPaytable, unsigned int& betInPaytable);
	void PaytableTigersBattleWinInfo5();
	void PaytableTigersBattleWinInfo10();
	~PaytableTigersBattle();
	
};