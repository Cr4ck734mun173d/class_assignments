#include <stdio.h>
float getPrice(int code, float quantity)
{
    int unitprice;
    switch (code)
    {
    case 1:
        unitprice = 10;
        break;
    case 2:
        unitprice = 15;
        break;
    case 3:
        unitprice = 5;
        break;
    case 4:
        unitprice = 3;
        break;
    case 5:
        unitprice = 12;
        break;
    default :
        unitprice=0;
        break;

    
    }
    return unitprice * quantity;
}
int main(){
    int code=1;
    float quantity,total=0.0;
    printf("Enter product code and quantity(0 to terminate iteration)\n");

    while (1)
    {
        printf("Product Code: ");
        scanf("%d",&code);
        if (code==0)
        {
            break;
        }
        if (code<0 || code>5)
        {
            printf("Enter Product code within range 1 to 5!\n");
            continue;
        }
        
        printf("Quantity: ");
        scanf("%f",&quantity);
        float price=getPrice(code,quantity);
        total+=price;
        printf("Price for Product %d: %f\n",code,price);
    }
    printf("Total Price= %f",total);
    return 0;
}