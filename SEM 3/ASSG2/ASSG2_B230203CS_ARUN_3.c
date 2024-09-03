#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 100

// AVL TREE STRUCT
typedef struct Node{
    int key;
    struct Node *left, *right;
    int height;
} Node;
// Utility Fun
int *readIntegers(int *count)
{
    int *arr = NULL;
    int num = 0;
    char ch;

    *count = 0;

    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0');
        }
        else if (ch == ' ')
        {
            arr = realloc(arr, (*count + 1) * sizeof(int));
            arr[(*count)++] = num;
            num = 0;
        }
    }

    if (num != 0 || *count == 0)
    {
        arr = realloc(arr, (*count + 1) * sizeof(int));
        arr[(*count)++] = num;
    }
    arr = realloc(arr, ((*count) + 1) * sizeof(int));
    arr[*count] = -1;

    return arr;
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
char *readParanthesis()
{
    char buffer[MAX_VAL];
    fgets(buffer, MAX_VAL, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *arr = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

    strcpy(arr, buffer);
    remove_spaces(arr);
    return arr;
}
int abs(int a)
{
    return a < 0 ? -a : a;
}
// Tree Utility Fun
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int AVL_balanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
// Helper Functions
void TreeParanthesis(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d", root->key);

    if (root->left != NULL || root->right != NULL)
    {
        printf(" (");

        if (root->left != NULL)
        {
            printf(" ");
            TreeParanthesis(root->left);
        }

        printf(" )");

        if (root->right != NULL)
        {
            printf(" ( ");
            TreeParanthesis(root->right);
            printf(" )");
        }
    }
}
void printpath(Node *root, Node *n)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    if (root->key > n->key)
    {
        printpath(root->left, n);
    }
    else if (root->key < n->key)
        printpath(root->right, n);
}
int TreeSum(Node *root)
{
    if (root != NULL)
    {
        return root->key + TreeSum(root->left) + TreeSum(root->right);
    }
}
// Tree Building Utilities and rotations
Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
Node *AVL_insert(Node *node, int key)
{

    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = AVL_insert(node->left, key);
    else if (key > node->key)
        node->right = AVL_insert(node->right, key);
    else
    {

        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = AVL_balanceFactor(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
Node *AVL_delete(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->key)
    {
        root->left = AVL_delete(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = AVL_delete(root->right, key);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }

            root->key = temp->key;
            root->right = AVL_delete(root->right, temp->key);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balancefactor = AVL_balanceFactor(root);

    if (balancefactor > 1 && AVL_balanceFactor(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (balancefactor > 1 && AVL_balanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balancefactor < -1 && AVL_balanceFactor(root->right) <= 0)
    {
        return leftRotate(root);
    }

    if (balancefactor < -1 && AVL_balanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// Tree operations
Node *find(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }

    if (key > root->key)
    {
        return find(root->right, key);
    }
    if (key < root->key)
    {
        return find(root->left, key);
    }
}
Node *Successor(Node *root, int key)
{

    Node *n = find(root, key);
    if (n == NULL)
    {

        return NULL;
    }
    if (n->right != NULL)
    {
        Node *temp = n->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *Succ = NULL;
    while (root != NULL)
    {
        if (n->key < root->key)
        {
            Succ = root;
            root = root->left;
        }
        else if (n->key > root->key)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return Succ;
}
Node *Predessor(Node *root, int key)
{
    Node *pred = NULL;
    Node *current = root;
    while (current != NULL)
    {
        if (key > current->key)
        {
            pred = current;
            current = current->right;
        }
        else if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            if (current->left != NULL)
            {
                pred = current->left;
                while (pred->right != NULL)
                {
                    pred = pred->right;
                }
            }
            break;
        }
    }
    return pred;
}
// MAIN TREE BUILDER
Node *tree(char str[], int start, int end, Node *root)
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
        return root;
    }

    root = AVL_insert(root, num);

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
        root->left = tree(str, start + 1, index - 1, root->left);
        root->right = tree(str, index + 2, end - 1, root->right);
    }

    return root;
}
// Tree Traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
// Sequence  Delete and Insert
Node *AVL_SeqInsert(Node *root, int *seq)
{
    int i = 0;
    while (seq[i] != -1)
    {
        root = AVL_insert(root, seq[i]);
        i++;
    }
    TreeParanthesis(root);
    printf("\n");
    return root;
}
Node *AVL_RangeDelete(Node *root, int low, int high)
{

    int size = (high - low) + 1;
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr[i] = low++;
    }

    int count = 0;
    for (int i = 0; i < size; i++)
    {

        if (find(root, arr[i]) != NULL)
        {
            root = AVL_delete(root, arr[i]);
            count++;
        }
    }

    free(arr);

    printf("%d ", count);
    preorder(root);
    printf("\n");

    return root;
}
void AVL_SuccessorPath(Node *root, int key)
{
    Node *new = find(root, key);
    Node *succ = Successor(root, key);
    if (new == NULL || succ == NULL)
    {
        printf("%d\n", max(height(root->left), height(root->right)));
        return;
    }
    // printpath(root, new);

    // printf(" %d", new->key);
    printpath(root, succ);

    printf("\n");
}
void AVL_SubtreeSum(Node *root, int key)
{
    Node *newroot = find(root, key);
    if (newroot == NULL)
    {
        printf("-1\n");
        return;
    }

    int sum = 0;
    sum = TreeSum(newroot);
    printf("%d ", sum);
    TreeParanthesis(newroot);
    printf("\n");
}
void AVL_FindClosest(Node *root, int key)
{

    Node *check = find(root, key);
    if (check == NULL)
    {
        printf("-1\n");
        return;
    }
    Node *prednode = Predessor(root, key);
    Node *succnode = Successor(root, key);

    int pred = (prednode != NULL) ? prednode->key : -1;
    int succ = (succnode != NULL) ? succnode->key : -1;

    if (pred == -1 && succ == -1)
    {
        printf("-1\n");
        return;
    }
    if (succ == -1)
    {
        printf("%d\n", pred);
        return;
    }
    if (pred == -1)
    {
        printf("%d\n", succ);
        return;
    }
    int predDiff = abs(key - pred);
    int succDiff = abs(key - succ);

    if (predDiff < succDiff)
    {
        printf("%d\n", pred);
    }
    else if (succDiff < predDiff)
    {
        printf("%d\n", succ);
    }
    else
    {
        printf("%d\n", (pred < succ) ? pred : succ);
    }
}

int main()
{
    Node *root = NULL;
    char *Input;
    Input = readParanthesis();
    root = tree(Input, 0, strlen(Input), root);
    // preorder(root);
    // printf("\n");
    while (1)
    {
        char choice;
        scanf("%c", &choice);
        int key,n1,n2;
        int *seq;
        int count = 0;
        switch (choice){
            case 'a':
                getchar();
                seq = readIntegers(&count);
                for (int i = 0; seq[i]!=-1; i++)
                {  
                    if (seq[i]>10000000 || seq[i]<1)
                    {
                       return 0;
                    }
                    
                }
                
                root = AVL_SeqInsert(root, seq);
                break;
            case 'b':
                scanf("%d %d", &n1, &n2);
                root = AVL_RangeDelete(root, n1, n2);
                break;
            case 'c':
                scanf("%d", &key);
                AVL_SuccessorPath(root, key);
                break;
            case 'd':
                scanf("%d", &key);
                AVL_SubtreeSum(root, key);
                break;
            case 'e':
                scanf("%d", &key);
                AVL_FindClosest(root, key);
                break;
            case 'g':
                return 0;
            default:
                break;
        }
    }

    return 0;
}