#include <stdio.h>
char marksToGrade(int);
void printResults(int);
struct student
{
    char rollnumber[100];
    int marks;
    char grade;

} M[100];

void printStudent(struct student);
char marksToGrade(int marks)
{
    if (marks >= 0 && marks <= 100)
    {
        if (marks >= 80)
        {
            return 'A';
        }
        if (marks >= 60)
        {
            return 'B';
        }
        if (marks >= 50)
        {
            return 'P';
        }
        if (marks >= 0)
        {
            return 'F';
        }

        return 'X';
    }
}
void printStudent(struct student s1)
{
    printf("%s %d %c \n", s1.rollnumber, s1.marks, s1.grade);
}
void printResults(int n)
{
    for (int i = 0; i < n; i++)
    {
        printStudent(M[i]);
    }
}
int main()
{
    int n;
    do
    {
        printf("Enter the number of students: ");
        scanf("%d", &n);
        if (n < 1 || n > 100)
        {
            printf("Invalid number of students!\nPlease enter a value between 1 and 100\n");
        }

    } while (n < 1 || n > 100);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the rollnumber and marks: ");
        scanf("%s %d", M[i].rollnumber, &M[i].marks);
        if (M[i].marks < 0 || M[i].marks > 100)
        {
            printf("Invalid value for marks!\nEnter a value between 0 and 100!\n");
            i--;
            continue;
        }

        M[i].grade = marksToGrade(M[i].marks);
    }

    printResults(n);

    return 0;
}
