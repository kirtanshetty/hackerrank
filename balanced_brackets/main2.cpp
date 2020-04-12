#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
#define MAX_SIZE 1000

void PushChar(char* s, int i, char c){
  s[i] = c;
}

char PopChar(char* s, int i){
  char c = s[i];
  s[i] = '\0';
  return c;
}

bool CompleteSeq(char* s){
  // for(int i = 0; i < n; i++) {
    bool flag = true;
    char *temp = (char*)malloc(MAX_SIZE * sizeof(char));
    int index = -1;
    // cout << s[i] << ".length = " << strlen(s[i]) << endl;
    for(int j = 0; j < strlen(s); j++){
      // cout << "i = " << i << ", j = " << j << endl;
      switch(s[j]){
        case '}':
          // cout << "1" << endl;
          if(index < 0) {
            flag = false;
          }
          else {
            char c1 = PopChar(temp, index);
            index--;
            if(c1 != '{')
              flag = false;
          }
          break;

        case ']':
        // cout << "2" << endl;
          if(index < 0) {
            flag = false;
          }
          else {
            char c2 = PopChar(temp, index);
            index--;
            if(c2 != '[')
              flag = false;
          }
          break;

        case ')':
        // cout << "3" << endl;
          if(index < 0) {
            flag = false;
          }
          else {
            char c3 = PopChar(temp, index);
            index--;
            if(c3 != '(')
              flag = false;
          }
          break;

        default:
        // cout << "4" << endl;
          index++;
          PushChar(temp, index, s[j]);
          // break;
      }
      // cout << "temp = " << temp << endl;

      if(!flag)
        break;
    }
    if(!flag || index != -1){
      // cout << "NO" << endl;
      return false;
    }
    else{
      // cout << "YES" << endl;
      return true;
    }
    // free(temp);
  // }
}

int main() {
  // char* seq;
  bool* result;
  int n = 0;

  cin >> n;

  char** seq;
  seq = (char**)malloc(n * sizeof(char));
  // result = (bool*)malloc(MAX_SIZE * sizeof(bool));

  for (int i = 0; i < n; i++) {
    seq[i] = (char*)malloc(MAX_SIZE * sizeof(char));
    cin >> seq[i];

    cout << " -> " << seq[i] << endl;
    // result[i] = CompleteSeq(seq);
    // free(seq);
     // cin.get(seq, MAX_SIZE);
  }


  for (int i = 0; i < n; i++)
  {
    cout <<  i << " = " << seq[i] << endl;
  }
  // free(seq);
  // for (int i = 0; i < n; i++) {
  //   if (result[i] == 0)
  //     cout << "NO" << endl;
  //   else
  //     cout << "YES" << endl;
  //    // cin.get(seq, MAX_SIZE);
  // }
  // CompleteSeq(seq, n);

  // int i = 0;
  // while(seq[0][i] != '\0')
  //   cout << "- " << seq[0][i++] << endl;

  // if (CompleteSeq(seq, n))
  //   cout << "YES" << endl;
  // else
  //   cout << "NO" << endl;

  return 0;
}

/*
input: The first line contains a single integer, n , denoting the number of strings.
Each line i of the n  subsequent lines consists of a single string, s , denoting a sequence of brackets.
-----------------
3
{[()]}
{[(])}
{{[[(())]]}}



output: For each string, print whether YES or NO no
-----------------
YES
NO
YES

*/
