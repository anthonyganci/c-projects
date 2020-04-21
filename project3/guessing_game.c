//Author: Anthony Ganci
//Class: CS 135 Assignment 3
//Date: 2/25/2020
//Purpose: This assignment ask the user for a seed to generate a random 
//number and then tells the user if their guess is higher or lower.

#include <stdio.h>
 
void printMenu()
{
    printf("GUESSING GAME\n");
    printf("Choose an option: \n");
    printf("1 - Generate Number\n");
    printf("2 - Guess Number\n");
    printf("0 - EXIT\n");
}
 
int getSeedValue() 
{
    int seed;

    printf("Enter a number to seed the generator: ");
    scanf("%d", &seed);

    return seed;
}
 
int generateNumber(int seedValue)
{
    int i = 2;
    while (i < 9)    {
        seedValue = (seedValue * i) / 3;
        i++;
    }

    return seedValue;   
}
 
int guessNumber(int numberToGuess, int userGuess)
{
    _Bool solved = 0;
    do 
        {
     if (userGuess > numberToGuess) { 
         printf("Your guess is too high, guess again: ");
         scanf("%d", &userGuess);
     }
     else if (userGuess < numberToGuess)    {
         printf("Your guess is too low, guess again: ");
         scanf("%d", &userGuess);
     }
     else if (userGuess = numberToGuess)    {
         printf("Congratulations! You guessed it!!!\n");
         solved++;
     }
} while (solved < 1); 

    return 0;
}
 
int main()
{
    int option;
    int seedValue;
    int numberToGuess = 42;
    int guessCheck;
    int userGuess;


do  {
    printMenu();
    scanf("%d", &option);
 
    switch(option)  {
        case 0: 
            break;
        case 1: 
            seedValue = getSeedValue();
            numberToGuess = generateNumber(seedValue);
            break;
        case 2:
            printf("Enter your guess: ");
            scanf("%d", &userGuess);

            guessCheck = guessNumber(numberToGuess, userGuess);

            break;
        default:
            printf("Please enter a valid option!\n");
            break;
    }
}while (option != 0);

return 0;
}
