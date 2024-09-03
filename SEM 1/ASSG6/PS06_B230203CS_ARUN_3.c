#include <stdio.h>
char marksTograde(float n)
{
    if (n <= 100 && n >= 0)
    {
        if (n >= 80)
            return 'A';
        else if (n >= 60)
            return 'B';
        else if (n >= 50)
            return 'P';
        else if (n < 50)
            return 'F';
    }
    else
        return 'X';
}
int main()
{
    int num, marks;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        printf("Enter the marks of student %d: ", i);
        scanf("%d", &marks);
        if (marksTograde(marks) == 'X')
        {
            printf("Marks entered are out of range.!\n");
            i--;
            continue;
        }
        printf("Grade for student %d = %c\n", i, marksTograde(marks));
    }

    return 0;
}