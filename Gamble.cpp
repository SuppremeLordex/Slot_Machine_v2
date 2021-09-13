#include "Gamble.h"

int const maxGambleAttempts = 5;
Gamble::Gamble() {
	//default constructor;
}
Gamble::Gamble(double creditGamble) {
	_creditGamble = creditGamble;
}

double Gamble::CallGamble(double& creditGamble) {
	int randomNumber;
	int counter = 0;
	
	std::string option;
	int intOption;
	std::cout << "*********************GAMBLE*****************************" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	/*std::cout << "Enter your choice: 0 red" << std::endl;
	std::cout << "Enter your choice: 1 black" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Insert Any other Number to take win!" << std::endl;*/
	
	bool isGambleLost = false;
	while (counter < maxGambleAttempts) {
		srand(time(0));
		randomNumber = rand() % 2;
		if (isGambleLost == true) {
			break;
		}
		std::cout << "Enter your choice: 0 red" << std::endl;
		std::cout << "Enter your choice: 1 black" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Insert Any other Number to take win!" << std::endl;
		std::cin >> option;
		intOption = option[0] - '0';
		if (option[0] != '1' && option[0] != '0') {

			return creditGamble;
			
		}else

		if (intOption == randomNumber) {
			creditGamble = creditGamble * 2;
			std::cout << "--------------------------------------------------------" << std::endl;
			std::cout << "Result: " << randomNumber << std::endl;
			std::cout << "Gamble Won! " << creditGamble << " Euro!" << std::endl;
			std::cout << "--------------------------------------------------------" << std::endl;
			counter++;
		
		}
		else {
			std::cout << "--------------------------------------------------------" << std::endl;
			std::cout << "Result: " << randomNumber << std::endl;
			std::cout << "You Lost!" << std::endl;
			std::cout << "--------------------------------------------------------" << std::endl;
			creditGamble = 0;
			isGambleLost = true;
			
		}
	}
	return creditGamble;
}

void Gamble::GambleInfoScreen() {
	std::cout << "++++++++++++++++" << std::endl;
	std::cout << "Info For Gamble"  << std::endl;
	std::cout << "++++++++++++++++" << std::endl;

	std::cout << "Press Gamble, when you win a payline. " << std::endl;
	std::cout << "Then Select Red or Black (0 or 1)." << std::endl;
	std::cout << "If Red or Black choice is correct, the gamble amount is Doubled! (x2)." << std::endl;
	std::cout << "If Red or Black choice is NOT correct, the gamble amount is lost and the game is finished!" << std::endl;
	std::cout << "Maximum Gamble Attempts: " << maxGambleAttempts << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------" << std::endl;
}
Gamble::~Gamble() {
	//deconstructing
}


