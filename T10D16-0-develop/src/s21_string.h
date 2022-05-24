#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(char *string);
int s21_strcmp(char *string, char *cmp_string);
char s21_strcpy(char *string, char *cpy_string);
char s21_strcat(char *string, char *cat_string);
char s21_strchr(char *string, int chr);
char s21_strstr(char *string, char *str_string);
char *s21_strtok(char *string, char *tok_string);
void s21_width(char *string, int width);

void s21_strlen_test();
void s21_strcpy_test();
void s21_strcmp_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

#endif