#include <stdio.h>
#include <stdlib.h>
#include "arbrebin.h"

int isEmpty(Tree tree)
{
    return tree==NULL;
}

Tree left(Tree tree)
{
	if (isEmpty(tree))
		return NULL;
	else
		return tree->left;
}

Tree right(Tree tree)
{
    if (isEmpty(tree))
        return NULL;
    else
        return tree->right;
}

int isLeave(Tree tree)
{
	if (isEmpty(tree))
		return false;
	else if (isEmpty(left(tree)) && isEmpty(right(tree)))
		return true;
	else
		return false;
}

int isInternalNode(Tree tree)
{
	return !isLeave(tree);
}

unsigned height(Tree tree)
{
	if (isEmpty(tree))
		return 0;
	else
		return 1 + max(height(left(tree)), height(right(tree)));
}

unsigned max(unsigned a, unsigned b)
{
	return (a>b)? a : b ;
}

unsigned nbNode(Tree tree)
{
	if(isEmpty(T))
		return 0;
	else
		return 1 + nbNode(left(tree)) + nbNode(right(tree));
}

unsigned nbLeaves(Tree tree)
{
	if(isEmpty(tree))
		return 0;
	else if (isLeave(tree) )
		return 1;
	else
		return nbLeaves(left(tree)) + nbLeaves(right(tree));
}

unsigned nbInternalNode(Tree tree)
{
	if (isEmpty(tree))
		return 0;
	else if(isLeave(tree))
		return 0;
	else
		return 1 + nbInternalNode(left(tree)) + nbInternalNode(right(tree));
}

Tree create(int val, Tree ls, Tree rs)
{
	Tree res;

	res = malloc(sizeof(*res));

	if( res == NULL )
	{
		fprintf(stderr, "Impossible d'allouer le noeud");
		return NULL;
	}

	res->value = val;
	res->left = ls;
	res->right = rs;

	return res;
}

void addElt(Tree src, int elt)
{
	if (src == NULL )
	{
		src = create(elt, NULL, NULL);
	}
	else if (isEmpty(left(src)) )
	{
		src->left = create(elt, NULL, NULL);
	}
	else if ( IsEmpty(Right(src)) )
	{
		src->right = create(elt, NULL, NULL);
	}
	else
	{
		addElt(left(src), elt);
	}
}
