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
	double hourlyRate;
	double firstFruitsPercent;
	double tithePercent;
//	double thirdTithePercent;	Will be used later.
	double grossIncome;
	double nikiSalary;
//	double taxRate;			Will be used later.
	int rateChange;
	int hoursWorked;
	int firstFruits;
	int tithe;
	int grossIncomePennies;
	
	//	Initialize variable(s).
	hourlyRate = 19.8265;
	firstFruitsPercent = 0.025;
	tithePercent = 0.10;
//	thirdTithePercent = 0.033;	Will be used later.
	grossIncome = 0.00;
	nikiSalary = 1630.00;
//	taxRate = 0.253026227303295;	Will be used later.
	rateChange = 0;
	hoursWorked = 0;
	firstFruits = 0;
	tithe = 0;
	grossIncomePennies = 0;

	//	Blank line for readability.
	puts( "" );

	//	Prompt user to enter their gross income. Store the input in grossIncome.
	printf( "%s", "Enter the number of hours worked this month:\t" );
	scanf( "%d", &hoursWorked );

	//	Ask if hourly rate has changed.
	printf( "Has your hourly rate changed from $%.4lf per hour? (1 = no or 2 = yes): ", hourlyRate );
	scanf( "%d", &rateChange );
	if ( rateChange == 2 )
	{
		printf( "%s", "Enter what it has changed to per hour ($XX.XX):\t$" );
		scanf( "%lf", &hourlyRate );
	}
	grossIncome = (hourlyRate * hoursWorked) + nikiSalary;

	//	Blank line for separation.
	puts( "" );

	//	Print out Forrest's monthly gross income and Niki's gross income.
	printf( "Forrest's Gross Monthly Income:\t$%.2lf\n", grossIncome - nikiSalary);
	printf( "Niki's Gross Monthly Income:\t$%.2lf\n", nikiSalary );
	printf( "Combined Gross Income:\t\t$%.2lf\n", grossIncome );

	//	Blanke line for separation.
	puts( "" );

	//	Turn the grossIncome into pennies.
	grossIncomePennies = grossIncome * 100;

	//	Perform arithmetic to determine the firstFruits in pennies then print out the result of First Fruits.
	firstFruits = floor( grossIncomePennies * firstFruitsPercent );
	//	If...else statement necessary to ensure the result has two decimal places.
	if ( firstFruits % 100 < 10 ) {
		printf( "First Fruits 2.5%%:\t\t$%d.0%d\n", firstFruits / 100, firstFruits % 100 );
	} else {
		printf( "First Fruits 2.5%%:\t\t$%d.%d\n", firstFruits / 100, firstFruits % 100 );
	}
	
	//	Subtract First Fruits from the grossIncomePennies.
	grossIncomePennies -= firstFruits;

	//	Perform arithmetic to determine the tithe in pennies then print out the result of Tithe.
	tithe = floor( grossIncomePennies * tithePercent );
	//	If...else statement necessary to ensure the result has two decimal places.
	if ( tithe % 100 < 10 ) {
		printf( "Tithe 10%%:\t\t\t$%d.0%d\n", tithe / 100, tithe % 100 );
	} else {
		printf( "Tithe 10%%:\t\t\t$%d.%d\n", tithe / 100, tithe % 100 );
	}
	
	//	Subtract Tithe from the grossIncomePennies.
	grossIncomePennies -= tithe;
	
	//	Print out the remaining income. If...else statement necessary to ensure the result has two decimal places.
	if ( grossIncomePennies % 100 == 0 ) {
		printf( "Remaining income:\t\t$%d.0%d\n", grossIncomePennies / 100, grossIncomePennies % 100 );
	} else {
		printf( "Remaining income:\t\t$%d.%d\n", grossIncomePennies / 100, grossIncomePennies % 100 );
	}

	//	If rateChange was 2, then inform user to update the hourlyRate in
	//	the source code.
	if ( rateChange == 2 )
	{
		puts( "" );
		printf( "%s", "********************\n" );
		printf( "%s", "********NOTE********\n" );
		printf( "%s", "********************\n" );
		printf( "%s", "\nPlease update the source code to have your new hourly rate.\n" );
	}
	//	Enter a blank line at the end for readability.
	puts( "" );
}
