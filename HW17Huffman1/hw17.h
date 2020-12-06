// ***
// *** DO NOT modify this file
// ***

#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#define WORDLENGTH 10

typedef struct tnode
{
  char value;
  int code;
  struct tnode * left;
  struct tnode * right;
} TreeNode;

typedef struct trnode
{
  TreeNode * root;
} Tree;

typedef struct Node
{
  TreeNode * tnode; 
  struct Node * next;
  struct Node * prev;
} ListNode;

typedef struct
{
  ListNode * head;
  ListNode * tail;
} List;

Tree * newTree(void);
void freeTree(Tree * tr);
void deleteTreeNode(TreeNode* tr);

void deleteList(List * arithlist);
bool deleteNode(List * arithlist, ListNode * ln);

TreeNode* newTnode(char word);
int numElem(char* filename);
bool readList(char * filename, List * arithlist);
bool encodeTree(TreeNode* root, int level, int* maxlevel);
int totalPrint(TreeNode* tnode);
void chBook(TreeNode* tnode, char wantArr[], int * index);

int max(int num1, int num2);
bool hasPath(TreeNode* root, int path[], char want, int* ind);
int treeHeight(TreeNode* root);
void printPath(Tree * tr, char val);

#endif
