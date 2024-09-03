#include <stdio.h>
#include <string.h>
#include <ctype.h>



typedef struct {
    char name[100];
    
} book;
void insertionSort(book b[],int n)
{
    int i,j;
    book key;
    for( i=1 ; i<n ; i++)
    {
        key=b[i];
        j=i-1;
        while(j>=0 && strcmp(b[j].name,key.name)>0)
        {
            b[j+1]=b[j];
            j=j-1;
        }
        b[j+1]=key;
    }
}
int main(){
    int n;
   
    while(1)
    {
        scanf("%d",&n);
        if(n>=1 && n<=100000)
            {   
                getchar();
                break;
            
            }
            else {
            printf("Invalid input. Please enter a number between 1 and 100000.\n");
           
            while (getchar() != '\n');
        }
    }
     book b[n];
     
    for(int i=0;i<n;i++)
    {
        
        char c;
        int j=0;
        while ((c=fgetc(stdin))!='\n')
        {
            b[i].name[j]=c;
            j++;
            if(j>100)
            {
                printf("INVALID INPUT");
                return 0;

            }
        }
        b[i].name[j]='\0';
        
    }
    insertionSort(b,n);
    for(int i=0;i<n;i++)
    {
        printf("%s\n",b[i].name);
    }
    return 0;
}