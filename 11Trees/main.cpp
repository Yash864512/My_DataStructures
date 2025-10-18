//===================================> Creating Binary tree
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node *lChild;
    int data;
    struct Node *RChild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is Full\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->front == q->rear) {
        printf("Queue is Empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

bool isEmpty(struct Queue q) {
    return q.front == q.rear;
}

// Global root node
struct Node *root = NULL;

void createTree() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter the root element: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lChild = root->RChild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);

        printf("Enter Left Child of %d (-1 for NULL): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lChild = t->RChild = NULL;
            p->lChild = t;
            enqueue(&q, t);
        }

        printf("Enter Right Child of %d (-1 for NULL): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lChild = t->RChild = NULL;
            p->RChild = t;
            enqueue(&q, t);
        }
    }
}

void preOrder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        preOrder(p->lChild);
        preOrder(p->RChild);
    }
}

void InOrder(struct Node *p) {
    if (p) {
        InOrder(p->lChild);
        printf("%d ", p->data);
        InOrder(p->RChild);
    }
}

void postOrder(struct Node *p) {
    if (p) {
        preOrder(p->lChild);
        preOrder(p->RChild);
        printf("%d ", p->data);
    }
}

int main(void) {
    createTree();
    printf("\nPreorder Traversal: ");
    preOrder(root);
    printf("\nInOrder Traversal: ");
    InOrder(root);
    printf("\nPostOrder Traversal: ");
    postOrder(root);
    printf("\n");
    return 0;
}
*/

//===============================> Binary tree using iterative approach
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x) {
    if (q->rear == q->size - 1)
        printf("Queue is Full\n");
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q) {
    return q.front == q.rear;
}

struct Stack {
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x) {
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st) {
    struct Node *x = NULL;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isStackEmpty(struct Stack st) {
    return st.top == -1;
}

struct Node *root = NULL;

void createTree() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void iterativePreorder(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100);

    while (p != NULL || !isStackEmpty(stk)) {
        if (p != NULL) {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            p = p->rchild;
        }
    }
    printf("\n");
    free(stk.S);
}

void iterativeInorder(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100);

    while (p != NULL || !isStackEmpty(stk)) {
        if (p != NULL) {
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
    free(stk.S);
}

void iterativePostorder(struct Node *p) {
    struct Stack stk;
    createStack(&stk, 100);
    intptr_t temp;

    while (p != NULL || !isStackEmpty(stk)) {
        if (p != NULL) {
            push(&stk, p);
            p = p->lchild;
        } else {
            temp = (intptr_t)pop(&stk);
            if (temp > 0) {
                push(&stk, (struct Node *)-temp);
                p = ((struct Node *)temp)->rchild;
            } else {
                printf("%d ", ((struct Node *)(-temp))->data);
                p = NULL;
            }
        }
    }
    printf("\n");
    free(stk.S);
}

int main() {
    createTree();

    printf("Iterative Preorder: ");
    iterativePreorder(root);

    printf("Iterative Inorder: ");
    iterativeInorder(root);

    printf("Iterative Postorder: ");
    iterativePostorder(root);

    return 0;
}