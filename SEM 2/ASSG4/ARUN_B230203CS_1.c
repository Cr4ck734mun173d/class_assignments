#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 100
typedef struct node
{
    int data;
    struct node *right, *left;

} node;
node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
node *InsertNode(node **root, int key)
{
    if (*root == NULL)
    {

        *root = createnode(key);
    }
    if (key < (*root)->data)
    {

        (*root)->left = InsertNode(&(*root)->left, key);
    }
    else if (key > (*root)->data)
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
    if (root->data == key)
    {
        printf("PRESENT\n");
        return;
    }

    if (root->data < key)
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
    if ((*root)->data > key)
    {
        DeleteNode(&(*root)->left, key);
    }
    else if ((*root)->data < key)
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
            (*root)->data = temp->data;
            DeleteNode(&(*root)->right, temp->data);
        }
    }
} 
void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);

        printf("%d ", root->data);
        InOrder(root->right);
    }
}
void PreOrder(node *root)
{
    if (root != NULL)
    {

        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    int n;
    node *root = NULL;
    while (1)
    {

        char choice;
        int num;
        int key;
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'i':
            scanf("%d", &key);
            InsertNode(&root, key);

            break;
        case 's':
            scanf("%d", &num);
            SearchKey(root, num);
            break;
        case 'd':

            scanf("%d", &key);
            DeleteNode(&root, key);
            break;
        case 'p':
            if (root == NULL)
            {
                printf("NULL\n");
                break;
            }

            InOrder(root);
            printf("\n");
            break;
        case 't':
            if (root == NULL)
            {
                printf("NULL\n");
                break;
            }
            PreOrder(root);
            printf("\n");
            break;
        case 'b':
            if (root == NULL)
            {
                printf("NULL\n");
                break;
            }
            PostOrder(root);
            printf("\n");
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