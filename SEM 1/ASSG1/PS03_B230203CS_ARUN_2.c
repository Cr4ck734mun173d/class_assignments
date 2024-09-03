#include <stdio.h>
int main(){
          int input, digit0, digit0dividend, digit1, digit2, sum;
          printf("Enter a 3 digit integer:\n");
          scanf("%d", &input);
          digit0=input%10;
          digit0dividend=input/10;
          digit1=digit0dividend%10;
          digit2=input/100;
          sum=digit0+digit1+digit2;
          printf("DIGIT0=%d, DIGIT1=%d, DIGIT2=%d, SUM=%d", digit0, digit1, digit2, sum);

return 0;
}