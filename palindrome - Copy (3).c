#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100];
int top=-1,j=0,k=0;
int main()
{
    int n,i;
    char cleaned[100];
char reversed[100];
    char ch,string[100];
    //step:1-clean and push onto the stack
 printf("Enter a string:");
 scanf("%s",string);
 n=strlen(string);
 printf("String length =%d\n",n);
 for(i=0;i<n;i++)
 {
    ch= string[i];
    if(isalnum(ch))
    {
        cleaned[k]=ch;
    k=k+1;
    top++;
    stack[top]=ch;
    }
 }
  cleaned[k]='\0';
 //step2:pop to build reverse string
 while(top>=0)
 {
     reversed[j]=stack[top];
     top=top-1;
     j++;
 }
 reversed[j]='\0';
 if(strcmp(cleaned,reversed)==0)
     printf("Given string is a palindrome\n");
 else
    printf("Given string is not a palindrome\n");

}
