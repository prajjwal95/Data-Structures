#include<stdio.h>
#define size 4
void push(int ons[],int *top,int ele)
{
    if(*top==size-1)
        printf("\n Overflow");
    else
        ons[++(*top)]=ele;
}
int pop(int ons[],int *top)
{
    if(*top==-1)
        printf("\n Underflow");
    else
        return ons[(*top)--];
}
void display(int ons[],int *topo,int nos[],int *topn)
{
    int i=0;
    if(*topo==-1&&*topn==-1)
        printf("\n Empty queue ");
    else if(*topo==-1)
    {
        for(i=0;i<=*topn;i++)
        printf("%d ",nos[i]);
    }
    else if(*topn==-1)
    {
        for(i=*topo;i>=0;i--)
            printf("%d ",ons[i]);
    }
    else
     {  for(i=*topo;i>=0;i--)
        printf("%d ",ons[i]);
        for(i=0;i<=*topn;i++)
        printf("%d ",nos[i]);
     }
}
int main()
{
    int newstack[size],oldstack[size],topo=-1,topn=-1,i=0,n,ele;
    do
    {
        printf("\n 1. Add 2.Delete 3.Display ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("\n Enter element to add ");
                    scanf("%d",&ele);
                        push(newstack,&topn,ele);
                        break;
            case 2:if(topo==-1)
                    {
                        while(topn!=-1)
                          { ele=pop(newstack,&topn);
                            push(oldstack,&topo,ele);
                          }
                          pop(oldstack,&topo);
                    }
                    else
                        pop(oldstack,&topo);
                        break;
             case 3:display(oldstack,&topo,newstack,&topn);
                    break;
        }
    }while(n==1||n==2||n==3);
     return 0;

}
