#pragma once
#include <string>

class word: public std::string {
  private:
  int count;
  std::string wrd;
  public:
  word *next;
  word();
  ~word();
  word(std::string w);
  void inc_count();
  void print_data();
  std::string get_string();
};
