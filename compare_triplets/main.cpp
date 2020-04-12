#include <stdio.h>

class Problem{
public:
  int clarity;
  int originality;
  int difficulty;
};

int main(){
  Problem* a = new Problem();
  Problem* b = new Problem();
  int a_points = 0, b_points = 0;

  scanf("%d %d %d", &a->clarity, &a->originality, &a->difficulty);
  scanf("%d %d %d", &b->clarity, &b->originality, &b->difficulty);

  if(a->clarity > b->clarity) a_points++;
  else if(b->clarity > a->clarity) b_points++;

  if(a->originality > b->originality) a_points++;
  else if(b->originality > a->originality) b_points++;

  if(a->difficulty > b->difficulty) a_points++;
  else if(b->difficulty > a->difficulty) b_points++;

  printf("%d %d\n", a_points, b_points);

  return 0;
}