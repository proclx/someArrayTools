#include <fstream>
#include <iostream>
#include "f.h"
#include <queue>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

int* readArray(int& len, const string fileName) {
	ifstream readFromFile(fileName);
	readFromFile >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; ++i) {
		readFromFile >> arr[i];
	}
	readFromFile.close();
	return arr;
}

void printArray(const int* arr, const int len) {
	if (len == 0) {
		cout << "Empty array!" << endl;
		return;
	}
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void manageArray(void(*func)(int* arr, const int len), int* arr, const int len) {
	func(arr, len);
}

void mapSquare(int* arr, const int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] *= arr[i];
	}
}

void mapMultiplyByTwo(int* arr, const int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] *= 2;
	}
}

int* isEven(const int* arr, const int len, int &newlen) {
	std::queue<int> sNumbers;
	for (unsigned i = 0; i < len; ++i) {
		if (arr[i] % 2 == 0) {
			++newlen;
			sNumbers.push(arr[i]);
		}
	}
	int* result = new int[newlen];
	for (int i = 0; i < newlen; ++i) {
		result[i] = sNumbers.front();
		sNumbers.pop();
	}
	return result;
}

int* isPositive(const int* arr, const int len, int &newlen) {
	std::queue<int> sNumbers;
	for (unsigned i = 0; i < len; ++i) {
		if (arr[i] > 0) {
			++newlen;
			sNumbers.push(arr[i]);
		}
	}
	int* result = new int[newlen];
	for (int i = 0; i < newlen; ++i) {
		result[i] = sNumbers.front();
		sNumbers.pop();
	}
	return result;
}

int* createArrayWithNumbers(int*(*func)(const int* arr, int len, int &newlen), const int* arr, const int len, int &newlen) {
	return func(arr, len, newlen);
}

int minValue(const int* arr, const int len) {
	int min = arr[0];
	for (int i = 1; i < len; ++i) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

int sumInRange(int* start, const int* end) {
	int sum = 0;
	while (start != end+1) {
		sum += *start;
		++start;
	}
	return sum;
}

void deleteArray(int* arr, int&len) {
	len = 0;
	delete[] arr;
}