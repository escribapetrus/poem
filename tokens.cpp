#include "tokens.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

Token::Token(TokenType type, string value, int line, int col)
    : type(type), value(value), line(line), col(col) {}

vector<Token> tokenize(string str) {
  int line = 0;
  char c;
  string buf = "";
  vector<Token> tokens;
  TokenType type = IDENTIFIER;
  for (char c : str)
    match(c, buf, line, type, tokens);

  return tokens;
}

vector<Token> tokenize(ifstream &file) {
  int line = 0;
  char c;
  string buf = "";
  vector<Token> tokens;
  TokenType type = IDENTIFIER;

  while (file.get(c))
    match(c, buf, line, type, tokens);

  return tokens;
}

void match(char c, string &buf, int &line, TokenType &type,
           vector<Token> &tokens) {
  if (c == ' ') {
    if (!buf.empty())
      tokens.emplace_back(type, buf, line, 0);
    buf.clear();
    return;
  }
  if (c == '\n' || c == '\r') {
    if (!buf.empty())
      tokens.emplace_back(type, buf, line, 0);
    tokens.emplace_back(KEYWORD, "newline", line, 0);
    line++;
    buf.clear();
    return;
  }
  if (symbols.find(c) != symbols.end()) {
    tokens.emplace_back(type, buf, line, 0);
    string value = "";
    value.push_back(c);
    tokens.emplace_back(SYMBOL, value, line, 0);
    buf.clear();
    return;
  }

  buf.push_back(c);

  if (keywords.find(buf) != keywords.end())
    type = KEYWORD;
  else
    type = IDENTIFIER;
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
