#include <stdio.h>
#include <stdlib.h>

#include "clear.h"
#include "io.h"
#include "search.h"
#include "state_sort.h"

int main() {
  FILE *fp = NULL;
  // input the file path
  char *file_name = (char *)malloc(sizeof(char));
  int size = get_size(fp);
  input(&file_name, &size);
  file_name[size + 2] = '\0';
  // open the file
  fp = fopen(file_name, "r+b");

  // check file for emptiness
  if (fp == NULL) {
    printf("n/a");
    exit(-1);
  }
  int num = 0;
  int year_1 = 1000, year_2 = 1000;
  int month_1 = 10, month_2 = 10;
  int day_1 = 10, day_2 = 10;
  int year_step = 0;
  int month_step = 0;
  int day_step = 0;
  char *str_1 = (char *)malloc(sizeof(char));
  char *str_2 = (char *)malloc(sizeof(char));
  search_input(&str_1, &size);
  search_input(&str_2, &size);
  DMY(&year_1, &month_1, &day_1, str_1);
  DMY(&year_2, &month_2, &day_2, str_2);

  for (int i = 0; i < size; i++) {
    fseek(fp, i * sizeof(int), SEEK_SET);
    for (int y = year_1; y <= +year_2; y++) {
      for (int m = month_1; m >= 0; m--) {
        for (int y = year_1; y >= 0; y--) }
    }
  }

  //   for (int i = 0; i < size; i++) {
  //     fseek(fp, i * 8 * sizeof(int), SEEK_SET);
  //     fread(&num, sizeof(int), 1, fp);
  //     if (num == year_1 + year_step) {
  //       fread(&num, sizeof(int), 1, fp);
  //       if (num == month_1 + month_step) {
  //         fread(&num, sizeof(int), 1, fp);
  //         if (num == day_1 + day_step) {

  //         }
  //       }
  //     }
  //   }
}
}
// close the file
free(file_name);
free(str_1);
free(str_2);
fclose(fp);
return 0;
}
