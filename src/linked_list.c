#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q)
{
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p)
{
  node *q;
  while (p != NULL)
  {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p)
{
  /* Base case: Last element in the list (next = NULL)*/
  if (p->next == NULL)
  {
    printf("%d", p->value);
  }
  /* Recursive step: */
  else
  {
    print_list(p->next);
    printf("%d", p->value);
  }
}

int sum_squares(node *p)
{
  /* Base case: Empty node */
  if (p == NULL)
  {
    return 0;
  }
  /* Base case: Last element in the list */
  if (p->next == NULL)
  {
    return (p->value) * (p->value);
  }
  /* Recursive step: */
  else
  {
    return (p->value) * (p->value) + sum_squares(p->next);
  }
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f)
{
  /* Pre: Non-empty list */
  assert(p != NULL);

  /* Base case: Last node */
  if(p->next == NULL) {
    node * q = make_node( f(p->value), NULL);
    return q;
  }
  /* Recursive step: */
  else {
    node * q = make_node( f(p->value), NULL);
    q->next = map(p->next, f);
    return q;
  }
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
