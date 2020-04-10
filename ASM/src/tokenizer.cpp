#include "../include/tokenizer.h"

#include <iostream>
#include <sstream>

using namespace std;

vector<string> Tokenizer::tokenize(const string &text) const {
  vector<string> tokens{};
  istringstream input(text);

  for (string token; getline(input, token, delimiter_); /* pass */) {
    tokens.push_back(token);
  }

  return tokens;
}
