#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node node;

struct node {

    node* lchild;
    int data;
    node* rchild;
};

node* new_node(int val){
    node* n = (node* )malloc(sizeof(node));

    n->data=val;
    n->rchild=n->lchild=NULL;

    return n;
}

node* insert(node* root, int val){

    //printf("Inside insert\n");

    if (root==NULL){
        return new_node(val);
    }

    else if (val<root->data){
        root->lchild= insert(root->lchild, val);
    }

    else {
        root->rchild=insert(root->rchild, val);
    }

    return root;
}    

node* delete_node(node* root, int key){
    
    if (key==root->data){
        if (root->lchild==NULL && root->rchild==NULL){
            free(root);
            return NULL;
        }

        else{
            if (root->rchild==NULL){
                node* temp = root->lchild;
                free(root);

                return temp;
            }

            else if (root->lchild==NULL){
                node* temp = root->rchild;
                free(root);

                return temp;
            }

            else {
                node* temp=root->lchild;

                while(temp->rchild!=NULL){
                    temp = temp->rchild;
                }

                root->data=temp->data;
                temp->data=key;

                root->lchild = delete_node(root->lchild, key);
            }
        }
    }

    else {
        if (key<root->data){
            root->lchild=delete_node(root->lchild, key);
        }

        else {
            root->rchild=delete_node(root->rchild, key);
        }
    }

    return root;
}

void inorder_traversal(node* root){

    if (root->lchild!=NULL){
        inorder_traversal(root->lchild);
    }

    printf("%d\t", root->data);

    if (root->rchild!=NULL){
        inorder_traversal(root->rchild);
    }
}


int main(void){

    node* root = NULL;

    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 13);

    cout<<"The inorder traversal of the tree is:\n";
    inorder_traversal(root);
    cout<<"\n\n";

    delete_node(root, 9);
    delete_node(root, 2);
    delete_node(root, 6);
    cout<<"\nAfter deleting 9, 2, 6, the inorder traversal of the tree is:\n";
    inorder_traversal(root);

    return 0;
}
