#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool findKnightsTour(std::vector<std::vector < int>> &board,
	std::vector<int> horzMoves, std::vector<int> vertMoves,
	std::string startSquare, std::string endSquare,
	std::vector<std::string > &tour);
void parseAdValdInput(int argc, char *argv[], int &boardSize,
	std::string &startSquare, std::string &endSquare,
	std::vector<int> &startIndexes,
	std::vector<int> &endIndexes);
bool isValidMove(std::vector<std::vector < int>> board, int nextMoveVer,
	int nextMoveHor);
void printTour(std::vector<std::string > tour);
void markSquare(std::vector<std::vector < int>> &board, int nextMoveHorz,
	int nextMoveVer, std::vector<std::string > &tour);
void unMarkSquare(std::vector<std::vector < int>> &board, int horzMoves,
	int vertMoves, std::string startSquare, int &nextMoveHorz,
	int &nextMoveVer, std::vector<std::string > &tour);
int strToInt(std::string string);
std::vector<int> squNamToIndex(std::string squNam);
std::string indexToSquNam(int horIndex, int verIndex);

int main(int argc, char *argv[])
{
	int boardSize;
	std::string startSquare;
	std::string endSquare;
	std::vector<std::string > tour;
	std::vector<int> startIndexes;
	std::vector<int> endIndexes;
	std::vector<int> horzMoves = { 2, 1, -1, -2, -2, -1, 1, 2 };
	std::vector<int> vertMoves = { 1, 2, 2, 1, -1, -2, -2, -1 };

	try
	{
		parseAdValdInput(argc, argv, boardSize, startSquare, endSquare,
			startIndexes, endIndexes);

		std::vector<std::vector < int>> board(boardSize, std::vector<int> (boardSize));
		board.at(startIndexes.at(1)).at(startIndexes.at(0)) = 1;
		tour.push_back(startSquare);

		if (findKnightsTour(board, horzMoves, vertMoves, startSquare, endSquare,
				tour))
		{
			printTour(tour);
		}
		else
		{
			throw std::runtime_error(" could not find a knight's tour ");
		}
	}

	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}

	return 0;
}

void parseAdValdInput(int argc, char *argv[], int &boardSize,
	std::string &startSquare, std::string &endSquare,
	std::vector<int> &startIndexes,
	std::vector<int> &endIndexes)
{
	if (argc != 4)
	{
		throw std::invalid_argument("invalid parameter list");
	}

	boardSize = strToInt(argv[1]);
	startSquare = argv[2];
	endSquare = argv[3];

	if (boardSize > 26 || boardSize <= 0)
	{
		throw std::invalid_argument("invalid parameter list");
	}

	startIndexes = squNamToIndex(startSquare);
	endIndexes = squNamToIndex(endSquare);

	if (startIndexes.at(0) >= boardSize || startIndexes.at(1) < 0 ||
		endIndexes.at(0) >= boardSize || endIndexes.at(1) >= boardSize)
	{
		throw std::invalid_argument("invalid parameter list");
	}
}

bool findKnightsTour(std::vector<std::vector < int>> &board,
	std::vector<int> horzMoves, std::vector<int> vertMoves,
	std::string startSquare, std::string endSquare,
	std::vector<std::string > &tour)
{
	if (startSquare == endSquare)
		return true;

	for (unsigned int i = 0; i < vertMoves.size(); i++)
	{
		std::vector<int> startIndexes = squNamToIndex(startSquare);

		int nextMoveHorz = startIndexes.at(0) + horzMoves.at(i);
		int nextMoveVer = startIndexes.at(1) + vertMoves.at(i);

		if (isValidMove(board, nextMoveVer, nextMoveHorz))
		{
			markSquare(board, nextMoveHorz, nextMoveVer, tour);

			std::string nextStartMove = indexToSquNam(nextMoveHorz, nextMoveVer);

			bool success = findKnightsTour(board, horzMoves, vertMoves, nextStartMove,
				endSquare, tour);

			if (success)
				return true;

			unMarkSquare(board, horzMoves.at(i), vertMoves.at(i), startSquare,
				nextMoveHorz, nextMoveVer, tour);
		}
	}

	return false;
}

void printTour(std::vector<std::string > tour)
{
	for (unsigned int i = 0; i < tour.size(); ++i)
	{
		std::cout << tour.at(i) << " ";
	}

	std::cout << std::endl;
}

int strToInt(std::string string)
{
	int num = 0;
	for (unsigned int i = 0; i < string.size(); ++i)
	{
		num = (num *10) + int(string.at(i) - '0');
	}

	return num;
}

std::vector<int> squNamToIndex(std::string squNam)
{
	std::vector<int> indexes(2);
	char letter = squNam.at(0);
	int num = 0;

	for (unsigned int i = 1; i < squNam.size(); ++i)
	{
		num = (num *10) + int(squNam.at(i) - '0');
	}

	indexes.at(0) = (int(letter) - 97);
	indexes.at(1) = (num - 1);

	return indexes;
}

std::string indexToSquNam(int horIndex, int verIndex)
{
	char letter = (horIndex + 97);
	std::string squName = letter + std::to_string(verIndex + 1);

	return squName;
}

bool isValidMove(std::vector<std::vector < int>> board, int nextMoveVer,
	int nextMoveHor)
{
	if ((nextMoveVer >= 0) && (nextMoveHor >= 0) &&
		(nextMoveVer < board.size()) && (nextMoveHor < board.size()) &&
		(board.at(nextMoveVer).at(nextMoveHor) == 0))
		return true;

	return false;
}

void markSquare(std::vector<std::vector < int>> &board, int nextMoveHorz,
	int nextMoveVer, std::vector<std::string > &tour)
{
	board.at(nextMoveVer).at(nextMoveHorz) = 1;
	std::string tourMove = indexToSquNam(nextMoveHorz, nextMoveVer);
	tour.push_back(tourMove);
}

void unMarkSquare(std::vector<std::vector < int>> &board, int horzMoves,
	int vertMoves, std::string startSquare, int &nextMoveHorz,
	int &nextMoveVer, std::vector<std::string > &tour)
{
	tour.pop_back();
	board.at(nextMoveHorz).at(nextMoveVer) = 0;
	std::vector<int> startIndexes = squNamToIndex(startSquare);
	nextMoveHorz = startIndexes.at(0) - horzMoves;
	nextMoveVer = startIndexes.at(1) - vertMoves;
}