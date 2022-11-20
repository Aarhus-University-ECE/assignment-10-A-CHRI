#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, tree_node *t)
{
    // Insert item x into the tree t

    /* Base case */
    if (t == NULL)
    {
        tree_node *new = (tree_node *)malloc(sizeof(tree_node));
        new->item = x;
        new->left = NULL;
        new->right = NULL;
        return new;
    }

    /* Recursive step */
    if (x <= t->item)
    {
        t->left = Insert(x, t->left);
    }
    else if (x > t->item)
    {
        t->right = Insert(x, t->right);
    }

    /* Return the tree */
    return t;
}

struct tree_node *Remove(int x, tree_node *t)
{
    // Remove one item from the tree t
    /* Base case */
    if (t == NULL)
        return t;

    /* Traverse left or right depending on value */
    if (x < t->item)
        t->left = Remove(x, t->left);

    else if (x > t->item)
        t->right = Remove(x, t->right);

    /* Check if the current node is the correct node */
    else
    {
        /* Case 1: No child or 1 child */
        if (t->left == NULL)
        {
            tree_node *temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == NULL)
        {
            tree_node *temp = t->left;
            free(t);
            return temp;
        }

        /* Case 2: Node with two children */
        /* Find the leftmost leaf in the right subtree*/
        tree_node *temp = t->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        t->item = temp->item;

        t->right = Remove(temp->item, t->right);
    }
    return t;
}

int Contains(int x, tree_node *t)
{
    /* If node is NULL */
    if (t == NULL)
        return 0;

    /* Traverse the tree in-order */
    if (t->item == x)
        return 1;

    if (x <= t->item)
        return Contains(x, t->left);

    if (x > t->item)
        return Contains(x, t->right);

    return 0;
}

struct tree_node *Initialize(tree_node *t)
{
    // Create an empty tree
    t = NULL;
    return t;
}

int Empty(tree_node *t)
{
    return t == NULL;
}

int Full(tree_node *t)
{
    // Test if full
    return 0;
}