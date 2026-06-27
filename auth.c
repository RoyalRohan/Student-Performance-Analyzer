#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "auth.h"

void startupScreen()
{
    printf("\n");
    printf("====================================================\n");
    printf("          STUDENT PERFORMANCE ANALYZER\n");
    printf("====================================================\n");
    printf("Loading System...\n");
    printf("System Ready...\n");
    printf("====================================================\n");
}

void hidePassword(char password[])
{
    struct termios old, new;

    int i = 0;
    char ch;

    tcgetattr(STDIN_FILENO, &old);

    new = old;
    new.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    while((ch = getchar()) != '\n')
    {
        if(ch == 127)
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            password[i] = ch;
            i++;
            printf("*");
        }
    }

    password[i] = '\0';

    tcsetattr(STDIN_FILENO, TCSANOW, &old);
}

int login()
{
    char username[30];
    char password[30];

    char correctUser[] = "admin";
    char correctPass[] = "1234";

    int attempts = 3;

    while(attempts > 0)
    {
        printf("\n");
        printf("============== LOGIN ==============\n");

        printf("Username : ");
        scanf("%s", username);

        getchar();

        printf("Password : ");
        hidePassword(password);

        printf("\n");

        if(strcmp(username, correctUser) == 0 &&
        strcmp(password, correctPass) == 0)
        {
            printf("\nLogin Successful!\n");
            return 1;
        }

        attempts--;

        printf("\nInvalid Username or Password!\n");
        printf("Remaining Attempts : %d\n", attempts);
    }

    return 0;
}