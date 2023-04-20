#include <iostream>
#include <string>
#include <vector>

const std::vector<int> verticalMove{2, 1, -1, -2, -2, -1, 1, 2};
const std::vector<int> horizontalMove{1, 2, 2, 1, -1, -2, -2, -1};

void print2D(std::vector<std::vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board.at(i).size(); j++) {
      std::cout << board.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}

void squNamToIndex(std::string squNam, std::vector<int> &indexes) {

  char letter = squNam.at(0);
  int num = 0;
  for (unsigned int i = 1; i < squNam.size(); ++i) {
    num = (num * 10) + int(squNam.at(i) - '0');
  }

  indexes.at(0) = ((letter)-97);
  indexes.at(1) = (num - 1);
}

void indexToSquNam(std::vector<int> &indexes) {

  char letter = (indexes.at(0) + 97);
  std::string squName = std::to_string(indexes.at(1) + 1) + letter;

  std::cout << squName << std::endl;
}

int main() {
  std::vector<std::vector<int>> board(4, std::vector<int>(4, 0));
  std::vector<int> indexes(2);

  board.at(0).at(0) = 1;

  std::string startSquare = "00";
  std::string endSquare = "22";

  squNamToIndex("z25", indexes);
  //   std::cout << indexes.at(0) << indexes.at(1);

  indexToSquNam(indexes);
  //   print2D(board);
}
