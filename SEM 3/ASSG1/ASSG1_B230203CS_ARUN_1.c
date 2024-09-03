#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 100

typedef struct new
{
    int val;
    struct new *left, *right;
}
node;

node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *buildtreeutil(int *inorder, int *preorder, int *index, int l, int h)
{
    if (l > h)
        return NULL;

    node *root = createnode(preorder[*index]);
    ++(*index);
    if (l == h)
        return root;

    int inorIndex = -1;
    for (int i = l; i <= h; i++)
    {
        if (inorder[i] == root->val)
        {
            inorIndex = i;
            break;
        }
    }

    root->left = buildtreeutil(inorder, preorder, index, l, inorIndex - 1);
    root->right = buildtreeutil(inorder, preorder, index, inorIndex + 1, h);
    return root;
}


int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if (leftheight > rightheight)
        return leftheight + 1;
    else
        return rightheight + 1;
}
void Max(node *root, int level, int *max)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        if (root->val > *max)
        {
            *max = root->val;
        }
    }
    else if (level > 1)
    {
        Max(root->left, level - 1, max);
        Max(root->right, level - 1, max);
    }
}
void LevelMax(node *root)
{
    if (root == NULL)
    {
        return;
    }
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        int max = root->val;
        Max(root, i, &max);
        printf("%d ", max);
    }
    printf("\n");
}
int diameter(node *root, int *height)
{
    int lefth = 0, righth = 0;
    int leftd = 0, rightd = 0;

    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    leftd = diameter(root->left, &lefth);
    rightd = diameter(root->right, &righth);

    if (lefth > righth)
    {
        *height = lefth + 1;
    }
    else
    {
        *height = righth + 1;
    }

    int maxd = (leftd > rightd ? leftd : rightd);
    if (lefth + righth + 1 > maxd)
    {
        return lefth + righth + 1;
    }
    return maxd;
}

void rightleafsumfinder(node *root, int *sum)
{
    if (root == NULL)
        return;

    if (root->right != NULL && root->right->left == NULL && root->right->right == NULL)
    {
        *sum += root->right->val;
    }
    rightleafsumfinder(root->left, sum);
    rightleafsumfinder(root->right, sum);
}

void rightLeafSum(node *root)
{
    int sum = 0;
    rightleafsumfinder(root, &sum);
    printf("%d \n", sum);
}

void inordert(node *root)
{
    if (root != NULL)
    {
        inordert(root->left);
        printf("%d ", root->val);
        inordert(root->right);
    }
}

void preordert(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preordert(root->left);
        preordert(root->right);
    }
}

void postordert(node *root)
{
    if (root != NULL)
    {
        postordert(root->left);
        postordert(root->right);
        printf("%d ", root->val);
    }
}

node *search(node *root, int val)
{
    if (root == NULL || root->val == val)
    {
        return root;
    }
    if (root->val > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}
void printlevel(node *root, int level, int lefttoright)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->val);
    }
    else if (level > 1)
    {
        if (lefttoright)
        {
            printlevel(root->left, level - 1, lefttoright);
            printlevel(root->right, level - 1, lefttoright);
        }
        else
        {
            printlevel(root->right, level - 1, lefttoright);
            printlevel(root->left, level - 1, lefttoright);
        }
    }
}
void zigZagTraversal(node *root)
{
    int h = height(root);
    int lefttoright = 0;
    for (int i = 1; i <= h; i++)
    {
        printlevel(root, i, lefttoright);
        lefttoright = !lefttoright;
    }
    printf("\n");
}
int main()
{
    node *root = NULL;
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 1000000)
        return 0;

    int inorder[n];
    int preorder[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
        if (inorder[i] <= 0 || inorder[i] > 1000000)
            return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
        if (preorder[i] <= 0 || preorder[i] > 1000000)
            return 0;
    }

    int index = 0;
    root = buildtreeutil(inorder, preorder, &index, 0, n - 1);

    while (1)
    {
        char choice;
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'p':
            postordert(root);
            printf("\n");
            break;
        case 'z':
            zigZagTraversal(root);
            
            break;
        case 'm':
            LevelMax(root);
            break;
        case 'd':
        {
            int a = 0;
            printf("%d\n", diameter(root, &a));
        }
        break;
        case 's':
            rightLeafSum(root);
            break;
        case 'i':
            inordert(root);
            printf("\n");
            break;
        case 'r':
            preordert(root);
            printf("\n");
            break;
        case 't':
            postordert(root);
            printf("\n");
            break;
        default:
            return 0;
        }
    }

    return 0;
}
