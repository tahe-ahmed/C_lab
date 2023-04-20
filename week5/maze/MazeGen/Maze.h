#include "Cell.h"

class Maze
{
    public:
    	Maze(int rows, int cols, int seed);
    	
    	void createMaze();
    	void show() const;
    	bool findPath(Cell &from, Cell to);
    	
    	Cell getFirstCell(){ return cells.at(0); }
    	Cell getLastCell() { return cells.at(cells.size() - 1); }

    private:
		int rows;
    	int cols;
    	int randSeed;
    	std::vector<Cell> cells;
    	std::vector<Cell> visitedCells;
    	std::vector<Cell> neighbors;
    	std::stack<Cell> stackCells;
    
    	bool isValid(int i, int j) const { return !(i < 0 || j < 0 || i >= rows || j >= cols);}
    	int index(int i, int j) const { return ((i *cols) + j); }
    
    	bool isSafe(int cellIndex, int directionNum);
    	void clearIsVisited();
    	void createCellsVector();
    	void removeWalls(int currentIndex, int nextIndex);
    	int getRandNum(int Max) const;
    	void checkNeighbors(int i, int j);
};

Maze::Maze(int rows, int cols, int seed)
{
	this->rows = rows;
	this->cols = cols;
	this->randSeed = seed;
}

void Maze::removeWalls(int currentIndex, int nextIndex)
{
	if (currentIndex < nextIndex)
	{
		if (nextIndex - currentIndex == 1)
		{
			cells.at(currentIndex).removeRight();	/// right of current
			cells.at(nextIndex).removeLeft();	/// left of next
		}
		else
		{
			cells.at(currentIndex).removeBottom();	/// bottom of current
			cells.at(nextIndex).removeTop();	/// top of the next
		}
	}
	else if (currentIndex > nextIndex)
	{
		if (currentIndex - nextIndex == 1)
		{
			cells.at(currentIndex).removeLeft();	/// remove left of current
			cells.at(nextIndex).removeRight();	/// remove right of next
		}
		else
		{
			cells.at(currentIndex).removeTop();	/// top of current
			cells.at(nextIndex).removeBottom();	/// bottom of next
		}
	}
}

void Maze::createMaze()
{
	createCellsVector();

	cells.at(0).visitCell();
	visitedCells.push_back(cells.at(0));
	Cell current = cells.at(0);

	while (visitedCells.size() != cells.size())
	{
		checkNeighbors(current.getX(), current.getY());
		if (neighbors.size() > 0)
		{
			int randIndex = getRandNum(neighbors.size());

			Cell next = neighbors.at(randIndex);

			stackCells.push(next);

			int nextIndex = index(next.getX(), next.getY());
			int currentIndex = index(current.getX(), current.getY());

			removeWalls(currentIndex, nextIndex);

			cells.at(nextIndex).visitCell();
			visitedCells.push_back(cells.at(nextIndex));
			current = next;
		}
		else
		{
			if (stackCells.size() != 0)
			{
				stackCells.pop();
				current = stackCells.top();
			}
		}
	}

	clearIsVisited();
}

void Maze::show() const
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cells.at(j + (i *cols)).drawHorzWallsTop();
		}

		std::cout << std::endl;
		for (int j = 0; j < cols; ++j)
		{
			cells.at(j + (i *cols)).drawVertWallsLeft();
			if (j == cols - 1)
				cells.at(j + (i *cols)).drawVertWallsRight();
		}

		std::cout << std::endl;
		for (int j = 0; j < cols; ++j)
		{
			cells.at(j + (i *cols)).drawHorzWallsBottom(cols);
		}
	}

	std::cout << std::endl;
}

bool Maze::findPath(Cell &from, Cell to)
{
	cells.at(0).visitCell();
	from.visitCell();

	if ((from.getX() == to.getX()) && (from.getY() == to.getY()))
	{
		return true;
	}

	if (isValid(from.getX() - 1, from.getY()))
	{
		int cellIndex = index(from.getX() - 1, from.getY());
		if (isSafe(cellIndex, 2))
		{
			if (findPath(cells.at(cellIndex), to))
				return true;
		}
	}

	if (isValid(from.getX(), from.getY() + 1))
	{
		int cellIndex = index(from.getX(), from.getY() + 1);
		if (isSafe(cellIndex, 3))
		{
			if (findPath(cells.at(cellIndex), to))
				return true;
		}
	}

	if (isValid(from.getX() + 1, from.getY()))
	{
		int cellIndex = index(from.getX() + 1, from.getY());
		if (isSafe(cellIndex, 0))
		{
			if (findPath(cells.at(cellIndex), to))
				return true;
		}
	}

	if (isValid(from.getX(), from.getY() - 1))
	{
		int cellIndex = index(from.getX(), from.getY() - 1);
		if (isSafe(cellIndex, 1))
		{
			if (findPath(cells.at(cellIndex), to))
				return true;
		}
	}

	from.UnVisitCell();
	return false;
}

void Maze::checkNeighbors(int i, int j)
{
	neighbors.clear();
	if (isValid(i, j - 1))
	{
		Cell top = cells.at(index(i, j - 1));
		if (!top.getIsVisited())
			neighbors.push_back(top);
	}

	if (isValid(i + 1, j))
	{
		Cell right = cells.at(index(i + 1, j));
		if (!right.getIsVisited())
			neighbors.push_back(right);
	}

	if (isValid(i, j + 1))
	{
		Cell bottom = cells.at(index(i, j + 1));
		if (!bottom.getIsVisited())
			neighbors.push_back(bottom);
	}

	if (isValid(i - 1, j))
	{
		Cell left = cells.at(index(i - 1, j));
		if (!left.getIsVisited())
			neighbors.push_back(left);
	}
}

int Maze::getRandNum(int Max) const
{
	std::srand(randSeed);
	return (rand() % Max);
}

void Maze::createCellsVector()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			Cell cell(i, j);
			cells.push_back(cell);
		}
	}
}

bool Maze::isSafe(int cellIndex, int directionNum)
{
	return (!cells.at(cellIndex).getWalls().at(directionNum) &&
		!cells.at(cellIndex).getIsVisited());
}

void Maze::clearIsVisited()
{
	for (int i = 0; i < cells.size(); ++i)
	{
		cells.at(i).UnVisitCell();
	}
}