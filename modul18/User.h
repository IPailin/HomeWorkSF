#pragma once

#include<iostream>
#include<string>
#include <fstream>

class User {

	std::string _name;
	std::string _login;
	std::string _pass;

public:
	User(const std::string name, const std::string login, const std::string pass) : _name(name), _login(login), _pass(pass) 
	{
	}

	friend std::fstream& operator >> (std::fstream& is, User& user);
	friend std::ostream& operator << (std::ostream& os, const User& user);
};
