#include "PaytableWisePharaohs5.h"
int const multiplier = 3;

//fixed rows
const int row0 = 0;
const int row1 = 1;
const int row2 = 2;

//fixed columns;
const int column0 = 0;
const int column1 = 1;
const int column2 = 2;
const int column3 = 3;
const int column4 = 4;

PaytableWisePharaohs5::PaytableWisePharaohs5(std::vector<std::vector<int>>myVectorInPaytableWisePharaohs, double creditInWisePharaohs, unsigned int betInWisePharaohs, bool isInFreeGames) {
	_creditInWisePharaohs = creditInWisePharaohs;
	_betInWisePharaohs = betInWisePharaohs;
	_isInFreeGames = isInFreeGames;

	for (int i = 0; i < myVectorInPaytableWisePharaohs.size(); ++i) {
		for (int j = 0; j < myVectorInPaytableWisePharaohs[i].size(); ++j) {
			_myVectorInPaytableWisePharaohs[i][j] = myVectorInPaytableWisePharaohs[i][j];
		}
	}
}
bool isInFreeSpins = false;
double PaytableWisePharaohs5::PaytableWisePharaohs5Win(std::vector<std::vector<int>>& myVectorInPaytableSuperFire, double& creditInPaytable, unsigned int& betInPaytable, bool &isInFreeGames) {
	// the ints in the random gen are 0 to 9 = 10 nums == 10 figures;
	const int cherryFigure = 1; //woman
	const int orangeFigure = 2; //man
	const int watermelonFigure = 3; // eye
	const int plumFigure = 4;     //sphinx
	const int grapesFigure = 5;  //Pharaoh
	const int Scatter = 6;
	

	//counters for non duplicate for credit!
	int counterScatterFigure = 0;

	int counterLine1FigureCherry = 0;
	int counterLine2FigureCherry = 0;
	int counterLine3FigureCherry = 0;
	int counterLine4FigureCherry = 0;
	int counterLine5FigureCherry = 0;

	int counterLine1FigureOrange = 0;
	int counterLine2FigureOrange = 0;
	int counterLine3FigureOrange = 0;
	int counterLine4FigureOrange = 0;
	int counterLine5FigureOrange = 0;

	int counterLine1FigureWatermelon = 0;
	int counterLine2FigureWatermelon = 0;
	int counterLine3FigureWatermelon = 0;
	int counterLine4FigureWatermelon = 0;
	int counterLine5FigureWatermelon = 0;

	int counterLine1FigurePlum = 0;
	int counterLine2FigurePlum = 0;
	int counterLine3FigurePlum = 0;
	int counterLine4FigurePlum = 0;
	int counterLine5FigurePlum = 0;

	int counterLine1FigureGrapes = 0;
	int counterLine2FigureGrapes = 0;
	int counterLine3FigureGrapes = 0;
	int counterLine4FigureGrapes = 0;
	int counterLine5FigureGrapes = 0;

	//credit prize which is added to current credit;
	double creditPrize = 0;

	char choiceForGamble;

	

	for (unsigned int i = 0; i < myVectorInPaytableSuperFire.size(); ++i) {
		for (int j = 0; j < myVectorInPaytableSuperFire[i].size(); ++j) {

			//Free Games;
			
			int const scatterPrize = 50;
			if (myVectorInPaytableSuperFire[i][j] == Scatter ) {
				counterScatterFigure++;
				 isInFreeSpins = true;
				if (counterScatterFigure >= 5 && i == myVectorInPaytableSuperFire.size() - 1) {
					Free_Games freeGamesStart(creditInPaytable, betInPaytable);
					freeGamesStart.Free_GamesWin(creditInPaytable, betInPaytable);

					creditInPaytable += creditPrize + scatterPrize;
				}
			}
			
			//---------------------------------------------------------------------Line 1 All Figures---------------------------------------------------------------------------------------------------------
			//line 1 - Cherry(5 figures);
			if (myVectorInPaytableSuperFire[row1][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row1][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row1][column3] == cherryFigure && myVectorInPaytableSuperFire[row1][column4] == cherryFigure) {
				if (counterLine1FigureCherry == 0) {
					std::cout << "Five Woman Figures on line 1!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureCherry++;
					break;
				}
			}
			//line 1 -Cherry(4 Figures);
			else if (myVectorInPaytableSuperFire[row1][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row1][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row1][column3] == cherryFigure) {
				if (counterLine1FigureCherry == 0) {
					std::cout << "Four Woman Figures on line 1!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureCherry++;
					break;
				}
			}
			//line 1 - Cherry(3 Figures)
			else if (myVectorInPaytableSuperFire[row1][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row1][column2] == cherryFigure) {
				if (counterLine1FigureCherry == 0) {
					std::cout << "Three Woman Figures on line 1!" << std::endl;
					creditPrize = 3;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureCherry++;
					break;
				}

			}

			//line 1 - Orange(5 figures)
			if (myVectorInPaytableSuperFire[row1][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row1][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row1][column3] == orangeFigure && myVectorInPaytableSuperFire[row1][column4] == orangeFigure) {
				if (counterLine1FigureOrange == 0) {
					std::cout << "Five Man Figures on line 1!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureOrange++;
					break;
				}

			}
			//line 1 - Orange(4 Figures)
			else if (myVectorInPaytableSuperFire[row1][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row1][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row1][column3] == orangeFigure) {
				if (counterLine1FigureOrange == 0) {
					std::cout << "Four Man Figures on line 1!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureOrange++;
					break;
				}
			}
			//line 1 - Orange(3 Figures)
			else if (myVectorInPaytableSuperFire[row1][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row1][column2] == orangeFigure) {
				if (counterLine1FigureOrange == 0) {
					std::cout << "Three Man Figures on line 1!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureOrange++;
					break;
				}
			}

			//line 1 - Watermelon(5 Figures);
			if (myVectorInPaytableSuperFire[row1][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row1][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row1][column3] == watermelonFigure && myVectorInPaytableSuperFire[row1][column4] == watermelonFigure) {
				if (counterLine1FigureWatermelon == 0) {
					std::cout << "Five Eye Figures on line 1!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureWatermelon++;
					break;
				}

			}
			//line 1 - Watermelon(4 Figures);
			else if (myVectorInPaytableSuperFire[row1][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row1][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row1][column3] == watermelonFigure) {
				if (counterLine1FigureWatermelon == 0) {
					std::cout << "Four Eye Figures on line 1!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
				}
				counterLine1FigureWatermelon++;
				break;
			}

			//line 1 - Watermelon(3 Figures);
			else if (myVectorInPaytableSuperFire[row1][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row1][column2] == watermelonFigure) {
				if (counterLine1FigureWatermelon == 0) {
					std::cout << "Three Eye Figures on line 1!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureWatermelon++;
					break;
				}
			}

			//line 1 - Plum(5 Figures)
			if (myVectorInPaytableSuperFire[row1][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row1][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row1][column3] == plumFigure && myVectorInPaytableSuperFire[row1][column4] == plumFigure) {
				if (counterLine1FigurePlum == 0) {
					std::cout << "Five Sphinx Figures on line 1!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigurePlum++;
					break;
				}
			}
			//line 1 - Plum(4 Figures)
			else if (myVectorInPaytableSuperFire[row1][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row1][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row1][column3] == plumFigure) {
				if (counterLine1FigurePlum == 0) {
					std::cout << "Four Sphinx Figures on line 1!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigurePlum++;
					break;
				}
			}
			//line 1 - Plum(3 Figures)
			else if (myVectorInPaytableSuperFire[row1][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row1][column2] == plumFigure) {
				if (counterLine1FigurePlum == 0) {
					std::cout << "Three Sphinx Figures on line 1!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigurePlum++;
					break;
				}
			}

			//line 1 - Grapes(5 Figures);
			if (myVectorInPaytableSuperFire[row1][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row1][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row1][column3] == grapesFigure && myVectorInPaytableSuperFire[row1][column4] == grapesFigure) {
				if (counterLine1FigureGrapes == 0) {
					if (betInPaytable == 5) {
						std::cout << "--------" << std::endl;
						std::cout << "Jackpot!" << std::endl;
						creditPrize = 1000000;
						std::cout << "--------" << std::endl;
					}
					else {
						std::cout << "Five Pharaoh Figures on line 1!" << std::endl;
						creditPrize = 9;
						if (isInFreeGames == true) {
							creditPrize = creditPrize * betInPaytable * multiplier;
						}
						else {
							creditPrize = creditPrize * betInPaytable;
						}
						std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
						std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
						std::cin >> choiceForGamble;
						if (choiceForGamble == '1') {
							Gamble playGamble(creditPrize);
							playGamble.CallGamble(creditPrize);
						}
					}


					creditInPaytable += creditPrize;
					counterLine1FigureGrapes++;
					break;
				}
			}
			//line 1 - Grapes(4 Figures);
			else if (myVectorInPaytableSuperFire[row1][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row1][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row1][column3] == grapesFigure) {
				if (counterLine1FigureGrapes == 0) {
					std::cout << "Four Pharaoh Figures on line 1!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine1FigureGrapes++;
					break;
				}
			}
			//line 1 - Grapes(3 Figures)
			else if (myVectorInPaytableSuperFire[row1][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row1][column2] == grapesFigure) {
				if (counterLine1FigureGrapes == 0) {
					std::cout << "Three Pharaoh Figures on line 1!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}

					creditInPaytable += creditPrize;
					counterLine1FigureGrapes++;
					break;
				}
			}


			//---------------------------------------------------------------------Line 2 All Figures---------------------------------------------------------------------------------------------------------
			if (myVectorInPaytableSuperFire[row0][column0] == cherryFigure && myVectorInPaytableSuperFire[row0][column1] == cherryFigure && myVectorInPaytableSuperFire[row0][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row0][column3] == cherryFigure && myVectorInPaytableSuperFire[row0][column4] == cherryFigure) {
				if (counterLine2FigureCherry == 0) {
					std::cout << "Five Woman Figures on line 2!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureCherry++;
					break;
				}

			}
			//line 2 -Cherry(4 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == cherryFigure && myVectorInPaytableSuperFire[row0][column1] == cherryFigure && myVectorInPaytableSuperFire[row0][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row0][column3] == cherryFigure) {
				if (counterLine2FigureCherry == 0) {
					std::cout << "Four Woman Figures on line 2!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureCherry++;
					break;
				}
			}
			//line 2 - Cherry(3 Figures)
			else if (myVectorInPaytableSuperFire[row0][column0] == cherryFigure && myVectorInPaytableSuperFire[row0][column1] == cherryFigure && myVectorInPaytableSuperFire[row0][column2] == cherryFigure) {
				if (counterLine2FigureCherry == 0) {
					std::cout << "Three Woman Figures on line 2!" << std::endl;
					creditPrize = 3;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureCherry++;
					break;
				}

			}

			//line 2 - Orange(5 figures)
			if (myVectorInPaytableSuperFire[row0][column0] == orangeFigure && myVectorInPaytableSuperFire[row0][column1] == orangeFigure && myVectorInPaytableSuperFire[row0][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row0][column3] == orangeFigure && myVectorInPaytableSuperFire[row0][column4] == orangeFigure) {
				if (counterLine2FigureOrange == 0) {
					std::cout << "Five Man Figures on line 2!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureOrange++;
					break;
				}

			}
			//line 2 - Orange(4 Figures)
			else if (myVectorInPaytableSuperFire[row0][column0] == orangeFigure && myVectorInPaytableSuperFire[row0][column1] == orangeFigure && myVectorInPaytableSuperFire[row0][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row0][column3] == orangeFigure) {
				if (counterLine2FigureOrange == 0) {
					std::cout << "Four Man Figures on line 2!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureOrange++;
					break;
				}
			}
			//line 2 - Orange(3 Figures)
			else if (myVectorInPaytableSuperFire[row0][column0] == orangeFigure && myVectorInPaytableSuperFire[row0][column1] == orangeFigure && myVectorInPaytableSuperFire[row0][column2] == orangeFigure) {
				if (counterLine2FigureOrange == 0) {
					std::cout << "Three Man Figures on line 2!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureOrange++;
					break;
				}
			}

			//line 2 - Watermelon(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == watermelonFigure && myVectorInPaytableSuperFire[row0][column1] == watermelonFigure && myVectorInPaytableSuperFire[row0][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row0][column3] == watermelonFigure && myVectorInPaytableSuperFire[row0][column4] == watermelonFigure) {
				if (counterLine2FigureWatermelon == 0) {
					std::cout << "Five Eye Figures on line 2!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureWatermelon++;
				}
				break;
			}
			//line 2 - Watermelon(4 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == watermelonFigure && myVectorInPaytableSuperFire[row0][column1] == watermelonFigure && myVectorInPaytableSuperFire[row0][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row0][column3] == watermelonFigure) {
				if (counterLine2FigureWatermelon == 0) {
					std::cout << "Four Eye Figures on line 2!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureWatermelon++;
					break;
				}
			}
			//line 2 - Watermelon(3 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == watermelonFigure && myVectorInPaytableSuperFire[row0][column1] == watermelonFigure && myVectorInPaytableSuperFire[row0][column2] == watermelonFigure) {
				if (counterLine2FigureWatermelon == 0) {
					std::cout << "Three Eye Figures on line 2!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureWatermelon++;
					break;
				}
			}

			//line 2 - Plum(5 Figures)
			if (myVectorInPaytableSuperFire[row0][column0] == plumFigure && myVectorInPaytableSuperFire[row0][column1] == plumFigure && myVectorInPaytableSuperFire[row0][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row0][column3] == plumFigure && myVectorInPaytableSuperFire[row0][column4] == plumFigure) {
				if (counterLine2FigurePlum == 0) {
					std::cout << "Five Sphinx Figures on line 2!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigurePlum++;
					break;
				}
			}
			//line 2 - Plum(4 Figures)
			else if (myVectorInPaytableSuperFire[row0][column0] == plumFigure && myVectorInPaytableSuperFire[row0][column1] == plumFigure && myVectorInPaytableSuperFire[row0][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row0][column3] == plumFigure) {
				if (counterLine2FigurePlum == 0) {
					std::cout << "Four Sphinx Figures on line 2!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigurePlum++;
					break;
				}
			}
			//line 2 - Plum(3 Figures)
			else if (myVectorInPaytableSuperFire[row0][column0] == plumFigure && myVectorInPaytableSuperFire[row0][column1] == plumFigure && myVectorInPaytableSuperFire[row0][column2] == plumFigure) {
				if (counterLine2FigurePlum == 0) {
					std::cout << "Three Sphinx Figures on line 2!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigurePlum++;
					break;
				}
			}

			//line 2 - Grapes(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == grapesFigure && myVectorInPaytableSuperFire[row0][column1] == grapesFigure && myVectorInPaytableSuperFire[row0][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row0][column3] == grapesFigure && myVectorInPaytableSuperFire[row0][column4] == grapesFigure) {
				if (counterLine2FigureGrapes == 0) {
					if (betInPaytable == 5) {
						std::cout << "--------" << std::endl;
						std::cout << "Jackpot!" << std::endl;
						creditPrize = 1000000;
						std::cout << "--------" << std::endl;
					}
					else {
						std::cout << "Five Pharaoh Figures on line 2!" << std::endl;
						creditPrize = 9;
						if (isInFreeGames == true) {
							creditPrize = creditPrize * betInPaytable * multiplier;
						}
						else {
							creditPrize = creditPrize * betInPaytable;
						}
						std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
						std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
						std::cin >> choiceForGamble;
						if (choiceForGamble == '1') {
							Gamble playGamble(creditPrize);
							playGamble.CallGamble(creditPrize);
						}
					}

					creditInPaytable += creditPrize;
					counterLine2FigureGrapes++;
					break;
				}
			}
			//line 2 - Grapes(4 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == grapesFigure && myVectorInPaytableSuperFire[row0][column1] == grapesFigure && myVectorInPaytableSuperFire[row0][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row0][column3] == grapesFigure) {
				if (counterLine2FigureGrapes == 0) {
					std::cout << "Four Pharaoh Figures on line 2!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureGrapes++;
					break;
				}

			}
			//line 2 - Grapes(3 Figures)
			else if (myVectorInPaytableSuperFire[row0][column0] == grapesFigure && myVectorInPaytableSuperFire[row0][column1] == grapesFigure && myVectorInPaytableSuperFire[row0][column2] == grapesFigure) {
				if (counterLine2FigureGrapes == 0) {
					std::cout << "Three Pharaoh Figures on line 2!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine2FigureGrapes++;
					break;
				}
			}
			//---------------------------------------------------------------------Line 3 All Figures---------------------------------------------------------------------------------------------------------
			if (myVectorInPaytableSuperFire[row2][column0] == cherryFigure && myVectorInPaytableSuperFire[row2][column1] == cherryFigure && myVectorInPaytableSuperFire[row2][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row2][column3] == cherryFigure && myVectorInPaytableSuperFire[row2][column4] == cherryFigure) {
				if (counterLine3FigureCherry == 0) {
					std::cout << "Five Woman Figures on line 3!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureCherry++;
					break;
				}
			}
			//line 3 -Cherry(4 Figures);
			else if (myVectorInPaytableSuperFire[row2][column0] == cherryFigure && myVectorInPaytableSuperFire[row2][column1] == cherryFigure && myVectorInPaytableSuperFire[row2][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row2][column3] == cherryFigure) {
				if (counterLine3FigureCherry == 0) {
					std::cout << "Four Woman Figures on line 3!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureCherry++;
					break;
				}
			}
			//line 3 - Cherry(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == cherryFigure && myVectorInPaytableSuperFire[row2][column1] == cherryFigure && myVectorInPaytableSuperFire[row2][column2] == cherryFigure) {
				if (counterLine3FigureCherry == 0) {
					std::cout << "Three Woman Figures on line 3!" << std::endl;
					creditPrize = 3;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureCherry++;
					break;
				}
			}

			//line 3 - Orange(5 figures)
			if (myVectorInPaytableSuperFire[row2][column0] == orangeFigure && myVectorInPaytableSuperFire[row2][column1] == orangeFigure && myVectorInPaytableSuperFire[row2][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row2][column3] == orangeFigure && myVectorInPaytableSuperFire[row2][column4] == orangeFigure) {
				if (counterLine3FigureOrange == 0) {
					std::cout << "Five Man Figures on line 3!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureOrange++;
					break;
				}
			}
			//line 3 - Orange(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == orangeFigure && myVectorInPaytableSuperFire[row2][column1] == orangeFigure && myVectorInPaytableSuperFire[row2][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row2][column3] == orangeFigure) {
				if (counterLine3FigureOrange == 0) {
					std::cout << "Four Man Figures on line 3!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureOrange++;
					break;
				}
			}
			//line 3 - Orange(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == orangeFigure && myVectorInPaytableSuperFire[row2][column1] == orangeFigure && myVectorInPaytableSuperFire[row2][column2] == orangeFigure) {
				if (counterLine3FigureOrange == 0) {
					std::cout << "Three Man Figures on line 3!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureOrange++;
					break;
				}
			}

			//line 3 - Watermelon(5 Figures);
			if (myVectorInPaytableSuperFire[row2][column0] == watermelonFigure && myVectorInPaytableSuperFire[row2][column1] == watermelonFigure && myVectorInPaytableSuperFire[row2][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row2][column3] == watermelonFigure && myVectorInPaytableSuperFire[row2][column4] == watermelonFigure) {
				if (counterLine3FigureWatermelon == 0) {
					std::cout << "Five Eye Figures on line 3!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureWatermelon++;
					break;
				}
			}
			//line 3 - Watermelon(4 Figures);
			else if (myVectorInPaytableSuperFire[row2][column0] == watermelonFigure && myVectorInPaytableSuperFire[row2][column1] == watermelonFigure && myVectorInPaytableSuperFire[row2][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row2][column3] == watermelonFigure) {
				if (counterLine3FigureWatermelon == 0) {
					std::cout << "Four Eye Figures on line 3!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureWatermelon++;
					break;
				}
			}
			//line 3 - Watermelon(3 Figures);
			else if (myVectorInPaytableSuperFire[row2][column0] == watermelonFigure && myVectorInPaytableSuperFire[row2][column1] == watermelonFigure && myVectorInPaytableSuperFire[row2][column2] == watermelonFigure) {
				if (counterLine3FigureWatermelon == 0) {
					std::cout << "Three Eye Figures on line 3!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureWatermelon++;
					break;
				}
			}

			//line 3 - Plum(5 Figures)
			if (myVectorInPaytableSuperFire[row2][column0] == plumFigure && myVectorInPaytableSuperFire[row2][column1] == plumFigure && myVectorInPaytableSuperFire[row2][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row2][column3] == plumFigure && myVectorInPaytableSuperFire[row2][column4] == plumFigure) {
				if (counterLine3FigurePlum == 0) {
					std::cout << "Five Sphinx Figures on line 3!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigurePlum++;
					break;
				}
			}
			//line 3 - Plum(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == plumFigure && myVectorInPaytableSuperFire[row2][column1] == plumFigure && myVectorInPaytableSuperFire[row2][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row2][column3] == plumFigure) {
				if (counterLine3FigurePlum == 0) {
					std::cout << "Four Sphinx Figures on line 3!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigurePlum++;
					break;
				}
			}
			//line 3 - Plum(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == plumFigure && myVectorInPaytableSuperFire[row2][column1] == plumFigure && myVectorInPaytableSuperFire[row2][column2] == plumFigure) {
				if (counterLine3FigurePlum == 0) {
					std::cout << "Three Sphinx Figures on line 3!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigurePlum++;
					break;
				}
			}

			//line 3 - Grapes(5 Figures);
			if (myVectorInPaytableSuperFire[row2][column0] == grapesFigure && myVectorInPaytableSuperFire[row2][column1] == grapesFigure && myVectorInPaytableSuperFire[row2][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row2][column3] == grapesFigure && myVectorInPaytableSuperFire[row2][column4] == grapesFigure) {
				if (counterLine3FigureGrapes == 0) {
					if (betInPaytable == 5) {
						std::cout << "--------" << std::endl;
						std::cout << "Jackpot!" << std::endl;
						creditPrize = 1000000;
						std::cout << "--------" << std::endl;
					}
					else {


						std::cout << "Five Pharaoh Figures on line 3!" << std::endl;
						creditPrize = 9;
						if (isInFreeGames == true) {
							creditPrize = creditPrize * betInPaytable * multiplier;
						}
						else {
							creditPrize = creditPrize * betInPaytable;
						}
						std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
						std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
						std::cin >> choiceForGamble;
						if (choiceForGamble == '1') {
							Gamble playGamble(creditPrize);
							playGamble.CallGamble(creditPrize);
						}
					}
					creditInPaytable += creditPrize;
					counterLine3FigureGrapes++;
					break;
				}
			}
			//line 3 - Grapes(4 Figures);
			else if (myVectorInPaytableSuperFire[row2][column0] == grapesFigure && myVectorInPaytableSuperFire[row2][column1] == grapesFigure && myVectorInPaytableSuperFire[row2][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row2][column3] == grapesFigure) {
				if (counterLine3FigureGrapes == 0) {
					std::cout << "Four Pharaoh Figures on line 3!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureGrapes++;
					break;
				}

			}
			//line 3 - Grapes(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == grapesFigure && myVectorInPaytableSuperFire[row2][column1] == grapesFigure && myVectorInPaytableSuperFire[row2][column2] == grapesFigure) {
				if (counterLine3FigureGrapes == 0) {
					std::cout << "Three Pharaoh Figures on line 3!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine3FigureGrapes++;
					break;
				}
			}
			//---------------------------------------------------------------------Line 4 All Figures---------------------------------------------------------------------------------------------------------
			//line 4 - Cherry(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row2][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row1][column3] == cherryFigure && myVectorInPaytableSuperFire[row0][column4] == cherryFigure) {
				if (counterLine4FigureCherry == 0) {
					std::cout << "Five Woman Figures on line 4!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureCherry++;
					break;
				}
			}
			//line 4 - Cherry(4 Figures); 
			else if (myVectorInPaytableSuperFire[row0][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row2][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row1][column3] == cherryFigure) {
				if (counterLine4FigureCherry == 0) {
					std::cout << "Four Woman Figures on line 4!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureCherry++;
					break;
				}
			}
			//line 4 - Cherry(3 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row2][column2] == cherryFigure) {
				if (counterLine4FigureCherry == 0) {
					std::cout << "Three Woman Figures on line 4!" << std::endl;
					creditPrize = 3;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureCherry++;
					break;
				}
			}

			//line 4 - Orange(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row2][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row1][column3] == orangeFigure && myVectorInPaytableSuperFire[row0][column4] == orangeFigure) {
				if (counterLine4FigureOrange == 0) {
					std::cout << "Five Man Figures on line 4!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureOrange++;
					break;
				}
			}
			//line 4 - Orange(4 Figures); 
			else if (myVectorInPaytableSuperFire[row0][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row2][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row1][column3] == orangeFigure) {
				if (counterLine4FigureOrange == 0) {
					std::cout << "Four Man Figures on line 4!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureOrange++;
					break;
				}
			}
			//line 4 - Orange(3 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row2][column2] == orangeFigure) {
				if (counterLine4FigureOrange == 0) {
					std::cout << "Three Man Figures on line 4!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureOrange++;
					break;
				}
			}

			//line 4 - Watermelon(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row2][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row1][column3] == watermelonFigure && myVectorInPaytableSuperFire[row0][column4] == watermelonFigure) {
				if (counterLine4FigureWatermelon == 0) {
					std::cout << "Five Eye Figures on line 4!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureWatermelon++;
					break;
				}
			}
			//line 4 - Watermelon(4 Figures); 
			else if (myVectorInPaytableSuperFire[row0][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row2][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row1][column3] == watermelonFigure) {
				if (counterLine4FigureWatermelon == 0) {
					std::cout << "Four Eye Figures on line 4!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureWatermelon++;
					break;
				}
			}
			//line 4 - Watermelon(3 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row2][column2] == watermelonFigure) {
				if (counterLine4FigureWatermelon == 0) {
					std::cout << "Three Eye Figures on line 4!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureWatermelon++;
					break;
				}
			}

			//line 4 - Plum(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row2][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row1][column3] == plumFigure && myVectorInPaytableSuperFire[row0][column4] == plumFigure) {
				if (counterLine4FigurePlum == 0) {
					std::cout << "Five Sphinx Figures on line 4!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigurePlum++;
					break;
				}
			}
			//line 4 - Plum(4 Figures); 
			else if (myVectorInPaytableSuperFire[row0][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row2][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row1][column3] == plumFigure) {
				if (counterLine4FigurePlum == 0) {
					std::cout << "Four Sphinx Figures on line 4!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigurePlum++;
					break;
				}
			}
			//line 4 - Plum(3 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row2][column2] == plumFigure) {
				if (counterLine4FigurePlum == 0) {
					std::cout << "Three Sphinx Figures on line 4!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigurePlum++;
					break;
				}
			}

			//line 4 - Grapes(5 Figures);
			if (myVectorInPaytableSuperFire[row0][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row2][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row1][column3] == grapesFigure && myVectorInPaytableSuperFire[row0][column4] == grapesFigure) {
				if (counterLine4FigureGrapes == 0) {
					if (betInPaytable == 5) {
						std::cout << "--------" << std::endl;
						std::cout << "Jackpot!" << std::endl;
						creditPrize = 1000000;
						std::cout << "--------" << std::endl;
					}
					else {
						std::cout << "Five Pharaoh Figures on line 4!" << std::endl;
						creditPrize = 9;
						if (isInFreeGames == true) {
							creditPrize = creditPrize * betInPaytable * multiplier;
						}
						else {
							creditPrize = creditPrize * betInPaytable;
						}
						std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
						std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
						std::cin >> choiceForGamble;
						if (choiceForGamble == '1') {
							Gamble playGamble(creditPrize);
							playGamble.CallGamble(creditPrize);
						}
					}
					creditInPaytable += creditPrize;
					counterLine4FigureGrapes++;
					break;
				}
			}
			//line 4 - Grapes(4 Figures); 
			else if (myVectorInPaytableSuperFire[row0][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row2][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row1][column3] == grapesFigure) {
				if (counterLine4FigureGrapes == 0) {
					std::cout << "Four Pharaoh Figures on line 4!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureGrapes++;
					break;
				}
			}
			//line 4 - Grapes(3 Figures);
			else if (myVectorInPaytableSuperFire[row0][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row2][column2] == grapesFigure) {
				if (counterLine4FigureGrapes == 0) {
					std::cout << "Three Pharaoh Figures on line 4!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine4FigureGrapes++;
					break;
				}
			}

			//---------------------------------------------------------------------Line 5 All Figures---------------------------------------------------------------------------------------------------------

			//line 5 Cherry(5 Figures)
			if (myVectorInPaytableSuperFire[row2][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row0][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row1][column3] == cherryFigure && myVectorInPaytableSuperFire[row2][column4] == cherryFigure) {
				if (counterLine5FigureCherry == 0) {
					std::cout << "Five Woman Figures on line 5!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureCherry++;
					break;
				}
			}
			//line 5 Cherry(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row0][column2] == cherryFigure &&
				myVectorInPaytableSuperFire[row1][column3] == cherryFigure) {
				if (counterLine5FigureCherry == 0) {
					std::cout << "Four Woman Figures on line 5!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureCherry++;
					break;
				}
			}
			//line 5 Cherry(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == cherryFigure && myVectorInPaytableSuperFire[row1][column1] == cherryFigure && myVectorInPaytableSuperFire[row0][column2] == cherryFigure) {
				if (counterLine5FigureCherry == 0) {
					std::cout << "Three Woman Figures on line 5!" << std::endl;
					creditPrize = 3;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureCherry++;
					break;
				}
			}

			//line 5 Orange(5 Figures)
			if (myVectorInPaytableSuperFire[row2][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row0][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row1][column3] == orangeFigure && myVectorInPaytableSuperFire[row2][column4] == orangeFigure) {
				if (counterLine5FigureOrange == 0) {
					std::cout << "Five Man Figures on line 5!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureOrange++;
					break;
				}
			}
			//line 5 Orange(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row0][column2] == orangeFigure &&
				myVectorInPaytableSuperFire[row1][column3] == orangeFigure) {
				if (counterLine5FigureOrange == 0) {
					std::cout << "Four Man Figures on line 5!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureOrange++;
					break;
				}
			}
			//line 5 Orange(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == orangeFigure && myVectorInPaytableSuperFire[row1][column1] == orangeFigure && myVectorInPaytableSuperFire[row0][column2] == orangeFigure) {
				if (counterLine5FigureOrange == 0) {
					std::cout << "Three Man Figures on line 5!" << std::endl;
					creditPrize = 4;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureOrange++;
					break;
				}
			}

			//line 5 Watermelon(5 Figures)
			if (myVectorInPaytableSuperFire[row2][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row0][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row1][column3] == watermelonFigure && myVectorInPaytableSuperFire[row2][column4] == watermelonFigure) {
				if (counterLine5FigureWatermelon == 0) {
					std::cout << "Five Eye Figures on line 5!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureWatermelon++;
					break;
				}
			}
			//line 5 Watermelon(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row0][column2] == watermelonFigure &&
				myVectorInPaytableSuperFire[row1][column3] == watermelonFigure) {
				if (counterLine5FigureWatermelon == 0) {
					std::cout << "Four Eye Figures on line 5!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureWatermelon++;
					break;
				}
			}
			//line 5 Watermelon(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == watermelonFigure && myVectorInPaytableSuperFire[row1][column1] == watermelonFigure && myVectorInPaytableSuperFire[row0][column2] == watermelonFigure) {
				if (counterLine5FigureWatermelon == 0) {
					std::cout << "Three Eye Figures on line 5!" << std::endl;
					creditPrize = 5;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureWatermelon++;
					break;
				}
			}

			//line 5 Plum(5 Figures)
			if (myVectorInPaytableSuperFire[row2][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row0][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row1][column3] == plumFigure && myVectorInPaytableSuperFire[row2][column4] == plumFigure) {
				if (counterLine5FigurePlum == 0) {
					std::cout << "Five Sphinx Figures on line 5!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigurePlum++;
					break;
				}
			}
			//line 5 Plum(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row0][column2] == plumFigure &&
				myVectorInPaytableSuperFire[row1][column3] == plumFigure) {
				if (counterLine5FigurePlum == 0) {
					std::cout << "Four Sphinx Figures on line 5!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigurePlum++;
					break;
				}
			}
			//line 5 Plum(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == plumFigure && myVectorInPaytableSuperFire[row1][column1] == plumFigure && myVectorInPaytableSuperFire[row0][column2] == plumFigure) {
				if (counterLine5FigurePlum == 0) {
					std::cout << "Three Sphinx Figures on line 5!" << std::endl;
					creditPrize = 6;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigurePlum++;
					break;
				}
			}

			//line 5 Grapes(5 Figures)
			if (myVectorInPaytableSuperFire[row2][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row0][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row1][column3] == grapesFigure && myVectorInPaytableSuperFire[row2][column4] == grapesFigure) {
				if (counterLine5FigureGrapes == 0) {
					if (betInPaytable == 5) {
						std::cout << "--------" << std::endl;
						std::cout << "Jackpot!" << std::endl;
						creditPrize = 1000000;
						std::cout << "--------" << std::endl;
					}
					else {
						std::cout << "Five Pharaoh Figures on line 5!" << std::endl;
						creditPrize = 9;
						if (isInFreeGames == true) {
							creditPrize = creditPrize * betInPaytable * multiplier;
						}
						else {
							creditPrize = creditPrize * betInPaytable;
						}
						std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
						std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
						std::cin >> choiceForGamble;
						if (choiceForGamble == '1') {
							Gamble playGamble(creditPrize);
							playGamble.CallGamble(creditPrize);
						}
					}
					creditInPaytable += creditPrize;
					counterLine5FigureGrapes++;
					break;
				}
			}
			//line 5 Grapes(4 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row0][column2] == grapesFigure &&
				myVectorInPaytableSuperFire[row1][column3] == grapesFigure) {
				if (counterLine5FigureGrapes == 0) {
					std::cout << "Four Pharaoh Figures on line 5!" << std::endl;
					creditPrize = 8;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureGrapes++;
					break;
				}
			}
			//line 5 Grapes(3 Figures)
			else if (myVectorInPaytableSuperFire[row2][column0] == grapesFigure && myVectorInPaytableSuperFire[row1][column1] == grapesFigure && myVectorInPaytableSuperFire[row0][column2] == grapesFigure) {
				if (counterLine5FigureGrapes == 0) {
					std::cout << "Three Pharaoh Figures on line 5!" << std::endl;
					creditPrize = 7;
					if (isInFreeGames == true) {
						creditPrize = creditPrize * betInPaytable * multiplier;
					}
					else {
						creditPrize = creditPrize * betInPaytable;
					}
					std::cout << "Win: " << creditPrize << " Euro!" << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(creditPrize);
						playGamble.CallGamble(creditPrize);
					}
					creditInPaytable += creditPrize;
					counterLine5FigureGrapes++;
					break;
				}
			}
		}
	}

	return creditInPaytable;
}

void PaytableWisePharaohs5::PaytableWisePharaohs5Info() {
	int row = 3;
	int col = 5;
	std::vector<std::vector<int>> LinesVector;
	LinesVector.resize(row);

	std::cout << "********" << std::endl;
	std::cout << "PAYTABLE" << std::endl;
	std::cout << "********" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Number 1 is representing Woman Figure." << std::endl;
	std::cout << "Number 2 is representing Man Figure." << std::endl;
	std::cout << "Number 3 is representing Eye Figure." << std::endl;
	std::cout << "Number 4 is representing Sphinx Figure." << std::endl;
	std::cout << "Number 5 is representing Pharaoh Figure." << std::endl;
	std::cout << "Number 6 is representing Scatter Figure." << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Woman Figure: 3 Figures: 3 Euro, 4 Figures: 4 Euro, 5 Figures: 5 Euro" << std::endl;
	std::cout << "Man Figure: 3 Figures: 4 Euro, 4 Figures: 5 Euro, 5 Figures: 6 Euro" << std::endl;
	std::cout << "Eye Figure: 3 Figures: 5 Euro, 4 Figures: 6 Euro, 5 Figures: 7 Euro" << std::endl;
	std::cout << "Sphinx Figure: 3 Figures: 6 Euro, 4 Figures: 7 Euro, 5 Figures: 8 Euro" << std::endl;
	std::cout << "Pharaoh Figure: 3 Figures: 7 Euro, 4 Figures: 8 Euro, 5 Figures: 9 Euro" << std::endl;
	std::cout << "Scatter Figure: 5 Figures: 50 Euro" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "All Pays are left to right on the selected Lines: line 1 to Line 5!" << std::endl;
	std::cout << "Line wins are multiplied by the number of points bet on the winning line!" << std::endl;
	std::cout << "Only the highest payline is paid!" << std::endl;
	std::cout << "Scatters cannot be retriggered in Free Games!" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "This game has Jackpot and cannot be GAMBLED!" << std::endl;
	std::cout << "Jackpot prize is 1 000 000 Euro!" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Line 1: " << std::endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == 1 && j == 0) {
				LinesVector[i].push_back(1);
			}
			else
				if (i == 1 && j == 1) {
					LinesVector[i].push_back(1);
				}
				else
					if (i == 1 && j == 2) {
						LinesVector[i].push_back(1);
					}
					else
						if (i == 1 && j == 3) {
							LinesVector[i].push_back(1);
						}
						else
							if (i == 1 && j == 4) {
								LinesVector[i].push_back(1);
							}
							else {
								LinesVector[i].push_back(0);
							}
		}
	}
	for (int i = 0; i < LinesVector.size(); ++i) {
		for (int j = 0; j < LinesVector[i].size(); ++j) {
			std::cout << LinesVector[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	LinesVector.clear();
	LinesVector.resize(row);
	std::cout << "Line 2: " << std::endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == 0 && j == 0) {
				LinesVector[i].push_back(2);
			}
			else
				if (i == 0 && j == 1) {
					LinesVector[i].push_back(2);
				}
				else
					if (i == 0 && j == 2) {
						LinesVector[i].push_back(2);
					}
					else
						if (i == 0 && j == 3) {
							LinesVector[i].push_back(2);
						}
						else
							if (i == 0 && j == 4) {
								LinesVector[i].push_back(2);
							}
							else {
								LinesVector[i].push_back(0);
							}
		}
	}
	for (int i = 0; i < LinesVector.size(); ++i) {
		for (int j = 0; j < LinesVector[i].size(); ++j) {
			std::cout << LinesVector[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	LinesVector.clear();
	LinesVector.resize(row);
	std::cout << "Line 3: " << std::endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == 2 && j == 0) {
				LinesVector[i].push_back(3);
			}
			else
				if (i == 2 && j == 1) {
					LinesVector[i].push_back(3);
				}
				else
					if (i == 2 && j == 2) {
						LinesVector[i].push_back(3);
					}
					else
						if (i == 2 && j == 3) {
							LinesVector[i].push_back(3);
						}
						else
							if (i == 2 && j == 4) {
								LinesVector[i].push_back(3);
							}
							else {
								LinesVector[i].push_back(0);
							}
		}
	}
	for (int i = 0; i < LinesVector.size(); ++i) {
		for (int j = 0; j < LinesVector[i].size(); ++j) {
			std::cout << LinesVector[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	LinesVector.clear();
	LinesVector.resize(row);
	std::cout << "Line 4: " << std::endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == 0 && j == 0) {
				LinesVector[i].push_back(4);
			}
			else
				if (i == 1 && j == 1) {
					LinesVector[i].push_back(4);
				}
				else
					if (i == 2 && j == 2) {
						LinesVector[i].push_back(4);
					}
					else
						if (i == 1 && j == 3) {
							LinesVector[i].push_back(4);
						}
						else
							if (i == 0 && j == 4) {
								LinesVector[i].push_back(4);
							}
							else {
								LinesVector[i].push_back(0);
							}
		}
	}
	for (int i = 0; i < LinesVector.size(); ++i) {
		for (int j = 0; j < LinesVector[i].size(); ++j) {
			std::cout << LinesVector[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	LinesVector.clear();
	LinesVector.resize(row);
	std::cout << "Line 5: " << std::endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == 2 && j == 0) {
				LinesVector[i].push_back(5);
			}
			else
				if (i == 1 && j == 1) {
					LinesVector[i].push_back(5);
				}
				else
					if (i == 0 && j == 2) {
						LinesVector[i].push_back(5);
					}
					else
						if (i == 1 && j == 3) {
							LinesVector[i].push_back(5);
						}
						else
							if (i == 2 && j == 4) {
								LinesVector[i].push_back(5);
							}
							else {
								LinesVector[i].push_back(0);
							}
		}
	}
	for (int i = 0; i < LinesVector.size(); ++i) {
		for (int j = 0; j < LinesVector[i].size(); ++j) {
			std::cout << LinesVector[i][j] << "   ";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	LinesVector.clear();
}
