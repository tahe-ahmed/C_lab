#include "Coord.h"

class Cell {
    public:
      Cell(int i, int j) {
        coord.setX(i);
        coord.setY(j);
      }
    
      int getX() { return coord.getX(); }
      int getY() { return coord.getY(); }
    
      void removeTop() { walls.at(0) = false; }
      void removeRight() { walls.at(1) = false; }
      void removeBottom() { walls.at(2) = false; }
      void removeLeft() { walls.at(3) = false; }
    
      void visitCell() { isVisited = true; }
      void UnVisitCell() { isVisited = false; }
      bool getIsVisited() { return isVisited; }
    
      std::vector<bool> getWalls() { return walls; }
    
      void drawHorzWallsTop() const;
      void drawVertWallsLeft() const;
      void drawVertWallsRight() const;
      void drawHorzWallsBottom(int cols) const;
    
    private:
      Coord coord;
      std::string cellContent;
      std::vector<bool> walls = {true, true, true, true};
      bool isVisited = false;
};

void Cell::drawHorzWallsTop() const
{
	if (coord.getX() == 0 &coord.getY() == 0)
	{
		std::cout << "+" <<
			"---" <<
			"+";
	}
	else if (coord.getX() == 0)
	{
		std::cout << "---" <<
			"+";
	}
}

void Cell::drawVertWallsLeft() const
{
	if (walls.at(3))
	{
		std::cout << "|" << (isVisited ? " . " : "   ");
	}
	else
	{
		std::cout << " " << (isVisited ? " . " : "   ");
	}
}

void Cell::drawVertWallsRight() const
{
	if (walls.at(1))
		std::cout << "|";
}

void Cell::drawHorzWallsBottom(int cols) const
{
	if (walls.at(2))
		std::cout << "+" <<
		"---";
	else
	{
		std::cout << "+   ";
	}

	if (coord.getY() == cols - 1)
	{
		std::cout << "+";
	}
}