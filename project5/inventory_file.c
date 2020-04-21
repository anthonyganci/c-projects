#include <stdio.h>
#define FILE_NAME "inventory_file.txt"

int getMenuChoice();
void displayInventory(FILE *fp);
void addInventory(FILE *fp);

int main()  {
    int userChoice;
    FILE *fp;
    
    do
    {
        userChoice = getMenuChoice();
        switch (userChoice)
        {
        case 0:
            break;
        case 1:
            fp = fopen(FILE_NAME, "r");
            displayInventory(fp);
            break;
        case 2:
            fp = fopen(FILE_NAME, "w");
            addInventory(fp);
            fclose(fp);
            break;
        default:
            printf("Please enter a valid option!\n");
            break;
        }

    } while (userChoice != 0);
    
}

int getMenuChoice() {
        int choice;

    printf("***INVENTORY SYSTEM***\n");
    printf("1 - display inventory\n");
    printf("2 - add inventory\n");
    printf("0 - EXIT\n");
    scanf("%d", &choice);

    return choice;
}

void displayInventory(FILE *fp) {
    int quantity, partNum;
    double price; 
    
    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open file\n");
    }
    else
    {
        printf(" INVENTORY\n==================================================\n||Item Code   |   Item Quantity   |   Item Price||\n||==============================================||\n||------------|-------------------|-------------||\n");
        while (!feof(fp))
        {
            fscanf(fp, "\n%d %lf %d",&quantity, &price, &partNum);
            printf("||%9d   |%9d          |%7.2lf      ||\n", partNum, quantity, price);
            printf("||------------|-------------------|-------------||\n");
        }
        printf("==================================================\n");
    }
}
void addInventory(FILE *fp) {
    int numOfInv = 0, count = 0;
    int quantity, partNum;
    double price; 

    if (fp == NULL) 
    {
        fprintf(stderr, "Can't open file.\n");
    }
    else
    {
        printf("How many items are you adding? ");
        scanf("%d", &numOfInv);

        while (count != numOfInv)
        {
           printf("Enter a quantity: ");
           scanf("%d", &quantity);
           
           printf("Enter a price: ");
           scanf("%lf", &price);

           printf("Enter a six digit part number: ");
           scanf("%d", &partNum);

           fprintf(fp, "\n%d %.2lf %d", quantity, price, partNum);
           count++;
        }
        
    }
    
}