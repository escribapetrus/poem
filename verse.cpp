#include "verse.hpp"

int Verse::countWords() { return words.size(); }
void Verse::putWord(string w) { words.push_back(w); }
