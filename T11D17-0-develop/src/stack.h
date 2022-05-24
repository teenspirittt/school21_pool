#ifndef STACK_H
#define STACK_H

typedef int stack_data;

typedef struct node {
    stack_data value;
    struct node *next;
} t_node;

typedef struct stack{
    t_node *ptr_start;
    int size;
}stack;

stack stack_create();
void push( stack *s, stack_data value);
stack_data pop( stack *s);
void destroy(t_node *ptr_start);
void print(t_node *ptr_start);
void stack_clear(stack *s);
void stack_print(const stack *s);
int stack_size(const stack *s);

#endif