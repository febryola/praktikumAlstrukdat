#include <stdio.h>
#include "stack_linked.h"

/*
NIM                 : 13520140
Nama                : Febryola Kurnia Putri
Tanggal             : 11 November 2021
Topik praktikum     : stack_linked
Deskripsi           : Implementasi file backspace.c
*/

int main() {
  int s1, s2;
  Stack stack1, stack2;
  CreateStack(&stack1);
  CreateStack(&stack2);
  scanf("%d %d", &s1, &s2);
  for (int i = 0; i < s1; i++) {
    int ctr;
    scanf("%d", &ctr);
    if (!ctr && !isEmpty(stack1)) {
      int p;
      pop(&stack1, &p);
    } else if (ctr) {
      push(&stack1, ctr);
    }
  }
  for (int i = 0; i < s2; i++) {
    int ctr;
    scanf("%d", &ctr);
    if (!ctr && !isEmpty(stack2)) {
      int p;
      pop(&stack2, &p);
    } else if (ctr) {
      push(&stack2, ctr);
    }
  }
  boolean isEqual = true;
  while (!isEmpty(stack1) && !isEmpty(stack2) && isEqual) {
    int val1, val2;
    pop(&stack1, &val1);
    pop(&stack2, &val2);
    if (val1 != val2) {
      isEqual = false;
    }
  }
  if (isEqual && isEmpty(stack1) && isEmpty(stack2)) {
    printf("Sama\n");
  } else {
    printf("Tidak sama\n");
  }
  return 0;
}