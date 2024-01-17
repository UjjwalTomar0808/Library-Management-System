#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "book.h"
#include "library.h"

int main() {
    int choice;
    char username[100];
    char password[100];

    addAccount("admin", "adminpass", 2);

    while (1) {
        system("cls");  

        printf("####################################\n");
        printf("Welcome to Library Management System\n");
        printf("####################################\n");


        printf("\nMain Menu:\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Create Account\n");
                printf("Enter a new username: ");
                scanf("%s", username);
                printf("Enter a password: ");
                scanf("%s", password);
                printf("Select account type (0: student, 1: staff, 2: superuser): ");
                int accountType;
                scanf("%d", &accountType);
                addAccount(username, password, accountType);
                // printf("Account created successfully.\n");
                clearScreenAndWait();
                break;
            case 2:
                printf("Login\n");
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                struct Account* userAccount = findAccount(username);
                if (userAccount != NULL && strcmp(userAccount->password, password) == 0) {
                    if (userAccount->accountType == 0) {
                       
                        printf("Login successful. Welcome, %s (Student)!\n", username);
                        studentMenu(username);
                    } else if (userAccount->accountType == 1) {
                        
                        printf("Login successful. Welcome, %s (Staff)!\n", username);
                        staffMenu(username);
                    } else if (userAccount->accountType == 2) {
                       
                        printf("Login successful. Welcome, %s (Superuser)!\n", username);
                        superuserMenu();
                    }
                } else {
                    printf("Login failed. Invalid username or password.\n");
                    clearScreenAndWait();
                }
                break;
            case 3:
                printf("Goodbye! Have a great day.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                clearScreenAndWait();
        }
    }

    return 0;
}
