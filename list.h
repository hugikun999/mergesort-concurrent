#ifndef LLIST_H_
#define LLIST_H_

#include <stdint.h>

#define MAX_NAME_SIZE 16
typedef intptr_t val_t;

/**
 * @struct node list.h "list.h"
 * @brief The basic element of the linked list
 */
typedef struct node {
#ifdef WORD
    char *lastname;
#endif
    val_t data; /**< Data of the node */
    struct node *next;  /**< Pointer to the next node */
} node_t;

/**
 * @struct llist list.h "list.h"
 * @brief Store the information of the linked list.
 */
typedef struct {
    node_t *head;   /**< The head of the linked list */
    uint32_t size;  /**< The size of the linked list */
} llist_t;

llist_t *list_new();
int list_add(llist_t * const list, const val_t val);
int list_addc(llist_t * const list, char *lastname);
void list_print(const llist_t * const the_list);
node_t *list_get(llist_t * const the_list, const uint32_t index);
void list_free_nodes(llist_t *the_list);
val_t chartolint(char *lastname);

#endif
