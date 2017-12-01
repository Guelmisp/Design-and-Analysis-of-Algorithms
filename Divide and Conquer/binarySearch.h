//
//  binarySearch.h
//  Algorithms
//
//  Created by Miguel Pessoa on 12/1/17.
//  Copyright © 2017 Miguel Pessoa. All rights reserved.
//

#ifndef binarySearch_h
#define binarySearch_h

#include <stdio.h>
#include <vector>

using namespace std;
long binarySearchCount(vector <int> array, int key);
long binarySearchIterative(vector <int> array, int key);
long binarySearchRecursive(vector <int> array, long left, long right, int key);

#endif /* binarySearch_h */
