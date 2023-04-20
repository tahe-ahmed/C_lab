
#include <fstream>
#include <iostream>
#include <stack>

void fillStack(std::stack<int> &stack, int topElement) {
  // push the top item back in the sorted stack
  // sortedInsert(stack, topElement);
  if ((stack.size() == 0) || (topElement < stack.top())) {
    stack.push(topElement);

  } else {

    int temp = stack.top();
    stack.pop();

    fillStack(stack, topElement);
    stack.push(temp);
  }
}
void sortStack(std::stack<int> &stack) {
  if (stack.size() < 2) {
    return;
  }

  int topElement = stack.top();
  // std::cout << topElement << std::endl;
  stack.pop();

  // sort the remaining
  sortStack(stack);

  fillStack(stack, topElement);
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
      while (fileStream >> singleInput) {

        // std::cout << singleInput << std::endl;
        stack.push(singleInput);
        // fileStream >> singleInput;
      }

      // Use a while loop together with the getline() function to read the file
      // line by line
      // while (getline(fileStream, singleInput)) {
      //   // Output the text from the file
      //   std::cout << singleInput << std::endl;
      // }

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