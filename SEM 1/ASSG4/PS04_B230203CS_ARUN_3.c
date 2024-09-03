#include<stdio.h>
int main(){
            float marks;
            char grade;
            printf("Enter the marks:");
            scanf("%f", &marks);

            if (marks<=100 && marks>0){
                if (marks>=80){
                    grade='A';
                }
                else if(marks>=60 && marks<80){
                    grade='B';
                }
                else if(marks>=50 && marks<60){
                    grade='P';
                }
                else
                   grade='F';
            printf("Grade=%c", grade);                                         
            }
            else {
                printf("Marks entered are not in range.\n");
                return 0;
            }

           


    return 0;
}