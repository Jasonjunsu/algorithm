#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void create_rand_array(int array[], int L){
    int i = 0;
    srand(rand());
    while(i++ < L){
       array[i] = rand() % 100;
    }
}


static void print_array(int a[], int L){
    int i = 0;
    while(i < L){
        printf("%d ", a[i++]);
    }
    printf("\n");
}

static int find_min(int a[], int L){
    int min = 0;
    int index = 0;
    min = a[0];
    while(index < L){
        if(a[index] < L){
            min = a[index];
        }
        index++;
    }
    return min;
}

void swap(int* a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int L){
    for(int i = 1; i < L; i++){
        for(int j = 0; j < L-i; j++){
            if(a[j] > a[j+1]) swap(&a[j], &a[j+1]);
        }
    }
}

void selection_sort(int a[], int L) {
    for(int i = 0; i < L; i++){
        int min = i;
        for(int j = i + 1; j < L; j++){
            if(a[j] < a[min]) min = j;
        }
        swap(&a[i], &a[min+1]); 
    }
}

void insertion_sort(int a[], int L){
    for(int i = 0; i < L - 1; i++){
        for(int j = i; j >= 0 && a[j] > a[j+1]; j--){
            swap(&a[j], &a[j+1]);
        }
    }
}

int main(){
  int a[10] = {0};
  //printf("please input 10 numbers\n");
  //for(int i = 0; i < 10; i++){
  //   scanf("%d", a+i);
  //}
  //int L = sizeof(a) / sizeof(int);
  int L = 10;
   
  printf("\nfind the mini\n");
  create_rand_array(a, L);
  print_array(a, L);
  printf("the min of the L is %d\n", find_min(a, L));
  
  printf("\nbubble sort\n");
  create_rand_array(a, L);
  print_array(a, L);
  bubble_sort(a, L);
  print_array(a, L);
  
  printf("\nselettion sort\n");
  create_rand_array(a, L);
  print_array(a, L);
  selection_sort(a, L);
  print_array(a, L);
  
  printf("\ninsertion sort\n");
  create_rand_array(a, L);
  print_array(a, L);
  insertion_sort(a, L);
  print_array(a, L);
  return 0;
}
