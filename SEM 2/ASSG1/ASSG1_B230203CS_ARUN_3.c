#include <stdio.h>
#include <string.h>
typedef struct 
{
    char name[100];
    int price;
} product;
void swap(product *a, product *b)
{
    product temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(product a[], int n)
{
    int i, j, key;
    for (i = 0; i < n - 1; i++)
    {
        key = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[key].price>a[j].price)
            {
                key = j;
            }
        }
        if (key!=i)
        {
            swap(&a[i], &a[key]);
        }
        
        
    }
}
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n>=1 && n<=100000)
        {
            break;
        }
        else
        {
            printf("Invalid Input! \nPlease enter a value between 1 and 100000\n");

        }
        
    }
    
    
    product arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i].name);
        scanf("%d", &arr[i].price);
        if (strlen(arr[i].name)>100 )
        {
           printf("Invalid Input for name!\nEnter a name less than 100 characters.\n");
           i--;
           continue;
        }
        if(arr[i].price<1000 || arr[i].price>100000)
        {
            printf("Invalid Input for price!\nEnter a value between 100 and 100000\n");
            i--;
            continue;
        }
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i].price);
    }

    return 0;
}