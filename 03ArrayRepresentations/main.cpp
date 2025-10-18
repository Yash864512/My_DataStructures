//=========================> Different ways to declare and access an array

/*
#include <iostream>
using namespace std;

int main(){
    int a[5];
    int b[5] = {1, 2, 3, 4, 5};
    int c[] = {1, 2, 3, 4, 5};
    int d[5] = {1, 2};
    int e[5] = {0};
    
    printf("%d \n", b[2]);
    printf("%d \n", 2[b]);
    printf("%d \n", *(b+2));
    
    for(int i = 0; i<5; i++){
        printf("%u \n", &b[i]);  // %u is used to print the address
    }
}
*/
 
//============================>Stack and Dynamic Array

/*
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    p = (int *)malloc(5*sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    
    for(int i = 0; i<5; i++){
        printf("%d ", A[i]);
    }
    
    printf("\n");
    
    for(int i = 0; i<5; i++){
        printf("%d ", p[i]);
    }
    
    free(p);
}
*/

//================================> Increasing the size of dynamic array

/*
#include <iostream>
using namespace std;

int main(){
    int *p = new int[5];
    int *q = new int[10];
    
    for(int i=0; i<5; i++){
        q[i] = p[i];
    }

    delete []p;
    p=q;
    q = NULL;  // usually the size of a dynamic array cannot be changed directly. We have to use bigger array to transfer
    
    p[0] = 10;
    p[1] = 20;
    p[2] = 30;
    p[3] = 40;
    p[4] = 50;
    p[5] = 60;
    p[6] = 70;
    p[7] = 80;
    p[8] = 90;
    p[9] = 100;
    
    for(int i =0; i<10; i++){
        printf("%d ", p[i]);
    }
    
    return 0;
}
*/

//====================================>2D array
//===============>Method1
/*
#include <iostream>
using namespace std;

int main(){
    int A[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
}
*/

//===============>Method2
/*
#include <iostream>
using namespace std;

int main(){
    int *p[3];
    p[0] = (int *)malloc(4*sizeof(int)); // In c++ u can write "p[0] = new int[4]"
    p[1] = (int *)malloc(4*sizeof(int));
    p[2] = (int *)malloc(4*sizeof(int));
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            p[i][j] = i;
        }
    }
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}
*/

//===============>Method3

/*
#include <iostream>
using namespace std;

int main(){
    int **p; //using double pointer
    p = (int **)malloc(3*sizeof(int *)); //creating array of pointers in heap
    p[0] = (int *)malloc(4*sizeof(int)); // In c++ u can write "p[0] = new int[4]"
    p[1] = (int *)malloc(4*sizeof(int));
    p[2] = (int *)malloc(4*sizeof(int));
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            p[i][j] = i;
        }
    }
    
    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}
*/