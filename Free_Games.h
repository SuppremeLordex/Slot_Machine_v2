#pragma once
#include "Matrix.h"
#include "Bet.h"
//#include "PaytableSuperFire.h"
#include "Gamble.h"
#include "CreditField.h"
#include "Select_Game.h"
#include<windows.h>
#include "Start.h"
#include "PaytableWisePharaohs5.h"
class Free_Games {
private:
	double _credits;
	unsigned int _bet;
public:
	Free_Games(double credits, unsigned int  bet);
	~Free_Games();
	double Free_GamesWin(double &credits, unsigned int &bet);
};