#include "CreditField.h"
double const addCreditLimit = 10000;
CreditField::CreditField(double credit) {
	_credit = credit;
}
CreditField::CreditField() {
	_credit = 0;
}
double CreditField::AddCredit(double &credit) {
	std::string addCredit;
	std::cout << "Insert Credit: ";
	std::cin >> addCredit;
	for (int i = 0; i < addCredit.size(); i++) {
		if (!isdigit(addCredit[i]) && addCredit[i] != '.') {
			std::cout << "counterfeit!" << std::endl;
			std::chrono::seconds duration(3);
			std::this_thread::sleep_for(duration);
			addCredit[0] = 0;
			AddCredit(credit);
			
			//exit(0);
		}
	}
	double addCreditConvert;
	std::istringstream istr(addCredit);
	istr >> addCreditConvert;
	while (addCreditConvert > addCreditLimit) {
		std::cout << "The Limit is: " << addCreditLimit<< " Euro!" << std::endl;
		std::cout << "Invalid Input!" << std::endl;
		std::cout << "Insert Credit To Play:";
		std::cin >> addCredit;
		std::istringstream istr(addCredit);
		istr >> addCreditConvert;
	}
	credit += addCreditConvert;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Current Credit: " << credit << std::endl;
	std::cout << "---------------------------" << std::endl;
	return credit;
}
CreditField::~CreditField() {
	//just destroying;
}

