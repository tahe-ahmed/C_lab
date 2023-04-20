#include <ctime>
#include <iostream>
#include <limits>
#include <random>
#include <stack>
#include <string>
#include <vector>
#include "Maze.h"

int main(int argc, char *argv[])
{
	int rows;
	int cols;
	int seed;

	try
	{
		if (argc < 3 || argc > 4)
		{
			throw std::invalid_argument("Invalid Command. Usage: ./maze row col seed");
		}

		rows = std::stoi(argv[1]);
		cols = std::stoi(argv[2]);

		if (argv[3])
		{
			seed = std::stoi(argv[3]);
		}
		else
		{
			seed = time(0) % 10;
		}

		Maze maze(rows, cols, seed);
		maze.createMaze();

		Cell from = maze.getFirstCell();
		Cell to = maze.getLastCell();

		maze.findPath(from, to);
		maze.show();
	}

	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}