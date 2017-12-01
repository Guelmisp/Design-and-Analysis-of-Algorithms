//  Divide and Conquer
//  binarySearch.cpp
//  Algorithms
//
//  Created by Miguel Pessoa on 12/1/17.
//  Copyright © 2017 Miguel Pessoa. All rights reserved.
//
#include "binarySearch.h"

//Counts the number of elements smaller or equal a value in sorted array
//Complexity - O(N);
long binarySearchCount(vector <int> array,  int key) {
    long n = array.size();
    long left = 0, right = n;
    long middle = 0;
    
    while (left < right) {
    
        middle = left + (right-left)/2;
        
        if (array[middle] == key) {
            while((array[middle+1] == key) && (middle+1 < n))
                middle++;
            break;
        } else if (array[middle] > key)
            right = middle;
        else
            left = middle+1;
    }
    
    while (array[middle] > key)
        middle--;
    
    return middle+1;
}


//Complexity O(Logn)
long binarySearchRecursive(vector <int> array, long left, long right, int key) {
    
    if (right >= left) {
        long middle = left + (right-left)/2;
        
        if (array[middle] == key)
            return middle;
        
        if (array[middle] > key)
            return binarySearchRecursive(array, middle+1, right, key);
        else
            return binarySearchRecursive(array, left, middle+1, key);
    }
    
    return -1;
}

long binarySearchIterative(vector <int> array, int key) {
    
    long n = array.size();
    long left = 0, right = n;
    long middle = 0;
    
    while (left < right) {
        
        middle = left + (right-left)/2;
        
        if (array[middle] == key) {
            return middle;
        } else if (array[middle] > key)
            right = middle - 1;
        else
            left = middle + 1;
    }
    
    return -1;
}

