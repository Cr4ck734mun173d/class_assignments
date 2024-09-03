#include <stdio.h>

int main(){
    int productcode=1, unitprice=1;
    float quantity,total=0,price=0;
        
        while (productcode!=0)
        {
            printf("Enter product code between 1 to 5. To terminate enter 0:");;
            scanf("%d", &productcode);
            
            if (productcode==0)
            {
                break;} 
            else if (productcode<1 || productcode>5)
            {
                printf("Please enter a valid product code\n");
                continue;
            }
            printf("Quantity=");
            scanf("%f", &quantity);
           
            
            switch (productcode)
            {
            case 1:
                unitprice=10;
                break;
            case 2:
                unitprice=15;
                break;
            case 3:
                unitprice=5;
                break;
            case 4:
                unitprice=3;
                break;
            case 5:
                unitprice=12;
                break;    
            default:printf("Entered product code is not in range. Please enter the correct value:");
                break;
            }
            price=unitprice*quantity;
            total+=price;
            printf("Product code  Unit Price  Quantity     Price\n%d               %d         %f   %f\n", productcode,unitprice,quantity,price);
        }
    printf("Total price=%f", total);
    return 0;
}