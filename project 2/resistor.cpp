// UCLA Winter 2012
// CS 33 Project 2
// Kyle Kodani
// 903896275
// Discussion 1D
// January 28, 2012
//
//
// This program prompts for and accepts a set of three resistor values in ohms.
// The program then prompts for and accepts a specification as to whether resistors
// in the set are connected in series or parallel (S or P).  The program then
// calculates the resistance value of the network of resistors connected as specified.
// Finally the program displays the resistance value of the resistor network.
// If the resistors are connected in series, the result is displayed in Kohms.
// If the resistors are connected in parallel, the result is displayed in ohms.
// One Kohm equals 1000 ohms.
//
// Following are the formulas for series and parallel resistance connections:
//
//      Resistance (Series) = Sum(Individual Resistor Values)
//
//      Resistance (Parallel) = 1/Sum(1/Individual Resistor Value)
//
//
// EXAMPLE 1:
//
// RESISTANCE CALCULATION PROGRAM
//
// Enter three resistor values in ohms:
// 100
// 300
// 800
// Series or parallel connection (S or P)? S
// Network resistance value = 1.2000 Kohms
//
// Done.
//
//
// EXAMPLE 2:
//
// RESISTANCE CALCULATION PROGRAM
//
// Enter three resistor values in ohms:
// 1
// 1.5
// 3
// Series or parallel connection (S or P)? P
// Network resistance value = 0.5000 ohms
//
// Done.
//
//
// EXAMPLE 3:
//
// RESISTANCE CALCULATION PROGRAM
//
// Enter three resistor values in ohms:
// 10
// -20
// 30
// Negative resistor values are not allowed!
//
// Done.
//
//
// EXAMPLE 4:
//
// RESISTANCE CALCULATION PROGRAM
//
// Enter three resistor values in ohms:
// 1
// 2
// 3
// Series or parallel connection (S or P)? x
// The connection type is invalid!
//
// Done.


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	const int    OHMS_PER_KILOHM = 1000;		// Conversion factor
	
	double resistorValue1;		// First  resistor value
	double resistorValue2;		// Second resistor value
	double resistorValue3;		// Third  resistor value
	double networkResistance;	// Resistance of connected resistor set 
	
	string selection;			// Selection string
	
	// Display a title
	cout << "RESISTANCE CALCULATION PROGRAM" << endl;
	
	// Display a blank line
	cout << endl;
	
	// Prompt for the resistor values
	cout << "Enter three resistor values in ohms:" << endl;
	
	// Accept the resistor values in ohms
	cin >> resistorValue1 >> resistorValue2 >> resistorValue3;
	
	// clear the input buffer
	cin.ignore(1000, '\n');
	
	// If any of the resistor values is negative
	if (resistorValue1 < 0 || resistorValue2 < 0 || resistorValue3 < 0)
	{
		// Display an error message
		cout << "Negative resistor values are not allowed!";
	}
	
	// Else
	else
	{
		// Prompt for the series or parallel specification
		cout << "Series or parallel connection (S or P)? ";
		
		// Accept the connection specification
		getline(cin, selection);
		
		// If the resistors are connected in series
		if (selection[0]=='s' || selection[0]=='S')
		{
			// Calculate the series network resistance value
			networkResistance=(resistorValue1+resistorValue2+resistorValue3)/OHMS_PER_KILOHM;
			
			// Display the resistance value in Kohms
			cout << "Network resistance value = " << fixed << setprecision(4) << networkResistance << " Kohms";
		}
		
		// Else if the resistors are connected in parallel
		else if (selection[0]=='p' || selection[0]=='P')
		{
			// if one or more resistor values equal zero
			if(resistorValue1 == 0 || resistorValue2 == 0 || resistorValue3 == 0)
			{
				// display a network resistance value of zero
				cout << "Network resistance value = 0.0000 ohms" ;
			}
			
			// else all the resistor values are non-zero
			else
			{
			// Calculate the parallel network resistance value
			networkResistance=1/((1/resistorValue1)+(1/resistorValue2)+(1/resistorValue3));
			
			// Display the resistance value in ohms
			cout.precision(4);
			cout << "Network resistance value = " << fixed << setprecision(4) << networkResistance << " ohms";
			}
		}
		
		// Else the connection specification is invalid
		else
		{
			// Display an error message
			cout << "The connection type is invalid!";
		}
	}
	
	// Display a blank line
	cout << endl << endl;
	
	// Display a termination message
	cout << "Done." << endl;
	
	// Return
	return 0;
}






