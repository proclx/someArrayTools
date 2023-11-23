#include <iostream>
#include "f.h"
using std::cout;
using std::endl;
using std::string;

int main() {
	string file = "data.txt";
	int len;
	int* ORIGINAL_ARRAY = readArray(len, file);
	int* arr = readArray(len, file);
	cout << "ORIGINAL ARRAY -> ";
	printArray(arr, len);

	manageArray(mapSquare, arr, len);
	cout << "array to square -> ";
	printArray(arr, len);

	manageArray(mapMultiplyByTwo, arr, len);
	cout << "array multiplied by two -> ";
	printArray(arr, len);

	int positive_len = 0;
	int* pos_arr = createArrayWithNumbers(isPositive, ORIGINAL_ARRAY, len, positive_len);
	cout << "array only with positive numbers(picked from original array) -> ";
	printArray(pos_arr, positive_len);

	int even_len = 0;
	int* even_arr = createArrayWithNumbers(isEven, ORIGINAL_ARRAY, len, even_len);
	cout << "array only with even numbers(picked from original array) -> ";
	printArray(even_arr, even_len);

	cout << "Min element(picked from original array) -> " << minValue(ORIGINAL_ARRAY, len) << endl;
	cout << "Sum [0; 3](picked from original array) -> " << sumInRange(ORIGINAL_ARRAY, ORIGINAL_ARRAY + 3) << endl;

	deleteArray(pos_arr, positive_len);
	deleteArray(even_arr, even_len);
	deleteArray(arr, len);
	deleteArray(ORIGINAL_ARRAY, len);
	printArray(arr, len);

	system("pause");
	return 0;
}