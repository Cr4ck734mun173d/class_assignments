#include <stdio.h>

struct student
{
    char rollnumber[20];

    union marksORgrade
    {
        int marks;
        char grade;
    } result;

} M[100];

void printResults()
{

    printf("Results:\nRollNo Grade/Marks\n");
    for (int i = 0; M[i].rollnumber[0] != '\0'; i++)
    {

        if (M[i].rollnumber[0] == 'M')
        {
            printf("%s %c\n", M[i].rollnumber, M[i].result.grade);
        }
        else
            printf("%s %d\n", M[i].rollnumber, M[i].result.marks);
    }
}

int main()
{
    int n;
    int marks;
    do
    {
        printf("Enter the number of students: ");
        scanf("%d", &n);
        if (n < 1 || n > 100)
        {
            printf("Invalid number of students!\nPlease enter a value between 1 and 100\n");
        }

    } while (n < 1 || n > 100);
    printf("Enter the roll no and marks : ");

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", M[i].rollnumber, &marks);
        if (marks < 0 || marks > 100)
        {
            printf("Error invalid marks\nEnter a value between 0 and 100!\n");
            i--;
            continue;
        }
        if (M[i].rollnumber[0] == 'M')
        {
            if (marks >= 50)
            {
                M[i].result.grade = 'P';
            }
            else
                M[i].result.grade = 'F';
        }
        else
            M[i].result.marks = marks;
    }
    printResults();
    return 0;
}