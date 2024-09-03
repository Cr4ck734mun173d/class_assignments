#include<stdio.h>
int main(){
       int input, hour, minutes;
       printf("Enter time in minutes:\n");
       scanf("%d", &input);
       hour=input/60;
       minutes=input%60;
       printf("%d hrs %d minutes", hour, minutes);
return 0;

}