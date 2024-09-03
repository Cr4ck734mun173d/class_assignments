#include <stdio.h>
float tofahrenheit(float n)
{
    return (1.8*n + 32);
}
int main()
{   printf("Celsius\tFahrenheit\n");
    for (int i = 30; i <=50; i++)
    {
        printf("%d\t%f\n",i,tofahrenheit(i));
    }
    

    return 0;
}