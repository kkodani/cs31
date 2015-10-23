// UCLA Winter 2012
// CS 31 Project 3: Motor Program
// Kyle Kodani
// 903896275
// Discussion 1D
// 2/6/12
//
//
// This program builds motor control programs.
//
// A motor controller utilizes a program of digital commands to control a motor.
// However, since the string of digits used to control the motor is difficult to
// read, the following more user-friendly syntax is used to generate motor programs.
//
// Each motor program consists of one or more motor command steps.  Each step is
// specified on a separate input line.  Each step consists of a two-digit decimal 
// operation code followed by zero or more parameters for the operation.  The first
// digit of the operation code specifies the number of parameters for the step.
// The second digit of the operation code specifies the motor action for the step.
// Each parameter is a one- or two-digit decimal number preceded by a period.
// No operation has more than nine parameters.  No extra periods or other
// characters are allowed in command step input.
//
// Each valid command step line is translated to a motor step which is a string of
// decimal digits where the operation code begins the string and each parameter is
// specified by a decimal digit representing its numerical position that occurs as
// many times as the value of the parameter.  The operation code and the parameter
// digits are concatenated together with no punctuation. 
//
// A motor program consists of all the motor steps concatenated together terminated
// by a single zero digit.  A motor program contains only decimal digits:  no blanks
// or other characters appear in a motor program.
//
//
// The C++ program begins by displaying a title and a blank line.
//
// Then the program prompts for and accepts command steps until an empty line is
// entered.  Each command step is displayed as it is entered then translated to a
// motor step.  Each motor step is displayed as it is generated.  A line of dashes
// is displayed after each motor step.  The complete motor program is displayed
// after all command steps have been input.  A line of equal signs followed by
// a blank line is displayed after the complete motor program.
//
// Motor program generation repeats until an empty line is input as the first
// command step.
//
// A blank line and a termination message are displayed at the end of the C++
// program execution.
//
//
// The C++ program is implemented as a main program and two supporting functions.
//
// The main program reads all input, writes all output, builds the motor program,
// and calls the two functions.  One function validates command steps.  The other
// function translates a valid command step to a motor step.
//
//

// Example Execution 1
//
// MOTOR CONTROL PROGRAM GENERATOR
//
// Command Step:25.7.4
// Motor   Step:2511111112222
// -----------------------------------------------------------
// Command Step:<Return>
// Complete Program::25111111122220
// ===========================================================
//
// Command Step:<Return>
//
// Done.
//
//
// Example Execution 2
//
// MOTOR CONTROL PROGRAM GENERATOR
//
// Command Step:07
// Motor   Step:07
// -----------------------------------------------------------
// Command Step:13.125
// Invalid command step!
// -----------------------------------------------------------
// Command Step:25.0.3
// Motor   Step:25222
// -----------------------------------------------------------
// Command Step:<Return>
// Complete Program::07252220
// ===========================================================
//
// Command Step:<Return>
//
// Done.
//
//
// Example Execution 3
//
// MOTOR CONTROL PROGRAM GENERATOR
//
// Command Step:01
// Motor   Step:01
// -----------------------------------------------------------
// Command Step:19.5
// Motor   Step:1911111
// -----------------------------------------------------------
// Command Step:27.3.6.1
// Invalid command step!
// -----------------------------------------------------------
// Command Step:32.4.-1.8
// Invalid command step!
// -----------------------------------------------------------
// Command Step:<Return>
// Complete Program::0119111110
// ===========================================================
//
// Command Step:<Return>
//
// Done.


// Example Execution 4
//
// MOTOR CONTROL PROGRAM GENERATOR
//
// Command Step:15
// Invalid command step!
// -----------------------------------------------------------
// Command Step:03.7
// Invalid command step!
// -----------------------------------------------------------
// Command Step:23.7.5
// Motor   Step:23111111122222
// -----------------------------------------------------------
// Command Step:<Return>
// Complete Program::231111111222220
// ===========================================================
//
// Command Step:09
// Motor   Step:09
// -----------------------------------------------------------
// Command Step:16.2
// Motor   Step:1611
// -----------------------------------------------------------
// Command Step:27.3.6
// Motor   Step:27111222222
// -----------------------------------------------------------
// Command Step:32.5.12.4
// Motor   Step:32111112222222222223333
// -----------------------------------------------------------
// Command Step:<Return>
// Complete Program::09161127111222222321111122222222222233330
// ===========================================================
//
// Command Step:<Return>
//
// Done.


#include <iostream>
#include <string>

using namespace std;



// =================================== Main Program ===================================

int main()
{
	// ============================== Prototype Declarations ==============================
	
	bool verifyCommand			// Verify a command step
	(string commandStep);
	
	void translateCommand			// Translate one command step
	(string  commandStep,
	 string &motorStep);
	
	// ================================ Local Declarations ================================
	
	string   input;				// Input line
	string   step;				// Motor step
	string   program;			// Motor program
	
	
	// ==================================== Statements ====================================
	
	// Display a title and a blank line
	cout << "MOTOR CONTROL PROGRAM GENERATOR" << endl << endl;
	
	// Prompt for a command step
	cout << "Command Step:";
	
	// Read a command step
	getline(cin, input);
	
	// begin loop
	while(!(input.length()==0))
	{
		// initialize program to blank string
		program="";
		
		// begin inner loop
		do
		{	
			
			// if input is valid
			if (verifyCommand(input))
			{
				// translate input, and put the translation into step
				translateCommand(input, step);
				
				// print step and a dash line
				cout << "Motor   Step:" << step << endl;
				cout << "-----------------------------------------------------------" << endl;
				
				//add step to program
				program+=step;
				
			}
			
			// else (input is invalid)
			else
			{
				//tell user the input is invalid and print a dash line
				cout << "Invalid command step!" << endl;
				cout << "-----------------------------------------------------------" << endl;
			
			}
			
			// Prompt for a command step
			cout << "Command Step:";
			
			// Read a command step
			getline(cin, input);
			
		} while(!(input.length()==0));
		
		// if input is blank (user hit return)
		if(input.length()==0)
		{
			// add '0' at end of program
			program+="0";
			
			// print program and line of '='
			cout << "Complete Program::" << program << endl;
			cout << "===========================================================" << endl << endl;
			
			// Prompt for a command step
			cout << "Command Step:";
			
			// Read a command step
			getline(cin, input);
		}
	
	}
	
	// print termination message
	cout << endl;
	cout << "Done." << endl;
	
	// Return
	return 0;
}



// =============================  Verify Command Function =============================

bool verifyCommand				// Verify a command step
(string commandStep)			// Command step string
// Return value:  True:   Valid
//                False:  Invalid
{
	// ================================ Local Declarations ================================
	
	bool resultVal;			// Result value
	unsigned int  pos;		// Step position
	int current;			// integer value of current position
	int numberOfSteps=(commandStep[0]-'0');	// integer value of first char in commandStep string
	int periods=0;		// counts the number of periods (to be compared with numberOfSteps)
	
	// ==================================== Statements ====================================
	
	// Precondition:
	//    The input parameter contains one command step.
	//
	// Postcondition:
	//    The return value is true if the command step is syntactically valid,
	//    false otherwise.
	
	
	// Initialize the result false
	resultVal = false;
	
	// If the string has at least two characters
	if(commandStep.length()>=2)
	{
		// If the first character is a decimal digit
		if(numberOfSteps>=0 && numberOfSteps<=9)
		{
			// If the second character is a decimal digit
			if((commandStep[1]-'0')>=0 && (commandStep[1]-'0')<=9)
			{
				// at this point the precondition has been met
				
				// check if the command is two chars starting with 0
				if(commandStep.length()==2 && numberOfSteps==0)
				{
					resultVal=true;
				}
				else
				{
					//set pos
					pos=2;
					
					//assume resultVal is true
					resultVal=true;
					
					// start iterating through rest of commandStep string
					while(pos<commandStep.length() && resultVal==true)
					{
						
						// initialize current to be the integer value of position pos in the commandStep string
						current=commandStep[pos];
						
						// if current is a period
						if(current=='.')
						{
							// advance pos
							pos++;
							
							// re-initialize current for new pos
							current=commandStep[pos];
							
							// increment number of periods
							periods++;
							
							// if there are more steps than were input
							if(periods>numberOfSteps)
							{
								// set resultVal to false, end loop
								resultVal=false;
							}
							
							// else if current is a decimal digit
							else if(current-'0'>=0 && current-'0'<=9)
							{
								// advance pos
								pos++;
								
								// re-initialize current for new pos
								current=commandStep[pos];
								
								// if current is a decimal digit
								if(current-'0'>=0 && current-'0'<=9)
								{
									// advance pos, return to start of loop
									pos++;
								}
								
								// else if current is a period
								else if(current=='.')
								{
									// do nothing, return to start of loop
								}
								
								// else if we are at the end of the string
								else if(pos>=commandStep.length())
								{
									// do nothing, return to start of loop
								}
								
								//else
								else
								{
									// set resultVal to false, end loop
									resultVal=false;
								}

							}
							
							// else
							else
							{
								// set resultVal to false, end loop
								resultVal=false;
							}

						}
						
						// else
						else
						{
							// set resultVal to false, end loop
							resultVal=false;
						}
					}
				}
			}
			
			// else
			else
			{
				// set resultVal to false
				resultVal=false;
			}

		}
		
		// else
		else
		{
			// set resultVal to false
			resultVal=false;
		}
	}
	
	// else
	else
	{
		// set resultVal to false
		resultVal=false;
	}
	
	// if there are fewer steps than were input
	if(periods<numberOfSteps)
	{
		// set resultVal to false, end loop
		resultVal=false;
	}
	
	// else
	else
	{
		// do nothing
	}

	
	// Return the result
	return resultVal;
}



// =========================== Translate Command Function =============================

void translateCommand				// Translate one command step
(string commandStep,			// Command step string
 string &motorStep)			// Motor   step string
{
	// ================================ Local Declarations ================================
	
	int  i;						// Parameter loop index
	int  j;				// Parameter digit index
	int  numberOfSteps=commandStep[0]-'0';		// Parameter output count
	unsigned int  pos;			// Command step position
	int current;				// integer value of current position
	
	// ==================================== Statements ====================================
	
	// Precondition:
	//    The input parameter contains one valid input motor step.
	//
	// Postcondition:
	//    The return value is the motor step for the command step.
	
	
	// Initialize the motor step
	motorStep = "";
	
	// Copy the parameter count
	motorStep += commandStep[0];
	
	// Copy the operation code
	motorStep += commandStep[1];
	
	// set pos to the first parameter
	pos=3;
	
	//precondition
	if(verifyCommand(commandStep))
	{
		// loop through number of parameters
		for(i=1; i<=numberOfSteps; i++)
		{
			// if the parameter is a two digit number
			if(commandStep[pos+1]-'0'>=0 && commandStep[pos+1]-'0'<=9)
			{
				// advance pos
				pos++;
			
				// initialize current as one's digit
				current=commandStep[pos];
			
				// add the ten's digit value to current
				current+=((commandStep[pos-1]-'0')*10);
			}
		
			// else
			else
			{
				// initialize current to parameter
				current=commandStep[pos];
			}
		
			// loop to add parameter number of 1's or 2's or 3's etc
			for(j=0; j<(current-'0'); j++)
			{
				// add the 1's or 2's etc to the motorStep string
				motorStep+=(i+'0');
			}
			
			// advance pos past the period to the next parameter
			pos+=2;
		}
	}
	
}
