#include <stdio.h>
#include <file.h>
#define MAX_ID_LEN 18
#define MAX_CUSTOMER_NUM 20000

typedef struct{
    char id[MAX_ID_LEN+1];
    unsigned int miles;
}Customer;

typedef struct _Customer{
    Customer co;
    Customer* next;
}CustomerList;

CustomerList customer_hash [MAX_CUSTOMER_LIST];

int main(){
    File* fp = fopen("sample.txt", r)
    if(fp == NULL){
        printf("file read error\n");
        return -1;
    }
    return 0;
}
