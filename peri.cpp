#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 3;

bool readSquare(int square[SIZE][SIZE], string inputFileName)
{
	//create object to read file
	fstream input;
	bool open_state;

	//open file
	input.open(inputFileName.c_str());
	if (input.is_open() == true)
		open_state = true;
	else open_state = false;

	for (int x = 1; x <= 9; x++)
	{
		for (int y = 1; y <= 9; y++)
		{
			input >> square[x][y];
		}
	}
	input.close();

	if (open_state = true)
		return true;
	else return false;
}

void printSquare(int square[SIZE][SIZE])
{
	cout << "Magic square" << endl;

	// Print out the Magic Square
	for (int x = 1; x <= 3; x++)
	{
		for (int y = 1; y <= 3; y++)
		{
			if (square[x][y] < 10)
				cout << " ";
			cout << square[x][y] << " ";
		}
		cout << endl;
	}
}

bool validateSquare(int square[SIZE][SIZE])
{
	int Row_Total = 0, Total;
	bool Square = true;
	// Get value for top row
	for (int x = 1; x <= 3; x++)
		Row_Total += square[1][x];

	// Read  each row and compare with top row value
	for (int x = 1; x <= 3; x++)
	{
		Total = 0; // Reset variable for next row
		for (int y = 1; y <= 3; y++)
		{
			Total += square[x][y];
		}
		if (Total != Row_Total)
			Square = false;
	}

	// Read  each column and compare with top row value
	for (int y = 1; y <= 3; y++)
	{
		Total = 0; // Reset variable for next column
		for (int x = 1; x <= 3; x++)
		{
			Total += square[x][y];
		}
		if (Total != Row_Total)
			Square = false;
	}

	Total = 0; // Reset variable

			   // Read diagonal top left to bottom right
	for (int x = 1; x <= 3; x++)
	{
		Total += square[x][x];
	}
	if (Total != Row_Total)
		Square = false;

	// Read diagonal top right to bottom left

	int y = 1;
	Total = 0; // Reset variable
	for (int x = 3; x > 0; x--)
	{
		Total += square[y][x];
		y++;
	}
	if (Total != Row_Total)
		Square = false;

	if (Square == true)
	{
		cout << endl << "Valid magic square" << endl;
		return true;
	}
	else
	{
		cout << endl << "Invalid magic square" << endl;
		return false;
	}
}

// main function
int main()
{
	int square[SIZE][SIZE];
	string inputFileName;
	getline(cin, inputFileName);
	//call function to open file and load matrix array with matrix found in file
	bool matrixSize = readSquare(square, inputFileName);

	//call function to output
	if (matrixSize == true)
	{
		printSquare(square);

		//call function to verify if square is a magic square
		validateSquare(square);
	}
	else
	{
		cout << "File \"" << inputFileName << "\" could not be opened" << endl;
	}

	return 0;
}
