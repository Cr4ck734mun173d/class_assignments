#include <stdio.h>
int isPrime(int n)
{ 
    if (n==2)
    {
        return 1;    
        
    }
    

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int up, low;
    printf("Enter Lower Bound: ");
    scanf("%d", &low);
    printf("Enter Upper Bound: ");
    scanf("%d", &up);
    if (low < 2)
    {
        low = 2;
    }
    printf("Prime Numbers in the range %d to %d: ", low, up);
    for (int i = low; i <= up; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}