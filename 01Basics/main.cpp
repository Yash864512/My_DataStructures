// Basic c and c++ for DSA
// =======================================> Arrays

/*
#include <iostream>
using namespace std;
int main()
{
    int A[5]= {5, 8, 7, 6, 3};
    for(int x: A){
        printf("%d\n", x); // We can combine both c and c++ in code
    }
    cout<< sizeof(A);
	return 0;
}
*/


// =======================================>Structures

/*
#include <iostream>
using namespace std;

struct rectangle{
        int length;
        int breadth;
};

int main(){
        struct rectangle r;
        r.length = 25;
        r.breadth = 10;
        cout<<"Length: " << r.length << endl;
        printf("Breadth: %d\n", r.breadth);
        cout<< "Area of rectangle: " << r.length*r.breadth << endl;
        
        struct rectangle r2 = {45, 10};
        cout<<"Length2: " << r2.length << endl;
        printf("Breadth2: %d\n", r2.breadth);
        cout<< "Area of rectangle: " << r2.length*r2.breadth << endl;
        return 0;
}
*/

// ===============================================> Pointers

/*
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
        printf("Creating variable pointer in stack memory\n");
        int a = 5;
        int *A;
        A = &a;
        cout<< *A << endl;
    
        printf("Creating Array pointer in stack memory\n");
        int r[5] = {2, 4, 6, 8, 10};
        int *R;
        R = r; // Shouldn't use & for addressing an array. if u want to use u can write (R = &r[0])
        for(int i=0; i<5; i++){
                cout<<R[i]<<" ";
        };
        cout<<endl;
    
        printf("Creating Array pointer in heap memory\n");
        int *p;
        int *c;
        p = (int *)malloc(5*sizeof(int)); //Syntax to create a heap memory using pointers in c
        c = new int[5]; //Syntax to create a heap memory using pointers in c++ (here 5 is used to create array of 5 int)
        p[0]=5; p[1]=10; p[2]=15; p[3]=20; p[4]=25;
        for(int i = 0; i<5; i++){
                cout<<p[i]<< " ";
        }
        cout<<endl;
        cout<< p << endl;
        cout<< c << endl;
        
        free(p); // used in c to deAllocate memory in heap that is allocated in code
        delete [] c; // used in c++ to deAllocate memory in heap that is allocated in code
        
        return 0;
}
*/

// ==========================================> Referancing

/*
#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int &r = a;
    r=15;
    cout<<a<<endl<<r<<endl;
}
*/

// ========================================> Pointer to Structure
/*
#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int main(){
    struct rectangle r = {25, 10};
    struct rectangle *p;
    p = &r;
    
    cout<< r.length << " " << r.breadth << endl;
    cout<< (*p).length << " " << (*p).breadth << endl;
    cout<< p->length << " " << p->breadth << endl;
    return 0;
}
*/

// =============================================> pointer to structure in Heap memory(Dynamic pointer)
/*
#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int main(){
    struct rectangle *p;
    p = (struct rectangle *) malloc(sizeof(struct rectangle));
    p->length=25;
    p->breadth=10;
    
    cout<<p->length<<" "<<p->breadth<<endl;
    return 0;
}
*/

// =====================================================> Functions

/*
#include <iostream>
using namespace std;

int add(int a, int b){
    int c = a + b;
    return c;
}

int main(){
    int x = 10, y = 20, z;
    z = add(x, y);
    printf("%d\n", z);
    return 0;
}
*/

// ===========================================> Parameter passing (call by address)

/*
#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 10, y = 20;
    printf("X: %d\n Y: %d\n", x, y);
    swap(&x, &y);
    printf("X: %d\n Y: %d\n", x, y); // with call by address actual values will change
    return 0;
}
*/

// ===========================================> Parameter passing (call by reference)

/*
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int x = 10, y = 20;
    printf("X: %d\n Y: %d\n", x, y);
    swap(x, y);
    printf("X: %d\n Y: %d\n", x, y); // by call by reference actual values will change
    return 0;
}
*/

// ===========================================> Array as parameter

/*
#include <iostream>
using namespace std;

void fun(int *arr, int n){
    arr[0] = 25;
}

int main(){
    int arr[5] = {0, 10, 20, 30, 40};
    fun(arr, 5);
    for(int i = 0; i<5; i++){
        printf("%d ", arr[i]);
    };
}
*/

// ============================================> Returning an Array

/*
#include <iostream>
using namespace std;

int * fun(int n){
        int *p;
        p = (int *) malloc(n*sizeof(int)); // p = new int[n]; for c++
        return p;
}

int  main(){
    int *A;
    A = fun(5);
    cout<<A<<endl;
    return 0;
    delete[] A; 
}
*/

// =========================================> Structure as parameter(Call by Value)

/*
#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void fun(struct rectangle r1){
    r1.length = 200;
    r1.breadth = 100;
    printf("Length in fun: %d\n Breadth in fun: %d\n", r1.length, r1.breadth);
}

int main(){
    struct rectangle r = {10, 20};
    fun(r);
}
*/

// =========================================> Structure as parameter(Call by address)

/*
#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void fun(struct rectangle &r1){
    r1.length = 200;
    r1.breadth = 100;
}

int main(){
    struct rectangle r = {10, 20};
    fun(r);
    printf("Length in main: %d\n Breadth in main: %d\n", r.length, r.breadth);
}
*/

// =========================================> Structure as parameter(Call by reference)

/*
#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void fun(struct rectangle *r1){
    r1->length = 200;
    r1->breadth = 100;
}

int main(){
    struct rectangle r = {10, 20};
    fun(&r);
    printf("Length in main: %d\n Breadth in main: %d\n", r.length, r.breadth);
}
*/

// =========================================> Arrays in Structure as parameter(call by address)

/*
#include <iostream>
using namespace std;

struct num{
    int arr[5];
    int n;
};

void fun(struct num &r1){
    r1.arr[0] = 50;
    r1.arr[4] = 10;
}

int main(){
    struct num r = {{10, 20, 30, 40, 50}, 5};
    fun(r);
    for(int i = 0; i<5; i++){
        printf("%d ", r.arr[i]);
    }
}
*/

// =======================================> Object created in heap using function

/*
#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

struct rectangle *fun(){
    struct rectangle *p;
    p = new rectangle;
    p->length = 100;
    p->breadth = 200;
    return p;
}

int main(){
    struct rectangle *ptr = fun();
    printf("length: %d\n Breadth: %d\n", ptr->length, ptr->breadth);
    return 0;
}
*/

// ==========================================> Code in c

/*
#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
    int length;
    int breadth;
};

void initialization(struct Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r){
    return r.length * r.breadth;
}

int changeLength(struct Rectangle *r, int l){
    return r->length = l;
}

int main(){
    struct Rectangle r;
    initialization(&r, 10, 20);
    printf("Area: %d\n", area(r));
    changeLength(&r, 30);
    printf("Area after changing length: %d\n", area(r));
    return 0;
}
*/

// ================================================> Code in c++

/*
#include <iostream>
using namespace std;

class rectangle{
    private:
        int length;
        int breadth;
    public:
        rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        
        int area(){
            return length * breadth;
        }
        
        void changeLength(int l){
            length = l;
        }
};

int main(){
    rectangle r(10, 20);
    cout<<"Area: " << r.area() << endl;
    r.changeLength(30);
    cout<<"Area after changing length: " << r.area() << endl;
    return 0;
}
*/

// ==========================================> Initializing in class, modifying outside the class

/*
#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length =0;
        int breadth =0;
    public:
        Rectangle();
        Rectangle(int l, int b);
        
        int area();
        void changeLength(int l);
};

Rectangle::Rectangle(int l, int b){
    length = l;
    breadth = b;
}

int Rectangle::area(){
    return length * breadth;
}

void Rectangle::changeLength(int l){
    length = l;
}

int main(){
    Rectangle r(10, 20);
    cout<<"Area: "<< r.area() <<endl;
    r.changeLength(30);
    cout<<"Area after changing length: "<< r.area() <<endl;
    return 0;
}
*/

// ===============================================> Template class / generic class

/*
#include <iostream>
using namespace std;

template<class T>
class Arithmetic{
    private:
        T length;
        T breadth;
    public:
        Arithmetic(T l, T b);
        T add();
        T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T l, T b){
    this->length = l;
    this->breadth = b;
}

template<class T>
T Arithmetic<T>::add(){
    return length+breadth;
}

template<class T>
T Arithmetic<T>::sub(){
    return length-breadth;
}

int main(){
    Arithmetic<int> ar1(10, 20);
    Arithmetic<float> ar2(1.2, 0.8);
    Arithmetic<double> ar3(10.854, 20.256);
    cout<<ar1.add()<<endl;
    cout<<ar1.sub()<<endl;
    cout<<ar2.add()<<endl;
    cout<<ar2.sub()<<endl;
    cout<<ar3.add()<<endl;
    cout<<ar3.sub()<<endl;
    
    return 0;
}
*/
