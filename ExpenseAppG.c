#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Expense Structure
struct Expense {
    char title[30];
    int amount;
    struct Expense* next;
};

// User Structure
struct User {
    char firstName[30];
    char email[30];
    char password[30];
    char accountName[30];  // Account name
    int balance;         // Account balance
    struct Expense* expenses; // Linked list of expenses
    struct User* next;     // Next user
} *head = NULL;

void addAccount(struct User* user) {
    printf("\nEnter Account Name: ");
    scanf("%s", user->accountName);

    printf("Enter Initial Balance: ");
    scanf("%d", &user->balance);


    printf("\nAccount Created Successfully with %d amount !\n",user->balance);
}


void addExpense(struct User* user) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));

    printf("\nEnter Expense Title: ");
    scanf("%s", newExpense->title);

    printf("Enter Expense Amount: ");
    scanf("%d", &newExpense->amount);

    // Deduct from balance
    if (newExpense->amount > user->balance) {
        printf("\nInsufficient Balance!\n");
        free(newExpense);
        return;
    }

    user->balance -= newExpense->amount;

    // Insert into expense list
    newExpense->next = user->expenses;
    user->expenses = newExpense;

    printf("\nExpense Added Successfully!\n");
}


void listExpenses(struct User* user) {
    struct Expense* temp = user->expenses;

    if (temp == NULL) {
        printf("\nNo Expenses Found!\n");
        return;
    }

    printf("\n===================================\n");
    printf("        Expense List\n");
    printf("===================================\n");
    printf("| %-3s | %-20s | %-10s |\n", "No", "Title", "Amount");
    printf("-----------------------------------\n");

    int count = 1;
    while (temp != NULL) {
        printf("| %-3d | %-20s | ₹%d |\n", count, temp->title, temp->amount);
        temp = temp->next;
        count++;
    }

    printf("===================================\n");
}



void checkBalance(struct User* user) {
    printf("\nCurrent Balance: ₹ %d\n", user->balance);
}


void userMenu(struct User* user) {
    int choice;

    while (1) {
        printf("\n0. Add Account\n1. Add Expense\n2. List Expenses\n3. Check Balance\n4. Logout\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                addAccount(user);
                break;
            case 1:
                addExpense(user);
                break;
            case 2:
                listExpenses(user);
                break;
            case 3:
                checkBalance(user);
                break;
            case 4:
                printf("\nLogging Out...\n");
                return;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }
}

void login() {
    char email[30], password[30];

    printf("\nEnter Email: ");
    scanf("%s", email);

    printf("Enter Password: ");
    scanf("%s", password);

    struct User* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0 && strcmp(temp->password, password) == 0) {
            printf("\nLogin Successful! Welcome, %s\n", temp->firstName);
            userMenu(temp);
            return;
        }
        temp = temp->next;
    }

    printf("\nInvalid Email or Password!\n");
}

void signup() {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));

    printf("\nEnter First Name: ");
    scanf("%s", newUser->firstName);

    printf("Enter Email: ");
    scanf("%s", newUser->email);

    // Check if the email already exists
    struct User* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->email, newUser->email) == 0) {
            printf("\nError: Email already registered! Try a different one.\n");
            free(newUser);
            return;
        }
        temp = temp->next;
    }

    printf("Enter Password: ");
    scanf("%s", newUser->password);

    // Initialize user details
    strcpy(newUser->accountName, "");  // Empty account name
    newUser->balance = 0;              // Zero balance
    newUser->expenses = NULL;          // No expenses
    newUser->next = head;
    head = newUser;

    printf("\nSignup Successful!\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n1 For Signup\n2 For Login\n3 For Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                printf("\nExiting Program...\n");
                return 0;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }
}
