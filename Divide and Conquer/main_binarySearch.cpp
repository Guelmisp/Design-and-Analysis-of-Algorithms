//
//  main.cpp
//  Algorithms
//
//  Created by Miguel Pessoa on 12/1/17.
//  Copyright © 2017 Miguel Pessoa. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include  <chrono>
#include "binarySearch.h"

using namespace std;
using namespace std::chrono;

int main(int argc, const char * argv[]) {
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    
    long size;
    int input, key;
    
    cin >> size;
    
    vector <int> array(size);
    for (int arr_i = 0; arr_i < size; arr_i++) {
        cin >> input;
        array[arr_i] = input;
    }
    cin >> key;
    
    t1 = high_resolution_clock::now();
    sort(array.begin(), array.end());
    t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "Sorting Duration: " << duration << endl;
    
    t1 = high_resolution_clock::now();
    long result = binarySearchRecursive(array, 0, size, key);
    t2 = high_resolution_clock::now();
    (result == -1 ) ? cout << "Not found" << endl
                    : cout << "Element is present at index: " << result << endl;
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "Recursive Duration: " << duration << endl;
    
    t1 = high_resolution_clock::now();
    result = binarySearchIterative(array, key);
    t2 = high_resolution_clock::now();
    (result == -1 ) ? cout << "Not found" << endl
                    : cout << "Element is present at index: " << result << endl;
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "Iterative Duration: " << duration << endl;
    
    cout << "Elements smaller or equal to than key: ";
    t1 = high_resolution_clock::now();
    result = binarySearchCount(array, key);
    t2 = high_resolution_clock::now();
    cout << result << endl;
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "Count Duration: " << duration << endl;
    
    return 0;
}
