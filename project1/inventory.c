//Ask user to input an inventory item 3 times and then displays their item
#include <stdio.h>

int main()	{

//Variables	
	int quantity1, quantity2, quantity3;
	int code1, code2, code3;	
	double price1, price2, price3;

//Gathering user inputted information
	printf("What is your first inventory item?\n(enter quantity, code, price) ");
	scanf("%d %d %lf", &quantity1, &code1, &price1);
	
	printf("What is your second inventory item?\n(enter quantity, code, price) ");
	scanf("%d %d %lf", &quantity2, &code2, &price2);

	printf("What is your third inventory item?\n(enter quantity, code, price) ");
	scanf("%d %d %lf", &quantity3, &code3, &price3);		

//Displays user inputted information
	printf("\n INVENTORY\n|==============================================|\n|Item Code   |   Item Quantity   |   Item Price|\n|------------|-------------------|-------------|\n|%9d   |%9d          |   %5.2lf     |\n|==============================================|\n|%9d   |%9d          |   %5.2lf     |\n|==============================================|\n|%9d   |%9d          |   %5.2lf     |\n|==============================================|\n", code1, quantity1, price1, code2, quantity2, price2, code3, quantity3, price3);

return 0;
}
