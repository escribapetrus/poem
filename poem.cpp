#include "poem.hpp"
#include <iostream>
#include <sstream>

int Poem::countStanzas() { return stanzas.size(); }

string Poem::generateReport() {
  int wordCount;
  int verseCount;
  int stanzaCount = countStanzas();
  for (auto stanza : stanzas) {
    verseCount = stanza.countVerses();
    for (auto verse : stanza.listVerses()) {
      wordCount += verse.countWords();
    }
  }

  std::ostringstream report;
  report << "POEM DATA:\n"
         << "stanzas: " << stanzaCount << "\n"
         << "verses: " << verseCount << "\n"
         << "words: " << wordCount << "\n";

  return report.str();
}

void Poem::printReport() { std::cout << generateReport(); }
