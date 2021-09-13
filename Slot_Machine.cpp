#include <iostream>
#include "CreditField.h"
#include "Matrix.h"
#include "Bet.h"
#include "Start.h"
#include "PaytableSuperFire.h"
#include "PaytableWisePharaohs5.h"
#include "PrintGameName.h"
#include "Gamble.h"
#include "Select_Game.h"
#include "Free_Games.h"
#include "MatrixPharaohs.h"
#include "PaytableTiger'sBattle.h"
#include "Keno.h"
#include "Keno_HotAndCold.h"
#include <iomanip>

//prefix setprecision double credit;
//make RTP Game
//Finish Keno
//make a github for the project
//refactor the code

int main()
{
    double credits = 0;
    //select Game
    SelectGame selectgame;
    selectgame.selectGame_Welcome();
    selectgame.selectGame_Games();
    //choosing a game
    selectgame.selectGame_Option(credits);
}


