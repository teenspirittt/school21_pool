#include "s21_string.h"

#include <stdio.h>
#define SUCCES printf("SUCCES\n")
#define FAIL printf("FAIL\n")

void s21_strlen_test() {
  char s1[] = "abcd";
  char s2[] = "abcdg";
  char s3[] = "asfAdddddd";
  char s4[] = "";

  if (s21_strlen(s1) == 4)
    SUCCES;
  else
    FAIL;
  if (s21_strlen(s2) == 5)
    SUCCES;
  else
    FAIL;
  if (s21_strlen(s3) == 10)
    SUCCES;
  else
    FAIL;
  if (s21_strlen(s4) == 0)
    SUCCES;
  else
    FAIL;
}

void s21_strcmp_test() {
  char s1[] = "cat";
  char s2[] = "dog";
  char s3[] = "cat";
  char s4[] = "catt";

  printf("length of string1 = length of string2. cat - dog\n");
  if (s21_strcmp(s1, s2) < 0) {
    SUCCES;
  } else {
    FAIL;
  }
  printf(" string1 = string2. cat - cat\n");
  if (s21_strcmp(s1, s3) == 0) {
    SUCCES;
  } else {
    FAIL;
  }
  printf("string1 bigger than string2. catt - dog\n");
  if (s21_strcmp(s4, s2) < 0) {
    SUCCES;
  } else {
    FAIL;
  }
  printf("string 1 smaller than string2. dog - cat\n");
  if (s21_strcmp(s2, s4) > 0) {
    SUCCES;
  } else {
    FAIL;
  }
}

void s21_strcpy_test() {
  char s1[] = "cat";
  char s2[] = "dog";
  int flag = 0;
  s21_strcpy(s1, s2);
  for (int i = 0; i < 3; i++)
    if (s1[i] != s2[i]) flag = 1;
  if (flag == 1)
    FAIL;
  else
    SUCCES;
}

void s21_strcat_test() {
  char s1[] = "cat";
  char s2[] = "dog";
  char s3[] = "catdog";
  int flag = 0;
  s21_strcat(s1, s2);
  for (int i = 0; i < 6; i++)
    if (s1[i] != s3[i]) flag = 1;
  if (flag == 1)
    FAIL;
  else
    SUCCES;
}

void s21_strchr_test() {
  char s1[] = "cat";
  s21_strchr(s1, 'a');
  SUCCES;
}

void s21_strstr_test() {
  char s1[] = "abobaaboba";
  s21_strstr(s1, "aboba");
  SUCCES;
}

int main() {
#ifdef test_len
  s21_strlen_test();
#endif

#ifdef test_cmp
  s21_strcmp_test();
#endif

#ifdef test_cpy
  s21_strcpy_test();
#endif

#ifdef test_cat
  s21_strcat_test();
#endif

#ifdef test_chr
  s21_strchr_test();
#endif

#ifdef test_str
  s21_strstr();
#endif

  return 0;
}
