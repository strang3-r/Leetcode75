// BST
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

    tree *p;

    if ((*r) == NULL)
    {
        p = (tree *)malloc(sizeof(tree));
        p->lchild = p->rchild = NULL;
        p->info = n;
        *r = p; // imprtant step
        return;
    }
    else if ((*r)->info > n && (*r)->info != n)
        create(&(*r)->lchild, n);

    else if ((*r)->info < n && (*r)->info != n)
        create(&(*r)->rchild, n);

    else
    {
        printf("duplicate element entered \n");
        return;
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

void delete (tree **r, int key)
{
    tree *p, *j = (*r);

    while (j != NULL)
    {
        if (key == j->info)
            break;

        p = j;

        if (key < j->info)
        {
            j = j->lchild;
        }

        else if (key > j->info)
            j = j->rchild;

        else
        {
            printf("not found");
            return;
        }
    }
    if ((j->lchild == NULL && j->rchild == NULL) && ((*r)->lchild != NULL || (*r)->rchild != NULL))
    {
        printf("deleted element is leaf node \n");

        if (p->info > key)
            p->lchild = NULL;
        else
            p->rchild = NULL;

        free(j);
    }
    else if ((*r)->lchild == NULL && (*r)->rchild == NULL)
    {
        printf("only root element\n");
        free(j);
    }
    else if (j->lchild!=NULL || j->rchild!=NULL)
    {
        
    }
}

tree* search(tree *r, int key)
{
    while (r != NULL)
    {
        if (key == r->info)
            return r;


        if (key < r->info)
        {
            r = r->lchild;
        }

        else if (key > r->info)
            r = r->rchild;

        else
        {
            printf("not found");
            return NULL;
        }
    }

    return r;
}
int inorderpre(tree *r)
{
    r=r->lchild;
    tree *p;
    while (r != NULL)
    {
        p = r;
        r = r->rchild;
    }

    return p->info;
}

int inordersucc(tree *r)
{
    r=r->rchild;
    tree *p;
    while (r != NULL)
    {
        p = r;
        r = r->lchild;
    }

    return p->info;
}

int height(tree *r)
{
    tree *p = r;
    int h1 = -1, h2 = -1 ;

    while (r != NULL)
    {
        r = r->lchild;
        h1++;
    }

    while (p != NULL)
    {
        p = p->rchild;
        h2++;
    }

    if (h1 >= h2)
        return h1;

    else
        return h2;
}

int main()
{
    tree *root = NULL;
    int n, ch, key;

    do
    {
        printf("\n1)Insert \n2)inorder \n3)preorder \n4)postorder \n5)delete \n6)height \n7)inorder succ \n8)inorder pred \n");
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
            delete (&root, key);
        }
        if (ch == 6)
            printf("height of tree is : %d\n",height(root));
        
        if(ch==7)
        {
            printf("Enter element of which you want to find inoder pred: ");
            scanf("%d",&key);

            printf("inorder pred is : %d\n",inorderpre(search(root,key)));
        }
        if(ch==8)
        break;

    } while (1);

    return 0;
}