#include "sort.h"

/**
 * swapper - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the linked list
 * @pre: pointer to the previous node
 * @cur: pointer to the current node
 */
void swapper(listint_t **list, listint_t *pre, listint_t *cur)
{
    if (pre->prev)
        pre->prev->next = cur;
    if (cur->next)
        cur->next->prev = pre;

    pre->next = cur->next;
    cur->prev = pre->prev;
    pre->prev = cur;
    cur->next = pre;

    if (!cur->prev)
        *list = cur;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !*list)
        return;

    listint_t *scanner, *cur, *tmp;
    int tmp_int;

    scanner = tmp = (*list)->next;

    while (scanner)
    {
        tmp = scanner->next;
        cur = scanner->prev;
        tmp_int = scanner->n;

        while (cur && cur->n > tmp_int)
        {
            swapper(list, cur, scanner);
            print_list(*list);
            cur = scanner->prev;
        }

        scanner = tmp;
    }
}
