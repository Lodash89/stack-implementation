#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define EMPTY_STACK INT_MIN
#define DELETED_ITEM INT_MAX

typedef struct _stack{
    int size;
    int top;
    int *items;
}stack;

stack *create_stack(int size){
    stack *s = (stack*)malloc(sizeof(stack)*size);
    s->size = size;
    s->top = -1;
    s->items = (int*)calloc(size, sizeof(int));
    return s;
}

void free_stack(stack *s){
    free(s->items);
    free(s);
}

bool is_full(stack *s){
    return s->top == s->size;
}

bool is_empty(stack *s){
    return s->top == -1;
}

void push(stack *s, int item){
    if(!is_full(s))
        s->items[++s->top] = item;
}

int pop(stack *s){
    int value = EMPTY_STACK;
    if(!is_empty(s)){
        value = s->items[s->top--];
        s->items[s->top+1] = DELETED_ITEM;
    }
    return value;
}

int peek(stack *s){
    int value = EMPTY_STACK;
    if(!is_empty(s)){
        value = s->items[s->top];
    }
    return value;
}

void print_stack(stack *s){
    for(int i = 0; i < s->size; i++)
        printf("-- %d\n", s->items[i]);
}

int main(int argc, char const *argv[])
{
    stack *s = create_stack(2);

    push(s, 3);
    push(s, 5);

    print_stack(s);

    pop(s);

    print_stack(s);

    free_stack(s);

    return 0;
}
