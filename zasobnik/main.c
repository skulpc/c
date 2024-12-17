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

Node *get_node(Stack *stack, int index)
{
  Node *tmp = stack->top;
  for (int i = 0; i < index; i++)
  {
    if (tmp == NULL)
    {
      return -1;
    }
    tmp = tmp->next;
  }
  return tmp;
}

int get_val(Stack *stack, int index)
{
  Node *tmp = get_node(stack, index);
  if (tmp == -1)
  {
    return -1;
  }
  return tmp->val;
}

void set_val(Stack *stack, int index, int val)
{
  Node *tmp = get_node(stack, index);
  if (tmp == -1)
  {
    return;
  }
  tmp->val = val;
}

void insert(Stack *stack, int index, int val)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("Nedostatek pameti\n");
    return;
  }

  new_node->val = val;

  if (index == 0)
  {
    new_node->next = stack->top;
    stack->top = new_node;
    return;
  }

  Node *prev = get_node(stack, index - 1);
  if (prev == -1)
  {
    return;
  }

  new_node->next = prev->next;
  prev->next = new_node;
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