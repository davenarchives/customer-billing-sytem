/* 
This is a simple Customer Billing System
Note: 
- Account Number only exceeds at 10 digits (1234567890) 
- Customer Name only works with one name */


#include <stdio.h>
#include <string.h>

// Using structure to represent customer data
struct Customer {
    int accountNumber;
    char name[50];
    float moneyDeposited;
    float totalExpenses;
    float remainingBalance;
    int isValid; // Check if the account is valid or invalid
};

// Using function to add a new account to the system
void addAccount(struct Customer accounts[], int *numAccounts) {
    struct Customer newCustomer;

    // Enter account number
    printf("=======================================\n");
    printf("\t      ADD ACCOUNT\t");
    printf("\n=======================================\n");
    printf("Enter account number\t:\t");
    scanf("%d", &newCustomer.accountNumber);

    // Check if the account number is duplicate
    int i;
    for (i = 0; i < *numAccounts; ++i) {
        if (accounts[i].accountNumber == newCustomer.accountNumber) {
            printf("=======================================\n");
            printf("Account with the given account number\n");
            printf("already exists. ");
            printf("Adding account failed.");
            return;
        }
    }
    
    // Enter customer name
    printf("Enter customer name\t:\t");
    scanf("%s", newCustomer.name);

    // Check if the customer name is duplicate
    for (i = 0; i < *numAccounts; ++i) {
        if (strcmp(accounts[i].name, newCustomer.name) == 0) {
            printf("=======================================\n");
            printf("Account with the given name \n");
            printf("already exists. ");
            printf("Adding account failed.");
            return;
        }
    }
    // Enter initial amount to deposit 
    printf("Enter amount to deposit\t:\tPhp");
    scanf("%f", &newCustomer.moneyDeposited);

    // Initialize other account details
    newCustomer.totalExpenses = 0;
    newCustomer.remainingBalance = 0;
    newCustomer.isValid = 1;
    accounts[*numAccounts] = newCustomer;

    *numAccounts += 1;

    printf("=======================================\n");
    printf("Account added successfully!");
}

// Function to search for an account based on name or number
void searchAccount(struct Customer accounts[], int numAccounts) {
    int choice;
    printf("=======================================\n");
    printf("\t(1) Search by Name\n");
    printf("\t(2) Search by Number\n");
    printf("=======================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Search by name
        char searchName[50];
        printf("=======================================\n");
        printf("Enter customer name to search: ");
        scanf("%s", searchName);

        int i;
        for (i = 0; i < numAccounts; ++i) {
            // Using strcmp (string compare) if the account is valid and matches the name
            if (accounts[i].isValid && strcmp(accounts[i].name, searchName) == 0) {
                // After validating it prints the account details
                printf("=======================================\n");
                printf("\t      ACCOUNT DATA\t");
                printf("\n=======================================\n");
                printf("Account Number     \t:\t %d\n", accounts[i].accountNumber);
                printf("Customer Name      \t:\t %s\n", accounts[i].name);
                printf("Money Deposited    \t:\t Php%.2f\n", accounts[i].moneyDeposited);
                printf("Total Expenses     \t:\t Php%.2f\n", accounts[i].totalExpenses);
                printf("Remaining Balance  \t:\t Php%.2f\n", accounts[i].remainingBalance);
                return;
            }
        }
        // If given name is unregistered it will print this
        printf("=======================================\n");
        printf("Account not found for the given name.");
    } else if (choice == 2) {
        // Search by account number
        int searchNumber;
        printf("=======================================\n");
        printf("Enter account number to search: ");
        scanf("%d", &searchNumber);

        int i;
        for (i = 0; i < numAccounts; ++i) {
            // Verifying if the account number is valid and account number matches
            if (accounts[i].isValid && accounts[i].accountNumber == searchNumber) {
                // Print account details 
                printf("=======================================\n");
                printf("\t      ACCOUNT DATA\t");
                printf("\n=======================================\n");
                printf("Account Number     \t:\t %d\n", accounts[i].accountNumber);
                printf("Customer Name      \t:\t %s\n", accounts[i].name);
                printf("Money Deposited    \t:\t Php%.2f\n", accounts[i].moneyDeposited);
                printf("Total Expenses     \t:\t Php%.2f\n", accounts[i].totalExpenses);
                printf("Remaining Balance  \t:\t Php%.2f\n", accounts[i].remainingBalance);
                return;
            }
        }
        // If the account number is not registered it will print this
        printf("=======================================\n");
        printf("Account not found for the given number.");
    } else {
        // If your choice is neither from the choices it will print this
        printf("=======================================\n");
        printf("Invalid choice. Please try again.");
    }
}

// Function to perform transactions (deposit, withdrawal, payment)
void performTransaction(struct Customer accounts[], int numAccounts) {
    int accountNumber, choice;
    printf("=======================================\n");
    printf("Enter account number for the transaction: ");
    scanf("%d", &accountNumber);

    int i;
    for (i = 0; i < numAccounts; ++i) {
        // Check if the account is valid and account number matches
        if (accounts[i].isValid && accounts[i].accountNumber == accountNumber) {
            // Print account details
            printf("=======================================\n");
            printf("\t      ACCOUNT DATA\t");
            printf("\n=======================================\n");
            printf("Account Number     \t:\t %d\n", accounts[i].accountNumber);
            printf("Customer Name      \t:\t %s\n", accounts[i].name);
            printf("Money Deposited    \t:\t Php%.2f\n", accounts[i].moneyDeposited);
            printf("Total Expenses     \t:\t Php%.2f\n", accounts[i].totalExpenses);
            printf("Remaining Balance  \t:\t Php%.2f\n", accounts[i].remainingBalance);
            printf("=======================================\n");

            // Transaction choices
            printf("\t(1) Deposit Money \n");
            printf("\t(2) Withdraw Money \n");
            printf("\t(3) Add Payment ");
            printf("\n=======================================\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                // Deposit money
                float amount;
                printf("=======================================\n");
                printf("Enter the amount to deposit: Php");
                scanf("%f", &amount);
                accounts[i].moneyDeposited += amount;
                accounts[i].remainingBalance = accounts[i].moneyDeposited - accounts[i].totalExpenses;
                printf("=======================================\n");
                printf("Deposit successful!");
            } else if (choice == 2) {
                // Withdraw money 
                float amount;
                printf("=======================================\n");
                printf("Enter the amount to withdraw: Php");
                scanf("%f", &amount);

                if (amount <= accounts[i].moneyDeposited && accounts[i].remainingBalance >= 0) {
                    // Check if withdrawal amount is valid
                    accounts[i].moneyDeposited -= amount;
                    accounts[i].remainingBalance = accounts[i].moneyDeposited - accounts[i].totalExpenses;
                    printf("=======================================\n");
                    printf("Withdrawal successful!");
                } else {
                    printf("=======================================\n");
                    printf("Invalid withdrawal. Insufficient funds.\n");
                }
            } else if (choice == 3) {
                // Add payment
                float amount;
                printf("=======================================\n");
                printf("Enter the payment amount: Php");
                scanf("%f", &amount);
                accounts[i].totalExpenses += amount; 
                accounts[i].remainingBalance = accounts[i].moneyDeposited - accounts[i].totalExpenses;
                printf("=======================================\n");
                printf("Payment added successfully!");
            } else {
                // If neither of the choices was made it will print this
                printf("=======================================\n");
                printf("Invalid choice. Transaction canceled.\n");
            }

            return;
        }
    }
    // If account is not registered it will print this
    printf("=======================================\n");
    printf("Account not found for the given number.");
}

// Function to display main menu
void displayMenu() {
    printf("\n=======================================\n");
    printf("\tCUSTOMER BILLING SYSTEM\n");
    printf("            ---Main Menu---");
    printf("\n=======================================\n");
    printf("\t(1) Add Account\n");
    printf("\t(2) Search Account\n");
    printf("\t(3) New Transaction\n");
    printf("\t(4) Exit\n");
    printf("=======================================\n");
}

// Main function 
int main() {
    struct Customer accounts[100];
    int numAccounts = 0;
    int choice;

    // Main menu loop 
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Using switch statement to handle user choices
        switch (choice) {
        case 1:
            addAccount(accounts, &numAccounts);
            break;
        case 2:
            searchAccount(accounts, numAccounts);
            break;
        case 3:
            performTransaction(accounts, numAccounts);
            break;
        case 4:
            printf("=======================================\n");
            printf("Exiting program. Goodbye!\n");
            printf("=======================================\n");
            break;
        default:
            printf("=======================================\n");
            printf("Invalid choice. Please try again.");
        }

    } while (choice != 4); // Exit loop when the user chooses to exit, and the program ends

    return 0;
}
