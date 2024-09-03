#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

char *LargestName(char **names, int n)
{
    int max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (strlen(names[i]) > max)
        {
            max = strlen(names[i]);
            index = i;
        }
    }
    if (index == -1)
    {
        printf("Error no name found");
        return NULL;
    }

    return names[index];
}

int main()
{
    int n;
   // printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar();
    if (n<=0)
    {
        printf("Error invalid input . ");
    }
    
    char **names = (char **)malloc(n * (sizeof(char *)));
    if (names == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }
    //printf("Enter names: ");
    for (int i = 0; i < n; i++)
    {
        char buffer[MAX_LEN];
        fgets(buffer, MAX_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0]=='\0')
        {
            printf("Error. Empty name.Please enter name again.\n");
            i--;
            continue;
        }
        

        names[i] = (char *)malloc((strlen(buffer) + 1) * (sizeof(char)));
        if (names[i] == NULL)
        {
            printf("Memory allocation failed.");
            return 1;
        }

        strcpy(names[i], buffer);
    }
    if (LargestName!=NULL)
    {
       printf("%s", LargestName(names, n));
    }
    
    
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
    return 0;
}