#include "LinkedList.h" // Include the header to connect declarations to definitions.

// --- Function Definitions (Implementations) ---
// NO MORE GLOBAL VARIABLE.

/**
 * @brief Inserts an integer into its correct sorted position in the given list.
 * @param head A pointer to the head pointer of the list (e.g., &HT[index]).
 * @param x The integer value to insert.
 */
void SortedInsert(struct Node **head, int x) {
    struct Node *t, *q = NULL;
    // p now points to the actual head of the specific list we're working with.
    struct Node *p = *head;

    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) { // Always check if malloc was successful
        return;
    }
    t->data = x;
    t->next = NULL;

    // Case 1: The list for this hash index is currently empty.
    if (*head == NULL) {
        *head = t;
    } else {
        // Traverse the list to find the correct insertion point.
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        // Case 2: Insert at the beginning of the list.
        if (p == *head) {
            t->next = *head;
            *head = t;
        } else {
            // Case 3: Insert in the middle or at the end of the list.
            t->next = q->next;
            q->next = t;
        }
    }
}

/**
 * @brief Displays the elements of the linked list.
 */
void display(struct Node *p) {
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct Node * LinearSearch(struct Node *p, int key){
    while(p!=NULL){
        if(key==p->data) return p;
        p=p->next;
    }
    return NULL;
}
