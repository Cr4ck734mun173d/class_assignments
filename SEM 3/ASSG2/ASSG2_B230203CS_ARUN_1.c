#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
    int height;
} Node;
typedef struct stackn
{
    Node *node;
    struct stackn *next;
} stacknode;

void push(stacknode **top_ref, Node *new_node)
{

    stacknode *new_node1 = (stacknode *)malloc(sizeof(stacknode));
    new_node1->node = new_node;
    new_node1->next = (*top_ref);
    (*top_ref) = new_node1;
}
Node *pop(stacknode **top)
{
    if (*top == NULL)
        return NULL;
    stacknode *temp = *top;
    *top = (*top)->next;
    Node *res = temp->node;
    free(temp);
    return res;
}
Node *peek(stacknode *top)
{
    if (top == NULL)
    {
        return NULL;
    }
    return top->node;
}
int isEmpty(stacknode *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

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

Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y, int *rot)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    ++(*rot);

    return x;
}

Node *leftRotate(Node *x, int *rot)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    ++(*rot);

    return y;
}

int AVL_balanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
void PrintAncestor(Node *root, int key)
{

    if (root == NULL)
    {
        return;
    }
    if (root->key == key)
    {
        printf("%d ", key);
    }
    printf("%d ", root->key);
    if (root->key > key)
    {
        PrintAncestor(root->left, key);
    }
    if (root->key < key)
    {
        PrintAncestor(root->right, key);
    }
}

Node *AVL_insert(Node *node, int key, int *leftrot, int *rightrot)
{

    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = AVL_insert(node->left, key, leftrot, rightrot);
    else if (key > node->key)
        node->right = AVL_insert(node->right, key, leftrot, rightrot);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = AVL_balanceFactor(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node, rightrot);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node, leftrot);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left, leftrot);
        return rightRotate(node, rightrot);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right, rightrot);
        return leftRotate(node, leftrot);
    }

    return node;
}
void print(Node *root, Node *node)
{
    if (root == NULL || node == NULL)
    {
        return;
    }
    if (node->key == root->key)
    {
        printf("%d\n", node->key);
        return;
    }
    if (node->key > root->key)
    {
        printf("%d ", root->key);
        print(root->right, node);
    }
    if (node->key < root->key)
    {
        printf("%d ", root->key);
        print(root->left, node);
    }
}

int printerfunction(Node *root, int key)
{
    stacknode *top = NULL;
    Node *temp = root;
    while (temp != NULL && temp->key != key)
    {
        push(&top, temp);
        if (temp->key > key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        //printf("-1\n");
        return -1;
    }

    printf("%d ", key);
    while (!isEmpty(top))
    {

        printf("%d", pop(&top)->key);
    }
    printf("\n");
    return 0;
}
Node *AVL_delete(Node *root, int key, int *leftrotations, int *rightrotations,int* flag)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (*flag==0)
    {
        *flag=1;
        if (printerfunction(root,key)==-1)
        {   
            
            printf("-1\n");
            return root;
        }
        
    }
    
    

    if (key < root->key)
    {
        root->left = AVL_delete(root->left, key, leftrotations, rightrotations,flag);
    }
    else if (key > root->key)
    {
        root->right = AVL_delete(root->right, key, leftrotations, rightrotations,flag);
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
            root->right = AVL_delete(root->right, temp->key, leftrotations, rightrotations,flag);
        }
    }
    if (printerfunction(root, key) == -1)
    {
        return root;
    }
    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balancefactor = AVL_balanceFactor(root);

    if (balancefactor > 1 && AVL_balanceFactor(root->left) >= 0)
    {
        return rightRotate(root, rightrotations);
    }

    if (balancefactor > 1 && AVL_balanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left, leftrotations);
        return rightRotate(root, rightrotations);
    }

    if (balancefactor < -1 && AVL_balanceFactor(root->right) <= 0)
    {
        return leftRotate(root, leftrotations);
    }

    if (balancefactor < -1 && AVL_balanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right, rightrotations);
        return leftRotate(root, leftrotations);
    }

    return root;
}

Node *AVL_find(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }

    if (key > root->key)
    {
        return AVL_find(root->right, key);
    }
    if (key < root->key)
    {
        return AVL_find(root->left, key);
    }
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
void AVL_rotations(Node *root, int *leftrotations, int *rightrotations)
{
    printf("%d %d\n", *leftrotations, *rightrotations);
}
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
int main()
{
    Node *root = NULL;
    int leftrotations = 0;
    int rightrotations = 0;
    int flag=0;
    while (1)
    {
        char choice;
        scanf("%c", &choice);
        int n;
        switch (choice)
        {
        case 'i':
            scanf("%d", &n);
            if (n>1000000||n<1)
            {
                return 0;
            }
            
            root = AVL_insert(root, n, &leftrotations, &rightrotations);
            break;
        case 'f':
            scanf("%d", &n);
            Node *temp = AVL_find(root, n);
            if (temp != NULL)
            {
                print(root, temp);
            }
            else
                printf("-1\n");

            break;
        case 'p':
            postorder(root);
            printf("\n");
            break;
        case 's':
            AVL_rotations(root, &leftrotations, &rightrotations);
            break;
        case 'd':
            scanf("%d", &n);
            root = AVL_delete(root, n, &leftrotations, &rightrotations,&flag);
            break;
        case 'b':
            scanf("%d", &n);
            int bf = AVL_balanceFactor(AVL_find(root, n));
            printf("%d\n", bf);
            break;
        case 'e':
            return 0;
            break;
        /*case 'y':
            inorder(root);
            printf("\n");
            break;
        case 'x':
            preorder(root);
            printf("\n");
            break;*/
        default:
            break;
        }
    }

    return 0;
}