//============================> Implementation of Queue using 2 pointers
/*
#include <iostream>
using namespace std;
 
class Queue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
int Queue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 
void Queue::display() {
    for (int i=front+1; i<=rear; i++){
        cout << Q[i] << flush;
        if (i < rear){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q(sizeof(A)/sizeof(A[0]));
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.enqueue(A[i]);
    }
 
    // Display
    q.display();
 
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.dequeue();
    }
 
    // Underflow
    q.dequeue();
    
    return 0;
}
*/

//=============================> Circular Queue using array

#include <iostream>
using namespace std;
 
class CircularQueue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};
 
CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int [size];
}
 
CircularQueue::~CircularQueue() {
    delete [] Q;
}
 
bool CircularQueue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}
 
void CircularQueue::enqueue(int x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
 
int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
 
void CircularQueue::display() {
    int i = front + 1;
    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}
 
 
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    CircularQueue cq(sizeof(A)/sizeof(A[0]) + 1);
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
    cq.display();
    cout << endl;
    cq.enqueue(10);
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
    cq.dequeue();
    return 0;
}