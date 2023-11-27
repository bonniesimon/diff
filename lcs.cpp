#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void print_table(std::vector<std::vector<int>> table, std::string string1, std::string string2);

int lcs (std::string& string1, std::string& string2, int len1, int len2) {
  if (len1 == 0 && len2 == 0) {
    return 0;
  }

  std::vector<std::vector<int>> lcs_table(len1+1, std::vector<int>(len2+1, 0));

  string1.insert(0, "*");
  string2.insert(0, "*");


  for(std::size_t i=1; i<lcs_table.size(); i++) {
    for (std::size_t j=1; j<lcs_table[i].size(); j++) {
      if (string1[i] == string2[j]) {
        lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
      } else {
        lcs_table[i][j] = std::max(lcs_table[i-1][j], lcs_table[i][j-1]);
      }
    }
  }

  print_table(lcs_table, string1, string2);


  return lcs_table[len1][len2];
}

void print_table(std::vector<std::vector<int>> table, std::string string1, std::string string2) {
  int index_string1 = 0;

  std::cout << "  ";
  for(char c: string2) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  for(std::vector<int>& row: table) {
    std::cout << string1[index_string1++] << " ";
    for (int& item: row) {
       std::cout << item << " ";
    }
    std::cout << std::endl;
  }
}
