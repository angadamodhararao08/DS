#include<stdio.h>
int search(int A[],int l,int h,int x){
 int mid;
 while(l<=h)
 {
  mid=(l+h)/2;
  if(A[mid]==x)
    return mid;
  else if(x<A[mid])
    h=mid-1;
  else
    l=mid+1;

 }
 return -1;

}
int main(){
int i,n,x,pos;
int A[]={5,10,15,20,25,30,35};
n=sizeof(A)/sizeof(int);
printf("Size of array:%d\n",n);
printf("Enter element to search:\n");
scanf("%d",&x);
pos=search(A,0,n-1,x);
printf("The position of %d is:%d",x,pos+1);
}

