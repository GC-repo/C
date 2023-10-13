#include<stdio.h>
#include<string.h>
void push(char a[],char val,int* f,int* r)
{
    (*r)++;
    a[*r]=val;
    
}
void pop(char a[],int* f,int* r)
{
    char c=a[*f];
    printf("%c",c);
    (*f)++;
}

int main()
{
    char q[]="EAS*Y*QUE***ST***IO*N***";
    int f = 0;
    int r = -1;
    for(int i=0;i<=strlen(q);i++)
    {
        if(q[i]=='*')
        {
            pop(q,&f,&r);
        }
        else
        {
            push(q,q[i],&f,&r);
        }
    }
}
