#include<iostream>
using namespace std;

class Node {

public:
    Node* children[26];

    bool end_of_word; // ������� ����� �����    
    char letter; //������ ������� ����

    Node(){
        end_of_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        letter = '\0';
    }

    ~Node() = default;
};


