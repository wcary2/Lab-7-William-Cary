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


void mergesort(vector<double> & vec) {
	if (vec.size() <= 1) {
		return;
	}
	else {
		int middle = vec.size() / 2;
		vector<double> left(vec.begin(), vec.begin() + middle);
		vector<double> right(vec.begin() + middle, vec.end());
		mergesort(left);
		mergesort(right);

		merge(left, right, vec);

		return;
	}
}

void merge(vector<double> & left, vector<double> & right, vector<double> & vec) {
	int l = 0, r = 0, m = 0;
	int leftsize = left.size(), rightsize = right.size();
	while (l < leftsize && r < rightsize) {
		vec[m++] = (left[l] < right[r]) ? left[l++] : right[r++];
	}
	while (l < leftsize)
		vec[m++] = left[l++];
	while (r < rightsize)
		vec[m++] = right[r++];
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

void quicksort(vector<double> vec) {
	if (vec.size() <= 1) {
		return;
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
		quicksort(less);
		quicksort(greater);
		int vecPos = 0;
		if (less.size() > 0) {
			for (unsigned i = 0; i < less.size(); i++) {
				vec[vecPos] = less[i];
				vecPos++;
			}
		}
		if (equal.size() > 0) {
			for (unsigned i = 0; i < equal.size(); i++) {
				vec[vecPos] = equal[i];
				vecPos++;
			}
		}
		if (greater.size() > 0) {
			for (unsigned i = 0; i < greater.size(); i++) {
				vec[vecPos] = greater[i];
				vecPos++;
			}
		}
		return;
	}
}