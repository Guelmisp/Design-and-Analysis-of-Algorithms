#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    stack <char> mystack;
    
    if ( expression.size() % 2 != 0) {
        return false;
    } else {       
        char caracters[expression.size()+1];
        std::strcpy(caracters, expression.c_str());
  
        for (int i = 0; i< expression.size(); i++) {
          switch (caracters[i]) {
             case '{': mystack.push('}'); break;
             case '(': mystack.push(')'); break;
             case '[': mystack.push(']'); break;
             default :
               if (mystack.empty() || caraacters[i] != mystack.top())
                 return false;
               mystack.pop();
          }
       }
    }          
    return mystack.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}



