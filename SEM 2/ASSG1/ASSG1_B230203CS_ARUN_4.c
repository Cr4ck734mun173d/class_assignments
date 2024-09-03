#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int key, i, j;
    for (i = 0; i < n - 1; i++)
    {
        key = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[key] > arr[j])
            {
                key = j;
            }
        }

        if (key != i)
        {
            int temp = arr[key];
            arr[key] = arr[i];
            arr[i] = temp;
        }
    }
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
            printf("Invalid input!\nEnter a value between 1 and 100000:\n ");
        }
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 1 || arr[i] > 100000)
        {
            printf("Invalid Input!\nEnter a value between 1 and 100000:\n ");
            i--;
            continue;
        }
    }

    int k;
    while (1)
    {
        scanf("%d", &k);
        if (k >= 1 && k <= n)
        {
            break;
        }
        else
        {
            printf("Invalid input!\nEnter a value between 1 and %d: ", n);
        }
    }
    selectionSort(arr, n);
    printf("%d", arr[k - 1]);

    return 0;
}
