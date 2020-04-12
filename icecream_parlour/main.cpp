#include <iostream>

using namespace std;

class icp_problem {
private:
  unsigned int n;
  unsigned int m;
  int* c;
public:

  void get_input(){
    cin >> m;
    cin >> n;

    c = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
      cin >> c[i];
  }

  void choose_icecream(){
    int one, two;
    for (int i = 0; i < n - 1; i++) {
      one = i;
      for(int j = i + 1; j < n; j ++){
        if(c[i] + c[j] == m){
          two = j;
          break;
        }
      }
      if(c[one] + c[two] == m)
        break;
    }
    cout << one + 1 << " " << two + 1 << endl;
  }
};

int main(){
  unsigned int t;
  cin >> t;

  icp_problem* icpb = new icp_problem[t];

  for(int i = 0; i < t; i++){
    icpb[i].get_input();
  }

  for(int i = 0; i < t; i++){
    icpb[i].choose_icecream();
  }

  return 0;
}