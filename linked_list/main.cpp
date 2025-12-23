#include <iostream>
#include "word.hpp"
#include <string>

using namespace std;

int main(){
  word* n;
  word* temp1;
  word* temp2;
  word* head;
  string t_word;

  cin >> t_word;
  n = new word(t_word);
  temp1 = n;
  head = n;
  while(cin.eof() == false){
    cin >> t_word;
    n = new word(t_word);
    temp1->next=n;
    temp1 = n;
  }

  temp1 = head;
  n = temp1->next;
  temp2 = head; //keep some pointer pointing to the head
  while(head->next != nullptr){
    temp1 = head;
    n = temp1->next;
    while(temp1->next!= nullptr){
     if(n->get_string() == head->get_string()){
      head->inc_count();
      delete n;
      n = n->next;
      temp1->next = n;
    }
    else{
      n = n->next;
      temp1 = temp1->next;
    }
   }
   head = head->next;
  }
  
  temp1 = temp2;
  temp1->print_data();
  while(temp1->next != nullptr){
    temp1 = temp1->next;
    temp1->print_data();
  }

  return 0;
}

  
