#include<stdio.h>
int sumarray(int a[],int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    sum+=a[i];
    return sum;
}
int meanarray(int a[],int n)
{
    int i;
    int sum=0;
    float mean;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    mean=sum/n;
    return mean;
}
int main()
{
    int i,n;
    int a[]={1,2,4,5,6};
    n=sizeof(a)/sizeof(int);
    printf("size of array:%d\n",n);
    printf("sum of array=%d\n",sumarray(a,n));
    printf(" mean of array=%.2f",meanarray(a,n));
    return 0;

}
