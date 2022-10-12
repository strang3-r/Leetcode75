/*BINARY SEARCH TREE(BST)
Operations:
Insertion in BST
Displaying in inorder, postorder and preorder
Counting nodes
Deletion of node */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    int info;
    struct node *right;
}treetype;
void insert(treetype **root, int data)
{
    if (*root == NULL)
    {
        treetype *newnode = (treetype *)malloc(sizeof(treetype));
        if (newnode == NULL)
            printf("Memory not allocated\n");
        else
        {
            newnode->left = NULL;
            newnode->info = data;
            newnode->right = NULL;
        }
        *root = newnode;
        return;
    }
    if (data < (*root)->info)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}
void inorder_display(treetype *root)
{
    if (root == NULL)
        return;
    inorder_display(root->left);
    printf("%d    ", root->info);
    inorder_display(root->right);
}
void preorder_display(treetype *root)
{
    if (root == NULL)
        return;
    printf("%d    ", root->info);
    preorder_display(root->left);
    preorder_display(root->right);
}
void postorder_display(treetype *root)
{
    if (root == NULL)
        return;
    postorder_display(root->left);
    postorder_display(root->right);
    printf("%d    ", root->info);
}
void fullcount(treetype *root, int *p)
{
    if (root == NULL)
        return;
    else
    {
        if (root)
            *p = *p + 1;
        fullcount(root->left, p);
        fullcount(root->right, p);
    }
}
void parentcount(treetype *root, int *p)
{
    if (root == NULL)
        return;
    else
    {
        if (root->left && root->right)
            *p = *p + 1;
        parentcount(root->left, p);
        parentcount(root->right, p);
    }
}
void leafcount(treetype *root, int *p)
{
    if (root == NULL)
        return;
    else
    {
        if (root->left == NULL && root->right == NULL)
            *p = *p + 1;
        leafcount(root->left, p);
        leafcount(root->right, p);
    }
}

treetype *inordersuccessor(treetype *p)
{
    treetype *temp = p;
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}
void delete (treetype **root, int key)
{
    if (*root == NULL)
        return;
    else if (key < (*root)->info)
        delete (&(*root)->left, key);
    else if (key > (*root)->info)
        delete (&(*root)->right, key);
    else
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL)
        {
            treetype *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL)
        {
            treetype *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            treetype *temp = inordersuccessor((*root)->right);
            (*root)->info = temp->info;
            delete (&(*root)->right, temp->info);
        }
    }
}
int main()
{
    treetype *root = NULL;
    int data, ch, c = 0, c1 = 0, c2 = 0, key;
    do
    {
        printf("Enter 1 for insert 2 for display 3 for node count 4 for deletion and 5 for exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to insert in binary search tree: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            preorder_display(root);
            printf("\n");
            inorder_display(root);
            printf("\n");
            postorder_display(root);
            printf("\n");
            break;
        case 3:
            fullcount(root, &c);
            printf("Number of nodes are: %d\n", c);
            parentcount(root, &c1);
            printf("Number of parent nodes are: %d\n", c1);
            leafcount(root, &c2);
            printf("Number of leaf nodes are: %d\n", c2);
            break;
        case 4:
            if (root == NULL)
                printf("Nothing to delete\n");
            else
            {
                printf("Enter the value you want to delete:");
                scanf("%d", &key);
                delete (&root, key);
            }
            break;
        case 5:
            exit(0);
            break;
        }
    } while (1);

    return 0;
}
