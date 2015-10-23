// UCLA Winter 2012
// CS 31 Project 5:  Skeleton Code
// John A. Rohr
// March 8, 2012
//
//
// This program processes polygons that can be divided into segments with horizontal
// lines such that each segment except possibly the top and/or bottom will be a
// trapezoid or a parallelogram.  There may be a triangle at the top and/or the
// bottom of a polygon.  Coordinates are limited to nonnegative values.
//
// The program processes multiple sets of input data during a single execution.
//
// The area of each polygon is calculated and the polygon is drawn on a Cartesian grid.
//
// The program begins processing input data by dividing the polygon into trapezoids
// using horizontal lines.  This may result in a triangle at the top and a triangle
// at the bottom unless the top and bottom respectively are horizontal lines.  Then
// the program calculates the polygon area by first calculating the area of the
// triangle at the top, if there is one.  Next the areas of all the trapezoids
// are calculated.  Then the area of the triangle at the bottom is calculated,
// if there is one.  After all the individual areas have been calculated, they
// are added together to obtain the total area of the polygon.
//
// The area of a trapezoid (and also a parallelogram) is 1/2 of the product of
// the sum of the lengths of the parallel sides times the distance between them.
// If the two sides have lengths A and B and the distance between them is D,
// then the area of the trapezoid or parallelogram is 0.5 * (A+B) * D.
//
// The area of a triangle is 1/2 of the product of the base times the height.  If
// the base has length B and height is H, then the area of the triangle is 0.5 * B * H.
//
// After the area of the polygon is calculated, the program draws the polygon.
//
// The program first draws the coordinate axes (X axis and Y axis).  Then the
// axis scales are calculated and the axes are labeled.  Next the polygon vertices
// are drawn on the Cartesian grid.  Then the edges of the polygon are drawn to
// connect the vertices.  Finally the vertices of the polygon are labeled.  By
// labeling the vertices last, all of the text of all the vertex labels will be
// visible even if parts of the edges of the polygon is overwritten.
//
//
// Each set of data consists of all the data for one polygon.  The data set consists 
// of specifications for all the vertices of the polygon on a Cartesian coordinate
// plane in order from the highest vertex (largest ordinate, i.e. Y coordinate) value
// to the smallest.  All coordinates must be nonnegative values.
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
// column is considered a comment and is displayed but not otherwise processed
// except that all the text on the first comment of a data set that is not empty
// is used as the title of the data set.
//
// All input is read from a text file named File5.In.   All output is written to cout.
// Selected output is also written to a text file named File5.Out.  The data written
// to the output file is the Cartesian grid at specific points in the program:  after
// the vertices are drawn, after the edges are drawn, and when the figure is complete.
//
// The program reads and processes all the data on the input file until the end of
// the file is reached.
//
// Controls are included in the program to generate additional output or eliminate
// unwanted output.
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
//    |                                x  6:B(12,0)
//   0+--------------+--------------+-----O--------+--------------+----> X Axis
//    0              5             10             15             20
//
//
// Example Input File
//
// *	Project 5 Example Data
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
// POLYGON AREA CALCULATOR
//
// *	Project 5 Example Data
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
// ===========================================================================
// *	Project 5 Example Data
// #	Plot Coordinates
// ##  *         LEFT_X        RIGHT_X            Y       ABS    ORD LAST NEXT
// --  - -------------- -------------- --------------  ------ ------ ---- ----
//  1  T        12.0000        12.0000        18.0000      12     18    3    1
//  2  R         9.0000        16.0000        15.0000      16     15    0    2
//  3  R         6.0000        20.0000        12.0000      20     12    1    5
//  4  L         6.0000        20.0000        12.0000       6     12    0    4
//  5  L         4.0000        18.6667        10.0000       4     10    3    5
//  6  B        12.0000        12.0000         0.0000      12      0   -1   -1
// ===========================================================================
//
// ***************************************************************************
//
// *	Project 5 Example Data
// #	Polygon Vertices
//
//                Y                                                                  
//                ^                                                                  
//                |                                                                  
//                |                                                                  
//             50 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             40 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             30 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             20 +                                                                  
//                |                                                                  
//                |           V                                                      
//                |                                                                  
//                |                                                                  
//                +               V                                                  
//                |                                                                  
//                |                                                                  
//                |     V             V                                              
//                |                                                                  
//             10 +   V                                                              
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//              0 +----+----+-V--+----+----+----+----+----+----+----+---> X          
//                0        10        20        30        40        50                
//
// ***************************************************************************
// ***************************************************************************
//
// *	Project 5 Example Data
// #	Complete Polygon
//
//                Y                                                                  
//                ^                                                                  
//                |                                                                  
//                |                                                                  
//             50 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             40 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             30 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             20 +                                                                  
//                |                                                                  
//                |           V                                                      
//                |          x xx                                                    
//                |         x    x                                                   
//                +        x      V                                                  
//                |       x        xx                                                
//                |      x           x                                               
//                |     V             V                                              
//                |    x             x                                               
//             10 +   V              x                                               
//                |    x            x                                                
//                |     x          x                                                 
//               |     x          x                                                 
//                |      x        x                                                  
//                +       x      x                                                   
//                |        x     x                                                   
//                |         x   x                                                    
//                |         x  x                                                     
//                |          x x                                                     
//              0 +----+----+-V--+----+----+----+----+----+----+----+---> X          
//                0        10        20        30        40        50                
//
// ***************************************************************************
// ***************************************************************************
//
// *	Project 5 Example Data
// #	Complete Figure
//
//                Y                                                                  
//                ^                                                                  
//                |                                                                  
//                |                                                                  
//             50 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             40 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             30 +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                +                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//                |                                                                  
//             20 +                                                                  
//                |           1:T(12,18)                                             
//                |           V                                                      
//                |          x xx                                                    
//                |         x    x                                                   
//                +        x      V 2:R(16,15)                                       
//                |       x        xx                                                
//                |      x           x                                               
//            4:L(6,12) V             V 3:R(20,12)                                   
//                |    x             x                                               
//          5:L(4,10) V              x                                               
//                |    x            x                                                
//                |     x          x                                                 
//                |     x          x                                                 
//                |      x        x                                                  
//                +       x      x                                                   
//                |        x     x                                                   
//                |         x   x                                                    
//                |         x  x                                                     
//                |          x6:B(12,0)                                              
//              0 +----+----+-V--+----+----+----+----+----+----+----+---> X          
//                0        10        20        30        40        50                
//
// ***************************************************************************
//
// ///////////////////////////////////////////////////////////////////////////
//
// Done.


//#define DISPLAY_VERTICES
//#define DISPLAY_LINKS
//#define DISPLAY_ABSCISSAS
//#define DISPLAY_AREAS

//#define DISPLAY_SCALES
//#define DISPLAY_AXES
#define DISPLAY_COORDINATES
#define DISPLAY_POINTS
#define DISPLAY_POLYGON


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;


//  ************************************************************************************
//  *                                                                                  *
//  *                                 GLOBAL CONSTANTS                                 *
//  *                                                                                  *
//  ************************************************************************************

const	int		MAX_VERTICES        = 99;	// Maximum number of vertices

const	double	MAX_X_VALUE         = 9999;	// Maximum Vertex Abscissa
const	double	MAX_Y_VALUE         = 9999;	// Maximum Vertex Ordinate

const	int		STACK_SIZE          = 50;	// Character stack size

const	int		X_PRE_TICS          = 15;	// X Axis Tics Before Origin
const	int		X_TICS              = 50;	// X Axis Number of Tics Past Origin
const	int		X_POST_TICS         = 16;	// X Axis Tics After End
const	int		X_EXTENSION         = 3;	// X Axis Extension Tics

const	int		Y_PRE_TICS          = 1;	// Y Axis Tics Below Origin
const	int		Y_TICS              = 50;	// Y Axis Number of Tics Past Origin
const	int		Y_POST_TICS         = 4;	// Y Axis Tics After Top
const	int		Y_EXTENSION         = 2;	// Y Axis Extension Tics

const	int		X_TIC_MARKS         = 10;	// X Axis Number of Tic Marks Past Origin
const	int		Y_TIC_MARKS         = 10;	// Y Axis Number of Tic Marks Over Origin

const	int		GRID_ROWS           = Y_PRE_TICS + Y_TICS + Y_POST_TICS + 1;
const	int		GRID_COLS           = X_PRE_TICS + X_TICS + X_POST_TICS + 2;

const	int		X_AXIS_LABELS       = 5;	// X Axis Number of Tic Marks Past Origin
const	int		Y_AXIS_LABELS       = 5;	// Y Axis Number of Tic Marks Over Origin

const	char	X_AXIS_CHAR         = '-';	// X Axis Character
const	char	Y_AXIS_CHAR         = '|';	// Y Axis Tic Mark Character

const	char	X_AXIS_TIC_MARK     = '+';	// X Axis Tic Mark Character
const	char	Y_AXIS_TIC_MARK     = '+';	// Y Axis Tic Mark Character

const	char	X_AXIS_END[]        = "> X";// X Axis End Characters
const	char	Y_AXIS_END[]        = "^Y";	// Y Axis Top Characters

const	char	GRID_CLEAR_CHAR     = '.';	// Grid Clear Character
const	char	VERTEX_CHAR         = 'V';	// Vertex Character
const	char	LINE_CHAR           = 'x';	// Line   Character

const	int		LINE_SIZE           = 80;	// Input line length limit

const	int		VERTEX_WIDTH        = 4;	// Field Width for Vertex Values
const	int		DECIMAL_PLACES      = 2;	// Decimal Places for Vertex Values
const	int		COORDINATE_WIDTH    = 7;	// Field Width for Coordinate Values
const	int		FIELD_WIDTH         = 14;	// Field Width for Area Value
const	int		AREA_PRECISION      = 4;	// Decimal Places for Area

const	char  	INFILE_NAME[]       = "File5.In";
const	char  	OUTFILE_NAME[]      = "File5.Out";

const	char  	TITLE[]             = "POLYGON AREA CALCULATOR";

const	char  	MAX_ABSCISSA[]      = "MAXIMUM ABSCISSA = ";	
const	char  	MAX_ORDINATE[]      = "MAXIMUM ORIDNATE = ";

const	char  	END_ABSCISSA[]      = "X AXIS END LABEL = ";	
const	char  	END_ORDINATE[]      = "Y AXIS END LABEL = ";

const	char  	AREA_TEXT[]         = "TOTAL AREA = ";

const	char  	SEPARATOR[]         = "/////////////////////////"
"/////////////////////////"
"/////////////////////////";

const	char  	LINKS_BORDER[]      = "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL"
"LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";

const	char  	COORDS_BORDER[]     = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"
"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";

const	char  	DISPLAY_BORDER[]    = "========================="
"========================="
"=========================";

const	char  	DRAW_BORDER[]       = "*************************"
"*************************"
"*************************";

const	char  	HEAD1[]             = "##  *         LEFT_X     "
"   RIGHT_X            Y  "
"     ABS    ORD LAST NEXT";

const	char  	HEAD2[]             = "--  - -------------- ----"
"---------- --------------"
"  ------ ------ ---- ----";

const	char  	ERROR_NO_IN[]       = "***** ERROR: No input file!";

const	char  	ERROR_NO_OUT[]      = "***** ERROR: No output file!";

const	char  	ERROR_NO_V[]        = "***** ERROR: No vertices!";

const	char  	ERROR_TOO_FEW_V[]   = "***** ERROR: Less than 3 vertices!";

const	char  	ERROR_TOO_MANY_V[]  = "***** ERROR: Too many vertices!";

const	char  	ERROR_INVALID_S[]   = "***** ERROR: Invalid top of polygon!";

const	char  	ERROR_INVALID_F[]   = "***** ERROR: Invalid bottom of polygon!";

const	char  	ERROR_NEG_X1[]      = "***** ERROR: Negative abscissa (";
const	char  	ERROR_NEG_X2[]      = ")!";

const	char  	ERROR_NEG_Y1[]      = "***** ERROR: Negative ordinate (";
const	char  	ERROR_NEG_Y2[]      = ")!";

const	char  	ERROR_INVALID_T1[]  = "***** ERROR: Invalid T vertex (";
const	char  	ERROR_INVALID_T2[]  = ")!";

const	char  	ERROR_INVALID_L1[]  = "***** ERROR: Invalid L vertex (";
const	char  	ERROR_INVALID_L2[]  = ")!";

const	char  	ERROR_INVALID_R1[]  = "***** ERROR: Invalid R vertex (";
const	char  	ERROR_INVALID_R2[]  = ")!";

const	char  	ERROR_INVALID_B1[]  = "***** ERROR: Invalid B vertex(";
const	char  	ERROR_INVALID_B2[]  = ")!";

const	char  	ERROR_TOO_MANY_L1[] = "***** ERROR: Too many L vertices at Y = ";
const	char  	ERROR_TOO_MANY_L2[] = "!";

const	char  	ERROR_TOO_MANY_R1[] = "***** ERROR: Too many R vertices at Y = ";
const	char  	ERROR_TOO_MANY_R2[] = "!";

const	char  	ERROR_INVALID_Y1[]  = "***** ERROR: Ascending ordinate at (";
const	char  	ERROR_INVALID_Y2[]  = ")!";

const	char  	ERROR_L_R_OF_R1[]   = "***** ERROR: L vertex (";
const	char  	ERROR_L_R_OF_R2[]   = ") not left  of right side!";

const	char  	ERROR_R_L_OF_L1[]   = "***** ERROR: R vertex (";
const	char  	ERROR_R_L_OF_L2[]   = ") not right of left  side!";

const	char  	TERM []             = "Done.";


//  ************************************************************************************
//  *                                                                                  *
//  *                           GLOBAL VARIABLE DECLARATIONS                           *
//  *                                                                                  *
//  ************************************************************************************

ifstream fin;								// Input  file
ofstream fout;								// Output file


//  ************************************************************************************
//  *                                                                                  *
//  *                               FUNCTION PROTOTYPES                                *
//  *                                                                                  *
//  ************************************************************************************

bool	initialize();						// Initialize the program

bool	read_input(							// Read a data set
				   char	 ttl[],					// Figure title
				   int		&num,					// Number of vertices
				   char	 t[],					// Vertex types	
				   double	 xl[],					// Left  abscissas
				   double	 xr[],					// Right abscissas
				   double	 yy[],					// Ordinates
				   int		 lv[],					// Last vertex
				   int		 nv[],					// Next vertex
				   int		 abs[],					// Plot abscissas
				   int		 ord[],					// Plot ordinates
				   double	&xm,					// Maximum abscissa value
				   double	&ym);					// Maximum ordinate value

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

void	draw_axes(							// Draw the Cartesian axes
				  char	 g[][GRID_COLS],		// Display grid
				  int		 rows,					// Number of rows
				  int		 cols);					// Number of columns

void	label_axes(							// Draw the Cartesian axes
				   char	 g[][GRID_COLS],		// Display grid
				   int		 rows,					// Number of rows
				   int		 cols,					// Number of columns
				   double	 xm,					// Maximum abscissa value
				   double	 ym,					// Maximum ordinate value
				   int		&xe,					// X axis end
				   int		&ye);					// Y axis end

void	draw_vertices(						// Draw the polygon vertices
					  char	 g[][GRID_COLS],		// Display grid
					  int		 num,					// Number of vertices
					  char	 t[],					// Vertex types	
					  double	 xl[],					// Left  abscissas
					  double	 xr[],					// Right abscissas
					  double	 yy[],					// Ordinates
					  int		 abs[],					// Plot abscissas
					  int		 ord[],					// Plot ordinates
					  int		 xe,					// X axis end
					  int		 ye);					// Y axis end

void	draw_edges(							// Draw the polygon edges
				   char	 g[][GRID_COLS],		// Display grid
				   int		 num,					// Number of vertices
				   char	 t[],					// Vertex types	
				   int		 lv[],					// Last vertex
				   int		 nv[],					// Next vertex
				   int		 abs[],					// Plot abscissas
				   int		 ord[]);				// Plot ordinates

void	label_vertices(						// Label the polygon vertices
					   char	 g[][GRID_COLS],		// Display grid
					   int		 num,					// Number of vertices
					   char	 t[],					// Vertex types	
					   double	 xl[],					// Left  abscissas
					   double	 xr[],					// Right abscissas
					   double	 yy[],					// Ordinates
					   int		 abs[],					// Plot abscissas
					   int		 ord[]);				// Plot ordinates

void	display_data(						// Display vertex data
					 char  	 ttl[],					// Display title
					 char  	 text[],				// Display text
					 int		 num,					// Number of vertices
					 char	 t[],					// Vertex types	
					 double	 xl[],					// Left  abscissas
					 double	 xr[],					// Right abscissas
					 double	 yy[],					// Ordinates
					 int		 abs[],					// Plot abscissas
					 int		 ord[],					// Plot ordinates
					 int		 lv[],					// Last vertex
					 int		 nv[]);					// Next vertex

void	draw_polygon(						// Draw the polygon
					 char  	 ttl[],					// Display title
					 char  	 text[],				// Display text
					 char	g[][GRID_COLS],			// Display grid
					 int		rows,					// Number of rows
					 int		cols);					// Number of columns

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
	
	
	bool	more;								// More  input indicator
	bool	valid;								// Valid data  indicator
	
	int		count;								// Number of vertices	
	int		x_end;								// X axis end
	int		y_end;								// Y axis end
	int		row;								// Current row
	int		col;								// Current column
	
	double	x_max;								// Maximum abscissa value
	double	y_max;								// Maximum ordinate value
	double	area;								// Polygon area
	
	
	char	title[LINE_SIZE+1];					// Figure title
	
	
	char	type[MAX_VERTICES+1];				// Vertex types
	
	double	x_left[MAX_VERTICES];				// Left  abscissas
	double	x_right[MAX_VERTICES];				// Right abscissas
	double	y[MAX_VERTICES];					// Ordinates
	
	int		plot_abs[MAX_VERTICES];				// Abscissas for plotting
	int		plot_ord[MAX_VERTICES];				// Ordinates for plotting
	
	int		last_vertex[MAX_VERTICES];			// Indices of last vertex on side
	int		next_vertex[MAX_VERTICES];			// Indices of next vertex on side
	
	
	char	grid[GRID_ROWS][GRID_COLS];			// Display grid
	
	
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
		more = read_input(title, count, type, x_left, x_right, y,
		                  last_vertex, next_vertex,
						  plot_abs, plot_ord, x_max, y_max);
		
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
			display_data(title, "#	Display After Input",
						 count, type, x_left, x_right, y,
						 plot_abs, plot_ord, last_vertex, next_vertex);
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
				display_data(title, "#	Display After Set Vertex Links",
							 count, type, x_left, x_right, y,
							 plot_abs, plot_ord, last_vertex, next_vertex);
#endif
				
				// Set the abscissas of the other end of each line
				set_other_abscissas(count, type, x_left, x_right, y,
				                    last_vertex, next_vertex);
				
#ifdef DISPLAY_ABSCISSAS
				// Display the vertex data
				display_data(title "#	Display After Set Other Abscissas",
							 count, type, x_left, x_right, y,
							 plot_abs, plot_ord, last_vertex, next_vertex);
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
					
					// Display a blank line on the console
					cout << endl;
					
					// Draw the polygon
					
					// Clear the display grid
					for (row = 0; row < GRID_ROWS; row++)
					{
						// Clear one row
						for (col = 0; col < GRID_COLS - 1; col++)
						{
							// Clear one column
							grid[row][col] = GRID_CLEAR_CHAR;
						}
						
						// Add a null terminator in the last position
						grid[row][GRID_COLS-1] = '\0';
					}
					
					// Draw the axes
					draw_axes(grid, GRID_ROWS, GRID_COLS-1);
					
					// Label the axes
					label_axes(grid, GRID_ROWS, GRID_COLS-1, x_max, y_max, x_end, y_end);
					
#ifdef DISPLAY_SCALES
					// Display the maximum abscissa
					cout << MAX_ABSCISSA << x_max << endl;
					
					// Display the maximum ordinate
					cout << MAX_ORDINATE << y_max << endl;
					
					// Display the X axis end label
					cout << END_ABSCISSA << x_end << endl;
					
					// Display the Y axis end label
					cout << END_ORDINATE << y_end << endl;
#endif
					
#ifdef DISPLAY_AXES
					// Display the labeled axes
					draw_polygon(title, "#	Labeled Axes", grid, GRID_ROWS, GRID_COLS-1);
#endif
					
					// Draw the polygon vertices
					draw_vertices(grid, count, type, x_left, x_right, y,
					              plot_abs, plot_ord, x_end, y_end);
					
#ifdef DISPLAY_COORDINATES
					// Display the plot Coordinates",
					display_data(title, "#	Plot Coordinates",
								 count, type, x_left, x_right, y,
								 plot_abs, plot_ord,
								 last_vertex, next_vertex);
#endif
					
#ifdef DISPLAY_POINTS
					// Display the polygon vertices
					draw_polygon(title, "#	Polygon Vertices", grid,
								 GRID_ROWS, GRID_COLS-1);
#endif
					
					// Draw the polygon edges
					draw_edges(grid, count, type, last_vertex, next_vertex,
					           plot_abs, plot_ord);
					
#ifdef DISPLAY_POLYGON
					// Display the complete polygon
					draw_polygon(title, "#	Complete Polygon", grid,
								 GRID_ROWS, GRID_COLS-1);
#endif
					
					// Label the polygon vertices
					label_vertices(grid, count, type, x_left, x_right, y,
					               plot_abs, plot_ord);
					
					// Display the final labeled polygon figure
					draw_polygon(title, "#	Complete Figure", grid,
								 GRID_ROWS, GRID_COLS-1);
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

bool	initialize()								// Initialize program
{
	// This function initializes the program.
	//
	// The floating-point output format is set.
	// The title and a blank line are displayed on the console.
	// The input file is opened if present.
	// If the input file is not present, an error message is displayed.
	// Else the output file is opened.
	// If the output file cannot be opened, an error message is displayed.
	
	
	// Set fixed-point with decimal point floating-point output format
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	
	// Display the title on the console
	cout << TITLE << endl;
	
	// Display a blank line on the console
	cout << endl;
	
	// Open the input file if present
	fin.open(INFILE_NAME, ios::in);
	
	// If the input file is present
	if (fin)
	{
		// Open the output file if present
		fout.open(OUTFILE_NAME, ios::out);
		
		// If there is an output file
		if (fout)
		{
			// Write the title to the output file
			fout << TITLE << endl;
			
			// Write a blank line to the output file
			fout << endl;
		}
		
		// Else
		else
		{
			// Display an error message on the console
			cout << ERROR_NO_OUT << endl;
		}
	}
	
	// Else
	else
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
				   char	 ttl[],					// Figure title
				   int		&num,					// Number of vertices
				   char	 t[],					// Vertex types	
				   double	 xl[],					// Left  abscissas
				   double	 xr[],					// Right abscissas
				   double	 yy[],					// Ordinates
				   int		 lv[],					// Last vertex
				   int		 nv[],					// Next vertex
				   int		 abs[],					// Plot abscissas
				   int		 ord[],					// Plot ordinates
				   double	&xm,					// Maximum abscissa value
				   double	&ym)					// Maximum ordinate value
{
	// This function reads the input data for one data set and determines the
	// maximum abscissa value and the maximum ordinate value.
	//
	// All vertex data is read and stored in the data arrays.
	//
	// All the text on the first comment line of the set that has any characters
	// is stored as the title of the figure.
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
	// If the first character is a tilde ('~'), the data set is terminated.
	//
	// If the first character is not B, L, R, or T, the line is a comment.
	// Comments are displayed but not otherwise processed.
	// 
	// The function returns true if there may be more data on the input file
	// and false if processing is to be terminated after the current data.
	//
	// The last vertex, next vertex, plot abscissa, and plot ordinate data are
	// initialized for all the vertices.
	
	
	bool	done;								// End of input indicator
	
	int		index;								// Title copy index
	
	char	ch;									// First character of input line
	
	char  	line[LINE_SIZE];					// Input line without first character
	
	
	// Initialize the finished indicator false
	done = false;
	
	// Initialize the number of vertices to -1
	num = -1;
	
	// Initialize the maximum abscissa to zero
	xm = 0.0;
	
	// Initialize the maximum ordinate to zero
	ym = 0.0;
	
	// Initialize the title empty
	ttl[0] = '\0';
	
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
				fin.getline(line, LINE_SIZE);
				
				// Display the line on the console
				cout << ch << line << endl;
				
				// If no title has yet been stored and
				//    there are any characters on the line 
				if ((ttl[0] == '\0') && (line[0] != '\0'))
				{
					// Copy the first character of the line to the title
					ttl[0] = ch;
					
					// Initialize the index
					index = 0;
					
					// Copy the rest of the line to the title
					for (; line[index] != '\0'; index++)
					{
						// Copy one character of the input line
						ttl[index+1] = line[index];
					}
					
					// Terminate the line
					ttl[index+1] = '\0';
				}
				
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
					
					// If the abscissa is greater than the maximum abscissa so far
					if (xl[num] > xm)
					{
						// Set the abscissa as the maximum abscissa
						xm = xl[num];
					}
					
					// If the ordinate is greater than the maximum abscissa so far
					if (yy[num] > ym)
					{
						// Set the ordinate as the maximum abscissa
						ym = yy[num];
					}
					
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
					
					// Set the plot abscissa to -1
					abs[num] = -1;
					
					// Set the plot ordinate to -1
					ord[num] = -1;
					
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
	// The function returns true if all data are valid and false otherwise.
	
	
	bool	good;								// Vertices valid indicator
	bool	end;								// B vertex indicator
	
	int		v;									// Current vertex number
	int		left_count;							// Number of L type at Y
	int		right_count;						// Number of R type at Y
	
	double	x;									// Current abscissa value
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
			
			// If the vertex is type L
			if (t[v] == 'L')
			{
				// Set the abscissa value from the left abscissa value
				x = xl[v];
			}
			
			// Else
			else
			{
				// Set the abscissa value from the right abscissa value
				x = xr[v];
			}
			
			// If the abscissa is negative
			if (x < 0.0)
			{
				// Display an error message on the console
				cout << ERROR_NEG_X1 << x << ',' << yy[v]
				<< ERROR_NEG_X2 << endl;
				
				// Set the vertices valid indicator false
				good = false;
			}
			
			// If the ordinate is negative
			if (yy[v] < 0.0)
			{
				// Display an error message on the console
				cout << ERROR_NEG_Y1 << x << ',' << yy[v]
				<< ERROR_NEG_Y2 << endl;
				
				// Set the vertices valid indicator false
				good = false;
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
						 char	 t[],					// Vertex types	
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
		if (t[v] == 'T')
		{
			// Set the last left vertex to 0
			last_left = 0;
			
			// Set the last right vertex to 0
			last_right = 0;
		}
		
		// Else if the vertex is type L
		else if (t[v] == 'L')
		{
			// If there is a previous vertex
			if (last_left >= 0)
			{
				// Set the next vertex of the last left
				// If the last left vertex is type T
				if (t[last_left] == 'T')
				{
					// Set the current vertex as the last left last vertex
					lv[last_left] = v;
				}
				
				// Else
				else
				{
					// Set the current vertex as the last left next vertex
					nv[last_left] = v;
				}
			}
			
			// Set the current last vertex to the last left vertex
			lv[v] = last_left;
			
			// Set the last left vertex to the current vertex
			last_left = v;
		}
		
		// Else if the vertex is type R
		else if (t[v] == 'R')
		{
			// If there is a previous vertex
			if (last_right >= 0)
			{
				// Set the next vertex of the last right to the current vertex
				nv[last_right] = v;
			}
			
			// Set the current last vertex to the last right vertex
			lv[v] = last_right;
			
			// Set the last right vertex to the current vertex
			last_right = v;
		}
		
		// Else if the vertex is type B
		else if (t[v] == 'B')
		{
			// If there is a previous last left vertex
			if (last_left >= 0)
			{
				// Set the next vertex of the last left
				// If the last left vertex is type T
				if (t[last_left] == 'T')
				{
					// Set the current vertex as the last left last vertex
					lv[last_left] = v;
				}
				
				// Else
				else
				{
					// Set the current vertex as the last left next vertex
					nv[last_left] = v;
				}
			}
			
			// If there is a previous last right vertex
			if (last_right >= 0)
			{
				// Set the next vertex of the last right to the current vertex
				nv[last_right] = v;
			}
		}
		
		// Else there is a program error
		else
		{
			// Display a program error message on the console
			cout << "@@@@@@ PROGRAM ERROR 3:  "
			<< "Set vertex links type not T, B, L, or R" << endl;
			
			// Exit
			exit (300);
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
				delta = (yy[v]          - yy[nv[last_right]])  *
				(xr[last_right] - xr[nv[last_right]])  /
				(yy[last_right] - yy[nv[last_right]]);	
				
				// Set the abscissa of the other end of the line
				xr[v] = xr[nv[last_right]] + delta;
				
				// Set the last left vertex as the current vertex
				last_left = v;
			}
		}
		
		// Else if the vertex is a right side vertex
		else if (t[v] == 'R')
		{
			// If the last left vertex is the top vertex
			if (t[last_left] == 'T')
			{
				// Set the last left next vertex from the as the last vertex
				// of the last left
				nv_last_left = lv[last_left];
			}
			
			// Else
			else
			{
				// Set the last left next vertex from the as the next vertex
				// of the last left
				nv_last_left = nv[last_left];
			}
			
			// If the last left side vertex has the same ordinate
			if (yy[last_left] == yy[v])
			{
				// Set the left abscissa as the last left side abscissa
				xl[v] = xl[last_left];
				
				// Set the last right vertex as the current vertex
				last_right = v;
			}
			
			// Else if the next left side vertex has the same ordinate
			else if (yy[nv_last_left] == yy[v])
			{
				// Set the left abscissa as the next last left side abscissa
				xl[v] = xl[nv_last_left];
				
				// Set the last right vertex as the current vertex
				last_right = v;
			}
			
			// Else find the vertex at the left end of the line
			else
			{
				// Calculate the incremental X length
				delta = (yy[v]         - yy[nv_last_left])  *
				(xl[last_left] - xl[nv_last_left])  /
				(yy[last_left] - yy[nv_last_left]);	
				
				// Set the abscissa of the other end of the line
				xl[v] = xl[nv_last_left] + delta;
				
				// Set the last right vertex as the current vertex
				last_right = v;
			}
		}
		
		// Else if the vertex is not a bottom vertex
		else if (t[v] != 'B')
		{
			// There is a program error
			// Display a program error message on the console
			cout << "@@@@@@ PROGRAM ERROR 5:  "
			<< "Set other abscissa type not L R, or B" << endl;
			
			// Exit
			exit (500);
		}
	}	
}


//  ************************************************************************************
//  *                                                                                  *
//  *                            VALIDATE_POLYGON FUNCTION                             *
//  *                                                                                  *
//  ************************************************************************************

bool	validate_polygon(						// Validate the polygon
						 int		 num,					// Number of vertices
						 char	 t[],					// Vertex types	
						 double	 xl[],					// Left  abscissas
						 double	 xr[],					// Right abscissas
						 double	 yy[])					// Ordinates
{
	// This function validates of the polygon.
	//
	// The polygon is valid if the every left vertex is left of the right side
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
		// If the vertex is type L
		if (t[v] == 'L')
		{
			// If the left vertex is not left of the right side
			if (xl[v] >= xr[v])
			{
				// Set the polygon validity indicator false
				ok = false;
				
				// Display an error message on the console
				cout << ERROR_L_R_OF_R1 << xl[v] << ',' << yy[v]
				<< ERROR_L_R_OF_R2 << endl;
			}
		}
		
		// Else if the vertex is type R
		if (t[v] == 'R')
		{
			// If the right vertex is not right of the left side
			if (xl[v] >= xr[v])
			{
				// Set the polygon validity indicator false
				ok = false;
				
				// Display an error message on the console
				cout << ERROR_R_L_OF_L1 << xr[v] << ',' << yy[v]
				<< ERROR_R_L_OF_L2 << endl;
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
					   char	 t[],					// Vertex types	
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
	
	// Initialize the vertex to the first vertex
	v = 0;
	
	// If the polygon has a top vertex
	if (t[0] == 'T')
	{
		// Get the area of the top triangle
		sa = 0.5 * (xr[1] - xl[1]) * (yy[0] - yy[1]);
		
#ifdef DISPLAY_AREAS		
		// Display the top triangle area on the console
		cout << "Top Triangle Area = " << sa << endl;
#endif
		
		// Add the area of the top triangle to the total area
		a += sa;
		
		// Move to the second vertex
		v++;
	}
	
	// Process each segment except for a bottom triangle
	for (; (v < num-1); v++)
	{
		// Get the area of the trapezoid segment
		sa = 0.5 * ((xr[v] - xl[v]) + (xr[v+1] - xl[v+1])) * (yy[v] - yy[v+1]);
		
#ifdef DISPLAY_AREAS		
		// Display the trapezoid segment area on the console
		cout << "Trapezoid Segment Area = " << sa << endl;
#endif
		
		// Add the area of the top triangle to the total area
		a += sa;		
	}
	
	// If the polygon has a bottom vertex
	if (t[num-1] == 'T')
	{
		// Get the area of the bottom triangle
		sa = 0.5 * (xr[num-2] - xl[num-2]) * (yy[num-2] - yy[num-1]);
		
#ifdef DISPLAY_AREAS		
		// Display the top triangle area on the console
		cout << "Bottom Triangle Area  = " << sa << endl;
#endif
		
		// Add the area of the bottom triangle to the total area
		a += sa;
	}
	
	// Return the total area
	return a;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                                DRAW AXES FUNCTION                                *
//  *                                                                                  *
//  ************************************************************************************

void	draw_axes(								// Draw the Cartesian axes
				  char	 g[][GRID_COLS],		// Display grid
				  int		 rows,					// Number of rows
				  int		 cols)					// Number of columns
{
	// This function draws the Cartesian axes.
	
	
	int		r;									// Row    number
	int		c;									// Column number
	
	
	// Draw the Y axis
	
	// Set the column
	c = X_PRE_TICS;
	
	// Draw the base Y axis
	for (r = Y_POST_TICS + Y_TICS; r > Y_POST_TICS - Y_EXTENSION - 2; r--)
	{
		// Draw one Y axis character
		g[r][c] = Y_AXIS_CHAR;
	}
	
	// Draw the end of the Y axis
	for (r = 0; r < strlen(Y_AXIS_END); r++)
	{
		// Draw one character at the end of the Y axis
		g[Y_POST_TICS - Y_EXTENSION - 1 - r][c] = Y_AXIS_END[r];
	}
	
	// Draw the Y axis tic marks
	for (r = Y_POST_TICS + Y_TICS; r > Y_POST_TICS - 2; r -= Y_TICS/Y_TIC_MARKS)
	{
		// Draw one Y axis tic mark
		g[r][c] = Y_AXIS_TIC_MARK;
	}	
	
	
	// Draw the X axis
	
	// Set the row
	r = GRID_ROWS - 1 - Y_PRE_TICS;
	
	// Draw the base X axis
	for (c = X_PRE_TICS; c < X_PRE_TICS + X_TICS + X_EXTENSION + 1; c++)
	{
		// Draw one X axis character
		g[r][c] = X_AXIS_CHAR;
	}
	
	// Draw the end of the X axis
	for (c = 0; c < strlen(X_AXIS_END); c++)
	{
		// Draw one character at the end of the X axis
		g[r][X_PRE_TICS + X_TICS + X_EXTENSION + 1 + c] = X_AXIS_END[c];
	}
	
	// Draw the X axis tic marks
	for (c = X_PRE_TICS; c <= X_PRE_TICS + X_TICS; c += X_TICS/X_TIC_MARKS)
	{
		// Draw one X axis tic mark
		g[r][c] = X_AXIS_TIC_MARK;
	}
}


//  ************************************************************************************
//  *                                                                                  *
//  *                               LABEL AXES FUNCTION                                *
//  *                                                                                  *
//  ************************************************************************************

void	label_axes(								// Label the Cartesian axes
				   char	 g[][GRID_COLS],		// Display grid
				   int		 rows,					// Number of rows
				   int		 cols,					// Number of columns
				   double	 xm,					// Maximum abscissa value
				   double	 ym,					// Maximum ordinate value
				   int		&xe,					// X axis end
				   int		&ye)					// Y axis end
{
	// This function calculates the scales for the axes then draws the labels
	// on the Cartesian axes.
	
	
	char	stack[STACK_SIZE];					// Digit characters stack
	
	int		r;									// Row    number
	int		c;									// Column number
	int		d;									// Digit  index
	int		i;									// Character index
	int		digits;								// Digits count
	int		residual;							// Residual value
	
	
	// Calculate the X axis end point
	xe = ((xe = 10 * pow(10, floor(log10(xm)))) == (10 * xm)) ? (xe / 10) :
	((xm <= xe/2) ? (xe / 2) : xe);
	
	// Calculate the Y axis end point
	ye = ((ye = 10 * pow(10, floor(log10(ym)))) == (10 * ym)) ? (ye / 10) :
	((ym <= ye/2) ? (ye / 2) : ye);
	
	
	// Label the Y axis
	
	// Set the origin label
	g[Y_POST_TICS+Y_TICS][X_PRE_TICS-2] = '0';
	
	// Set the other labels
	for (i = 1; i <= Y_AXIS_LABELS; i++)
	{
		// Set the row
		r = Y_POST_TICS + Y_TICS - (i * Y_TICS / Y_AXIS_LABELS);
		
		// Set the starting column
		c = X_PRE_TICS-2;
		
		// Initialize the residual value
		residual = i * ye / Y_AXIS_LABELS;
		
		// Do
		do
		{
			// Set one digit character
			g[r][c] = residual % 10  +  '0';
			
			// Decrease the residual
			residual /= 10;
			
			// Move to the next column
			c--;
		}
		// While there are more digits to generate
		while (residual > 0);
	}
	
	
	// Label the X axis
	
	// Set the row for all X axis labels
	r = Y_POST_TICS+Y_TICS+1;
	
	// Set the origin label
	g[r][X_PRE_TICS] = '0';
	
	// Set the other labels
	for (i = 1; i <= X_AXIS_LABELS; i++)
	{
		// Initialize the digit count
		digits = 0;
		
		// Initialize the residual value
		residual = i * xe / X_AXIS_LABELS;
		
		// Generate the digit characters
		do
		{
			// Generate one digit character
			stack[digits] = residual % 10  +  '0';
			
			// Decrease the residual
			residual /= 10;
			
			// Increment the digit count
			digits++;
			
			// Move to the next column
			c--;
		}
		// While there are more digits to generate
		while (residual > 0);
		
		// Set the starting column
		c = X_PRE_TICS + (i * X_TICS / X_AXIS_LABELS) + ((digits - 1) / 2);
		
		// Set the digit characters
		for (d = 0; d < digits; d++)
		{
			// Set one digit character
			g[r][c] = stack[d];
			
			// Move to the next column
			c--;			
		}
	}
}


//  ************************************************************************************
//  *                                                                                  *
//  *                              DRAW VERTICES FUNCTION                              *
//  *                                                                                  *
//  ************************************************************************************

void	draw_vertices(							// Draw the polygon vertices
					  char	 g[][GRID_COLS],		// Display grid
					  int		 num,					// Number of vertices
					  char	 t[],					// Vertex types	
					  double	 xl[],					// Left  abscissas
					  double	 xr[],					// Right abscissas
					  double	 yy[],					// Ordinates
					  int		 abs[],					// Plot abscissas
					  int		 ord[],					// Plot ordinates
					  int		 xe,					// X axis end
					  int		 ye)					// Y axis end
{
	// This function determines the plot abscissa and plot ordinate for each vertex
	// and plots each vertex on the Cartesian grid.
	//
	// The plot abscissas and plot ordinates are points on the Cartesian plot plane.
	// Each coordinate is between 0 and the maximum number of tics on the axis.  For
	// example, if the number of tics on axis is 50, the plot coordinates for that axis
	// will range from 0 to 50, regardless of the actual coordinates of the vertex.
	//
	// The constant character VERTEX_CHAR is used as the character to plot each vertex.
	
	
	int		v;									// Current vertex number
	
	int		r;									// Row    number
	int		c;									// Column number
	
	
	// Plot each vertex
	for (v = 0; v < num; v++)
	{
		// if vertex is a left vertex
		if(t[v]=='L')
		{
			//calculate plot abs and ord
			abs[v] = (floor(xl[v]) * X_TICS) / xe + 0.5;
			ord[v] = (floor(yy[v]) * Y_TICS) / ye + 0.5;
		}
		
		// else
		else
		{
			//calculate plot abs and ord
			abs[v] = (floor(xr[v]) * X_TICS) / xe + 0.5;
			ord[v] = (floor(yy[v]) * Y_TICS) / ye + 0.5;
		}
		
		// set row and column to plot ord and plot abs respectively
		r=ord[v];
		c=abs[v];
		
		// plot the vertices on the graph
		g[Y_POST_TICS+Y_TICS-r][c+X_PRE_TICS]=VERTEX_CHAR;
		
	}
}


//  ************************************************************************************
//  *                                                                                  *
//  *                               DRAW EDGES FUNCTION                                *
//  *                                                                                  *
//  ************************************************************************************

void	draw_edges(								// Draw the polygon edges
				   char		 g[][GRID_COLS],		// Display grid
				   int		 num,					// Number of vertices
				   char		 t[],					// Vertex types	
				   int		 lv[],					// Last vertex
				   int		 nv[],					// Next vertex
				   int		 abs[],					// Plot abscissas
				   int		 ord[])					// Plot ordinates
{
	// This function draws the edges of the polygon.
	//
	// The linear equation y = a*x + b is used to draw the edges between the vertices.
	//
	// Using two points on a line, (x1, y1) and (x2, y2), the values of a and b can be
	// calculated as follows:
	//
	//     a = (an / ad)  where  an = (y1 - y2)  and  ad = (x1 - x2);
	//
	//     b = (y1 - a * x1)  or  b = (y2 - a * x2).
	//
	// If there are as many or more horizontal steps than vertical steps between
	// a pair of vertices, the equation used is
	//
	//     y = an * x / ad + b
	//
	// and every horizontal step is used to draw a point on the line
	// between the vertices.
	//
	// If there are more vertical steps than horizontal steps between the vertices,
	// the equation used is
	//
	//     x = (y - b) * ad / an
	//
	// and every vertical step is used to draw a point on the line between the vertices.
	//
	// Plot coordinates are rounded to the nearest integer for plotting.
	//
	// Horizontal lines at the top of a polygon and the bottom of a polygon are special
	// cases and are drawn before the edges connecting the other vertices are drawn.
	//
	// A vertical line between vertices is a special case and is drawn without using the
	// equation cited above.
	//
	// The constant character LINE_CHAR is used as the character to plot each line point.
	
	
	bool	top_left;							// Top left vertex indicator
	
	int		v;									// Current vertex number
	int		next;								// Next    vertex number
	
	int		i;									// Plot loop index
	
	int		x;									// Edge point plot abscissa
	int		y;									// Edge point plot ordinate
	
	int		x1;									// First  vertex abscissa
	int		x2;									// Second vertex abscissa
	
	int		x_steps;							// Horizontal steps between vertices
	int		y_steps;							// Vertical   steps between vertices
	
	double	an;									// Linear equation multiplier numerator
	double	ad;									// Linear equation multiplier denominator
	
	double	b;									// Linear equation constant
	
	
	
	 // Set the top left indicator false
	 top_left = false;
	 
	 // If there is a top vertex
	 if (t[0] == 'T')
	 {
		 // Set the top left indicator true
		 top_left = true;
	 }
	 
	 // Else there is no top vertex
	 else
	 {
		 // If the first vertex is a left vertex and
		 //    the second vertex is a right vertex
		 if ((t[0] == 'L') && (t[1] == 'R'))
		 {
			 // Set the left plot abscissa
			 x1 = abs[0];
			 
			 // Set the right plot ordinate
			 x2 = abs[1];
		 }
	 
		 // Else if the first vertex is a right vertex and
		 //         the second vertex is a left vertex
		 else if ((t[0] == 'R') && (t[1] == 'L'))
		 {
			 // Set the left plot abscissa
			 x1 = abs[1];
	 
			 // Set the right plot ordinate
			 x2 = abs[0];
		 }
	 
		 // Else
		 else
		 {
			 // There is a program error
			 // Display a program error message on the console
			 cout << "@@@@@@ PROGRAM ERROR 7:  "
			 << "Top vertices for edge line are not types  L and R" << endl;
	 
			 // Exit
			 exit (700);
		 }
	 
		 // If the two points do not have the same ordinate
		 if (ord[0] != ord[1])
		 {
			 // There is a program error
			 // Display a program error message on the console
			 cout << "@@@@@@ PROGRAM ERROR 8:  "
			 << "Line not horizontal for drawing top line" << endl;
	 
			 // Exit
			 exit (800);
		 }
	 
		 // Set the plot ordinate
		 y = ord[0];
	 
		 // Plot the top edge line
		 for (x = x1 + 1; x < x2; x++)
		 {
			 // Plot the  point of the top line
			 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
		 }
	 }
	 
	 // If there is a horizontal line at the bottom of the polygon
	 if (t[num-1] != 'B')
	 {
		 // If the next to last vertex is a left vertex and
		 //    the last vertex is a right vertex
		 if ((t[num-2] == 'L') && (t[num-1] == 'R'))
		 {
			 // Set the left plot abscissa
			 x1 = abs[num-2];
	 
			 // Set the right plot ordinate
			 x2 = abs[num-1];
		 }
	 
		 // Else if the next to last vertex is a right vertex and
		 //         the last vertex is a left vertex
		 else if ((t[num-2] == 'R') && (t[num-1] == 'L'))
		 {
			 // Set the left plot abscissa
			 x1 = abs[num-1];
	 
			 // Set the right plot ordinate
			 x2 = abs[num-2];
		 }
	 
		 // Else
		 else
		 {
			 // There is a program error
			 // Display a program error message on the console
			 cout << "@@@@@@ PROGRAM ERROR 9:  "
			 << "Bottom vertices for edge line are not types  L and R" << endl;
	 
			 // Exit
			 exit (900);
		 }
	 
		 // If the two points do not have the same ordinate
		 if (ord[num-2] != ord[num-1])
		 {
			 // There is a program error
			 // Display a program error message on the console
			 cout << "@@@@@@ PROGRAM ERROR 10:  "
			 << "Line not horizontal for drawing bottom line" << endl;
	 
			 // Exit
			 exit (1000);
		 }
	 
		 // Set the plot ordinate
		 y = ord[num-1];
	 
		 // Plot the bottom edge line
		 for (x = x1 + 1; x < x2; x++)
		 {
			 // Plot the  point of the bottom line
			 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
		 }		// Draw the horizontal line at the bottom of the polygon
	 }
	 
	 // Initialize the vertex number to the top vertex
	 v = 0;
	 
	 // Plot all the other edges
	 do
	 {
		 // If this is the left edge from a top vertex
		 if (top_left)
		 {
			 // Set the next left vertex number from the last vertex number
			 next = lv[v];
		 }
	 
		 // Else
		 else
		 {
			 // Set the next left vertex number from the next vertex number
			 next = nv[v];
		 }
	 
		 // if the vertices are in the same column (same x value)
		 if(abs[v]==abs[nv[v]])
		 {
			 
			 y_steps=ord[v]-ord[nv[v]];
			 
			 x=abs[v];
			 
			 for(i=1; i<y_steps; i++)
			 {
				 y=ord[v]-i;
				 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
			 }
			 
			 /*
			 if(t[v]=='T')
			 {
				 y_steps=ord[v]-ord[lv[v]];
				 x_steps=abs[v]-abs[lv[v]];
				 
				 if(x_steps<0)
				 {
					 x_steps=-x_steps; 
				 }
				 
				 
				 an = 0-y_steps;
				 ad = x_steps;
				 b = (ord[v] - (an/ad) * abs[v]);
				 
				 
				 if(x_steps>=y_steps)
				 {
					 for(i=1; i<x_steps; i++)
					 {
						 
						 if(abs[v]-abs[lv[v]]>0)
						 {
							 x=abs[v]-i;
						 }
						 else
						 {
							 x=abs[v]+i;
						 }
						 
						 y = (an * x) / ad + b;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
				 
				 else
				 {
					 for(i=1; i<y_steps; i++)
					 {
						 y=ord[v]+i;
						 x = ((y - b) * ad) / an;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }				 
			 }*/
			 
			 
			  
		 }
		 // if the vertices are in the same column (this case accounts for when a vertex is of type T)
		 //		and thus lv[v] actually stores the next left
		 else if(abs[v]==abs[lv[v]])
		 {
			 
			 y_steps=ord[v]-ord[lv[v]];
			 
			 x=abs[v];
			 
			 for(i=1; i<y_steps; i++)
			 {
				 y=ord[v]-i;
				 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
			 }
			 
			 if(t[v]=='T')
			 {
				 y_steps=ord[v]-ord[nv[v]];
				 x_steps=abs[v]-abs[nv[v]];
				
				 if(x_steps<0)
				 {
					 x_steps=-x_steps; 
				 }
				 
				 
				 an = 0-y_steps;
				 ad = x_steps;
				 b = (ord[v] - (an/ad) * abs[v]);
				 
				 				 
				 if(x_steps>=y_steps)
				 {
					 for(i=1; i<x_steps; i++)
					 {
						 
						 if(abs[v]-abs[nv[v]]>0)
						 {
							 x=abs[v]-i;
						 }
						 else
						 {
							 x=abs[v]+i;
						 }
						 
						 y = (an * x) / ad + b;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
				 
				 else
				 {
					 for(i=1; i<y_steps; i++)
					 {
						 y=ord[v]+i;
						 x = ((y - b) * ad) / an;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
				 
			 }
			 
			 
		 }
		 
		 // else 
		 else
		 {
			 /*
			 if(t[v]=='T')
			 {
				 y_steps=ord[v]-ord[nv[v]];
				 x_steps=abs[v]-abs[nv[v]];
				 
				 if(x_steps<0)
				 {
					 x_steps=-x_steps; 
				 }
				 
				 
				 an = 0-y_steps;
				 ad = x_steps;
				 b = (ord[v] - (an/ad) * abs[v]);
				 
				 
				 if(x_steps>=y_steps)
				 {
					 for(i=1; i<x_steps; i++)
					 {
						 
						 if(abs[v]-abs[nv[v]]>0)
						 {
							 x=abs[v]-i;
						 }
						 else
						 {
							 x=abs[v]+i;
						 }
						 
						 y = (an * x) / ad + b;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
				 
				 else
				 {
					 for(i=1; i<y_steps; i++)
					 {
						 y=ord[v]+i;
						 x = ((y - b) * ad) / an;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
				 
				 y_steps=ord[v]-ord[lv[v]];
				 x_steps=abs[v]-abs[lv[v]];
				 
				 if(x_steps<0)
				 {
					 x_steps=-x_steps; 
				 }
				 
				 
				 an = 0-y_steps;
				 ad = x_steps;
				 b = (ord[v] - (an/ad) * abs[v]);
				 
				 
				 if(x_steps>=y_steps)
				 {
					 for(i=1; i<x_steps; i++)
					 {
						 
						 if(abs[v]-abs[lv[v]]>0)
						 {
							 x=abs[v]-i;
						 }
						 else
						 {
							 x=abs[v]+i;
						 }
						 
						 y = (an * x) / ad + b;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
				 
				 else
				 {
					 for(i=1; i<y_steps; i++)
					 {
						 y=ord[v]+i;
						 x = ((y - b) * ad) / an;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }				 
				 
				 
			 }
			 
			 else
			 {
				 y_steps=ord[v]-ord[nv[v]];
				 x_steps=abs[v]-abs[nv[v]];
			 
				 if(x_steps<0)
				 {
					 x_steps=-x_steps; 
				 }
			 
			 
				 an = 0-y_steps;
				 ad = x_steps;
				 b = (ord[v] - (an/ad) * abs[v]);
			 
			 
				 if(x_steps>=y_steps)
				 {
					 for(i=1; i<x_steps; i++)
					 {
					 
						 if(abs[v]-abs[nv[v]]>0)
						 {
							 x=abs[v]-i;
						 }
						 else
						 {
							 x=abs[v]+i;
						 }
					 
						 y = (an * x) / ad + b;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
			 
				 else
				 {
					 for(i=1; i<y_steps; i++)
					 {
						 y=ord[v]+i;
						 x = ((y - b) * ad) / an;
						 g[Y_POST_TICS+Y_TICS-y][X_PRE_TICS+x] = LINE_CHAR;
					 }
				 }
			 }
			  */
		 }
		 
		 
	 
		 // If the current edge is the top left edge
		 if (top_left)
		 {
			 // Set the top left indicator false
			 top_left = false;
		 }
	 
		 // Else
		 else
		 {
			 // Move to the next vertex
			 v++;
		 }
	 }
	 // While there are more edges to draw
	 while (nv[v] >= 0);
	 
}


//  ************************************************************************************
//  *                                                                                  *
//  *                             LABEL VERTICES FUNCTION                              *
//  *                                                                                  *
//  ************************************************************************************

void	label_vertices(						// Label the polygon vertices
					   char		 g[][GRID_COLS],		// Display grid
					   int		 num,					// Number of vertices
					   char		 t[],					// Vertex types	
					   double	 xl[],					// Left  abscissas
					   double	 xr[],					// Right abscissas
					   double	 yy[],					// Ordinates
					   int		 abs[],					// Plot abscissa
					   int		 ord[])					// Plot ordinate
{
	// This function labels the vertices of the polygon.
	//
	// The format of each label is:  #;t(x,y) where # is the number of the vertex
	// (beginning with 1), t is the type of the vertex, and x and y are the nearest
	// integer values of the abscissa and ordinate of the vertex labeled.
	//
	// All abscissa and ordinate values for vertex labels are rounded to the nearest
	// integer value for the label.  Numbers in labels use only as many digits as
	// are required to specify the value.
	//
	// The placement of the labels is as follows:
	//
	//      T:  The label begins directly above the vertex on the next line above.
	//
	//      L:  If the vertex is on the X axis, the last digit of the ordinate is
	//               directly above the vertex on the next line above;
	//          Else the label is on the same line as the vertex and ends
	//               immediately before a single space on the left side of the vertex.
	//
	//      R:  If the vertex is on the X axis, the label begins directly above
	//               the vertex on the next line above;
	//          Else the label is on the same line as the vertex and begins immediately
	//               after a single space on the right side of the vertex.
	//
	//      B:  If the vertex is on the X axis, the label begins directly above
	//               the vertex on the next line above;
	//          Else if the vertex is on the line immediately above the X axis
	//               the label begins on the same line as the vertex immediately
	//               after a single space on the right side of the vertex;
	//          Else the label begins directly below the vertex on the next line below.
	
	
	char	stack[STACK_SIZE];					// Label characters stack
	
	int		v;									// Current vertex number
	
	int		r;									// Row    number
	int		c;									// Column number
	int		s;									// Stack index
	int		residual;							// Residual value
	
	
	// Label each vertex
	for (v = 0; v < num; v++)
	{
		s=0;
		
		// convert the vertex number into a string and place it in the stack array
		if(v+1>=10)
		{
			stack[s]=(char)(((v+1)/10)+'0');
			s++;
			stack[s]=(char)(((v+1)%10)+'0');
			s++;
		}
		else
		{
			stack[s]=(char)(v+1+'0');
			s++;
		}
		
		
		// place the colon, type, and opening parantheses in the stack array
		stack[s]=':';
		s++;
		stack[s]=t[v];
		s++;
		stack[s]='(';
		s++;
		
		
		// convert the x coordinate to a string
		
		// case where vertex is a left vertex
		if(t[v]=='L')
		{
			if(xl[v]==0)
			{
				stack[s]='0';
				s++;
			}
			else
			{
				if(xl[v]>=100)
				{
					stack[s]=((int)xl[v])/100+'0';
					s++;
					stack[s]=(((int)xl[v])/10)%10+'0';
					s++;
					stack[s]=((int)xl[v])%10+'0';
					s++;
				}
				else if(xl[v]<100 && xl[v]>=10)
				{
					stack[s]=(xl[v])/10+'0';
					s++;
					stack[s]=(int)(xl[v])%10+'0';
					s++;
				}
				
				else
				{
					stack[s]=(char)xl[v]+'0';
					s++;
				}
			}
			
		}
		// case where vertex is not a left vertex
		else
		{
			if(xr[v]==0)
			{
				stack[s]='0';
				s++;
			}
			else
			{
				if(xr[v]>=100)
				{
					stack[s]=((int)xr[v])/100+'0';
					s++;
					stack[s]=(((int)xr[v])/10)%10+'0';
					s++;
					stack[s]=((int)xr[v])%10+'0';
					s++;
				}
				else if(xr[v]<100 && xr[v]>=10)
				{
					stack[s]=(xr[v])/10+'0';
					s++;
					stack[s]=(int)(xr[v])%10+'0';
					s++;
				}
				
				else
				{
					stack[s]=(char)xr[v]+'0';
					s++;
				}
			}
			
		}
		
		// place comma in stack
		stack[s]=',';
		s++;
		
		
		// convert the y coordinate to a string and place it in stack
		if(yy[v]==0)
		{
			stack[s]='0';
			s++;
		}
		else
		{
			if(yy[v]>=100)
			{
				stack[s]=((int)yy[v])/100+'0';
				s++;
				stack[s]=(((int)yy[v])/10)%10+'0';
				s++;
				stack[s]=((int)yy[v])%10+'0';
				s++;
			}
			else if(yy[v]<100 && yy[v]>=10)
			{
				stack[s]=(yy[v])/10+'0';
				s++;
				stack[s]=(int)(yy[v])%10+'0';
				s++;
			}
			 
			else
			{
				stack[s]=(char)yy[v]+'0';
				s++;
			}
		}
		
		// place closing paranthese in stack
		stack[s]=')';
		
		// initialize residual to where s currently is
		residual=s;
		
		// determine where to plot the labels based on type
		if(t[v]=='T')
		{
			//      T:  The label begins directly above the vertex on the next line above.
			r=ord[v]+1;
			c=abs[v];
		}
		else if(t[v]=='L')
		{
			//      L:  If the vertex is on the X axis, the last digit of the ordinate is
			//               directly above the vertex on the next line above;
			if(yy[v]==0)
			{
				r=ord[v]+1;
				c=abs[v]-residual+1;
			}
			//          Else the label is on the same line as the vertex and ends
			//               immediately before a single space on the left side of the vertex.
			else
			{
				r=ord[v];
				c=abs[v]-residual-2;
			}
		}
		else if(t[v]=='R')
		{
			//      R:  If the vertex is on the X axis, the label begins directly above
			//               the vertex on the next line above;
			if(yy[v]==0)
			{
				r=ord[v]+1;
				c=abs[v];
			}
			
			//          Else the label is on the same line as the vertex and begins immediately
			//               after a single space on the right side of the vertex.
			else
			{
				r=ord[v];
				c=abs[v]+2;
			}
		}
		else
		{
			//      B:  If the vertex is on the X axis, the label begins directly above
			//               the vertex on the next line above;
			if(yy[v]==0)
			{
				r=ord[v]+1;
				c=abs[v];
			}
			//          Else if the vertex is on the line immediately above the X axis
			//               the label begins on the same line as the vertex immediately
			//               after a single space on the right side of the vertex;
			else if(yy[v]+1==0)
			{
				r=ord[v];
				c=abs[v]+2;
			}
			//          Else the label begins directly below the vertex on the next line below.
			else
			{
				r=ord[v]-1;
				c=abs[v];
			}
		}
		
		// plot the vertices on the graph
		for(s=0; s<residual+1; s++)
		{
			g[Y_POST_TICS+Y_TICS-r][c+X_PRE_TICS+s]=stack[s];
		}
		
	}
}


//  ************************************************************************************
//  *                                                                                  *
//  *                               DISPLAY DATA FUNCTION                              *
//  *                                                                                  *
//  ************************************************************************************

void	display_data(							// Display vertex data
					 char  	 ttl[],					// Display title
					 char  	 text[],				// Display text
					 int		 num,					// Number of vertices
					 char	 t[],					// Vertex types	
					 double	 xl[],					// Left  abscissas
					 double	 xr[],					// Right abscissas
					 double	 yy[],					// Ordinates
					 int		 abs[],					// Plot abscissas
					 int		 ord[],					// Plot ordinates
					 int		 lv[],					// Last vertex
					 int		 nv[])					// Next vertex
{
	// This function displays the data for all the vertices.
	
	
	int		v;									// Vertex number
	
	
	// Display the separator on the console
	cout << DISPLAY_BORDER << endl;
	
	// Display the title on the console
	cout << ttl << endl;
	
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
		
		// Display the plot abscissa
		cout << setw(COORDINATE_WIDTH+1) << abs[v];
		
		// Display the plot ordinate
		cout << setw(COORDINATE_WIDTH) << ord[v];
		
		// Display the last vertex index
		cout << setw(VERTEX_WIDTH+1) << lv[v];
		
		// Display the next vertex index
		cout << setw(VERTEX_WIDTH+1) << nv[v];
		
		// End the line
		cout << endl;
	}
	
	// Display the separator on the console
	cout << DISPLAY_BORDER << endl;
	
	// Display a blank line on the console
	cout << endl;
}


//  ************************************************************************************
//  *                                                                                  *
//  *                                DRAW DATA FUNCTION                                *
//  *                                                                                  *
//  ************************************************************************************

void	draw_polygon(							// Draw the polygon
					 char  	 ttl[],					// Display title
					 char  	 text[],				// Display text
					 char	g[][GRID_COLS],			// Display grid
					 int		rows,					// Number of rows
					 int		cols)					// Number of columns
{
	// This function draws the polygon as generated.
	
	
	int		row;								// Row number
	
	
	// Display the separator on the console
	cout << DRAW_BORDER << endl;
	
	// Display a blank line on the console
	cout << endl;
	
	// Display the title on the console
	cout << ttl << endl;
	
	// Display the text on the console
	cout << text << endl;
	
	// Display a blank line on the console
	cout << endl;
	
	// Display each line on the console
	for (row = 0; row < rows; row++)
	{
		// Display one row on the console
		cout << g[row] << endl;
	}
	
	// Display a blank line on the console
	cout << endl;
	
	// Display the separator on the console
	cout << DRAW_BORDER << endl;
	
	// If there is an output file
	if (fout)
	{
		// Write  the separator to the output file
		fout << DRAW_BORDER << endl;
		
		// Write  a blank line to the output file
		fout << endl;
		
		// Write  the text to the output file
		fout << text << endl;
		
		// Write  the title to the output file
		fout << ttl << endl;
		
		// Write  a blank line to the output file
		fout << endl;
		
		// Write  each line to the output file
		for (row = 0; row < rows; row++)
		{
			// Write  one row to the output file
			fout << g[row] << endl;
		}
		
		// Write  a blank line to the output file
		fout << endl;
		
		// Write  the separator to the output file
		fout << DRAW_BORDER << endl;
	}
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
	// The output file is closed if present.
	// The input  file is closed if present.
	
	
	// Display a termination message on the console
	cout << TERM << endl;
	
	// If there is an output file
	if (fout)
	{
		// Write a termination message to the output file
		fout << TERM << endl;
		
		// Close the output file
		fout.close();
	}
	
	// If there is an input file
	if (fin)
	{
		// Close the input file
		fin.close();
	}
}
