#include <stdio.h>
#include <string.h>

#include "student.h"

void addStudent()
{
    FILE *fp;

    Student s;
    s.cProgramming = 0;
    s.digitalLogic = 0;
    s.mathematics = 0;
    s.computerFundamentals = 0;
    s.english = 0;

    s.attendance = 0;

    s.gpa = 0;

strcpy(s.grade,"N/A");

    fp = fopen("students.dat", "ab");

    if(fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("\n===== ADD STUDENT =====\n");

    printf("Student ID : ");
    scanf("%d", &s.id);

    getchar();

    printf("Student Name : ");
    fgets(s.name, sizeof(s.name), stdin);

    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Age : ");
    scanf("%d", &s.age);

    printf("Section : ");
    scanf("%s", s.section);

    fwrite(&s, sizeof(Student), 1, fp);

    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}

void viewStudents()
{
    FILE *fp;

    Student s;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("No Student Records Found!\n");
        return;
    }

    printf("\n=============================================\n");
    printf("ID\tName\t\tAge\tSection\n");
    printf("=============================================\n");

    while(fread(&s, sizeof(Student), 1, fp))
    {
        printf("%d\t%s\t\t%d\t%s\n",
               s.id,
               s.name,
               s.age,
               s.section);
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp;

    Student s;

    int id;
    int found = 0;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("No Student Records Found!\n");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d", &id);

    while(fread(&s, sizeof(Student), 1, fp))
    {
        if(s.id == id)
        {
            found = 1;

            printf("\n===== STUDENT FOUND =====\n");

            printf("ID      : %d\n", s.id);
            printf("Name    : %s\n", s.name);
            printf("Age     : %d\n", s.age);
            printf("Section : %s\n", s.section);

            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }

    fclose(fp);
}

void updateStudent()
{
    FILE *fp;

    Student s;

    int id;
    int found = 0;

    fp = fopen("students.dat", "rb+");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    printf("\nEnter Student ID : ");
    scanf("%d", &id);

    while(fread(&s,sizeof(Student),1,fp))
    {
        if(s.id == id)
        {
            found = 1;

            getchar();

            printf("New Name : ");
            fgets(s.name,sizeof(s.name),stdin);

            s.name[strcspn(s.name,"\n")] = '\0';

            printf("New Age : ");
            scanf("%d",&s.age);

            printf("New Section : ");
            scanf("%s",s.section);

            fseek(fp,-sizeof(Student),SEEK_CUR);

            fwrite(&s,sizeof(Student),1,fp);

            printf("\nRecord Updated Successfully!\n");

            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }

    fclose(fp);
}

void deleteStudent()
{
    FILE *fp;
    FILE *temp;

    Student s;

    int id;
    int found = 0;

    fp = fopen("students.dat","rb");

    if(fp == NULL)
    {
        printf("File Not Found!\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    printf("\nEnter Student ID : ");
    scanf("%d",&id);

    while(fread(&s,sizeof(Student),1,fp))
    {
        if(s.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&s,sizeof(Student),1,temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat","students.dat");

    if(found)
    {
        printf("\nStudent Deleted Successfully!\n");
    }
    else
    {
        printf("\nStudent Not Found!\n");
    }
}