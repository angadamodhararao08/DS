#include<stdio.h>
#include<ctype.h>
int queue[50];
int top=-1;
void push(int data)
{
   queue[++top]=data;
}
int pop()
{
    return queue[top--];
}
int Evaluatepostfix(char E[])
{
    int i=0,ope2,ope1,res;
    while(E[i]!='\0')
    {
        if(isdigit(E[i]))
        {
            push(E[i]-'0');
        }
        else
        {
            ope2=pop();
            ope1=pop();
            switch(E[i])
            {
            case '+':
                res=ope1+ope2;
                break;
            case '-':
                res=ope1-ope2;
                break;
            case '*':
                res=ope1*ope2;
                break;
            case '/':
                res=ope1/ope2;
                break;
            }
             push(res);
        }
        i++;
    }
    return pop();
}
int main()
{
    char Ex[50];
    printf("Enter the postfix expression:");
    scanf("%s",Ex);
    printf("Result=%d",Evaluatepostfix(Ex));


}
