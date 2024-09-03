#include<stdio.h>
int main(){
        float total, quantity;
        int prdtcode, unitprice;
                printf("Enter the product code:");
                scanf("%d", &prdtcode);
                printf("Enter the quantity:");
                scanf("%f", &quantity);
                     

                     switch (prdtcode)
                     {
                     case 1: unitprice=10;
                           break;
                     case 2:unitprice=15;
                           break;
                     case 3:unitprice=5;
                           break;
                     case 4:unitprice=3;
                           break;
                     case 5:unitprice=12;
                           break;
                     default:printf("Entered product code is not in range");
                     return 1;
                           break;
                     }

                    printf("Total Price=%f", total=(unitprice*quantity));

    return 0;
}