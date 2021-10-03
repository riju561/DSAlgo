#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorder(struct node* root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ->", root->item);
  inorder(root->right);
}

// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}


int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);
  printf("Binary Tree needs to be hard coded\nSo look at the commented tree for better understanding\n");
  /*
    Our Tree Looks Like this after inserting above elements
               1
              /  \
             /    \
            2      3
           /      / \
          /      /   \
         4     NULL   NULL
    */
    printf("Inorder traversal of Binary Tree : ");
    inorder(root);
    printf("\n");
    int c;
    printf("\n\nNow Type 1 to insert 12 in the corresponding tree : \nOR\nType 2 to delete an existing element from tree : \n");
    scanf("%d",&c);
    switch(c){
        case 1 : {
            int key=12;
            insertLeft(root->right, key);
            printf("\n\nInorder traversal after insertion: ");
            inorder(root);
            break;
        }
        case 2 : {
            root->left->left=NULL;
            printf("\n\nInorder traversal after deletion: ");
            inorder(root);
            break;
        }
    }
    return 0;
}
