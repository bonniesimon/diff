#include <iostream>
#include <string>
#include <vector>

#include "lcs.h"

struct TestCase {
  std::string string1;
  std::string string2;
  int lcs;
};

void runAll(std::vector<TestCase> test_cases);
void runOne(TestCase test_case);

int main () {
  std::vector<TestCase> test_cases {
    {"", "", 0},
    {"ABCDEF", "ABCDEF", 6},
    {"ABC", "XYZ", 0},
    {"AABCXY", "XYZ", 2},
    {"GAC", "AGCAT", 2}
  };


  runAll(test_cases);
}

void runAll(std::vector<TestCase> test_cases) {
    for (TestCase test_case : test_cases) {
    int lcs_result = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

    lcs_result == test_case.lcs ? std::cout << "PASS" : std::cout << "FAIL";

    std::cout << "\n";
  }
}

void runOne(TestCase test_case) {
  int result = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

  std::cout << "LCS = " << result << "\n";
}
