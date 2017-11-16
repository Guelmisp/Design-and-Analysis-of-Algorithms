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
#include <locale>
#include <regex>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    
    map <string, string> mymap;
    string key, value;
    
    for (int i = 0; i < n; i++) {
        cin >> key;
        cin >> value;    
        mymap.insert(make_pair(key, value));    
    }
    
    while (cin >> key) {
        if (mymap.find(key) != mymap.end()) {
            cout << key + "=" + mymap[key] << endl;
        } else {
             cout << "Not found" << endl;        
        }    
    }

    return 0;
}

