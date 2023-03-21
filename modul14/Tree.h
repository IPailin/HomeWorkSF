#pragma once
#include<iostream>
#include <string>

#include "Node.hpp"

using namespace std;


constexpr int max_number_word{ 10 };

class Tree {

private:

    Node root_;
    std::string buf_word[max_number_word];
    int counter_word{ 0 };

public:

    Tree() = default;
    ~Tree() = default;

    const Node& get_root() const;
    const std::string& get_word(int number);

    //Добавление слова в дерево
    void insert(const string& str);

    //Отчистка переменной buf_word и сброс счетчика слов
    void clear_buf_word();

    //Поиск слова в дереве
    Node* search(const string& str);

    // Написание слов по начальному префиксу
    void print_lexical(Node* current, const string& prefix, const string& suffix);
};
