#include <cstdlib>
#include <string>

using namespace std;

class Config {
  string home_path;
  public:
    Config();
    string get_home_path();
};
