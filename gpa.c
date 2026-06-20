#include <stdio.h>
#include <string.h>

#include "student.h"
#include "gpa.h"

void enterMarks()
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

            printf("\nEnter Marks\n");

            printf("C Programming : ");
            scanf("%f",&s.cProgramming);

            printf("Mathematics : ");
            scanf("%f",&s.mathematics);

            printf("English : ");
            scanf("%f",&s.english);

            printf("Statistics : ");
            scanf("%f",&s.statistics);

            printf("Physics : ");
            scanf("%f",&s.physics);

            float average;

            average =
            (s.cProgramming +
             s.mathematics +
             s.english +
             s.statistics +
             s.physics) / 5.0;

            s.gpa = average / 25.0;

            if(s.gpa >= 3.6)
                strcpy(s.grade,"A");
            else if(s.gpa >= 3.2)
                strcpy(s.grade,"B");
            else if(s.gpa >= 2.8)
                strcpy(s.grade,"C");
            else if(s.gpa >= 2.0)
                strcpy(s.grade,"D");
            else
                strcpy(s.grade,"F");

            fseek(fp,-sizeof(Student),SEEK_CUR);

            fwrite(&s,sizeof(Student),1,fp);

            printf("\nMarks Saved Successfully!\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }

    fclose(fp);
}

void viewMarks()
{
    FILE *fp;

    Student s;

    fp = fopen("students.dat","rb");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    printf("\n==================================================\n");

    while(fread(&s,sizeof(Student),1,fp))
    {
        printf("\nID : %d\n",s.id);
        printf("Name : %s\n",s.name);

        printf("C Programming : %.2f\n",s.cProgramming);
        printf("Mathematics : %.2f\n",s.mathematics);
        printf("English : %.2f\n",s.english);
        printf("Statistics : %.2f\n",s.statistics);
        printf("Physics : %.2f\n",s.physics);

        printf("GPA : %.2f\n",s.gpa);
        printf("Grade : %s\n",s.grade);

        printf("----------------------------------\n");
    }

    fclose(fp);
}