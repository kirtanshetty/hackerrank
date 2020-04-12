#include <iostream>

using namespace std;

int RowSum(int** mat, int r, int n, int start, int end){
  int sum = 0;
  for(int i = start; i <= end; i++){
    sum += mat[r][i];
  }
  return sum;
}

int ColSum(int** mat, int c, int n, int start, int end){
  int sum = 0;
  for(int i = start; i <= end; i++){
    sum += mat[i][c];
  }
  return sum;
}

void PrintMat(int*** mat, int n, int *s){
  cout << "Mat is : " << endl;
  for(int i = 0; i < n; i++){
    cout << "\nmat[" << i << "] :" << endl;
    for(int j = 0; j < s[i]*2; j++){
      for(int k = 0; k < s[i]*2; k++){
        cout << mat[i][j][k] << " ";
      }
      cout << endl;
    }
  }
}

int FlipMat(int** mat, int s){
  int sum = 0;

for (int i = 0; i < s/2; i++){
  for(int j = 0; j < s/2; j++){
    int max = 0;

    if(mat[i][j] > max)
      max = mat[i][j];
    if(mat[i][s - 1 - j] > max)
      max = mat[i][s - 1 - j];
    if(mat[s - 1 - i][j] > max)
      max = mat[s - 1 - i][j];
    if(mat[s - 1 - i][s - 1 - j] > max)
      max = mat[s - 1 - i][s - 1 - j];

    mat[i][j] = max;
  }
}

  return sum;
}

int GetSum(int** mat, int s){
  int sum = 0;
  for(int i = 0;i < s/2; i++){
    sum += RowSum(mat, i, s, 0, s/2 - 1);
  }
  return sum;
}

int main(){
  int n = 0, s = 0;
  cin >> n;

  int ***mat;

  mat = (int***)malloc(n * sizeof(int***));
  int* size = new int[n];

  for(int i = 0; i < n; i++){
    cin >> size[i];
    mat[i] = (int**)malloc(size[i] * sizeof(int**) * 2);
    for(int j = 0; j < size[i] * 2; j++){
      mat[i][j] = (int*)malloc(size[i] * sizeof(int*) * 2);
      for(int k = 0; k < size[i] * 2; k++){
        cin >> mat[i][j][k];
      }
    }
  }

  for(int i = 0; i < n; i++) {
    FlipMat(mat[i], size[i]*2);
    cout << GetSum(mat[i], size[i]*2) << endl;
  }

  PrintMat(mat, n, size);

  return 0;
}
