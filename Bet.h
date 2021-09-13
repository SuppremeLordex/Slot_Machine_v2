#pragma once
#include <vector>
#include <iostream>
#include "Credit.h"
#include "Select_Game.h"

class Bet {
private:
	unsigned int _bet_bet;
	double _credit_bet;
public:
	Bet(unsigned int bet, double credit);
	unsigned int selectBet( unsigned int &bet, double &credit);
	unsigned int selectBetSuperFire10(unsigned int& bet, double& credit);
	unsigned int selectBetWisePharaohs(unsigned int& bet, double& credit);
	unsigned int selectBetTigersBattle10(unsigned int& bet, double& credit);
	unsigned int selectBetTigersBattle5(unsigned int& bet, double& credit);
	unsigned int selectBetKeno(unsigned int& bet, double& credit);
	Bet();
	~Bet();
};