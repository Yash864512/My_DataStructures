//=======================> Stack using Arrays
/*
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("Enter the size of Stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(sizeof(int));
}

void display(struct Stack *st){
    for(int i = st->top; i>=0; i--){
        printf("%d ", st->S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x){
    if(st->top == st->size-1){
        printf("Stack Overflow\n");
    }else{
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x = -1;
    if(st->top == -1){
        printf("Stack Underflow\n");
    }else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index){
    int x = -1;
    if(st.top-index+1<0){
        printf("Invalid Index\n");
    }else{
        x = st.S[st.top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st){
    if(st.top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack st){
    return st.top == st.size-1;
}

int stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.S[st.top];
    }
    return -1;
}

int main(){
    struct Stack st;
    create(&st);
    
    push(&st, 10); //4
    push(&st, 20); //3
    push(&st, 30); //2
    push(&st, 40); //1
    push(&st, 50); //0
    push(&st, 60); //Stack Over Flowed if the size is 5
    display(&st);
    
    printf("Popped Value: %d\n", pop(&st));
    printf("Peeking the value at position 2: %d\n", peek(st, 2));
}
*/

//================================> Stack using Linked List
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(struct Node *st, int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack Overflow\n");
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(struct Node *st){
    struct Node *t;
    int x = -1;
    if(st == NULL){
        printf("Stack Underflow\n");
    }else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x; 
}

void display(){
    struct Node *p;
    p = top;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    push(top, 10);
    push(top, 20);
    push(top, 30);
    push(top, 40);
    push(top, 50);
    display();
    printf("Popped element is %d: \n", pop(top));
    display();
}
*/

//=============================> Stack using Linked List in C++
/*
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){top = NULL;}
        void push(int x);
        int pop();
        void display();
};

void Stack::push(int x){
    Node *t;
    t = new Node;
    if(t==NULL){
        cout<<"Stack Underflow"<<endl;
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop(){
    int x = -1;
    if(top==NULL){
        cout<<"Stack Underflow"<<endl;
    }else{
        Node *t;
        t = top;
        top=top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Stack::display(){
    Node *p = top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.display();
    cout<<"The popped element is "<<stk.pop()<<endl;
    stk.display();
}
*/

//=================================> Peranthasis Matching
/*
#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack Overflow\n");
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    struct Node *t;
    char x = -1;
    if(top == NULL){
        printf("Stack Underflow\n");
    }else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x; 
}

int isBalanced(char *str){
    int i;
    for(i = 0; str[i]!='\0';i++){
        if(str[i]=='('){
            push(str[i]);
        }else if(str[i]==')'){
            if(top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(top==NULL){
        return 1;
    }else return 0;
}

int main(){
    char str[] = "((a+b)*(c-d))";
    if(isBalanced(str)) printf("Balanced\n");
    else printf("Not Balanced");
}
*/

//===========================>Infix to Postfix conversion
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the stack
struct Node {
    char data;
    struct Node *next;
} *top = NULL;

// Push function
void push(char x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Stack is full\n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Pop function
char pop() {
    struct Node *t;
    char x = -1;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Check precedence of operators
int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Check if character is operand
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

// Infix to Postfix conversion
char* InToPost(char *infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (top != NULL && precedence(top->data) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }
    while (top != NULL) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[] = "a+b*c-d/e";
    push('#'); // Initial dummy value to prevent NULL dereference

    char *postfix = InToPost(infix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
*/

//======================> Infix to Postfix using STLS
/*
#include <iostream>
#include<cstring>
#include <stack>

using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};
 
Stack::Stack() {
    top = nullptr;
}
 
Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}
 
void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
 
int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}
 
int Stack::isEmpty() {
    return top ? 0 : 1;
}
 
int Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}
 
int Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;
 
        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }
 
        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}
 
 
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
}
 
int operation(char op, int x, int y){
    if (op == '+'){
        return x + y;
    } else if (op == '-'){
        return x - y;
    } else if (op == '*'){
        return x * y;
    } else if (op == '/'){
        return x / y;
    }
}
 
int postfixEvaluate(char* postfix){
    stack<int> stk;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++){
        if (isOperand(postfix[i])){
            // int typecast would not work because of char so subtract '0'
            stk.push(postfix[i]-'0');
        } else {
            y = stk.top();
            stk.pop();
            x = stk.top();
            stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.top();
    stk.pop();
    return result;
}
 
int Evaluate(char* postfix){
    Stack stk;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++){
        if (isOperand(postfix[i])){
            // int typecast would not work because of char so subtract '0'
            stk.push(postfix[i]-'0');
        } else {
            y = stk.pop();
            x = stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}
 
int main() {
 
    char postfix[] = "35*62/+4-";
    cout << Evaluate(postfix) << endl;
    cout << postfixEvaluate(postfix) << endl;
 
    return 0;
}
*/

//==========================>Evaluation of Postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    
    if (t == NULL) {
        printf("stack is full\n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;
    
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display() {
    struct Node *p = top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == NULL) {
                return 0;
            }
            pop();
        }
    }
    return (top == NULL) ? 1 : 0;
}

// Function to get the precedence of an operator
// Note: This function is not used in the postfix evaluation logic
int pre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

// Function to check if a character is an operand
// This is used for both infix-to-postfix and postfix evaluation
int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

// Infix to Postfix conversion
// Note: This function is not used in the main evaluation logic
char * InToPost(char *infix) {
    int i = 0, j = 0;
    long len = strlen(infix);
    char *postfix = (char *)malloc((len + 2) * sizeof(char));
    
    // Note: This function uses a global `top` that expects `char` data,
    // which is inconsistent with the `int` type used by `push` and `pop`
    // for evaluation. This would require code refactoring to work correctly.
    
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (pre(infix[i]) > pre(top->data)) {
                // This line would cause issues due to type mismatch
                // push(infix[i++]);
            } else {
                // This line would cause issues due to type mismatch
                // postfix[j++] = pop();
            }
        }
    }
    while (top != NULL) {
        // This line would cause issues due to type mismatch
        // postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

// Core function to evaluate a postfix expression
int Eval(char *postfix) {
    int i = 0;
    int x1, x2, r = 0;
    
    // Iterate through the postfix string
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            // If it's an operand, convert from character to integer and push to stack
            push(postfix[i] - '0');
        } else {
            // If it's an operator, pop two operands
            x2 = pop();
            x1 = pop();
            
            // Perform the operation based on the operator
            switch(postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r); // Push the result back to the stack
        }
    }
    return top->data; // The final result is the only item left on the stack
}

int main() {
    char *postfix = "234*+82/-";
    
    printf("Result is %d\n", Eval(postfix));
    
    return 0;
}