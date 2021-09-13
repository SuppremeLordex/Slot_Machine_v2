#include "Free_Games.h"
int const FreeGamesSize = 15;
Free_Games::Free_Games(double credits, unsigned int  bet) {
	_credits = credits;
	_bet = bet;
}

double Free_Games::Free_GamesWin(double& credits, unsigned int  &bet) {
	//int currentBet = bet;
	//no bet in Free Spins
	//bet = 0;
	std::cout << "You Won 50 Euros!" << std::endl;
	std::cout << "They will be transfered in Credit Field After Free Games!" << std::endl;
	std::cout << "3x Multiplier! on every line" << std::endl;
	unsigned int betInFreeGames = 0;
	std::string p;
	Start startFreeSpin;
	Matrix mymatrix;
	Bet betFreesSpin;
	int currentGame = 1;
	std::vector<std::vector<int>>myVectorInStart;
	bool isInFreeGames = true;
	PaytableWisePharaohs5 paytableForGame(myVectorInStart, credits, bet, isInFreeGames);
	myVectorInStart = mymatrix.getVectorMatrix();
	//clears screen
	//if (system("CLS")) system("clear");
	for (int i = 0; i < FreeGamesSize; ++i) {
		std::cout << "Current Game: " << currentGame << " of " << FreeGamesSize << std::endl;
		std::cout << "Press 'v' to Start a Game!" << std::endl;
		std::cin >> p;
		if (p[0] == 'v' && p.size() == 1) {
			startFreeSpin.takeCreditsWithBet(credits, betInFreeGames);
			//need to change matrix with 6 figures! --- DONT!
			mymatrix.RandomNumbersInMatrix(myVectorInStart);
			
			std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			mymatrix.outPutMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl;
			startFreeSpin.checkForCreditsAndBet(credits, bet);
			startFreeSpin.outputCreditsAndBetCurrentFreeGames(credits, bet);
			paytableForGame.PaytableWisePharaohs5Win(myVectorInStart, credits, bet, isInFreeGames);
			currentGame++;
		}
		/*else {
			if (i != 0) {
				i--;
			}
		}*/
		myVectorInStart.clear();
	}
	
	return credits ;
}
Free_Games::~Free_Games() {
	//just deconstructing
}