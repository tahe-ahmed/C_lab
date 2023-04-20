
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#include "BST.h"

int main() {

  int inputNum;
  Node *root;
  root = nullptr;
  BST *bst;

  std::cout << "Enter the numbers to be stored: ";
  std::cin >> inputNum;

  if (std::cin) {

    bst = new BST();

    bst->insertKey(inputNum);

    std::cin >> inputNum;
    while (std::cin) {
      bst->insertKey(inputNum);
      std::cin >> inputNum;
    }

  } else {
    bst = new BST();
  }

  std::cin.clear();
  std::cin.ignore(10000, '\n');

  std::cout << "The numbers in sorted order: ";
  std::vector<int> nodeVector = bst->inOrder();
  for (int i = 0; i < nodeVector.size(); ++i) {
    std::cout << nodeVector.at(i) << " ";
  }
  std::cout << std::endl;

  bst->prettyPrint();

  delete bst;

  return 0;
}