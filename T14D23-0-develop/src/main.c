#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "state_sort.h"

void menu(FILE *fp);

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
  // pseudo menu
  menu(fp);
  // close the file
  free(file_name);
  fclose(fp);
  return 0;
}

void menu(FILE *fp) {
  int menu_num = 0;
  scanf("%d", &menu_num);
  if (menu_num == 0) {
    output(fp);
  } else if (menu_num == 1) {
    bubble_sort(fp);
    output(fp);
  } else if (menu_num == 2) {
    add_tape(fp);
    bubble_sort(fp);
    output(fp);
  }
}
