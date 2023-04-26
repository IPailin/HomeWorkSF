#include <iostream>
#include <fstream>
#include<filesystem>

#include "Message.h"
#include "User.h"

namespace fs = std::filesystem;


void demo_perms(fs::perms p);

int main() {

	std::fstream user_file = std::fstream("user.txt", std::ios::in | std::ios::out | std::ios::trunc);

	std::fstream message_file = std::fstream("message.txt", std::ios::in | std::ios::out | std::ios::trunc);

	if (user_file && message_file) {

		User user1("Alex", "@alex", "qwerty");
		user_file << user1 << std::endl;

		Message mes1("text message", "@alex", "@tor");
		message_file << mes1 << std::endl;

		user_file.seekg(0, std::ios_base::beg);
		message_file.seekg(0, std::ios_base::beg);

		user_file >> user1;
		message_file >> mes1;

		std::cout << user1 << std::endl;
		std::cout << mes1 << std::endl;
	}

	demo_perms(fs::status("user.txt").permissions());
	demo_perms(fs::status("message.txt").permissions());

	//Меняем разрешение файла 
	fs::permissions("user.txt", fs::perms::group_all | fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
	fs::permissions("message.txt", fs::perms::group_all | fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);

	demo_perms(fs::status("user.txt").permissions());
	demo_perms(fs::status("message.txt").permissions());

	user_file.close();
	message_file.close();

	return 0;
}


void demo_perms(fs::perms p)
{
	std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
		<< '\n';
}