#pragma once
//#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
class Keno_HotAndCold {
private:
	std::vector<int>_vectorTo80Nums;

public:
	Keno_HotAndCold(std::vector<int> vectorTo80Nums);
	Keno_HotAndCold();
	void infoHotAndCold(std::vector<int>& generate20Numbers);
	~Keno_HotAndCold();
};