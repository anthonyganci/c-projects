//Author: Anthony Ganci
//Class: CS 135 Project 4
//Date: 3/5/2020
//Purpose: Complex Calculator

#include <stdio.h>

int getMenuChoice();
void getComplexNumber(double *realNum,double *imagNum);
void addComplexNumber(double realNum1, double realNum2, double imagNum1, double imagNum2, double *sumReal, double *sumImag);
void subtractComplexNumbers(double realNum1, double realNum2, double imagNum1, double imagNum2, double *difReal, double *difImag);
void multiplyComplexNumbers(double realNum1, double realNum2, double imagNum1, double imagNum2, double *prodReal, double *prodImag);
void displayComplexNumbers(double combReal, double combImag);

int main()  {
    int userChoice;
    double realNumber1, imagNumber1, realNumber2, imagNumber2, combReal, combImag;

    do  {
        userChoice = getMenuChoice();
        switch(userChoice)  {
            case 0:
                break;
            case 1: 
                getComplexNumber(&realNumber1, &imagNumber1);
                getComplexNumber(&realNumber2, &imagNumber2);
                addComplexNumber(realNumber1, realNumber2, imagNumber1, imagNumber2, &combReal, &combImag);
                displayComplexNumbers(combReal, combImag);

                break;
            case 2:
                getComplexNumber(&realNumber1, &imagNumber1);
                getComplexNumber(&realNumber2, &imagNumber2);
                subtractComplexNumbers(realNumber1, realNumber2, imagNumber1, imagNumber2, &combReal, &combImag);
                displayComplexNumbers(combReal, combImag);

                break;
            case 3:
                getComplexNumber(&realNumber1, &imagNumber1);
                getComplexNumber(&realNumber2, &imagNumber2);
                multiplyComplexNumbers(realNumber1, realNumber2, imagNumber1, imagNumber2, &combReal, &combImag);
                displayComplexNumbers(combReal, combImag);

                break;
            default:
                printf("Please enter a valid option!\n");
                break;  
    }
}while (userChoice != 0);

    return 0;
}
//Displays menu and gets user choice.
int getMenuChoice() {
    int choice;

    printf("***COMPLEX NUMBER CALCULATOR***\n");
    printf("1 - addition\n");
    printf("2 - subtraction\n");
    printf("3 - multiplication\n");
    printf("0 - EXIT\n");
    scanf("%d", &choice);

    return choice;
}
//Gets input
void getComplexNumber(double *realNum,double *imagNum) {
    printf("Enter the real component: ");
    scanf("%lf", realNum);

    printf("Enter the imaginary component: ");
    scanf("%lf", imagNum);
}
//Takes the complex numbers inputted adds them and saves them to the address two variables.
void addComplexNumber(double realNum1, double realNum2, double imagNum1, double imagNum2, double *sumReal, double *sumImag) {
    *sumReal = realNum1 + realNum2;
    *sumImag = imagNum1 + imagNum2;
}
//Takes the complex numbers inputted subtracts them and saves them to the address two variables.
void subtractComplexNumbers(double realNum1, double realNum2, double imagNum1, double imagNum2, double *difReal, double *difImag)   {
    *difReal = realNum1 - realNum2;
    *difImag = imagNum1 - imagNum2;
}
//Takes the complex numbers inputted multiplies them and saves them to the address two variables.
void multiplyComplexNumbers(double realNum1, double realNum2, double imagNum1, double imagNum2, double *prodReal, double *prodImag) {
    *prodReal = (realNum1 * realNum2) - (imagNum1 * imagNum2);
    *prodImag = (realNum1 * imagNum2) + (realNum2 * imagNum1);
}
//Displays variables.
void displayComplexNumbers(double combReal, double combImag) {
    printf("*RESULT*\n");
    printf("%.2lf + %.2lfi\n", combReal, combImag);
}