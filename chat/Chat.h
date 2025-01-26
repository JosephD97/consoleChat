#pragma once
#include "User.h"
#include "Message.h"
#include <vector>



class Chat
{
	User users[10];
	int userCount = 0;
	std::vector<Message> groupMessages_;
public:
	User* signUp();
	User* logIn();
	User* getUserByLogin(const std::string& login);


	void sendToAll(const std::string& senderLogin, const std::string& text);
	void viewAllChat() const;
	void sendPrivateMessage(const std::string& senderLogin, const std::string& recipientLogin, const std::string& text);
	void viewPrivateMessages(const std::string& login);
};

