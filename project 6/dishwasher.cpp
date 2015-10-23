// UCLA Winter 2012
// CS 31 Project 6:  Object Oriented Dishwasher:  Skeleton Code
// John A. Rohr
// March 2, 2012
//
//
// This program simulates the operation of a dishwasher.
//
// The dishwasher has five states:  idle, pause, wash, rinse, and dry.
//
// The dishwasher has three types of cycles:  light, regular, and heavy.
// The only difference between cycles is the amount of washing time.
// Each cycle includes washing, rinsing and drying time.
//
// The dishwasher includes push buttons, a timer, and a status display.
//
// At the beginning of the program, the dishwasher is in the idle state.
// At the beginning of the program, the cycle selected is the regular cycle.
//
// There are six function buttons:  three control the state and three select
// the cycle type.  The state control buttons are go (start), stop, and cancel.
// The cycle selection buttons are light, regular, and heavy.  The cycle
// selection remains the same until it is changed.  
//
// The display shows the current state, the selected cycle, the amount of time
// left in the current cycle if the state is not idle, and the total simulation
// time.
//
//
// The program begins with initialization.
//
// The program then prompts for and waits for commands.  Four kinds of commands
// are available:  display the menu of commands, push a button, advance the cycle
// a specified number of seconds, and quit.  Commands may be entered in either
// upper case or lower case.  Command words may be any length, but only the first
// letter of a command is used.  The A command advances the simulation by a
// specified number of seconds.  White space must separate the command letter
// or word and the number of seconds.  If no value is given or the value given
// is invalid (not terminated by white space or the end of the line), an increment
// of one is used.
//
// Each time a valid command is entered, it is executed, the dishwasher status
// is displayed, and, if the command is not quit, the program then prompts for
// and waits for the next command.
//
// When the quit command is executed, operation of the dishwasher is terminated,
// final status is displayed, and program execution is terminated.
//
//
// Following is the menu of commands available in the program:
//
//     Key  Function
//      G   Go (start) or restart if stopped during a cycle
//      S   Stop (pause) during a cycle
//      C   Cancel the cycle and go to idle
//      L   Cycle Select: Light
//      R   Cycle Select: Regular
//      H   Cycle Select: Heavy
//      M   Display the menu 
//      A   Advance the simulation:  Specify the number of seconds
//      Q   Quit the simulation
//
//

// Example Execution:
//
// = = = =   DISHWASHER  SIMULATOR   = = = =
//
// * * * * * *  DISHWASHER MENU  * * * * * *
// *            Key  Function              *
// *             G   Go (Start)            *
// *             S   Stop                  *
// *             C   Cancel                *
// *                                       *
// *             L   Cycle Select: Light   *
// *             R   Cycle Select: Regular *
// *             H   Cycle Select: Heavy   *
// *                                       *
// *             M   Display Menu          *
// *             A   Advance Simulation    *
// *             Q   Quit Simulation       *
// * * * * * * * * * * * * * * * * * * * * *
//
// Command:G
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |      WASH     |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |      1200     |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |       0       |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//
// Command:A
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |      WASH     |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |      1199     |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |       1       |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//

// Command:A 1199
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |     RINSE     |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |      600      |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |      1200     |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//
// Command:Advance
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |     RINSE     |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |      599      |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |      1201     |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//
// Command:Advance 599
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |      DRY      |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |      1200     |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |      1800     |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//

// Command:advanc 1199
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |      DRY      |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |       1       |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |      2999     |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//
// Command:a
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |      IDLE     |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |               |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |      3000     |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//
// Command:Q
//
// = = = = =   DISHWASHER STATUS   = = = = =
// =                 State                 =
// =           +---------------+           =
// =           |      IDLE     |           =
// =           +---------------+           =
// =                 Cycle                 =
// =           +---------------+           =
// =           |    REGULAR    |           =
// =           +---------------+           =
// =                 Timer                 =
// =           +---------------+           =
// =           |               |           =
// =           +---------------+           =
// =            Simulation Time            =
// =           +---------------+           =
// =           |      3000     |           =
// =           +---------------+           =
// = = = = = = = = = = = = = = = = = = = = =
//
// Simulation complete.

//#define ECHO


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


//  ********************************************************************************
//  *                                                                              *
//  *                               GLOBAL CONSTANTS                               *
//  *                                                                              *
//  ********************************************************************************

const int		MAX_SIMTIME     = 999999;	// Maximum simulation time

const int		LIGHT_TIME      = 600;		// Cycle time:  Light:    Seconds
const int		REGULAR_TIME    = 1200;		// Cycle time:  Regular:  Seconds
const int		HEAVY_TIME      = 1800;		// Cycle time:  Heavy:    Seconds

const int		RINSE_TIME      = 600;		// Rinse time

const int		DRY_TIME        = 1200;		// Dry   time

const int		CANCEL_BUTTON   = 0;        // Button number 0: Cancel
const int		STOP_BUTTON     = 1;        // Button number 1: Stop
const int		GO_BUTTON       = 2;        // Button number 2: Go (Start) 
const int		LIGHT_BUTTON    = 3;        // Button number 3: Cycle:  Light
const int		REGULAR_BUTTON  = 4;        // Button number 4: Cycle:  Regular
const int		HEAVY_BUTTON    = 5;        // Button number 5: Cycle:  Heavy

const int		STATE_ROW       = 3;		// State display row
const int		STATE_COL_START = 13;		// State display column start

const int		CYCLE_ROW       = 7;		// Cycle display row
const int		CYCLE_COL_START = 13;		// Cycle display column start

const int		TIMER_ROW       = 11;		// Timer display row
const int		TIMER_COL_START = 13;		// Timer display column start
const int		TIMER_COL_END   = 27;		// Timer display column end

const int		SIMTIM_ROW      = 15;		// Simulation time display row
const int		SIMTIM_COL_START= 13;		// Simulation time display column start
const int		SIMTIM_COL_END  = 27;		// Simulation time display column end


enum		State             { IDLE,	// Idle  state
	PAUSE,	// Pause state
	WASH,	// Wash  state
	RINSE,	// Rinse state
	DRY};	// Dry   state

enum		Cycle             { LIGHT,	// Light   cycle
	REGULAR,// Regular cycle
	HEAVY};	// Heavy Cycle

const string	STATE_TEXT[]    = {"      IDLE     ",
	"     PAUSE     ",
	"      WASH     ",
	"     RINSE     ",
	"      DRY      "};

const string	CYCLE_TEXT[]    = {"     LIGHT     ",
	"    REGULAR    ",
	"     HEAVY     "};

const string    MENU            = "* * * * * *  DISHWASHER MENU  * * * * * *\n"
"*            Key  Function              *\n"
"*             G   Go (Start)            *\n"
"*             S   Stop                  *\n"
"*             C   Cancel                *\n"
"*                                       *\n"
"*             L   Cycle Select: Light   *\n"
"*             R   Cycle Select: Regular *\n"
"*             H   Cycle Select: Heavy   *\n"
"*                                       *\n"
"*             M   Display Menu          *\n"
"*             A   Advance Simulation    *\n"
"*             Q   Quit Simulation       *\n"
"* * * * * * * * * * * * * * * * * * * * *\n";


//  ********************************************************************************
//  *                                                                              *
//  *                                DISPLAY DATA                                  *
//  *                                                                              *
//  ********************************************************************************

string  d_line[] = {"= = = = =   DISHWASHER STATUS   = = = = =\n",	// Line  0
	"=                 State                 =\n",	// Line  1
	"=           +---------------+           =\n",	// Line  2
	"=           |      IDLE     |           =\n",	// Line  3
	"=           +---------------+           =\n",	// Line  4
	"=                 Cycle                 =\n",	// Line  5
	"=           +---------------+           =\n",	// Line  6
	"=           |    REGULAR    |           =\n",	// Line  7
	"=           +---------------+           =\n",	// Line  8
	"=                 Timer                 =\n",	// Line  9
	"=           +---------------+           =\n",	// Line 10
	"=           |       0       |           =\n",	// Line 11
	"=           +---------------+           =\n",	// Line 12
	"=            Simulation Time            =\n",	// Line 13
	"=           +---------------+           =\n",	// Line 14
	"=           |       0       |           =\n",	// Line 15
	"=           +---------------+           =\n",	// Line 16
	"= = = = = = = = = = = = = = = = = = = = =\n"};	// Line 17



//  ********************************************************************************
//  *                                                                              *
//  *                          FORWARD CLASS DECLARATION                           *
//  *                                                                              *
//  ********************************************************************************

class		Dishwasher;


//  ********************************************************************************
//  *                                                                              *
//  *                              CLASS DEFINITIONS                               *
//  *                                                                              *
//  ********************************************************************************

class Timer									// Timer class
{
public:
	// Constructor
	Timer();
	
	// Accessors
	int			getTime() const;			// Get the time left in seconds
	
	// Mutator
	void		setTime(int seconds);		// Set the time left in seconds
	bool		run(int seconds);			// Run the timer for specified seconds
	//    True if run for time
	//    True if not enough time left
private:
	int			m_time;						// TIme left in seconds
};


class Button								// Button class
{
public:
	// Constructor
	Button();
	
	// Accessors
	bool		getState() const;			// Report the button state
	//     True if button is pressed
	// Mutators
	bool		press();					// Button pressed
	bool		release();					// Button released
	// Both fail if already in that state
private:
    bool		m_pressed;					// Button pressed state
};



class Display								// Display class
{
public:
	// Constructor
	Display(Dishwasher* d);
	
	// Accessors
	void		show() const;				// Show the display status
	
private:
	Dishwasher*	mp_dishwasher;				// Pointer to the dishwasher
};


class Dishwasher							// Dishwasher class
{
public:
	// Constructor
	Dishwasher();
	
	// Destructor
	~Dishwasher();
	
	// Accessors
	int			getState()      const;		// Get the current state
	int			getCycle()      const;		// Get the current cycle
	int			getTime()       const;		// Get the current cycle time left
	int			getSimTime()    const;		// Get the current simulation time
	void        displayMenu()   const;		// Display the menu
	void		displayStatus() const;		// Display the status
	
	// Mutators
	void		pressButton(int number);	// Respond to a button press
	bool		advance(int inc);			// Advance the simulation
	void		quit();						// Terminate the simulation
	
private:
	void		update();					// Update the simulation state
    Timer		m_timer;					// Timer object
	Display*	mp_display;					// Display object pointer
	Button		m_button[6];				// Button array
	State		m_state;					// Current state
	State		m_priorstate;				// Prior   state
	State		m_pausestate;				// Pause   state
	Cycle       m_cycle;					// Most recent cycle
	int			m_simtime;					// Simulation time
};


class User									// User class
{
public:
	// Constructor
	User();
	
	// Mutators
	void		operate();					// Operate the dishwasher
	
private:
	Dishwasher*	mp_dishwasher;				// Dishwasher object pointer
};



//  ********************************************************************************
//  *                                                                              *
//  *                          TIMER CLASS IMPLEMENTATION                          *
//  *                                                                              *
//  ********************************************************************************

// Constructor
Timer::Timer():m_time(0)
{}


// Get the time left in seconds
int	Timer::getTime() const
{
	// Return the time left in seconds
	return m_time;
}


// Set the time left in seconds
void Timer::setTime(int seconds)
{
	// Set the time left in seconds
	m_time=seconds;
}


// Run the timer for specified seconds
bool Timer::run(int seconds)
{
	bool		success;					// Success indicator
	//    True if run for time
	//    True if not enough time left
	
	
	// If there is less time left than the run time
	if (m_time < seconds)
	{
		// Set the success false
		success = false;
	}
	
	// Else
	else
	{
		// Set the success true
		success =true;
		
		// Decrement the time by the run time
		m_time=m_time-seconds;
	}
	
	// Return the success of the move
	return success;
}



//  ********************************************************************************
//  *                                                                              *
//  *                         BUTTON CLASS IMPLEMENTATION                          *
//  *                                                                              *
//  ********************************************************************************

// Constructor
Button::Button():m_pressed(false)
{}


// Press button
bool Button::press()
{
	bool		changed;					// Changed indicator
	
	
	// If the button was already pressed
	if (m_pressed)
	{
		// Set the changed indicator false
		changed = false;
	}
	
	// Else
	else
	{
		// Set the changed indicator true
		changed = true;
	}
	
	// Set the button pressed indicator true
	m_pressed = true;
	
	// Return the changed indicator
	return changed;
}



// Release button
bool Button::release()
{
	bool		changed;					// Changed indicator
	
	
	// If the button was already released
	if (!m_pressed)
	{
		// Set the changed indicator false
		changed = false;
	}
	
	// Else
	else
	{
		// Set the changed indicator true
		changed = true;
	}
	
	// Set the button pressed indicator false
	m_pressed = false;
	
	// Return the changed indicator
	return changed;
}


// Report the button state
bool Button::getState()	const				// True if button is pressed
{
	// Return the button state
	return m_pressed;
}



//  ********************************************************************************
//  *                                                                              *
//  *                        DISPLAY CLASS IMPLEMENTATION                          *
//  *                                                                              *
//  ********************************************************************************

// Constructor
Display::Display(Dishwasher* p): mp_dishwasher(p)
{}


// Show the display status
void Display::show() const
{
	int			row;						// Display row
	int			col;						// Display column
	int			state;						// State enumeration number
	int			cycle;						// Cycle enumeration number
	int			cycletime;					// Cycle time
	int			simtime;					// Simulation time
	int			residual;					// Residual value
	int			prespaces;					// Leading  space count
	int			postspaces;					// Trailing space count
	int			get;						// Get character position
	int			put;						// Put character position
	
	
	// Get the state
	state = mp_dishwasher->getState();
	
	// Get the cycle
	cycle = mp_dishwasher->getCycle();
	
	// Get the cycle time
	cycletime = mp_dishwasher->getTime();
	
	// Get the simulation time
	simtime = mp_dishwasher->getSimTime();
	
	// Set the state text
	for (col = 0; col < STATE_TEXT[state].length(); col++)
	{
		// Set one state text character
		d_line[STATE_ROW][STATE_COL_START+col] = STATE_TEXT[state][col];
	}
	
	// Set the cycle text
	for (col = 0; col < CYCLE_TEXT[cycle].length(); col++)
	{
		// Set one cycle text character
		d_line[CYCLE_ROW][CYCLE_COL_START+col] = CYCLE_TEXT[cycle][col];
	}
	
	
	// If the state is IDLE
	if (state == IDLE)
	{
		// Clear the time display
		for (col = TIMER_COL_START; col <= TIMER_COL_END; col++)
		{
			// Clear one time display position
			d_line[TIMER_ROW][col] = ' ';
		}
	}
	
	// Else
	else
	{
		// Initialize the cycle time residual
		residual = cycletime;
		
		// Initialize the put position
		put = TIMER_COL_END;
		
		// Set the cycle time digits
		do
		{
			// Set one position digit
			d_line[TIMER_ROW][put] = residual % 10  +  '0';
			
			// Discard the digit value
			residual /= 10;
			
			// Decrement the put position
			put--;
		}
		// While there are digits to set
		while (residual > 0);
		
		// Calculate the number of prespaces
		prespaces = put - TIMER_COL_START + 1;
		
		// If the space count is negative
		if (prespaces < 0)
		{
			// Set the space count to zero
			prespaces = 0;
		}
		
		// Distribute the spaces before and after
		postspaces = prespaces / 2;
		prespaces -= postspaces;
		
		
		// Initialize the get character position
		get = put + 1;
		
		// Initialize the put character position
		put = TIMER_COL_START;
		
		// Set the leading spaces
		while (prespaces > 0)
		{
			// Set one prespace
			d_line[TIMER_ROW][put] = ' ';
			
			// Decrement the prespace count
			prespaces--;
			
			// Increment the put character position
			put++;
		}
		
		// Set the position characters
		while (get <= TIMER_COL_END)
		{
			// Set one function character
			d_line[TIMER_ROW][put] = d_line[TIMER_ROW][get];
			
			// Increment the get character position
			get++;
			
			// Increment the put character position
			put++;
		}
		
		// Set the trailing spaces
		while (postspaces > 0)
		{
			// Set one postspace
			d_line[TIMER_ROW][put] = ' ';
			
			// Decrement the postspace count
			postspaces--;
			
			// Increment the put character position
			put++;
		}
	}
	
	// Initialize the simulation time residual
	residual = simtime;
	
	// Initialize the put position
	put = SIMTIM_COL_END;
	
	
	// Set the simulation time digits
	do
	{
		
		// Set one position digit
		d_line[SIMTIM_ROW][put] = residual % 10  +  '0';
		
		// Discard the digit value
		residual /= 10;
		
		// Decrement the put position
		put--;
	}
	// While there are digits to set
	while (residual > 0);
	
	// Calculate the number of prespaces
	prespaces = put - SIMTIM_COL_START + 1;
	
	// If the space count is negative
	if (prespaces < 0)
	{
		// Set the space count to zero
		prespaces = 0;
	}
	
	// Distribute the spaces before and after
	postspaces = prespaces / 2;
	prespaces -= postspaces;
	
	// Initialize the get character position
	get = put + 1;
	
	// Initialize the put character position
	put = SIMTIM_COL_START;
	
	// Set the leading spaces
	while (prespaces > 0)
	{
		// Set one prespace
		d_line[SIMTIM_ROW][put] = ' ';
		
		// Decrement the prespace count
		prespaces--;
		
		// Increment the put character position
		put++;
	}
	
	
	// Set the position characters
	while (get <= SIMTIM_COL_END)
	{
		// Set one function character
		d_line[SIMTIM_ROW][put] = d_line[SIMTIM_ROW][get];
		
		// Increment the get character position
		get++;
		
		// Increment the put character position
		put++;
	}
	
	// Set the trailing spaces
	while (postspaces > 0)
	{
		// Set one postspace
		d_line[SIMTIM_ROW][put] = ' ';
		
		// Decrement the postspace count
		postspaces--;
		
		// Increment the put character position
		put++;
	}
	
	// Display the status
	for (row = 0; row <= 17; row++)
	{
		// Disp0lay one row of the status
		cout << d_line[row];
	}
	
	// Display a blank line
	cout << endl;
}



//  ********************************************************************************
//  *                                                                              *
//  *                        DISHWASHER CLASS IMPLEMENTATION                       *
//  *                                                                              *
//  ********************************************************************************

// Constructor
Dishwasher::Dishwasher():m_state(IDLE),
m_priorstate(IDLE),
m_pausestate(IDLE),
m_cycle(REGULAR),
m_simtime(0)
{
	// Instantiate a display
	mp_display=new Display(this);
}


// Destructor
Dishwasher::~Dishwasher()
{
	// Delete the display
	delete mp_display;
}


// Display the menu
void Dishwasher::displayMenu() const
{
	// Display the menu
	cout << MENU;
	
	// Display a blank line
	cout << endl;
}


// Display the status
void Dishwasher::displayStatus() const
{
	// Display the status
	mp_display->show();
}


// Get the current state
int Dishwasher::getState() const
{
	// Return the current state
	return m_state;
}


// Get the current cycle	
int Dishwasher::getCycle() const
{
	// Return the current cycle
	return m_cycle;
}



// Get the current cycle time left	
int Dishwasher::getTime() const
{
	// Return the current cycle time left
	return m_timer.getTime();
}


// Get the current simulation time	
int Dishwasher::getSimTime() const
{
	// Return the current simulation time
	return m_simtime;
}


// Respond to a button press
void Dishwasher::pressButton(int number)
{
	// Press the button and process if changed
	if (m_button[number].press())
	{
		// Update the simulation state
		this->update();
	}
	
	// Else
	else
	{
		// Display a blank line
		cout << endl;
		
		// Display an error message
		cout << "@@@@@ PROGRAM ERROR 1:  "
		<< "Button " 
		<< m_button
		<< " already pressed!"
		<< endl;
		
		// Display a blank line
		cout << endl;
		
		// Exit
		exit (100);
	}
}



// Update the simulation state
void Dishwasher::update()
{
	// If Button 0 (Cancel) has been pressed
	if (m_button[0].getState())
	{
		// If the state is not IDLE
		if (m_state != IDLE)
		{
			// Set the prior state to the current state
			m_priorstate = m_state;
			
			// Set the current state to IDLE
			m_state = IDLE;
			
			// Set the timer to zero
			m_timer.setTime(0);
		}
		
		// Release the button
		m_button[0].release();
	}
	
	// If Button 1 (Stop) has been pressed
	if (m_button[1].getState())
	{
		// If the state is not IDLE or PAUSE
		if ((m_state != IDLE) && (m_state != PAUSE))
		{
			// Set the pause state to the current state
			m_pausestate = m_state;
			
			// Set the prior state to the current state
			m_priorstate = m_state;
			
			// Set the current state to PAUSE
			m_state = PAUSE;
		}
		
		// Release the button
		m_button[1].release();
	}
	
	
	// If Button 2 (Go/Start) has been pressed
	if (m_button[2].getState())
	{
		// If the state is IDLE
		if (m_state == IDLE)
		{
			// Set the prior state to the current state
			m_priorstate = m_state;
			
			// Set the current state to WASH
			m_state = WASH;
			
			// Set the timer to the wash time
			switch (m_cycle)
			{
					// Light cycle
				case LIGHT:		m_timer.setTime(LIGHT_TIME);
					
					break;
					
					// Regular cycle
				case REGULAR:	m_timer.setTime(REGULAR_TIME);
					
					break;
					
					// Heavy cycle
				case HEAVY:	m_timer.setTime(HEAVY_TIME);
					
					break;
					
					// Default:  Error
				default:	// Display a blank line
					cout << endl;
					
					// Display an error message
					cout << "@@@@@ PROGRAM ERROR 2:  "
					<< "Invalid cycle for Go button!"
					<< endl;
					
					// Display a blank line
					cout << endl;
					
					// Exit
					exit (200);
			}
		}
		
		// Else if the state is PAUSE
		else if (m_state == PAUSE)
		{
			// Set the prior state to the current state
			m_priorstate = m_state;
			
			// Set the current state to the pause state
			m_state = m_pausestate;
		}
		
		// Release the button
		m_button[2].release();
	}
	
	
	// If Button 3 (Set Light cycle) has been pressed
	if (m_button[3].getState())
	{
		// If the state is IDLE
		if (m_state == IDLE)
		{
			// Set the cycle type to LIGHT
			m_cycle = LIGHT;
		}
		
		// Else
		else
		{
			// Display an error message
			cout << "***** Cycle cannot be changed unless dishwasher is idle!"
			<< endl;
		}
		
		// Release the button
		m_button[3].release();
	}
	
	// If Button 4 (Set Regular cycle) has been pressed
	if (m_button[4].getState())
	{
		// If the state is IDLE
		if (m_state == IDLE)
		{
			// Set the cycle type to REGULAR
			m_cycle = REGULAR;
		}
		
		// Else
		else
		{
			// Display an error message
			cout << "***** Cycle cannot be change unless dishwasher is idle!"
			<< endl;
		}
		
		// Release the button
		m_button[4].release();
	}
	
	
	// If Button 5 (Set Heavy cycle) has been pressed
	if (m_button[5].getState())
	{
		// If the state is IDLE
		if (m_state == IDLE)
		{
			// Set the cycle type to HEAVY
			m_cycle = HEAVY;
		}
		
		// Else
		else
		{
			// Display an error message
			cout << "***** Cycle cannot be change unless dishwasher is idle!"
			<< endl;
		}
		
		// Release the button
		m_button[5].release();
	}
}



// Advance the simulation
bool Dishwasher::advance(int inc)
{
	bool		cont;						// Continue similation flag
	
	int			left;						// Remaining increment time
	
	
	// If the state is not  IDLE or PAUSE
	if ((m_state != IDLE) && (m_state != PAUSE))
	{
		// Initialize the remaining increment time
		left = inc;
		
		// Do
		do
		{
			// If the increment is less than the time on the timer
			if (left < m_timer.getTime())
			{
				// Decrement the timer by the increment
				m_timer.run(left);
				
				// Set the time left to zero
				left = 0;
			}
			
			// Else 
			else
			{
				// Decrement the time left by the time on the timer
				left -= m_timer.getTime();
				
				// If the state is WASH
				if (m_state == WASH)
				{
					// Set the state to rinse
					m_state = RINSE;
					
					// Set the time to the rinse time
					m_timer.setTime(RINSE_TIME);
				}
				
				// Else if the state is RINSE
				else if (m_state == RINSE)
				{
					// Set the state to dry
					m_state = DRY;
					
					// Set the time to the dry time
					m_timer.setTime(DRY_TIME);
				}
				
				// Else if the state is dry
				else if (m_state == DRY)
				{
					// Set the state to IDLE
					m_state = IDLE;
					
					// Set the time to zero
					m_timer.setTime(0);
				}
				
				
				// Else there is an error
				else
				{
					// Display a blank line
					cout << endl;
					
					// Display an error message
					cout << "@@@@@ PROGRAM ERROR 3:  "
					<< "Invalid cycle for advance!"
					<< endl;
					
					// Display a blank line
					cout << endl;
					
					// Exit
					exit (300);
				}
			}
		}
		// While the state is not idle and there is more increment time left
		while ((m_state != IDLE) && (left > 0));
	}
	
	// Advance the simulation time
	m_simtime += inc;
	
	// If the simulation time has not reached the maximum
	if (m_simtime <= MAX_SIMTIME)
	{
		// Set the simulation continuation flag true
		cont = true;
	}
	
	// Else
	else
	{
		// Set the simulation continuation flag false
		cont = false;
	}
	
	// Return the simulation continuation flag
	return cont;
}


// Terminate the simulation
void Dishwasher::quit()
{
	// Cancel the cycle 
	this->pressButton(CANCEL_BUTTON);
}



//  ********************************************************************************
//  *                                                                              *
//  *                          USER CLASS IMPLEMENTATION                           *
//  *                                                                              *
//  ********************************************************************************

// Constructor
User::User()
{}


// Operate the dishwasher
void User::operate()
{
	bool		run;						// Simulation run flag
	
	int			value;						// Command parameter value
	int			index;						// Command parameter index
	
	char        command;					// Command letter
	
	string      commandLine;				// Command string
	
	
	// Instantiate a dishwasher
	mp_dishwasher = new Dishwasher();
	
	// Display the menu
	mp_dishwasher->displayMenu();
	
	// Set the simulation run flag true
	run = true;
	
	// Process commands
	do
	{
		// Get a valid command
		do
		{
			// Clear the command
			command = ' ';
			
			// Prompt for a command
			cout << "Command:";
			
			// Get a command string
			getline(cin, commandLine);
			
#ifdef ECHO
			// If the input is good
			if (cin.good())
			{
				// Echo the input
				cout << commandLine << endl;
			}
#endif
			
			
			// If the input is good and the line is not empty
			if (cin.good() && commandLine.length()>0)
			{
				// Get the command letter
				command = commandLine[0];
				
				// If the command letter is lower case
				if ((command >= 'a') && (command <= 'z'))
				{
					// Convert the command letter to upper case
					command -= 'a' - 'A';
				}
			}
		}
		// While there is more input and the command is invalid
		while (cin.good() && (command == ' '));
		
		// If the input is good
		if (cin.good())
		{
			// If the command is A
			if (command == 'A')
			{
				// Initialize the command parameter index
				index = 1;
				
				// Skip additional keyword characters
				while ((index < int(commandLine.length())) &&
					   (int(commandLine[index] > ' ')))
				{
					// Increment the command line index
					index++;
				}
				
				// Skip blanks
				while ((index < int(commandLine.length())) &&
					   (int(commandLine[index] <= ' ')))
				{
					// Increment the command line index
					index++;
				}
				
				
				// If the end of the line has not been reached
				if (index < int(commandLine.length()))
				{
					// Initialize the parameter value to zero
					value = 0;
					
					// Accumulate the parameter value digit values
					while ((index < int(commandLine.length())) &&
						   (commandLine[index] >= '0')	           &&
						   (commandLine[index] <= '9'))
					{
						// Accumulate a digit value
						value = 10 * value  +  commandLine[index] - '0';
						
						// Increment the index
						index++;
					}
					
					// If there is an invalid termination
					if ((index < int(commandLine.length())) &&
						(int(commandLine[index] > ' ')))
					{
						// Set the parameter value to one
						value = 1;
					}
				}
				
				// Else
				else
				{
					// Set the parameter value to one
					value = 1;
				}
			}
			
			
			// Process the command
			switch (command)
			{
					//    C:   Cancel
				case 'C':
					// Press Button
					mp_dishwasher->pressButton(CANCEL_BUTTON);
					
					break;
					
					//    G:   Go (Start)
				case 'G':
					// Press Button
					mp_dishwasher->pressButton(GO_BUTTON);
					
					break;
					
					//    S:   Stop
				case 'S':
					// Press Button
					mp_dishwasher->pressButton(STOP_BUTTON);
					
					break;
					
					//    L:   Light Cycle
				case 'L':
					// Press Button
					mp_dishwasher->pressButton(LIGHT_BUTTON);
					
					break;
					
					//    R:   Regular Cycle
				case 'R':
					// Press Button
					mp_dishwasher->pressButton(REGULAR_BUTTON);
					
					break;
					
					//    H:   Heavy Cycle
				case 'H':
					// Press Button
					mp_dishwasher->pressButton(HEAVY_BUTTON);
					
					break;
					
					
					//    A:Advance
				case 'A':
					// Advance the simulation
					run = mp_dishwasher->advance(value);
					
					break;
					
					
					//    M:Menu
				case 'M':
					// Display a blank line
					cout << endl;
					
					// Display the menu
					mp_dishwasher->displayMenu();
					
					break;
					
					//    Q:Quit
				case 'Q':
					// Terminate the simulation
					mp_dishwasher->quit();
					
					// Set the simulation run flag false
					run = false;
					
					break;
					
					//    Default:  Illegal command
				default:
					// Display an invalid command message
					cout << "Invalid command!" << endl;
			}
			
			// If the command was not M
			if (command != 'M')
			{
				// Display a blank line
				cout << endl;
				
				// Display the status
				mp_dishwasher->displayStatus();
			}
		}
	}
	// While the input is good and the simulation run flag is true
	while (cin.good() && run);
	
	// Delete the dishwasher
	delete(mp_dishwasher);
}



//  ********************************************************************************
//  *                                                                              *
//  *                                 MAIN PROGRAM                                 *
//  *                                                                              *
//  ********************************************************************************

int main()
{
	User		u;							// Dishwasher user interface object
	
	
	// Display a title
	cout << "= = = =   DISHWASHER  SIMULATOR   = = = =" << endl;
	
	// Display a blank line
	cout << endl;
	
	// Run the dishwasher
	u.operate();
	
	// Display a termination message
	cout << "Simulation complete." << endl;
	
	// Return
	return 0;
}