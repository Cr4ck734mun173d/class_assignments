#include<stdio.h>
int main(){
    float salary, hourrate ;
    int hours,remhour;
 
 

              
                printf("Number of hrs per week: ");
                scanf("%d", &hours);
                printf("Hourly rate: ");
                scanf("%f", &hourrate);
           
        remhour=(hours-40); 
           
            
            
            if(remhour<=0){
                
                    printf("Weekly Salary=%f", salary=hours*hourrate);
            }
            else if(remhour!=0){
                printf("Weekly Salary=%f\nExtra hours=%d", salary=((40*hourrate)+(remhour*(hourrate/2))), remhour);
            }

           

                










    return 0;
}