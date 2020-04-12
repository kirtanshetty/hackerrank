#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;
#define MAX_SIZE 30000

bool ransomMessage(map<string, int>& m, string* r, int nr) {
  bool isHashable = true;
  for(int j= 0; j < nr; j++){

    if(m[r[j]] == 0) {
      isHashable = false;
      break;
    }
    else {
      m[r[j]]--;
    }
  }

  return isHashable;
}

int main() {
  map<string, int> mag;
  string ran[MAX_SIZE];
  string ip;
  int nm = 0, nr = 0;

  cin >> nm >> nr;

  for (int i = 0; i < nm; i++)
  {
    cin >> ip;
    mag[ip]++;
  }

  for (int i = 0; i < nr; i++)
  {
    cin >> ran[i];
  }

  if (ransomMessage(mag, ran, nr))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

/*
input: The first line contains two space-separated integers describing the respective values of m(the number of words in the magazine) and n(the number of words in the ransom note).
The second line contains m space-separated strings denoting the words present in the magazine.
The third line contains n space-separated strings denoting the words present in the ransom note.
-----------------
6 4
give me one grand today night
give one grand today



output: Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.
-----------------
Yes

*/
