//WAP to find the 2nd minimum element from a BST.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;


struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


struct node *insert(struct node *node, int data)
{
  
    if (node == NULL)
        return (newNode(data));
    else
    {
       
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }
}
int Successor(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}

int Second_Minimum(Node *root)
{

    if (!root)
        return -1;

    Node *previous = root;

    if (root->left)
    {
        while (root->left)
        {
            previous = root;
            root = root->left;
        }

        if (!root->right)
            return previous->data;
    }

    if (root->right)
        return Successor(root->right);

    return (previous->data);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);

    printf("\n The 2nd Minimum value in BST is %d", Second_Minimum(root));
    getchar();
    return 0;
}
