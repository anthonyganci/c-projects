/*
Purpose: This program generates a password by encoding user inputs.
Author: Anthony Ganci
Class: CS135
Assignment 2
*/
#include <stdio.h>

//changes the age to a float value
double encodeIntToDouble(int a)
{
	double multiplier = 1.6;
	
	return a * multiplier;
}

//changes the money in pocket to a character
char encodeDoubleToChar(double a)
{
	int moneyInt = a;
	int remainderMoney = (moneyInt % 3);
	char moneyToChar = remainderMoney, exclamation = '!';
	
	return moneyToChar + exclamation;

}

//changes the users initial to an integer
int encodeCharToInt(char a)
{
	int initialValue = a + 12;

	return initialValue;
}

//prints code after encoding is done
void printNewCode(double ageDouble, char moneyChar, int initialInt)
{
	printf("%d-%.2lf-%c\n", initialInt, ageDouble, moneyChar);
	
}

//main function
int main()
{
	int age;
	double money;
	char initial;

	printf("Please enter the first initial of your first name: ");
	scanf("%c", &initial);
	printf("Please enter your age: ");
	scanf("%d", &age);
	printf("Please enter how much money is in your pocket: ");
	scanf("%lf", &money);
	
	double ageDouble = encodeIntToDouble(age);
	char moneyChar = encodeDoubleToChar(money);
	int initialInt = encodeCharToInt(initial);

	printNewCode(ageDouble, moneyChar, initialInt);

	return 0;
}





