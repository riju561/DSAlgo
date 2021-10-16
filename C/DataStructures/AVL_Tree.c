#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int key;
    int h;
    struct node *left, *right;
} node;


typedef struct avltree
{
    node *root;
} tree;


node *create_node(int k)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = k;
    temp->h = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


int height(node *n)
{
    if (n == NULL)
        return -1;
    else
        return n->h;
}


int max(int a, int b)
{
    return a > b ? a : b;
}


node *rotatefromleft(node *n)
{
    node *p = n->left;
    n->left = p->right;
    p->right = n;
    n->h = max(height(n->left), height(n->right)) + 1;
    p->h = max(height(p->left), height(p->right)) + 1;
    return p;
}


node *rotatefromright(node *n)
{
    node *p = n->right;
    n->right = p->left;
    p->left = n;
    n->h = max(height(n->left), height(n->right)) + 1;
    p->h = max(height(p->left), height(p->right)) + 1;
    return p;
}


node *doublerotatefromright(node *n)
{
    n->right = rotatefromleft(n->right);
    return rotatefromright(n);
}


node *doublerotatefromleft(node *n)
{
    n->left = rotatefromright(n->left);
    return rotatefromleft(n);
}


int getbalance(node *a)
{
    if (a == NULL)
        return -2;
    return height(a->left) - height(a->right);
}


node *insert(node *a, int k)
{
    if (a == NULL)
        return create_node(k);
    else
    {
        if (a->key == k)
            return a;
        else if (a->key > k)
        {
            a->left = insert(a->left, k);
            if (abs(getbalance(a)) == 2)
            {
                if (a->left->key > k)
                    a = rotatefromleft(a);
                else
                    a = doublerotatefromleft(a);
            }
        }
        else if (a->key < k)
        {
            a->right = insert(a->right, k);
            if (abs(getbalance(a)) == 2)
            {
                if (a->right->key < k)
                    a = rotatefromright(a);
                else
                    a = doublerotatefromright(a);
            }
        }
        a->h = max(height(a->left), height(a->right)) + 1;
        return a;
    }
}


node *search(tree *a, int k)
{
    node *x = a->root;
    while (x != NULL && k != x->key)
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}


int isavl(node *a)
{
    int left, right;
    if (a == NULL)
        return 0;
    left = isavl(a->left);
    if (left == -1)
        return left;
    right = isavl(a->right);
    if (right == -1)
        return right;
    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}


node *parent(tree *t, node *n)
{
    node *r = t->root;
    if (r == n)
        return NULL;
    while (r != NULL && r->left != n && r->right != n)
    {
        if (n->key < r->key)
            r = r->left;
        else if (n->key > r->key)
            r = r->right;
    }
    return r;
}


node *transplant(tree *t, node *u, node *v)
{
    if (u != NULL)
    {
        node *p = parent(t, u);

        if (p == NULL)
        {
            t->root = v;
        }
        else if (p->left != NULL && u == p->left)
            p->left = v;

        else
            p->right = v;
        node *x = p;
        while (p != NULL)
        {
            p->h = max(height(p->left), height(p->right)) + 1;
            p = parent(t, p);
        }
        if (v == NULL)
            return x;
        else
            return v;
    }
    return NULL;
}


node *minvalue(node *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}


void deletenode(tree *t, node *x)
{
    if (x == NULL)
    {
        printf("FALSE\n");
        return;
    }
    node *p;
    int d = x->key;
    if (x->left == NULL)
        p = transplant(t, x, x->right);
    else if (x->right == NULL)
        p = transplant(t, x, x->left);
    else
    {
        node *y = minvalue(x->right);
        if (parent(t, y) != NULL)
        {
            p = transplant(t, y, y->right);
            y->right = x->right;
        }
        p = transplant(t, x, y);
        p->left = x->left;
        p->h = max(height(p->left), height(p->right)) + 1;
    }
    printf("%d\n", d);
    int shorter = 1;
    while (p != NULL && shorter == 1)
    {
        if (isavl(p) == -1)
        {
            if (getbalance(p) > 0)
            {
                node *q = p->left;
                if (getbalance(q) == 0)
                {
                    p = transplant(t, p, rotatefromleft(p));
                    shorter = 0;
                }
                else if (getbalance(q) > 0)
                {
                    p = transplant(t, p, rotatefromleft(p));
                    p = parent(t, p);
                }
                else if (getbalance(q) < 0)
                {
                    p = transplant(t, p, doublerotatefromleft(p));
                    p = parent(t, p);
                }
            }
            else if (getbalance(p) < 0)
            {
                node *q = p->right;
                if (getbalance(q) == 0)
                {
                    p = transplant(t, p, rotatefromright(p));
                    shorter = 0;
                }
                else if (getbalance(q) > 0)
                {
                    p = transplant(t, p, doublerotatefromright(p));
                    p = parent(t, p);
                }
                else if (getbalance(q) < 0)
                {
                    p = transplant(t, p, rotatefromright(p));
                    p = parent(t, p);
                }
            }
        }
        else
            p = parent(t, p);
    }
}


// avl tree elements in inorder traversal gives the elements as a sorted list.
void inorder(tree *t)
{
    if (t->root == NULL)
        return;

    tree left;
    left.root = t->root->left;
    inorder(&left);

    int i;
    for (i = 0; i < t->root->count; i++)
        printf("%d ", t->root->key);

    tree right;
    right.root = t->root->right;
    inorder(&right);
}
