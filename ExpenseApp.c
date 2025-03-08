#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define User Structure
struct User
{
    char firstName[30];
    char email[30];
    char password[30];
    struct User *next; // Pointer to next user
} *head = NULL;

// Function to check if email already exists
int emailExists(char email[])
{
    struct User *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->email, email) == 0)
        {
            return 1; // Email found
        }
        temp = temp->next;
    }
    return 0; // Email not found
}

// Function to Sign up
void signup()
{
    struct User *newUser = (struct User *)malloc(sizeof(struct User));

    printf("\nEnter First Name: ");
    scanf("%s", newUser->firstName);

    printf("Enter Email: ");
    scanf("%s", newUser->email);

    // Check if email already exists
    if (emailExists(newUser->email))
    {
        printf("Error: Email already registered!\n");
        free(newUser);
        return;
    }

    printf("Enter Password: ");
    scanf("%s", newUser->password);

    // Insert user into linked list
    newUser->next = head;
    head = newUser;

    printf("\nSignup Successful!\n");
}

// Function to Login
struct User *login()
{
    char email[30], password[30];

    printf("\nEnter Email: ");
    scanf("%s", email);

    printf("Enter Password: ");
    scanf("%s", password);

    struct User *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->email, email) == 0 && strcmp(temp->password, password) == 0)
        {
            printf("\nLogin Successful! Welcome, %s\n", temp->firstName);
            return temp;
        }
        temp = temp->next;
    }

    printf("\nInvalid Email or Password!\n");
    return NULL;
}

// void displayUsers()
// {
//     if (head == NULL)
//     {
//         printf("\nNo users found!\n");
//         return;
//     }

//     struct User *temp = head;
//     printf("\nList of Registered Users:\n");
//     printf("-----------------------------------\n");
//     while (temp != NULL)
//     {
//         printf("Name: %s\n", temp->firstName);
//         printf("Email: %s\n", temp->email);
//         printf("-----------------------------------\n");
//         temp = temp->next;
//     }
// }

void displayUsers() {
    if (head == NULL) {
        printf("\nNo users found!\n");
        return;
    }

    struct User* temp = head;
    
    printf("\n==========================================================\n");
    printf("|                     Registered Users                   |\n");
    printf("==========================================================\n");
    printf("| %-3s | %-20s | %-25s |\n", "No", "Name", "Email");
    printf("----------------------------------------------------------\n");

    int count = 1;
    while (temp != NULL) {
        printf("| %-3d | %-20s | %-25s |\n", count, temp->firstName, temp->email);
        temp = temp->next;
        count++;
    }
    
    printf("==========================================================\n");
}

// Main Function
int main()
{
    int choice;
    struct User *currentUser;
    while (1)
    {
        printf("\n1 For Signup\n2 For Login\n3 For Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            signup();
            break;
        case 2:
            currentUser = login();
            if (currentUser != NULL)
            {
                printf("\n%s => ", currentUser->firstName);
            }
            break;
        case 3:
            printf("\nExiting Program...\n");
            return 0;
        case 0:
            displayUsers();break;
        default:
            printf("\nInvalid Choice! Try Again.\n");
        }
    }
}
