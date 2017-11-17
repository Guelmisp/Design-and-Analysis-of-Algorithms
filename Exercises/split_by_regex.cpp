#include <iostream>
#include <string>
#include <regex>

using namespace std;


int main(){
    string s;
    cin >> s;
    
    regex rgx("[A-Z_]");
    vector <string> strings;
    
    regex_token_iterator<string::iterator> it(s.begin(), s.end(), rgx, -1);
    regex_token_iterator<string::iterator> end;
    
    while (it != end) {
        strings.push_back(*it);
        it++;
    }
    
    cout << strings.size();
    
    return 0;   
}

