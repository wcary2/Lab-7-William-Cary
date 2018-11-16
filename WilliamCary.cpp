#include "WilliamCary.h"
#include <iostream>
vector<double> bubble(vector<double> & vec) {
	int sorted = 0;
	if (vec.size() > 1) {
		do {
			sorted = 0;
			for (unsigned i = 0; i < vec.size() - 1; i++) {
				if (vec[i] > vec[i + 1]) {
					double temp = vec[i + 1];
					vec[i + 1] = vec[i];
					vec[i] = temp;
					sorted++;
				}
			}
		} while (sorted > 1 && vec.size() > 2);
	}
	return vec;
}

vector<double> insertion(vector<double> & vec) {
	for (unsigned i = 1; i < vec.size(); i++) {
		double val = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > val) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = val;
	}
	return vec;
}
//change
vector<double> selection(vector<double> & vec) {
	for (unsigned i = 0; i < vec.size() - 1; i++) {
		double smallest = vec[i];
		int swap = i;
		for (unsigned j = i+1; j < vec.size(); j++) {
			if (vec[j] < smallest) {
				smallest = vec[j];
				swap = j;
			}
		}
		vec[swap] = vec[i];
		vec[i] = smallest;
	}
	return vec;
}

vector<double> mergesort(vector<double> vec) {
	if (vec.size() <= 1) {
		return vec;
	}
	else {
		int middle = vec.size() / 2;
		vector<double> left;
		vector<double> right;
		for (unsigned i = 0; i < middle; i++) {
			left.push_back(vec[i]);
		}
		for (unsigned i = middle; i < vec.size(); i++) {
			right.push_back(vec[i]);
		}
		left = mergesort(left);
		right = mergesort(right);

		vec = merge(left, right);
		
		return vec;
	}
}

vector<double> merge(vector<double> left, vector<double> right) {
	vector<double>::iterator leftIt = left.begin();
	vector<double>::iterator rightIt = right.begin();
	vector<double> merged;
	while (leftIt != left.end() && rightIt != right.end()) {
		if (*rightIt < *leftIt) {
			merged.push_back(*rightIt);
			rightIt++;
			continue;
		}
		else {
			merged.push_back(*leftIt);
			leftIt++;
		}
	}
	while (rightIt != right.end()) {
		merged.push_back(*rightIt);
		rightIt++;
	}
	while (leftIt != left.end()) {
		merged.push_back(*leftIt);
		leftIt++;
	}
	return merged;
}

vector<double> quicksort(vector<double> vec) {
	if (vec.size() <= 1) {
		return vec;
	}
	else {
		vector<double> less, greater, equal;
		double pivot = vec[vec.size() - 1];
		vec.pop_back();
		for (unsigned i = 0; i < vec.size(); i++) {
			if (vec[i] == pivot) {
				equal.push_back(vec[i]);
				continue;
			}
			(pivot > vec[i]) ? less.push_back(vec[i]) : greater.push_back(vec[i]);
		}
		less = quicksort(less);
		greater = quicksort(greater);
		vector<double> merged(less);
		merged.push_back(pivot);
		if (equal.size() > 0) {
			for (unsigned i = 0; i < equal.size(); i++) {
				merged.push_back(pivot);
			}
		}
		if (greater.size() > 0) {
			for (unsigned i = 0; i < greater.size(); i++) {
				merged.push_back(greater[i]);
			}
		}

		return merged;
	}
}