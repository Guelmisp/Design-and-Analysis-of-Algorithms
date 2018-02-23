#include <iostream>

using namespace std;

void insertion_sort(vector <int> &arr) {

  for (int i = 0; i < arr.size(); i++){
    
    int escolhido = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > escolhido) {
      arr[j + 1] = vetor [j];
      j--;
    }

    arr[j + 1] = escolhido;

  }
  
}

int main(){

  return 0;
}
