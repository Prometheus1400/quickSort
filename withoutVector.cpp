#include <iostream>
#include <stdlib.h>
#include <ctime>
using std::cout, std::endl;

double fRand(int maxRanVal = 100, int numFloatPt = 2);
void quickSort(double list[], const int size);

int main() {
	srand(time(0));
	int SIZE = 1000000;
	double *list = new double[SIZE];

	for (int i = 0; i < SIZE; ++i) {
		list[i] = fRand();
	}

	//Randomized array created
	//Beginning quick sort
	clock_t begin = clock();
	quickSort(list,SIZE);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken: " << time_spent << endl;
	



	return 0;
}

void quickSort(double list[], const int size) {
	if (size == 1 || size == 0) {
		return;
	}
	double pivot = list[size-1];
	int sCount = 0;
	int lCount = 0;
	for (int i = 0; i < size-1; ++i) {
		if (list[i] <= pivot) {
			++sCount;
		}
	}
	lCount = (size - 1) - sCount;
	double *smaller = new double[sCount];
	double *larger = new double[lCount];

	int sIndex = 0;
	int lIndex = 0;
	for (int i = 0; i < size-1; ++i) {
		if (list[i] <= pivot) {
			smaller[sIndex] = list[i];
			++sIndex;
		} else {
			larger[lIndex] = list[i];
			++lIndex;
		}
	}

	quickSort(smaller, sCount);
	quickSort(larger, lCount);


	int totalIndex = 0;
	for (int i = 0; i < sCount; i++) {
		list[totalIndex] = smaller[i];
		++totalIndex;
	}
	list[totalIndex] = pivot;
	++totalIndex;
	for (int i = 0; i < lCount; i++) {
		list[totalIndex] = larger[i];
		++totalIndex;
	}
	delete[] smaller;
	delete[] larger;

	return;
}


double fRand(int maxRanVal, int numFloatPt) {
	double remFactor = 1;
	for (int i = 0; i < numFloatPt; ++i) {
		remFactor *= 10;
	}
	double remainder = (rand() % (int)remFactor) / remFactor;
	double num = rand() % maxRanVal;

	return (num + remainder);
}