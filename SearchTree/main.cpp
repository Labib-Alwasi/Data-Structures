#include <iostream>
#include <string>
#include <fstream>
#include "node.hpp"

using namespace std;

// forward declarations
void print_tree(node *tree);
bool process_word(string new_word, node*& tree);
void search(string checkWord, node*& tree);

int main() {
    try {
        node* root = nullptr; // start with an empty tree
        int wordcount = 0; // optional
        int individual_word_count = 0; // optional
        ifstream inFile; // declare a file variable that will read                   // the file
        string book_file;

        string word;
        cout << "Please enter the name of the book file:" << endl;
        cin >> book_file;

     while (!inFile.is_open()) {
            inFile.open(book_file);

            if (!inFile.is_open()) {
                cout << "An error occurred attempting to open the file \"" << book_file << "\"." << endl;
                cout << "Please enter the name of the book file:" << endl;
                cin >> book_file;
                

            } else {
                while (inFile >> word) {
                    wordcount++;
                    if (process_word(word, root)) {
                        individual_word_count++;
                    }
                }
                inFile.close();

                cout << "The file \"" << book_file << "\" contains " << wordcount << " words of which "
                     << individual_word_count << " are distinct." << endl;

                while (cin.eof() == false) {
                    cout << "Please enter the word you wish to check:" << endl;
                    string checkWord;
                    cin >> checkWord;
                    if (!cin.fail()) {
                        search(checkWord, root);
                    }
                }
                break;
            }
        }
        cout << "Goodbye" << endl;
    }
    catch(...) {
        cout << "An error occurred trying to read the file.";
    }

    return 0; // tell the OS everything is peachy
}

// returns true if the word is new, false otherwise
bool process_word(string new_word, node*& tree) {
    bool response;
    if (tree == nullptr) {
        tree = new node();
        tree->assign(new_word);
        response = true; // it is a new word
    } else {
        if (new_word == *tree) {
            tree->count++;
            response = false; // it is not a new word
        } else {
            if (new_word < *tree) {
                response = process_word(new_word, tree->before);
            } else {
                response = process_word(new_word, tree->after);
            }
        }
    }
    return response;
}

void print_tree(node *tree) {
    if (tree != nullptr) {
        print_tree(tree->before);
        cout << "\"" << *tree <<"\" " << tree->count << endl;
        print_tree(tree->after);
    }
}

void search(string checkWord, node*& tree){
    if(tree == nullptr){
        cout<<"The word \"" << checkWord << "\" was not found."<< endl;
        return;
    }
    if(*tree == checkWord){
        int t_count;
        t_count =tree->count;

        if(t_count == 1){
            cout<<"The word \""<< checkWord <<"\" was found once."<< endl;
        }
        else if(t_count == 2){
            cout<<"The word \""<< checkWord<<"\" was found twice."<< endl;
        }
        else{
            cout <<"The word \""<< checkWord <<"\" was found "<< t_count <<" times."<< endl;
        }
        return;
    }
    if(checkWord < *tree){
        search(checkWord, tree->before);
    }
    else{
        search(checkWord, tree->after);
    }
}
