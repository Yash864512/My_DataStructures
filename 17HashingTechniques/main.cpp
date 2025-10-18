//=================================> Chaining Method
/*
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int hashFunction(int key){
    return key % 10;
}

void insert(struct Node *H[], int key){
    int index = hashFunction(key);
    SortedInsert(&H[index], key);
}

int main(void){
    struct Node *HT[10];
    struct Node *temp;
    int key;
    
    for(int i = 0; i < 10; i++){
        HT[i] = NULL;
    }
    
    insert(HT, 12); // Should go to index 2
    insert(HT, 22); // Should go to index 2
    insert(HT, 2);  // Should go to index 2
    insert(HT, 35); // Should go to index 5
    insert(HT, 25); // Should go to index 5

    printf("Hash Table:\n");
    for(int i = 0; i < 10; i++) {
        printf("Index %d: ", i);
        display(HT[i]);
    }
    
    printf("\nEnter number you wanted to search for: ");
    scanf("%d", &key);
    
    temp = LinearSearch(HT[hashFunction(key)], key);
    if(temp){
        printf("\nKey: %d found at index %d", temp->data, hashFunction(22));
    }else{
        printf("\nKey not found");
    }
    
    return 0;
}
*/

//===================================> Linear Probing Method
/*
#include <stdio.h>
#define SIZE 10

int hashFunction(int key){
    return key % SIZE;
}

int probe(int HT[], int key){
    int index = hashFunction(key);
    int i = 0;
    while(HT[(index + i) % SIZE] != 0){
        i++;
    }
    return (index + i) % SIZE;
}

void insert(int HT[], int key){
    int index = hashFunction(key);
    if(HT[index] != 0){
        index = probe(HT, key);
    }
    HT[index] = key;
}

int search(int HT[], int key){
    int index = hashFunction(key);
    int i = 0;
    while(HT[(index + i) % SIZE] != 0){
        if(HT[(index + i) % SIZE] == key)
            return (index + i) % SIZE;  // found
        i++;
        if(i == SIZE) return -1; // table full / not found
    }
    return -1; // not found
}

void display(int HT[]){
    printf("Hash Table: \n");
    for(int i = 0; i < SIZE; i++){
        printf("%d: %d\n", i, HT[i]);
    }
}

int main(void){
    int HT[SIZE] = {0};

    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);

    display(HT);

    int key = 35;
    int pos = search(HT, key);
    if(pos != -1)
        printf("Key %d found at index %d\n", key, pos);
    else
        printf("Key %d not found\n", key);

    return 0;
}
*/

//================================> Quadratic Probing
/*
#include <stdio.h>
#define SIZE 10

int hashFunction(int key){
    return key % SIZE;
}

int probe(int HT[], int key){
    int index = hashFunction(key);
    int i = 0;
    while(HT[(index + i*i) % SIZE] != 0){
        i++;
    }
    return (index + i*i) % SIZE;
}

void insert(int HT[], int key){
    int index = hashFunction(key);
    if(HT[index] != 0){
        index = probe(HT, key);
    }
    HT[index] = key;
}

int search(int HT[], int key){
    int index = hashFunction(key);
    int i = 0;
    while(HT[(index + i*i) % SIZE] != 0){
        if(HT[(index + i*i) % SIZE] == key)
            return (index + i*i) % SIZE;  // found
        i++;
        if(i == SIZE) return -1; // table full / not found
    }
    return -1; // not found
}

void display(int HT[]){
    printf("Hash Table: \n");
    for(int i = 0; i < SIZE; i++){
        printf("%d: %d\n", i, HT[i]);
    }
}

int main(void){
    int HT[SIZE] = {0};

    insert(HT, 23);
    insert(HT, 43);
    insert(HT, 13);
    insert(HT, 27);

    display(HT);

    int key = 35;
    int pos = search(HT, key);
    if(pos != -1)
        printf("Key %d found at index %d\n", key, pos);
    else
        printf("Key %d not found\n", key);

    return 0;
}
*/

//===================================> Double Hashing Method (C++)

#include <iostream>
#define SIZE 10
#define PRIME 7

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
 
int Hash(int key){
    return key % SIZE;
}
 
int PrimeHash(int key){
    return PRIME - (key % PRIME);
}
 
int DoubleHash(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0){
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}
 
void Insert(int H[], int key){
    int idx = Hash(key);
 
    if (H[idx] != 0){
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}
 
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key){
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0){
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
}
 
 
int main() {
 
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
 
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;
 
    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
 
    return 0;
}