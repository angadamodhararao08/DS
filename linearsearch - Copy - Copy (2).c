#include<stdio.h>
int search(int A[],int n,int x){
  int i;
  for(i=0;i<n;i++){
    if(A[i]==x)
        return i;
  }
  return -1;

}
int main(){
int i,n,x,pos;
int A[]={1,34,54,23,67,89,9,54};
n=sizeof(A)/sizeof(int);
printf("Size of array:%d\n",n);
printf("Enter element to search:\n");
scanf("%d",&x);
pos=search(A,n,x);
printf("The position of %d is:%d",x,pos+1);
}
