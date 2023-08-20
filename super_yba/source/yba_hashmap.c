#include<stdio.h>
#include<stdlib.h>

#include "yba_common.h"
#include "yba_hashmap.h"

typedef struct _d_node
{
  YBA_CHAR *key;
  YBA_UINT32 value;
  struct _d_node *next;
  struct _d_node *prev;
} D_NODE;

typedef struct _l_node
{
  YBA_CHAR *key;
  YBA_UINT32 value;
  struct _l_node *next;
} L_NODE;

typedef struct _head
{
  YBA_UINT32 used;
  L_NODE *p_l_head;
  D_NODE *p_d_head;
} HEAD;

static YBA_UINT32 curr_len = 8;
static struct _head **p_hashmap;

void hashmap_init()
{
  YBA_UINT32 i = 0;

  p_hashmap = malloc(sizeof(struct _head *) * curr_len);
  printf("p_hashmap = %d \n",p_hashmap);
  for (i = 1; i < curr_len; i++)
  {
    p_hashmap[i] = NULL;
  }
  for (i = 0; i < curr_len; i++)
  {
    printf("p_hashmap[%d] = %d\n",i, p_hashmap[i]);
  }
  printf("p_hashmap = %d \n",p_hashmap);
  for (i = 0; i < curr_len; i++) 
  {
    p_hashmap[i] =  malloc(sizeof(struct _head));
    p_hashmap[i]->used = i;
  }
  for (i = 0; i < curr_len; i++)
  {
    printf("p_hashmap[%d]->used  = %d\n",i, p_hashmap[i]->used);
    if (p_hashmap[i]->used >= 5)
    {
      p_hashmap[i]->p_l_head = malloc(sizeof(struct _l_node));
    }
    else 
    {
      p_hashmap[i]->p_d_head = malloc(sizeof(struct _d_node));
    }
  }

  for (i = 0; i < curr_len; i++)
  {
    if (p_hashmap[i]->p_l_head != NULL)
    {
      printf("p_hashmap[%d] has l_head \n",i);
    }
    else if (p_hashmap[i]->p_d_head != NULL) 
    {
      printf("p_hashmap[%d] has d_head \n",i);
    }
  }

}
