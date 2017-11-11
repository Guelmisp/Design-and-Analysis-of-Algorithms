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

bool is_pangram(string str){
    if (str.size() == 0)
      return false;
    
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    std::map<char, int> map;

    for (int i = 0; i < str.size(); i++){ 
      if (isspace(str[i]))
        continue;
      else {
          if (!map[str[i]]){
              map.insert(make_pair(str[i], i));   
           }
       }
    }
    
    if (map.size() == 26)  
        return true;  
    else
        return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    bool result;
    string input_string;
    
    getline(cin, input_string);
    result  = is_pangram(input_string);
    
    if (result)
        cout << "pangram";
    else
        cout << "not pangram";
    
    return 0;
}
