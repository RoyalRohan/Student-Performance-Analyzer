#include <stdio.h>

#include "student.h"
#include "stats.h"

void topperList()
{
    FILE *fp;

    Student s;
    Student topper;

    int found = 0;

    fp = fopen("students.dat","rb");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    while(fread(&s,sizeof(Student),1,fp))
    {
        if(found == 0)
        {
            topper = s;
            found = 1;
        }

        if(s.gpa > topper.gpa)
        {
            topper = s;
        }
    }

    fclose(fp);

    if(found)
    {
        printf("\n==============================\n");
        printf("         TOPPER LIST\n");
        printf("==============================\n");

        printf("Name : %s\n", topper.name);
        printf("ID   : %d\n", topper.id);
        printf("GPA  : %.2f\n", topper.gpa);
        printf("Grade: %s\n", topper.grade);
    }
}

void classStatistics()
{
    FILE *fp;

    Student s;

    int count = 0;

    float totalGPA = 0;
    float highestGPA = 0;
    float lowestGPA = 4.0;

    fp = fopen("students.dat","rb");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    while(fread(&s,sizeof(Student),1,fp))
    {
        count++;

        totalGPA += s.gpa;

        if(s.gpa > highestGPA)
        {
            highestGPA = s.gpa;
        }

        if(s.gpa < lowestGPA)
        {
            lowestGPA = s.gpa;
        }
    }

    fclose(fp);

    if(count == 0)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n==============================\n");
    printf("      CLASS STATISTICS\n");
    printf("==============================\n");

    printf("Total Students : %d\n",count);

    printf("Highest GPA    : %.2f\n",highestGPA);

    printf("Lowest GPA     : %.2f\n",lowestGPA);

    printf("Average GPA    : %.2f\n",
           totalGPA / count);
}