#include <stdio.h>
void swap (int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int smallest (int a[])
{   int index=0;
    for (int i = 0; i < 5; i++)
    {
        int small=a[0];
        if (a[i]<small)
        {
            small=a[i];
            index=i;
        }
        
    }
    return index;
}

int main(){
    int A[5];
    int *ptrA=&A[0];
    for (int i = 0; i <5; i++)
    {
        scanf("%d",&A[i]);
    }

int *ptrB=&A[smallest(A)];
swap(ptrA,ptrB);
for (int i = 0; i < 5; i++)
{
    printf("%d ",A[i]);
}

}