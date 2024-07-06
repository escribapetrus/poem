#include "verse.hpp"
#include <vector>

using std::vector;
class Stanza {
private:
  vector<Verse> verses;

public:
  int countVerses();
  void putVerse(Verse v);
  vector<Verse> listVerses();
};
