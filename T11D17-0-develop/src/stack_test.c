#include "stack.h"

#include <stdio.h>

#define SUCCES printf("SUCCES\n")
#define FAIL printf("FAIL\n")
int main() {
  int size = 0;
  stack steck = stack_create();

  printf("Test #1:\nThe size must be 0.");
  size = stack_size(&steck);
  stack_print(&steck);
  printf("\n");
  if (size == 0)
    SUCCES;
  else
    FAIL;
  printf("\n");

  printf("Test #2:\nThe size must be 1.\n");
  push(&steck, 3);
  size = stack_size(&steck);
  stack_print(&steck);
  printf("\n");
  if (size == 1)
    SUCCES;
  else
    FAIL;
  printf("\n");

  printf("Test #3:\nThe size must be 2.\n");
  push(&steck, 5);
  size = stack_size(&steck);
  stack_print(&steck);
  printf("\n");
  if (size == 2)
    SUCCES;
  else
    FAIL;
  printf("\n");

  printf("Test #4:\nThe size must be 3.\n");
  push(&steck, 7);
  size = stack_size(&steck);
  stack_print(&steck);
  printf("\n");
  if (size == 3)
    SUCCES;
  else
    FAIL;
  printf("\n");

  printf("Test #5:\nThe size must be 2.\n");
  pop(&steck);
  size = stack_size(&steck);
  stack_print(&steck);
  printf("\n");
  if (size == 2)
    SUCCES;
  else
    FAIL;
  printf("\n");

  printf("Test #5:\nThe size must be 1.\n");
  pop(&steck);
  stack_print(&steck);
  printf("\n");
  size = stack_size(&steck);
  if (size == 1)
    SUCCES;
  else
    FAIL;
  printf("\n");

  printf("Test #6:\nThe size must be 0.\n");
  pop(&steck);
  size = stack_size(&steck);
  if (size == 0)
    SUCCES;
  else
    FAIL;
  stack_print(&steck);
  stack_clear(&steck);
}
