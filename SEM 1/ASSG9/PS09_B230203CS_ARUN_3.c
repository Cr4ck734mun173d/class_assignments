#include <stdio.h>
 void readMarks(int a[],int n)
    {
       for (int i = 0; i < n; i++)
       {
        scanf("%d",&a[i]);
        if (a[i]<0||a[i]>100)
        {
            printf("Error!Invalid marks.\nEnter values between 0 and 100.\n");
            i--;
            continue;  
        }
        
       }
        
    }
void marksToGrade(int a[],char b[],int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i]<=100 && a[i]>=0)
        {
            if (a[i]>=80)
            {
                b[i]='A';
            }
            if (a[i]<80&&a[i]>=60)
            {
                b[i]='B';
            }
            if (a[i]<60&&a[i]>=50)
            {
                b[i]='P';
            }
            if (a[i]<50)
            {
                b[i]='F';
            }
        }
       
        
    }
    
}
void printGradeCount(char a[],int n)
{   
    int A=0,B=0,F=0,P=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]=='A')
        {
            A++;
        }
        if (a[i]=='B')
        {
            B++;
        }
        if (a[i]=='P')
        {
            P++;            
        }
        if (a[i]=='F')
        {
            F++;
        }
        
    }
    printf("A\t%d\n",A);
    printf("B\t%d\n",B);
    printf("P\t%d\n",P);
    printf("F\t%d\n",F);
}
int main()
{
    int n;
    while(1){
        scanf("%d",&n);
        if(n>100||n<1)
        {
            printf("Invalid value !\nPlease enter a value between 1 and 100\n");
            continue;
        }
        else break;
    }
    int M[n];
    char G[n];
    //int *ptrM=&M,*ptrG=&G;
   readMarks(M,n);
   marksToGrade(M,G,n);
   printGradeCount(G,n);
}