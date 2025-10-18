//================================> (Tail Recursion) First function is printing value of n and calling itself

/*#include <iostream>

void fun(int n){
    if(n>0){
        printf("%d ", n);
        fun(n-1);
    };
}

int main(){
    int n = 3;
    fun(n);
}
*/

//================================> (Head Recursion) First function is calling itself and printing value of n

/*
#include <iostream>

void fun(int n){
    if(n>0){
        fun(n-1);
        printf("%d ", n); // Observe that by just interchanging these 2 lines output differs
    };
}

int main(){
    int n = 3;
    fun(n);
}
*/

// ===============================> Returning function and adding constant

/*
#include <iostream>

int fun(int n){
    if(n>0){
        return fun(n-1) + n;
    };
    return 0;
}

int main(){
    int a = 5;
    printf("%d ", fun(a));
}
*/

// ===============================> Returning function and adding static variable

/*
#include <iostream>

int fun(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun(n-1) + x;
    };
    return 0;
}

int main(){
    int a = 5;
    printf("%d ", fun(a));
}
*/

// ==================================> Tree Recursion

/*
#include <iostream>
using namespace std;

void fun(int n){
    if(n>0){
        printf("%d ", n);
        fun(n-1);
        fun(n-1);
    }
}

int main(){
    fun(3);
    return 0;
}
*/

//===================================> Indirect Recursion

/*
#include <iostream>
using namespace std;

void funB(int n);

void funA(int n){
    if(n>0){
        printf("%d ", n);
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){
        printf("%d ", n);
        funA(n/2);
    }
}

int main(){
    funA(20);
    return 0;
}
*/

//===================================> Nested recursion

/*
#include <iostream>
using namespace std;

int fun(int n){
    if(n>100)
        return n -10;
    else
        return fun(fun(n+11));
}

int main(){
    printf("%d ", fun(95));
}
*/

//======================================> Sum of n natural numbers using recursion

/*
#include <iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }else{
        return sum(n-1)+n;
    }
}

int main(){
    int num {100};
    printf("%d", sum(num));
}
*/

//=================================> Factorial of n numbers

/*
#include <iostream>
using namespace std;

int fact(int n){
    if(n==0 || n ==1){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}

int main(){
    int num {0};
    printf("%d", fact(num));
}
*/

//================================> Exponents using recursion

/*
#include <iostream>
using namespace std;

int exp(int m, int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return exp(m*m, n/2);
    }else{
        return m*exp(m*m, (n-1)/2);
    }
}

int main(){
    int num = 2, pow = 9;
    printf("%d", exp(num, pow));
}
*/

//===================================> Taylor series using recursion

/*
#include <iostream>
using namespace std;

double e(int x, int n){
    static double p = 1, f = 1;
    double r;
    
    if(n==0){
            return 1;
    }
    r = e(x, n-1);
    p = p*x;
    f = f*n;
    return r+p/f;
}

int main(){
    int x = 1, n = 10; // Increase value of n for more accurate value of e
    printf("%lf \n", e(x, n));
}
*/

//===================================> Taylor series(with horner's rule) using recursion

/*
#include <iostream>
using namespace std;

double e(int x, int n){
    static double s;
    if(n==0){
        return s;
    }
    s=1+x*s/n;
    return e(x, n-1);
}

int main(){
    printf("%lf \n", e(1, 10));
}
*/

//=================================>Taylor series using normal coding

/*
#include <iostream>
using namespace std;

double e(int x, int n){
    double s = 1;
    int i;
    double num=1;
    double den = 1;
    
    for(i = 1; i<=n; i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

int main(){
    printf("%lf \n", e(1, 10));
}
*/

//===============================>Fibonocci Series using iteration, recursion, memoization

/*
#include <iostream>
using namespace std;

int fib(int n){
    int f0 = 0, f1 = 1, s = 0, i;
    
    if(n<=1){
        return n;
    }
    
    for(i=2; i<=n; i++){   // Fibonocci Series using iteration(time complexity O(n))
        s = f0+f1;
        f0 = f1;
        f1 = s;
    }
    
    return s;
}

int rfib(int n){
    if(n<=1) return n;
    
    return rfib(n-2) + rfib(n-1);  // Fibonocci Series using Recursion(time complexity O(2^n))
}


int f[10];
int mfib(int n){
    if(n<=1){
        f[n] = n;
        return n;
    }
    
    if(f[n-2] == -1){
        f[n-2] = mfib(n-2);
    }
    if(f[n-1] == -1){
        f[n-1] = mfib(n-1);
    }
    
    return f[n-2] + f[n-1];  // Fibonocci Series using memoization(time complexity O(n))
}

int main(){
    for(int i =0; i<10; i++){
        f[i] = -1;
    }
    
    printf("%d \n", fib(6));
    printf("%d \n", rfib(6));
    printf("%d \n", mfib(6));
}
*/

//=========================================> nCr using recursion

/*
#include <iostream>
using namespace std;

int fact(int n){
    if(n==0) return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r){
    int num, den;
    num = fact(n);
    den = fact(r)*fact(n-r);
    return num/den;
}

int NCR(int n, int r){
    if(r==n || r==0) return 1;
    return NCR(n-1, r-1)+NCR(n-1, r);   // Recursion in nCr using pascals triangle
}

int main(){
    printf("%d \n", nCr(4, 3));
    printf("%d \n", NCR(4, 3));
}
*/

//==========================================> Tower of hanoi using recursion

/*
#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C){
    if(n>0){
        TOH(n-1, A, C, B);
        printf("(%d,%d) \n", A, C);
        TOH(n-1, B, A, C);
    }
}

int main(){
    TOH(3, 1, 2, 3);  // A, B, C are the sticks where we can place the disc
}
*/