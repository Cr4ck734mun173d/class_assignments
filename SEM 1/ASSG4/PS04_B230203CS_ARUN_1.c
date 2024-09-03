#include<stdio.h>
int main(){
    float marks;
    char grade;
    printf("Enter the value of marks:");
    scanf("%f", &marks);
 if (marks<0){
    {printf("Error:marks entered are wrong");}
    return 0;}
if (marks>100){
    {printf("Error:marks entered are wrong");}
    return 0;}
    if (marks<=100){
        if (marks>=80)
        grade='A';
    }
    if(marks<80)
    {if (marks>=60)
    grade='B';}
    if (marks<60){
        if(marks>=50)
        grade='P';

    }
    if(marks<50){
        if(marks>=0)
        grade='F';
    }
    printf("Grade=%c", grade);
    return 0;
   }
