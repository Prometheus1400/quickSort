#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
using std::cout, std::cin, std::endl, std::vector;

double fRand(int maxRanVal = 100, int numFloatPt = 2);
void quickSort(vector<double> &list);

int main() {
	srand(time(0));
	const int size = 1000000;
	vector<double> list(size,0);

	for (int i = 0; i < size; ++i) {
		list[i] = fRand();
	}

	//Randomized array created
	//Beginning quick sort
	clock_t begin = clock();
	quickSort(list);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	// for (int i = 0; i < list.size(); ++i) {
	// 	cout << list[i] << endl;
	// }
	
	cout << "Time taken: " << time_spent << endl;

	



	return 0;
}

void quickSort(vector<double> &list) {
	if (list.size() == 1 || list.size() == 0) {
		return;
	}
	double pivot = list.back();
	vector<double> smaller;
	vector<double> larger;

	for (unsigned int i = 0; i < list.size() - 1; ++i) {
		if (list[i] <= pivot) {
			smaller.push_back(list[i]);
		} else {
			larger.push_back(list[i]);
		}
	}

	quickSort(smaller);
	quickSort(larger);

	// recombining the vectors
	int count = 0;
	for (unsigned int i = 0; i < smaller.size(); ++i) {
		list[count] = smaller[i];
		++count;
	}
	list[count] = pivot;
	++count;
	for (unsigned int i = 0; i < larger.size(); ++i) {
		list[count] = larger[i];
		++count;
	}

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