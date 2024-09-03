#include <stdio.h>
long fact(int n)
{
    if (n<=0)
    {
       return 1;
    }
     return n * fact(n - 1);
}
int main()
{
    int num;
    printf("Enter a non negative integer: ");
    scanf("%d", &num);
    printf("Factorial=%ld", fact(num));
    return 0;
}