#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>


class Matrix {
private:
	std::vector<std::vector<int>> _matrixVec;
	
public:
	Matrix();
	std::vector<std::vector<int>> RandomNumbersInMatrix(std::vector<std::vector<int>> &matrixVec);
	void outPutMatrix(std::vector<std::vector<int>>&matrixVec);
	Matrix(std::vector<std::vector<int>> matrixVec);
	std::vector<std::vector<int>>getVectorMatrix();
	~Matrix();
};