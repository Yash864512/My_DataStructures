//================================> Creating array of charecter
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[10] = "";
    char name2[5] = {'J', 'O', 'H', 'N', '\0'}; //\0 is string delimeter
    char arr3[5] = {65, 66, 67, 68, 69};
    
    printf("ASCII code of A: %d\n", arr3[0]);
    printf("%c\n", arr3[0]);
    
    printf("%s\n", name2);
    gets(name); // Stores the name("Taj Mahal") until we press enter
    printf("%s\n", name);
}
*/

//==================================> Finding length of the string
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    char s[] = "WELCOME";
    int i = 0;
    
    for(i; s[i]!='\0'; i++); // Loop will run until it reaches null charecter or string delimeter
    printf("Length of the string: %d\n", i);
}
*/

//===================================> Converting string to lower case
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    char s[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', '\0'};
    
    for(int i = 0; s[i]!='\0'; i++){
        s[i]+=32; //ASCII code for A-65, a-97. Diff = 97-65 = 32
    }
    printf("%s\n", s);
}
*/

//=====================================> Toggle case(some upper, some lower)
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    char s[] = {'W', 'e', 'L', 'c', 'o', 'M', 'e', '\0'};
    
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i] >= 65 && s[i]<=90){
            s[i]+=32;
        }else if(s[i]>=97 && s[i]<=122){
            s[i]-=32;
        }
    }
    printf("%s\n", s);
}
*/

//=====================================> Vovel, Consonent counter and counting no of words
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    char s[] = "How are you";
    int Vcount = 0, Ccount = 0;
    int Nwords = 1; // No of words is always no oof spaces + 1
    
    for(int i = 0; s[i]!='\0'; i++){ // code to count Vowels and consonents
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' ||
        s[i]=='O' || s[i]=='U'){
            Vcount++;
        }else if((s[i] >= 65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            Ccount++;
        }
    }
    
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i] == ' ' && s[i-1]!= ' '){  // code for counting no of words
            Nwords++;
        }
    }
    
    printf("No of words: %d\n", Nwords);
    printf("No of Vowels: %d\n", Vcount);
    printf("No of Consonents: %d\n", Ccount);
}
*/

//=================================> Validating a string(Checking if string contains any special char)
/*
#include <stdio.h>
#include <stdlib.h>

int valid(char name[]){
    for(int i = 0; name[i]!='\0'; i++){
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57)){
            return 0;
        }
    }
    return 1;
}

int main(){
    char name[] = "Y@sh123"; // Username should not contain any special char
    
    if(valid(name)){
        printf("The Username is valid");
    }else{
        printf("The Username is not valid");
    }
}
*/

//==================================> Reversing a string using swap method
/*
#include <stdio.h>
#include <stdlib.h>

 int main(){
     char s[] = "PYTHON";
     int i, j;
     
     for(j = 0; s[j]!='\0'; j++);
     char k;
     
     for(i = 0, j--; i<j; i++, j--){
         k = s[i];
         s[i] = s[j];
         s[j] = k;
    }
    printf("%s\n", s);
}
*/

//==================================> Reversing a string using swap method
/*
#include <stdio.h>
#include <stdlib.h>

 int main(){
     char s[] = "PYTHON";
     int i, j;
     
     for(j = 0; s[j]!='\0'; j++);
     char d[j];
     int length = j;
     for(i = 0, j--; i<length; i++, j--){
         d[i] = s[j];
    }
    d[length] = '\0';
    printf("%s\n", d);
}
*/

//===================================> Finding duplicates in a string using hashmap
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[] = "Finding";
    int arr[26] = {0}, i;
    
    for(i = 0; name[i]!='\0'; i++){
        arr[name[i] - 97]++;;
    }
    
    for(i = 0; i<26; i++){
        if(arr[i]>1){
            printf("%c appeared %d times\n", i+97, arr[i]);
        }
    }
}
*/

//================================> Finding duplicates in a string using bitwise operations
/*
#include <stdio.h>
#include <stdlib.h>

int  main(){
    char A[] = "findings";
    long int H = 0, x = 0;
    
    for(int i = 0; A[i]!='\0'; i++){
        x = 1;
        x=x<<(A[i]-97);
        
        if((x&H)>0){
            printf("%c is Duplicated\n", A[i]);
        }else{
            H = x|H;
        }
    }
}
*/

//==================================> Finding weather 2 strings are anagram or not
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char A[] = "medical";
    char B[] = "decimal";
    int H[26] = {0};
    
    if (strlen(A) != strlen(B)) {
        printf("The strings are not Anagram\n");
        return 0;
    }

    for (int i = 0; A[i] != '\0'; i++) {
        H[A[i] - 'a']++;
    }

    for (int i = 0; B[i] != '\0'; i++) {
        H[B[i] - 'a']--;
        if (H[B[i] - 'a'] < 0) {
            printf("The strings are not Anagram\n");
            return 0;
        }
    }

    printf("The strings are Anagram\n");
    return 0;
}
*/

//=========================================> Permutations of a string
/*
#include <stdio.h>
#include <stdlib.h>

void perm(char S[], int k){
    static int A[10] = {0};
    static char res[10];
    int i;
    
    if(S[k]=='\0'){
        res[k] = '\0';
        printf("%s\n", res);
    }else{
        for(i=0; S[i]!='\0'; i++){
            if(A[i] == 0){
                res[k] = S[i];
                A[i] = 1;
                perm(S, k+1);
                A[i] = 0;
            }
        }
    }
}

int main(){
    char S[] = "ABCD";
    perm(S, 0);
}
*/

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    char num[10];
    char rev[10];
    int len = 0;
    sprintf(num, "%d", x);
    if(x<0) return false;
    else{
        for(int i = 0; i!='\0'; i++){
            len++;
        }
        for(int j = len, k = 0; j>=0, k<len; j--, k++){
            rev[k] = num[j];
        }
        for(int l = 0; l<len; l++){
            if(rev[l] == num[l]){
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    isPalindrome(10);

}