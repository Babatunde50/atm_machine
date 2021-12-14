#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned long accountBalance = 1000, deposition, withdrawal;
int pin, choice, k; // Defining few required variables in the transaction
char transaction = 'y';

char name[50] = "Babatunde ", lastName[] = "Ololade";
char date[] = "14/12/2021";

void printAccountOptions()
{
    strcat(name, lastName);
    printf("Hello %s, Welcome to our ATM Service\n", name);
    printf("Enter 1: View Account Balance\n");
    printf("Enter 2: Withdraw Cash \n");
    printf("Enter 3: Deposit Funds \n");
    printf("Enter 4: Card Return\n");
    printf("-----------------------\n\n");
    printf("Please proceed with your choice: ");
}

void depositFunds()
{
    printf("\n Insert the amount to be deposited: ");
    scanf("%lu", &deposition);
    accountBalance += deposition;
    printf("Your account balance is now ₺%lu", accountBalance);
}

void cardReturn()
{
    printf("\n We are thankful to you for USING our ATM services!");
}

void viewAccountBalance()
{
    printf("\n Your account balance is  ₺:%lu \n", accountBalance);
}

void deductFund(int amount)
{
    if (amount % 10 != 0)
    {
        printf("\n You are requested to insert the amount in multiples of 10");
    }
    else if (amount > accountBalance)
    {
        printf("\n You are having an insufficient balance");
    }
    else
    {
        accountBalance -= amount;
        printf("\n\n You can now collect your cash cash"); // after having a sufficient amount in the account the ATM machine will provide the cash amount.
        printf("\n Your current balance is ₺%lu", accountBalance);
    }
}

void withdrawCash()
{
    int withdrawalOption;

    printf("Withdrawal menu \n");
    printf("1 - ₺20 \t\t 4 - ₺100\n");
    printf("2 - ₺40 \t\t 5 - ₺200\n");
    printf("3 - ₺60 \t\t 6 - Enter another amount\n");
    printf("7 - Cancel transaction \n");

    printf("Please proceed with your choice: ");

    scanf("%d", &withdrawalOption);

    while (withdrawalOption < 1 || withdrawalOption > 7)
    {
        printf("\n You have made an invalid choice... Please select from the available options: ");

        printf("Withdrawal menu \n");
        printf("1 - ₺20 \t\t 4 - ₺100\n");
        printf("2 - ₺40 \t\t 5 - ₺200\n");
        printf("3 - ₺60 \t\t 6 - Enter another amount\n");
        printf("7 - Cancel transaction \n");

        printf("Please proceed with your choice: ");

        scanf("%d", &withdrawalOption);
    }

    switch (withdrawalOption)
    {
    case 1:
        deductFund(20);
        break;
    case 2:
        deductFund(40);
        break;
    case 3:
        deductFund(60);
        break;
    case 4:
        deductFund(100);
        break;
    case 5:
        deductFund(200);
        break;
    case 6:
        printf("Please enter the amount you will like to withdraw: ");
        int otherAmount;
        scanf("%d", &otherAmount);
        deductFund(otherAmount);
        break;
    case 7:
        // don't do anything
        break;
    }
}

void shouldContinue()
{
    printf("\n\n\n Would you like to have another ATM transaction?(y/n): ");
    fflush(stdin);
    scanf("%c", &transaction);
    if (transaction == 'n' || transaction == 'N')
    {
        k = 1;
    }
}

void shouldCancel()
{

    k = 1;
}

int main()
{
    // Using while loop to check for the condition on a pin number matching
    while (pin != 2025)
    {
        printf("Type your secret pin number:");
        scanf("%d", &pin);
        if (pin != 2025) // Checking if the pin number types by the user is matched with the database record or not
            printf("Please insert your valid password:\n");
    }

    do
    {
        printAccountOptions();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            viewAccountBalance();
            break;
        case 2:
            withdrawCash();
            break;
        case 3:
            depositFunds();
            break;
        case 4:
            cardReturn();
            break;
        default:
            printf("\n You have made an invalid choice");
        }
        (choice != 4) ? shouldContinue() : shouldCancel();

    } while (!k);
    printf("\n\n Thank you so much for your time to choose The our ATM services!");

    return 0;
}