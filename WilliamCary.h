#ifndef WILLIAM_CARY_H_
#define WILLIAM_CARY_H_
#include <stdio.h>
#include "winTimer.h"
#include <vector>

using namespace std;
vector<double> bubble(vector<double> & vec);
vector<double> insertion(vector<double> & vec);
vector<double> selection(vector<double> &vec);
vector<double> mergesort(vector<double> vec);
void mergesort2(vector<double> & vec);
void merge(vector<double> & left, vector<double> & right, vector<double> & vec);
vector<double> quicksort(vector<double> vec);
vector<double> merge(vector<double> left, vector<double> right);




#endif