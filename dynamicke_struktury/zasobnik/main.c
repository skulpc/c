#include <stdio.h>
#include <stdlib.h>

// LIFO - last in first out

typedef struct node
{
  char val;
  struct node *previous;
} Node;

typedef struct list
{
  Node *back;
} List;

void init(List *stack)
{
  stack->back = NULL;
}

void push(int val, List *stack)
{
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node == NULL)
  {
    printf("Nedostatek pameti\n");
    return;
  }

  new_node->val = val;
  new_node->previous = stack->back;
  stack->back = new_node;
}

int pop(List *stack)
{
  if (stack->back == NULL)
  {
    return -1;
  }
  int val = stack->back->val;
  stack->back = stack->back->previous;
  return val;
}

Node *get_node(List *stack, int index)
{
  Node *tmp = stack->back;
  for (int i = 0; i < index; i++)
  {
    if (tmp == NULL)
    {
      return NULL;
    }
    tmp = tmp->previous;
  }
  return tmp;
}

int get_val(List *stack, int index)
{
  Node *tmp = get_node(stack, index);
  if (tmp == NULL)
  {
    return -1;
  }
  return tmp->val;
}

void set_val(List *stack, int index, int val)
{
  Node *tmp = get_node(stack, index);
  if (tmp == NULL)
  {
    return;
  }
  tmp->val = val;
}

void insert(List *stack, int index, int val)
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
    new_node->previous = stack->back;
    stack->back = new_node;
    return;
  }

  Node *prev = get_node(stack, index - 1);
  if (prev == NULL)
  {
    return;
  }

  new_node->previous = prev->previous;
  prev->previous = new_node;
}

void free_queue(List *stack)
{
  while (stack->back != NULL)
  {
    Node *tmp = stack->back;
    stack->back = stack->back->previous;
    free(tmp);
  }
}

int main()
{
  List stack;

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

  free_queue(&stack);
}