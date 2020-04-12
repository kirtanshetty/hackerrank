#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>

using namespace std;

class problem{
public:
  int np, k;
  int* p;
  int** matrix;

  int* solving_problem();
  void create_matrix();
  void print_matrix();
  void print_array();
};


int* problem::solving_problem(){
  while(count < np){
    int i = 0;
    while(i < np){
      int sum = -1, index = -1;
      for(int j = i; j < np; j++){
        int diff = abs(p[i] - p[j]);
        if(diff >= k && (sum > diff || sum == -1)){
          index = j;
        }
      }
      if(index != -1){
        if(p[i] != 0){
          p[i] = 0;
          count++;
        }
        p[index] = 0;
        count++;
        i = index;
      }
      else
        break;
    }
  }

  return 0;
}

void problem::create_matrix(){
  matrix = (int**)malloc(sizeof(int*) * np);
  for(int i = 0; i < np; i++){
    matrix[i] = (int*)malloc(sizeof(int) * np);
  }

  for(int i = 0; i < np; i++){
    for(int j = 0; j < np; j++){
      matrix[i][j] = abs(p[i] - p[j]);
    }
  }
}

void problem::print_matrix(){
  for(int i = 0; i < np; i++){
    for(int j = 0; j < np; j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void problem::print_array(){
  for(int i = 0; i < np; i++){
    cout << p[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = 0;

  cin >> n;

  problem* list = (problem*)malloc(sizeof(problem) * n);

  for (int i = 0; i < n; i++){
    cin >> list[i].np >> list[i].k;
    list[i].p = (int*)malloc(sizeof(int) * list[i].np);
    for(int j = 0; j < list[i].np; j++)
      cin >> list[i].p[j];
    // list[i].print_array();
    list[i].create_matrix();
    list[i].print_matrix();
  }

  // list[i].create_matrix();
  // print_matrix();

  return 0;
}