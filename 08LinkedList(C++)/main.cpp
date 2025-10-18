//====================================>Linked List and its functions using c++
/*
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *first;
public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n) { // Constructor to create linked list from array
    Node *last, *t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList() { // Destructor to free memory
    Node *p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display() { // Display all elements in the list
    Node *p = first;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length() { // Return length of the linked list
    Node *p = first;
    int len = 0;

    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x) { // Insert a new node at a given index
    Node *t, *p = first;

    if (index < 0 || index > Length())
        return;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0) {  // Insert at beginning
        t->next = first;
        first = t;
    } else {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index) { // Delete node at a given index and return its value
    Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;

    if (index == 1) {  // Delete first node
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } else {
        p = first;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    // Inserting 10 at index 3 (0-based indexing => after 3rd element)
    l.Insert(3, 10);  // List becomes: 1 2 3 10 4 5

    l.Display();  // Output: 1 2 3 10 4 5

    return 0;
}
*/
//==========================> Circular Linked List
/*
#include <iostream>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node* p);
    Node* getHead(){ return head; }
    ~CircularLinkedList();

    
};
 
CircularLinkedList::CircularLinkedList(int *A, int n) {
 
    Node* t;
    Node* tail;
 
    head = new Node;
 
    head->data = A[0];
    head->next = head;
    tail = head;
 
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}
 
void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}
 
void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}
 
CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head){
        p = p->next;
    }
 
    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }
 
    if (p == head){
        delete head;
        head = nullptr;
    }
 
}
 
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));
 
    cl.Display();
 
    Node* h = cl.getHead();
    cl.recursiveDisplay(h);
 
    return 0;
}
*/

//===================================> Inserting, Deleting and Reversing a Doubly linked list

#include <iostream>
using namespace std;
 
class Node{
public:
    Node* prev;
    int data;
    Node* next;
};
 
class DoublyLinkedList{
private:
    Node* head;
public:
    DoublyLinkedList();
    DoublyLinkedList(int A[], int n);
    ~DoublyLinkedList();
    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
    void Reverse();
};
 
 
DoublyLinkedList::DoublyLinkedList() {
    head = new Node;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}
 
DoublyLinkedList::DoublyLinkedList(int *A, int n) {
 
    head = new Node;
    head->prev = nullptr;
    head->data = A[0];
    head->next = nullptr;
    Node* tail = head;
 
    for (int i=1; i<n; i++){
        Node* t = new Node;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next; // tail->next is pointing to NULL
        tail->next = t;
        tail = t;
    }
}
 
void DoublyLinkedList::Display() {
    Node* p = head;
    while (p != nullptr){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <-> " << flush;
        }
    }
    cout << endl;
}
 
int DoublyLinkedList::Length() {
    int length = 0;
    Node* p = head;
    while (p != nullptr){
        length++;
        p = p->next;
    }
    return length;
}
 
void DoublyLinkedList::Insert(int index, int x) {
 
    if (index < 0 || index > Length()){
        return;
    }
 
    Node* p = head;
    Node* t = new Node;
    t->data = x;
 
    if (index == 0){
        t->prev = nullptr;
        t->next = head;
        head->prev = t;
        head = t;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next){
            p->next->prev = t;
        }
        p->next = t;
    }
}
 
int DoublyLinkedList::Delete(int index) {
    int x = -1;
    Node* p = head;
 
    if (index < 0 || index > Length()){
        return x;
    }
 
    if (index == 1){
        head = head->next;
        if (head){
            head->prev = nullptr;
        }
        x = p->data;
        delete p;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}
 
void DoublyLinkedList::Reverse() {
    Node* p = head;
    Node* temp;
    while (p != nullptr){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
 
        // Need to check the following condition again
        if (p->next == nullptr){
            p->next = p->prev;
            p->prev = nullptr;
            head = p;
            break;
        }
    }
}
 
DoublyLinkedList::~DoublyLinkedList() {
    Node* p = head;
    while (head){
        head = head->next;
        delete p;
        p = head;
    }
}
 
 
int main() {
 
    int A[] {1, 3, 5, 7, 9};
 
    DoublyLinkedList dll(A, sizeof(A)/sizeof(A[0]));
    cout << "Length: " << dll.Length() << endl;
 
    dll.Insert(0, 11);
    dll.Insert(6, 13);
    dll.Display();
 
    dll.Delete(1);
    dll.Delete(6);
    dll.Display();
 
    dll.Reverse();
    dll.Display();
 
    return 0;
}