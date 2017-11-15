#include <bits/stdc++.h>
#include <stack>
#include <iostream>

using namespace std;

string super_reduced_string(string s){   
    stack <char> myStack;
    
    char chars[s.size()+1];
    std::strcpy(chars, s.c_str());
  
    myStack.push(chars[0]);
    
    for (int i = 1; i < s.size(); i ++) { 

        if (!myStack.empty() && myStack.top() == chars[i]) {
            myStack.pop();
        } else {
            myStack.push(chars[i]);
        }

    }
    
    if (myStack.empty()) {
        return "Empty String";
    } else {
        string result;
        while (!myStack.empty()) {
            result += myStack.top();
            myStack.pop();
        } 
        std::reverse(result.begin(), result.end());
        return result;
    }        
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}

