#include <fstream>
#include <string>
#include <unordered_set>

using std::unordered_set;
using std::string;
using std::vector;
using std::ifstream;

enum TokenType {
    UNDEFINED,
    KEYWORD,
    IDENTIFIER,
    SYMBOL,
    INVALID,
};

struct Token {
    TokenType type = IDENTIFIER;
    string value;
    int line;
    int col;

    Token(TokenType type, string value, int line, int col);
};

const unordered_set<string> keywords {
  "###" 
};

const unordered_set<char> symbols {
    '.', ',', '-', ';', ':', '!', '?'
}; 

vector<Token> tokenize(string);

vector<Token> tokenize(ifstream&);

void match(char c, string &buf, int &line, TokenType &type, vector<Token> &tokens);

void printTokens(vector<Token> tokens);
