#pragma once

#include<iostream>
#include<string>
#include <fstream>

class Message {

	std::string _text;
	std::string _sender;
	std::string _reciver;

public:
	Message(const std::string text, const std::string sender, const std::string reciver) : _text(text), _sender(sender), _reciver(reciver)
	{
	}

	friend std::fstream& operator >> (std::fstream& is, Message& message);
	friend std::ostream& operator << (std::ostream& os, const Message& message);
};
