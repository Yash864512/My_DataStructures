//==========================> Creating Binary Search Tree
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void insert(int key){
    struct Node *t = root;
    struct Node *r, *p;
    
    if(root==NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    
    while(t!=NULL){
        r = t;
        if(key<t->data){
            t = t->lchild;
        }else if(key>t->data){
            t = t->rchild;
        }else{
            return;
        }
    }
    
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    
    if(key<r->data) r->lchild = p;
    else r->rchild = p;
}

void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

struct Node * search(int key){
    struct Node *t = root;
    while(t){
        if(key == t->data){
            return t;
        }else if(key < t->data){
            t = t->lchild;
        }else{
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node *RInsert(struct Node *p, int key){
    if(p==NULL){
        struct Node *t = NULL;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild;
        return t;
    }
    if(key < p->data){
        p->lchild = RInsert(p->lchild, key);
    }else if(key > p->data){
        p->rchild = RInsert(p->rchild, key);
    }
    return p;
}

int main(void){
    struct Node *temp;
    int key;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    
    inOrder(root);
    printf("\n");
    printf("What is the key you want to search for? ");
    scanf("%d", &key);
    temp = search(key);
    
    if(temp) printf("\nSearching for %d..... Key found\n", key);
    else printf("\nSearching for %d..... Key not found\n", key);
}
*/

//=================================> Insert and delete Recursive functions in BST
#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}

struct Node * search(int key){
    struct Node *t = root;
    while(t){
        if(key == t->data){
            return t;
        }else if(key < t->data){
            t = t->lchild;
        }else{
            t = t->rchild;
        }
    }
    return NULL;
}

struct Node *RInsert(struct Node *p, int key){
    if(p==NULL){
        struct Node *t = NULL;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = RInsert(p->lchild, key);
    }else if(key > p->data){
        p->rchild = RInsert(p->rchild, key);
    }
    return p;
}

int Height(struct Node *p) {
    int x;
    int y;
    if (p == NULL){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node* InPre(struct Node *p) {
    while (p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}
 
struct Node* InSucc(struct Node *p) {
    while (p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

struct Node* Delete(struct Node *p, int key) {
    Node* q;
 
    if (p == NULL){
        return NULL;
    }
 
    if (p->lchild == NULL && p->rchild == NULL){
        if (p == root){
            root = NULL;
        }
        free (p);
        return NULL;
    }
 
    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main(){
    struct Node *temp;
    int key;
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);
    
    inOrder(root);
    printf("\n");
    
    printf("What is the key you want to search for? ");
    scanf("%d", &key);
    temp = search(key);
    
    if(temp) printf("\nSearching for %d..... Key found\n", key);
    else printf("\nSearching for %d..... Key not found\n", key);
    
    printf("\n");
    printf("What is the key you want to delete? ");
    scanf("%d", &key);
    Delete(root, key);
    
    inOrder(root);
    printf("\n");
}