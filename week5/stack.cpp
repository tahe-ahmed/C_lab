#include <iostream>
#include <limits>
#include <vector>

class Stack {
public:
  Stack();
  bool isEmpty() const;
  int top() const;
  int pop();
  void push(int i);
  std::string toString() const;

private:
  std::vector<int> elements;
};
//
// your implementation of Stack goes here

Stack::Stack() {}
bool Stack::isEmpty() const { return (elements.size() == 0); }

int Stack::top() const {
  if (isEmpty()) {
    throw std::runtime_error("stack is empty");
  }
  int firstElement = elements.at(0);

  return firstElement;
}

int Stack::pop() {

  if (isEmpty()) {
    throw std::runtime_error("stack is empty");
  }

  int firstElement = elements.at(0);
  std::vector<int> newElements;
  for (unsigned int i = 1; i < elements.size(); ++i) {
    newElements.push_back(elements.at(i));
  }
  elements = newElements;

  return firstElement;
}

void Stack::push(int i) {
  // elements.insert(elements.begin(), i);
  std::vector<int> newElements;
  newElements.push_back(i);
  for (unsigned int i = 0; i < elements.size(); ++i) {
    newElements.push_back(elements.at(i));
  }

  elements = newElements;
}

std::string Stack::toString() const {
  // if (isEmpty()) {
  //   return "[]";
  // }
  std::string stackString = "[";

  stackString = stackString + std::to_string(elements.at(0));
  for (unsigned int i = 1; i < elements.size(); ++i) {
    stackString = stackString + "," + std::to_string(elements.at(i));
  }
  stackString = stackString + "]";

  return stackString;
}
//
//
int main() {
  Stack stack;

  while (true) {
    try {
      std::cout << "stack> ";

      std::string command;
      std::cin >> command;

      if ((command.compare("end") == 0) || std::cin.eof()) {
        break;
      } else if (command.compare("top") == 0) {
        std::cout << stack.top() << std::endl;
      } else if (command.compare("pop") == 0) {
        std::cout << stack.pop() << std::endl;
      } else if (command == "push") {
        if (std::cin.eof())
          break;
        int i;
        std::cin >> i;
        bool failed = std::cin.fail();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (failed) {
          throw std::runtime_error("not a number");
        }
        stack.push(i);
      } else if (command.compare("list") == 0) {
        std::cout << stack.toString() << std::endl;
        ;
      } else {
        throw std::runtime_error("invalid command");
      }
    } catch (std::runtime_error &e) {
      std::cout << "error: " << e.what() << std::endl;
    }
  }

  return 0;
}