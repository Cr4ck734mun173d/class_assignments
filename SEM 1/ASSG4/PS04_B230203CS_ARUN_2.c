#include <stdio.h>
int main(){
            float marks;
            char grade;
            printf("Enter the marks:");
            scanf("%f", &marks);
            if (marks>100 || marks<0){
                printf("Marks entered are not in range");
                return 0;
            }
            if(marks<=100){
                if(marks>=80){
                    grade='A';
                }
                if(marks>=60 && marks<80){
                    grade='B';

                }
                if(marks>=50 && marks<60){
                    grade='P';

                }
                if (marks<50){
                    grade='F';
                }

            }
            printf("Grade=%c", grade);
            





    return 0;
}