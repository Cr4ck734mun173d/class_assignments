#include <stdio.h>

int main(){
    int n,i,marks,A=0,B=0,P=0,F=0;
    marks=0;

         printf("Enter the number of students:");
         scanf("%d", &n);
    for (i = 1; i<=n; i++)
    {
        printf("Marks of Student %d:", i);
        scanf("%d", &marks);
            if(marks<=100 && marks>=0){
                if(marks>=80){
                    A++;
                }
                if(marks>=60 && marks<80){
                    B++;
                }
                if(marks>=50 && marks<60){
                    P++;
                }
                if(marks<50 && marks>0){
                    F++;
                }        
            }
            
         
            }
  printf("The total number of students with A grade=%d\nThe total number of students with B grade=%d\nThe total number of students with P grade=%d\nThe total number of students with F grade=%d",A,B,P,F);
    return 0;  }
    

