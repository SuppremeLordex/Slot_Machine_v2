#include "Keno.h"

int const row = 9;
int const column = 10;
int const maxSizeBet = 10;
int const maxRangeForKeno = 80;
int const generateNumbers = 20;

Keno::Keno(std::vector<std::vector<int>> kenoVector, double credits, unsigned bet) {
	_credits = credits;
	_bet = bet;
	for (int i = 0; i < _kenoVector.size(); ++i) {
		kenoVector.push_back(std::vector<int>());
		for (int j = 0; j < _kenoVector[i].size(); ++i) {
			_kenoVector[i][j] = kenoVector[i][j];
		}
	}
}

std::vector<std::vector<double>> Keno::fillKenoVector() {
	
	const std::vector<std::vector<double>>kenoVector{
				{10,90,0,0,0,0,0,0,0,0},                               //2 Numbers
				{10,20,180,0,0,0,0,0,0,0},							   //3 Numbers
				{0,20,110,200,0,0,0,0,0,0},                            //4 Numbers
				{0,10,40,250,800,0,0,0,0,0},                           //5 Numbers
				{0,10,20,80,450,2000,0,0,0,0},                         //6 Numbers
				{0,0,20,80,170,550,3000,0,0,0},                        //7 Numbers
				{0,0,20,30,120,200,1100,8000,0,0},                     //8 Numbers
				{0,0,10,30,70,170,650,2500,20000,0},                   //9 Numbers
				{0,0,10,20,40,110,300,1000,10000,50000},               //10 Number
	};

	return kenoVector;
}

std::vector<int> Keno::selectNumbers() {
	//std::cin.ignore();
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Input Numbers: " << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::vector<int>selectNumbersBet;
	//selectNumbersBet.resize(10);

	std::string line;
	std::cin.ignore();
	getline(std::cin, line);
	
	std::istringstream istr(line);
	int currNumber = 0;
	while (istr >> currNumber) {
		selectNumbersBet.push_back(currNumber);
	}
	int count = selectNumbersBet.size();
	while (count < 10) {
		selectNumbersBet.push_back(0);
		count++;
	}
	if (selectNumbersBet.size() > 10) {
		std::cout << "---------------------------------"<< std::endl;
		std::cout << "The max selected numbers are 10!" << std::endl;
		std::cout << "---------------------------------" <<std::endl;
		selectNumbers();
	}
	size_t size = selectNumbersBet.size();
	for (int i = 0; i < selectNumbersBet.size(); i++) {
		if (selectNumbersBet[i] == 0) {
			size--;
		}
	}

	if (size < 2) {
		std::cout << "---------------------------------" << std::endl;
		std::cout << "The min selected numbers are 2!"   << std::endl;
		std::cout << "---------------------------------" << std::endl;
		selectNumbers();
	}

	/*for (int i = 0; i < selectNumbersBet.size(); ++i) {
		for (int j = 1; j < selectNumbersBet.size(); ++j) {
			if (selectNumbersBet[i] == selectNumbersBet[j]) {
				std::cout << "---------------------------------" << std::endl;
				std::cout << "The Numbers must NOT repeat!" << std::endl;
				std::cout << "---------------------------------" << std::endl;
				selectNumbers();
			}
		}
	}*/
	return selectNumbersBet;
}

//does not work as expected -- 
//need to add counters for hot and cold;
std::vector<int> Keno::generate20Numbers() {
	srand(time(0));
	std::vector<int> rand20Nums;
	std::unordered_set<int> rand20NumsSet;
	int currNumber;
	int last = 80;
	int first = 1;
	int const maxNumbers =20;
	//int currNumberSet;
	for (int i = 0; i < maxNumbers; ++i) {
		currNumber = rand() % (last + 1 - first) + first;
		rand20NumsSet.insert(currNumber);
	}
	if (rand20NumsSet.size() < maxNumbers) {
		while (rand20NumsSet.size() < maxNumbers) {
			currNumber = rand() % (last + 1 - first) + first;
			rand20NumsSet.insert(currNumber);
		}
	}
	
		for (auto it = rand20NumsSet.begin(); it != rand20NumsSet.end(); ++it) {
			rand20Nums.push_back(*it);
		}
	
	Keno_HotAndCold info;
	info.infoHotAndCold(rand20Nums);
	return rand20Nums;
}

void Keno::outputGeneratedNumbers(std::vector<int>& outputVector) {
	for (int i = 0; i < outputVector.size(); ++i) {
		std::cout << outputVector[i] << " ";
	}
	std::cout << std::endl;
}
double Keno::checkForHits(double &credits, unsigned int &bet) {
	std::vector<std::vector<double>> paytable;
	paytable = fillKenoVector();
	std::vector<int> inputNumbers;
	inputNumbers = selectNumbers();
	std::vector<int> generatedNumbers;
	generatedNumbers = generate20Numbers();
	std::cout << "-----------------------------------------------" << std::endl;
	outputGeneratedNumbers(generatedNumbers);
	std::cout << "-----------------------------------------------" << std::endl;
	char choiceForGamble;
	double  creditPrize;
	//for loop to check for zeros;
	// == size;
	size_t size = inputNumbers.size();
	for (int i = 0; i < inputNumbers.size(); i++) {
		if (inputNumbers[i] == 0) {
			size--;
		}
	}
	int counter = 0;
	for (int i = 0; i < generatedNumbers.size(); ++i) {
		for (int j = 0; j < inputNumbers.size(); ++j) {
			if (size == 2) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 2 && i == generatedNumbers.size() - 1) {
					paytable[0][1] = paytable[0][1] * bet;
					std::cout <<  "2 Hits: " << paytable[0][1] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						creditPrize = paytable[0][1];
						Gamble playGamble(paytable[0][1]);
						playGamble.CallGamble(paytable[0][1]);

					}
					credits += paytable[0][1];
					break;
				}
				else if (counter == 1 && i == generatedNumbers.size() - 1) {
					paytable[0][0] = paytable[0][0] * bet;
					std::cout << "1 Hit: " << paytable[0][0] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[0][0]);
						playGamble.CallGamble(paytable[0][0]);
					}
					credits += paytable[0][0];
					break;
				}
			}
			if (size == 3) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[1][2] = paytable[1][2] * bet;
					std::cout <<  "3 Hits: " << paytable[1][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[1][2]);
						playGamble.CallGamble(paytable[1][2]);
					}
					credits += paytable[1][2];
					break;
				}
				else if (counter == 2 && i == generatedNumbers.size() - 1) {
					paytable[1][1] = paytable[1][1] * bet;
					std::cout <<  "2 Hits: " << paytable[1][1] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[1][1]);
						playGamble.CallGamble(paytable[1][1]);
					}
					credits += paytable[1][1];
					break;
				}
				else if (counter == 1 && i == generatedNumbers.size() - 1) {
					paytable[1][0]= paytable[1][0] * bet;
					std::cout <<"1 Hit: " << paytable[1][0] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[1][0]);
						playGamble.CallGamble(paytable[1][0]);
					}
					credits += paytable[1][0];
					break;
				}
			}
			if (size == 4) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[2][3] = paytable[2][3] * bet;
					std::cout <<  "4 Hits: " << paytable[2][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[2][3]);
						playGamble.CallGamble(paytable[2][3]);
					}
					credits += paytable[2][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[2][2] = paytable[2][2] * bet;
					std::cout <<  "3 Hits: " << paytable[2][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[2][2]);
						playGamble.CallGamble(paytable[2][2]);
					}
					credits += paytable[2][2];
					break;
				}
				else if (counter == 2 && i == generatedNumbers.size() - 1) {
					paytable[2][1] = paytable[2][1] * bet;
					std::cout <<  "2 Hits: " << paytable[2][1] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[2][1]);
						playGamble.CallGamble(paytable[2][1]);
					}
					credits += paytable[2][1];
					break;
				}
			}
			if (size == 5) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 5 && i == generatedNumbers.size() - 1) {
					paytable[3][4] = paytable[3][4] * bet;
					std::cout <<  "5 Hits: " << paytable[3][4] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[3][4]);
						playGamble.CallGamble(paytable[3][4]);
					}
					credits += paytable[3][4];
					break;
				}
				else if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[3][3] = paytable[3][3] * bet;
					std::cout <<  "4 Hits: " << paytable[3][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[3][3]);
						playGamble.CallGamble(paytable[3][3]);
					}
					credits += paytable[3][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[3][2] = paytable[3][2] * bet;
					std::cout << "3 Hits: " << paytable[3][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[3][2]);
						playGamble.CallGamble(paytable[3][2]);
					}
					credits += paytable[3][2];
					break;
				}
				else if (counter == 2 && i == generatedNumbers.size() - 1) {
					paytable[3][1] = paytable[3][1] * bet;
					std::cout << "2 Hits: " << paytable[3][1] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[3][1]);
						playGamble.CallGamble(paytable[3][1]);
					}
					credits += paytable[3][1];
					break;
				}
			}
			if (size == 6) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 6 && i == generatedNumbers.size() - 1) {
					paytable[4][5] = paytable[4][5] * bet;
					std::cout <<  "6 Hits: " << paytable[4][5] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[4][5]);
						playGamble.CallGamble(paytable[4][5]);
					}
					credits += paytable[4][5];
					break;
				}
				else if (counter == 5 && i == generatedNumbers.size() - 1) {
					paytable[4][4] = paytable[4][4] * bet;
					std::cout <<  "5 Hits: " << paytable[4][4] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[4][4]);
						playGamble.CallGamble(paytable[4][4]);
					}
					credits += paytable[4][4];
					break;
				}
				else if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[4][3] = paytable[4][3] * bet;
					std::cout <<  "4 Hits: " << paytable[4][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[4][3]);
						playGamble.CallGamble(paytable[4][3]);
					}
					credits += paytable[4][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[4][2] = paytable[4][2] * bet;
					std::cout << "3 Hits: " << paytable[4][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[4][2]);
						playGamble.CallGamble(paytable[4][2]);
					}
					credits += paytable[4][2];
					break;
				}
				else if (counter == 2 && i == generatedNumbers.size() - 1) {
					paytable[4][1] = paytable[4][1] * bet;
					std::cout <<  "2 Hits: " << paytable[4][1] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[4][1]);
						playGamble.CallGamble(paytable[4][1]);
					}
					credits += paytable[4][1];
					break;
				}
			}
			if (size == 7) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 7 && i == generatedNumbers.size() - 1) {
					paytable[5][6] = paytable[5][6] * bet;
					std::cout <<  "7 Hits: " << paytable[5][6] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[5][6]);
						playGamble.CallGamble(paytable[5][6]);
					}
					credits += paytable[5][6];
					break;
				}
				//here
				else if (counter == 6 && i == generatedNumbers.size() - 1) {
					paytable[5][5] = paytable[5][5] * bet;
					std::cout << "6 Hits: " << paytable[5][5] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[5][5]);
						playGamble.CallGamble(paytable[5][5]);
					}
					credits += paytable[5][5];
					break;
				}
				else if (counter == 5 && i == generatedNumbers.size() - 1) {
					paytable[5][4] = paytable[5][4] * bet;
					std::cout <<  "5 Hits: " << paytable[5][4] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[5][4]);
						playGamble.CallGamble(paytable[5][4]);
					}
					credits += paytable[5][4];
					break;
				}
				else if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[5][3] = paytable[5][3] * bet;
					std::cout << "4 Hits: " << paytable[5][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[5][3]);
						playGamble.CallGamble(paytable[5][3]);
					}
					credits += paytable[5][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[5][2] = paytable[5][2] * bet;
					std::cout <<  "3 Hits: " << paytable[5][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[5][2]);
						playGamble.CallGamble(paytable[5][2]);
					}
					credits += paytable[5][2];
					break;
				}
			}
			if (size == 8) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 8 && i == generatedNumbers.size() - 1) {
					paytable[6][7] = paytable[6][7] * bet;
					std::cout << "8 Hits: " << paytable[6][7] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[6][7]);
						playGamble.CallGamble(paytable[6][7]);
					}
					credits += paytable[6][7];
					break;
				}
				else if (counter == 7 && i == generatedNumbers.size() - 1) {
					paytable[6][6] = paytable[6][6] * bet;
					std::cout <<  "7 Hits: " << paytable[6][6] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[6][6]);
						playGamble.CallGamble(paytable[6][6]);
					}
					credits += paytable[6][6];
					break;
				}
				else if (counter == 6 && i == generatedNumbers.size() - 1) {
					paytable[6][5] = paytable[6][5] * bet;
					std::cout << "6 Hits: " << paytable[6][5] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[6][5]);
						playGamble.CallGamble(paytable[6][5]);
					}
					credits += paytable[6][5];
					break;
				}
				else if (counter == 5 && i == generatedNumbers.size() - 1) {
					paytable[6][4] = paytable[6][4] * bet;
					std::cout << "5 Hits: " << paytable[6][4] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[6][4]);
						playGamble.CallGamble(paytable[6][4]);
					}
					credits += paytable[6][4];
					break;
				}
				else if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[6][3] = paytable[6][3] * bet;
					std::cout <<  "4 Hits: " << paytable[6][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[6][3]);
						playGamble.CallGamble(paytable[6][3]);
					}
					credits += paytable[6][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[6][2] = paytable[6][2] * bet;
					std::cout <<  "3 Hits: " << paytable[6][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[6][2]);
						playGamble.CallGamble(paytable[6][2]);
					}
					credits += paytable[6][2];
					break;
				}
			}
			if (size == 9) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 9 && i == generatedNumbers.size() - 1) {
					paytable[7][8] = paytable[7][8] * bet;
					std::cout << "9 Hits: " << paytable[7][8] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][8]);
						playGamble.CallGamble(paytable[7][8]);
					}
					credits += paytable[7][8];
					break;
				}
				else if (counter == 8 && i == generatedNumbers.size() - 1) {
					paytable[7][7] = paytable[7][7] * bet;
					std::cout << "8 Hits: " << paytable[7][7] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][7]);
						playGamble.CallGamble(paytable[7][7]);
					}
					credits += paytable[7][7];
					break;
				}
				else if (counter == 7 && i == generatedNumbers.size() - 1) {
					paytable[7][6] = paytable[7][6] * bet;
					std::cout << "7 Hits: " << paytable[7][6] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][6]);
						playGamble.CallGamble(paytable[7][6]);
					}
					credits += paytable[7][6];
					break;
				}
				else if (counter == 6 && i == generatedNumbers.size() - 1) {
					paytable[7][5] = paytable[7][5] * bet;
					std::cout << "6 Hits: " << paytable[7][5] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][5]);
						playGamble.CallGamble(paytable[7][5]);
					}
					credits += paytable[7][5];
					break;
				}
				else if (counter == 5 && i == generatedNumbers.size() - 1) {
					paytable[7][4] = paytable[7][4] * bet;
					std::cout <<  "5 Hits: " << paytable[7][4] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][4]);
						playGamble.CallGamble(paytable[7][4]);
					}
					credits += paytable[7][4];
					break;
				}
				else if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[7][3] = paytable[7][3] * bet;
					std::cout <<  "4 Hits: " << paytable[7][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][3]);
						playGamble.CallGamble(paytable[7][3]);
					}
					credits += paytable[7][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[7][2]= paytable[7][2] * bet;
					std::cout <<  "3 Hits: " << paytable[7][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[7][2]);
						playGamble.CallGamble(paytable[7][2]);
					}
					credits += paytable[7][2];
					break;
				}
			}
			if (size == 10) {
				if (inputNumbers[j] == generatedNumbers[i]) {
					counter++;
				}
				if (counter == 10 && i == generatedNumbers.size() - 1) {
					paytable[8][9] = paytable[8][9] * bet;
					std::cout <<  "10 Hits: " << paytable[8][9] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][9]);
						playGamble.CallGamble(paytable[8][9]);
					}
					credits += paytable[8][9];
					break;
				}
				else if (counter == 9 && i == generatedNumbers.size() - 1) {
					paytable[8][8] = paytable[8][8] * bet;
					std::cout << "9 Hits: " << paytable[8][8] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][8]);
						playGamble.CallGamble(paytable[8][8]);
					}
					credits += paytable[8][8];
					break;
				}
				else if (counter == 8 && i == generatedNumbers.size() - 1) {
					paytable[8][7] = paytable[8][7] * bet;
					std::cout << "8 Hits: " << paytable[8][7] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][7]);
						playGamble.CallGamble(paytable[8][7]);
					}
					credits += paytable[8][7];
					break;
				}
				else if (counter == 7 && i == generatedNumbers.size() - 1) {
					paytable[8][6] = paytable[8][6] * bet;
					std::cout <<  "7 Hits: " << paytable[8][6] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][6]);
						playGamble.CallGamble(paytable[8][6]);
					}
					credits += paytable[8][6];
					break;
				}
				else if (counter == 6 && i == generatedNumbers.size() - 1) {
					paytable[8][5] = paytable[8][5] * bet;
					std::cout <<  "6 Hits: " << paytable[8][5] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][5]);
						playGamble.CallGamble(paytable[8][5]);
					}
					credits += paytable[8][5];
					break;
				}
				else if (counter == 5 && i == generatedNumbers.size() - 1) {
					paytable[8][4] = paytable[8][4] * bet;
					std::cout <<  "5 Hits: " << paytable[8][4] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][4]);
						playGamble.CallGamble(paytable[8][4]);
					}
					credits += paytable[8][4];
					break;
				}
				else if (counter == 4 && i == generatedNumbers.size() - 1) {
					paytable[8][3] = paytable[8][3] * bet;
					std::cout << "4 Hits: " << paytable[8][3] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][3]);
						playGamble.CallGamble(paytable[8][3]);
					}
					credits += paytable[8][3];
					break;
				}
				else if (counter == 3 && i == generatedNumbers.size() - 1) {
					paytable[8][2] = paytable[8][2] * bet;
					std::cout <<  "3 Hits: " << paytable[8][2] << std::endl;
					std::cout << "Gamble or take win, 1 for Gamble,or press any key to take win." << std::endl;
					std::cin >> choiceForGamble;
					if (choiceForGamble == '1') {
						Gamble playGamble(paytable[8][2]);
						playGamble.CallGamble(paytable[8][2]);
					}
					credits += paytable[8][2];
					break;
				}
			}
		}
	}
	counter = 0;
	return credits;
}

void Keno::infoPageKeno() {
	std::cout << "----------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "In Keno, the player chooses up to 10 numbers from 1 to 80. " << std::endl;
	std::cout << "During the game 20 numbers are drawn. " << std::endl;
	std::cout << "The winning are paid out according to the paytable depending on the matches between the player's choice and the drawn numbers." << std::endl;
	std::cout << "*Hot and cold text, when I make this Feature!*" << std::endl;
	std::cout << "Only the highest winning combination is paid." << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------" << std::endl;

}

Keno::~Keno() {
	//just deconstructing
}

