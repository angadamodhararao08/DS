#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[100];
int top=-1;
char top_char;
void push(char data)
{
    stack[++top]=data;
}
int pop()
{
    return stack[top--];
}
void Para(char E[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(E[i]=='('||E[i]=='['||E[i]=='{')
            {
                top++;
                stack[top]=E[i];
            }
        else if(E[i]==')'||E[i]==']'||E[i]=='}')
            {
                if(top==-1)
                {
                    printf("Unbalanced\n");
                    return;
                }
                top_char=stack[top];
                top--;
                if((E[i]==')'&&top_char!='(')||(E[i]==']'&&top_char!='[')||(E[i]=='}'&&top_char!='{'))
                    {
                        printf("Unbalanced\n");
                        return;
                    }
            }

    }
    if(top==-1)
    {
        printf("Balanced\n");
    }
        else{
            printf("Unbalanced");
    }
}
int main()
{
    int n,i;
    char E[50];
    printf("Enter the perantheses expression:");
    scanf("%s",E);
    n=strlen(E);
    printf("Length of string=%d\n",n);
    Para(E,n);

}
