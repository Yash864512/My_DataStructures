//=======================> Creating and Displaying LinkedList
/*
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p){  //Recursive display function
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

void RDisplayRev(struct Node *p){  //Reverse Recursive display function
    if(p!=NULL){
        RDisplayRev(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p){
    if(p==0){
        return 0;
    }else{
        return count(p->next) + 1;
    }
}

int sum(struct Node *p){
    if(p){
        return sum(p->next) + p->data;
    }else return 0;
}

int max(struct Node *p){
    int x = 0;
    if(p==0) return INT32_MIN;
    x = max(p->next);
    return (x>p->data)? x: p->data;
}

int main(){
    int A[] = {3, 8, 9, 12, 15, 19};
    create(A, 6);
    display(first);
    printf("\n");
    RDisplay(first);
    printf("\n");
    RDisplayRev(first);
    printf("\n");
    printf("%d\n", count(first));
    printf("%d\n", sum(first));
    printf("%d \n", max(first));
}
*/

//============================> Searching in a LinkedList
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

struct Node * LinearSearch(struct Node *p, int key){
    while(p!=NULL){
        if(key==p->data) return p;
        p=p->next;
    }
    return NULL;
}

struct Node * RLinearSearch(struct Node *p, int key){
    if(p==NULL) return NULL;
    if(key==p->data) return p;
    return RLinearSearch(p->next, key);
}

struct Node * HeadLinearSearch(struct Node *p, int key){
    struct Node *q = NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next = p->next;
            p->next=first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

int main(){
    struct Node *temp1=NULL, *temp2=NULL, *temp3=NULL;
    int A[] = {3, 8, 9, 12, 15, 19};
    create(A, 6);
    temp1 = LinearSearch(first, 15);
    temp2 = RLinearSearch(first, 15);
    temp3 = HeadLinearSearch(first, 15);
    if(temp1){
        printf("Key is found: %d\n", temp1->data);
    }else printf("Key is not found\n");
    
    if(temp2){
        printf("Key is found: %d\n", temp2->data);
    }else printf("Key is not found\n");
    
    if(temp3){
        printf("Key is found: %d\n", temp3->data);
    }else printf("Key is not found\n");
    display(first);
}

*/

//=================================> Inserting in a Linked List
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int count(struct Node *p){
    if(p==0){
        return 0;
    }else{
        return count(p->next) + 1;
    }
}

void insert(struct Node *p, int x, int index){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(index<0 || index>count(p)){
        return;
    }
    t->data = x;
    if(index==0){
        t->next=first;
        first = t;
    }else{
        for(int i = 0; i<index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next = t;
    }
}

int main(){
    int A[] = {3, 8, 9, 12, 15, 19};
    create(A, 6);
    insert(first, 100, 0);
    display(first);
}
*/

//================================> Creating Linked List using insert function
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

int count(struct Node *p){
    if(p==0){
        return 0;
    }else{
        return count(p->next) + 1;
    }
}

void insert(struct Node *p, int x, int index){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(index<0 || index>count(p)){
        return;
    }
    t->data = x;
    if(index==0){
        t->next=first;
        first = t;
    }else{
        for(int i = 0; i<index-1; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next = t;
    }
}void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    insert(first, 100, 0);
    insert(first, 200, 1);
    insert(first, 300, 2);
    insert(first, 400, 3);
    display(first);
}
*/

//====================> Inserting in a sorted linked list
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void SortedInsert(struct Node *p, int x){
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    
    if(first==NULL){
        first=t;
    }else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first) {
            t->next = first;
            first=t;
        }else{
            t->next=q->next; //t->next = p
            q->next=t;
        }
    }
}

int main(){
    int A[] = {5, 9, 15, 18, 20, 24};
    create(A, 6);
    SortedInsert(first, 4);
    display(first);
}
*/

//==================================> Deleting an element from linked list
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p){
    if(p==0){
        return 0;
    }else{
        return count(p->next) + 1;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int deleteElement(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1, i;
    if(index<1 || index>count(p)){
        return -1;
    }
    
    if(index==1){
        p = first;
        first=first->next;
        x = p->data;
        free (p);
        return x;
    }else{
        for(i = 0; i<index-1; i++){
            q = p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        free (p);
    }
    
    return x;
}

int main(){
    int A[] = {5, 9, 15, 18, 20, 24};
    create(A, 6);
    deleteElement(first, 3);
    display(first);
}
*/

//==============================> Checking weather linked list is sorted or not
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int isSorted(struct Node *p){
    int x = -65536; // Smallest number of 4 bytes integer
    while(p!=NULL){
        if(p->data < x){
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main(){
    int A[] = {5, 9, 15, 2, 20, 24};
    create(A, 6);
    display(first);
    if(isSorted(first)){
        printf("\nThe elements are sorted");
    }else{
        printf("\nThe elements are not sorted");
    }
}
*/

//================================> Deleting duplicate elements
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(int i = 1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void DeleteSort(struct Node *p){
    struct Node *q;
    q = p->next;
    
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main(){
    int A[] = {10, 20, 20, 20, 30, 40, 40, 50};
    create(A, 8);
    DeleteSort(first);
    display(first);
}
*/

//==============================> Reversing a linked list
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p) {
    int c = 0;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Reverse1(struct Node *p) { // Reverse using auxiliary array
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL) {
        A[i++] = q->data;
        q = q->next;
    }

    q = p;
    i--;
    while (q != NULL) {
        q->data = A[i--];
        q = q->next;
    }

    free(A);
}

void Reverse2(struct Node *p) { // Reverse using sliding pointers (iterative)
    struct Node *q = NULL, *r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
}

void Reverse3(struct Node *q, struct Node *p) { // Reverse using recursion
    if (p != NULL) {
        Reverse3(p, p->next);
        p->next = q;
    } else {
        first = q;
    }
}

// Main function
int main() {
    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    Reverse1(first);  // Call reverse function (can change to Reverse2 or Reverse3)
    Display(first);

    return 0;
}
*/

//=================================> Concatination and Merging of 2 linked lists
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int B[], int n) {
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void concat(struct Node *p, struct Node *q){
    third = p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = q;
}

void merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third = last = p;
        p=p->next;
        third->next = NULL;
    }else{
        third = last = q;
        q=q->next;
        third->next=NULL;
    }
    
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    if(q) last->next = q;
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    int B[] = {5, 15, 25, 35, 45};
    create2(B, 5);
    
//    concat(first, second);
    printf("Concatinated Linked List: \n");
    Display(third);
    printf("\n\n");
    
    printf("Merging 2 Linked List: \n");
    merge(first, second);
    Display(third);
    printf("\n\n");
}
*/

//=====================================> Checking weather the Linked List is looped or not
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int isLoop(struct Node *f){
    struct Node *p, *q;
    p = q = f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q; //if q=NULL then stop otherwise q is pointing to next node
    }while(p && q && p!=q);
    
    if(p==q){
        return 1;
    }else return 0;
}

int main(){
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    if(isLoop(first)) printf("This is Looped Linked List");
    else printf("This is not Looped Linked List");
}
*/

//===========================> Circular Linked List
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *Head = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;  // Point to Head
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h) { // Iterative display
    if (h == NULL) return;
    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

void RDisplay(struct Node *h) { // Recursive display
    static int flag = 0;
    if (h != Head || flag == 0) {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node *p) { // Count nodes in the circular list
    int len = 0;
    if (p == NULL) return 0;
    do {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void Insert(struct Node *p, int index, int x) { // Insert a node at a given index (0-based)
    struct Node *t;
    int i;

    if (index < 0 || index > Length(p)) return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
        } else {
            while (p->next != Head) p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    } else {
        for (i = 0; i < index - 1; i++) p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index) { // Delete a node at given index (1-based)
    struct Node *q;
    int i, x;

    if (index < 1 || index > Length(Head)) return -1;

    if (index == 1) {
        while (p->next != Head) p = p->next; // go to last node
        x = Head->data;

        if (Head == p) {  // Only one node
            free(Head);
            Head = NULL;
        } else {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    } else {
        for (i = 0; i < index - 2; i++) p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    
    RDisplay(Head); // Display the circular linked list recursively

    return 0;
}
*/
//===================> Doubly Linked List and inserting in Doubly Linked List
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *Prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int x){
    struct Node *t, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->Prev = first->next = NULL;
    last = first;
    
    for(i = 1; i<x; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->Prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct Node *p, int index, int x) {
    struct Node *t;
    if (index < 0 || index > length(p)) return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {
        t->Prev = NULL;
        t->next = first;
        if (first) first->Prev = t;
        first = t;
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        t->Prev = p;

        if (p->next) p->next->Prev = t;
        p->next = t;
    }
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    printf("Length of the Linked list is: %d\n", length(first));
    insert(first, 2, 25);
    display(first);
}
*/

//=========================> Deleting an element in Doubly Linked List
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *Prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int x){
    struct Node *t, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->Prev = first->next = NULL;
    last = first;
    
    for(i = 1; i<x; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->Prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node *p){
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

int deleteEle(struct Node *p, int index){
    int x = -1, i;
    if(index<0 || index>=length(p)) return -1;
    
    if(index == 0){
        first = first->next;
        if(first) first->Prev = NULL;
        x = p->data;
        free (p);
    }else{
        for(i = 0; i<index; i++){
            p = p->next;
        }
        p->Prev->next = p->next;
        if(p->next) p->next->Prev = p->Prev;
        
        x = p->data;
        free (p);
    }
    return x;
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    
    deleteEle(first, 1);
    display(first);
}
*/

//==========================> Reversing a doubly linked list
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *Prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int x){
    struct Node *t, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->Prev = first->next = NULL;
    last = first;
    
    for(i = 1; i<x; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->Prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void reverse(struct Node *p){
    struct Node *temp;
    
    while(p!=NULL){
        temp = p->next;
        p->next = p->Prev;
        p->Prev = temp;
        p = p->Prev;
        if(p!= NULL && p->next == NULL){
            first = p;
        }
    }
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    reverse(first);
    display(first);
}
*/

//============================>Polynomial representation using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;           
    int exp;               
    struct Node *next;    
} *poly = NULL;


void create() {
    struct Node *t, *last = NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp:\n");

    for (i = 0; i < num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;

        if (poly == NULL) {
            poly = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p) {
    while (p) {
        printf("%dx%d", p->coeff, p->exp);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x) {
    long val = 0;

    while (p) {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

// Main function
int main() {
    create();                  
    printf("Polynomial: ");
    Display(poly);               

    int x;
    printf("Enter value of x: ");
    scanf("%d", &x);

    printf("Polynomial evaluated at x = %d is %ld\n", x, Eval(poly, x));
    return 0;
}
