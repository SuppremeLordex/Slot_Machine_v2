#include "Select_Game.h"

const int row = 3;
const int column = 5;
SelectGame::SelectGame() {
	//default construct =0;
}
SelectGame::SelectGame(std::vector<std::vector<std::string>> selectGameMatrix, double credits) {
	_selectGameMatrix = selectGameMatrix;
	_credits = credits;
}
void SelectGame::selectGame_Welcome() {
	if (system("CLS")) system("clear");
	/*std::cout << "********************************************************************************************************************" << std::endl;
	std::cout << "                                                  * Welcome! *                                                      " << std::endl;*/
	std::cout << "********************************************************************************************************************" << std::endl;
	std::cout << "                                                * Select Game *                                                     " << std::endl;
	std::cout << "********************************************************************************************************************" << std::endl;
	selectGame_Games();
}
double SelectGame::selectGame_Option(double & credits) {
	std::string option;
	bool neverExit =false;
	while (neverExit==false) {
		selectGame_Welcome();
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Choose a game which you want to Play!" << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Option: 1 for SuperFire 5" << std::endl;
		std::cout << "Option: 2 for SuperFire 10" << std::endl;
		std::cout << "Option: 3 for Wise Pharaohs 5" << std::endl;
		std::cout << "Option: 4 for Tiger's Battle 10" << std::endl;
		std::cout << "Option: 5 for Keno" << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Press a to add credit!" << std::endl;
		std::cout << "Press c to exit!" << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Current Credit: " << credits << " Euro!" << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cin >> option;

		if (option[0] == 'a' && option.size() == 1) {
			CreditField addCredit;
			addCredit.AddCredit(credits);
		}
		if (option[0] == 'c' && option.size() == 1) {
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
		if (option[0] == '1' && option.size() == 1) {
			//clear console
			if (system("CLS")) system("clear");
			//welcome game
			PrintGameName printWelcome;
			printWelcome.PrintGameNameWelcome();
			//credit
			if (credits < 1) {
				std::cout << "Please Insert Credits in order to play. Minimum is 1 Euro for Min Bet!" << std::endl;
				std::cout << "----------------------------------------------------------------------" << std::endl;
				CreditField myCredit;
				myCredit.AddCredit(credits);
			}
			unsigned int bet = 0;
			Bet currentBet(bet, credits);
			currentBet.selectBet(bet, credits);

			//matrix 2D
			std::vector<std::vector<int>> myMatrixVector;
			Matrix myMatrix(myMatrixVector);

			//starting a game
			Start startGame(credits, bet);
			startGame.StartGameNow(credits, bet);
		}
		if (option[0] == '2' && option.size() == 1) {
				//clear console
			if (system("CLS")) system("clear");
				//welcome game
				PrintGameName printWelcome;
				printWelcome.PrintGameNameWelcomeSuperFire10();
				//credit
			if (credits < 2) {
					std::cout << "Please Insert Credits in order to play. Minimum is 2 Euro for Min Bet!" << std::endl;
					std::cout << "----------------------------------------------------------------------" << std::endl;
					CreditField myCredit;
					myCredit.AddCredit(credits);
			}
			
			//bet
			unsigned int bet = 0;
			Bet currentBet(bet, credits);
			currentBet.selectBetSuperFire10(bet, credits);

			//matrix 2D
			std::vector<std::vector<int>> myMatrixVector;
			Matrix myMatrix(myMatrixVector);

			//starting a game
			Start startGame(credits, bet);
			startGame.StartGameNowSuperFire10(credits, bet);
		}
		// Wise Pharaohs 5 
		if (option[0] == '3' && option.size() == 1) {
			//clear console
			if (system("CLS")) system("clear");
			//welcome game
			PrintGameName printWelcome;
			printWelcome.PrintGameNameWelcomeWisePharaohs5();
			//credit
			if (credits < 1) {
				std::cout << "Please Insert Credits in order to play. Minimum is 1 Euro for Min Bet!" << std::endl;
				std::cout << "----------------------------------------------------------------------" << std::endl;
				CreditField myCredit;
				myCredit.AddCredit(credits);
			}
			unsigned int bet = 0;
			Bet currentBet(bet, credits);
			currentBet.selectBetWisePharaohs(bet, credits);

			//matrix 2D
			//need to change
			std::vector<std::vector<int>> myMatrixVector;
			MatrixPharaohs myMatrix(myMatrixVector);

			//starting a game
			Start startGame(credits, bet);
			startGame.StartGameNowWisePharaohs5(credits, bet); 
		}

		if (option[0] == '4' && option.size() == 1) {
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
			currentBet.selectBetTigersBattle10(bet, credits); //changed  bet 2 euro

			//matrix 2D
			std::vector<std::vector<int>> myMatrixVector;
			Matrix myMatrix(myMatrixVector);

			//starting a game
			Start startGame(credits, bet);
			startGame.StartGameNowTigersBattle10(credits, bet); //changed
		}
		if (option[0] == '5' && option.size() == 1) {
			//clear console
			if (system("CLS")) system("clear");
			//welcome game
			PrintGameName printWelcome;
			printWelcome.PrintGameNameWelcomeKeno();
			//credit
			if (credits < 1) {
				std::cout << "Please Insert Credits in order to play. Minimum is 1 Euro for Min Bet!" << std::endl;
				std::cout << "----------------------------------------------------------------------" << std::endl;
				CreditField myCredit;
				myCredit.AddCredit(credits);
			}
			unsigned int bet = 0;
			Bet currentBet(bet, credits);
			currentBet.selectBetKeno(bet, credits);

			//matrix 2D
			/*std::vector<std::vector<int>> myMatrixVector;
			Matrix myMatrix(myMatrixVector);*/

			//starting a game

			Start startGame(credits, bet);
			startGame.StartGameNowKeno(credits, bet);
		}
	}
	return credits;
}
void SelectGame::selectGame_Games() {
	//Super Fire 5
	std::vector<std::vector<std::string>> superFire5;
	std::string namesuperFire5 = "SuperFire 5";
	for (int i = 0; i < row; ++i) {
		superFire5.push_back(std::vector<std::string>());
		for (int j = 0; j < column; ++j) {
			if (i == 0) {
				for (int k = 0; k < namesuperFire5.size() +2 ; ++k) {
					superFire5[i].push_back("-");
				}
				break;
				
			}
			if (i == 1 && j == 2) {
				superFire5[i].push_back("|SuperFire 5|");
			}
			if (i == 2) {
				for (int k = 0; k < namesuperFire5.size() + 2; ++k) {
					superFire5[i].push_back("-");
				}
				break;
			}
			
			
		}
	}

	//for (int i = 0; i < superFire5.size(); ++i) {
	//	for (int j = 0; j < superFire5[i].size(); ++j) {
	//		std::cout << superFire5[i][j];
	//	}
	//	std::cout << std::endl;
	//}

	//Super Fire 10
	std::vector<std::vector<std::string>> superFire10;
	std::string namesuperFire10 = "SuperFire 10";
	for (int i = 0; i < row; ++i) {
		superFire10.push_back(std::vector<std::string>());
		for (int j = 0; j < column; ++j) {
			if (i == 0) {
				for (int k = 0; k < namesuperFire10.size() + 2; ++k) {
					superFire10[i].push_back("-");
				}
				break;

			}
			if (i == 1 && j == 2) {
				superFire10[i].push_back("|SuperFire 10|");
			}
			if (i == 2) {
				for (int k = 0; k < namesuperFire10.size() + 2; ++k) {
					superFire10[i].push_back("-");
				}
				break;
			}


		}
	}

	/*for (int i = 0; i < superFire10.size(); ++i) {
		for (int j = 0; j < superFire10[i].size(); ++j) {
			std::cout << superFire10[i][j];
		}
		std::cout << std::endl;
	}*/

	//5 Wise Pharaohs
	std::vector<std::vector<std::string>> wisePharaohs5;
	std::string nameWisePharaohs5 = "Wise Pharaohs 5";
	for (int i = 0; i < row; ++i) {
		wisePharaohs5.push_back(std::vector<std::string>());
		for (int j = 0; j < column; ++j) {
			if (i == 0) {
				for (int k = 0; k < nameWisePharaohs5.size() + 2; ++k) {
					wisePharaohs5[i].push_back("-");
				}
				break;

			}
			if (i == 1 && j == 2) {
				wisePharaohs5[i].push_back("|Wise Pharaohs 5|");
			}
			if (i == 2) {
				for (int k = 0; k < nameWisePharaohs5.size() + 2; ++k) {
					wisePharaohs5[i].push_back("-");
				}
				break;
			}


		}
	}


	//for (int i = 0; i < wisePharaohs5.size(); ++i) {
	//	for (int j = 0; j < wisePharaohs5[i].size(); ++j) {
	//		std::cout << wisePharaohs5[i][j];
	//	}
	//	std::cout << std::endl;
	//}


	//Tiger's Battle 10
	std::vector<std::vector<std::string>> tigersBattle10;
	std::string nameTigersBattle10 = "Tiger's Battle 10";
	for (int i = 0; i < row; ++i) {
		tigersBattle10.push_back(std::vector<std::string>());
		for (int j = 0; j < column; ++j) {
			if (i == 0) {
				for (int k = 0; k < nameTigersBattle10.size() + 2; ++k) {
					tigersBattle10[i].push_back("-");
				}
				break;

			}
			if (i == 1 && j == 2) {
				tigersBattle10[i].push_back("|Tiger's Battle 10|");
			}
			if (i == 2) {
				for (int k = 0; k < nameTigersBattle10.size() + 2; ++k) {
					tigersBattle10[i].push_back("-");
				}
				break;
			}


		}
	}

	/*for (int i = 0; i < tigersBattle10.size(); ++i) {
		for (int j = 0; j < tigersBattle10[i].size(); ++j) {
			std::cout << tigersBattle10[i][j];
		}
		std::cout << std::endl;
	}*/

	//Keno

	std::vector<std::vector<std::string>> keno;
	std::string nameKeno = "Keno";
	for (int i = 0; i < row; ++i) {
		keno.push_back(std::vector<std::string>());
		for (int j = 0; j < column; ++j) {
			if (i == 0) {
				for (int k = 0; k < nameKeno.size() + 2; ++k) {
					keno[i].push_back("-");
				}
				break;
			}
			if (i == 1 && j == 2) {
				keno[i].push_back("|Keno|");
			}
			if (i == 2) {
				for (int k = 0; k < nameKeno.size() + 2; ++k) {
					keno[i].push_back("-");
				}
				break;
			}
		}
	}

	/*for (int i = 0; i < keno.size(); ++i) {
		for (int j = 0; j < keno[i].size(); ++j) {
			std::cout << keno[i][j];
		}
		std::cout << std::endl;
	}*/
	std::vector<std::string>gamesNames;
	
	const std::string firstLines = "               ------------- -------------- ----------------- ------------------- ------";
	const std::string gamename = "               |SuperFire 5| |SuperFire 10| |Wise Pharaohs 5| |Tiger's Battle 10| |Keno|";
	
	std::cout << firstLines << std::endl;
	std::cout << gamename << std::endl;
	std::cout << firstLines << std::endl;
}

SelectGame::~SelectGame() {
	//deconstructing;
}