#include "search.h"

#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "state_sort.h"

int searcher(FILE *fp) {
  fseek(fp, 0, SEEK_SET);
  int year = 1000;
  int month = 10;
  int day = 10;
  int num;
  int res = 0;
  int size = get_size(fp) / 8;
  char *str = (char *)malloc(sizeof(char));
  search_input(&str, &size);
  str[size - 1] = '\0';
  DMY(&year, &month, &day, str);
  for (int i = 0; i < size; i++) {
    fseek(fp, i * 8 * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, fp);
    if (num == year) {
      fread(&num, sizeof(int), 1, fp);
      if (num == month) {
        fread(&num, sizeof(int), 1, fp);
        if (num == day) {
          for (int i = 0; i < 5; ++i) {
            fread(&num, sizeof(int), 1, fp);
            res = num;
          }
        }
      }
    }
  }
  free(str);
  fclose(fp);
  return res;
}

void DMY(int *year, int *month, int *day, char *str) {
  //  year forming
  *year = *year * (str[6] - '0');
  *year = *year + ((str[7] - '0') * 100);
  *year = *year + ((str[8] - '0') * 10);
  *year = *year + (str[9] - '0');
  //  month forming
  *month = *month * (str[3] - '0');
  *month = *month + (str[4] - '0');
  //  day forming
  *day = *day * (str[0] - '0');
  *day = *day + (str[1] - '0');
}
