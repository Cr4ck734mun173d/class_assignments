#include <stdio.h>
float getWeeklySalary(int n, float m)
{
    if (n<=40)
    {
        return n*m;
    }
    return (((n-40)*(m/2))+(40*m));
    
}
int main()
{
    int num,hours;
    float rate;
printf("Enter the number of employees:");
scanf("%d",&num);
for (int i = 1; i<=num; i++)
{
    printf("Enter hours worked for employee %d: ",i);
    scanf("%d",&hours);
     printf("Enter hourly rate for employee %d: ",i);
    scanf("%f",&rate);
    printf("Weekly salary for employee %d= %f\n",i,getWeeklySalary(hours,rate));
}

    return 0;
}