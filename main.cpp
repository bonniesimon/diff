#include <iostream>
#include <string>
#include <vector>

#include "lcs.h"

struct TestCase {
  std::string string1;
  std::string string2;
  std::string lcs;
};

int main () {
  TestCase test_cases[] = {
    {"", "", ""},
    {"ABCDEF", "ABCDEF", "ABCDEF"},
    {"ABC", "XYZ", ""},
    {"AABCXY", "XYZ", "XY"}
  };


  for (TestCase test_case : test_cases) {
    std::string lcs_result = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

    lcs_result == test_case.lcs ? std::cout << "PASS" : std::cout << "FAIL";

    std::cout << "\n";
  }

}
