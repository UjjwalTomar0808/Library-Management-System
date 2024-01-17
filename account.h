#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    char username[100];
    char password[100];
    int accountType;
    int suspended;
    int suspensionDays;
    struct Account* next;
};


struct Account* accountList = NULL;

void addAccount(char username[], char password[], int accountType) {
    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    strcpy(newAccount->username, username);
    strcpy(newAccount->password, password);
    newAccount->accountType = accountType;
    newAccount->suspended = 0;
    newAccount->suspensionDays = 0;
    newAccount->next = NULL;

    if (accountList == NULL) {
        accountList = newAccount;
    } else {
        struct Account* current = accountList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAccount;
    }

    printf("Account created successfully.\n");
}


struct Account* findAccount(char username[]) {
    struct Account* current = accountList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void removeAccount(char username[]) {
    struct Account* current = accountList;
    struct Account* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            if (prev == NULL) {
                accountList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Account deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Account not found.\n");
}

void suspendAccount(char username[], int suspensionDays) {
    struct Account* current = accountList;

    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            current->suspended = 1;
            current->suspensionDays = suspensionDays;
            printf("Account suspended successfully for %d days.\n", suspensionDays);
            return;
        }
        current = current->next;
    }

    printf("Account not found.\n");
}



int login(char username[], char password[]) {
    struct Account* current = accountList;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0 && current->suspended == 0) {
            return current->accountType;
        }
        current = current->next;
    }
    return -1;
}


#endif
