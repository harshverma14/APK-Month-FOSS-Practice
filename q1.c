#include <stdio.h>
#include <stdlib.h>

void scan(int *x)
{
    scanf("%d", x);
}

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} node;

node *createnode(int data)
{
    node *create = (node *)malloc(sizeof(node));
    create->data = data;
    create->rchild = NULL;
    create->lchild = NULL;
    return create;
}
void insert(int x, node *root)
{
    node *prev = NULL;
    node *new = root;
    while (new != NULL)
    {
        prev = new;
        if (new->data < x)
        {
            new = new->rchild;
        }
        else
        {
            new = new->lchild;
        }
    }
    node *newnode = createnode(x);
    if (x > prev->data)
    {
        prev->rchild = newnode;
    }
    else
    {
        prev->lchild = newnode;
    }
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
    return;
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
    return;
}

void preorderwithoutrecursion(node* root){
    if(root == NULL) return;
    
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
    return;
}

node *minValuenode(node *check)
{
    node *current = check;
    while (current && current->lchild != NULL)
        current = current->lchild;
    return current;
}
node *deletenode(node *root, int data)
{
    if (root == NULL)
    {
        printf("Not present in the tree\n");
        return root;
    }

    if (data < root->data)
        root->lchild = deletenode(root->lchild, data);
    else if (data > root->data)
        root->rchild = deletenode(root->rchild, data);
    else
    {
        if (root->lchild == NULL)
        {
            node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            node *temp = root->lchild;
            free(root);
            return temp;
        }

        node *temp = minValuenode(root->rchild);
        root->data = temp->data;
        root->rchild = deletenode(root->rchild, temp->data);
    }
    return root;
}


int main()
{
    printf("enter n: ");
    int n;
    scan(&n);
    int rootdata;
    printf("enter the datas you want to store in the nodes");
    scan(&rootdata);
    node *root = createnode(rootdata);
    for (int i = 1; i < n; i++)
    {
        int x;
        scan(&x);
        insert(x, root);
    }
    while (1)
    {
        printf("1. enter 0 to exit.\n");
        printf("2. enter 1 to print preorder.\n");
        printf("3. enter 2 to print inorder.\n");
        printf("4. enter 3 to print postorder.\n");
        printf("5. enter 4 to search and delete the node(if exists) and then print inordertraversal\n");
        printf("6. enter 5 to insert a node in the tree\n");
        int x;
        scan(&x);
        int flag = 0;
        int key;
        switch (x)
        {
        case 0:
            printf("exit\n");
            flag = 1;
            break;
        case 1:
            preorder(root);
            printf("\n");
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;

        case 3:
            postorder(root);
            printf("\n");
            break;

        case 4:
        printf("enter the value of the node you want to delete : ");
            scan(&key);
            root = deletenode(root,key);
            inorder(root);
            printf("\n");
            break;
        case 5:
        printf("enter the value you want to store in the node: ");
        scan(&key);
        insert(key,root);
        break;
        default:
            printf("enter valid input\n");
            break;
        }
        if (flag == 1)
            break;
    }
    return 0;
}