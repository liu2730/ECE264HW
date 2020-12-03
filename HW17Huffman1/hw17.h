// ***
// *** DO NOT modify this file
// ***

#ifndef TREE_H
#define TREE_H

#define WORDLENGTH 10
#include <stdbool.h>

typedef struct tnode
{
  int value;
  struct tnode * left;
  struct tnode * right;
} TreeNode;

typedef struct trnode
{
  TreeNode * root;
} Tree;

typedef struct Node
{
  char word[WORDLENGTH]; // word is a string and one element must be '\0'
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
void addNode(List * arithlist, char * word);
bool deleteNode(List * arithlist, ListNode * ln);


#endif
