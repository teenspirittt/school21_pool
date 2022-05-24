#ifndef ALL_STRUCTURE_H
#define ALL_STRUCTURE_H

typedef struct {
  short type;     //  1 - for operator, 2 - for operand
  double value;   //  index in lexemes[] for operation, value for operand
  short prec;
  short args;
  char name[10];
} Lexeme;

typedef struct stack {
  Lexeme elem;
  struct stack* next;
} Stack;

typedef struct queue {
  Lexeme elem;
  struct queue* back;
} Queue;

Stack* init_stack(Lexeme new_elem);
void pop_stack(Stack** elem_del);
void push_stack(Stack** hade, Lexeme new_elem);
void desroy_stack(Stack** bot);

Queue* init_queue(Lexeme new_elem);
Lexeme last_in_queue(Queue* hade);
void pop_queue(Queue** hade);
void push_queue(Queue** hade, Lexeme new_elem);
void desroy_queue(Queue** bot);
#endif