#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


vector <int> knapsackProblem (vector <int> itens, vector <int> weights, int numberOfItens, int maxWeight) {

  vector <int> solution(numberOfItens+1, 0);
  int bestValue = 0;

  for (int i = 0; i < pow(2, numberOfItens); i++) {

    int j = numberOfItens;
    int tempWeight = 0;
    int tempValue = 0;

    while (solution[j] != 0 && j > 0) {
      solution[j] = 0;
      j = j - 1;
    }

    solution[j] = 1;

    for (int k = 0; k < numberOfItens; k++) {
      if (solution[k] = 1) {
        tempWeight += weights[k];
        tempValue += itens[k];
      }
    }

    if ((tempValue > bestValue) && (tempWeight <= maxWeight)){
      bestValue = tempValue;
    }
  }

  return solution;

}


int main() {
  int numberOfItens;
  int maxWeight;

  vector <int> itens(numberOfItens);
  vector <int> weights(numberOfItens);

  cin >> numberOfItens;
  for(int i = 0; i < n; i++){
       cin >> itens[i] >> weights[i];
  }

  vector <int> solution = knapsackProblem(itens, weights, numberOfItens, maxWeight);

  return 0;
}