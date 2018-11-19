#ifndef WILLIAM_CARY_H_
#define WILLIAM_CARY_H_
#include <stdio.h>
#include "winTimer.h"
#include <vector>

using namespace std;
vector<double> bubble(vector<double> & vec);
vector<double> insertion(vector<double> & vec);
vector<double> selection(vector<double> &vec);
void mergesort(vector<double> & vec);

void merge(vector<double> & left, vector<double> & right, vector<double> & vec);
void quicksort(vector<double> vec);
vector<double> merge(vector<double> left, vector<double> right);




#endif