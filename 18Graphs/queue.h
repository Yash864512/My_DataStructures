#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

/* Node structure for linked queue */
struct Node {
    int data;
    struct Node *next;
};

/* Global pointers (defined in queue.c) */
extern struct Node *front;
extern struct Node *rear;

/* Function prototypes */
void enqueue(int x);
int dequeue(void);
int isEmpty(void);

#ifdef __cplusplus
}
#endif

#endif /* QUEUE_H */
