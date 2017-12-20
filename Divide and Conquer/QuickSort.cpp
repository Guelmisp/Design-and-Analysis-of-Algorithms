//
//  main.cpp
//  QuickSort
//
//  Created by Miguel Pessoa on 12/20/17.
//  Copyright © 2017 Miguel Pessoa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int hoarePartition(vector<int>& arr, int l, int r) {
    
    int p = arr[l];
    int i = l - 1;
    int j = r + 1;
    
    while(true) {
        
        do {
            j--;
        }while(arr[j] > p);
        
        do {
            i++;
        }while(arr[i] < p);
        
        if (i < j)
            swap(arr[i], arr[j]);
        else
            return j;
    }
    
}


void quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int s = hoarePartition(arr, l, r);
        quickSort(arr, l, s);
        quickSort(arr, s+1, r);
    }
}


int main(int argc, const char * argv[]) {
   //Test Case
    vector <int> arr{33, 17, 16, 8, 6, 3};
    
    cout << "Initial \n";
    for (int i = 0; i < arr.size(); i ++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    quickSort(arr, 0, arr.size()-1);
    
    cout << "Sorted \n";
    for (int i  =0; i < arr.size(); i ++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
