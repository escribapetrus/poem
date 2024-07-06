#include <string>
#include <unordered_map>
#include <vector>

#include "stanza.hpp"
using std::string;
using std::vector;
using std::unordered_map;

class Poem {
private:
  unordered_map<string, string> metadata;
  vector<Stanza> stanzas;

public:
  int countStanzas();
  string generateReport();
  void printReport();
};
