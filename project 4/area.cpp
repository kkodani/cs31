// UCLA Winter 2012
// CS 31 Project 4
// Kyle Kodani
// 903896275
// Discussion 1D
// February 28, 2012
//
//
// This program calculates areas of polygons that can be divided into segments with
// horizontal lines such that each segment except possibly the top and/or bottom will
// be a trapezoid or a parallelogram.  There may be a triangle at the top and/or the
// bottom of a polygon.
//
// The area of a trapezoid (and also a parallelogram) is � of the product of the sum
// of the lengths of the parallel sides times the distance between them.  If the two
// sides have lengths A and B and the distance between them is D, then the area of the
// trapezoid or parallelogram is 0.5 * (A+B) * D.
//
// The area of a triangle is � of the product if the base times the height.  If the
// base has length B and height is H, then the area of the triangle is 0.5 * B * H.
//
//
// The program reads and displays multiple sets of input data.
//
// Each set of data consists of all the data for one polygon.  The data set consists 
// of specifications for all the vertices of the polygon on a Cartesian coordinate
// plane in order from the highest vertex (largest ordinate, i.e. Y coordinate) value
// to the smallest.
//
// Each vertex is listed on a separate line of data.  The vertex type is identified
// by a single letter in the first column of the line.  The abscissa (X coordinate)
// and ordinate (Y coordinate) follow on the line with white space before each of
// the two values.  The four types of vertices are as follows:
//
//      T:  Top vertex:   Used only if there is a triangle on top.
//      L:  Left vertex:  A vertex on the left  side of the polygon.
//      R:  Right vertex: A vertex on the right side of the polygon.
//      T:  Top vertex:   Used only if there is a triangle on the bottom.
//
// The data set is ended with a line having a tilde (~) in the first column.
//
// Any line in the input data that does not have a B, L, R, B, or ~ in the first
// column is considered a comment and is displayed but not otherwise processed.
//
// All input is read from a text file namesFile4.In.   All output is written to cout.
//
// The program reads and processes all the data on the input file until the end of
// the file is reached.
//
//
//  Example Polygon
//
//  Y Axis  
//    ^
//    |
//    |
//  20+
//    |                                   1:T(12,18)
//    |                                   O
//    |                                x      x
//    |                             x             x
// 15+|                          x                    O 2:R(16,15)
//    |                       x                           x
//    |                    x                                  x
//    |      4:L(6,12)  O                                         O 3:R(20,12)
//    |              x                                           x
//  10  5:L(4,10) O                                            x
//    |             x                                        x
//    |               x                                    x
//    |                  x                               x
//    |                    x                           x
//   5+                      x                       x
//    |                         x                  x
//    |                           x              x
//    |                             x          x
//    |                                x     x
//   0+--------------+--------------+-----O--------+--------------+----> X Axis
//    0              5             10   6:B(12,0) 15             20
//
//
// Example Input File
//
// *	Polygon:  6 Vertices with 4 Segments
// T	12	18
// R	16	15
// R	20	12
// L	6	12
// L	4	10
// B	12	0
// ~	End Polygon:  6 Vertices with 4 Segments
//
//
// Example Output File
//
// *	Polygon:  6 Vertices with 4 Segments
// T         12.00         18.00
// R         16.00         15.00
// R         20.00         12.00
// L          6.00         12.00
// L          4.00         10.00
// B         12.00          0.00
// ~	End Polygon:  6 Vertices with 4 Segments
// <><><><><><> All vertices are valid!
// <><><><><><> Polygon is valid!
// TOTAL AREA = 144.0000
//
// ////////////////////////////////////////////////////////////
//
// Done.


//#define DISPLAY_VERTICES
//#define DISPLAY_LINKS
//#define DISPLAY_ABSCISSAS
//#define DISPLAY_AREAS


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;


//  ************************************************************************************
//  *                                                                                  *
//  *                                 GLOBAL CONSTANTS                                 *
//  *                                                                                  *
//  ************************************************************************************

const	int		MAX_VERTICES      = 100;

const	int		VERTEX_WIDTH      = 4;
const	int		FIELD_WIDTH       = 14;
const	int		DECIMAL_PLACES    = 2;
const	int		AREA_PRECISION    = 4;

const	string	INFILE_NAME       = "File4.In";
const	string	OUTFILE_NAME      = "File4.Out";

const	string	TITLE             = "POLYGON AREA CALCULATOR";

const	string	AREA_TEXT         = "TOTAL AREA = ";

const	string	SEPARATOR         = "//////////////////////////////"
"//////////////////////////////";

const	string	LINKS_BORDER      = "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL"
"LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";

const	string	COORDS_BORDER     = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";

const	string	DISPLAY_BORDER    = "=============================="
"==============================";

const	string	HEAD1             =	"##  *         LEFT_X        RI"
"GHT_X              Y LAST NEXT";

const	string	HEAD2             = "--  - -------------- ---------"
"----- -------------- ---- ----";

const	string	ERROR_NO_IN       = "***** ERROR: No input file!";

const	string	ERROR_NO_V        = "***** ERROR: No vertices!";

const	string	ERROR_TOO_FEW_V   = "***** ERROR: Less than 3 vertices!";

const	string	ERROR_TOO_MANY_V  = "***** ERROR: Too many vertices!";

const	string	ERROR_INVALID_S   = "***** ERROR: Invalid top of polygon!";

const	string	ERROR_INVALID_F   = "***** ERROR: Invalid bottom of polygon!";

const	string	ERROR_INVALID_T1  = "***** ERROR: Invalid T vertex (";
const	string	ERROR_INVALID_T2  = ")!";

const	string	ERROR_INVALID_L1  = "***** ERROR: Invalid L vertex (";
const	string	ERROR_INVALID_L2  = ")!";

const	string	ERROR_INVALID_R1  = "***** ERROR: Invalid R vertex (";
const	string	ERROR_INVALID_R2  = ")!";

const	string	ERROR_INVALID_B1  = "***** ERROR: Invalid B vertex(";
const	string	ERROR_INVALID_B2  = ")!";

const	string	ERROR_TOO_MANY_L1 = "***** ERROR: Too many L vertices at Y = ";
const	string	ERROR_TOO_MANY_L2 = "!";

const	string	ERROR_TOO_MANY_R1 = "***** ERROR: Too many R vertices at Y = ";
const	string	ERROR_TOO_MANY_R2 = "!";

const	string	ERROR_INVALID_Y1  = "***** ERROR: Ascending Y coordinate at (";
const	string	ERROR_INVALID_Y2  = ")!";

const	string	ERROR_L_R_OF_R1   = "***** ERROR: L vertex (";
const	string	ERROR_L_R_OF_R2   = ") not left  of right side!";

const	string	ERROR_R_L_OF_L1   = "***** ERROR: R vertex (";
const	string	ERROR_R_L_OF_L2   = ") not right of left  side!";

const	string	TERM              = "Done.";


//  ************************************************************************************
//  *                                                                                  *
//  *                           GLOBAL VARIABLE DECLARATION                            *
//  *                                                                                  *
//  ************************************************************************************

ifstream fin;								// Input  file


//  ************************************************************************************
//  *                                                                                  *
//  *                               FUNCTION PROTOTYPES                                *
//  *                                                                                  *
//  ************************************************************************************

bool	initialize();						// Initialize the program

bool	read_input(							// Read a data set
				   int		&num,					// Number of vertices
				   char	 t[],					// Vertex types	
				   double	 xl[],					// Left  abscissas
				   double	 xr[],					// Right abscissas
				   double	 yy[],					// Ordinates
				   int		 lv[],					// Last vertex
				   int		 nv[]);					// Next vertex

bool	validate_vertices(					// Validate a set of vertices
						  int		 num,					// Number of vertices
						  char	 t[],					// Vertex types	
						  double	 xl[],					// Left  abscissas
						  double	 xr[],					// Right abscissas
						  double	 yy[]);					// Ordinates

void	set_vertex_links(					// Set the vertex links
						 int		 num,					// Number of vertices
						 char	 t[],					// Vertex types	
						 int		 lv[],					// Last vertex
						 int		 nv[]);					// Next vertex

void	set_other_abscissas(				// Set the other abscissas
							int		 num,					// Number of vertices
							char	 t[],					// Vertex types	
							double	 xl[],					// Left  abscissas
							double	 xr[],					// Right abscissas
							double	 yy[],					// Ordinates
							int		 lv[],					// Last vertex
							int		 nv[]);					// Next vertex

bool	validate_polygon(					// Validate the polygon
						 int		 num,					// Number of vertices
						 char	 t[],					// Vertex types	
						 double	 xl[],					// Left  abscissas
						 double	 xr[],					// Right abscissas
						 double	 yy[]);					// Ordinates

double	calculate_area(						// Calculate the total area
					   int		 num,					// Number of vertices
					   char	 t[],					// Vertex types	
					   double	 xl[],					// Left  abscissas
					   double	 xr[],					// Right abscissas
					   double	 yy[]);					// Next vertex

void	display_data(						// Display vertex data
					 string	 text,					// Display text
					 int		 num,					// Number of vertices
					 char	 t[],					// Vertex types	
					 double	 xl[],					// Left  abscissas
					 double	 xr[],					// Right abscissas
					 double	 yy[],					// Ordinates
					 int		 lv[],					// Last vertex
					 int		 nv[]);					// Next vertex

void	finish();							// Terminate the program


//  ************************************************************************************
//  *                                                                                  *
//  *                                   MAIN PROGRAM                                   *
//  *                                                                                  *
//  ************************************************************************************

int		main()
{
	// This function is the main program.
	//
	// This function uses nine functions:
	//
	//      initialize:           Initialize the program
	//      read_input:           Get the input data
	//      validate_vertices:    Validate the vertices
	//      set_vertex_links;     Set the vertex links
	//      set_other_abscissas:  Set the other abscissas
	//      validate_polygon:     Validate the polygon
	//      calculate_area:       Calculate the total area
	//      display_data:         Display debugging data
	//      finish:               Terminate the program
	//
	// A display_data function is also available to display data for debugging.
	
	
	// Function declarations
	bool	initialize();						// Initialize the program
	
	
	void	finish();							// Terminate the program
	
	
	bool	more;								// More  input indicator
	bool	valid;								// Valid data  indicator
	
	int		count;								// Number of vertices	
	
	double	area;								// Polygon area
	
	
	char	type[MAX_VERTICES+1];				// Vertex types
	
	double	x_left[MAX_VERTICES];				// Left  abscissas
	double	x_right[MAX_VERTICES];				// Right abscissas
	double	y[MAX_VERTICES];					// Ordinates
	
	int		last_vertex[MAX_VERTICES];			// Index of last vertex on side
	int		next_vertex[MAX_VERTICES];			// Index of next vertex on side
	
	
	// Initialize the program
	more = initialize();
	
	// While there is more input
	while (more)
	{
		// Set the default output precision
		cout.precision(DECIMAL_PLACES);
		
		// Set the area to zero
		area = 0.0;
		
		// Read the input data
		more = read_input(count, type, x_left, x_right, y, last_vertex, next_vertex);
		
		// If there are no input vertices
		if (count == 0)
		{
			// Display an error message on the console
			cout << ERROR_NO_V << endl;
		}
		
		// Else if there are some input vertices
		else if (count > 0)
		{
#ifdef DISPLAY_VERTICES
			// Display the vertex data
			display_data("Display After Input",
						 count, type, x_left, x_right, y, last_vertex, next_vertex);
#endif
			
			// Validate the vertices
			valid = validate_vertices(count, type, x_left, x_right, y);
			
			// If one or more of the vertices are not valid
			if (!valid)
			{
				// Display an error message on the console
				cout << "@@@@@@@@@@@ Vertex data is invalid!" << endl;
			}
			
			// Else
			else
			{
				// Report that all vertices are valid on the console
				cout << "<><><><><><> All vertices are valid!" << endl;
				
				// Set the next and last vertex links
				set_vertex_links(count, type, last_vertex, next_vertex);
				
#ifdef DISPLAY_LINKS
				// Display the vertex data
				display_data("Display After Set Vertex Links",
							 count, type, x_left, x_right, y, last_vertex, next_vertex);
#endif
				
				// Set the abscissas of the other end of each line
				set_other_abscissas(count, type, x_left, x_right, y, last_vertex, next_vertex);
				
#ifdef DISPLAY_ABSCISSAS
				// Display the vertex data
				display_data("Display After Set Other Abscissas",
							 count, type, x_left, x_right, y, last_vertex, next_vertex);
#endif
				
				// Validate that the polygon is a single closed figure
				valid = validate_polygon(count, type, x_left, x_right, y);
				
				// If the polygon is not valid
				if (!valid)
				{
					// Display an error message on the console
					cout << "@@@@@@@@@@@@ Polygon is not valid!" << endl;
				}
				
				// Else
				else
				{
					// Report that the polygon is valid on the console
					cout << "<><><><><><> Polygon is valid!" << endl;
					
					// Calculate the total area of the polygon
					area =	calculate_area(count, type, x_left, x_right, y);
					
					// Display the total area of the polygon on the console
					cout << setprecision(AREA_PRECISION) << AREA_TEXT << area << endl;
				}
			}
		}
		
		// If there was any input in the last data set
		if (count >= 0)
		{
			// Display a blank line on the console
			cout << endl;
			
			// Display a separator on the console
			cout << SEPARATOR << endl;
			
			// Display a blank line on the console
			cout << endl;
		}
	}
	
	// Terminate the program
	finish();
	
	// Return
	return 0;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                               INITIALIZE FUNCTION                                *
//  *                                                                                  *
//  ************************************************************************************

bool	initialize()							// Initialize program
{
	// This function initializes the program.
	//
	// The floating-point output format is set.
	// The title and a blank line are displayed on the console.
	// The input file is opened if present.
	// If the input file is not present, an error message is displayed.
	
	
	// Set fixed-point with decimal point floating-point output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	// Display the title on the console
	cout << TITLE << endl;
	
	// Display a blank line on the console
	cout << endl;
	
	// Open the input file if present
	fin.open(INFILE_NAME.c_str(), ios::in);
	
	// If the input file is not present
	if (!fin)
	{
		// Display an error message on the console
		cout << ERROR_NO_IN << endl;
	}
	
	// Return the input file status
	return (fin != 0);
}


//  ************************************************************************************
//  *                                                                                  *
//  *                                READ_INPUT FUNCTION                               *
//  *                                                                                  *
//  ************************************************************************************

bool	read_input(								// Read a data set
				   int		&num,					// Number of vertices
				   char	 t[],					// Vertex types	
				   double	 xl[],					// Left  abscissas
				   double	 xr[],					// Right abscissas
				   double	 yy[],					// Ordinates
				   int		 lv[],					// Last vertex
				   int		 nv[])					// Next vertex
{
	// This function reads the input data for one data set.
	//
	// All vertex data is read and stored in the data arrays.
	//
	// If the first character on a line a B or T, the abscissa is set
	// in both the left and right abscissa arrays.
	//
	// If the first character on a line an L, the abscissa is set
	// in the left abscissa and the right abscissa is set to -1.0.
	//
	// If the first character on a line an R, the abscissa is set
	// in the right abscissa and the left abscissa is set to -1.0.
	//
	// If the first character is B, L, R, or T, the last vertex index and
	// the next vertex index are both set to -1.
	//
	// If the first character is a tilde (�~�), the data set is terminated.
	//
	// If the first character is not B, L, R, or T, the line is a comment.
	// Comments are displayed but not otherwise processed.
	// 
	// The function returns true if there may be more data on the input file
	// and false if processing is to be terminated after the current data.
	
	
	bool	done;								// End of input indicator
	
	char	ch;									// First character of input line
	
	string	line;								// Input line without first character
	
	
	// Initialize the finished indicator false
	done = false;
	
	// Initialize the number of vertices to -1
	num = -1;
	
	// Do
	do
	{
		// Read the first character of the input file
		fin.get(ch);
		
		// If there is no input
		if (!fin.good())
		{
			// Set the end of input indicator true
			done = true;
		}
		
		// Else if the input line is not empty
		else if ((ch != '\n') && (ch != '\r'))
		{
			// If the number of vertices is negative
			if (num < 0)
			{
				// Set the number of vertices to zero
				num = 0;
			}
			
			// If the character is a lower case vertex type
			if ((ch == 't') || (ch == 'l') || (ch == 'r') || (ch == 'b'))
			{
				// Convert the character to upper case
				ch += 'A' - 'a';
			}
			
			// If the input line is a comment
			if ((ch != 'T') && (ch != 'L') && (ch != 'R') && (ch != 'B'))
			{
				// Read the rest of the line
				getline(fin, line);
				
				// Display the line on the console
				cout << ch << line << endl;
			}
			
			// Else
			else
			{
				// If there are too many vertices
				if (num >= MAX_VERTICES)
				{
					// Display a blank line on the console
					cout << endl;
					
					// Display an error message on the console
					cout << ERROR_TOO_MANY_V << endl;
					
					// Set the end of input indicator true
					done = true;
				}
				
				// Else
				else
				{
					// Set the vertex type
					t[num] = ch;
					
					// Read the abscissa into the left abscissa value
					fin >> xl[num];
					
					// Read the ordinate
					fin >> yy[num];
					
					// Ignore the rest of the line
					fin.ignore(10000, '\n');
					
					// Display the vertex type on the console
					cout << ch;
					
					// Display the abscissa on the console
					cout << setw(FIELD_WIDTH) << xl[num];
					
					// Display the ordinate on the console
					cout << setw(FIELD_WIDTH) << yy[num];
					
					// End the line on the console
					cout << endl;
					
					// If the type is T or B
					if ((ch == 'T') || (ch == 'B'))
					{
						// Set the right abscissa the same as the left
						xr[num] = xl[num];
					}
					
					// Else if the type is L
					else if (ch == 'L')
					{
						// Set the right abscissa to -1
						xr[num] = -1.0;
					}
					
					// Else if the type is R
					else if (ch == 'R')
					{
						// Move the input value to the right abscissa
						xr[num] = xl[num];
						
						// Set the left abscissa to -1
						xl[num] = -1.0;
						
					}
					
					// Else there is a program error
					else
					{
						// Display a program error message on the console
						cout << "@@@@@@ PROGRAM ERROR 1:  "
						<< "Input type not T, B, L, or R" << endl;
						
						// Exit
						exit (100);
					}
					
					// Set the last vertex index to -1
					lv[num] = -1;
					
					// Set the next vertex index to -1
					nv[num] = -1;
					
					// Increment the number of vertices
					num++;
				}
			}
		}
	}
	// While the end of input is not reached and there are more vertices
	while ((!done) && (ch != '~'));
	
	// Return the inverse of the finished indicator
	return !done;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                            VALIDATE_VERTICES FUNCTION                            *
//  *                                                                                  *
//  ************************************************************************************

bool	validate_vertices(						// Validate a set of vertices
						  int		 num,					// Number of vertices
						  char	 t[],					// Vertex types	
						  double	 xl[],					// Left  abscissas
						  double	 xr[],					// Right abscissas
						  double	 yy[])					// Ordinates
{
	// This function validates the vertices for one data set.
	//
	// The following requirements are checked for validity:
	//
	// 1.  All vertices must be of type T, L, R, or B.
	// 2.  There can only be one vertex of type T and it must be
	//     the first vertex if it is present.
	// 3.  There can only be one vertex of type B and it must be
	//     the last vertex if it is present.
	// 4.  If there is no vertex of type T, the first two vertices
	//     must be type L and type R (in either order) and both
    //     must have the same ordinate.
	// 5.  If there is no vertex of type B, the last two vertices
	//     must be type L and type R (in either order) and
    //     must have the same ordinate.
	// 6.  All vertices after an optional T vertex at the beginning
	//     and before an optional B vertex at the end must be type L or R.
	// 7.  Vertices must be ordered with no ascending ordinate values.		
	// 8.  There can be no more than two type L or type R vertices of the
    //     same type at any given ordinate.
	// 
	// The function returns true if all data is valid and false otherwise.
	
	
	bool	good;								// Vertices valid indicator
	bool	end;								// B vertex indicator
	
	int		v;									// Current vertex number
	int		left_count;							// Number of L type at Y
	int		right_count;						// Number of R type at Y
	
	double	last_y;								// Last       ordinate
	double	last_left_y;						// Last left  ordinate
	double	last_right_y;						// Last right ordinate
	
	
	// If there are not at least 3 vertices
	if (num < 3)
	{
		// Set the vertices valid indicator false
		good = false;
		
		// Display an error message on the console
		cout << ERROR_TOO_FEW_V << endl;
	}
	
	// Else
	else
	{
		// Initialize the vertices valid indicator true
		good = true;
		
		// Initialize the B vertex indicator false
		end = false;
		
		// Initialize the left vertex count to 0
		left_count = 0;
		
		// Initialize the right vertex count to 0
		right_count = 0;
		
		// Initialize the last ordinate to that of the first vertex
		last_y = yy[0];
		
		// If there is not a vertex or parallel line at the top
		if (!((t[0] == 'T') || (((t[0] == 'L') && (t[1] == 'R'))  ||
								((t[0] == 'R') && (t[1] == 'L'))) &&
			  (yy[0] == yy[1])))
		{
			// Set the vertices valid indicator false
			good = false;
			
			// Display an error message on the console
			cout << ERROR_INVALID_S << endl;
		}
		
		// Initialize the current vertex number to 0
		v = 0;
		
		// While the end of the data set is not reached
		while (v < num)
		{
			// If the vertex is not the first vertex
			if (v > 0)
			{
				// If the ordinate is greater than the last ordinate
				if (yy[v] > last_y)
				{
					// Set the vertices valid indicator false
					good = false;
					
					// Display an error message on the console
					cout << ERROR_INVALID_Y1 << ((t[v] == 'L') ? xl[v] : xr[v])
					<< ',' << yy[v] << ERROR_INVALID_Y2 << endl;
				}
			}
			
			// If the vertex type is T
			if (t[v] == 'T')
			{
				// If this is not the first vertex
				if (v > 0)
				{
					// Set the vertices valid indicator false
					good = false;
					
					// Display an error message on the console
					cout << ERROR_INVALID_T1 << xl[v] << ',' << yy[v]
					<< ERROR_INVALID_T2 << endl;
				}
			}
			
			// Else if the vertex type is L
			else if (t[v] == 'L')
			{
				// If there has already been a vertex of type B
				if (end)
				{
					// Set the vertices valid indicator false
					good = false;
					
					// Display an error message on the console
					cout << ERROR_INVALID_L1 << xl[v]<< ',' << yy[v]
					<< ERROR_INVALID_L2 << endl;
				}
				
				// Else
				else
				{
					// If the left vertex count is zero
					if (left_count == 0)
					{
						// Set the ordinate as the last left ordinate
						last_left_y = yy[v];
						
						// Set the left vertex count to 1
						left_count = 1;
					}
					
					// Else
					else
					{
						// If the ordinate is the same as the last left ordinate
						if (yy[v] == last_left_y)
						{
							// Increment the left vertex count
							left_count++;
							
							// If the left vertex count is greater than two
							if (left_count > 2)
							{
								// Set the vertices valid indicator false
								good = false;
								
								// Display an error message on the console
								cout << ERROR_TOO_MANY_L1 << yy[v]
								<< ERROR_TOO_MANY_L2 << endl;
							}
						}
						
						// Else
						else
						{
							// Set the left vertex count to one
							left_count = 1;
							
							// Set the ordinate as the last left ordinate
							last_left_y = yy[v];
						}
					}
				}
			}	
			
			// Else if the vertex type is R
			else if (t[v] == 'R')
			{
				// If there has already been a vertex of type B
				if (end)
				{
					// Set the vertices valid indicator false
					good = false;
					
					// Display an error message on the console
					cout << ERROR_INVALID_R1 << xr[v] << ',' << yy[v]
					<< ERROR_INVALID_R2 << endl;
				}
				
				// Else
				else
				{
					// If the right vertex count is zero
					if (right_count == 0)
					{
						// Set the ordinate as the last right ordinate
						last_right_y = yy[v];
						
						// Set the right vertex count to 1
						right_count = 1;
					}
					
					// Else
					else
					{
						// If the ordinate is the same as the last right ordinate
						if (yy[v] == last_right_y)
						{
							// Increment the right vertex count
							right_count++;
							
							// If the right vertex count is greater than two
							if (right_count > 2)
							{
								// Set the vertices valid indicator false
								good = false;
								
								// Display an error message on the console
								cout << ERROR_TOO_MANY_R1 << yy[v]
								<< ERROR_TOO_MANY_R2 << endl;
							}
						}
						
						// Else
						else
						{
							// Set the right vertex count to one
							right_count = 1;
							
							// Set the ordinate as the right left ordinate
							last_right_y = yy[v];
						}
					}
				}
			}
			
			// Else if the vertex type is B
			else if (t[v] == 'B')
			{
				// If there is more than one vertex of type B
				if (end)
				{
					// Set the vertices valid indicator false
					good = false;
					
					// Display an error message on the console
					cout << ERROR_INVALID_B1 << xl[v] << ',' << yy[v]
					<< ERROR_INVALID_B2 << endl;
				}
				
				// Else
				else
				{
					// Set the B vertex indicator true
					end = true;
				}
			}
			
			// Else there is a program error
			else
			{
				// Display a program error message on the console
				cout << "@@@@@@ PROGRAM ERROR 2:  "
				<< "Validate type not T, B, L, or R" << endl;
				
				// Exit
				exit (200);
			}
			
			// Set the last ordinate to the current ordinate
			last_y = yy[v];
			
			// Increment the current vertex number
			v++;
		}
		
		// If there is not a vertex or parallel line at the bottom
		if (!((t[num-1] == 'B') || (((t[num-1] == 'L') && (t[num-2] == 'R'))  ||
									((t[num-1] == 'R') && (t[num-2] == 'L'))) &&
			  (yy[num-1] == yy[num-2])))
		{
			// Set the vertices valid indicator false
			good = false;
			
			// Display an error message on the console
			cout << ERROR_INVALID_F << endl;
		}
	}
	
	// Return the validity of the vertices
	return good;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                             SET_VERTEX_LINKS FUNCTION                            *
//  *                                                                                  *
//  ************************************************************************************

void	set_vertex_links(						// Set the vertex links
						 int		 num,					// Number of vertices
						 char		 t[],					// Vertex types	
						 int		 lv[],					// Last vertex
						 int		 nv[])					// Next vertex
{
	// This function set the indices of the next and last vertices of a data set.
	
	
	int		v;									// Current vertex number
	int		last_left;							// Last left  vertex
	int		last_right;							// Last right vertex
	
	
	// Initialize the last left vertex to -1
	last_left = -1;
	
	// Initialize the last right vertex to -1
	last_right = -1;
	
	// Process each vertex
	for (v = 0; v < num; v++)
	{
		// If the vertex is type T
		if(t[v]=='T')
		{
			// Set the last left vertex to 0
			last_left=0;
			
			// Set the last right vertex to 0
			last_right=0;
		}
		
        // Else 
		else
		{
			//if the vertex is type L
			if(t[v]=='L')
			{
				// If there is a previous vertex
				if(last_left!=-1)
				{
					// If the last left vertex is type T
					if(t[last_left]=='T')
					{
						// Set the current vertex as the last left last vertex
						lv[last_left]=v;
					}
					// Else
					else
					{
						// Set the current vertex as the last left next vertex
						nv[last_left]=v;
					}
				}
				// Set the current last vertex to the last left vertex
				lv[v]=last_left;
				
				// Set the last left vertex to the current vertex
				last_left=v;
			}
			
			// Else
			else
			{
				//if the vertex is type R
				if(t[v]=='R')
				{
					// If there is a previous vertex
					if(last_right!=-1)
					{
						// Set the next vertex of the last right to the current vertex
						nv[last_right]=v;
					}
					
					// Set the current last vertex to the last right vertex
					lv[v]=last_right;
					
					// Set the last right vertex to the current vertex
					last_right=v;
				}
				// Else 
				else
				{
					// if the vertex is type B
					if(t[v]=='B')
					{
						// If the last left vertex is type T
						if(t[last_left]=='T')
						{
							// Set the current vertex as the last left last vertex
							lv[last_left]=v;
						}
						// Else
						else
						{
							// Set the current vertex as the last left next vertex
							nv[last_left]=v;
						}
						
						// Set the next vertex of the last right to the current vertex
						nv[last_right]=v;
					}
					// Else there is a program error
					else
					{
						// Display a program error message on the console
						cout << "Error in set_vertex_links function!";
						
					}
				}
			}
		}
	}
}


//  ************************************************************************************
//  *                                                                                  *
//  *                           SET_OTHER_ABSCISSAS FUNCTION                           *
//  *                                                                                  *
//  ************************************************************************************

void	set_other_abscissas(					// Set the other abscissas
							int		 num,					// Number of vertices
							char	 t[],					// Vertex types	
							double	 xl[],					// Left  abscissas
							double	 xr[],					// Right abscissas
							double	 yy[],					// Ordinates
							int		 lv[],					// Last vertex
							int		 nv[])					// Next vertex
{
	// This function sets the abscissa (X coordinate) of the other end of the
	// line from each vertex.
	
	
	int		v;									// Current vertex number
	int		last_left;							// Last left  vertex
	int		last_right;							// Last right vertex
	int		nv_last_left;						// Next vertex of last left
	
	double	delta;								// Incremental X length
	
	// If the first vertex is type T
	if (t[0] == 'T')
	{
		// Initialize the last left vertex to 0
		last_left = 0;
		
		// Initialize the last right vertex to 0
		last_right = 0;
	}
	
	// Else if the first vertex is type L
	else if (t[0] == 'L')
	{
		// Initialize the last left vertex to 0
		last_left = 0;
		
		// Initialize the last right vertex to 1
		last_right = 1;
	}
	
	// Else if the first vertex is type R
	else if (t[0] == 'R')
	{
		// Initialize the last left vertex to 1
		last_left = 1;
		
		// Initialize the last right vertex to 0
		last_right = 0;
	}
	
	// Else there is a program error
	else
	{
		// Display a program error message on the console
		cout << "@@@@@@ PROGRAM ERROR 4:  "
		<< "Set other abscissa type not T, L, or R" << endl;
		
		// Exit
		exit (400);
	}
	
	// If the first vertex is type T
	if (t[0] == 'T')
	{
		// Begin with the second vertex
		v = 1;
	}
	
	// Else
	else
	{
		// Begin with the first vertex
		v = 0;
	}
	
	// Process each vertex
	for (; v < num; v++)
	{
		// If the vertex is a left side vertex
		if (t[v] == 'L')
		{
			// If the last right side vertex has the same ordinate
			if (yy[last_right] == yy[v])
			{
				// Set the right abscissa as the last right side abscissa
				xr[v] = xr[last_right];
				
				// Set the last left vertex as the current vertex
				last_left = v;
			}
			
			// Else if the next right side vertex has the same ordinate
			else if (yy[nv[last_right]] == yy[v])
			{
				// Set the right abscissa as the next last right side abscissa
				xr[v] = xr[nv[last_right]];
				
				// Set the last left vertex as the current vertex
				last_left = v;
			}
			
			// Else find the vertex at the right end of the line
			else
			{
				// Calculate the incremental X length
				delta = (yy[v]      - yy[nv[last_right]])  *
					(xr[last_right] - xr[nv[last_right]])  /
					(yy[last_right] - yy[nv[last_right]]);	
				
				// Set the abscissa of the other end of the line
				xr[v] = xr[nv[last_right]] + delta;
				
				// Set the last left vertex as the current vertex
				last_left = v;
			}
		}
		
		// Else if the vertex is a right side vertex
		else if(t[v] == 'R')
		{
			// If the last left vertex is the top vertex
			if(t[last_left]=='T')
			{
				// Set the last left next vertex as
				//     the last vertex of the last left
				nv[last_left]=lv[last_left];
			}
			// Else
			else
			{
				// Set the last left next vertex as
				//     the next vertex of the last left
				nv_last_left=nv[last_left];
			}
			// If the last left side vertex has the same ordinate
			if(yy[last_left] == yy[v])
			{
				// Set the left abscissa as the last left side abscissa
				xl[v] = xl[last_left];
				
				// Set the last right vertex as the current vertex
				last_right = v;
			}
			// Else if the next left side vertex has the same ordinate
			else if(yy[nv[last_left]] == yy[v])
			{
				// Set the left abscissa as the next last left side abscissa
				xl[v] = xl[nv[last_left]];
				
				// Set the last right vertex as the current vertex
				last_right = v;
			}
			// Else find the vertex at the left end of the line
			else
			{
				// Calculate the incremental X length
				delta = (yy[v]      - yy[nv[last_left]])  *
					(xl[last_left] - xl[nv[last_left]])  /
					(yy[last_left] - yy[nv[last_left]]);	
				
				// Set the abscissa of the other end of the line
				xl[v] = xl[nv[last_left]] + delta;
				
				// Set the last right vertex as the current vertex
				last_right = v;
			}
		}
		
		// else if vertex is a bottom vertex
		else if(t[v] == 'B')
		{
			// Do nothing, x_left and x_right are already set correctly
		}
		
		// Else if the vertex is not a bottom vertex
		else
		{
			// Display a program error message on the console
			cout << "Error in set_other_abscissas function";
			// Exit
			exit(1);
		}
		
	}	
}


//  ************************************************************************************
//  *                                                                                  *
//  *                            VALIDATE_POLYGON FUNCTION                             *
//  *                                                                                  *
//  ************************************************************************************

bool	validate_polygon(						// Validate the polygon
						 int	 num,					// Number of vertices
						 char	 t[],					// Vertex types	
						 double	 xl[],					// Left  abscissas
						 double	 xr[],					// Right abscissas
						 double	 yy[])					// Ordinates
{
	// This function validates of the polygon.
	//
	// The polygon is valid if every left vertex is left of the right side
	// of the polygon at the ordinate of the vertex and every right vertex is
	// right of the left side of the polygon at the ordinate of the vertex.
	//
	// Otherwise the figure is not a single polygon and is not valid.
	// 
	// The function returns true if the polygon is valid and false otherwise.
	
	
	
	bool	ok;									// Polygon validity indicator
	
	int		v;									// Current vertex number
	
	
	// Set the polygon validity indicator true
	ok = true;
	
	// Check each vertex
	for (v = 0; v < num; v++)
	{
		// if type is bottom or top
		if(t[v]=='B' || t[v]=='T')
		{
			// do nothing, let v increment
		}
		
		// else if type is left
		else if(t[v]=='L')
		{
			if(!(xl[v]<xr[v]))
			{
				ok=false;
			}
		}
		
		// else type is right
		else
		{
			if(!(xl[v]<xr[v]))
			{
				ok=false;
			}
		}
	}
	
	// Return the polygon validity
	return ok;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                             CALCULATE_AREA FUNCTION                              *
//  *                                                                                  *
//  ************************************************************************************

double	calculate_area(							// Calculate the total area
					   int		 num,					// Number of vertices
					   char		 t[],					// Vertex types	
					   double	 xl[],					// Left  abscissas
					   double	 xr[],					// Right abscissas
					   double	 yy[])					// Next vertex
{
	// This function calculates the total area of the polygon.
	//
	// The return value is the area.
	
	
	int		v;									// Current vertex number
	
	double	a;									// Area of the polygon
	double	sa;									// Segment area
	
	
	// Initialize the area to zero
	a = 0;
	
	// Loop through each vertex, except the last one
	for(v=0; v<num-1; v++)
	{
		// If type is T
		if(t[v]=='T')
		{
			// Calculate area of top triangle
			sa=(.5 * (xr[v+1]-xl[v+1]) * (yy[v]-yy[v+1]));
		}
		
		// Else type is L or R
		else
		{
			// if the next vertex is of type B
			if(t[v+1]=='B')
			{
				// Calculate area of  bottom triangle
				sa=(.5 * (xr[v]-xl[v]) * (yy[v]-yy[v+1]));
			}
			
			else
			{
				// Calculate the area of the trapezoid
				sa=(.5 * ((xr[v]-xl[v])+(xr[v+1]-xl[v+1])) * (yy[v]-yy[v+1]));
			}

		}
		
		// Add segmenta area to total area
		a+=sa;
	}
	
	// Return the total area
	return a;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                               DISPLAY DATA FUNCTION                              *
//  *                                                                                  *
//  ************************************************************************************

void	display_data(							// Display vertex data
					 string	 text,					// Display text
					 int		 num,					// Number of vertices
					 char	 t[],					// Vertex types	
					 double	 xl[],					// Left  abscissas
					 double	 xr[],					// Right abscissas
					 double	 yy[],					// Ordinates
					 int		 lv[],					// Last vertex
					 int		 nv[])					// Next vertex
{
	// This function displays the data for all the vertices.
	
	int		v;									// Vertex number
	
	
	// Display the separator on the console
	cout << DISPLAY_BORDER << endl;
	
	// Display the text on the console
	cout << text << endl;
	
	// Display the first header on the console
	cout << HEAD1 << endl;
	
	// Display the second header on the console
	cout << HEAD2 << endl;
	
	// Display all the data on the console
	for (v = 0; v < num; v++)
	{
		// Display the vertex number
		cout << setw(2) << (v + 1);
		
		// Display the vertex type
		cout << setw(3) << t[v];
		
		// Display the left abscissa
		cout << setw(FIELD_WIDTH+1) << xl[v];
		
		// Display the right abscissa
		cout << setw(FIELD_WIDTH+1) << xr[v];
		
		// Display the ordinate
		cout << setw(FIELD_WIDTH+1) << yy[v];
		
		// Display the last vertex index
		cout << setw(VERTEX_WIDTH+1) << lv[v];
		
		// Display the next vertex index
		cout << setw(VERTEX_WIDTH+1) << nv[v];
		
		// End the line
		cout << endl;
	}
	
	// Display the separator on the console
	cout << DISPLAY_BORDER << endl;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                                 FINISH FUNCTION                                  *
//  *                                                                                  *
//  ************************************************************************************

void	finish()								// Terminate the program
{
	// This function terminates the program.
	//
	// A termination message is displayed.
	// The input  file is closed if present.
	
	
	// Display a termination message on the console
	cout << TERM << endl;
	
	// If there is an input file
	if (fin)
	{
		// Close the input file
		fin.close();
	}
}