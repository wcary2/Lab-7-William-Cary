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

	return theList;
}

int main()
{
	int sortTest = 0;
	cout << "Testing various sort algorithm efficiencies" << endl
		<< "--------------------------------------------------" << endl << endl;
	while (sortTest < 6)
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
		case 5:
			cout << "----------  STL::Sort  ----------" << endl << endl;
			currentTest = "STL::sort";
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

		// Report a sorting time
		Timer time;
		
		switch (sortTest) {
		case 0:
			time.start();
			bubble(numbers);
			time.stop();
			break;
		case 1:
			time.start();
			insertion(numbers);
			time.stop();
			break;
		case 2:
			time.start();
			selection(numbers);
			time.stop();
			break;
		case 3:
			time.start();
			mergesort(numbers);
			time.stop();
			break;
		case 4:
			time.start();
			quicksort(numbers);
			time.stop();
			break;
		case 5:
			time.start();
			sort(begin(numbers), end(numbers));
			time.stop();
			break;
		}
		cout << "Sorted version: " << endl;
		if (n < 25)
			cout << numbers << endl << endl; 
		cout << currentTest << " sorted the list in: "
			<< time() << " seconds"
			<< endl << endl;
	}
	return 0;
}
