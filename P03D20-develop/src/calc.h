#ifndef CALC_H
#define CALC_H
#include <math.h>
#include <stdlib.h>
#include "all_structure.h"
double read_parced(Lexeme* lexs, double x);
void sort_polish(Stack* pause_lex, Queue* out_lex, Lexeme lexs_copy_i);
Lexeme* create_copy(Lexeme* lexs);
void replace_x_to_value(Lexeme* copy_lexs, double x);
#endif