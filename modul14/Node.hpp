#include<iostream>
using namespace std;

class Node {

public:
    Node* children[26];

    bool end_of_word; // Признак конца слова    
    char letter; //Символ текущей ноды

    Node(){
        end_of_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        letter = '\0';
    }

    ~Node() = default;
};


