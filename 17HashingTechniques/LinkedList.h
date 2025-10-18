#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// This block ensures that a C++ compiler will not mangle the names
// of the C functions, allowing main.cpp to link with LinkedList.c correctly.
#ifdef __cplusplus
extern "C" {
#endif

// --- Structure Definition ---
struct Node {
    int data;
    struct Node *next;
};

// --- Function Prototypes (Declarations) ---
// The functions now take a double pointer to the head of the list.
// This allows them to modify the head pointer directly, removing the
// need for a global variable.

/**
 * @brief Inserts an integer into its correct sorted position in the given list.
 * @param head A pointer to the head pointer of the list.
 * @param x The integer value to insert.
 */
void SortedInsert(struct Node **head, int x);

/**
 * @brief Displays the elements of a linked list.
 * @param p A pointer to the starting node of the list to display.
 */
void display(struct Node *p);

struct Node * LinearSearch(struct Node *p, int key);

#ifdef __cplusplus
}
#endif

#endif // LINKED_LIST_H
