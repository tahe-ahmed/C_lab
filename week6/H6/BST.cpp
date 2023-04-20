
#include <iostream>
#include <vector>

#include "BST.h"

int main() {

  int inputNum;
  int toSearchNum;

  Node *root;
  root = nullptr;
  BST *bst;

  std::cout << "Enter the numbers to be stored: ";
  std::cin >> inputNum;

  if (std::cin) {

    bst = new BST();

    // root = bst->getNodeRoot();
    bst->insertKey(inputNum);

    std::cin >> inputNum;
    while (std::cin) {
      bst->insertKey(inputNum);
      std::cin >> inputNum;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << std::endl;

    std::cout << "The numbers in sorted order: ";
    std::vector<int> nodeVector = bst->inOrder();
    for (int i = 0; i < nodeVector.size(); ++i) {
      std::cout << nodeVector.at(i) << " ";
    }

    bst->prettyPrint();
  } else {
    bst = new BST();
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "The numbers in sorted order: ";
    std::vector<int> nodeVector = bst->inOrder();
    for (int i = 0; i < nodeVector.size(); ++i) {
      std::cout << nodeVector.at(i) << " ";
    }
    std::cout << std::endl;

    // bst->prettyPrint();
  }

  // std::cin.clear();
  // std::cin.ignore(10000, '\n');
  // std::cout << std::endl;

  // std::cout << "The numbers in sorted order: ";
  // std::vector<int> nodeVector = bst->inOrder();
  // for (int i = 0; i < nodeVector.size(); ++i) {
  //   std::cout << nodeVector.at(i) << " ";
  // }
  // std::cout << std::endl;

  // bst->prettyPrint();

  // std::cout << "Which number do you want to look up? ";
  // std::cin >> toSearchNum;

  // std::cout << toSearchNum
  //           << " is in the tree: " << (bst->hasKey(toSearchNum) ? "yes" :
  //           "no")
  //           << std::endl;

  // std::cout << "The numbers in sorted order: ";
  // std::vector<int> nodeVector = bst->inOrder();
  // for (int i = 0; i < nodeVector.size(); ++i) {
  //   std::cout << nodeVector.at(i) << " ";
  // }
  // std::cout << std::endl;

  // int height = bst->getHeight();
  // std::cout << "Height of the tree: " << height << std::endl;

  delete bst;

  return 0;
}