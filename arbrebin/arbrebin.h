#ifndef ARBREBIN_H_INCLUDED
#define ARBREBIN_H_INCLUDED

typedef struct node *Tree;
struct Node
{
    int value;
    tree left;
    tree right;
};

int isEmpty(Tree tree);
Tree left(Tree tree);
Tree right(Tree tree);
int isLeave(Tree tree);
int isInternalNode(Tree tree);
unsigned height(Tree tree);
unsigned max(unsigned a, unsigned b);
unsigned nbNode(Tree tree);
unsigned nbLeaves(Tree tree);
unsigned nbInternalNode(Tree tree);
Tree create(int val, Tree ls, Tree rs);

#endif // ARBREBIN_H_INCLUDED
