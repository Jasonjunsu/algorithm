#include <stdio.h>

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
        for(int j = i; j < L; j++){
            if(a[j] < a[i]) swap(&a[i], &a[j]); 
        }
    }
}

void insertion_sort(int a[], int L){
    for(int i = 0; i < L - 1; i++){
　　　　　
        for(int j = i + 1; j >= 1; j--){
            if(a[j] < a[j-1]){
                 swap(&a[j], &a[j-1]);
            }
        }
    }
}

int main(){
  int a[10];
  printf("please input 10 numbers\n");
  for(int i = 0; i < 10; i++){
     scanf("%d", a+i);
  }
  int L = sizeof(a) / sizeof(int);
   
  print_array(a, L); 
  printf("the min of the L is %d\n", find_min(a, L));
  
  int b[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  //bubble_sort(b, L);
  //printf("---after bubble sort show array----\n");
  ///print_array(b, L);

  //selection_sort(b, L);
  //print_array(b, L);
  
  insertion_sort(b, L);
  print_array(b, L);
  return 0;
}
