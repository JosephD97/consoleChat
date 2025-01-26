#include <iostream>
#include <string>
#include "User.h"
#include "Chat.h"
#include "Message.h"


int main()
{
	Chat chat;
	std::string login;
	std::string password;
	std::string message;
	std::string reciever;
	char choise;
	User* currentUser = nullptr;


	if (currentUser == nullptr)
	{
		while (true) 
		{
			std::cout << "=========================\n";
			std::cout << "1 Registration\n2 Login\n3 Exit\n";
			std::cout << "=========================\n";
			std::cout << "Make a choise : ";
			std::cin >> choise;
			std::cin.ignore();
			switch (choise)
			{
			case '1':
				std::cout << "\n";
				chat.signUp();
				break;
			case '2':
				std::cout << "\n";
				currentUser = chat.logIn();
				while (true)
				{
					std::cout << "=========================\n";
					std::cout << "1 General chat\n2 Private chat\n3 Show general chat\n4 Show private messages\n5 Logout\n";
					std::cout << "=========================\n";
					std::cout << "Make a choise : ";
					std::cin >> choise;
					switch (choise)
					{
					case '1':
						std::cout << "\n";
						std::cout << "Enter a message: ";
						std::cin.ignore();
						std::getline(std::cin,message);
						chat.sendToAll(currentUser->getLogin(), message);
						break;
					case '2':
						std::cout << "\n";
						std::cout << "Enter reciever's name: ";
						std::cin >> reciever;
						std::cin.ignore();
						std::cout << "Enter a message: ";
						std::getline(std::cin,message);
						chat.sendPrivateMessage(currentUser->getLogin(), reciever, message);
						break;
					case '3':
						std::cout << "\n";
						chat.viewAllChat();
						break;
					case'4':
						std::cout << "\n";
						chat.viewPrivateMessages(currentUser->getLogin());
						break;
					case'5':
						std::cout << "\n";
						std::cout << "Logging out...\n";
						currentUser = nullptr;
						break;
					default:"Invalid value, try again\n";
						continue;
					}
					if (currentUser == nullptr)
						break;
				}
				break;
			case'3':
				exit(true);
				break;
			default:
				std::cout<< "Invalid value, try again\n";
				continue;
			}
		}

	}
    return 0;
}
