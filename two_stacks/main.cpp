#include <iostream>
#include <stack>

using namespace std;

class TS_Queue {
private:
  stack<int> in, out;

  void FillInStack();

public:
  void Push(int);
  void Pop();
  int Print();
};

void TS_Queue::FillInStack(){
  while(!in.empty()){
    out.push(in.top());
    in.pop();
  }
}

void TS_Queue::Push(int element) {
  in.push(element);
}

void TS_Queue::Pop() {
  if(out.empty())
    FillInStack();

  out.pop();
}

int TS_Queue::Print(){
  int element;
  if(out.empty())
    FillInStack();
  element = out.top();
  // cout << "pop = " << element << endl;
  return element;
}

int main () {
  TS_Queue* queue = new TS_Queue();
  int n = 0;

  cin >> n;
  int** queries = new int*[n];
  for(int i = 0; i < n; i++)
    queries[i] = new int[2];

  for(int i = 0; i < n; i++){
    cin >> queries[i][0];
    if (queries[i][0] == 1)
      cin >> queries[i][1];
  }

  for (int i = 0; i < n; i++)
  {
    switch(queries[i][0]){
      case 1:
        queue->Push(queries[i][1]);
        break;
      case 2:
        queue->Pop();
        break;
      case 3:
        cout << queue->Print() << endl;
        break;
    }
  }
}

/*
input: The first line contains a single integer, q, denoting the number of queries.
Each line i of the q subsequent lines contains a single query in the form described in the problem statement above.
All three queries start with an integer denoting the query type, but only query 1 is followed by an additional space-separated value, x, denoting the value to be enqueued.
-----------------
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2



output: For each query of type 3, print the value of the element at the front of the queue on a new line.
-----------------
14
14

*/
