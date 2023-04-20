#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define BIGNUM1                                                                \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999"
#define BIGNUM2                                                                \
  "10000000000000000000000000000000000000000000000000000000000000000000000123" \
  "4567"                                                                       \
  "889"

#define checkException(CALL)                                                   \
  {                                                                            \
                                                                               \
    bool exceptionRaised = false;                                              \
    try {                                                                      \
      CALL;                                                                    \
    } catch (std::runtime_error & o) {                                         \
      exceptionRaised = true;                                                  \
    } catch (...) {                                                            \
    }                                                                          \
    if (!exceptionRaised)                                                      \
      std::cout << " go";                                                      \
  }
class BigInt {
public:
  BigInt(); // default value is 0
  BigInt(unsigned int value);
  BigInt(std::string digitString); // throws std::runtime_error

  BigInt operator+(const BigInt &rightValue);
  // example use:
  // BigInt a,b,c;
  // c = a + b;
  bool operator<(const BigInt &rightValue);
  // example use:
  // BigInt a,b;
  // bool x = a < b;
  std::string toString() const;
  // example use:
  // BigInt a(123);
  // a.toString() yields "123"
private:
  // data structure(s) for storing numbers with arbitrary many digits
  // private helper functions if/as needed
  std::vector<int> numbers;
  std::string numString;
  int number;
};

BigInt::BigInt() { numString = "0"; }

BigInt::BigInt(unsigned int value) {
  number = value;
  numString = std::to_string(value);
}

BigInt::BigInt(std::string digitString) {
  for (unsigned int i = 0; i < digitString.size(); ++i) {
    if (!isdigit(digitString.at(i))) {
      throw std::runtime_error("String is not supported");
    }
  }
  numString = digitString;
}

BigInt BigInt::operator+(const BigInt &rightValue) {

  std::string number1 = numString;
  std::string number2 = rightValue.numString;

  std::string str = "";

  if (number1.size() < number2.size()) {
    std::string temp = number2;
    number2 = number1;
    number1 = temp;
  }

  int j = number2.size() - 1;
  int carry = 0;

  for (int i = number1.size() - 1; i >= 0; --i) {

    // std::cout << i << " " << j << std::endl;
    if (j >= 0) {
      int sum = (number1.at(i) - '0') + (number2.at(j) - '0') + carry;
      if (sum > 9) {
        carry = 1;
        sum = sum % 10;
      } else {
        carry = 0;
      }

      str += std::to_string(sum);
    }

    if (j < 0) {

      int sum = (number1.at(i) - '0') + carry;
      if (sum > 9) {
        carry = 1;
        sum = sum % 10;
      } else {
        carry = 0;
      }
      str += std::to_string(sum);
    }

    j = j - 1;
  }
  if (carry > 0) {
    str += std::to_string(carry);
  }

  std::string finalString = "";
  for (int i = (str.size() - 1); i >= 0; i--) {
    finalString += str.at(i);
  }
  //   std::cout << " final " << finalString << std::endl;

  return finalString;
}

bool BigInt::operator<(const BigInt &rightValue) {
  std::string number1 = numString;
  std::string number2 = rightValue.numString;

  if (number1.size() < number2.size()) {
    return true;
  }
  if (number1.size() > number2.size()) {
    return false;
  }
  if (number1.size() > 0 && number2.size() > 0) {
    for (int i = 0; i < number1.length(); ++i) {
      if ((number1.at(i) - '0') < (number2.at(i) - '0')) {
        return true;
      }
    }
  }

  return false;
}

std::string BigInt::toString() const {
  if (!number)
    return numString;
  return numString;
}

int main() {
  BigInt num();
  // try {
  //   std::vector<BigInt> numbers(4);
  //   numbers.at(1) = BigInt(1234567890);
  //   numbers.at(2) = BigInt(BIGNUM1);
  //   numbers.at(3) = numbers.at(1) + numbers.at(2);

  //   // numbers.at(0) = std::numeric_limits<int>::max();
  //   // std::cout << ((numbers.at(0).toString() ==
  //   //                std::to_string(std::numeric_limits<int>::max())))
  //   //           << std::endl;

  //   numbers.at(2) = BigInt(BIGNUM1);
  //   numbers.at(3) = numbers.at(2) + numbers.at(1);

  //   // std::cout << (numbers.at(0) < numbers.at(1)) << std::endl;
  //   std::cout << ((numbers.at(2) < numbers.at(0)) == 0) << std::endl;
  //   // checkException(numbers.at(2) = BigInt("b999999999x99999999999cc"));
  //   // std::cout << (numbers.at(0).toString() == "0") << std::endl;
  //   // std::cout << (numbers.at(2) = BigInt("b999999999x99999999999cc"))
  //   //           << std::endl;
  //   // std::cout << (numbers.at(2).toString() == BIGNUM1) << std::endl;

  //   // numbers.at(2) = BigInt(BIGNUM1);
  //   // numbers.at(3) = numbers.at(2) + numbers.at(1);
  //   // std::cout << (numbers.at(3).toString() == BIGNUM2) << std::endl;

  //   // std::cout << (numbers.at(2) < numbers.at(3)) << std::endl;
  //   // std::cout << (numbers.at(0) < numbers.at(1)) << std::endl;
  //   // std::cout << ((numbers.at(2) < numbers.at(0)) == 0) << std::endl;

  // } catch (const std::runtime_error &e) {
  //   std::cout << e.what() << std::endl;
  // }

  //   std::cout << () << std::endl;
  //   std::cout << (numbers.at(2).toString()) << std::endl;
}