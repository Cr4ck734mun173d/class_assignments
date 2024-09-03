#include <stdio.h>
 long long sum(long long n)
{
    if (n<10)
    {
        return n;
    }
    
    return (n%10 + sum(n/10));
}
 long long main(){
    long long num;
    printf("Enter the value of integer: ");
    scanf("%lld",&num);
    if (num<0)

    {
        num=num*-1;
    }
    
    printf("Sum= %lld", sum(num));
    return 0;
}