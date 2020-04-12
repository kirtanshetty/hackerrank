#include <iostream>
#include <string>

using namespace std;

struct Player
{
  int score;
  string name;
};

int main() {
  int n = 0;
  cin >> n;
  struct Player *arr = new Player[n];

  for (int i = 0; i < n; i++){
    cin >> arr[i].name >> arr[i].score;
  }

  for (int i=0; i < (n-1); i++){
    bool swap = false;
    for(int j=0; j < (n-1-i); j++){
      if(arr[j].score < arr[j+1].score) {
        swap = true;
        Player temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
      else if(arr[j].score == arr[j+1].score) {
        if(arr[j].name > arr[j+1].name){
          swap = true;
          Player temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
      }
    }
    if(!swap)
      break;
  }

  for (int i = 0; i < n; i++)
  {
    cout << arr[i].name << " " << arr[i].score << endl;
  }

}