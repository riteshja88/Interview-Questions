/*
 * =====================================================================================
 *
 *       Filename:  linked_list.h
 *
 *    Description:  Linked List library
 *
 *        Version:  1.0
 *        Created:  01/16/2015 05:43:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ritesh Agarwal (Omi), riteshja@yahoo-inc.com
 *        Company:  Yahoo! Inc
 *
 * =====================================================================================
 */

typedef struct node_t node_t;

void llist_init(node_t **);

void llist_add(node_t **, void *);

void llist_add_head(node_t **, void *);

void llist_add_tail(node_t **, void *);

void llist_add_priority(node_t **, void *, int (*cmp_func)(void *, void *));

uin_8 llist_count(node_t *);



