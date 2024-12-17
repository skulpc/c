#include <stdio.h>
#include <stdlib.h>

// LIFO - last in first out

typedef struct node
{
  char val;
  struct node *next;
} Node;

typedef struct stack
{
  Node *top;
} Stack;

void init(Stack *stack)
{
  stack->top = NULL;
}

void push(int val, Stack *stack)
{
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node == NULL)
  {
    printf("Nedostatek pameti\n");
    return;
  }

  new_node->val = val;
  new_node->next = stack->top;
  stack->top = new_node;
}

int pop(Stack *stack)
{
  if (stack->top == NULL)
  {
    return -1;
  }
  int val = stack->top->val;
  stack->top = stack->top->next;
  return val;
}

void free_stack(Stack *stack)
{
  while (stack->top != NULL)
  {
    Node *tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
  }
}

int main()
{
  Stack stack;

  init(&stack);

  char c;
  while ((c = getchar()) != '\n')
  {
    push(c, &stack);
  }

  int val;
  while ((val = pop(&stack)) != -1)
  {
    printf("%c\n", val);
  }

  free_stack(&stack);
}