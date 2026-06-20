#include <stdio.h>

#include "auth.h"
#include "student.h"
#include "gpa.h"
#include "attendance.h"
#include "stats.h"
#include "report.h"

int main()
{
    int choice;

    startupScreen();

    if(!login())
    {
        printf("\nToo Many Failed Attempts!\n");
        return 0;
    }

    do
    {
        printf("\n");
        printf("====================================\n");
        printf("    STUDENT PERFORMANCE ANALYZER\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Enter Marks\n");
        printf("7. View Marks\n");
        printf("8. Record Attendance\n");
        printf("9. View Attendance\n");
        printf("10. Topper List\n");
        printf("11. Class Statistics\n");
        printf("12. Generate Report\n");
        printf("0. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;
            
            case 6:
                enterMarks();
                break;
            
            case 7:
                viewMarks();
                break;
            
            case 8:
                recordAttendance();
                break;
            
            case 9:
                viewAttendance();
                break;
            
            case 10:
                topperList();
                break;
            
            case 11:
                classStatistics();
                break;

            case 12:
                generateReport();
                break;

            case 0:
                printf("\nThank You For Using Student Performance Analyzer!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    }while(choice != 0);

    return 0;
}