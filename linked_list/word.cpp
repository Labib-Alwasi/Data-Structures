#include "word.hpp"
#include <iostream>
#include <string>

word::word(){
  
}

word::~word(){

}

word::word(std::string w){
  count = 1;
  wrd = w;
}

void word::inc_count(){
  count = count + 1;
}

void word::print_data(){
  std::cout << "\"" << wrd << "\""  << " " << count << std::endl;
}

std::string word::get_string(){
  return wrd;
}
