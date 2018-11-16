#include "WilliamCary.h"

vector<double> bubble(vector<double> & vec) {
	unsigned sorted = 0;
	if (vec.size > 1) {
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
	for (unsigned i = 1; i < vec.size() - 1; i++) {
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
		auto temp = vec[i];
		for (unsigned j = 1; j < vec.size(); j++) {
			if (temp < vec[j])
				temp = vec[j];
		}
		vec[i + 1] = vec[i];
		vec[i] = temp;
	}
	return vec;
}

vector<double> mergesort(vector<double> vec) {
	if (vec.size() == 1) {
		return vec;
	}
	else {
		int middle = vec.size() / 2;
		vector<double> left;
		vector<double> right;

		for(unsigned i = 0; i < middle; i++) {
			left.push_back(vec[i]);
		}
		for (unsigned i = middle; i < vec.size(); i++) {
			right.push_back(vec[i]);
		}
		if (left.back() < right.front()) {
			return vec;
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
		}
		else {
			merged.push_back(*leftIt);
			leftIt++;
		}
	}
	while (leftIt == left.end() && rightIt != right.end()) {
		merged.push_back(*rightIt);
		rightIt++;
	}
	while (rightIt == right.end() && leftIt != left.end()) {
		merged.push_back(*leftIt);
		leftIt++;
	}
	return merged;
}

vector<double> quicksort(vector<double> vec) {
	if (vec.size() == 1) {
		return vec;
	}
	else {
		vector<double> less, greater, equal;
		double pivot = vec.back();
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
		for (unsigned i = 0; i < equal.size(); i++) {
			merged.push_back(pivot);
		}
		for (unsigned i = 0; i < greater.size(); i++) {
			merged.push_back(greater[i]);
		}
		return merged;
	}
}