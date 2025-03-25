#include <stdio.h>
#include <stdlib.h>

typedef struct Node_struct
{
    int value;
    struct Node_struct *left;
    struct Node_struct *right;
} Node;

// int remove()
// {
//     // if list:
//     //     =null
//     // elif jeden naslednik:
//     //     nahradim naslednikem
//     // elif dva naslednici:
//     //     - bud nejlevejsi prvek z praveho podstromu
//     //     - nebo nejpravejsim prvkem z leveho podstromu
// }

Node *add(Node *root, int x)
{
    if (root == NULL)
    {
        Node *tmp = malloc(sizeof(Node));
        tmp->value = x;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    if (x > root->value)
    {
        root->right = add(root->right, x);
        // what am i setting it to? wheres the return
    }
    else if (x < root->value)
    {
        root->left = add(root->left, x);
    }
    return root;
}

Node *find(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (x > root->value)
    {
        return find(root->right, x);
    }
    if (x < root->value)
    {
        return find(root->left, x);
    }
    return root;
}

void print_tree(Node *root, int depth)
{
    for (size_t i = 0; i < depth; i++)
    {
        printf(" ");
    }

    if (root == NULL)
        return;
    else
        printf("%2d", root->value);

    
    print_tree(root->left, ++depth);
    printf("\n");
    print_tree(root->right, depth);
}

int main()
{
    Node *root = NULL;
    
    root = add(root, 17);
    root = add(root, 12);
    root = add(root, 20);
    root = add(root, 18);
    root = add(root, 19);
    root = add(root, 22);

    print_tree(root, 0);

    Node *tmp = find(root, 17);
    if (tmp == NULL) {
        printf("17 not found\n");
    }
    else {
        printf("17 found, sbtree:\n");
        print_tree(tmp, 0);
    }
    tmp = find(root, 20);
    if (tmp == NULL) {
        printf("20 not found\n");
    }
    else {
        printf("20 found, sbtree:\n");
        print_tree(tmp, 0);
    }

}