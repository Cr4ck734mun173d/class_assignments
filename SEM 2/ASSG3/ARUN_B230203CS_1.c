#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 10000
typedef struct data
{
    char name[MAX_LEN];
    int mileage;

}vehicle;

int charToInt(char *str)
{
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        num = (num * 10) + str[i] - '0';
    }
    return num;
}
void Heapify(vehicle *Car, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && Car[left].mileage < Car[largest].mileage)
    {
        largest = left;
    }
    if (right < n && Car[right].mileage < Car[largest].mileage)
    {
        largest = right;
    }
    if (largest != i)
    {
        vehicle temp = Car[i];
        Car[i] = Car[largest];
        Car[largest] = temp;
        Heapify(Car, n, largest);
    }
}
void HeapSort(vehicle *Car, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(Car, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        vehicle temp = Car[0];
        Car[0] = Car[i];
        Car[i] = temp;
        Heapify(Car, i, 0);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n<1||n>1000)
    {
        return 1;
    }
    
    getchar();
    vehicle Car[n];
    for (int i = 0; i < n; i++)
    {
        fgets(Car[i].name,MAX_LEN,stdin);
        Car[i].name[strcspn(Car[i].name, "\n")] = '\0';
        
        if (Car[i].name[0] == '\0')
        {
            i--;
            continue;
        }
        
        
        int j = 0;
        j=strcspn(Car[i].name,":")+1;
        
        // while (Car[i].name[j] != '\0'&& !isdigit(Car[i].name[j]))
        // {
             
        //     j++;
        // }
        // if (Car[i].name[j-1]!=' ')
        // {
        //     while (Car[i].name[j] != '\0'&& isdigit(Car[i].name[j]))
        //     {
        //         j++;
        //     }
        //     j++;
            
        // }
        
        //printf(" %d\n", j);
        if (isdigit(Car[i].name[j]))
        {
            Car[i].mileage = charToInt(&Car[i].name[j]);
            Car[i].name[j] = '\0';
        }
    //    printf("%d\n", Car[i].mileage);

    }
    HeapSort(Car, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s%d\n", Car[i].name, Car[i].mileage);
    }
    return 0;
}
