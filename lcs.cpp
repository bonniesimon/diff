#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void print_table(std::vector<std::vector<int>> table, std::string string1, std::string string2);

std::string lcs_string(std::vector<std::vector<int>> lcs_table, std::string string1, std::string string2, int i, int j) {
  if (i == 0 || j == 0) {
    return "";
  }

  if (string1[i-1] == string2[j-1]) {
    return lcs_string(lcs_table, string1, string2, i-1, j-1) + string1[i-1];
  }

  if (lcs_table[i][j-1] > lcs_table[i-1][j-1]) {
    return lcs_string(lcs_table, string1, string2, i, j-1);
  }

  return lcs_string(lcs_table, string1, string2, i-1, j);
}

std::vector<std::vector<int>> lcs (std::string& string1, std::string& string2, int len1, int len2) {
  std::vector<std::vector<int>> lcs_table(len1+1, std::vector<int>(len2+1, 0));

  for(std::size_t i=1; i<lcs_table.size(); i++) {
    for (std::size_t j=1; j<lcs_table[i].size(); j++) {
      if (string1[i-1] == string2[j-1]) {
        lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
      } else {
        lcs_table[i][j] = std::max(lcs_table[i-1][j], lcs_table[i][j-1]);
      }
    }
  }

  print_table(lcs_table, string1, string2);


  return lcs_table;
}

void print_table(std::vector<std::vector<int>> table, std::string string1, std::string string2) {
  int index_string1 = 0;

  std::cout << "    ";
  for(char c: string2) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  for(std::vector<int>& row: table) {
    if (std::addressof(row) == std::addressof(table.front())){
      std::cout << "  ";
    } else {
      std::cout << string1[index_string1++] << " ";
    }

    for (int& item: row) {
       std::cout << item << " ";
    }

    std::cout << std::endl;
  }
}
