#include <iostream>
#include <string>
#include <vector>

#include "lcs.h"

struct TestCase {
  std::string string1;
  std::string string2;
  std::string lcs;
};

void runAll(std::vector<TestCase> test_cases);
void runOne(TestCase test_case);

int main () {
  std::vector<TestCase> test_cases {
    {"", "", ""},
    {"ABCDEF", "ABCDEF", "ABCDEF"},
    {"ABC", "XYZ", ""},
    {"AABCXY", "XYZ", "XY"},
    {"GAC", "AGCAT", "GA"}
  };


  runAll(test_cases);
}

void runAll(std::vector<TestCase> test_cases) {
  for (TestCase test_case : test_cases) {
    if (test_case.string1.length() == 0 && test_case.string2.length() == 0) {
      std::cout << "Empty strings" << "\n==============\n\n\n" << std::endl;
      continue;
    }

    std::vector<std::vector<int>> lcs_table = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

    std::string result = lcs_string(lcs_table, test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

    result == test_case.lcs ? std::cout << "PASS" << " -> LSC = " << result : std::cout << "FAIL";

    std::cout << "\n==============\n\n\n" << std::endl;

  }
}

void runOne(TestCase test_case) {
  if (test_case.string1.length() == 0 && test_case.string2.length() == 0) {
     std::cout << "Empty strings" << std::endl;
  }

  std::vector<std::vector<int>> lcs_table = lcs(test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

  std::string result = lcs_string(lcs_table, test_case.string1, test_case.string2, test_case.string1.length(), test_case.string2.length());

  std::cout << "LCS = " << result << "\n";
}
