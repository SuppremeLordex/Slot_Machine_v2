#include "Keno_HotAndCold.h"
static std::vector<int> saveGeneratedNumbers;
static std::vector<int> printGeneratedNumbers;;
std::multimap<int, int> hot;
std::map<int, int> hot1;
int count = 0;
Keno_HotAndCold::Keno_HotAndCold() {
	//default constr
}
Keno_HotAndCold::Keno_HotAndCold(std::vector<int> vectorTo80Nums) {
	_vectorTo80Nums = vectorTo80Nums;
}
Keno_HotAndCold::~Keno_HotAndCold() {
	//deconstructing
}

void Keno_HotAndCold::infoHotAndCold(std::vector<int> &generate20Numbers) {
	int currNumber = 0;
	
	for (int i = 0; i < generate20Numbers.size(); ++i) {
		saveGeneratedNumbers.push_back(generate20Numbers[i]);
	}

	for (int i = 0; i < saveGeneratedNumbers.size(); ++i) {
		currNumber = saveGeneratedNumbers[i];
		for (int j = 1; j < saveGeneratedNumbers.size(); ++j) {
			if (saveGeneratedNumbers[i] == saveGeneratedNumbers[j]) {
				count++;
			}
		}
		hot.insert(std::pair<int, int>(currNumber, count));
		count = 0;
	}

	
	/*for (auto it = hot1.begin(); it != hot1.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}*/

	//int countHot = 0;
	//int number = 0;;
	//std::cout << "Hot Numbers: ";
	//for (auto it = hot.begin(); it != hot.end(); ++it) {
	//	
	//	for (auto it1 = it++; it1 != hot.end(); ++it1) {
	//		if (it->second < it1->second && it->first<=it1->first) { // count
	//			number = it1->first;
	//		}
	//		else {
	//			number = it -> first;
	//		}
	//	}
	//	printGeneratedNumbers.push_back(number);
	//}

	//int counter1 = 0;
	//for (size_t i = printGeneratedNumbers.size(); i >= 5 ; --i) {
	//	if (counter1 == 5) {
	//		break;
	//	}
	//	std::cout << printGeneratedNumbers[i] << " ";
	//}
	//count++;
	//std::cout << std::endl;
}


