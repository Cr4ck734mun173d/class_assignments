#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 100

typedef struct new
{
    int model_num;
    char *model_name;
    int price;
    struct new *left, *right, *parent;
}
node;

node *Create_node(int model_num, char *model_name, int price)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->model_num = model_num;

    newnode->model_name = (char *)malloc(strlen(model_name) * sizeof(char));
    strcpy(newnode->model_name, model_name);
    newnode->price = price;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
node *add(node *root, int model_num, char *model_name, int price)
{

    if (root == NULL)
    {
        node *newnode = Create_node(model_num, model_name, price);
        return newnode;
    }
    node *parent = NULL;
    node *current = root;
    while (current != NULL)
    {
        parent = current;
        if (current->model_num >= model_num)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    node *newnode = Create_node(model_num, model_name, price);
    newnode->parent = parent;
    if (parent == NULL)
    {
        return newnode;
    }

    if (parent->model_num >= model_num)
    {
        parent->left = newnode;
    }
    else
    {
        parent->right = newnode;
    }
    return root;
}

node *delete(node *root, int model_num)
{
    if (root == NULL)
        return root;

    if (root->model_num > model_num)
    {
        root->left = delete (root->left, model_num);
    }
    else if (root->model_num < model_num)
    {
        root->right = delete (root->right, model_num);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->model_num = temp->model_num;
        root->right = delete (root->right, temp->model_num);
        return root;
    }
}

node *Search(node *root, int model_num)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->model_num == model_num)
    {
        return root;
    }
    if (root->model_num > model_num)
    {
        return Search(root->left, model_num);
    }
    else
    {
        return Search(root->right, model_num);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d %s %d\n", root->model_num, root->model_name, root->price);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d %s %d\n", root->model_num, root->model_name, root->price);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d %s %d\n", root->model_num, root->model_name, root->price);
    }
}
void modify(node *root, int model_num, int price)
{
    if (root == NULL)
    {
        return;
    }
    if (root->model_num == model_num)
    {
        root->price = price;
        return;
    }
    if (root->model_num > model_num)
    {
        modify(root->left, model_num, price);
    }
    else
    {
        modify(root->right, model_num, price);
    }
}

int main()
{
    node *root = NULL;
    while (1)
    {
        char choice;
        char model_name[MAX_VAL];
        int model_num;
        int price;
        scanf("%c", &choice);

        switch (choice)
        {
        case 'a':

            scanf("%d %s %d", &model_num, model_name, &price);
            if (model_num <1 || price < 1)
            {
                return 0;
            }

            root = add(root, model_num, model_name, price);
            break;
        case 'd':
            scanf("%d", &model_num);
            if (model_num < 1)
            {
                return 0;
            }
            
            root = delete (root, model_num);
            break;
        case 's':
            scanf("%d", &model_num);
            if (model_num < 1)
            {
                return 0;
            }
            
            node *temp = Search(root, model_num);
            if (temp != NULL)
            {

                printf("%d %s %d\n", temp->model_num, temp->model_name, temp->price);
            }
            else
                printf("-1\n");
            break;
        case 'p':
            preorder(root);
            break;
        case 'i':
            inorder(root);
            break;
        case 't':
            postorder(root);
            break;
        case 'm':
            scanf("%d %d", &model_num, &price);
            if (model_num<1 || price<1)
            {
                return 0;
            }
            
            modify(root, model_num, price);
            break;
        case 'e':
            return 0;
        default:
            break;
        }
    }

    return 0;
}
