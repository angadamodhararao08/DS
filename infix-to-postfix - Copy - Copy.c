#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[50];
int top=-1;
void push(char data)
{
    stack[++top]=data;
}
int pop()
{
    return stack[top--];
}
void output(char data)
{
    printf("%c",data);
}
int precedence(char data)
{
    if(data=='+'||data=='-')
        return 1;
    if(data=='*'||data=='/')
        return 2;
    if(data=='^')
        return 3;
    return 0;
}
int main()
{
    int n,i;
    char k;
    char E[50];
    printf("Enter infix exression:");
    scanf("%s",E);
    n=strlen(E);
    printf("Length of string=%d\n",n);
    printf("Infix Expression=");
    for(i=0;i<n;i++)
    {
        if(E[i]=='(')
        {
            push(E[i]);
        }
        else if(E[i]==')')
        {
            while(stack[top]!='(')
            {
                output(pop());
            }
            pop();
        }
        else if(E[i]!=')'&&E[i]!='('&&E[i]!='+'&&E[i]!='_'&&E[i]!='*'&&E[i]!='/')
        {
            output(E[i]);
        }
        else
            {
            while(top!=-1&&precedence(stack[top])>=precedence(E[i]))
                  {
                      output(pop());
                  }
                  push(E[i]);
            }

    }
    while(top!=-1)
    {
        output(pop());
        if(top==-1)
            break;
    }


}
