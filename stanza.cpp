#include "stanza.hpp"

int Stanza::countVerses() { return verses.size(); }
void Stanza::putVerse(Verse v) { verses.push_back(v); }
vector<Verse> Stanza::listVerses() { return verses; }
