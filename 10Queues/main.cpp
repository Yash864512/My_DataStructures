//==========================> Implementation of Queue using 2 pointers
/*
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q){
    printf("Enter the size of the queue: ");
    scanf("%d", &q->size);
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enQueue(struct Queue *q, int x){
    if(q->rear == q->size-1){
        printf("Queue Overflow\n");
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int deQueue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        printf("Queue is Empty\n");
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    for(int i = q.front+1; i<q.rear+1; i++){
        printf("%d ", q.Q[i]);
    }
}

int main(){
    struct Queue q;
    create(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    display(q);
    printf("\ndeQueued Element: %d\nElements after dequeue\n", deQueue(&q));
    display(q);
}
*/
//===========================> Circular Queue using Arrays
/*
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1;

    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    enqueue(&q, 50);
    enqueue(&q, 60);

    Display(q);

    printf("%d\n", dequeue(&q));

    return 0;
}
*/
//==================================> Implementing Queues using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enQueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is Full\n");
    }else{
        t->data = x;
        t->next = NULL;
        if(front==NULL){
            front = rear = t;
        }else{
            rear->next = t;
            rear = rear->next; //rear = t
        }
    }
}

int deQueue(){
    struct Node *t;
    int x = -1;
    if(front==NULL){
        printf("Queue is Empty\n");
    }else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void display(){
    struct Node *p = front;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    display();
    
    deQueue();
    display();
}