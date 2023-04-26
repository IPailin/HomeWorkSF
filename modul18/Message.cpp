#include "Message.h"

std::fstream& operator >> (std::fstream& is, Message& message) {

	is >> message._sender;
	is.seekg(std::ios_base::cur - 3);
	is >> message._reciver;
	is >> message._text;

	return is;
}

std::ostream& operator << (std::ostream& os, const Message& message) {

	os << message._sender;
	os << " -> ";
	os << message._reciver;
	os << "!\n";
	os << message._text;

	return os;
}