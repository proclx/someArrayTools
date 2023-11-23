#pragma once
#include <fstream>
#include <iostream>
using std::string;
// task 1
void manageArray(void(*func)(int* arr, const int len), int* arr, const int len);
int* readArray(int& len, const string fileName);
void printArray(const int* arr, const int len);
void mapSquare(int* arr, const int len);
void mapMultiplyByTwo(int* arr, const int len);
// task 2
int* isEven(const int* arr, const int len, int& newlen);
int* isPositive(const int* arr, const int len, int& newlen);
int* createArrayWithNumbers(int* (*func)(const int* arr, int len, int& newlen), const int* arr, const int len, int& newlen);
// task 3
int minValue(const int* arr, const int len);
int sumInRange(int* start, const int* end);
void deleteArray(int* arr, int& len);