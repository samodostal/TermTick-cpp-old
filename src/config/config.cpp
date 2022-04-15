#include <iostream>
#include <vector>

#include "config.hpp"

using namespace std;

Config::Config() {
  this->home_path = getenv("HOME");
  cout << this->home_path << endl;
}

string Config::get_home_path() { return this->home_path; };
