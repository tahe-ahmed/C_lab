#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "bigint.h"

class TestFailed {
public:
  TestFailed(int seq) { sequenceNumber = seq; }
  int sequenceNumber;
};
int testNumber = 0;
#define check(CALL)                                                            \
  {                                                                            \
    testNumber++;                                                              \
    if (!(CALL))                                                               \
      throw TestFailed(testNumber);                                            \
  }
#define checkException(CALL)                                                   \
  {                                                                            \
    testNumber++;                                                              \
    bool exceptionRaised = false;                                              \
    try {                                                                      \
      CALL;                                                                    \
    } catch (std::runtime_error & o) {                                         \
      exceptionRaised = true;                                                  \
    } catch (...) {                                                            \
    }                                                                          \
    if (!exceptionRaised)                                                      \
      throw TestFailed(testNumber);                                            \
  }
std::ostream &operator<<(std::ostream &os, BigInt &bi) {
  return os << bi.toString();
}
#define BIGNUM1                                                                \
  "99999999999999999999999999999999999999999999999999999999999999999999999999" \
  "999999"
#define BIGNUM2                                                                \
  "10000000000000000000000000000000000000000000000000000000000000000000000123" \
  "4567"                                                                       \
  "889"

int main() {
  try {
    std::vector<BigInt> numbers(4);
    numbers.at(1) = BigInt(1234567890);
    numbers.at(2) = BigInt(BIGNUM1);
    numbers.at(3) = numbers.at(1) + numbers.at(2);
    check(numbers.at(0).toString() == "0");
    check(numbers.at(3).toString() == BIGNUM2);
    checkException(numbers.at(2) = BigInt("b999999999x99999999999cc")); // test
                                                                        // 5
    numbers.at(2) = BigInt(BIGNUM1);
    numbers.at(3) = numbers.at(2) + numbers.at(1);
    check(numbers.at(3).toString() == BIGNUM2);

    check(numbers.at(2) < numbers.at(3));
    check(numbers.at(0) < numbers.at(1));
    check((numbers.at(2) < numbers.at(0)) == 0);
    numbers.at(0) = std::numeric_limits<int>::max();
    check(numbers.at(0).toString() ==
          std::to_string(std::numeric_limits<int>::max())); // test 10
    numbers.at(1) = numbers.at(0) + 1;
    check(numbers.at(0) < numbers.at(1));
    unsigned long long reallyLong =
        std::numeric_limits<unsigned long long>::max();
    numbers.at(2) = BigInt(std::to_string(reallyLong));
    numbers.at(3) = numbers.at(2) + 1;
    check(numbers.at(2) < numbers.at(3)); // test 12
    std::cout << "All tests passed!\n";
  } catch (TestFailed &tf) {
    std::cerr << "Test number " << tf.sequenceNumber << " failed.\n";
    return 1;
  } catch (...) {
    std::cerr << "an unexpected exception occured\n";
    std::cerr << "Tests passed so far: " << testNumber << std::endl;
    return 2;
  }
  return 0;
}