#include <stdio.h>

#define MAX_SIZE 100000

void PrintArr(long long* arr, long s) {
  for(long i = 0; i < s; i++)
    printf("%lld ", arr[i]);

  printf("\n");
}

void RotateArr(long long* arr, long long* rotArr, long s, long rot) {
  for(long i = 0; i < s; i++) {
    int newPos = i - rot;
    if (newPos < 0) newPos = s + newPos;
    rotArr[newPos] = arr[i];
  }
}

int main() {
  long long arr[MAX_SIZE];
  long long rotArr[MAX_SIZE];
  long size, rotations;

  scanf("%ld %ld", &size, &rotations);

  if (size > MAX_SIZE)
    return -1;
  if (rotations > size)
    return -1;

  for(long i = 0 ; i < size ; i++) {
    scanf("%lld", &arr[i]);
  }

  RotateArr(arr, rotArr, size, rotations);
  PrintArr(rotArr, size);
}


/*
input: The first line contains two space-separated integers denoting the respective values of n(the number of integers) and d(the number of left rotations you must perform).
The second line contains  n - space-separated integers describing the respective elements of the array's initial state.
-----------------
5 4
1 2 3 4 5



output: Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.
-----------------
5 1 2 3 4

*/