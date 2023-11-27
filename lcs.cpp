#include <iostream>
#include <string>
#include <algorithm>


int lcs (std::string& string1, std::string& string2, int len1, int len2) {
  if (len1 == 0 && len2 == 0) {
    return 0;
  }

  int lcs_table[len1+1][len2+1];

  string1.insert(0, "*");
  string2.insert(0, "*");

  for(int i=0; i<len1+1; i++) {
    for (int j=0; j<len2+1; j++) {
      lcs_table[i][j] = 0;
    }
  }

  for(int i=1; i<len1+1; i++) {
    for (int j=1; j<len2+1; j++) {
      if (string1[i] == string2[j]) {
        lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
      } else {
        lcs_table[i][j] = std::max(lcs_table[i-1][j], lcs_table[i][j-1]);
      }
    }
  }


  return lcs_table[len1][len2];
}


// Print the array
/*
  for(int i=0; i<len1+1; i++) {
    for (int j=0; j<len2+1; j++) {
      std::cout << lcs_table[i][j] << " ";
    }
    std::cout << "\n";
  }
*/
