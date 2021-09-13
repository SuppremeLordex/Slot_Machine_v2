#pragma once
#include "Matrix.h"
#include "MatrixPharaohs.h"
#include "Bet.h"
#include "PaytableSuperFire.h"
#include "PaytableWisePharaohs5.h"
#include "PaytableTiger'sBAttle.h"
#include "Gamble.h"
#include "CreditField.h"
#include "Select_Game.h"
#include<windows.h>
#include "Keno.h"
#include "Keno_HotAndCold.h"
class Start : Matrix {
private:
	double  _credits;
	unsigned int _bet;

public:
	Start();
	Start(double credits, unsigned int bet);
	~Start();
	double takeCreditsWithBet(double& credits, unsigned int& bet);
	void StartGameNow(double& credits, unsigned int& bet);
	void StartGameNowSuperFire10(double& credits, unsigned int& bet);
	void StartGameNowWisePharaohs5(double& credits, unsigned int& bet);
	void StartGameNowTigersBattle5(double& credits, unsigned int& bet);
	void StartGameNowTigersBattle10(double& credits, unsigned int& bet);
	void StartGameNowKeno(double& credits, unsigned int& bet);
	void checkForCreditsAndBet(double& credits, unsigned int& bet);
	void checkForCreditsAndBetSuperFire10(double& credits, unsigned int& bet);
	void outputCreditsAndBetCurrent(double& credits, unsigned int& bet);
	void outputCreditsAndBetCurrentFreeGames(double& credits, unsigned int& bet);
	double getStartCredits();

}; 
