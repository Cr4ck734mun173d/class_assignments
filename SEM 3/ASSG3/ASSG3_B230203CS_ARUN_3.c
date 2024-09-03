#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 1000

int hashfun(int key, int n)
{
    return key % n;
}
int isPrime(int k)
{
    if (k <= 1)
        return 0;
    for (int i = 2; i <= k / 2; i++)
    {
        if (k % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int largePrime(int n)
{
    for (int i = n - 1; i >= 2; i--)
    {
        if (isPrime(i))
        {
            return i;
        }
    }
    return -1;
}
int hashfun2(int key, int prime)
{
    return prime - (key % prime);
}
void Linear(int *htable, int *arr, int arraysize, int tablesize)
{
    int count = 0;
    for (int i = 0; i < tablesize; i++)
    {
        htable[i] = -1;
    }
    for (int i = 0; i < arraysize; i++)
    {
        int key = hashfun(arr[i], tablesize);
        if (htable[key] == -1)
        {
            htable[key] = arr[i];
        }
        else
        {
            while (htable[key] != -1)
            {
                int j = 1;
                key = (key + j) % tablesize;
                j++;
                count++;
            }
            htable[key] = arr[i];
        }
        printf("%d ", key);
    }
    printf("\n%d\n", count);
}
void quadratic(int *htable, int *arr, int arraysize, int tablesize)
{
    int count = 0;
    for (int i = 0; i < tablesize; i++)
    {
        htable[i] = -1;
    }
    for (int i = 0; i < arraysize; i++)
    {
        int key = hashfun(arr[i], tablesize);
        // if (htable[key] == -1)
        // {
        //     htable[key] = arr[i];
        // }
        // else
        // {
        //     while (htable[key] != -1)
        //     {
        //         int j = 1;
        //         key = (key + (j*j)) % tablesize;
        //         j++;
        //         count++;
        //     }
        //     htable[key] = arr[i];
        // }
        // printf("%d ", key);

        int j = 0;
        while (htable[(key + (j * j)) % tablesize] != -1)
        {
            j++;
            count++;
        }
        htable[(key + (j * j)) % tablesize] = arr[i];
        printf("%d ", (key + (j * j)) % tablesize);
    }
    printf("\n%d\n", count);
}

void doublehashing(int *htable, int *arr, int arraysize, int tablesize)
{
    int count = 0;
    for (int i = 0; i < tablesize; i++)
    {
        htable[i] = -1;
    }

    int prime = largePrime(tablesize);
    for (int i = 0; i < arraysize; i++)
    {
        int key = hashfun(arr[i], tablesize);

        int key2 = hashfun2(arr[i], prime);
        int j = 1;
        int index=key;
        while (htable[index]!=-1)
        {
            index=(index +( j*key2))%tablesize;
            j++;
            count++;
        }
        
        htable[index] = arr[i];

        printf("%d ", index);
    }
    printf("\n%d\n", count);
}

int main()
{
    int N, m;
    scanf("%d %d", &N, &m);
    int Arr[m];
    int hashtable[N];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &Arr[i]);
    }

    while (1)
    {
        char choice;
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            Linear(hashtable, Arr, m, N);
            break;
        case 'b':
            quadratic(hashtable, Arr, m, N);
            break;
        case 'c':
            doublehashing(hashtable, Arr, m, N);
            break;
        case 'd':
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}