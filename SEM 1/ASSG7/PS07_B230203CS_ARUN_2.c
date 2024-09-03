#include <stdio.h>
int HighestMarks(int, int);
int LowestMarks(int, int);
float AvgMarks(int, int);
int TotalMarks(int);
int Marks[100][3];
int main()
{
    int n, choice, courseID, StudentID;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the marks for student %d \n", i + 1);
        for (int j = 0; j < 3; j++)

        {
            printf("Marks for course %d: ", j + 1);
            scanf("%d", &Marks[i][j]);
        }
    }
    while (1)
    {
        printf("\nPlease enter a number indicating your choice:\n");
        printf("1: Highest mark in a course\n");
        printf("2: Lowest mark in a course\n");
        printf("3: Average marks for a course\n");
        printf("4: Total marks of a student\n");
        printf("0: Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("Enter the course ID : ");
            scanf("%d", &courseID);
            printf("Highest mark in course %d: %d\n", courseID, HighestMarks(courseID, n));
            break;
        case 2:
            printf("Enter the course ID : ");
            scanf("%d", &courseID);
            printf("Lowest mark in course %d: %d\n", courseID, LowestMarks(courseID, n));
            break;
        case 3:
            printf("Enter the course ID : ");
            scanf("%d", &courseID);
            printf("Average mark in course %d: %f\n", courseID, AvgMarks(courseID, n));
            break;
        case 4:
            printf("Enter the student ID : ");
            scanf("%d", &StudentID);
            printf("Total marks for student %d: %d\n", StudentID, TotalMarks(StudentID));
            break;
        default:
            printf("Please enter a value between 0 and 5!\n");
            break;
        }
    }

    return 0;
}
int HighestMarks(int course, int n)
{
    int max = Marks[0][course];
    for (int i = 0; i < n; i++)
    {
        if (Marks[i][course] > max)
        {
            max = Marks[i][course];
        }
    }
    return max;
}
int LowestMarks(int course, int n)
{
    int min = Marks[0][course];
    for (int i = 0; i < n; i++)
    {
        if (Marks[i][course] < min)
        {
            min = Marks[i][course];
        }
    }
    return min;
}
float AvgMarks(int course, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += Marks[i][course];
    }
    return (float)sum / n;
}
int TotalMarks(int n)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += Marks[n][i];
    }
    return sum;
}
