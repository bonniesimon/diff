#include <iostream>
#include <string>
#include <vector>

#include "lcs.h"

struct TestCase {
  std::string string1;
  std::string string2;
  int lcs;
};

int main () {
  TestCase test_cases[] = {
    // {"", "", ""},
    // {"ABCDEF", "ABCDEF", "ABCDEF"},
    // {"ABC", "XYZ", ""},
    // {"AABCXY", "XYZ", "XY"}
    {"", "", 0},
    {"ABCDEF", "ABCDEF", 6},
    {"ABC", "XYZ", 0},
    {"AABCXY", "XYZ", 2},
    {"GAC", "AGCAT", 2}
  };


  for (TestCase test_case : test_cases) {
    int lcs_result = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

    lcs_result == test_case.lcs ? std::cout << "PASS" : std::cout << "FAIL";

    std::cout << "\n";
  }

  // TestCase test_case = test_cases[1];

  // int result = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

  // std::cout << result << "\n";

}
