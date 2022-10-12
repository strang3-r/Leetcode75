#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *lchild;
    int info;
    struct tree *rchild;
} tree;

void create(tree **r, int n)
{
    tree *p=(*r),*j;
    if (*r == NULL)
    {
        p = (tree *)malloc(sizeof(tree));
        p->lchild = p->rchild = NULL;
        p->info=n;
        *r = p;
        return;
    }
    while (p != NULL)
    {
        j = p;

        if (p->info>n)
            p = p->lchild;

        else if (n > p->info)
            p = p->rchild;

        else
        {
            printf("DUplicate element \n");
            return;
        }
    }

    if (p == NULL)
    {
        p = (tree *)malloc(sizeof(tree));
        p->lchild = p->rchild = NULL;
        p->info=n;
        
        if(j->info>n)
        {
            j->lchild=p;
            return;
        }
        else
        {
            j->rchild=p;
            return;
        }
    }
}

void inorder(tree *r)
{
    if (r == NULL)
        return;

    inorder(r->lchild);
    printf("%d ", r->info);
    inorder(r->rchild);
}

void preorder(tree *r)
{
    if (r == NULL)
        return;

    printf("%d ", r->info);
    preorder(r->lchild);
    preorder(r->rchild);
}

void postorder(tree *r)
{
    if (r == NULL)
        return;

    postorder(r->lchild);
    postorder(r->rchild);
    printf("%d ", r->info);
    
}

int main()
{
    tree *root = NULL;
    int n, ch, key;

    do
    {
        printf("\n1)Insert \n2)inorder \n3)preorder \n4)postorder \n5)delete \n6)exit \n");
        printf("enter your choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("enter the digit to insert : ");
            scanf("%d", &n);
            create(&root, n);
        }

        if (ch == 2)
        {
            inorder(root);
            printf("\n");
        }

        if (ch == 3)
            preorder(root);

        if (ch == 4)
            postorder(root);

        if (ch == 5)
        {
            printf("enter element to delete : ");
            scanf("%d", &key);
           // delete (&root, key);
        }
        if (ch == 6)
            break;

    } while (1);

    return 0;
}