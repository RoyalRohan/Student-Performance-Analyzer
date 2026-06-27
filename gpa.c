#include <stdio.h>
#include <string.h>

#include "student.h"
#include "gpa.h"

float inputMarks(char subject[])
{
    float marks;

    while(1)
    {
        printf("%s : ", subject);
        scanf("%f", &marks);

        if(marks >= 0 && marks <= 100)
        {
            return marks;
        }

        printf("Invalid Marks! Please enter marks between 0 and 100.\n");
    }
}

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

        s.cProgramming = inputMarks("C Programming");
        s.digitalLogic = inputMarks("Digital Logic");
        s.mathematics = inputMarks("Mathematics");
        s.computerFundamentals = inputMarks("Computer Fundamentals");
        s.english = inputMarks("English");

        float average;

        average =
        (s.cProgramming +
        s.digitalLogic +
        s.mathematics +
        s.computerFundamentals +
        s.english) / 5.0;

        /* GPA & Grade Calculation */

        if(average >= 90)
        {
            s.gpa = 4.0;
            strcpy(s.grade,"A+");
        }
        else if(average >= 80)
        {
            s.gpa = 3.6;
            strcpy(s.grade,"A");
        }
        else if(average >= 70)
        {
            s.gpa = 3.2;
            strcpy(s.grade,"B+");
        }
        else if(average >= 60)
        {
            s.gpa = 2.8;
            strcpy(s.grade,"B");
        }
        else if(average >= 50)
        {
            s.gpa = 2.4;
            strcpy(s.grade,"C+");
        }
        else if(average >= 40)
        {
            s.gpa = 2.0;
            strcpy(s.grade,"C");
        }
        else if(average >= 35)
        {
            s.gpa = 1.6;
            strcpy(s.grade,"D+");
        }
        else if(average >= 20)
        {
            s.gpa = 1.2;
            strcpy(s.grade,"D");
        }
        else
        {
            s.gpa = 0.0;
            strcpy(s.grade,"NG");
        }

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

    int id;
    int found = 0;

    fp = fopen("students.dat","rb");

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

            printf("\n==============================\n");
            printf("      STUDENT MARKS\n");
            printf("==============================\n");

            printf("ID : %d\n",s.id);
            printf("Name : %s\n",s.name);

            printf("C Programming : %.2f\n",s.cProgramming);
            printf("Digital Logic : %.2f\n",s.digitalLogic);
            printf("Mathematics : %.2f\n",s.mathematics);
            printf("Computer Fundamentals : %.2f\n",s.computerFundamentals);
            printf("English : %.2f\n",s.english);

            printf("GPA : %.2f\n",s.gpa);
            printf("Grade : %s\n",s.grade);

            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }

    fclose(fp);
}
