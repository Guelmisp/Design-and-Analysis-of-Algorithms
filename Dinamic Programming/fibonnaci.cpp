#include <vector>
#include <iostream>

using namespace std;

int fibonnaci(int n) {
    if (n < 2)
        return n;
    else 
        return fibonnaci(n-1) + fibonnaci(n-2);
}

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
