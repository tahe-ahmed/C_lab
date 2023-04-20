void drawCell() { drawHorzWalls(); }
void drawHorzWalls() {
  for (int i = 0; i < row + 1; ++i) {
    for (int j = 0; j < col; ++j) {
      // std::cout << i << " " << j << std::endl;
      if (walls.at(0)) { // top
        std::cout << corner << horzWall;
      }

      // std::cout << vertWall << content << vertWall << std::endl;
    }
    std::cout << corner;
    std::cout << std::endl;
    if ((i < row)) {
      drawVertWalls();
    }
  }
  // std::cout << corner << horzWall;
}

void drawVertWalls() {
  for (int j = 0; j < col; ++j) {
    if (walls.at(3) || walls.at(1)) { /// left
      std::cout << vertWall;
    } else {
      std::cout << " ";
    }
    std::cout << content;
    //   if (walls.at(1)) { /// right
    //     std::cout << vertWall;
    //   } else {
    //     std::cout << " ";
    //   }
  }
  std::cout << vertWall;
  std::cout << std::endl;
  // for (int j = 0; j < col; ++j) {

  //   if (walls.at(2)) { // bottom
  //     std::cout << corner << horzWall << corner;
  //   }
  // }
  // std::cout << std::endl;
}

for (int i = 0; i < row; ++i) {
  for (int j = 0; j < col; ++j) {
    cells.at(j + (i * col)).drawHorzWallsTop();
  }
  std::cout << std::endl;
  for (int j = 0; j < col; ++j) {
    cells.at(j + (i * col)).drawVertWallsLeft();
    cells.at(j + (i * col)).drawVertWallsRight();
  }

  std::cout << std::endl;
  for (int j = 0; j < col; ++j) {
    cells.at(j + (i * col)).drawHorzWallsBottom();
  }
  std::cout << std::endl;
}

/// first row
for (int j = 0; j < col; ++j) {
  cells.at(j).drawHorzWallsTop();
}
std::cout << std::endl;
for (int j = 0; j < col; ++j) {
  cells.at(j).drawVertWallsLeft();
  //   cells.at(j).drawVertWallsRight();
}

std::cout << std::endl;
for (int j = 0; j < col; ++j) {
  cells.at(j).drawHorzWallsBottom();
}
std::cout << std::endl;

// the rest rows

for (int i = 1; i < row; ++i) {
  //   for (int j = 0; j < col; ++j) {
  //     cells.at(j + (i * col)).drawHorzWallsTop();
  //   }
  //   std::cout << std::endl;
  for (int j = 0; j < col; ++j) {
    cells.at(j + (i * col)).drawVertWallsLeft();
    // cells.at(j + (i * col)).drawVertWallsRight();
  }

  std::cout << std::endl;
  for (int j = 0; j < col; ++j) {
    cells.at(j + (i * col)).drawHorzWallsBottom();
  }
  std::cout << std::endl;
}

bool findPath(Cell &from, Cell &to) {

  from.exploreCell();
  if ((from.getX() == to.getX()) && (from.getY() == to.getY())) {
    return true;
  }

  checkNextMove(from.getX(), from.getY());
  // for (int i = 0; i < possibleMoves.size(); ++i) {
  //   std::cout << "Possible MOves: X " << possibleMoves.at(i).getX()
  //             << " Y: " << possibleMoves.at(i).getY() << std::endl;
  // }
  for (int i = 0; i < possibleMoves.size(); ++i) {
    std::cout << "Possible MOves: X " << possibleMoves.at(i).getX()
              << " Y: " << possibleMoves.at(i).getY() << std::endl;

    //// HIT FOR DEBUG ===> POSSIBLE MOVES MAYBE NOT GIVING ALL POSSIBLITIES
    int indexCell =
        index(possibleMoves.at(i).getX(), possibleMoves.at(i).getY());
    //   Cell possibleCell = cells.at(indexCell);
    //   std::cout << "is explored : " << cells.at(indexCell).getIsExplored()
    //             << std::endl;

    if (cells.at(indexCell).getIsExplored() == 0) {
      std::cout << "Next Move : indexCell " << indexCell
                << " X: " << cells.at(indexCell).getX() << " Y "
                << cells.at(indexCell).getY() << std::endl;
      if (findPath(cells.at(indexCell), to)) {
        //   cells.at(indexCell).exploreCell();
        return true;
      }
    }
  }

  // std::cout << " to un explore : X " << from.getX() << " Y; " <<
  // from.getY()
  //           << std::endl;
  // from.unExplore();
  return false;
}

// std::cout << Max << std::endl;
// std::random_device rd;
// std::mt19937 eng(rd());
// std::uniform_int_distribution<int> distr(0, Max - 1);
// return distr(eng);