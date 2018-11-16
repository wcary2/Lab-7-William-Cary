// SortedDriver.cpp

// tom bailey   1445  25 mar 2014
// Construct sorted sequences and call functions that
//   process the sorted sequences.


#include "RandomUtilities.h"
#include "ContainerPrinting.h"
#include "winTimer.h"//CHANGE: this to unixTimer.h if on mac/linux
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include "WilliamCary.h"

using namespace std;

// post: a sorted vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	//sort(begin(theList), end(theList));

	return theList;
}


// post: a sorted list of numWords words of length
//         wordLength with characters chosen randomly from
//         alphabet has been returned.
list<string> getWords(size_t numWords, size_t wordLength, string alphabet)
{
	list<string> theWords;
	for (size_t i = 0; i < numWords; ++i)
	{
		string word;
		for (size_t j = 0; j < wordLength; ++j)
		{
			word += alphabet.at(randInt(0, alphabet.size()));
		}
		theWords.push_back(word);
	}

	theWords.sort();

	return theWords;
}


// pre:  number is not empty;
//       number is sorted from smallest to largest
// post: The most isolated entry in number has been returned
double mostIsolated(vector<double> & number)
{
	double diff = 0;
	double candidate = 0;
	double currentHigh = -1;
	double prev = 0;
	double next = 0;
	for (unsigned i = 1; i < number.size() - 1; i++) {
		prev = next;
		next = number[i + 1] - number[i];
		if (((next > prev) ? prev : next) > currentHigh) {
			currentHigh = (next > prev) ? prev : next;
			candidate = number[i];
		}
		if (i == number.size() - 1 && next < currentHigh) {
			candidate = number[i + 1];
		}
	}
	return candidate;
}


// pre:  A and B are sorted.
// post: The number of strings in A that do not occur in B
//         has been returned.
int unmatched(list<string> & A, list<string> & B)
{
	int sum = 0;
	string prev = "";

	list<string>::iterator iterA = A.begin();
	list<string>::iterator iterB = B.begin();

	while (iterA != A.end() && iterB != B.end()) {
		string aString = *iterA;
		string bString = *iterB;
		if (aString == bString) {
			string prevA = aString;
			string prevB = bString;
			while (prevA == aString && iterA != A.end()) {
				aString = *iterA++;
			}
			while (prevB == bString && iterB != B.end()) {
				bString = *iterB++;
			}
		}
		if (aString < bString) {
			string prevA = aString;
			string prevB = bString;
			int tempCount = 0;
			while (prevA == aString && iterA != A.end()) {
				aString = *iterA++;
				tempCount++;
			}
			while (prevB == bString && iterB != B.end()) {
				bString = *iterB++;
			}
			sum += tempCount;
		}

		if (aString > bString && iterB != B.end()) {
			string prevA = aString;
			string prevB = bString;
			bool foundSame = false;
			int tempCount = 0;
			while (prevA == aString && iterA != A.end()) {
				aString = *iterA++;
				tempCount++;
			}
			while (aString > bString && iterB != B.end()) {
				bString = *iterB++;
				if (bString == prevA) {
					break;
				}
				if (aString < bString) {
					sum += tempCount;
				}
			}
		}
	}
	if (iterB == B.end() && iterA != A.end()) {
		sum++;
		while (iterA != A.end()) {
			iterA++;
			sum++;
		}
	}
	return sum;
}


int main()
{
	int sortTest = 0;
	cout << "Find the most isolated number" << endl
		<< "-----------------------------" << endl << endl;
	while (sortTest < 5)
	{
		string currentTest = "";
		switch (sortTest) {
		case 0:
			cout << "---------- Bubble Sort ----------" << endl << endl;
			currentTest = "Bubble Sort";
			break;
		case 1:
			cout << "----------  Insertion  ----------" << endl << endl;
			currentTest = "Insertion Sort";
			break;
		case 2:
			cout << "----------  Selection  ----------" << endl << endl;
			currentTest = "Selection Sort";
			break;
		case 3:
			cout << "----------  Merge Sort ----------" << endl << endl;
			currentTest = "Merge Sort";
			break;
		case 4:
			cout << "----------  Quick Sort ----------" << endl << endl;
			currentTest = "Quick Sort";
			break;
		}
		cout << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0) {
			sortTest++;
			continue;
		}
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a sorted list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, -n, n);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (n < 25)
			cout << numbers << endl << endl;

		// Report a most isolated isolated number
		Timer time;
		time.start();
		switch (sortTest) {
		case 0:
			bubble(numbers);
			break;
		case 1:
			insertion(numbers);
			break;
		case 2:
			selection(numbers);
			break;
		case 3:
			numbers = mergesort(numbers);
			break;
		case 4:
			numbers = quicksort(numbers);
			break;
		}
		time.stop();
		cout << "Sorted version: " << endl;
		if (n < 25)
			cout << numbers << endl << endl; 
		cout << currentTest << " sorted the list in: "
			<< time() << " seconds"
			<< endl << endl;
	}


	/*cout << endl << endl;
	cout << "Count the unmatched words" << endl
		<< "-------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size for words lists: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter word length: ";
		int wordSize;
		cin >> wordSize;
		cout << "Enter alphabet: ";
		string alphabet;
		cin >> alphabet;

		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct two sorted vectors of words
		Timer get;
		get.start();
		list<string> A = getWords(n, wordSize, alphabet);
		list<string> B = getWords(n, wordSize, alphabet);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (wordSize * n < 60)
		{
			cout << "A is: " << A << endl
				<< "B is: " << B << endl;
		}

		// Report the number of words in the first sorted list
		//   that are not in the second sorted list
		Timer time;
		time.start();
		int count = unmatched(A, B);
		time.stop();
		cout << count
			<< " words in A were not in B" << endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}*/

	return 0;
}
