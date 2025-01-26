#pragma once
#include <iostream>

class Message
{
	std::string from_;
	std::string	to_;
	std::string	text_;
public:
	Message(const std::string& from, const std::string& text)
		: from_(from), text_(text), to_("") {}

	Message(const std::string& from, const std::string& to, const std::string& text)
		: from_(from), to_(to), text_(text) {}

	const std::string& getFrom() const { return from_; }
	const std::string& getTo() const { return to_; }
	const std::string& getText() const { return text_; }
};

