// ATM BANKING
#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
    system("color 9f");
    int pin = 1234, enterpin, option, count = 0, amount = 1;
    float balance = 5000;
    int continueTransaction = 1;
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t\t%s", ctime(&now));
    printf("\n\t\t\t\t===========WELCOME TO THE ATM BANKING===========");

    while (pin != enterpin)
    {
        printf("\n ENTER YOUR PIN NUMBER: ");
        scanf("%d", &enterpin);
        if (enterpin != pin)
            ;
        {
            Beep(600, 500);
            printf("\n INVALID PIN!!!");
        }
        count++;
        if (count == 5 && pin != enterpin)
        {
            printf("\n\tYOUR CARD HAS BEEN BLOCKED");
            exit(0);
        }
    }
    while (continueTransaction != 0)
    {
        printf("\n\t\t\t================AVAILABE TRANSACTIONS================");
        printf("\n\tPLEASE SELECT AN OPTION;\n");
        printf("\n\n\t\t1.WITHDRAWL");
        printf("\n\n\t\t2.DEPOSIT");
        printf("\n\n\t\t3.CHECK BALANCE\n\t");

        scanf("%d", &option);
        switch (option)
        {
        case 1:
            while (amount % 100 != 0)
            {
                printf("\n\tENTER THE AMOUNT:");
                scanf("%d", &amount);
                if (amount % 100 != 0)
                {
                    printf("\n\tamount should be multiple of 100");
                }
                if (balance < amount)
                {
                    printf("\n\t SORRY YOU HAVE INSUFFICIENT BALANCE");
                    amount = 1;
                    break;
                }
                else
                {
                    balance -= amount;
                    printf("\n\t YOU HAVE WITHDRAWN Rs:%d,YOUR NEW BALANCE IS:%.2f", amount, balance);
                    amount = 1;
                    break;
                }
            }

        case 2:
            printf("\n\t ENTER THE AMOUNT:");
            scanf("%d", &amount);
            balance += amount;
            printf("\n\tYOU HAVE DEPOSITE Rs.%d,YOUR NEW BALANCE IS:%.2f", amount, balance);
            amount = 1;
            printf("\n\t\t\t============THANK YOU FOR USING ATM BANKING============");
            break;

        case 3:
            printf("\n\tYOUR BALANCE IS Rs:%.2f,balance");
            break;

        default:
            Beep(610, 500);
            printf("\n\t\tINVALID OPTION!!!");
        }
        printf("\n\t\tDO YOU WISH TO PERFORM ANOTHER TRANSACTION?press 1[Yes],0[No]\n");
        scanf("%d", &continueTransaction);
    }

    return 0;
}