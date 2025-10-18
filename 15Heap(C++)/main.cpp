//====================================> Create Heap Using STL Vector
/*
#include <iostream>
#include <vector>
using namespace std;
 
void Insert(vector<int>& vec, int key){
    // Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);
 
    // Rearrange elements: O(log n)
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}
 
void InsertInplace(int A[], int n){
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}
 
void CreateHeap(vector<int>& vec, int A[], int n){
    // O(n log n)
    for (int i=0; i<n; i++){
        Insert(vec, A[i]);
    }
}
 
void createHeap(int A[], int n){
    for (int i=0; i<n; i++){
        InsertInplace(A, i);
    }
}
 
template <class T>
void Print(T& vec, int n, char c){
    cout << c << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
 
int main() {
 
    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    Print(b, sizeof(b)/sizeof(b[0]), 'b');
 
    vector<int> v;
    CreateHeap(v, b, sizeof(b)/sizeof(b[0]));
    Print(v, v.size(), 'v');
 
    cout << "Inplace Insert" << endl;
    createHeap(b, sizeof(b)/sizeof(b[0]));
    Print(b, sizeof(b)/sizeof(b[0]), 'b');
 
 
    return 0;
}
*/

//==================================> Heap Sort
/*
#include <stdio.h>
void Insert(int A[], int n) 
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2]) 
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int Delete(int A[], int n) 
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val; // Places the max element at the end
    i = 1;
    j = i * 2;
    
    while (j <= n - 1) 
    {
        // Compare left and right child to find the larger one
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        
        // If parent is smaller than the larger child, swap them
        if (A[i] < A[j]) 
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } 
        else 
        {
            break;
        }
    }
    return val;
}

int main() 
{
    // Index 0 is ignored to facilitate 1-based indexing for the heap
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    
    // Build Max Heap
    for (i = 2; i <= 7; i++)
        Insert(H, i);
    
    // Perform Heap Sort
    for (i = 7; i > 1; i--) 
    {
        Delete(H, i);
    }
    
    // Print Sorted Array
    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");
    
    return 0;
}
*/
//==================================> Heapify - Faster Method for creating Heap
/*
#include <iostream>
using namespace std;
 
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
int Delete(int A[], int n){
    int x = A[0];  // Max element
    A[0] = A[n-1];
 
    int i = 0;
    int j = 2 * i + 1;
 
    while (j < n-1){
        // Compare left and right children
        if (A[j] < A[j+1]){
            j = j+1;
        }
 
        // Compare parent and largest child
        if (A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    return x;
}
 
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}
 
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
 
int main() {
 
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A)/sizeof(A[0]), "A");
 
    Heapify(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]), "Heapified A");
    cout << endl;
 
    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B)/sizeof(B[0]), "B");
 
    Heapify(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");
 
    return 0;
}
*/
