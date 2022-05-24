#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "search.h"
#include "state_sort.h"

int main() {
  FILE *fp = NULL;
  // input the file path
  char *file_name = (char *)malloc(sizeof(char));
  int size = 0;
  input(&file_name, &size);
  file_name[size + 2] = '\0';
  // open the file
  fp = fopen(file_name, "r+b");

  // check file for emptiness
  if (fp == NULL) {
    printf("n/a");
    exit(-1);
  }
  printf("%d", searcher(fp));

  // close the file
  free(file_name);
  fclose(fp);
  return 0;
}
