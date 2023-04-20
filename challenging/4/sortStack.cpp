
#include <fstream>
#include <iostream>
#include <stack>

// Recursive function to insert an item x in sorted way
void sortedInsert(std::stack<int> &s, int element) {
  // Base case: Either stack is empty or newly inserted
  // item is greater than top (more than all existing)
  if ((s.size() == 0) || (element < s.top())) {
    s.push(element);
  } else {

    // Remove the top item and recur
    int temp = s.top();
    s.pop();
    sortedInsert(s, element);

    // Put back the top item removed earlier
    s.push(temp);
  }
}

void sortStack(std::stack<int> &stack) {
  if (stack.size() < 2) {
    return;
  }

  // remove the top element
  int topElement = stack.top();
  stack.pop();

  // sort the remaining
  sortStack(stack);

  // push the top item back in the sorted stack
  sortedInsert(stack, topElement);

  // if (topElement < stack.top()) {
  //   stack.push(topElement);
  //   //   isDone = true;
  //   break;
  // } else {
  //   int temp = topElement;
  //   topElement = stack.top();
  //   stack.pop();
  //   stack.push(temp);
  // }
  //   }
}

int main(int argc, char *argv[]) {
  std::stack<int> stack;
  std::ifstream fileStream;

  if (argc == 2) {
    fileStream.open(argv[1]);

    if (!fileStream.is_open()) {
      std::cout << "an error occurred: could not open input file " << argv[1]
                << std::endl;
    } else {

      int singleInput;
      while (!fileStream.eof()) {
        stack.push(singleInput);
        fileStream >> singleInput;
      }

      sortStack(stack);
      if (stack.size() == 0)
        return 0;
      while (stack.size() != 0) {
        std::cout << stack.top() << " ";
        stack.pop();
      }
    }

  } else {
    std::cout << "an error occurred: no input file name given " << std::endl;
    return 1;
  }

  return 0;
}