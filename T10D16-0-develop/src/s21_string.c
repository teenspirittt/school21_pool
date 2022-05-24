#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char *string) {
  char *c = string;
  for (; *c; ++c)
    ;
  return c - string;
}

int s21_strcmp(char *string, char *cmp_string) {
  int i = 0;
  while (string[i] == cmp_string[i] && string[i] != '\0' &&
         cmp_string[i] != '\0')
    i++;
  return (string[i] - cmp_string[i]);
}

char s21_strcpy(char *string, char *cpy_string) {
  while ((*string++ = *cpy_string++) != '\0')
    ;
  *string = '\0';
  return *string;
}

void s21_strcat(char *string, char *cat_string) {
  int n = 0;
  int i;
  for (i = s21_strlen(string); cat_string[i - (i - n)] != '\0'; ++i) {
    string[i] = cat_string[i - (i - n)];
    n++;
  }
  string[i] = '\0';
}

char s21_strchr(char *string, int chr) {
  int flag = 0;
  while (*string != '\0')
    if (*string++ == chr) {
      flag = 1;
      break;
    }
  if (flag == 1)
    return *string;
  else
    return 0;
}

char *s21_strstr(char *string, char *str_string) {
  char *ptr = NULL, *ptr2 = NULL;
  int flag = 0;
  if (string == NULL || str_string == NULL) return 0;
  while (*string) {
    if (*string == *str_string) {
      flag = 1;
      ;
      ptr = string;
      ptr2 = str_string;
      while (*string && *str_string) {
        flag = flag && (*string == *str_string);
      }
      if (flag) return string;
    }
    ++string;
  }
  return 0;
}

static void write(char c) { printf("%c", c); }

// void s21_width(char *string, const int width) {
//   int i = 0;
//   int len = 0;
//   char c;
//   int str_len = s21_strlen(string);
//   while (i < str_len) {
//     while ((c != ' ') || (c != '\0')) {
//       c = string[i];
//       len++;
//       i++;
//     }
//     c = '.';
//     if (len <= width) {
//       i = i - len;
//       while (i < len) {
//         write(string[i]);
//         i++;
//       }
//       write('\n');
//       i++;
//       len = 0;
//     } else if (len > width) {
//       i = i - len;
//       while (i < width - 1) {
//         write(string[i]);
//         i++;
//       }
//       write('-');
//       write('\n');
//       len = 0;
//     }
//   }
// }

// char *s21_strtok(char *string, char *tok_string) {}

void s21_width(char *string, const int width) {
  int len = s21_strlen(string);
  int start_position = 0;
  int space_cnt = 0;
  int *space_index = (int *)malloc(sizeof(int));
  int step = 0;
  int start_index = 0;
  char c = 'q';
  int flag = 1;
  for (int i = 0; c != '\0'; ++i) {
    c = string[i];
    if (c == ' ') {
      space_index = (int *)realloc(space_index, (i + 1) * sizeof(int));
      space_index[space_cnt] = i;
      space_cnt++;
    }
  }
  space_index = (int *)realloc(space_index, (space_cnt + 1) * sizeof(int));
  space_index[space_cnt + 1] = len;

  while (step < space_cnt + 1) {
    for (int i = start_index; i < space_index[step]; ++i) {
      write(string[i]);
    }
    write('\n');
    if (flag == 1) {
      start_index = space_index[step] + 1;
      step++;
      flag = 0;
    } else {
      step++;
      start_index = space_index[step] + 1;
    }
  }
}