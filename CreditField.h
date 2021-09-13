#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
class CreditField {
private:
	double _credit;
public:
	CreditField(double credit);
	CreditField();
	~CreditField();
	double AddCredit(double& credit);
};