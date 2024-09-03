#include <stdio.h>

char G[100];

char marksToGrade(int);
void printGradeCount(void);
int gradeCount(char);



char marksToGrade(int n)
{
    if (n >= 80 && n <= 100)
        return 'A';
    if (n >= 60)
        return 'B';
    if (n >= 50)
        return 'P';
    if (n < 50 && n >= 0)
        return 'F';
    return 'X';
}
void printGradeCount()
{
    printf("Grade\tCount\n");
    printf("A\t%d\n",gradeCount('A'));
    printf("B\t%d\n",gradeCount('B'));
    printf("P\t%d\n",gradeCount('P'));
    printf("F\t%d\n",gradeCount('F'));
}

int gradeCount(char grade)
{ int count=0;
    for (int i = 0;G[i]!='\0'; i++)
    {
        if(G[i]==grade)
        {   
            count++;
        }
       
        
    }
    return count;
    
}
int main()
{
    int n;
    printf("Enter the number of students :");
    scanf("%d", &n);
    int M[n];
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter the marks of student %d :", i+1);
        scanf("%d", &M[i]);
        if (M[i]>100||M[i]<0)
        {
            printf("Invalid marks! Please enter a value between 0 and 100.\n");
            i--;
            continue;
        }
        
        G[i] = marksToGrade(M[i]);
    }
    printGradeCount();

    
        return 0;
}


