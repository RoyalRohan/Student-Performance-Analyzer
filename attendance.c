#include <stdio.h>

#include "student.h"
#include "attendance.h"

void recordAttendance()
{
    FILE *fp;

    Student s;

    int id;
    int found = 0;

    fp = fopen("students.dat","rb+");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d",&id);

    while(fread(&s,sizeof(Student),1,fp))
    {
        if(s.id == id)
        {
            found = 1;

            printf("Attendance Percentage : ");
            scanf("%f",&s.attendance);

            fseek(fp,-sizeof(Student),SEEK_CUR);

            fwrite(&s,sizeof(Student),1,fp);

            printf("\nAttendance Saved Successfully!\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }

    fclose(fp);
}

void viewAttendance()
{
    FILE *fp;

    Student s;

    fp = fopen("students.dat","rb");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    printf("\n===============================\n");

    while(fread(&s,sizeof(Student),1,fp))
    {
        printf("\nID : %d\n",s.id);
        printf("Name : %s\n",s.name);
        printf("Attendance : %.2f %%\n",s.attendance);

        printf("---------------------------\n");
    }

    fclose(fp);
}