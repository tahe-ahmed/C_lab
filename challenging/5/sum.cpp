#include <iostream>
#include <string>
using namespace std;
string addBigNumbers(string number1, string number2) {

  string str = "";

  if (number1.size() < number2.size()) {
    string temp = number2;
    number2 = number1;
    number1 = temp;
  }

  int j = number2.size() - 1;
  int carry = 0;

  for (int i = number1.size() - 1; i >= 0; --i) {

    // cout << i << " " << j << endl;
    if (j >= 0) {
      int sum = (number1.at(i) - '0') + (number2.at(j) - '0') + carry;
      if (sum > 9) {
        carry = 1;
        sum = sum % 10;
      } else {
        carry = 0;
      }

      str += to_string(sum);
    }

    if (j < 0) {
      int sum = (number1.at(i) - '0') + carry;
      if (sum > 9) {
        carry = 1;
        sum = sum % 10;
      } else {
        carry = 0;
      }

      str += to_string(sum);
    }

    j = j - 1;
  }

  if (carry > 0) {
    str += to_string(carry);
  }

  string finalString = "";
  for (int i = (str.size() - 1); i >= 0; i--) {
    finalString += str.at(i);
  }
  cout << " final " << finalString << endl;

  return str;
}
int main() {
  string number1 = "99999999999999999999999999999999";
  string number2 = "1";
  addBigNumbers(number1, number2);
  //   cout << "Sum of two large numbers is " << addBigNumbers(number1,
  //   number2);
  return 0;
}