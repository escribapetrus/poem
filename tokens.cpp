#include "tokens.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

vector<Token> tokenize(string) {
  vector<Token> tokens;
  return tokens;
}

vector<Token> tokenize(ifstream &file) {
  int line = 0;
  char c;
  string buf = "";
  Token token = Token();
  token.type = IDENTIFIER;
  vector<Token> tokens;

  while (file.get(c))
    match(c, buf, line, token, tokens);

  return tokens;
}

void match(char c, string &buf, int &line, Token &token, vector<Token> &tokens) {
  if (c == ' ') {
    token.value = buf;
    tokens.push_back(token);
    token = Token();
    buf.clear();
    return;
  }
  if (c == '\n' || c == '\r') {
    token.value = buf;
    tokens.push_back(token);
    token = Token();
    Token newlineToken;
    newlineToken.type = KEYWORD;
    newlineToken.value = "newline";
    newlineToken.line = line;
    tokens.push_back(newlineToken);
    line++;
    buf.clear();
    return;
  }
  if (symbols.find(c) != symbols.end()) {
    token.value = buf;
    tokens.push_back(token);
    token = Token();
    Token symbolToken;
    string value = "";
    value.push_back(c);
    symbolToken.type = SYMBOL;
    symbolToken.value = value;
    symbolToken.line = line;
    tokens.push_back(symbolToken);
    return;
  }

  buf.push_back(c);

  if (!isalnum(c))
    token.type = INVALID;

  if (keywords.find(buf) != keywords.end())
    token.type = KEYWORD;
}

void printTokens(vector<Token> tokens) {
  for (auto token : tokens) {
    string type = "other";
    if (token.type == SYMBOL)
      type = "symbol";
    if (token.type == IDENTIFIER)
      type = "identifier";
    if (token.type == KEYWORD)
      type = "keyword";
    if (token.type == INVALID)
      type = "invalid";
    if (token.type == UNDEFINED)
      type = "undefined";
    cout << "{" << type << ", " << token.value << ", " << token.line << "}\n";
  }
}
