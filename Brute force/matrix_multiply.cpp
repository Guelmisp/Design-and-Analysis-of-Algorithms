#include<iostream>
using namespace std;

const int N = 4;

void printMatrix(int matrix[][N]) {
  for ( int i = 0; i < N; i++ ) {
    for( int j = 0; j < N; j++ ) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void multiplyMatrix(int firtMatrix[][N], int secondMatrix[][N]){

int result[N][N];

for (int i = 0; i < N; i++){
  for (int j = 0; j < N; j++){
    result[i][j] = 0;
  }
}

for (int i = 0; i < N; i++){
  for (int j = 0; j < N; j++){
    int k = 0;
    while (k < N) {
      result[i][j] = *firtMatrix[i, k] * secondMatrix[k][j]; 
      k++;
    }
  }
}

printMatrix(result); 

}


int main() {

  int mat1[N][N] = { {1, 1, 1, 1},
                     {2, 2, 2, 2},
                     {3, 3, 3, 3},
                     {4, 4, 4, 4}};
 
  int mat2[N][N] = { {1, 1, 1, 1},
                     {2, 2, 2, 2},
                     {3, 3, 3, 3},
                     {4, 4, 4, 4}};

  printMatrix(mat1);

  multiplyMatrix(mat1, mat2);
  return 0;
}

