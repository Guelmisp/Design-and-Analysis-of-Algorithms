//
//  main.cpp
//  Testes
//
//  Created by Miguel Pessoa on 2/2/18.
//  Copyright © 2018 Miguel Pessoa. All rights reserved.
//
#include <vector>
#include <iostream>

using namespace std;

int bottomUpFibonacci(int n) {
    vector <int> arr;
    arr.push_back(1);
    arr.push_back(1);
    
    for (int i = 2; i <= n; i ++){
        arr.push_back(arr[i-1] + arr[i-2]);
        cout << arr[i];
        cout << endl;
    }
    
    return arr[n];
}

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    cout << "Result: " ;
    cout << bottomUpFibonacci(n);
    cout << endl;
    
    return 0;
}
