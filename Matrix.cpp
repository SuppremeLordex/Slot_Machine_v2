#include "Matrix.h"

int const _rows = 3;
int const _columns = 5;

Matrix::Matrix() {
	for (int i = 0; i < _matrixVec.size(); i++) {
		for (int j = 0; j < _matrixVec[i].size(); j++) {
			_matrixVec[i][j] = 0;
		}
	}
}
Matrix::Matrix(std::vector<std::vector<int>> matrixVec) {
	_matrixVec = matrixVec;
}

std::vector<std::vector<int>> Matrix::RandomNumbersInMatrix(std::vector<std::vector<int>>& matrixVec) {
	srand(time(0));
	int randomNumber;
	int const numberOfFigures = 5;
	for (int i = 0; i < _rows; ++i) {
		matrixVec.push_back(std::vector<int>());

		for (int j = 0; j < _columns; ++j) {
			randomNumber = rand() % numberOfFigures + 1;
			matrixVec[i].push_back(randomNumber);
		}
	}

	return matrixVec;
}
std::vector<std::vector<int>> Matrix::getVectorMatrix() {
	return _matrixVec;
}
void Matrix::outPutMatrix(std::vector<std::vector<int>>&matrixVec) {
	for (int i = 0; i < matrixVec.size(); ++i) {
		for (int j = 0; j < matrixVec[i].size(); ++j) {
			std::cout << matrixVec[i][j] << "   ";
		}
		std::cout << " " << std::endl;;
		std::cout << std::endl;
	}
}
Matrix::~Matrix() {
	//just to destroy it here;
}


