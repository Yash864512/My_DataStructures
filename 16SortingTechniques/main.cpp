//================================> Bubble sort
/*
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n){
    int flag = 0;
    for(int i = 0; i < n-1; i++){
        flag = 0;
        for(int j = 0; j < n-i-1; j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    BubbleSort(A, n);
}
*/

//==============================> Insertion Sort
/*
#include <stdio.h>

void InsertionSort(int A[], int n){
    int i, j, x;
    
    for(i = 1; i<n; i++){
        j = i-1;
        x = A[i];
        while(j>=0 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    InsertionSort(A, n);
}
*/

//===============================> Selection Sort
/*
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int A[], int n){
    int i, j, k;
    for(i = 0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    SelectionSort(A, n);
}
*/

//==================================> Quick Sort
/*
#include <climits>
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int PartitionMethod(int A[], int low, int high, int n){
    int pivot = A[low];
    int i = low, j = high;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        
        if(i < j) swap(&A[i], &A[j]);
        
    }while(i<j);
    
    swap(&A[low], &A[j]);
    
    return j;
}

void QuickSort(int A[], int low, int high, int n){
    int j;
    
    if(low<high){
        j = PartitionMethod(A, low, high, n);
        QuickSort(A, low, j, n);
        QuickSort(A, j+1, high, n);
    }
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT_MAX}, n = 11;
    QuickSort(A, 0, n-1, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
*/

//========================================> Merge Sort (Iterative Version)
/*
#include <stdio.h>

void Merge(int A[], int low, int mid, int high){
    int i = low, j = mid+1, k = low;
    int B[100];
    
    while(i<=mid && j<=high){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }else{
            B[k++] = A[j++];
        }
    }
    
    for(; i<=mid; i++){
        B[k++] = A[i];  
    }
    for(; j<=high; j++){
        B[k++] = A[j];
    }
    
    for(int i = low; i<=high; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int n){
    int p, l, h, mid;
    
    for(p = 2; p<=n; p = p*2){
        for(int i = 0; i+p-1 < n; i = i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
    }
    
    if(p/2<n){
        Merge(A, 0, p/2-1, n-1);
    }
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    MergeSort(A, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
}
*/

//================================> Recursive Merge Sort
/*
#include <stdio.h>

void Merge(int A[], int low, int mid, int high){
    int i = low, j = mid+1, k = low;
    int B[100];
    
    while(i<=mid && j<=high){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }else{
            B[k++] = A[j++];
        }
    }
    
    for(; i<=mid; i++){
        B[k++] = A[i];  
    }
    for(; j<=high; j++){
        B[k++] = A[j];
    }
    
    for(int i = low; i<=high; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    MergeSort(A, 0, n-1);
    
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
}
*/

//==================================> Count Sort
/*
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

int findMax(int A[], int n){
    int max = INT32_MIN;
    for(int i = 0; i<n; i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n){
    int *C, max;
    max = findMax(A, n) + 1;
    C = (int *)malloc(sizeof(int) * max);
    
    for(int i = 0; i<max; i++){
        C[i] = 0;
    }
    
    for(int j = 0; j<n; j++){
        C[A[j]]++;
    }
    
    int i=0, j=0;
    while(j<max){
        if(C[j]>0){
            A[i++] = j;
            C[j]--;
        }else{
            j++;
        }
    }
}

int main(void){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    CountSort(A, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
}
*/

//================================> Bucket/Bin sort (C++)
/*
#include <iostream>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

class Node{
public:
    int value;
    Node* next;
};
 
void Insert(Node** ptrBins, int idx){
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx]; 
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
void BinSort(int A[], int n){
    int max = Max(A, n);
 
    Node** bins = new Node* [max + 1];
 
    for (int i=0; i<max+1; i++){
        bins[i] = nullptr;
    }
 
    for (int i=0; i<n; i++){
        Insert(bins, A[i]);
    }
    
    int i = 0;
    int j = 0;
    while (i < max+1){
        while (bins[i] != nullptr){
            A[j++] = Delete(bins, i);
        }
        i++;
    }
 
    delete [] bins;
}
 
int main() {
 
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\tA");
    BinSort(A, n);
    Print(A, n, " Sorted A");
    cout << endl;
    return 0;
}
*/

//================================> Radix Sort (C++)
/*
#include <iostream>
#include <cmath>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}
 
// Linked List node
class Node{
public:
    int value;
    Node* next;
};
 
int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}
 
void initializeBins(Node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = nullptr;
    }
}
 
void Insert(Node** ptrBins, int value, int idx){
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}
 
void RadixSort(int A[], int n){
    int max = Max(A, n);
    int nPass = countDigits(max);
 
    // Create bins array
    Node** bins = new Node* [10];
 
    // Initialize bins array with nullptr
    initializeBins(bins, 10);
 
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
 
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
 
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != nullptr){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }
 
    // Delete heap memory
    delete [] bins;
}
 
int main() {
 
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\tA");
    RadixSort(A, n);
    Print(A, n, " Sorted A");
 
    return 0;
}
*/

//=================================> Shell Sort

#include <stdio.h>
#include <stdlib.h>

void ShellSort(int A[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap >= 1; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = A[i];
            j = i - gap;

            while (j >= 0 && A[j] > temp) {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    ShellSort(A, n);

    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
