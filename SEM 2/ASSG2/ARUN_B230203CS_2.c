#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 50
typedef struct student
{
    char name[MAX_LEN];
    int marks;
} record;
int charToInt(char *str)
{
    int num=0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        num=(num*10)+str[i]-'0';

    }
    return num;
    
}
record *FindRank(record *student, int n, int r)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (student[j + 1].marks > student[j].marks)
            {
                record temp = student[j + 1];
                student[j + 1] = student[j];
                student[j] = temp;
            }
        }
    }
    return &student[r-1];
}

int main()
{
    int N;
    //printf("Enter the number of students: ");
    scanf("%d", &N);
    getchar();
    record *student = (record *)malloc(N * sizeof(student));
    if (student == NULL)
    {
        printf("Error Memory allocation failed.");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
       // printf("Enter name: ");
        char num[2];
        int x=0;
        //scanf("%s", student[i].name);
        fgets(student[i].name,sizeof(student[i].name),stdin);
        student[i].name[strcspn(student[i].name,"\n")]='\0';
        if (student[i].name[0]=='\0')
        {
            printf("Empty input.Please try again\n");
            i--;
            continue;
        }
        
        int j=0;
        while (student[i].name[j]!='\0'&&!isdigit(student[i].name[j]))
        {
            j++;
        }
        if (isdigit(student[i].name[j]))
        {   
            student[i].marks=charToInt(&student[i].name[j]);
            student[i].name[j]='\0';
        }
        else printf("Invalid input.");
        
        
        //printf("%s and %d\n",student[i].name,student[i].marks);

    }
//printf("Enter the rank : ");
    int r;
    scanf("%d", &r);


    record *Ranker = FindRank(student, N, r);
    printf("%s %d", Ranker->name, Ranker->marks);
    free(student);

    return 0;
}