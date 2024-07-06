#include <fstream>
#include <iostream>
#include <stdio.h>

#include "poem.hpp"
#include "tokens.hpp"

using std::ifstream;

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    std::ifstream f(argv[i]);
    if (f.is_open()) {
      vector<Token> tokens = tokenize(f);
      printTokens(tokens);
    }
    f.close();
  }

  return 0;
}
