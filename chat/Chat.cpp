#include "Chat.h"
#include <iostream>
#include "Message.h"


User* Chat::signUp()
{
	if (userCount >= 10)
	{
		std::cout << "Too many users!\n";
		return nullptr;
	}

	std::string login;
	std::string password;

	std::cout << "login: ";
	std::cin >> login;

	for (int i = 0; i < userCount; ++i)
	{
		if (users[i].getLogin() == login)
		{
			std::cout << "This login is already taken\n";
			return nullptr;
		}
	}

	std::cout << "password: ";
	std::cin >> password;

	users[userCount].setLogin(login);
	users[userCount].setPassword(password);
	userCount++;
	std::cout << "\n";
	std::cout << "Succsess!\n";
	return &users[userCount - 1];	
}

User* Chat:: logIn()
{
	std::string login;
	std::string password;
	std::cout << "login: ";
	std::cin >> login;
	std::cout << "password: ";
	std::cin >> password;

	for (int i = 0; i < userCount; ++i)
	{
		if (users[i].getLogin() == login && users[i].getPassword() == password)
		{
			std::cout << "\n";
			std::cout << "Succsess!\n";
			return &users[i];
		}
		
		
	}
	std::cout << "\n";
	std::cout << "Invalid login or password!\n";
	return nullptr;
}

User* Chat::getUserByLogin(const std::string& login)  
{
	for (int i = 0; i < userCount; ++i) 
	{
		if (users[i].getLogin() == login) 
		{
			return &users[i];
		}
	}
	return nullptr;
}

void Chat::sendToAll(const std::string& senderLogin, const std::string& text) 
{
	Message msg(senderLogin, text);
	groupMessages_.push_back(msg); 
	std::cout << "Message sent to all: " << text << std::endl;
}


void Chat::viewAllChat() const 
{
	std::cout << "General chat:\n";
	for (const auto& msg : groupMessages_) 
	{
		std::cout << msg.getFrom() << ": " << msg.getText() << std::endl;
	}
}


void Chat::sendPrivateMessage(const std::string& from, const std::string& to, const std::string& text) 
{
	User* sender = getUserByLogin(from);
	User* recipient = getUserByLogin(to);

	if (sender && recipient) 
	{
		Message msg(from, to, text);
		recipient->getPrivateMessages().push_back(msg);
		sender->getPrivateMessages().push_back(msg);
		std::cout << "Message sent from " << from << " to " << to << ": " << text << std::endl;
	}
	else 
	{
		std::cout << "Invalid sender or recipient login.\n";
	}
}


void Chat::viewPrivateMessages(const std::string& login) 
{
	User* user = getUserByLogin(login);
	if (user)
	{
		const auto& messages = user->getPrivateMessages();
		if (messages.empty())
		{
			std::cout << "No private messages.\n";
		}
		else
		{
			std::cout << "Private messages for " << login << ":\n";
			for (const auto& msg : messages)
			{
				std::cout << msg.getFrom() << " -> " << msg.getTo() << ": " << msg.getText() << std::endl;
			}
		}
	}
	else
	{
		std::cout << "User not found.\n";
	}
}

