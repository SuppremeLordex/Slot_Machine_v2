#include "Start.h"


void Start::checkForCreditsAndBet(double& credits, unsigned int& bet) {
	if (bet > credits && credits >= 1) {
		std::cout << "Automatic change bet to min!" << std::endl;
		std::cout << "Not Enough Credits for Max Bet!" << std::endl;
		bet = 1;
	}
}
void Start::checkForCreditsAndBetSuperFire10(double& credits, unsigned int& bet) {
	if (bet > credits && credits >= 2) {
		std::cout << "Automatic change bet to min!" << std::endl;
		std::cout << "Not Enough Credits for Max Bet!" << std::endl;
		bet = 2;
	}
}
void Start::outputCreditsAndBetCurrent(double & credits, unsigned int& bet) {
	std::cout << "Current Credit: " << credits << " Euro." << std::endl;
	std::cout << "Current Bet: " << bet << " Euro." << std::endl;
}
void Start::outputCreditsAndBetCurrentFreeGames(double& credits, unsigned int& bet) {
	std::cout << "Current Credit: " << credits << " Euro." << std::endl;
	std::cout << "Current Bet: " << "No Bet in Free Games!" << std::endl;
}

Start::Start() {

}
Start::Start(double credits, unsigned int bet) {
	_credits = credits;
	_bet = bet;
	
}
double Start::getStartCredits() {
	return _credits;
}

double Start::takeCreditsWithBet(double & credits, unsigned int& bet) {
	credits = credits - bet;
	return credits;
}
//need to add funct to add money any time!
void Start::StartGameNow(double & credits, unsigned int& bet) {
	
	std::vector<std::vector<int>>myVectorInStart;
	myVectorInStart = getVectorMatrix();
	std::string p;
	
	unsigned int minBet = 1;
	PaytableSuperFire paytableForGame(myVectorInStart, credits, bet);
	while (credits >= 1) {
		if (credits < bet && credits >= 1) {
			bet = minBet;
			std::cout << "Changing Bet to min: " << bet <<" Euro!" << std::endl;
		}
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cout << "Press 'p' to Start a Game!" << std::endl;
			std::cout << "Press 'e' to Change the Bet!" << std::endl;
			std::cout << "Press 'i' to see the Paytable!" << std::endl;
			std::cout << "Press 'c' to Cashout!" << std::endl;
			std::cout << "Press 'g' to see the Gamble Info Screen!" << std::endl;
			std::cout << "Press 'a' to add credit!" << std::endl;
			std::cout << "Press 'q' for More Games!" << std::endl;
			std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
		
		std::cin >> p;
		//new code here for safety
		/*while(p.size() > 1) {
			std::cin >> p;
		}*/
		if (p[0] == 'p' && p.size()==1) {
			//clears screen
			if (system("CLS")) system("clear");

			takeCreditsWithBet(credits, bet);
			RandomNumbersInMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			outPutMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl;
			checkForCreditsAndBet(credits, bet);
			outputCreditsAndBetCurrent(credits,bet);
			paytableForGame.PaytableSuperFireWin(myVectorInStart,credits,bet);
		}
		if (p[0] == 'e' && p.size() == 1) {
			if (system("CLS")) system("clear");
			Bet settingBet(bet, credits);
			settingBet.selectBet(bet,credits );
		}
		if (p[0] == 'i' && p.size() == 1) {
			if (system("CLS")) system("clear");
			paytableForGame.PaytableSuperFireInfo();
		}
		if (p[0] == 'c' && p.size() == 1) {
			if (credits > 0.0) {
				std::cout << "Cashout..." << std::endl;
				std::cout << "Handpay! Call Attendant! " << credits << " Euro!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
				credits = 0;
			}
			else {
				std::cout << "Nothing to cashout!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
			}
			//exit(0);
		}
		if (p[0] == 'g' && p.size() == 1) {
			
			Gamble gambleInfoScreen;
			gambleInfoScreen.GambleInfoScreen();
		}
		if (p[0] == 'a' &&p.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (p[0] == 'q' && p.size() == 1) {
			SelectGame selectgame;
			selectgame.selectGame_Welcome();
			selectgame.selectGame_Games();

			//choosing a game
			selectgame.selectGame_Option(credits);
		}
	
		if (credits < 1 ) {
			std::cout << "No More Credits To Play on Min Bet! :(" << std::endl;
			CreditField addCreditBeforeExit;
			addCreditBeforeExit.AddCredit(credits);
			if (credits < 1) {
				std::cout << "You need to add atleast 1 Euro!" << std::endl;
				std::cout << "Cashout: " << credits << " Euro." << std::endl;
				credits = 0;
				Sleep(2000);
				SelectGame selectgame;
				selectgame.selectGame_Welcome();
				selectgame.selectGame_Games();

				//choosing a game
				selectgame.selectGame_Option(credits);
			}
		}
		
		myVectorInStart.clear();
	}
}

//Super Fire 10

void Start::StartGameNowSuperFire10(double& credits, unsigned int& bet) {

	std::vector<std::vector<int>>myVectorInStart;
	myVectorInStart = getVectorMatrix();
	std::string p;

	unsigned int minBet = 2;
	PaytableSuperFire paytableForGame(myVectorInStart, credits, bet);
	while (credits >= minBet) {
		if (credits < bet && credits >= minBet) {
			bet = minBet;
			std::cout << "Changing Bet to min: " << bet << " Euro!" << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		std::cout << "Press 'p' to Start a Game!" << std::endl;
		std::cout << "Press 'e' to Change the Bet!" << std::endl;
		std::cout << "Press 'i' to see the Paytable!" << std::endl;
		std::cout << "Press 'c' to Cashout!" << std::endl;
		std::cout << "Press 'g' to see the Gamble Info Screen!" << std::endl;
		std::cout << "Press 'a' to add credit!" << std::endl;
		std::cout << "Press 'q' for More Games!" << std::endl;
		std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
		std::cout << "********************************************************************************************************************" << std::endl;

		std::cin >> p;
		std::cin.ignore();
		//new code here for safety
		/*while(p.size() > 1) {
			std::cin >> p;
		}*/
		if (p[0] == 'p' && p.size() == 1) {
			//clears screen
			if (system("CLS")) system("clear");

			takeCreditsWithBet(credits, bet);
			RandomNumbersInMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			outPutMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl;
			checkForCreditsAndBetSuperFire10(credits, bet);
			outputCreditsAndBetCurrent(credits, bet);
			paytableForGame.PaytableSuperFireWin10(myVectorInStart, credits, bet);
		}
		if (p[0] == 'e' && p.size() == 1) {
			if (system("CLS")) system("clear");
			Bet settingBet(bet, credits);
			settingBet.selectBetSuperFire10(bet, credits);
		}
		if (p[0] == 'i' && p.size() == 1) {
			if (system("CLS")) system("clear");
			paytableForGame.PaytableSuperFireInfo10();
		}
		if (p[0] == 'c' && p.size() == 1) {
			if (credits > 0.0) {
				std::cout << "Cashout..." << std::endl;
				std::cout << "Handpay! Call Attendant! " << credits << " Euro!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
				credits = 0;
			}
			else {
				std::cout << "Nothing to cashout!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
			}
			//exit(0);
		}
		if (p[0] == 'g' && p.size() == 1) {

			Gamble gambleInfoScreen;
			gambleInfoScreen.GambleInfoScreen();
			
		}
		if (p[0] == 'a' && p.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (p[0] == 'q' && p.size() == 1) {
			SelectGame selectgame;
			selectgame.selectGame_Welcome();
			selectgame.selectGame_Games();

			//choosing a game
			selectgame.selectGame_Option(credits);
		}

		if (credits < minBet) {
			std::cout << "No More Credits To Play on Min Bet! :(" << std::endl;
			CreditField addCreditBeforeExit;
			addCreditBeforeExit.AddCredit(credits);
			if (credits < minBet) {
				std::cout << "You need to add atleast 2 Euro!" << std::endl;
				std::cout << "Cashout: " << credits << " Euro." << std::endl;
				credits = 0;
				Sleep(2000);
				SelectGame selectgame;
				selectgame.selectGame_Welcome();
				selectgame.selectGame_Games();

				//choosing a game
				selectgame.selectGame_Option(credits);
			}
		}

		myVectorInStart.clear();
	}
}

// Wise Pharaohs 5
void Start::StartGameNowWisePharaohs5(double& credits, unsigned int& bet) {
	std::vector<std::vector<int>>myVectorInStart;
	MatrixPharaohs matrix;
	myVectorInStart = matrix.getVectorMatrixPharaos();
	std::string p;
	bool isInFreeGames = false;
	unsigned int minBet = 1;
	PaytableWisePharaohs5 paytableForGame(myVectorInStart, credits, bet, isInFreeGames);
	while (credits >= 1) {
		if (credits < bet && credits >= 1) {
			bet = minBet;
			std::cout << "Changing Bet to min: " << bet << " Euro!" << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		std::cout << "Press 'p' to Start a Game!" << std::endl;
		std::cout << "Press 'e' to Change the Bet!" << std::endl;
		std::cout << "Press 'i' to see the Paytable!" << std::endl;
		std::cout << "Press 'c' to Cashout!" << std::endl;
		std::cout << "Press 'g' to see the Gamble Info Screen!" << std::endl;
		std::cout << "Press 'a' to add credit!" << std::endl;
		std::cout << "Press 'q' for More Games!" << std::endl;
		std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
		std::cout << "********************************************************************************************************************" << std::endl;

		std::cin >> p;
		//new code here for safety
		/*while(p.size() > 1) {
			std::cin >> p;
		}*/
		if (p[0] == 'p' && p.size() == 1) {
			//clears screen
			if (system("CLS")) system("clear");

			takeCreditsWithBet(credits, bet);
			MatrixPharaohs matrixPharaohs;
			matrixPharaohs.RandomNumbersInMatrixPharaohs(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			outPutMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl;
			checkForCreditsAndBet(credits, bet);
			outputCreditsAndBetCurrent(credits, bet);
			paytableForGame.PaytableWisePharaohs5Win(myVectorInStart, credits, bet, isInFreeGames);
		}
		if (p[0] == 'e' && p.size() == 1) {
			if (system("CLS")) system("clear");
			Bet settingBet(bet, credits);
			settingBet.selectBet(bet, credits);
		}
		if (p[0] == 'i' && p.size() == 1) {
			if (system("CLS")) system("clear");
			paytableForGame.PaytableWisePharaohs5Info();
		}
		if (p[0] == 'c' && p.size() == 1) {
			if (credits > 0.0) {
				std::cout << "Cashout..." << std::endl;
				std::cout << "Handpay! Call Attendant! " << credits << " Euro!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
				credits = 0;
			}
			else {
				std::cout << "Nothing to cashout!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
			}
			//exit(0);
		}
		if (p[0] == 'g' && p.size() == 1) {

			Gamble gambleInfoScreen;
			gambleInfoScreen.GambleInfoScreen();
		}
		if (p[0] == 'a' && p.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (p[0] == 'q' && p.size() == 1) {
			SelectGame selectgame;
			selectgame.selectGame_Welcome();
			selectgame.selectGame_Games();

			//choosing a game
			selectgame.selectGame_Option(credits);
		}

		if (credits < 1) {
			std::cout << "No More Credits To Play on Min Bet! :(" << std::endl;
			CreditField addCreditBeforeExit;
			addCreditBeforeExit.AddCredit(credits);
			if (credits < 1) {
				std::cout << "You need to add atleast 1 Euro!" << std::endl;
				std::cout << "Cashout: " << credits << " Euro." << std::endl;
				credits = 0;
				Sleep(2000);
				SelectGame selectgame;
				selectgame.selectGame_Welcome();
				selectgame.selectGame_Games();

				//choosing a game
				selectgame.selectGame_Option(credits);
			}
		}

		myVectorInStart.clear();
	}
	
}

//Tiger's Battle 10
void Start::StartGameNowTigersBattle10(double& credits, unsigned int& bet) {

	std::vector<std::vector<int>>myVectorInStart;
	myVectorInStart = getVectorMatrix();
	std::string p;

	unsigned int minBet = 2;
	PaytableTigersBattle paytableForGame(myVectorInStart, credits, bet);
	while (credits >= minBet) {
		if (credits < bet && credits >= minBet) {
			bet = minBet;
			std::cout << "Changing Bet to min: " << bet << " Euro!" << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		std::cout << "Press 'p' to Start a Game!" << std::endl;
		std::cout << "Press 'e' to Change the Bet!" << std::endl;
		std::cout << "Press 'i' to see the Paytable!" << std::endl;
		std::cout << "Press 'c' to Cashout!" << std::endl;
		std::cout << "Press 'g' to see the Gamble Info Screen!" << std::endl;
		std::cout << "Press 'a' to add credit!" << std::endl;
		std::cout << "Press 'q' for More Games!" << std::endl;
		std::cout << "Press 'l' To Change Lines!" << std::endl;
		std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
		std::cout << "********************************************************************************************************************" << std::endl;

		std::cin >> p;
		//new code here for safety
		/*while(p.size() > 1) {
			std::cin >> p;
		}*/
		if (p[0] == 'p' && p.size() == 1) {
			//clears screen
			if (system("CLS")) system("clear");

			takeCreditsWithBet(credits, bet);
			RandomNumbersInMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			outPutMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl;
			checkForCreditsAndBetSuperFire10(credits, bet);
			outputCreditsAndBetCurrent(credits, bet);
			paytableForGame.PaytableTigersBattleWin10(myVectorInStart, credits, bet);
		}
		if (p[0] == 'e' && p.size() == 1) {
			if (system("CLS")) system("clear");
			Bet settingBet(bet, credits);
			settingBet.selectBetTigersBattle10(bet, credits);
		}
		if (p[0] == 'i' && p.size() == 1) {
			if (system("CLS")) system("clear");
			paytableForGame.PaytableTigersBattleWinInfo10();
		}
		if (p[0] == 'c' && p.size() == 1) {
			if (credits > 0.0) {
				std::cout << "Cashout..." << std::endl;
				std::cout << "Handpay! Call Attendant! " << credits << " Euro!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
				credits = 0;
			}
			else {
				std::cout << "Nothing to cashout!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
			}
			//exit(0);
		}
		if (p[0] == 'g' && p.size() == 1) {

			Gamble gambleInfoScreen;
			gambleInfoScreen.GambleInfoScreen();
		}
		if (p[0] == 'a' && p.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (p[0] == 'q' && p.size() == 1) {
			SelectGame selectgame;
			selectgame.selectGame_Welcome();
			selectgame.selectGame_Games();

			//choosing a game
			selectgame.selectGame_Option(credits);
		}
		if (p[0] == 'l' && p.size() == 1) {
			//clear console
			if (system("CLS")) system("clear");
			//welcome game
			PrintGameName printWelcome;
			printWelcome.PrintGameNameWelcomeTigersBattle5(); // changed
			//credit
			if (credits < 1) {
				std::cout << "Please Insert Credits in order to play. Minimum is 1 Euro for Min Bet!" << std::endl;
				std::cout << "----------------------------------------------------------------------" << std::endl;
				CreditField myCredit;
				myCredit.AddCredit(credits);
			}
			unsigned int bet = 0;
			Bet currentBet(bet, credits);
			currentBet.selectBetTigersBattle5(bet, credits); //Changing to 5 Lines bet 1 to 5 

			//matrix 2D
			std::vector<std::vector<int>> myMatrixVector;
			Matrix myMatrix(myMatrixVector);

			//starting a game
			Start startGame(credits, bet);
			startGame.StartGameNowTigersBattle5(credits, bet);
		}

		if (credits < 1) {
			std::cout << "No More Credits To Play on Min Bet! :(" << std::endl;
			CreditField addCreditBeforeExit;
			addCreditBeforeExit.AddCredit(credits);
			if (credits < 1) {
				std::cout << "You need to add atleast 2 Euro!" << std::endl;
				std::cout << "Cashout: " << credits << " Euro." << std::endl;
				credits = 0;
				Sleep(2000);
				SelectGame selectgame;
				selectgame.selectGame_Welcome();
				selectgame.selectGame_Games();

				//choosing a game
				selectgame.selectGame_Option(credits);
			}
		}

		myVectorInStart.clear();
	}
}

void Start::StartGameNowTigersBattle5(double& credits, unsigned int& bet) {

	std::vector<std::vector<int>>myVectorInStart;
	myVectorInStart = getVectorMatrix();
	std::string p;

	unsigned int minBet = 1;
	PaytableTigersBattle paytableForGame(myVectorInStart, credits, bet);
	while (credits >= 1) {
		if (credits < bet && credits >= 1) {
			bet = minBet;
			std::cout << "Changing Bet to min: " << bet << " Euro!" << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		std::cout << "Press 'p' to Start a Game!" << std::endl;
		std::cout << "Press 'e' to Change the Bet!" << std::endl;
		std::cout << "Press 'i' to see the Paytable!" << std::endl;
		std::cout << "Press 'c' to Cashout!" << std::endl;
		std::cout << "Press 'g' to see the Gamble Info Screen!" << std::endl;
		std::cout << "Press 'a' to add credit!" << std::endl;
		std::cout << "Press 'q' for More Games!" << std::endl;
		std::cout << "Press 'l' for Changing lines!" << std::endl;
		std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
		std::cout << "********************************************************************************************************************" << std::endl;

		std::cin >> p;
		//new code here for safety
		/*while(p.size() > 1) {
			std::cin >> p;
		}*/
		if (p[0] == 'p' && p.size() == 1) {
			//clears screen
			if (system("CLS")) system("clear");

			takeCreditsWithBet(credits, bet);
			RandomNumbersInMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			outPutMatrix(myVectorInStart);
			std::cout << "---------------------------------------------" << std::endl;
			checkForCreditsAndBet(credits, bet);
			outputCreditsAndBetCurrent(credits, bet);
			paytableForGame.PaytableTigersBattleWin5(myVectorInStart, credits, bet);
		}
		if (p[0] == 'e' && p.size() == 1) {
			if (system("CLS")) system("clear");
			Bet settingBet(bet, credits);
			settingBet.selectBetTigersBattle5(bet, credits);
		}
		if (p[0] == 'i' && p.size() == 1) {
			if (system("CLS")) system("clear");
			paytableForGame.PaytableTigersBattleWinInfo5();
		}
		if (p[0] == 'c' && p.size() == 1) {
			if (credits > 0.0) {
				std::cout << "Cashout..." << std::endl;
				std::cout << "Handpay! Call Attendant! " << credits << " Euro!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
				credits = 0;
			}
			else {
				std::cout << "Nothing to cashout!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
			}
			//exit(0);
		}
		if (p[0] == 'g' && p.size() == 1) {

			Gamble gambleInfoScreen;
			gambleInfoScreen.GambleInfoScreen();
		}
		if (p[0] == 'a' && p.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (p[0] == 'q' && p.size() == 1) {
			SelectGame selectgame;
			selectgame.selectGame_Welcome();
			selectgame.selectGame_Games();

			//choosing a game
			selectgame.selectGame_Option(credits);
		}
		if (p[0] == 'l' && p.size() == 1) {
			//clear console
			if (system("CLS")) system("clear");
			//welcome game
			PrintGameName printWelcome;
			printWelcome.PrintGameNameWelcomeTigersBattle10(); // changed
			//credit
			if (credits < 2) {
				std::cout << "Please Insert Credits in order to play. Minimum is 2 Euro for Min Bet!" << std::endl;
				std::cout << "----------------------------------------------------------------------" << std::endl;
				CreditField myCredit;
				myCredit.AddCredit(credits);
			}
			unsigned int bet = 0;
			Bet currentBet(bet, credits);
			currentBet.selectBetTigersBattle10(bet, credits); //Changing to 5 Lines bet 1 to 5 

			//matrix 2D
			std::vector<std::vector<int>> myMatrixVector;
			Matrix myMatrix(myMatrixVector);

			//starting a game
			Start startGame(credits, bet);
			startGame.StartGameNowTigersBattle10(credits, bet);
		}
		if (credits < 1) {
			std::cout << "No More Credits To Play on Min Bet! :(" << std::endl;
			CreditField addCreditBeforeExit;
			addCreditBeforeExit.AddCredit(credits);
			if (credits < 1) {
				std::cout << "You need to add atleast 1 Euro!" << std::endl;
				std::cout << "Cashout: " << credits << " Euro." << std::endl;
				credits = 0;
				Sleep(2000);
				SelectGame selectgame;
				selectgame.selectGame_Welcome();
				selectgame.selectGame_Games();

				//choosing a game
				selectgame.selectGame_Option(credits);
			}
		}

		myVectorInStart.clear();
	}
}

//need to change alot of things here
//Keno
void Start::StartGameNowKeno(double& credits, unsigned int& bet) {

	std::vector<std::vector<int>>myVectorInStart;
	//myVectorInStart = getVectorMatrix();
	std::string p;
	Keno playgame(myVectorInStart,credits,bet);
	unsigned int minBet = 1;
	Keno_HotAndCold hotAndCold;
	//PaytableSuperFire paytableForGame(myVectorInStart, credits, bet);
	while (credits >= 1) {
		if (credits < bet && credits >= 1) {
			bet = minBet;
			std::cout << "Changing Bet to min: " << bet << " Euro!" << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		std::cout << "Press 'p' to Start a Game!" << std::endl;
		std::cout << "Press 'e' to Change the Bet!" << std::endl;
		std::cout << "Press 'i' to see the Paytable!" << std::endl;
		std::cout << "Press 'c' to Cashout!" << std::endl;
		std::cout << "Press 'g' to see the Gamble Info Screen!" << std::endl;
		std::cout << "Press 'a' to add credit!" << std::endl;
		std::cout << "Press 'q' for More Games!" << std::endl;
		//std::cout << "Press 'h' for Hot and Cold Numbers!" << std::endl;
		std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
		std::cout << "********************************************************************************************************************" << std::endl;

		std::cin >> p;
		//new code here for safety
		/*while(p.size() > 1) {
			std::cin >> p;
		}*/
		if (p[0] == 'p' && p.size() == 1) {
			//clears screen
			if (system("CLS")) system("clear");
			
			takeCreditsWithBet(credits, bet);
			playgame.checkForHits(credits,bet);
			//RandomNumbersInMatrix(myVectorInStart);
			//std::cout << "---------------------------------------------" << std::endl; std::cout << " " << std::endl;
			//outPutMatrix(myVectorInStart);
			//std::cout << "---------------------------------------------" << std::endl;
			checkForCreditsAndBet(credits, bet);
			outputCreditsAndBetCurrent(credits, bet);
			//paytableForGame.PaytableSuperFireWin(myVectorInStart, credits, bet);
		}
		if (p[0] == 'e' && p.size() == 1) {
			if (system("CLS")) system("clear");
			Bet settingBet(bet, credits);
			settingBet.selectBetKeno(bet, credits);
		}
		if (p[0] == 'i' && p.size() == 1) {
			if (system("CLS")) system("clear");
			playgame.infoPageKeno();
		}
		if (p[0] == 'c' && p.size() == 1) {
			if (credits > 0.0) {
				std::cout << "Cashout..." << std::endl;
				std::cout << "Handpay! Call Attendant! " << credits << " Euro!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
				credits = 0;
			}
			else {
				std::cout << "Nothing to cashout!" << std::endl;
				std::chrono::seconds duration(3);
				std::this_thread::sleep_for(duration);
			}
			//exit(0);
		}
		if (p[0] == 'g' && p.size() == 1) {

			Gamble gambleInfoScreen;
			gambleInfoScreen.GambleInfoScreen();
		}
		if (p[0] == 'a' && p.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (p[0] == 'q' && p.size() == 1) {
			SelectGame selectgame;
			selectgame.selectGame_Welcome();
			selectgame.selectGame_Games();

			//choosing a game
			selectgame.selectGame_Option(credits);
		}
		/*if (p[0] == 'h' && p.size() == 1) {
			if (system("CLS")) system("clear");
			hotAndCold.infoHotAndCold();
		}*/
		if (credits < 1) {
			std::cout << "No More Credits To Play on Min Bet! :(" << std::endl;
			CreditField addCreditBeforeExit;
			addCreditBeforeExit.AddCredit(credits);
			if (credits < 1) {
				std::cout << "You need to add atleast 1 Euro!" << std::endl;
				std::cout << "Cashout: " << credits << " Euro." << std::endl;
				credits = 0;
				Sleep(2000);
				SelectGame selectgame;
				selectgame.selectGame_Welcome();
				selectgame.selectGame_Games();

				//choosing a game
				selectgame.selectGame_Option(credits);
			}
		}

		myVectorInStart.clear();
	}
}

Start::~Start() {
	//destroying
}