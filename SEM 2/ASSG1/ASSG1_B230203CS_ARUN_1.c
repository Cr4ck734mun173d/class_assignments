#include <stdio.h>

void insetionSort(int a[],int n)
{
    int key=0,j=0;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j=i-1;

        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;

        }
        a[j+1]=key;
        

    }
    
}
int main(){
    int n;
    while (1)
    {
        scanf("%d",&n);
        if (n<1||n>100000)
        {
            printf("Invalid input\n");
        }
        else
        {
            break;
        }
        
    }
    
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
       if (arr[i]<-100000||arr[i]>100000)
       {
           printf("Invalid input\n");
          i--;
          continue;
       }
    }
    insetionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
}