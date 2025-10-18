//======================> Diagonal matrix
/*
#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int A[10];
    int n;
};

void set(struct matrix *m, int i, int j, int x){
    if(i==j){
        m->A[i-1] = x;
    }
}

int get(struct matrix *m, int i, int j){
    if(i==j){
        return m->A[i-1];
    }else{
        return 0;
    }
}
void display(struct matrix m){
    for(int i = 0; i<m.n; i++){
        for(int j = 0; j<m.n; j++){
            if(i==j){
                printf("%d ", m.A[i]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct matrix m;
    m.n=4;
    set(&m, 1, 1, 5);set(&m, 2, 2, 10);set(&m, 3, 3, 15);set(&m, 4, 4, 20);
    display(m);
}
*/

//======================> Diagonal matrix in c++
/*
#include <iostream>
using namespace std;

class matrix{
    private:
        int n;
        int *A;
    public:
        matrix(int n){
            this->n = n;
            A = new int[n];
        }
        
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~matrix(){
            delete []A;
        }
};

void matrix::set(int i, int j, int x){
    if(i==j) A[i-1] = x;
}

int matrix::get(int i, int j){
    if(i==j) cout<<A[i-1];
    else return 0;
    return 0;
}

void matrix::display(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    matrix m(4);
    m.set(1, 1, 5);m.set(2, 2, 10);m.set(3, 3, 15);m.set(4, 4, 20);
    m.display();
}
*/

//=======================> Lower trianglur matrix
/*
#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int *A;
    int n;
};

void set(struct matrix *m, int i, int j, int x){
    if(i>=j){
        m->A[i*(i-1)/2 + j-1] = x;
    }
}

int get(struct matrix *m, int i, int j){
    if(i>=j){
        return m->A[i*(i-1)/2 + j-1]; //(i*(i-1)/2 + j-1) is the formula for row major method. refer notes
    }else{
        return 0;
    }
}
void display(struct matrix m){
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i>=j){
                printf("%d ", m.A[i*(i-1)/2 + j-1]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct matrix m;
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc((m.n*(m.n+1)/2)*sizeof(int));
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i>=j){
                int num;
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &num);
                set(&m, i, j, num);
            }
        }
    }
    display(m);
}
*/

//=================================> Lower trainglur using c++
/*
#include <iostream>
using namespace std;

class matrix{
    private:
        int n;
        int *A;
    public:
        matrix(int n){
            this->n = n;
            A = new int[n];
        }
        
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~matrix(){
            delete []A;
        }
};

void matrix::set(int i, int j, int x){
    if(i>=j) A[i*(i-1)/2 + j-1] = x;
}

int matrix::get(int i, int j){
    if(i>=j) cout<<A[i*(i-1)/2 + j-1];
    else return 0;
    return 0;
}

void matrix::display(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i>=j) cout<<A[i*(i-1)/2 + j-1]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the dimension of the matrix: ";
    cin>>n;
    matrix m(n);
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i>=j){
                int num;
                cout<<"A["<<i<<"]["<<j<<"]: ";
                cin>>num;
                m.set(i, j, num);
            }
        }
    }
    m.display();
}
*/
//================================>Tri-Diagonal matrix
/*
#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int *A;
    int n;
};

void display(struct matrix m){
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i-j==0){
                printf("%d ", m.A[m.n-1+i-1]);
            }else if(i-j==1){
                printf("%d ", m.A[i-1]);
            }else if(i-j==-1){
                printf("%d ", m.A[2*(m.n)-1+i-1]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct matrix m;
    printf("What is the size of the matrix: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc((3*m.n-2)*sizeof(int));
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i-j==0){
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &m.A[m.n-1+i-1]);
            }else if(i-j==1){
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &m.A[i-1]);
            }else if(i-j==-1){
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &m.A[2*(m.n)-1+i-1]);
            }
        }
    }
    display(m);
}
*/

//================================> Toeplitz matrix
/*
#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int *A;
    int n;
};

void display(struct matrix m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            if (i <= j) {
                printf("%d ", m.A[j - i]);
            } else {
                printf("%d ", m.A[m.n + i - j - 1]);
            }
        }
        printf("\n");
    }
}

int main(){
    struct matrix m;
    printf("What is the size of the matrix: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc((2*m.n-1)*sizeof(int));
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i<=j && i==1){
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &m.A[j-i]);
            }else if(i>j && j==1){
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &m.A[m.n+i-j-1]);
            }
        }
    }
    display(m);
}
*/
//================================> Menu driven program for matrices

#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int *A;
    int n;
};

void display1(struct matrix m){
    for(int i = 0; i<m.n; i++){
        for(int j = 0; j<m.n; j++){
            if(i==j){
                printf("%d ", m.A[i]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

void display2(struct matrix m){
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i>=j){
                printf("%d ", m.A[i*(i-1)/2 + j-1]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

void display3(struct matrix m){
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(j>=i){
                printf("%d ", m.A[j*(j-1)/2 + i-1]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

void display4(struct matrix m){
    for(int i = 1; i<=m.n; i++){
        for(int j = 1; j<=m.n; j++){
            if(i-j==0){
                printf("%d ", m.A[m.n-1+i-1]);
            }else if(i-j==1){
                printf("%d ", m.A[i-1]);
            }else if(i-j==-1){
                printf("%d ", m.A[2*(m.n)-1+i-1]);
            }else printf("0 ");
        }
        printf("\n");
    }
}

void display5(struct matrix m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            if (i <= j) {
                printf("%d ", m.A[j - i]);
            } else {
                printf("%d ", m.A[m.n + i - j - 1]);
            }
        }
        printf("\n");
    }
}

int main(){
    struct matrix m;
    int ch = 0;
    do{
        printf("1. Diagonal Matrix\n2. Lower Triangular matrix\n3. Upper Triangular matrix\n4. Tri-Diagonal matrix\n5. Toeplitz matrix:\n6. Exit\n");
        printf("Enter the matrix you want to see: ");
        scanf("%d", &ch);
        while(ch>6 || ch<1){
            printf("Wrong index. Choose again: ");
            scanf("%d", &ch);
        }
        
        switch (ch){
            case 1:
                printf("Enter the dimention of the matrix: ");
                scanf("%d", &m.n);
                m.A = (int *) malloc(m.n*sizeof(int));
                printf("Enter the values:\n");
                for(int i = 1; i<=m.n; i++){
                    for(int j = 1; j<=m.n; j++){
                        if(i==j){
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &m.A[i-1]);
                        }
                    }
                }
                printf("\nDiagonal matrix: \n\n");
                display1(m);
                printf("\n");
                break;
            case 2:
                printf("Enter the dimension of the matrix: ");
                scanf("%d", &m.n);
                m.A = (int *)malloc((m.n*(m.n+1)/2)*sizeof(int));
                printf("Enter the values:\n");
                for(int i = 1; i<=m.n; i++){
                    for(int j = 1; j<=m.n; j++){
                        if(i>=j){
                            int num;
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &num);
                            m.A[i*(i-1)/2 + j-1] = num;
                        }
                    }
                }
                printf("\nLower Triangular matrix: \n\n");
                display2(m);
                printf("\n");
                break;
                
            case 3:
                printf("Enter the dimension of the matrix: ");
                scanf("%d", &m.n);
                m.A = (int *)malloc((m.n*(m.n+1)/2)*sizeof(int));
                printf("Enter the values:\n");
                for(int i = 1; i<=m.n; i++){
                    for(int j = 1; j<=m.n; j++){
                        if(j>=i){
                            int num;
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &num);
                            m.A[j*(j-1)/2 + i-1] = num;
                        }
                    }
                }
                printf("\nUpper Triangular matrix: \n\n");
                display3(m);
                printf("\n");
                break;
            case 4:
                printf("Enter the dimension of the matrix: ");
                scanf("%d", &m.n);
                m.A = (int *)malloc((3*m.n-2)*sizeof(int));
                for(int i = 1; i<=m.n; i++){
                    for(int j = 1; j<=m.n; j++){
                        if(i-j==0){
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &m.A[m.n-1+i-1]);
                        }else if(i-j==1){
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &m.A[i-1]);
                        }else if(i-j==-1){
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &m.A[2*(m.n)-1+i-1]);
                        }
                    }
                }
                printf("\nTri-Diagonal matrix: \n\n");
                display4(m);
                printf("\n");
                break;
            case 5:
                printf("Enter the dimension of the matrix: ");
                scanf("%d", &m.n);
                m.A = (int *)malloc((2*m.n-1)*sizeof(int));
                for(int i = 1; i<=m.n; i++){
                    for(int j = 1; j<=m.n; j++){
                        if(i<=j && i==1){
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &m.A[j-i]);
                        }else if(i>j && j==1){
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &m.A[m.n+i-j-1]);
                        }
                    }
                }
                printf("\nToeplitz matrix: \n\n");
                display5(m);
                printf("\n");
                break;
            case 6:
                ch=6;
                break;
        }
        
    }while(ch!=6);
}
