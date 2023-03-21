#include "Tree.h"

void Tree::clear_buf_word() {
    for (size_t i = 0; i < max_number_word; ++i) {
        buf_word[i] = "";
    }
    counter_word = 0;
}


const std::string& Tree::get_word(int number) {
    return buf_word[number];
}


void Tree::print_lexical(Node* current, const string& prefix, const string& suffix) {

    if (current->end_of_word and suffix.size() != 0) {
        cout << to_string(counter_word) + " " + prefix + suffix << endl;


        buf_word[counter_word] = prefix + suffix;
        ++counter_word;
    }

    for (int i = 0; i < 26; i++) {
        string temp = suffix;
        if (current->children[i]) {
            temp += current->children[i]->letter;
            print_lexical(current->children[i], prefix, temp);
        }
    }
}


Node* Tree::search(const string& str) {
    Node* current = &root_;
    for (size_t i = 0; i < str.size(); i++) {
        if (current->children[str.at(i) - 'a']) {
            current = current->children[str.at(i) - 'a'];
        }
        else {
            current = NULL;
            break;
        }
    }
    return current;
}



void Tree::insert(const string& str) {
    Node* current = &root_;
    for (size_t i = 0; i < str.size(); i++) {
        if (current->children[str.at(i) - 'a'] == NULL) {
            current->children[str.at(i) - 'a'] = new Node;
            current->children[str.at(i) - 'a']->letter = str.at(i);
        }
        current = current->children[str.at(i) - 'a'];
    }
    current->end_of_word = true;
}


const Node& Tree::get_root() const {
    return root_;
}