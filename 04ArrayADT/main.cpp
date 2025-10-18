//============================> Demo
/*
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array{
    int *A;
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main(){
    struct array arr;
    
    printf("Enter the size of an array: ");
    scanf("%d", &arr.size);
    
    arr.A = (int *) malloc(arr.size*(sizeof(int)));
    
    printf("How many numbers you wanted to fill in an array: ");
    scanf("%d", &arr.length);
    
    printf("Type the numbers: \n");
    for(int i=0; i<arr.length;i++){
        scanf("%d", &arr.A[i]);
    }
    
    display(arr);
}
*/

//===========================================> Append & Insert opeartions

/*
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void append(struct array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length] = x;
    }
    arr->length++;
}

void insert(struct array *arr, int index, int x){
    if(index>=0 && index<arr->size){
        for(int i = arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main(){
    struct array arr = {{5, 10, 15, 20, 25},10, 5};
    display(arr);
    append(&arr, 30);
    display(arr);
    insert(&arr, 2, 100);
    display(arr);
}
*/

//==================================> Delete operation
/*
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void del(struct array *arr, int index){
    if(index<arr->length && index>=0){
        for(int i = index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

int main(){
    struct array arr = {{5, 10, 15, 20, 25}, 10, 5};
    display(arr);
    del(&arr, 2);
    display(arr);
}
*/

//==============================> Linear Search
/*
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

int LinearSearch(struct array *arr, int x){
    for(int i = 0; i<arr->length; i++){
        if(arr->A[i] == x){
            swap(&arr->A[i], &arr->A[i-1]); // Swapping found element with preceding element
//            swap(&arr->A[i], &arr->A[0]); // Swapping found element with zero index
            return i;
        }
    }
    return -1;
}

int main(){
    struct array arr = {{2, 4, 6, 8, 10}, 10, 5};
    display(arr);
    printf("Element found at: %d index\n", LinearSearch(&arr, 8));
    display(arr);
    
    return 0;
}
*/

//===================================> Binary search
/*
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int BinarySearch(struct array arr, int key){
    int l = 0;
    int h = arr.length-1;
    int mid;
    
    while(l<=h){
        mid = (l+h)/2;
        if(key==arr.A[mid]) return mid;
        else if(key<arr.A[mid]){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int RBinarySearch(struct array arr, int l, int h, int key){ // Binary search with recursion
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key==arr.A[mid]) return mid;
        else if(key<arr.A[mid]) return RBinarySearch(arr, l, mid-1, key);
        else return RBinarySearch(arr, mid+1, h, key);
    }
    return -1;
}

int main(){
    struct array arr = {{2, 4, 6, 8, 10}, 10, 5};
    printf("Element found at: %d", BinarySearch(arr, 8));
    printf("Element found at: %d", RBinarySearch(arr, 0, 5, 10));
    return 0;
}
*/

//=======================================> Get, Set, Max, Min, Sum, Avg operations
/*
#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int size;
    int length;
};

int get(struct array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

int set(struct array *arr, int index, int value){
    if(index>=0 && index<arr->length){
        arr->A[index] = value;
        printf("Array after setting the value is: ");
        for(int i = 0; i<arr->length; i++){
            printf("%d ", arr->A[i]);
        }
        printf("\n");
    }
    return -1;
}

int max(struct array arr){
    int max = arr.A[0];
    for(int i = 1; i<arr.length; i++){
        if(max<arr.A[i]){
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct array arr){
    int min = arr.A[0];
    for(int i = 1; i<arr.length; i++){
        if(min>arr.A[i]){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct array arr){
    int sum = 0;
    for(int i = 0; i<arr.length; i++){
        sum+=arr.A[i];
    }
    return sum;
}

float avg(struct array arr){
    return (float) sum(arr) / arr.length;
}

int main(){
    struct array arr = {{2, 4, 6, 8, 10}, 10, 5};
    printf("Element at index 3 is: %d\n", get(arr, 3));
    set(&arr, 2, 100);
    printf("Maximum element in the array is: %d\n", max(arr));
    printf("Minimum element in the array is: %d\n", min(arr));
    printf("Sum of all the elements in an array: %d\n", sum(arr));
    printf("Average of all the elements in an array: %f\n", avg(arr));
    
    return 0;
}
*/

//========================================> Reversing an array
/*
#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void reverse(struct array *arr){
    int *B;
    int i, j;
    B = (int *)malloc(arr->length*sizeof(int));
    
    for(i = 0, j = arr->length-1; j>=0; i++, j--){
        B[i] = arr->A[j];
    }
    for(i = 0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
}

void swapping(struct array *arr){
    int i = 0;
    int j = arr->length-1;
    
    for(int k = 0; k<arr->length/2; k++){
        if(i<j){
        int temp;
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        i++;
        j--;
        }
    }
}

int main(){
    struct array arr = {{2, 3, 4, 5, 6, 7}, 10, 6};
    swapping(&arr);
    display(arr);
    return 0;
}
*/

//======================================> Left shifting of an array
/*
#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void leftShift(struct array *arr){
    int a = arr->A[0];
    
    for(int i = 0, j = 1; i<arr->length-1; i++, j++){
        arr->A[i] = arr->A[j];
    }
    arr->A[arr->length-1] = a;
}

int main(){
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    leftShift(&arr);
    display(arr);
    
    return 0;
}
*/

//====================================> Inserting an element in sorted array, Checking is the array is sorted or not
//====================================> Negative numbers on left side
/*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void insertSort(struct array *arr, int x){
    int i = arr->length-1;
    if(arr->length>=arr->size) return;
    
    while(i>=0 && arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

bool isSorted(struct array arr){
    int i = arr.length-1;
    int j = 0;
    
    while(j<i){
        if(arr.A[j]>arr.A[j+1]){
            return false;
        }
        j++;
    }
    return true;
}

void negativeCheck(struct array *arr1){
    int i = 0;
    int j = arr1->length-1;
    
    while(i<j){
        while(arr1->A[i] < 0) i++;
        while(arr1->A[j] > 0) j--;
        int temp;
        temp = arr1->A[i];
        arr1->A[i] = arr1->A[j];
        arr1->A[j] = temp;
    }
}

int main(){
    struct array arr = {{2, 5, 9, 15, 20}, 10, 5};
    struct array arr1 = {{-2, 5, -1, 0, 6, 9}, 10, 6};
    insertSort(&arr, 16);
    display(arr);
    std::cout<<isSorted(arr)<<std::endl;
    negativeCheck(&arr1);
    display(arr1);
    return 0;
}
*/

//==============================> Merging two sorted arrays
/*
#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

struct array *mergeArrays(struct array arr1, struct array arr2){
    int i, j, k;
    i=j=k=0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    
    while (i < arr1.length) {
        arr3->A[k++] = arr1.A[i++];
    }

    while (j < arr2.length) {
        arr3->A[k++] = arr2.A[j++];
    }
    
    arr3->length = arr1.length+arr2.length;
    arr3->size = arr1.size+arr2.size;
    return arr3;
}

int main(){
    struct array arr1 = {{2, 8, 15, 19, 24}, 10, 5};
    struct array arr2 = {{4, 9, 14, 20, 22}, 10, 5};
    struct array *arr3;
    arr3 = mergeArrays(arr1, arr2);
    display(*arr3);
    
    return 0;
}
*/

//==============================> Union, Intersection and Difference of 2 arrays
/*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct array{
    int A[10];
    int size;
    int length;
};

void display(struct array arr){
    printf("Array elements are: \n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

struct array *ArrayUnion(struct array arr1, struct array arr2){
    int i, j, k;
    i=j=k=0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }else if(arr2.A[j]<arr1.A[i]){
            arr3->A[k++] = arr2.A[j++];
        }else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    
    while (i < arr1.length) {
        arr3->A[k++] = arr1.A[i++];
    }

    while (j < arr2.length) {
        arr3->A[k++] = arr2.A[j++];
    }
    
    arr3->length = k;
    arr3->size = arr1.size+arr2.size;
    return arr3;
}

struct array *ArrayIntersection(struct array arr1, struct array arr2){
    int i, j, k;
    i=j=k=0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            i++;
        }else if(arr2.A[j]<arr1.A[i]){
            j++;
        }else if(arr1.A[i] == arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    
    arr3->length = k;
    arr3->size = arr1.size+arr2.size;
    return arr3;
}

struct array *ArrayDifference(struct array arr1, struct array arr2){
    int i, j, k;
    i=j=k=0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }else if(arr2.A[j]<arr1.A[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    
    while (i < arr1.length) {
        arr3->A[k++] = arr1.A[i++];
    }
    
    arr3->length = k;
    arr3->size = arr1.size+arr2.size;
    return arr3;
}

int main(){
    struct array arr1 = {{2, 8, 15, 19, 22}, 10, 5};
    struct array arr2 = {{4, 8, 14, 19, 24}, 10, 5};
    struct array *arr3;
    printf("Union ");
    arr3 = ArrayUnion(arr1, arr2);
    display(*arr3);
    printf("Interseting ");
    arr3 = ArrayIntersection(arr1, arr2);
    display(*arr3);
    printf("Difference ");
    arr3 = ArrayDifference(arr1, arr2);
    display(*arr3);
    
    return 0;
}
*/

//==========================> Finding single missing number in an series array
/*
#include <stdio.h>

void SingleMissing1(int arr[]){ // To find missing number if the array numbers starting from 1
    int sum = (10*(10+1))/2;
    int realSum = 0;
    for(int i = 0; i<10; i++){
        realSum += arr[i];
    }
    printf("The missing number is: %d\n", sum-realSum);
}

void SingleMissing2(int arr[]){ //// To find missing number if the array numbers starting from some random number
    int diff = arr[0] - 0;
    for(int i = 0; i<10; i++){
        if(arr[i]-i != diff){
            printf("The missing number is: %d", arr[i]-1);
            return;
        }
    }
}

int main(){
    
    int arr[10] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int arr2[10] = {6, 7, 8, 9, 11, 12, 13, 14, 15};
    SingleMissing1(arr);
    SingleMissing2(arr2);
}
*/

//======================================> Finding multiple missing numbers in an series array
/*
#include <stdio.h>
void MultipleMissing(int arr[]){ // To find missing number if the array numbers starting from some random number
    int diff = arr[0] - 0;
    printf("Elements missing are: ");
    for(int i = 0; i<10; i++){
        if(arr[i]-i != diff){
            while(diff<arr[i]-i){
                printf("%d ", diff+i);
                diff++;
            }
        }
    }
}

int main(){
    int arr2[10] = {6, 7, 8, 9, 11, 12, 15};
    MultipleMissing(arr2);
}
*/

//=====================================>Finding missing elements in unsorted array using hashmap
/*
#include <stdio.h>
#include <stdlib.h>

void hashMap(int arr[], int arr2[]){
    for(int i = 0; i<12; i++){
        arr2[arr[i]]++;
    }
    printf("Elements missing are: ");
    for(int i = 1; i<12; i++){
        if(arr2[i] == 0){
            printf("%d ", i);
        }
    }
}

int main(){
    int arr[12] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int arr2[12] = {0};
    
    hashMap(arr, arr2);
}
*/

//=======================================> Finding duplicate values and counting no of times it occured
/*
#include <stdio.h>
#include <stdlib.h>

void countValues(int arr[]){
    for(int i = 0; i<10; i++){
        if(arr[i] == arr[i+1]){
            int j = i+1;
            while(arr[j] == arr[i]) j++;
            printf("%d appeared %d times\n", arr[i], j-i);
            i=j-1;
        }
    }
}

int main(){
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    countValues(arr);
    
    return 0;
}
*/

//=======================================> Finding duplicate values and counting no of times it occured using hashmap
/*
#include <stdio.h>
#include <stdlib.h>

void countValues(int arr[], int h[]){
    for(int i=0; i<10; i++){
        h[arr[i]]++;
    }
    
    for(int i=0; i<20; i++){
        if(h[i]>1){
            printf("%d appeared %d times\n", i, h[i]);
        }
    }
}

int main(){
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int h[20] = {0};
    countValues(arr, h);
    
    return 0;
}
*/

//=================================> Finding duplicate values and counting no of times it occured in unsorted array
/*
#include <stdio.h>
#include <stdlib.h>

void unSortedDuplicates(int arr[]){
    for(int i=0; i<9; i++){
        int count = 1;
        if(arr[i] != -1){
            for(int j=i+1; j<10; j++){
                if(arr[i] == arr[j]){
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if(count>1){
            printf("%d appeared %d times\n", arr[i], count);
        }
    }
}

int main(){
    int arr[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    unSortedDuplicates(arr);
}
*/

//===================> Finding duplicate values and counting no of times it occured in unsorted array using hashmap
/*
#include <stdio.h>
#include <stdlib.h>

void unSortedDuplicates(int arr[], int h[]){
    for(int i = 0; i<10; i++){
        h[arr[i]]++;
    }
    
    for(int i = 0; i<10; i++){
        if(h[i] > 1){
            printf("%d appeared %d times\n", i, h[i]);
        }
    }
}

int main(){
    int arr[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int h[10] = {0};
    unSortedDuplicates(arr, h);
}
*/

//=====================> Finding a pair with sum K(a+b=k)
/*
#include <stdio.h>
#include <stdlib.h>

void sumPair(int arr[]){
    for(int i = 0; i<9; i++){
        for(int j = i+1; j<10; j++){
            if(arr[i]+arr[j]==10){
                printf("%d + %d = %d\n", arr[i], arr[j], 10);
            }
        }
    }
}

int main(){
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    sumPair(arr);
}
*/

//========================> Finding a pair with sum K(a+b=k) using hashmap
/*
#include <stdio.h>
#include <stdlib.h>

void sumPair(int arr[], int h[]){
    for(int i = 0; i<10; i++){
        if(h[10-arr[i]] != 0 && 10-arr[i]>0){
            printf("%d + %d = %d\n", arr[i], 10-arr[i], 10);
        }
        h[arr[i]]++;
    }
}

int main(){
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int h[16] = {0};
    sumPair(arr, h);
}
*/

//=========================> Finding a pair with sum K(a+b=k) in sorted array
/*
#include <stdio.h>
#include <stdlib.h>

void sumPair(int arr[]){
    int i = 0;
    int j = 9;
    int sum = 10;
    while(i<j){
        if(arr[i] + arr[j] == sum){
            printf("%d + %d = %d\n", arr[i], arr[j], sum);
            i++;
            j--;
        }else if(arr[i] + arr[j] > sum){
            j--;
        }else i++;
    }
}

int main(){
    int arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    sumPair(arr);
}
*/

//===========================> Finding min and max in single scan

#include<stdio.h>
#include<stdlib.h>

void MinMaxScan(int arr[]){
    int min = arr[0];
    int max = arr[0];
    
    for(int i = 1; i<10; i++){
        if(arr[i] < min){
            min = arr[i];
        }else if(arr[i] > max){
            max = arr[i];
        }
    }
    
    printf("Max: %d\n Min: %d\n", max, min);
}

int main(){
    int arr[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    MinMaxScan(arr);
    
    return 0;
}