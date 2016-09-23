#include<stdio.h>
#define size 50
#define max 10
void ADD(int stacks[],int top[],int ele,int boundary[],int j)
{
    if(top[j]==boundary[j+1])
    {
        printf("\n Overflow");
        return;
    }
        stacks[++top[j]]=ele;
}
int DELETE(int stacks[],int top[],int boundary[],int j)
{
    if(top[j]==boundary[j])
    {
        printf("\n Underflow");
        return;
    }
    else
        return stacks[top[j]--];
}
void display(int stacks[],int top[],int boundary[],int j)
{
    int i=0;
    if(top[j]==boundary[j])
    {
        printf("\n Empty stack");
        return;
    }
        for(i=boundary[j]+1;i<=top[j];i++)
        {
            printf("%d ",stacks[i]);
        }
}
int main()
{
    int stacks[size],ch,i=0,n,top[max],boundary[max],j,ele;
    printf("\n Enter number of stacks ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        boundary[i]=top[i]=size/n*i-1;

     do
    {
        printf("\n Enter stack number ");
        scanf("%d",&j);
        printf("\n 1.ADD 2.DELETE 3.Display ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n Enter element to add ");
                    scanf("%d",&ele);
                    ADD(stacks,top,ele,boundary,j);
                    break;
            case 2:DELETE(stacks,top,boundary,j);
                    break;
            case 3:display(stacks,top,boundary,j);
                    break;
        }
    } while(ch==1||ch==2||ch==3);
    return 0;
}
