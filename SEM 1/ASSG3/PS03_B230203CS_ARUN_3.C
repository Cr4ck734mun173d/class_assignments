#include<stdio.h>
  int main(){
          float marksA, marksB, marksC, Total, percent;
          printf("Enter the marks of course A:\n");
          scanf("%f", &marksA);
          printf("Enter the marks of course B:\n");
          scanf("%f", &marksB);
          printf("Enter the marks of course C:\n");
          scanf("%f", &marksC);
      Total=marksA+marksB+marksC;
      percent=(Total/300)*100;
          printf(" Course A: %f\n Course B: %f\n Course C: %f\n Total marks: %f\n Percentage: %f ", marksA, marksB,marksC, Total, percent);
    return 0;
  }