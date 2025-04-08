#include <stdio.h>
#include <stdlib.h>

// FIFO

typedef struct node
{
  char val;
  struct node *previous;
  struct node *next;
} Node;

typedef struct list
{
  Node *back;
  Node *front;
} List;

void init(List *stack)
{
  stack->back = NULL;
  stack->front = NULL;
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
  new_node->next = NULL;

  if (stack->back != NULL)
  {
    stack->back->next = new_node;
  }
  else
  {
    stack->front = new_node;
  }

  stack->back = new_node;
}

int pop(List *stack)
{
  if (stack->front == NULL)
  {
    return -1;
  }
  int val = stack->front->val;

  Node *tmp = stack->front;
  stack->front = stack->front->next;
  if (stack->front == NULL)
    stack->back = NULL;
  free(tmp);

  return val;
}

// nize az po insert(.) nezmeneno od zasobniku

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

// vyse nezmeneno od zasobniku

void free_queue(List *queue)
{
  while (queue->back != NULL)
  {
    Node *tmp = queue->back;
    queue->back = queue->back->previous;
    free(tmp);
  }
}

void print_queue(List *queue)
{
  int val;
  while ((val = pop(queue)) != -1)
  {
    printf("%c\n", val);
  }
}

int main()
{
  List queue;

  init(&queue);

  char c;
  while ((c = getchar()) != '\n')
  {
    push(c, &queue);
  }

  print_queue(&queue);

  free_queue(&queue);
}