#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int noOfStudents,noOfFaculty;
struct Student
{
    int arrival;
};
struct Faculty
{
    int arrival;
};

int main()
{

    printf("\n\a\n\t\t\t\t\t\t\t\t\t Welcome\n\n");Sleep(2000);
    printf("\n\n\n\t\t\t\tLoading\n");Sleep(1000);
    int chioce;
    printf("\n\nEnter the number of STUDENTS\n");
    scanf("%d",&noOfStudents);
    struct Student st[noOfStudents];
    if(noOfStudents!=0)
    {
        a:  printf("\nNow enter their ARRIVAL time, ARRIVAL time should be positive integer and atmost 120 minutes beacause  SUDESH SHARMA will be available from 10am to 12am only(2hrs).\n");
        for(int i=0;i<noOfStudents;i++)
        {
            scanf("%d",&st[i].arrival);
            if(st[i].arrival>120||st[i].arrival<0)
            {
              printf("\nPlease retry!\n");
              goto a;
            }
        }
    }
    printf("\nEnter the number of Faculties\n");
    scanf("%d",&noOfFaculty);
    struct Faculty ft[noOfFaculty];
    if(noOfFaculty!=0)
    {
        b:  printf("\nNow enter their ARRIVAL time, ARRIVAL time should be positive integer and atmost 120 minutes beacause  SUDESH SHARMA will be available from 10am to 12am only(2hrs).\n");
        for(int i=0;i<noOfFaculty;i++)
        {
            scanf("%d",&ft[i].arrival);
            if(ft[i].arrival>120||ft[i].arrival<0)
            {
              printf("\nPlease retry!\n");
              goto b;
            }
        }
    }
    int total=noOfFaculty+noOfStudents;

    // Sorting on the basis of arrival time
    // For Students

    for(int i=0;i<noOfStudents-1;i++)
    {
        for(int j=0;j<noOfStudents-1;j++)
        {
            if(st[j+1].arrival<st[j].arrival)
            {
              int temp; temp=st[j].arrival;
              st[j].arrival=st[j+1].arrival;
              st[j+1].arrival=temp;
            }
        }
    }

    // Sorting on the basis of arrival time
    // For Faculties

    for(int i=0;i<noOfFaculty-1;i++)
    {
        for(int j=0;j<noOfFaculty-1;j++)
        {
            if(ft[j+1].arrival<ft[j].arrival)
            {
              int temp; temp=ft[j].arrival;
              ft[j].arrival=ft[j+1].arrival;
              ft[j+1].arrival=temp;
            }
        }
    }

   if(total!=0)
    {
        printf("\n\n\t\t\tThe sequence of handling queue is\n\n ");
        int i,j,cnt=0;
        for(i=0,j=0;i<noOfStudents&&j<noOfFaculty;)
        {
           if(st[i].arrival<=ft[j].arrival)
           {
              cnt++;  printf("\nThe %d user is a Student with arrival time %d\n",cnt,st[i].arrival);
              i++;
           }
           else
           {
              cnt++;  printf("\nThe %d user is a Faculty with arrival time %d\n",cnt,ft[j].arrival);
              j++;
           }
        }

        if(i<noOfStudents)
          for(;i<noOfStudents;i++)
          {
             cnt++;  printf("\nThe %d user is a Student with arrival time %d\n",cnt,st[i].arrival);
          }

        if(j<noOfFaculty)
          for(;j<noOfFaculty;j++)
          {
              cnt++;  printf("\nThe %d user is a Faculty with arrival time %d\n",cnt,ft[j].arrival);
          }

        printf("\n\nAs Sudesh Sharma will work from 10 to 12AM, so the total time is 2hrs.\n");
        printf("\n\nAs the total number of users are %d, so the time share is %d minutes per person.\n",total,120/total);
    }
    else printf("\n\n\t\t\tNo users so no scheduling required!\n\n");
    printf("\n\n\n\n\t\t\t\t\t");Sleep(5000);
    char x[]="Thank You!";
    for(int i=0;i<sizeof(x);i++)
    {
        printf("%c",x[i]);Sleep(120);
    }
    printf("\n\n\n\t\t");
    return 0;
}

