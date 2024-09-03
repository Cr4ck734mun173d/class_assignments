#include <stdio.h>
int fibo(int n)
{
    if (n < 0)
    {
        printf("Please enter a positive integer!");
    }
    else if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {

        return fibo(n - 1) + fibo(n - 2);
    }
}
int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("%d", fibo(num));
    return 0;
}