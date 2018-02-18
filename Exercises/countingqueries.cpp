//
//  main.cpp
//  Training
//
//  Created by Miguel Pessoa on 2/16/18.
//  Copyright © 2018 Miguel Pessoa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


// function to find the minimum element's index
int findMinIndex(vector <int> arr, int low, int high){
    
    if (high < low)  return 0;
    
    if (high == low) return low;
    
    int mid = (low + high) / 2;
    
    if (mid < high && arr[mid+1] < arr[mid])
        return (mid + 1);
    
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;
    
    if (arr[high] > arr[mid])
        return findMinIndex(arr, low, mid-1);
    return findMinIndex(arr, mid+1, high);
}

int binary_search(vector <int> arr, int l, int h, int x)
{
    while (l <= h)
    {
        int mid = (l+h) / 2;
        
        if (arr[mid] < x)
            l = mid + 1;
        else
            h = mid - 1;
    }
    
    return h;
}

int countEleLessThanOrEqual(vector <int> arr, int n, int x)
{
    int min_index = findMinIndex(arr, 0, n-1);
    
    if (x <= arr[n-1])
        return (binary_search(arr, min_index, n-1, x) + 1 - min_index);
    
    if ((min_index - 1) >= 0 && x <= arr[min_index - 1])
        return (n - min_index + binary_search(arr, 0, min_index-1, x) + 1);
    
    return n;
}

long binarySearchCount(vector <int> array,  int key) {
    long n = array.size();
    long left = 0, right = n-1;
    long middle = 0;
    
    while (left <= right) {
        
        middle = left + (right-left)/2;
        
        if (array[middle] == key) {
            while((array[middle+1] > key) && (middle+1 < n))
                middle++;
            break;
        }
        else if (array[middle] > key)
            right = middle -1;
        else
            left = middle+1;
        
    }
    
    while (array[middle] > key)
        middle--;
    
    return middle+1;
}

void printArray(vector<int> arr){
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    high_resolution_clock::time_point t3;
    high_resolution_clock::time_point t4;
    
    int input;
    int numberofQueries, numberofElements;
    cin >> numberofQueries >> numberofElements;
    
    vector<int> queries (numberofQueries);
    vector<int> elements (numberofElements);
    
    for(int i = 0 ; i < numberofQueries; i++){
        cin >> queries[i];
    }
    
    for(int i = 0 ; i < numberofElements; i++){
        cin >> elements[i];
    }
    
    sort(elements.begin(),elements.end()); //O(nlogn)
    
    t1 = high_resolution_clock::now();
    for (int i = 0; i < numberofQueries; i++) {
        cout << binarySearchCount(elements, queries[i]) <<  " ";
    }
    t2 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count();
    
    cout << duration1 << endl;
    
    t3 = high_resolution_clock::now();
    for (int i = 0; i < numberofQueries; i++) {
        cout << countEleLessThanOrEqual(elements, elements.size(), queries[i]) << " ";
    }
    t4 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();
    cout << duration2 << endl;
    
    //printArray(queries);
    //printArray(elements);
}
