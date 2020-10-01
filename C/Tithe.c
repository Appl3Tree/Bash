/*
	Programmer: Forrest Connelly
	Program: Tithe
	Goal: Take in the gross income and output the tithe and first fruits. 
*/

//	Include the standard input/output header.
#include <stdio.h>

//	Every C program needs a main function.
int main( void ) {
	
	//	Declare variables.
	float grossIncome;
	float firstFruits;
	float tithe;
//	float thirdTithe;	//	Will be used later.

	//	Prompt user to enter gross income. Store input in grossIncome.
	printf( "%s", "Please enter your gross income (before taxes):\t$" );
	scanf( "%f", &grossIncome );

	//	Blank line for readability.
	puts( "" );

	//	Perform arithmetic and output the firstFruits and tithe.
	firstFruits = grossIncome * 0.025;
	printf( "First Fruits 2.5%%:\t$%.2f\n", firstFruits );
	
	//	Set new grossIncome equal to grossIncome minus the First Fruits.
	grossIncome = grossIncome - firstFruits;
	tithe = grossIncome * 0.10;
	printf( "Tithe 10%%:\t\t$%.2f\n", tithe );

	//	Set new grossIncome.
	grossIncome = grossIncome - tithe;
	printf( "Remaining income:\t$%.2f\n", grossIncome );
}
