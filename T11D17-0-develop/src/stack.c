#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(stack *s, stack_data value) {
  t_node *p = (t_node *)malloc(sizeof(t_node));
  p->value = value;
  p->next = s->ptr_start;
  s->ptr_start = p;
  s->size++;
}

stack_data pop(stack *s) {
  t_node *tmp = s->ptr_start;
  stack_data tmp_value = tmp->value;
  s->ptr_start = s->ptr_start->next;
  s->size--;
  free(tmp);
  return tmp_value;
}

void destroy(t_node *ptr_start) {
  t_node *p = ptr_start;
  while (p != NULL) {
    t_node *tmp;
    tmp = p;
    p = p->next;
    free(tmp);
  }
}

void print(t_node *ptr_start) {
  t_node *p = ptr_start;
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}

stack stack_create() {
  stack steck = {NULL, 0};
  return steck;
}

void stack_print(const stack *s) { print(s->ptr_start); }

void stack_clear(stack *s) {
  destroy(s->ptr_start);
  s->ptr_start = NULL;
  s->size = 0;
}

int stack_size(const stack *s) { return s->size; }
