#pragma once
#include <fstream>
#include <iostream>
#include <vector>

class Text{ 
 public:
  Text(const char*);
  std::pair<int, int> operator[] (const int) const;
  const char* get() const;
  bool rhythm(std::pair<int, int>, std::pair<int, int>);
  bool ignore(char);
  void print(int);
  int get_rhythm(int);
 private:
  std::vector<std::pair<int, int>> lines;
  char* txt_;
};
