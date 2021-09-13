#pragma once
#include <vector>
#include <iostream>
#include "Gamble.h"
#include "Free_Games.h"
class PaytableWisePharaohs5 {
private:
	std::vector<std::vector<int>>_myVectorInPaytableWisePharaohs;
	double _creditInWisePharaohs;
	unsigned int _betInWisePharaohs;
	bool _isInFreeGames;

public:
	PaytableWisePharaohs5(std::vector<std::vector<int>>myVectorInPaytableWisePharaohs, double creditInWisePharaohs, unsigned int betInWisePharaohs, bool isInFreeGames);
	double PaytableWisePharaohs5Win(std::vector<std::vector<int>>& myVectorInPaytableWisePharaohs, double& creditInWisePharaohs, unsigned int& betInWisePharaohs, bool& isInFreeGames);
	void PaytableWisePharaohs5Info();
};