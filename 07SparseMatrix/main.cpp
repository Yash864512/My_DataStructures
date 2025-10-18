//===========================> Sparce matrix using c
/*
#include <stdio.h>
#include <stdlib.h>

struct element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct element *ele;
};

void create(struct Sparse *s){
    printf("Enter the dimensions of the matrix: \nM: ");
    scanf("%d", &s->m);
    printf("N: ");
    scanf("%d", &s->n);
    printf("Enter the no of non-zero elements: ");
    scanf("%d", &s->num);
    s->ele = (struct element *)malloc(s->num*sizeof(struct element));
    
    printf("Enter all row, col, num of non-zero elements: \n");
    for(int i= 0; i<s->num; i++){
        printf("Element %d: \n", i+1);
        printf("Row: ");
        scanf("%d", &s->ele[i].i);
        printf("Column: ");
        scanf("%d", &s->ele[i].j);
        printf("Num: ");
        scanf("%d", &s->ele[i].x);
    }
}

void display(struct Sparse s){
    int i, j, k=0;
    for(i=0; i<s.m; i++){
        for(j=0; j<s.n; j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                printf("%d ", s.ele[k++].x);
            }else printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct Sparse s;
    create(&s);
    display(s);
}
*/

//=================================> Addition of two sparse matrices
/*
#include <stdio.h>
#include <stdlib.h>

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s) {
    int i;

    printf("Enter Dimensions (rows columns): ");
    scanf("%d%d", &s->m, &s->n);

    printf("Number of non-zero elements: ");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    printf("Enter non-zero elements (row column value):\n");
    for (i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

void display(struct Sparse s) {
    int i, j, k = 0;

    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if (k < s.num && s.ele[k].i == i && s.ele[k].j == j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2) {
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if (s1->m != s2->m || s1->n != s2->n)
        return NULL;

    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num) {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }

    while (i < s1->num)
        sum->ele[k++] = s1->ele[i++];
    while (j < s2->num)
        sum->ele[k++] = s2->ele[j++];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main() {
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    if (s3 == NULL) {
        printf("Matrix dimensions do not match for addition.\n");
        return 1;
    }

    printf("\nFirst Matrix:\n");
    display(s1);

    printf("Second Matrix:\n");
    display(s2);

    printf("Sum Matrix:\n");
    display(*s3);

    // Free memory
    free(s1.ele);
    free(s2.ele);
    free(s3->ele);
    free(s3);

    return 0;
}
*/

//==========================> Polynomial representation and adding two polynomials

#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
};

struct Poly {
    int n;
    struct Term *terms;
};

void create(struct Poly *p) {
    int i;
    printf("Number of terms? ");
    scanf("%d", &p->n);
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter terms in descending order of exponents (coeff exp):\n");
    for (i = 0; i < p->n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p) {
    int i;
    for (i = 0; i < p.n; i++) {
        printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i != p.n - 1)
            printf(" + ");
    }
    printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2) {
    int i = 0, j = 0, k = 0;
    struct Poly *sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    while (i < p1->n && j < p2->n) {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    // Copy remaining terms
    while (i < p1->n)
        sum->terms[k++] = p1->terms[i++];
    while (j < p2->n)
        sum->terms[k++] = p2->terms[j++];

    sum->n = k;
    return sum;
}

int main() {
    struct Poly p1, p2, *p3;

    printf("Enter the first polynomial:\n");
    create(&p1);

    printf("Enter the second polynomial:\n");
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    printf("Sum Polynomial: ");
    display(*p3);

    // Free memory
    free(p1.terms);
    free(p2.terms);
    free(p3->terms);
    free(p3);

    return 0;
}
