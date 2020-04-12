#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

bool IsCharPresent(char c, char* d, int s) {
  for(int i = 0; i < s; i++)
    if(d[i] == c)
      return true;

  return false;
}

int AnagramDeletions (char* s1, char* s2, int l1, int l2, char* d, int del) {
  int deletions = del;

  for(int i = 0; i < l1; i++) {
    bool isPresent = false;
    int j = 0;

    if(s1[i] == 0)
      continue;
    if(IsCharPresent(s1[i], d, deletions)){
      deletions++;
      continue;
    }

    for(j = 0; j < l2; j++) {
      if(s2[j] != 0)
        if (s1[i] == s2[j]){
          isPresent = true;
          break;
        }
    }

    if (!isPresent)
        d[++deletions] = s1[i];
    s1[i] = 0;
    s2[j] = 0;
  }

  return deletions;
}

int main() {
  char* str1;
  char* str2;
  char* deleted;
  char* tested;
  int len1 = 0, len2 = 0, del = 0, test = 0;

  str1 = (char*)(malloc(MAX_SIZE));
  str2 = (char*)(malloc(MAX_SIZE));
  deleted = (char*)(malloc(26));
  tested = (char*)(malloc(26));

  fgets (str1, MAX_SIZE, stdin);
  fgets (str2, MAX_SIZE, stdin);

  str1[strcspn(str1, "\n")] = 0;
  str2[strcspn(str2, "\n")] = 0;

  len1 = strlen(str1);
  len2 = strlen(str2);

  del = AnagramDeletions (str1, str2, len1, len2, deleted, del);
  del = AnagramDeletions (str2, str1, len2, len1, deleted, del);
  printf("%d\n", del);
}

/*
input: The first line contains a single string, a.
The second line contains a single string, b.
-----------------
cde
abc



output: Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.
-----------------
4

