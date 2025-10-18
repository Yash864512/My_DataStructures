//=================================> Menu driven programme for arrays

#include <stdio.h>
#include <stdlib.h>
using namespace std;

class array{
    private:
        int *A;
        int size;
        int length;
        void swap(int *a, int *b);
    public:
        array(){
            size = 10;
            length = 0;
            A = new int(size);
        }
        array(int sz){
            size = sz;
            length = 0;
            A = new int(size);
        }
        ~array(){
            delete []A;
        }
        
        void display();
        void append(int x);
        void insert(int index, int x);
        void del(int index);
        int LinearSearch(int x);
        int BinarySearch(int key);
        int get(int index);
        int set(int index, int value);
        int max();
        int min();
        int sum();
        float avg();
        void reverse();
        void swapping();
        void leftShift();
        void insertSort(int x);
        bool isSorted();
        void negativeCheck();
        array *mergeArrays(array arr2);
        array *ArrayUnion(array arr2);
        array *ArrayIntersection(array arr2);
        array *ArrayDifference(array arr2);

};

void array::display(){
    printf("Array elements are: \n");
    for(int i=0; i<length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void array::append(int x){
    if(length<size){
        A[length] = x;
    }
    length++;
}

void array::insert(int index, int x){
    if(index>=0 && index<size){
        for(int i = length; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

void array::del(int index){
    if(index<length && index>=0){
        for(int i = index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
    }
}

void array::swap(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}



int array::LinearSearch(int x){
    for(int i = 0; i<length; i++){
        if(A[i] == x){
            swap(&A[i], &A[i-1]); // Swapping found element with preceding element
//            swap(&arr->A[i], &arr->A[0]); // Swapping found element with zero index
            return i;
        }
    }
    return -1;
}

int array::BinarySearch(int key){
    int l = 0;
    int h = length-1;
    int mid;
    
    while(l<=h){
        mid = (l+h)/2;
        if(key==A[mid]) return mid;
        else if(key<A[mid]){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int array::get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}

int array::set(int index, int value){
    if(index>=0 && index<length){
        A[index] = value;
        printf("Array after setting the value is: ");
        for(int i = 0; i<length; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    return -1;
}

int array::max(){
    int max = A[0];
    for(int i = 1; i<length; i++){
        if(max<A[i]){
            max = A[i];
        }
    }
    return max;
}

int array::min(){
    int min = A[0];
    for(int i = 1; i<length; i++){
        if(min>A[i]){
            min = A[i];
        }
    }
    return min;
}

int array::sum(){
    int sum = 0;
    for(int i = 0; i<length; i++){
        sum+=A[i];
    }
    return sum;
}

float array::avg(){
    return (float) sum() / length;
}

void array::reverse(){
    int *B;
    int i, j;
    B = new int[length];
    
    for(i = 0, j = length-1; j>=0; i++, j--){
        B[i] = A[j];
    }
    for(i = 0; i<length; i++){
        A[i] = B[i];
    }
}

void array::swapping(){
    int i = 0;
    int j = length-1;
    
    for(int k = 0; k<length/2; k++){
        if(i<j){
        int temp;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
        }
    }
}

void array::leftShift(){
    int a = A[0];
    
    for(int i = 0, j = 1; i<length-1; i++, j++){
        A[i] = A[j];
    }
    A[length-1] = a;
}

void array::insertSort(int x){
    int i = length-1;
    if(length>=size) return;
    
    while(i>=0 && A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

bool array::isSorted(){
    int i = length-1;
    int j = 0;
    
    while(j<i){
        if(A[j]>A[j+1]){
            return false;
        }
        j++;
    }
    return true;
}

void array::negativeCheck(){
    int i = 0;
    int j = length-1;
    
    while(i<j){
        while(A[i] < 0) i++;
        while(A[j] > 0) j--;
        int temp;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

array* array::ArrayUnion(array arr2) {
    int i = 0, j = 0, k = 0;
    array *arr3 = new array(this->length + arr2.length);

    while(i < this->length && j < arr2.length) {
        if(this->A[i] < arr2.A[j]) {
            arr3->A[k++] = this->A[i++];
        } else if(arr2.A[j] < this->A[i]) {
            arr3->A[k++] = arr2.A[j++];
        } else {
            arr3->A[k++] = this->A[i++];
            j++;
        }
    }

    while(i < this->length) {
        arr3->A[k++] = this->A[i++];
    }

    while(j < arr2.length) {
        arr3->A[k++] = arr2.A[j++];
    }

    arr3->length = k;
    return arr3;
}

array* array::ArrayIntersection(array arr2){
    int i, j, k;
    i=j=k=0;
    array *arr3 = new array(length+arr2.length);
    
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            i++;
        }else if(arr2.A[j]<A[i]){
            j++;
        }else if(A[i] == arr2.A[j]){
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    
    arr3->length = k;
    arr3->size = size+arr2.size;
    return arr3;
}

array *array::ArrayDifference(array arr2){
    int i, j, k;
    i=j=k=0;
    array *arr3 = new array(length+arr2.length);
    
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }else if(arr2.A[j]<A[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    
    while (i < length) {
        arr3->A[k++] = A[i++];
    }
    
    arr3->length = k;
    arr3->size = size+arr2.size;
    return arr3;
}

int main() {
    array *arr1;
    int ch, sz, x, index;

    printf("Enter size of array: ");
    scanf("%d", &sz);

    arr1 = new array(sz);

    do {
        printf("\nMenu:\n");
        printf("1. Append\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Get\n");
        printf("8. Set\n");
        printf("9. Max\n");
        printf("10. Min\n");
        printf("11. Sum\n");
        printf("12. Average\n");
        printf("13. Reverse\n");
        printf("14. Left Shift\n");
        printf("15. Insert Sort\n");
        printf("16. Check if Sorted\n");
        printf("17. Move Negatives Left\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter element to append: ");
                scanf("%d", &x);
                arr1->append(x);
                break;
            case 2:
                printf("Enter index and element to insert: ");
                scanf("%d %d", &index, &x);
                arr1->insert(index, x);
                break;
            case 3:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                arr1->del(index);
                break;
            case 4:
                arr1->display();
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &x);
                index = arr1->LinearSearch(x);
                if(index != -1) printf("Found at index %d\n", index);
                else printf("Not found.\n");
                break;
            case 6:
                printf("Enter element to binary search: ");
                scanf("%d", &x);
                index = arr1->BinarySearch(x);
                if(index != -1) printf("Found at index %d\n", index);
                else printf("Not found.\n");
                break;
            case 7:
                printf("Enter index to get value: ");
                scanf("%d", &index);
                printf("Element at index %d: %d\n", index, arr1->get(index));
                break;
            case 8:
                printf("Enter index and new value: ");
                scanf("%d %d", &index, &x);
                arr1->set(index, x);
                break;
            case 9:
                printf("Maximum value: %d\n", arr1->max());
                break;
            case 10:
                printf("Minimum value: %d\n", arr1->min());
                break;
            case 11:
                printf("Sum of elements: %d\n", arr1->sum());
                break;
            case 12:
                printf("Average of elements: %.2f\n", arr1->avg());
                break;
            case 13:
                arr1->reverse();
                printf("Array reversed.\n");
                break;
            case 14:
                arr1->leftShift();
                printf("Array left shifted.\n");
                break;
            case 15:
                printf("Enter element to insert in sorted order: ");
                scanf("%d", &x);
                arr1->insertSort(x);
                break;
            case 16:
                if(arr1->isSorted())
                    printf("Array is sorted.\n");
                else
                    printf("Array is not sorted.\n");
                break;
            case 17:
                arr1->negativeCheck();
                printf("Moved negative elements to left.\n");
                break;
            case 0:
                delete arr1;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(ch != 0);

    return 0;
}

