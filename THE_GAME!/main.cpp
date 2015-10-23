#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
const int SIZE=9;
void printBoard(char s[SIZE][SIZE]);
bool isMine(int a, int b, char s[SIZE][SIZE]);
char numMines(int a, int b, char s[SIZE][SIZE]);


int main (int argc, char * const argv[])
{
	
	cout << endl << endl;
    char board[SIZE][SIZE];
	char answerBoard[SIZE][SIZE];
	int mines;
	int hits=0;
	int x, y;
	
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			board[i][j]='+';
		}
	}
	
	for(int i=0; i<SIZE; i++)
	{
		board[i][0]=i+'0';
		board[0][i]=i+'0';
	}
	
	cout << "How many ships would you like to play with? ";
	cin >> mines;
	cin.ignore(1000, '\n');
	
	
	for(int i=0; i<mines; i++)
	{
		cout << "Enter a position to place a mine (of the form row column): ";
		cin >> x >> y;
		cin.ignore(1000, '\n');
		answerBoard[x][y]='X';
	}
	
	while(hits<1)
	{
		printBoard(board);
		cout << "Enter a position to examine (of the form row column): ";
		cin >> x >> y;
		cin.ignore(1000, '\n');
		if(isMine(x, y, answerBoard))
		{
			board[x][y]='X';
			hits++;
		}
		else
		{
			board[x][y]=numMines(x, y, answerBoard);
		}

	}
	printBoard(board);
	cout<<endl<<endl<<"GG";
	
	
	
	cout << endl << endl;
    return 0;
}

char numMines(int a, int b, char s[SIZE][SIZE])
{
	int count=0;
	for(int i=a-1; i<=a+1; i++)
	{
		for(int j=b-1; j<=a+1; j++)
		{
			if(isMine(i, j, s))
			{
				count++;
			}
		}
	}
	
	if(count==0)
	{
		for(int i=a-1; i<=a+1; i++)
		{
			for(int j=b-1; j<=a+1; j++)
			{
				s[i][j]=numMines(i, j, s);

			}
		}
	}
	
	return char(count+'0');
}

bool isMine(int a, int b, char s[SIZE][SIZE])
{
	if(s[a][b]=='X')
	{
		return true;
	}
	else
	{
		return false;
	}

}

void printBoard(char s[SIZE][SIZE])
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
}