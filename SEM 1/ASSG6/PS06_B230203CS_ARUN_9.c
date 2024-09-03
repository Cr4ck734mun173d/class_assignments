#include <stdio.h>
int gcd(int n, int m)
{

    if (m == 0)
        return n;
    else
        return gcd(m, n % m);
}
int main()
{
    int a, b;
    printf("Enter the value of A: ");
    scanf("%d", &a);
    printf("Enter the value of B: ");
    scanf("%d", &b);
    if (b > a)
    {
        int temp;
        temp = b;
        b = a;
        a = temp;
    }
    printf("GCD of %d and %d is : %d ",a,b,gcd(a,b));

    return 0;
}