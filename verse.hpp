#include <string>
#include <vector>

using std::string;
using std::vector;

class Verse {
private:
  vector<string> words;

public:
  int countWords();
  void putWord(string w);
};
