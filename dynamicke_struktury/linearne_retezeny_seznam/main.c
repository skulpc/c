#include <stdio.h>
#include <stdlib.h>

// FIFO

typedef struct node
{
    char val;
    struct node *next;
} Node;

typedef struct list
{
    Node *back;
} List;

void init(List *list)
{
    list->back = NULL;
}

int pop(List *stack)
{
    if (stack->back == NULL)
    {
        return -1;
    }
    int val = stack->back->val;

    Node *tmp = stack->back;
    stack->back = stack->back->next;
    free(tmp);

    return val;
}

void add_to_sorted(List *list, int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;

    if (list->back == NULL)
    {
        list->back = new_node;
        return;
    }

    Node *prev = NULL;
    Node *next = list->back;

    while (1)
    {
        if (next->val >= new_node->val)
        {
            if (next == list->back)
            {
                new_node->next = list->back;
                list->back = new_node;
                break;
            }

            prev->next = new_node;
            new_node->next = next;
            break;
        }
        if (next->next == NULL)
        {
            next->next = new_node;
            break;
        }
        prev = next;
        next = next->next;
    }

    return;
}

// vyse nezmeneno od zasobniku

void free_queue(List *queue)
{
    while (queue->back != NULL)
    {
        Node *tmp = queue->back;
        queue->back = queue->back->next;
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
    List list;

    init(&list);

    char c;
    while ((c = getchar()) != '\n')
    {
        add_to_sorted(&list, c);
    }

    print_queue(&list);

    //remove thingies

    free_queue(&list);
}