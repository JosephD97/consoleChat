#pragma once
#include <iostream>
#include <vector>
#include "Message.h"


class Message;

class User
{

	std::string login_;
	std::string password_;
	std::vector<Message> privateMessages_;

public:
	User() = default;
	User(const std::string& login, const std::string& password)
		: login_(login), password_(password) {}


	const std::string& getLogin() const {return login_;}
	const std::string& getPassword() const { return password_; }


	void setLogin(const std::string& login) { login_ = login; }
	void setPassword(const std::string& password) { password_ = password; }


	std::vector<Message>& getPrivateMessages() { return privateMessages_; }

	//const std::string& getUserName() const { return name_; }
	//void setUserName(const std::string& name) { name_ = name; }
		

};

