#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    int id;
    char name[50];
    int age;
    char section[10];

    float cProgramming;
    float mathematics;
    float english;
    float statistics;
    float physics;

    float attendance;

    float gpa;
    char grade[5];

} Student;

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif
