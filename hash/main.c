#include <stdio.h>
#include <string.h>
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

typedef CustomerList* HastItem; 

//HashItem customer_hash_table[MAX_CUSTOMER_LIST];

void init_hash_table(HashItem ht, int size){
    for(int i = 0; i < size; i++)
        ht+i = NULL;
}

int get_hash_value(const char* str){
    int value = 0;
    int i = 0;
    if (str == NULL) return -1;

    while(*str){
        value = value << 5 + *str++;
    }
    return value;
}

HashItem* get_hash_item(HashItem ht, const char* str){
   if (ht == NULL || str == NULL) return NULL;
   int index = get_hash_value(str);
   HashItem item = ht[index];
   if(item != NULL){
       while(item!= NULL){
           if(!strcmp(item->id, str) && item->next != NULL) break;
           item = item->next;
       }
   }
   
   return item;
}

char* strudp(const char* str){
    int len = strlen(str);
    char* newstr = (char*)malloc(len * sizeof(char));
    if(newstr == NULL) return NULL;
    strcpy(newstr, str);
    return newstr;
}

void insert_value(HashItem* ht, const char* str, int mile){
    int index = get_hash_value(ht, str);
    HashItem item = get_hash_item(ht, str);
    if(item == NULL){
        HashItem new_item = (HashItem)malloc(sizeof(HashItem))
        ht[index] = new_item;
        new_item->id = strudp(str);
        new_item->mile = mile;
        new_itme->next = NULL;
    }

    if (!strcmp(item->id, str)) {
        item->mile = mile;
    } else {
        HashItem new_item = (HashItem)malloc(sizeof(HashItem))
        item->next = new_item;
        new_item->id = strudp(str);
        new_item->mile = mile;
        new_item->next = NULL;
    } 
}



int main(){
    File* fp = fopen("sample.txt", r)
    if(fp == NULL){
        printf("file read error\n");
        return -1;
    }
    return 0;
}
