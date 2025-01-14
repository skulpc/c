#include <stdio.h>
#include <stdlib.h>

// FIFO

typedef struct node
{
    char val;
    struct node *previous;
    struct node *next;
} Node;

typedef struct queue
{
    Node *back;
    Node *front;
} Queue;

void init(Queue *stack)
{
    stack->back = NULL;
    stack->front = NULL;
}

void push(int val, Queue *stack)
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

int pop(Queue *stack)
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

Node *get_node(Queue *stack, int index)
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

int get_val(Queue *stack, int index)
{
    Node *tmp = get_node(stack, index);
    if (tmp == NULL)
    {
        return -1;
    }
    return tmp->val;
}

void set_val(Queue *stack, int index, int val)
{
    Node *tmp = get_node(stack, index);
    if (tmp == NULL)
    {
        return;
    }
    tmp->val = val;
}

void insert(Queue *queue, int index, int val)
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
        queue->back->next = new_node;
        new_node->previous = queue->back;
        new_node->next = NULL;
        queue->back = new_node;
        return;
    }

    Node *prev = get_node(queue, index - 1);
    if (prev == NULL)
    {
        return;
    }
    new_node->previous = prev->previous;
    new_node->next = prev;
    prev->previous = new_node;
    if (new_node->previous != NULL)
    {
        new_node->previous->next = new_node;
    }
}

void insert_sorted(Queue *queue, int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Nedostatek pameti\n");
        return;
    }
    new_node->val = val;

    if (queue->back == NULL) // add to empty queue
    {
        queue->back = new_node;
        queue->back = new_node;
        new_node->next = NULL;
        new_node->previous = NULL;
        return;
    }

    Node *p1 = queue->back, *p2 = NULL;

    while (p1->previous != NULL)
    {
        p2 = p1->previous;

        if () // add to the back
        {
            p1->next = new_node;
            new_node->previous = queue->back;
            new_node->next = NULL;
            queue->back = new_node;
            return;
        }

        if (p1->val < val && p2->val <= val)
        {
            p1->previous = new_node;
            new_node->next = p1;
            p2->next = new_node;
            new_node->previous = p2;
            return;
        }

        p1 = p2;
    }
        //add to the front
        queue->front = new_node;
        p1->previous = new_node;
        new_node->next = p1;
        new_node->previous = NULL;
    
}

// vyse nezmeneno od zasobniku

void free_queue(Queue *queue)
{
    while (queue->back != NULL)
    {
        Node *tmp = queue->back;
        queue->back = queue->back->previous;
        free(tmp);
    }
}

void print_queue(Queue *queue)
{
    int val;
    while ((val = pop(queue)) != -1)
    {
        printf("%c\n", val);
    }
}

int main()
{
    Queue queue;

    init(&queue);

    char c;
    while ((c = getchar()) != '\n')
    {
        insert_sorted(&queue, c);
    }

    print_queue(&queue);

    //remove thingies

    free_queue(&queue);
}