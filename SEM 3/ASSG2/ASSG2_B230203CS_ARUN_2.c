#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int value;
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

Node *newNode(int key, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
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

int AVL_balanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *AVL_insert(Node *node, int key, int value)
{

    if (node == NULL)
        return (newNode(key, value));

    if (key < node->key)
        node->left = AVL_insert(node->left, key, value);
    else if (key > node->key)
        node->right = AVL_insert(node->right, key, value);
    else
    {
        node->value = value;
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
        // printf("-1\n");
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
Node *AVL_delete(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    // if (*flag == 0)
    // {
    //     *flag = 1;
    //     if (printerfunction(root, key) == -1)
    //     {

    //         printf("-1\n");
    //         return root;
    //     }
    // }

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
int size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int Empty(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return 0;
}
void DisplayElement(Node *root)
{
    if (root != NULL)
    {
        DisplayElement(root->right);
        printf("%d ", root->key);
        DisplayElement(root->left);
    }
}
Node *UpperBound(Node *root, int key)
{
    Node *ub = NULL;
    while (root != NULL)
    {
        if (key <= root->key)
        {
            ub = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ub;
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
    while (1)
    {
        char choice;
        scanf("%c", &choice);
        int key;
        int value;
        Node *temp;
        switch (choice)
        {
        case 'i':
            scanf("%d %d", &key, &value);
            if (key < 0 || value < 0)
            {
                return 0;
            }

            root = AVL_insert(root, key, value);
            break;
        case 'u':
            scanf("%d", &key);
            if (key < 0)
            {
                return 0;
            }

            temp = UpperBound(root, key);
            if (temp != NULL)
            {
                printf("%d %d\n", temp->key, temp->value);
            }
            else
                printf("-1\n");

            break;
        case 'f':

            scanf("%d", &key);
              if (key<0 )
            {
                return 0;
            }
            
            temp = find(root, key);
            if (temp != NULL)
            {
                printf("%d %d\n", temp->key, temp->value);
            }
            else
                printf("-1\n");

            break;
        case 's':
            printf("%d", size(root));
            printf("\n");
            break;
        case 'e':
            printf("%d\n", Empty(root));
            break;
        case 'd':
            DisplayElement(root);
            printf("\n");
            break;
        case 't':
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}