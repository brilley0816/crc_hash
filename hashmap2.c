#include<stdio.h>
#include<stdlib.h>

typedef struct _d_node
{
  char *key;
  int value;
  struct _d_node *next;
  struct _d_node *prev;
} D_NODE;

typedef struct _d_head
{
  int used;
  D_NODE *p_next;
  D_NODE *p_prev;
} D_HEAD;


typedef struct _l_node
{
  char *key;
  int value;
  struct _l_node *next;
} L_NODE;

typedef struct _l_head
{
  int used;
  L_NODE *p_next;
} L_HEAD;

static int curr_len = 8;
static void ** p_hashmap;

void hashmap_init()
{
  p_hashmap = malloc(sizeof(void*) * curr_len);
  printf("p_hashmap = %d \n",p_hashmap);
  for (int i = 1; i < curr_len; i++)
  {
    p_hashmap[i] = NULL;
  }
  for (int i = 0; i < curr_len; i++)
  {
    printf("p_hashmap[%d] = %d\n",i, p_hashmap[i]);
  }
  printf("p_hashmap = %d \n",p_hashmap);
 
  p_hashmap[0] = malloc(sizeof(struct _d_head));
  struct _d_head *tmp = (struct _d_head*) p_hashmap[0];
  tmp->used = 10;
  for (int i = 1; i < curr_len; i++) 
  {
    p_hashmap[i] =  malloc(sizeof(struct _l_head));
    struct _l_head *p_tmp = (struct _l_head *) p_hashmap[i];
    p_tmp->used = 8;
  }
  for (int i = 0; i < curr_len; i++)
  {
    if (((struct _l_head *)p_hashmap[i])->used == 8)
    {
      printf("l_head\n");
    }
    else 
    {
      printf("d_head\n");
    }
  }

}
