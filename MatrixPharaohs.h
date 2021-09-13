#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
class MatrixPharaohs {
private:
	std::vector<std::vector<int>> _matrixVec;

public:
	MatrixPharaohs();
	std::vector<std::vector<int>> RandomNumbersInMatrixPharaohs(std::vector<std::vector<int>>& matrixVec);
	void outPutMatrixPharaohs(std::vector<std::vector<int>>& matrixVec);
	MatrixPharaohs(std::vector<std::vector<int>> matrixVec);
	std::vector<std::vector<int>>getVectorMatrixPharaos();
	~MatrixPharaohs();
};