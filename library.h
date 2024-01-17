#ifndef LIBRARY_H
#define LIBRARY_H


#include "library.h"
#include "book.h"
#include <stdio.h>

void clearScreenAndWait() {
    printf("\nPress any key to return to the main menu...");
    getchar();
    getchar(); 
}

void superuserMenu() {
    int suspensionDays;
    int choice;
    char username[100];
    char password[100];
    char title[100];
    char author[100];
    float price;
    int quantity;
    char studentName[100];
    char admissionNo[100];
    int classNo;
    char section;

    while (1) {
        printf("\nSuperuser Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search for a Book\n");
        printf("3. Display Available Books\n");
        printf("4. Remove Book\n");
        printf("5. Issue a Book\n");
        printf("6. Display Issued Books\n");
        printf("7. Remove Issued Book\n");
        printf("8. Display Overdue Students\n");
        printf("9. Delete Account\n");
        printf("10. Suspend Account\n");
        printf("11. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        	case 1:
                printf("Add Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Price: ");
                scanf("%f", &price);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addBook(title, author, price, quantity);
                clearScreenAndWait();
                break;
            case 2:
                printf("Search for a Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                struct Book* foundBook;
                foundBook = searchBook(title);
                if (foundBook != NULL) {
                    printf("Book found: Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
                           foundBook->title, foundBook->author, foundBook->price, foundBook->quantity);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 3:
                printf("Display Available Books\n");
                displayAvailableBooks();
                break;
             case 4:
                printf("Remove Book\n");
                printf("Enter Book Title to Remove: ");
                scanf("%s", title);
                removeBook(title);
                clearScreenAndWait();
                break;
            case 5:
                printf("Issue a Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Student Name: ");
                scanf("%s", studentName);
                printf("Enter Admission No: ");
                scanf("%s", admissionNo);
                printf("Enter Class No: ");
                scanf("%d", &classNo);
                printf("Enter Section: ");
                scanf(" %c", &section);
                issueBook(title, author, studentName, admissionNo, classNo, section);
                break;
            case 6:
                printf("Display Issued Books\n");
                displayIssuedBooks();
                break;
            case 7:
                printf("Remove Issued Book\n");
                printf("Enter Book Title to Remove from Issued List: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Student Name: ");
                scanf("%s", studentName);
                removeIssuedBook(title, author, studentName);
                break;
            case 8:
                printf("Display Overdue Students\n");
                displayOverdueStudents();
                break;
            case 9:
                printf("Delete Account\n");
                printf("Enter username to delete: ");
                scanf("%s", username);
                removeAccount(username);
                break;
            case 10:
                printf("Suspend Account\n");
                printf("Enter username to suspend: ");
                scanf("%s", username);
                printf("Enter suspension period in days: ");
                scanf("%d", &suspensionDays);
                suspendAccount(username, suspensionDays);
                break;
            case 11:
                printf("Logged out.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}


void studentMenu(char username[]) {
    int choice;
    char title[100];
    char author[100];
    char studentName[100];
    char admissionNo[100];
    int classNo;
    char section;

    while (1) {
        printf("\nStudent Menu:\n");
        printf("1. Search for a Book\n");
        printf("2. Display Available Books\n");
        printf("3. Issue a Book\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Search for a Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                struct Book* foundBook;
                foundBook = searchBook(title);
                if (foundBook != NULL) {
                    printf("Book found: Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
                           foundBook->title, foundBook->author, foundBook->price, foundBook->quantity);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 2:
                printf("Display Available Books\n");
                displayAvailableBooks();
                break;
            case 3:
                printf("Issue a Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Your Name: ");
                scanf("%s", studentName);
                printf("Enter Your Admission No: ");
                scanf("%s", admissionNo);
                printf("Enter Your Class No: ");
                scanf("%d", &classNo);
                printf("Enter Your Section: ");
                scanf(" %c", &section);
                issueBook(title, author, studentName, admissionNo, classNo, section);
                break;
            case 4:
                printf("Logged out.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void staffMenu(char username[]) {
    int choice;
    // char username[100];
    char password[100];
    char title[100];
    char author[100];
    float price;
    int quantity;
    char studentName[100];
    char admissionNo[100];
    int classNo;
    char section;

    while (1) {
        printf("\nStaff Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search for a Book\n");
        printf("3. Display Available Books\n");
        printf("4. Remove Book\n");
        printf("5. Issue a Book\n");
        printf("6. Display Issued Books\n");
        printf("7. Remove Issued Book\n");
        printf("8. Display Overdue Students\n");
        printf("9. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        	case 1:
                printf("Add Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Price: ");
                scanf("%f", &price);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addBook(title, author, price, quantity);
                clearScreenAndWait();
                break;
            case 2:
                printf("Search for a Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                struct Book* foundBook = searchBook(title);
                if (foundBook != NULL) {
                    printf("Book found: Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
                           foundBook->title, foundBook->author, foundBook->price, foundBook->quantity);
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 3:
                printf("Display Available Books\n");
                displayAvailableBooks();
                break;
            case 4:
                printf("Remove Book\n");
                printf("Enter Book Title to Remove: ");
                scanf("%s", title);
                removeBook(title);
                clearScreenAndWait();
                break;
            case 5:
                printf("Issue a Book\n");
                printf("Enter Book Title: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Student Name: ");
                scanf("%s", studentName);
                printf("Enter Admission No: ");
                scanf("%s", admissionNo);
                printf("Enter Class No: ");
                scanf("%d", &classNo);
                printf("Enter Section: ");
                scanf(" %c", &section);
                issueBook(title, author, studentName, admissionNo, classNo, section);
                break;
            case 6:
                printf("Display Issued Books\n");
                displayIssuedBooks();
                break;
            case 7:
                printf("Remove Issued Book\n");
                printf("Enter Book Title to Remove from Issued List: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Student Name: ");
                scanf("%s", studentName);
                removeIssuedBook(title, author, studentName);
                break;
            case 8:
                printf("Display Overdue Students\n");
                displayOverdueStudents();
                break;
            case 9:
                printf("Logged out.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}


void displayMainMenu() {
    printf("\nMain Menu:\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}


#endif 
