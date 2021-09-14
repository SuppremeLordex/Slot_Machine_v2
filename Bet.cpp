#include "Bet.h"
#include "CreditField.h"

//needs fix 
Bet::Bet() {
	_bet_bet = 0;
	_credit_bet = 0;
}
Bet::Bet(unsigned int bet, double credit) {
	_bet_bet = bet;
	_credit_bet = credit;
}

//Keno
unsigned int Bet::selectBetKeno(unsigned int& bet, double& credit) {

	std::vector<unsigned int> betVector;
	unsigned const int oneEuro = 1;
	betVector.push_back(oneEuro);
	unsigned const int twoEuro = 2;
	betVector.push_back(twoEuro);
	unsigned const int threeEuro = 3;
	betVector.push_back(threeEuro);
	unsigned const int FourEuro = 4;
	betVector.push_back(FourEuro);
	unsigned const int FiveEuro = 5;
	betVector.push_back(FiveEuro);

	std::string okay = "ok";
	std::string confirm;
	std::string y;
	int countAbove = 0;
	int countBelow = 0;

	//if credit < 1
	//if credit < 5
	//if credit< cannot increase!
	CreditField repeatInput;

	while (_credit_bet < oneEuro) {

		std::cout << "Please insert Credit! The minimum is 1 Euro! " << std::endl;
		repeatInput.AddCredit(_credit_bet);

	}
	std::cout << ">>>The minimum bet is: " << oneEuro << " Euro and the max bet is: " << FiveEuro << " Euro! " << std::endl;
	std::cout << ">>>Current Bet: " << betVector[0] << " Euro" << std::endl;
	if (_credit_bet >= oneEuro) {
		std::cout << ">>>Please, Select Bet! " << std::endl;
		if (_credit_bet >= FiveEuro) {
			std::cout << ">>>Play On Max Bet!" << std::endl;
		}
		if (_credit_bet < FiveEuro) {
			std::cout << ">>>Insert credit to play on max bet! " << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		while (confirm != okay) {
			std::cout << "---Press y to increase the bet! " << std::endl;
			std::cout << "---Press n to decrease the bet!" << std::endl;
			std::cout << "---Press q to quit!" << std::endl;
			std::cout << "---Press o to play with current bet!" << std::endl;
			std::cout << "---Press m for more games!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cin >> y;
			//new code here for safety
			/*while (y.size() > 1) {

				std::cin >> y;
			}*/
			for (int i = 0; i < betVector.size(); i++) {
				if (y[0] == 'y' && y.size() == 1) {
					if (_credit_bet <= bet) {
						if (credit == FiveEuro && bet == FiveEuro) {
							std::cout << "You are already playing on max bet!" << std::endl;
							std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
							break;
						}
						else {
							std::cout << "Not enough credits to increase the bet!" << std::endl;
							std::cout << "Credits: " << _credit_bet << std::endl;
							std::cout << "Bet: " << bet << std::endl;

							break;
						}

					}
					else {

						if (betVector[i] >= FiveEuro) {
							betVector[i] = FiveEuro;
							bet = betVector[i];
							countAbove++;
						}
						else {
							if (credit == oneEuro) {
								bet = oneEuro;
							}
							if (_credit_bet == oneEuro) {
								bet = oneEuro;
							}
							else {

								betVector[i] += oneEuro;
								bet = betVector[i];
							}

							countBelow = 0;
						}
						if (countAbove > 0) {
							std::cout << "You are already playing on max bet!" << std::endl;
						}
						std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
						break;
					}

				}
				if (y[0] == 'n' && y.size() == 1) {

					if (betVector[i] <= oneEuro) {
						betVector[i] = oneEuro;
						bet = betVector[i];
						countBelow++;
					}
					else {
						betVector[i] -= 1;
						bet = betVector[i];
						countBelow = 0;
					}
					if (countBelow > 0) {
						std::cout << "You are already playing on minimum bet!" << std::endl;
					}
					std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
					break;
				}
				if (y[0] == 'q' && y.size() == 1) {
					std::cout << "Cashout..." << std::endl;
					std::cout << "Handpay! Call Attendant! " << _credit_bet << " Euro!" << std::endl;
					//std::chrono::seconds duration(3);
					//std::this_thread::sleep_for(duration);
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();
					credit = 0;
					//choosing a game
					selectgame.selectGame_Option(credit);

					//exit(0);
					break;
				}
				if (y[0] == 'm' && y.size() == 1) {
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
				}

				if (y[0] == 'o' && y.size() == 1) {
					if (system("CLS")) system("clear");
					bet = betVector[i];
					Start startgame;
					startgame.StartGameNowKeno(_credit_bet, bet);
					confirm = "ok";
					break;
				}
				else {
					std::cout << "Invalid Input" << std::endl;
					bet = oneEuro;
					std::cin >> y;
				}
			}
		}
	}
	return bet;
}
unsigned int Bet::selectBetTigersBattle5(unsigned int& bet, double& credit) {

	std::vector<unsigned int> betVector;
	unsigned const int oneEuro = 1;
	betVector.push_back(oneEuro);
	unsigned const int twoEuro = 2;
	betVector.push_back(twoEuro);
	unsigned const int threeEuro = 3;
	betVector.push_back(threeEuro);
	unsigned const int FourEuro = 4;
	betVector.push_back(FourEuro);
	unsigned const int FiveEuro = 5;
	betVector.push_back(FiveEuro);

	std::string okay = "ok";
	std::string confirm;
	std::string y;
	int countAbove = 0;
	int countBelow = 0;

	//if credit < 1
	//if credit < 5
	//if credit< cannot increase!
	CreditField repeatInput;

	while (_credit_bet < oneEuro) {

		std::cout << "Please insert Credit! The minimum is 1 Euro! " << std::endl;
		repeatInput.AddCredit(_credit_bet);

	}
	std::cout << ">>>The minimum bet is: " << oneEuro << " Euro and the max bet is: " << FiveEuro << " Euro! " << std::endl;
	std::cout << ">>>Current Bet: " << betVector[0] << " Euro" << std::endl;
	if (_credit_bet >= oneEuro) {
		std::cout << ">>>Please, Select Bet! " << std::endl;
		if (_credit_bet >= FiveEuro) {
			std::cout << ">>>Play On Max Bet!" << std::endl;
		}
		if (_credit_bet < FiveEuro) {
			std::cout << ">>>Insert credit to play on max bet! " << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		while (confirm != okay) {
			std::cout << "---Press y to increase the bet! " << std::endl;
			std::cout << "---Press n to decrease the bet!" << std::endl;
			std::cout << "---Press q to quit!" << std::endl;
			std::cout << "---Press o to play with current bet!" << std::endl;
			std::cout << "---Press m for more games!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cin >> y;
			//new code here for safety
			/*while (y.size() > 1) {

				std::cin >> y;
			}*/
			for (int i = 0; i < betVector.size(); i++) {
				if (y[0] == 'y' && y.size() == 1) {
					if (_credit_bet <= bet) {
						if (credit == FiveEuro && bet == FiveEuro) {
							std::cout << "You are already playing on max bet!" << std::endl;
							std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
							break;
						}
						else {
							std::cout << "Not enough credits to increase the bet!" << std::endl;
							std::cout << "Credits: " << _credit_bet << std::endl;
							std::cout << "Bet: " << bet << std::endl;

							break;
						}

					}
					else {

						if (betVector[i] >= FiveEuro) {
							betVector[i] = FiveEuro;
							bet = betVector[i];
							countAbove++;
						}
						else {
							if (credit == oneEuro) {
								bet = oneEuro;
							}
							if (_credit_bet == oneEuro) {
								bet = oneEuro;
							}
							else {

								betVector[i] += oneEuro;
								bet = betVector[i];
							}

							countBelow = 0;
						}
						if (countAbove > 0) {
							std::cout << "You are already playing on max bet!" << std::endl;
						}
						std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
						break;
					}

				}
				if (y[0] == 'n' && y.size() == 1) {

					if (betVector[i] <= oneEuro) {
						betVector[i] = oneEuro;
						bet = betVector[i];
						countBelow++;
					}
					else {
						betVector[i] -= 1;
						bet = betVector[i];
						countBelow = 0;
					}
					if (countBelow > 0) {
						std::cout << "You are already playing on minimum bet!" << std::endl;
					}
					std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
					break;
				}
				if (y[0] == 'q' && y.size() == 1) {
					std::cout << "Cashout..." << std::endl;
					std::cout << "Handpay! Call Attendant! " << _credit_bet << " Euro!" << std::endl;
					//std::chrono::seconds duration(3);
					//std::this_thread::sleep_for(duration);
					credit = 0;
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
					//exit(0);
					break;
				}
				if (y[0] == 'm' && y.size() == 1) {
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
				}

				if (y[0] == 'o' && y.size() == 1) {
					bet = betVector[i];
					Start startgame;
					startgame.StartGameNowTigersBattle5(_credit_bet, bet);
					confirm = "ok";
					break;
				}
				else {
					std::cout << "Invalid Input" << std::endl;
					bet = oneEuro;
					std::cin >> y;
				}
			}
		}
	}
	return bet;
}

unsigned int Bet::selectBetTigersBattle10(unsigned int& bet, double& credit) {

	std::vector<unsigned int> betVector;

	unsigned const int twoEuro = 2;
	betVector.push_back(twoEuro);

	unsigned const int FourEuro = 4;
	betVector.push_back(FourEuro);

	unsigned const int sixEuro = 6;
	betVector.push_back(sixEuro);

	unsigned const int eightEuro = 8;
	betVector.push_back(eightEuro);

	unsigned const int tenEuro = 10;
	betVector.push_back(tenEuro);



	std::string okay = "ok";
	std::string confirm;
	std::string y;
	int countAbove = 0;
	int countBelow = 0;

	//if credit < 1
	//if credit < 5
	//if credit< cannot increase!
	CreditField repeatInput;

	while (_credit_bet < twoEuro) {

		std::cout << "Please insert Credit! The minimum is 2 Euro! " << std::endl;
		repeatInput.AddCredit(_credit_bet);

	}
	std::cout << ">>>The minimum bet is: " << twoEuro << " Euro and the max bet is: " << tenEuro << " Euro! " << std::endl;
	std::cout << ">>>Current Bet: " << betVector[0] << " Euro" << std::endl;
	if (_credit_bet >= twoEuro) {
		std::cout << ">>>Please, Select Bet! " << std::endl;
		if (_credit_bet >= tenEuro) {
			std::cout << ">>>Play On Max Bet!" << std::endl;
		}
		if (_credit_bet < tenEuro) {
			std::cout << ">>>Insert credit to play on max bet! " << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		while (confirm != okay) {
			std::cout << "---Press y to increase the bet! " << std::endl;
			std::cout << "---Press n to decrease the bet!" << std::endl;
			std::cout << "---Press q to quit!" << std::endl;
			std::cout << "---Press o to play with current bet!" << std::endl;
			std::cout << "---Press m for more games!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cin >> y;
			//new code here for safety
			/*while (y.size() > 1) {

				std::cin >> y;
			}*/
			for (int i = 0; i < betVector.size(); i += 2) {
				if (y[0] == 'y' && y.size() == 1) {
					if (_credit_bet <= bet) {
						if (credit == tenEuro && bet == tenEuro) {
							std::cout << "You are already playing on max bet!" << std::endl;
							std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
							break;
						}
						else {
							std::cout << "Not enough credits to increase the bet!" << std::endl;
							std::cout << "Credits: " << _credit_bet << std::endl;
							std::cout << "Bet: " << bet << std::endl;

							break;
						}

					}
					else {

						if (betVector[i] >= tenEuro) {
							betVector[i] = tenEuro;
							bet = betVector[i];
							countAbove++;
						}
						else {
							if (credit == twoEuro) {
								bet = twoEuro;
							}
							if (_credit_bet == twoEuro) {
								bet = twoEuro;
							}
							else {

								betVector[i] += twoEuro;
								bet = betVector[i];
							}

							countBelow = 0;
						}
						if (countAbove > 0) {
							std::cout << "You are already playing on max bet!" << std::endl;
						}
						std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
						break;
					}

				}
				if (y[0] == 'n' && y.size() == 1) {

					if (betVector[i] <= twoEuro) {
						betVector[i] = twoEuro;
						bet = betVector[i];
						countBelow++;
					}
					else {
						betVector[i] -= 2;
						bet = betVector[i];
						countBelow = 0;
					}
					if (countBelow > 0) {
						std::cout << "You are already playing on minimum bet!" << std::endl;
					}
					std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
					break;
				}
				if (y[0] == 'q' && y.size() == 1) {
					std::cout << "Cashout..." << std::endl;
					std::cout << "Handpay! Call Attendant! " << _credit_bet << " Euro!" << std::endl;
					
					//std::chrono::seconds duration(3);
					//std::this_thread::sleep_for(duration);
					credit = 0;
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
					//exit(0);
					break;
				}
				if (y[0] == 'm' && y.size() == 1) {
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
				}

				if (y[0] == 'o' && y.size() == 1) {
					bet = betVector[i];
					confirm = "ok";
					Start startgame;
					startgame.StartGameNowTigersBattle10(_credit_bet, bet);
					break;
				}
				else {
					std::cout << "Invalid Input" << std::endl;
					bet = twoEuro;
					std::cin >> y;
				}
			}
		}
	}
	return bet;
}
unsigned int Bet::selectBet(unsigned int& bet, double &credit) {

	std::vector<unsigned int> betVector;
	unsigned const int oneEuro = 1;
	betVector.push_back(oneEuro);
	unsigned const int twoEuro = 2;
	betVector.push_back(twoEuro);
	unsigned const int threeEuro = 3;
	betVector.push_back(threeEuro);
	unsigned const int FourEuro = 4;
	betVector.push_back(FourEuro);
	unsigned const int FiveEuro = 5;
	betVector.push_back(FiveEuro);
	
	std::string okay = "ok";
	std::string confirm;
	std::string y; 
	int countAbove = 0; 
	int countBelow = 0; 
	
	//if credit < 1
	//if credit < 5
	//if credit< cannot increase!
	CreditField repeatInput;

	while (_credit_bet < oneEuro) {
	
		std::cout << "Please insert Credit! The minimum is 1 Euro! " << std::endl;
		repeatInput.AddCredit(_credit_bet);
		
	}
	std::cout << ">>>The minimum bet is: " << oneEuro << " Euro and the max bet is: " << FiveEuro << " Euro! " << std::endl;
	std::cout << ">>>Current Bet: " << betVector[0] << " Euro" << std::endl;
	if (_credit_bet >= oneEuro) {
		std::cout << ">>>Please, Select Bet! " << std::endl;
		if (_credit_bet >= FiveEuro) {
			std::cout << ">>>Play On Max Bet!" << std::endl;
		}
		if (_credit_bet < FiveEuro) {
			std::cout << ">>>Insert credit to play on max bet! " << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		while (confirm != okay) {
			std::cout << "---Press y to increase the bet! " << std::endl;
			std::cout << "---Press n to decrease the bet!" << std::endl;
			std::cout << "---Press q to quit!" << std::endl;
			std::cout << "---Press o to play with current bet!" << std::endl;
			std::cout << "---Press m for more games!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cin >> y;
			//new code here for safety
			/*while (y.size() > 1) {
				
				std::cin >> y;
			}*/
			for (int i = 0; i < betVector.size(); i++) {
				if (y[0] == 'y' && y.size()==1 ) {
					if (_credit_bet <= bet) {
						if (credit == FiveEuro && bet == FiveEuro) {
							std::cout << "You are already playing on max bet!" << std::endl;
							std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
							break;
						}
						else {
							std::cout << "Not enough credits to increase the bet!" << std::endl;
							std::cout << "Credits: " << _credit_bet << std::endl;
							std::cout << "Bet: " << bet << std::endl;

							break;
						}
						
					}
					else {
						
						if (betVector[i] >= FiveEuro) {
							betVector[i] = FiveEuro;
							bet = betVector[i];
							countAbove++;
						}
						else {
							if (credit == oneEuro) {
								bet = oneEuro;
							}
							if (_credit_bet == oneEuro) {
								bet = oneEuro;
							}
							else {

								betVector[i] += oneEuro;
								bet = betVector[i];
							}
							
							countBelow = 0;
						}
						if (countAbove > 0) {
							std::cout << "You are already playing on max bet!" << std::endl;
						}
						std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
						break;
					}
					
				}
				if (y[0] == 'n' && y.size() == 1) {

					if (betVector[i] <= oneEuro) {
						betVector[i] = oneEuro;
						bet = betVector[i];
						countBelow++;
					}
					else {
						betVector[i] -= 1;
						bet = betVector[i];
						countBelow = 0;
					}
					if (countBelow > 0) {
						std::cout << "You are already playing on minimum bet!" << std::endl;
					}
					std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
					break;
				}
				if (y[0] == 'q' && y.size() == 1) {
					std::cout << "Cashout..." << std::endl;
					std::cout << "Handpay! Call Attendant! " << _credit_bet << " Euro!" << std::endl;
					//std::chrono::seconds duration(3);
					//std::this_thread::sleep_for(duration);
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();
					credit = 0;
					//choosing a game
					selectgame.selectGame_Option(credit);
					
					//exit(0);
					break;
				}
				if (y[0] == 'm' && y.size() == 1) {
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
				}
				
				if (y[0] == 'o'  && y.size() == 1) {
					bet = betVector[i];
					Start startgame;
					startgame.StartGameNow(_credit_bet, bet);
					confirm = "ok";
					break;
				}
				else {
					std::cout << "Invalid Input" << std::endl;
					bet = oneEuro;
					std::cin >> y;
				}
			}
		}
	}
	return bet;
}
//super fire 10 BET scheme
unsigned int Bet::selectBetSuperFire10(unsigned int& bet, double& credit) {

	std::vector<unsigned int> betVector;
	
	unsigned const int twoEuro = 2;
	betVector.push_back(twoEuro);
	
	unsigned const int FourEuro = 4;
	betVector.push_back(FourEuro);

	unsigned const int sixEuro = 6;
	betVector.push_back(sixEuro);

	unsigned const int eightEuro = 8;
	betVector.push_back(eightEuro);

	unsigned const int tenEuro = 10;
	betVector.push_back(tenEuro);

	

	std::string okay = "ok";
	std::string confirm;
	std::string y;
	int countAbove = 0;
	int countBelow = 0;

	//if credit < 1
	//if credit < 5
	//if credit< cannot increase!
	CreditField repeatInput;

	while (_credit_bet < twoEuro) {

		std::cout << "Please insert Credit! The minimum is 2 Euro! " << std::endl;
		repeatInput.AddCredit(_credit_bet);

	}
	std::cout << ">>>The minimum bet is: " << twoEuro << " Euro and the max bet is: " << tenEuro << " Euro! " << std::endl;
	std::cout << ">>>Current Bet: " << betVector[0] << " Euro" << std::endl;
	if (_credit_bet >= twoEuro) {
		std::cout << ">>>Please, Select Bet! " << std::endl;
		if (_credit_bet >= tenEuro) {
			std::cout << ">>>Play On Max Bet!" << std::endl;
		}
		if (_credit_bet < tenEuro) {
			std::cout << ">>>Insert credit to play on max bet! " << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		while (confirm != okay) {
			std::cout << "---Press y to increase the bet! " << std::endl;
			std::cout << "---Press n to decrease the bet!" << std::endl;
			std::cout << "---Press q to quit!" << std::endl;
			std::cout << "---Press o to play with current bet!" << std::endl;
			std::cout << "---Press m for more games!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cin >> y;
			//new code here for safety
			/*while (y.size() > 1) {

				std::cin >> y;
			}*/
			for (int i = 0; i < betVector.size(); i+=2) {
				if (y[0] == 'y' && y.size() == 1) {
					if (_credit_bet <= bet) {
						if (credit == tenEuro && bet == tenEuro) {
							std::cout << "You are already playing on max bet!" << std::endl;
							std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
							break;
						}
						else {
							std::cout << "Not enough credits to increase the bet!" << std::endl;
							std::cout << "Credits: " << _credit_bet << std::endl;
							std::cout << "Bet: " << bet << std::endl;

							break;
						}

					}
					else {

						if (betVector[i] >= tenEuro) {
							betVector[i] = tenEuro;
							bet = betVector[i];
							countAbove++;
						}
						else {
							if (credit == twoEuro) {
								bet = twoEuro;
							}
							if (_credit_bet == twoEuro) {
								bet = twoEuro;
							}
							else {

								betVector[i] += twoEuro;
								bet = betVector[i];
							}

							countBelow = 0;
						}
						if (countAbove > 0) {
							std::cout << "You are already playing on max bet!" << std::endl;
						}
						std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
						break;
					}

				}
				if (y[0] == 'n' && y.size() == 1) {

					if (betVector[i] <= twoEuro) {
						betVector[i] = twoEuro;
						bet = betVector[i];
						countBelow++;
					}
					else {
						betVector[i] -= 2;
						bet = betVector[i];
						countBelow = 0;
					}
					if (countBelow > 0) {
						std::cout << "You are already playing on minimum bet!" << std::endl;
					}
					std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
					break;
				}
				if (y[0] == 'q' && y.size() == 1) {
					std::cout << "Cashout..." << std::endl;
					std::cout << "Handpay! Call Attendant! " << _credit_bet << " Euro!" << std::endl;
					//std::chrono::seconds duration(3);
					//std::this_thread::sleep_for(duration);
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();
					credit = 0;
					//choosing a game
					selectgame.selectGame_Option(credit);
					
					//exit(0);
					break;
				}
				if (y[0] == 'm' && y.size() == 1) {
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
				}

				if (y[0] == 'o' && y.size() == 1) {
					bet = betVector[i];
					confirm = "ok";
					Start startgame;
					startgame.StartGameNowSuperFire10(_credit_bet,bet);
					break;
				}
				else {
					std::cout << "Invalid Input" << std::endl;
					bet = twoEuro;
					std::cin >> y;
				}
			}
		}
	}
	return bet;
}

unsigned int Bet::selectBetWisePharaohs(unsigned int& bet, double& credit) {

	std::vector<unsigned int> betVector;
	unsigned const int oneEuro = 1;
	betVector.push_back(oneEuro);
	unsigned const int twoEuro = 2;
	betVector.push_back(twoEuro);
	unsigned const int threeEuro = 3;
	betVector.push_back(threeEuro);
	unsigned const int FourEuro = 4;
	betVector.push_back(FourEuro);
	unsigned const int FiveEuro = 5;
	betVector.push_back(FiveEuro);

	std::string okay = "ok";
	std::string confirm;
	std::string y;
	int countAbove = 0;
	int countBelow = 0;

	//if credit < 1
	//if credit < 5
	//if credit< cannot increase!
	CreditField repeatInput;

	while (_credit_bet < oneEuro) {

		std::cout << "Please insert Credit! The minimum is 1 Euro! " << std::endl;
		repeatInput.AddCredit(_credit_bet);

	}
	std::cout << ">>>The minimum bet is: " << oneEuro << " Euro and the max bet is: " << FiveEuro << " Euro! " << std::endl;
	std::cout << ">>>Current Bet: " << betVector[0] << " Euro" << std::endl;
	if (_credit_bet >= oneEuro) {
		std::cout << ">>>Please, Select Bet! " << std::endl;
		if (_credit_bet >= FiveEuro) {
			std::cout << ">>>Play On Max Bet!" << std::endl;
		}
		if (_credit_bet < FiveEuro) {
			std::cout << ">>>Insert credit to play on max bet! " << std::endl;
		}
		std::cout << "********************************************************************************************************************" << std::endl;
		while (confirm != okay) {
			std::cout << "---Press y to increase the bet! " << std::endl;
			std::cout << "---Press n to decrease the bet!" << std::endl;
			std::cout << "---Press q to quit!" << std::endl;
			std::cout << "---Press o to play with current bet!" << std::endl;
			std::cout << "---Press m for more games!" << std::endl;
			std::cout << "********************************************************************************************************************" << std::endl;
			std::cin >> y;
			//new code here for safety
			/*while (y.size() > 1) {

				std::cin >> y;
			}*/
			for (int i = 0; i < betVector.size(); i++) {
				if (y[0] == 'y' && y.size() == 1) {
					if (_credit_bet <= bet) {
						if (credit == FiveEuro && bet == FiveEuro) {
							std::cout << "You are already playing on max bet!" << std::endl;
							std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
							break;
						}
						else {
							std::cout << "Not enough credits to increase the bet!" << std::endl;
							std::cout << "Credits: " << _credit_bet << std::endl;
							std::cout << "Bet: " << bet << std::endl;

							break;
						}

					}
					else {

						if (betVector[i] >= FiveEuro) {
							betVector[i] = FiveEuro;
							bet = betVector[i];
							countAbove++;
						}
						else {
							if (credit == oneEuro) {
								bet = oneEuro;
							}
							if (_credit_bet == oneEuro) {
								bet = oneEuro;
							}
							else {

								betVector[i] += oneEuro;
								bet = betVector[i];
							}

							countBelow = 0;
						}
						if (countAbove > 0) {
							std::cout << "You are already playing on max bet!" << std::endl;
						}
						std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
						break;
					}

				}
				if (y[0] == 'n' && y.size() == 1) {

					if (betVector[i] <= oneEuro) {
						betVector[i] = oneEuro;
						bet = betVector[i];
						countBelow++;
					}
					else {
						betVector[i] -= 1;
						bet = betVector[i];
						countBelow = 0;
					}
					if (countBelow > 0) {
						std::cout << "You are already playing on minimum bet!" << std::endl;
					}
					std::cout << "Your Current bet is: " << bet << " Euro" << std::endl;
					break;
				}
				if (y[0] == 'q' && y.size() == 1) {
					std::cout << "Cashout..." << std::endl;
					std::cout << "Handpay! Call Attendant! " << _credit_bet << " Euro!" << std::endl;
					
					//std::chrono::seconds duration(3);
					//std::this_thread::sleep_for(duration);
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();
					credit = 0;
					//choosing a game
					selectgame.selectGame_Option(credit);
					//exit(0);
					break;
				}
				if (y[0] == 'm' && y.size() == 1) {
					SelectGame selectgame;
					selectgame.selectGame_Welcome();
					selectgame.selectGame_Games();

					//choosing a game
					selectgame.selectGame_Option(credit);
				}

				if (y[0] == 'o' && y.size() == 1) {
					bet = betVector[i];
					Start startgame;
					startgame.StartGameNowWisePharaohs5(_credit_bet, bet);
					confirm = "ok";
					break;
				}
				else {
					std::cout << "Invalid Input" << std::endl;
					bet = oneEuro;
					std::cin >> y;
				}
			}
		}
	}
	return bet;
}
Bet::~Bet() {
	//destroying
}
