
#include "io.h"

#include <stdio.h>
#include <stdlib.h>

#include "state_sort.h"

int input(char **str, int *size) {
  char c;
  *str = (char *)realloc(*str, 3 * sizeof(char));
  (*str)[0] = '.';
  (*str)[1] = '.';
  (*str)[2] = '/';
  for (int i = 3; c != '\n'; ++i) {
    *str = (char *)realloc(*str, (i + 1) * sizeof(char));
    scanf("%c", &c);
    (*str)[i] = c;
    (*size)++;
  }

  return ERROR;
}

void output(FILE *f) {
  int num;
  fseek(f, 0, SEEK_SET);
  int flag = 0;
  while (!feof(f)) {
    for (int i = 0; i < 8; ++i) {
      if (fread(&num, sizeof(int), 1, f) == 1) {
        printf("%d ", num);
      } else {
        flag = 1;
      }
    }
    if (flag == 0) {
      printf("\n");
    }
  }
}

void add_tape(FILE *fp) {
  int num;
  fseek(fp, 0, SEEK_END);
  for (int i = 0; i < 8; ++i) {
    scanf("%d", &num);
    fwrite(&num, sizeof(int), 1, fp);
  }
  fseek(fp, 0, SEEK_SET);
}

void search_input(char **str, int *size) {
  char c;

  for (int i = 0; c != '\n'; ++i) {
    *str = (char *)realloc(*str, (i + 1) * sizeof(char));
    scanf("%c", &c);
    (*str)[i] = c;
    (*size)++;
  }
}
