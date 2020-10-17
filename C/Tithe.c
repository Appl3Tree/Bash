/*
	Programmer: Forrest Connelly
	Program: Tithe
	Goal: Take in the gross income and output the tithe and first fruits. 
*/

//	Include the standard input/output and math headers.
#include <stdio.h>
#include <math.h>

//	Every C program needs a main function.
int main( void )
{
	//	Declare variable(s).
	double firstFruitsPercent;
	double tithePercent;
//	double thirdTithePercent;	Will be used later.
	double grossIncome;
	int firstFruits;
	int tithe;
	int grossIncomePennies;
	
	//	Initialize variable(s).
	firstFruitsPercent = 0.025;
	tithePercent = 0.10;
//	thirdTithePercent = 0.033;	Will be used later.
	grossIncome = 0.00;
	firstFruits = 0;
	tithe = 0;
	grossIncomePennies = 0;

	//	Blank line for readability.
	puts( "" );

	//	Prompt user to enter their gross income. Store the input in grossIncome.
	printf( "%s", "Please enter your gross income (before taxes):\t$" );
	scanf( "%lf", &grossIncome );

	//	Blank line for separation.
	puts( "" );

	//	Turn the grossIncome into pennies.
	grossIncomePennies = grossIncome * 100;

	//	Perform arithmetic to determine the firstFruits in pennies then print out the result of First Fruits.
	firstFruits = floor( grossIncomePennies * firstFruitsPercent );
	//	If...else statement necessary to ensure the result has two decimal places.
	if ( firstFruits % 100 < 10 ) {
		printf( "First Fruits 2.5%%:\t$%d.%d0\n", firstFruits / 100, firstFruits % 100 );
	} else {
		printf( "First Fruits 2.5%%:\t$%d.%d\n", firstFruits / 100, firstFruits % 100 );
	}
	
	//	Subtract First Fruits from the grossIncomePennies.
	grossIncomePennies -= firstFruits;

	//	Perform arithmetic to determine the tithe in pennies then print out the result of Tithe.
	tithe = floor( grossIncomePennies * tithePercent );
	//	If...else statement necessary to ensure the result has two decimal places.
	if ( tithe % 100 < 10 ) {
		printf( "Tithe 10%%:\t\t$%d.%d0\n", tithe / 100, tithe % 100 );
	} else {
		printf( "Tithe 10%%:\t\t$%d.%d\n", tithe / 100, tithe % 100 );
	}
	
	//	Subtract Tithe from the grossIncomePennies.
	grossIncomePennies -= tithe;
	
	//	Print out the remaining income. If...else statement necessary to ensure the result has two decimal places.
	if ( grossIncomePennies % 100 == 0 ) {
		printf( "Remaining income:\t$%d.%d0\n", grossIncomePennies / 100, grossIncomePennies % 100 );
	} else {
		printf( "Remaining income:\t$%d.%d\n", grossIncomePennies / 100, grossIncomePennies % 100 );
	}
}
