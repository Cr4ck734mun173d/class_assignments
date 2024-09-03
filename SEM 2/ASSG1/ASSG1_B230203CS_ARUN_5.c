#include <stdio.h>
int bubbleSort(int a[], int n)
{
    int i, temp = 0, count = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n >= 1 && n <= 100000)
        {
            break;
        }
        else
        {
            printf("INVALID INPUT!\nEnter a value between 1 and 100000\n");
        }
    }
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < 1 || a[i] > 100000)
        {
            printf("Invalid Input!\nEnter a value between 1 and 100000\n");
            i--;
            continue;
        }
    }
    int x = bubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n%d", x);

    return 0;
}