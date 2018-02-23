// INFO450Guess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;


const int ROWS = 8;
const int COLS = 8;
const int BOMB = 1;
const int GUESSES = 5;
const int GOLD = 5;

void initializeArray(char board[ROWS][COLS]);
void items(char board[ROWS][COLS]);
void printArray(char mArray[ROWS][COLS]);
void guessWhere(char board[ROWS][COLS]);

char answer;

int main()
{
	do
	{
		char board[ROWS][COLS];

		initializeArray(board);
		printArray(board);
		items(board);
		guessWhere(board);


		cout << endl;
		//This asks if the user wants to play again.
		cout << "\nPlay again? Hit Y for yes: ";
		cin >> answer;
		cout << "\n";

	} while (answer == 'y' | answer == 'Y');

	return 0;

}
//This function initializes the array.
void initializeArray(char board[ROWS][COLS])
{
	int rows, cols;

	for (rows = 0; rows < ROWS; rows++)
	{

		for (cols = 0; cols < COLS; cols++)
		{
			board[rows][cols] = ' ';
		}
	}
}
// This function sets the items randomly throughout the board.
void items(char board[ROWS][COLS])
{
	int gold = 0;
	int x, y;
	int bomb = 0;
	srand(time(NULL));

	for (gold = 0; gold < GOLD; gold++)
	{
		x = rand() % ROWS;
		y = rand() % COLS;
		board[x][y] = 'G';
	}

	for (bomb = 0; bomb < BOMB; bomb++)
	{
		x = rand() % ROWS;
		y = rand() % COLS;
		board[x][y] = 'B';
	}

}
// This function displays the instructions to the user
void printArray(char mArray[ROWS][COLS])
{
	int r, c;

	cout << "    ";

	for (c = 0; c < COLS; c++)

		cout << c + 1 << "  ";

	cout << endl;
	cout << "   ------------------------" << endl;



	for (r = 0; r < ROWS; r++)
	{
		cout << r + 1 << " ";
		cout << "| ";

		for (c = 0; c < COLS; c++)
		{
			cout << "?" << "  ";
		}
		cout << endl;
	}



	cout << "   ------------------------" << endl;
	cout << " **  *******************  **" << endl;
	cout << " **      Find Gold!       **" << endl;
	cout << " ** You Have Five Guesses,**" << endl;
	cout << " **   5 Pieces of Gold    **" << endl;
	cout << " **      and 1 bomb       **" << endl;
	cout << " **      Good Luck!       **" << endl;
	cout << " **  *******************  **" << endl;

	cout << endl;
}
//This function has the user input coordinates and in displays the results in the end.
void guessWhere(char board[ROWS][COLS])
{
	int r, c;
	int attempts = GUESSES;
	int points = 0;

	while (attempts > 0)
	{
		cout << endl;
		cout << "Enter an X coordinate: ";
		cin >> r;
		cout << endl;
		cout << "Enter a Y coordinate: ";
		cin >> c;

		if (board[r - 1][c - 1] == 'G')
		{
			cout << endl;
			cout << "You found GOLD!! You get another attempt. ";
			board[r - 1][c - 1] = 'F';
			points = points + 1;
			attempts--;
			attempts++;
			cout << "You have " << attempts << " guesses left!!" << endl;
			cout << endl;
			continue;
		}
		else if (board[r - 1][c - 1] == 'B')
		{
			cout << endl;
			attempts = 0;
			cout << "Bomb!!" << "GAME OVER" << endl;
			break;

		}
		else
			cout << endl;
		cout << "Too Bad. ";
		attempts--;
		cout << "You have " << attempts << " guesses left!!" << endl;
		cout << endl;

	}

	cout << "You earned " << points << " points!!" << endl;
	cout << "Better Luck Next Time!!" << endl;
	cout << "Here's your board: " << endl;
	cout << endl;

	cout << endl;
	cout << "    ";

	for (c = 0; c < COLS; c++)

		cout << c + 1 << "  ";

	cout << endl;
	cout << "   ------------------------" << endl;



	for (r = 0; r < ROWS; r++)
	{
		cout << r + 1 << " ";
		cout << "| ";

		for (c = 0; c < COLS; c++)
		{
			cout << board[c][r] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}