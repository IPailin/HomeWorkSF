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

    //���������� ����� � ������
    void insert(const string& str);

    //�������� ���������� buf_word � ����� �������� ����
    void clear_buf_word();

    //����� ����� � ������
    Node* search(const string& str);

    // ��������� ���� �� ���������� ��������
    void print_lexical(Node* current, const string& prefix, const string& suffix);
};
