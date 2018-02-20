// Functions
#include <algorithm>
std::max('a','z');
std::max_element(max.begin(), max.end());

//vector functions
int positives = count_if(array.begin(), array.end(), [](int n){return n > 0;});
find(v.begin(), v.end(), head->data) == v.end(); //not found

// lower_bound and upper_bound
std::vector<int>::iterator low,up;
int valuetoSearch = 20;
low=std::lower_bound (v.begin(), v.end(), valuetoSearch);

std::map<char,int>::iterator itlow,itup;
itlow=mymap.lower_bound ('b');  // itlow points to b
itup=mymap.upper_bound ('d');

// split string
split( fields, input, is_any_of( " " ) );

//string to int (throws exception)
int value = stoi(s);=

//is space in string
isspace(str[i])

//lowercase
transform(str.begin(), str.end(), str.begin(), ::tolower);

//copy string to char
char caracters[expression.size()+1];
std::strcpy(caracters, expression.c_str());

//Read string from keyboard:
string input_string;
getline(cin, input_string);
result  = is_pangram(input_string);

//input to vector
vector<int> ar(n);
for(int ar_i = 0; ar_i < n; ar_i++){
    cin >> ar[ar_i];
}

//input matrix
vector< vector<int> > a(n,vector<int>(n));
for(int a_i = 0;a_i < n;a_i++){
    for(int a_j = 0;a_j < n;a_j++){
      cin >> a[a_i][a_j];
}
}

//sorting vector
vector<long int>arr ;
for(long int i=0;i<n;i++){
  cin>>p ;
  arr.push_back(p) ;
}
sort(arr.begin(),arr.end()) ; // O(nlogn)

//function for printing the elements in a list
void showlist(list <int> g){
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

//STRUCTURES

//set
Set<Integer> set =new HashSet<Integer>();
set.add(prevNode.data);
set.contains(n.data);

//Hashmap
std::map <char, int> map;
map.insert(make_pair(str[i], i));
map.size();
!map[str[i]];

//Stack
stack <char> mystack;
mystack.push();
mystack.pop();
mystack.top();
mystack.empty();

//Queue
queue <int> q;
q.push(int);
q.size();
q.front();
q.pop();
q.back();

//List
list <int> list1;
list1.front();
list1.back();
list1.pop_front();
list1.pop_back();
list1.reverse();
list1.sort();

//template
template <class T> void printArray (vector<T> a) {
  int size = a.size();
  for(int i = 0; i < size; i++) {
      cout << a[i] << endl;
  }
}meu

//prime
bool primeOrNotPrime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0)
          return false;
  }   
  return true;    
}


