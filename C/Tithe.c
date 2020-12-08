/*
	Programmer: Forrest Connelly
	Program: Tithe
	Goal: Take in the gross income and output the tithe and first fruits. 
*/

//	Include the standard input/output and math headers.
#include <stdio.h>
#include <math.h>
#define SIZE 2

//	Function prototype(s) before the main function.
int convertToDollars( int pennies );
int convertToCents( int pennies );
int convertToPennies( double x );
double convertToNetIncome( int pennies );

//	Every C program needs a main function.
int main( void )
{
	//	Declare variable(s).
	unsigned int hoursWorked;
	int firstFruits;
	int tithe;
	int grossIncomeInPennies;
	char rateChange[SIZE];
	double hourlyRate;
	double incomeFromNiki;
	double grossIncome;
	double firstFruitsPercent;
	double tithePercent;
//	double thirdTithePercent;	Will be used later
	
	//	Initialize varible(s).
	hoursWorked = 0;
	firstFruits = 0;
	tithe = 0;
	grossIncomeInPennies = 0;
	rateChange[0] = ' ';
	hourlyRate  = 19.8265;
	incomeFromNiki = 1630.00;
	grossIncome = 0.00;
	firstFruitsPercent = 0.025;
	tithePercent = 0.10;
//	thirdTithePercent = 0.033; 	Will be used later.

	//	Blank line for readability.
	puts( "" );

	//	Prompt user to enter hours worked this month. Store input in grossIncome.
	printf( "%s", "Enter the number of hours worked this month:\t" );
	scanf( "%u", &hoursWorked );

	//	Ask if the hourly rate has changed.
	printf( "Has your hourly rate changed from $%.4lf per hour? (y/n): ", hourlyRate );
	scanf( "%1s", rateChange );
	switch ( rateChange[0] )
	{
		case 'Y':
		case 'y':
			printf( "%s", "Enter what it has changed to per hour ($XX.XX):\t$" );
			scanf( "%lf", &hourlyRate );
			break;
		default:
			break;
	}
	
	//	Ask if there are multiple incomes.

	//	For now, manually add multiple incomes to grossIncome.
	grossIncome = ( hourlyRate * hoursWorked ) + incomeFromNiki;

	//	Blank line for readability.
	puts( "" );

	//	Print out Niki's and my gross incomes.
	printf( "Forrest's Gross Monthly Income:\t$%.2lf\n", grossIncome - incomeFromNiki );
	printf( "Niki's Gross Monthly Income:\t$%.2lf\n", incomeFromNiki );
	printf( "Combined Gross Income:\t\t$%.2lf\n", grossIncome );

	//	Blank line for readability.
	puts( "" );

	//	Turn the grossIncome into pennies for proper money handling.
	grossIncomeInPennies = convertToPennies( grossIncome );

	//	Find the First Fruits in pennies.
	firstFruits = floor( grossIncomeInPennies * firstFruitsPercent );

	//	If...else statement to ensure the decimal has two places.
	if ( firstFruits % 100 < 10 )
	{
		printf( "First Fruits 2.5%%:\t\t$%d.0%d\n", convertToDollars( firstFruits ), convertToCents( firstFruits ) );
	}
	else
	{
		printf( "First Fruits 2.5%%:\t\t$%d.%d\n", convertToDollars( firstFruits ), convertToCents( firstFruits ) );
	}

	//	Subtract First Fruits from grossIncome.
	grossIncomeInPennies -= firstFruits;

	//	Find the Tithe in pennies.
	tithe = floor( grossIncomeInPennies * tithePercent );

	//	If...else statement to ensure the decimal has two places.
	if ( tithe % 100 < 10 )
	{
		printf( "Tithe 10%%:\t\t\t$%d.0%d\n", convertToDollars( tithe ), convertToCents( tithe ) );
	}
	else
	{
		printf( "Tithe 10%%:\t\t\t$%d.%d\n", convertToDollars( tithe ), convertToCents( tithe ) );
	}

	//	Subtract tithe from grossIncome.
	grossIncomeInPennies -= tithe;

	//	Display the remaining income. If...else statement to ensure the decimal has two places.
	if ( grossIncomeInPennies % 100 < 10 )
	{
		printf( "Remaining gross income:\t\t$%d.0%d\n", convertToDollars( grossIncomeInPennies ), convertToCents( grossIncomeInPennies ) );
	}
	else
	{
		printf( "Remaining gross income:\t\t$%d.%d\n", convertToDollars( grossIncomeInPennies ), convertToCents( grossIncomeInPennies ) );
	}

	//	If the rateChange has changed, inform the user to update the hourlyRate in the source code.
	if ( rateChange[0] == 'y' || rateChange[0] == 'Y' )
	{
		puts( "" );
		printf( "%s", "********************\n" );
		printf( "%s", "********NOTE********\n" );
		printf( "%s", "********************\n" );
		printf( "%s", "\nPlease update the source code to have your new hourly rate.\n" );
	}

	//	Blank line for readability.
	puts( "" );
}

int convertToDollars( int pennies )
{
	return pennies / 100;
}

int convertToCents( int pennies )
{
	return pennies % 100;
}

int convertToPennies( double money )
{
	return floor( money * 100 );
}

double convertToNetIncome( int pennies )
{
	return 0;
}
