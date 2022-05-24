#include "calc.h"

double read_parced(Lexeme* lexs, double x) {
  int y;
  int size = sizeof(lexs) / sizeof(*lexs);
  int flag = 1;
  Lexeme* lexs_copy = create_copy_form(lexs);
  Stack* pause_lex = NULL;
  Queue* out_lex = NULL;
  replace_x_to_value(lexs, x);
  for (int i = 0; i < size; i++) {
    sort_polish(pause_lex, out_lex, *(lexs_copy + i));
  }
  push_queue(&out_lex, pause_lex->elem);
  y = out_persed();
  return y;
}

void sort_polish(Stack* pause_lex, Queue* out_lex, Lexeme lexs_copy_i) {
  if (lexs_copy_i.type == 2) {
    push_queue(&out_lex, lexs_copy_i);
  } else {
    if (lexs_copy_i.name == "(") {
      push_stack(&out_lex, (lexs_copy_i));
    } else if (lexs_copy_i.args == 1) {
      push_stack(&out_lex, (lexs_copy_i));
    } else if (lexs_copy_i.name == ")") {
      while (pause_lex->elem.name !="(") {
        push_queue(&out_lex, pause_lex->elem);
        pop_stack(&pause_lex);
      }
      pop_stack(&pause_lex);
    } else {
      if (pause_lex != NULL) {
        while (pause_lex->elem.args == 1 ||
               pause_lex->elem.prec > lexs_copy_i.prec||
               pause_lex!=NULL) {
          push_queue(&out_lex, pause_lex->elem);
          pop_stack(&pause_lex);
        }
      }
      push_stack(&pause_lex, lexs_copy_i);
    }
  }
}

//    создание копии
Lexeme* create_copy(Lexeme* lexs) {
  int size = sizeof(lexs) / sizeof(*lexs);
  Lexeme* new_lexs = (Lexeme*)malloc(size * sizeof(Lexeme));
  for (int i = 0; i < size; i++) {
    *(new_lexs + i) = *(lexs + i);
  }
  return new_lexs;
}
//    замена переменной на соответствующее значение
void replace_x_to_value(Lexeme* copy_lexs, double x) {
  int size = sizeof(copy_lexs) / sizeof(*copy_lexs);
  for (int i = 0; i < size; i++) {
    if ((copy_lexs + i)->type == 1 && (copy_lexs + i)->value == 0) {
      (copy_lexs + i)->type = 1;
      (copy_lexs + i)->value = x;
    }
  }
  return copy_lexs;
}

/*
кодировка операций:
0-"x"      1-"+"       2-"-"      3-"*"      4-"/"        5-"("      6-")"
7-"sin"    8-"cos"     9-"tg"     10-"ctg"   11-"sqrt"    12-"ln"    13-"^"
*/
