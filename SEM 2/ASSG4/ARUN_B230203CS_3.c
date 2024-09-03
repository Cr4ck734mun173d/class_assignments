#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 100000
#define COUNT 10

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *newnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *tree(char str[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int num = -1;
    while (start <= end && str[start] >= '0' && str[start] <= '9')
    {
        if (num == -1)
        {
            num = 0;
        }
        num = num * 10 + (str[start] - '0');
        start++;
    }
    if (num == -1)
    {
        return NULL;
    }
    node *root = newnode(num);
    int index = -1;
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (str[i] == '(')
        {
            count++;
        }
        else if (str[i] == ')')
        {
            count--;
            if (count == 0)
            {
                index = i;
                break;
            }
        }
    }
    if (index != -1)
    {
        root->left = tree(str, start + 1, index - 1);
        root->right = tree(str, index + 2, end - 1);
    }
    return root;
}

void remove_spaces(char *s)
{
    int j = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] != ' ')
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
void printInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

node *nodechecker(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    node *left = nodechecker(root->left, key);
    if (left != NULL)
    {
        return left;
    }

    return nodechecker(root->right, key);
}
void printnode(node *root, int *depth)
{

    if (root == NULL || *depth < 0)
    {
        return;
    }
    int depthcopy = *depth;
    if (depthcopy == 0)
    {
        printf("%d ", root->data);
        return;
    }
    depthcopy--;
    printnode(root->left, &depthcopy);
    printnode(root->right, &depthcopy);
}
int main()
{
    int n = 0;
    char input[MAX_VAL];
    getchar();
    fgets(input, MAX_VAL, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (input[0] == '\0')
    {
        return 0;
    }
    char copy[MAX_VAL];
    int digit[MAX_VAL];
    digit[0] = -1;
    strcpy(copy, input);
    int j = 0;
    int index = 0;
    while (copy[j] != '\0')
    {
        if (isdigit(copy[j]))
        {
            digit[index] = atoi(&copy[j]);
            index++;

            while (isdigit(copy[j]))
            {
                j++;
            }
        }
        else
        {
            j++;
        }
    }

    if (index > 1000)
    {
        return 0;
    }

    digit[index] = -1;
    for (int i = 0; digit[i] != -1; ++i)
    {
        if (digit[i] < 1 || digit[i] > 1000000)
        {
            return 0;
        }
    }
    remove_spaces(input);
    // printf("%s",input);
    node *root = tree(input, 0, strlen(input) - 1);
    int x, k;
    scanf("%d %d", &x, &k);
    if (k < 1 || k > 1000)
    {
        return 0;
    }


    node *temp = nodechecker(root, x);
    // printf("%d ",temp->data);
    printnode(temp, &k);
    printf("\n");
    return 0;
}