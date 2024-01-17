#ifndef BOOK_H
#define BOOK_H


#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Book {
    char title[100];
    char author[100];
    float price;
    int quantity;
    struct Book* next;
};

struct Issue {
    char title[100];
    char author[100];
    char studentName[100];
    char admissionNo[100];
    int classNo;
    char section;
    char dateOfIssue[20];
    struct Issue* next;
};


struct Book* library = NULL;  // Definition of the head pointer for the library

struct Issue* issuedBooks = NULL;

struct Book* searchBook(char title[]) {
    struct Book* current = library;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayAvailableBooks() {
    struct Book* current = library;
    if (current == NULL) {
        printf("The library is empty.\n");
        return;
    }
    printf("Available Books:\n");
    while (current != NULL) {
        if (current->quantity > 0) {
            printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
                   current->title, current->author, current->price, current->quantity);
        }
        current = current->next;
    }
}

void displayBooks() {
    struct Book* current = library;
    if (current == NULL) {
        printf("The library is empty.\n");
        return;
    }
    printf("Book List:\n");
    while (current != NULL) {
        printf("Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
               current->title, current->author, current->price, current->quantity);
        current = current->next;
    }
}

void addBook(char title[], char author[], float price, int quantity) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->price = price;
    newBook->quantity = quantity;
    newBook->next = library;
    library = newBook;
    printf("Book added successfully.\n");
}

void removeBook(char title[]) {
    struct Book* current = library;
    struct Book* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                library = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Book removed successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Book not found.\n");
}

void issueBook(char title[], char author[], char studentName[], char admissionNo[], int classNo, char section) {
    struct Book* current = library;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0 && strcmp(current->author, author) == 0) {
            if (current->quantity > 0) {
                struct Issue* newIssue = (struct Issue*)malloc(sizeof(struct Issue));
                strcpy(newIssue->title, title);
                strcpy(newIssue->author, author);
                strcpy(newIssue->studentName, studentName);
                strcpy(newIssue->admissionNo, admissionNo);
                newIssue->classNo = classNo;
                newIssue->section = section;
                time_t now;
                struct tm current_time;
                time(&now);
                current_time = *localtime(&now);
                strftime(newIssue->dateOfIssue, 20, "%Y-%m-%d %H:%M:%S", &current_time);

                newIssue->next = issuedBooks;
                issuedBooks = newIssue;

                current->quantity--;
                printf("Book issued successfully.\n");
                return;
            } else {
                printf("No more copies available for this book.\n");
                return;
            }
        }
        current = current->next;
    }

    printf("Book not found.\n");
}

void displayIssuedBooks() {
    struct Issue* current = issuedBooks;
    if (current == NULL) {
        printf("No books have been issued.\n");
        return;
    }
    printf("Issued Book List:\n");
    while (current != NULL) {
        printf("Title: %s, Author: %s\n", current->title, current->author);
        printf("Student Name: %s, Admission No: %s\n", current->studentName, current->admissionNo);
        printf("Class: %d, Section: %c\n", current->classNo, current->section);
        printf("Date of Issue: %s\n", current->dateOfIssue);
        printf("\n");
        current = current->next;
    }
}

void removeIssuedBook(char title[], char author[], char studentName[]) {
    struct Issue* current = issuedBooks;
    struct Issue* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0 &&
            strcmp(current->author, author) == 0 &&
            strcmp(current->studentName, studentName) == 0) {
            if (prev == NULL) {
                issuedBooks = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Issued book removed successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Issued book not found.\n");
}

void displayOverdueStudents() {
    struct Issue* current = issuedBooks;
    int hasOverdueStudents = 0;

    time_t now;
    struct tm current_time;
    time(&now);
    current_time = *localtime(&now);

    while (current != NULL) {
        int dayOfIssue, monthOfIssue, yearOfIssue;
        sscanf(current->dateOfIssue, "%d-%d-%d", &yearOfIssue, &monthOfIssue, &dayOfIssue);

        int daysSinceIssue = (current_time.tm_year + 1900 - yearOfIssue) * 365 +
                             (current_time.tm_mon + 1 - monthOfIssue) * 30 +
                             (current_time.tm_mday - dayOfIssue);

        if (daysSinceIssue > 30) {
            int fine = (daysSinceIssue - 30) * 5;
            printf("Student Name: %s, Admission No: %s\n", current->studentName, current->admissionNo);
            printf("Book Title: %s, Author: %s, Days Since Issue: %d, Fine: Rs. %d, Date of Issue: %s\n", current->title, current->author, daysSinceIssue, fine, current->dateOfIssue);
            hasOverdueStudents = 1;
        }
        current = current->next;
    }

    if (!hasOverdueStudents) {
        printf("No overdue students.\n");
    }
}


#endif 
