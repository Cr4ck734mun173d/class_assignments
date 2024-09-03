#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 100
typedef struct node
{
    int key;
    struct node *left, *right;
} node;
node *CreateNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->key = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
node *InsertNode(node **root, int key)
{
    if (*root == NULL)
    {

        *root = CreateNode(key);

        return *root;
    }
    if (key < (*root)->key)
    {

        (*root)->left = InsertNode(&(*root)->left, key);
    }
    else if (key > (*root)->key)
    {

        (*root)->right = InsertNode(&(*root)->right, key);
    }
    return *root;
}
void SearchKey(node *root, int key)
{
    if (root == NULL)
    {
        printf("NOT PRESENT\n");
        return;
    }
    if (root->key == key)
    {
        printf("PRESENT\n");
        return;
    }

    if (root->key < key)
    {
        SearchKey(root->right, key);
    }
    else
        SearchKey(root->left, key);
}
void DeleteNode(node **root, int key)
{
    if (*root == NULL)
    {
        printf("NOT PRESENT in the BST\n");
        return;
    }
    if ((*root)->key > key)
    {
        DeleteNode(&(*root)->left, key);
    }
    else if ((*root)->key < key)
    {
        DeleteNode(&(*root)->right, key);
    }
    else
    {
        if ((*root)->left == NULL)
        {
            node *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL)
        {
            node *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else
        {
            node *temp = (*root)->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            (*root)->key = temp->key;
            DeleteNode(&(*root)->right, temp->key);
        }
    }
}
void Maximum(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    printf("%d\n", root->key);
}

int InOrder(node *root, int i, int *count)
{

    if (root == NULL || *count >= i)
    {
        return -1;
    }
    int l = InOrder(root->left, i, count);
    if (l != -1)
    {
        return l;
    }
    (*count)++;
    if (*count == i)
    {
        return root->key;
    }
    return InOrder(root->right, i, count);
}
int KthSmallest(node *root, int key)
{
    int i = 0;
    printf("%d\n", InOrder(root, key, &i));
}
    void Successor(node *root, int num)
    {
        if (root == NULL)
        {
            return;
        }
        if (num > root->key)
        {
            Successor(root->right, num);
        }
        if (num < root->key)
        {
            Successor(root->left, num);
        }
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
        printf("%d\n", root->key);
    }
int main()
{
    char choice;
    node *root = NULL;
    int key;
    while (1)
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'i':
            scanf("%d", &key);
            InsertNode(&root, key);
            break;

        case 'k':
            scanf("%d", &key);
            KthSmallest(root, key);

            break;
        case 'd':
            scanf("%d", &key);
            DeleteNode(&root, key);
            break;
        case 's':
            scanf("%d", &key);
            SearchKey(root, key);

            break;
        case 'm':
            Maximum(root);

            break;
        case 'n':
            scanf("%d", &key);
            Successor(root, key);
            break;
        case 'e':
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}