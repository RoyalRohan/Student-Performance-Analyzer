#include <stdio.h>

#include "student.h"
#include "report.h"

void generateReport()
{
    FILE *fp;
    FILE *report;

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

        report = fopen("report.txt","w");

        fprintf(report,
        "===== STUDENT REPORT =====\n\n");

        fprintf(report,
        "ID : %d\n",
        s.id);

        fprintf(report,
        "Name : %s\n",
        s.name);

        fprintf(report,
        "Age : %d\n",
        s.age);

        fprintf(report,
        "Section : %s\n\n",
        s.section);

        fprintf(report,
        "C Programming : %.2f\n",
        s.cProgramming);

        fprintf(report,
        "Mathematics : %.2f\n",
        s.mathematics);

        fprintf(report,
        "English : %.2f\n",
        s.english);

        fprintf(report,
        "Digital Logic : %.2f\n",
        s.digitalLogic);

        fprintf(report,
        "Computer Fundamentals : %.2f\n",
        s.computerFundamentals);

        fprintf(report,
        "\nAttendance : %.2f%%\n",
        s.attendance);

        fprintf(report,
        "GPA : %.2f\n",
        s.gpa);

        fprintf(report,
        "Grade : %s\n",
        s.grade);

        fclose(report);

        printf("\nReport Generated Successfully!\n");
        printf("Saved As report.txt\n");

        break;
        }
}

if(found == 0)
{
        printf("\nStudent Not Found!\n");
}

fclose(fp);
}