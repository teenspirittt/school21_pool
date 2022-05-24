#include <stdlib.h>
#include "all_structure.h"

//    определение стека

Stack* init_stack(Lexeme new_elem) {
  Stack* pol = (Stack*)malloc(sizeof(Stack));
  pol->elem = new_elem;
  
  pol->next = NULL;
  return pol;
}

void pop_stack(Stack** elem_del) {
  if (elem_del) {
    Stack* Stackr = *elem_del;
    (*elem_del) = (*elem_del)->next;
    free(Stackr);
  }
}

void push_stack(Stack** hade, Lexeme new_elem) {
  if ((*hade)) {
    Stack* push_n = (Stack*)malloc(sizeof(Stack));
    push_n->elem = new_elem;
    push_n->next = *hade;
    *hade = push_n;
  } else {
    *hade = init_stack(new_elem);
  }
}

void desroy_stack(Stack** bot) {
  if (*bot) {
    while ((*bot)->next != NULL) {
      pop_stack(bot);
    }
    free(*bot);
  }
}



Queue* init_queue(Lexeme new_elem) {
  Queue* pol = (Queue*)malloc(sizeof(Queue));
  pol->elem = new_elem;
  pol->back = NULL;
  return pol;
}

void pop_queue(Queue** hade) {
  Queue* op = *hade;
  (*hade) = (*hade)->back;
  free(op);
}

Lexeme last_in_queue(Queue* hade){
  Queue* first = hade;
  while ((first)->back == NULL) {
    first = first->back;
  }
  return first->elem;
}

void push_queue(Queue** hade, Lexeme new_elem) {
  if(*hade!=NULL){
  Queue* first = *hade;
  while ((first)->back == NULL) {
    first = first->back;
  }
  Queue* push_n = (Queue*)malloc(sizeof(Queue));
  push_n->elem = new_elem;
  push_n->back = NULL;
  first->back = push_n;
  } else
    *hade = init_queue(new_elem);
}

void desroy_queue(Queue** bot) {
  while ((*bot)->back != NULL) {
    pop_queue(bot);
  }
  free(*bot);
}

