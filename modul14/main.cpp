#include<iostream>
#include <string>
#include "Tree.h"

using namespace std;


std::string choice_word(Tree& T);


int main() {    

    Tree T;

    //Добавление слов в дерево
    T.insert("we");
    T.insert("walk");
    T.insert("want");
    T.insert("wish");
    T.insert("wit");
    T.insert("am");
    T.insert("yo");
    T.insert("will");
    T.insert("wee");
    T.insert("war");
    T.insert("warp");
    T.insert("win");
    
    std::string result;
    std::string word;
    for(;;) {
       
        word = choice_word(T);
        T.clear_buf_word();

        if(word == "EXIT") {
            std::cout << result << std::endl;
            break;
        }

        if (word != "") {
            result = result + word + " ";            
        }
        
        std::cout << result << std::endl;
    }    
    return 0;
}


std::string choice_word(Tree& T) {

    string part_word;

    std::cout << "Write part word" << std::endl;
    std::cout << "For exit from the programm write EXIT" << std::endl;
    std::cin >> part_word;        

    if (part_word == "EXIT") {
        system("cls");
        return part_word;
    }    

    //преобразование в нижний регистр
    for (size_t i = 0; i < part_word.size(); ++i) {
        if (part_word[i] < 97) {
            part_word[i] += 32;
        }
    }

    Node* current = T.search(part_word);
    current = T.search(part_word);
    bool haschildren = false;

    if (current == NULL or current == &T.get_root()) {
        cout << "Not found words with part_word " << endl;
    }
    else {
        // поиск слова с переданным префиксом       
        for (int c = 0; c < 26; c++) {
            if (current->children[c] != NULL) {
                haschildren = true;
                break;
            }
        }

        if (haschildren == false) {
            cout << "No words with matching prefix found" << endl;
        }
        else {
            cout << "Word(s) with prefix: " << part_word << endl;
            T.print_lexical(current, part_word, "");
        }
    }

    std::string number; //номер слова из предложенных вариантов

    if (haschildren) {
        std::cout << "Write number word" << std::endl;
        std::cin >> number;
        system("cls");
        if (std::stoi(number) >= max_number_word) {
            return "";
        }
        else {
            return T.get_word(std::stoi(number));
        }
    }
    else {        
        return "";
    }
}
