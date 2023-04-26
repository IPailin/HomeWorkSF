#include "User.h"

std::fstream& operator >> (std::fstream& is, User& user) {
	is >> user._name;
	is >> user._login;
	is >> user._pass;
	return is;
}

std::ostream& operator << (std::ostream& os, const User& user) {

	os << user._name;
	os << ' ';
	os << user._login;
	os << ' ';
	os << user._pass;

	return os;
}