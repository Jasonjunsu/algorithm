#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 200000
typedef struct Node * Hash;/** **/
struct Node{
  char arr[20]; // 
  int fen; // 
  Hash next; //  NULL
};
int deal(char *arr) /****/
{
  int idex;
  idex = (arr[5]-'0')*10000+(arr[9]-'0')*1000+(arr[13]-'0')*100+(arr[15]-'0')*10+(arr[16]-'0');
  if(arr[17]=='x') idex = idex*10+10;
  else idex = idex*10 + (arr[17]-'0');
  return idex;
}
int nextprime(int N) /**N  **/
{
  int i,p=(N%2)?N+2:N+1;
  while(p<MAX)
  {
    for(i=(int)sqrt(N);i>=2;i--)
      if(!(p%i)) break;
    if(i<2) break; // 
    else p+=2;  //
  }
  return p;
}
Hash insert(Hash h,int x,char *s) /**  **/
{
  Hash p =h;
  while(p) /****/
  {
    /****/
    if(strcmp(p->arr,s)==0) /****/
    {
      p->fen+=x;
      return h;
    }
    else p=p->next; /**   NULL **/
  }
  /**i ,**/
  p= (Hash)malloc(sizeof(struct Node)); /*if it is NULL, */
  strcpy(p->arr,s);
  p->fen=x;
  p->next=h; /**,**/
  return p; /**(nexth)h  **/
}
void display(Hash h,char *s) /****/
{
  while(h)
  {
    if(strcmp(h->arr,s)==0)
    {
      printf("%d\n",h->fen);
      return;
    }
    h=h->next;
  }
  printf("No Info\n");
}
int main(){
  int n,k;
  scanf("%d %d\n",&n,&k);
  int p= nextprime(n);
  Hash *h = (Hash*)malloc(p*sizeof(Hash)); /**    h**/
  int i;
  for(i=0;i<p;i++) /****/
  {
    h[i]=NULL;
  }
  int x,idex;  /****/
  char arr[20];
  while(n--)
  {
    scanf("%s %d\n",arr,&x);
    if(x<k) x=k; //if x miles less than k, treat as K miles
    idex = deal(arr)%p; //get the hash value of array, and mod the primer for index.
    h[idex] = insert(h[idex],x,arr); //save the node into hash list
  }
  int m;
  scanf("%d\n",&m);
  while(m--)
  {
    scanf("%s",arr);
    idex = deal(arr)%p;
    display(h[idex],arr);
  }
    return 0;
}

