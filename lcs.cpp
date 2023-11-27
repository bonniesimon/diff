#include <iostream>
#include "string"

std::string lcs (std::string& string1, std::string& string2, int len1, int len2) {
  if (len1 == 0 && len2 == 0) {
    return "";
  }

  int lcs_table[len1+1][len2+1];

  string1.insert(0, "*");
  string2.insert(0, "*");

  for(int i=0; i<len1; i++) {
    lcs_table[i][0] = 0;
  }
  for(int j=0; j<len2; j++) {
    lcs_table[0][j] = 0;
  }

  for(int i=1; i<len1; i++) {
    for (int j=1; j<len2; j++) {

    }
  }

  return "";
}
