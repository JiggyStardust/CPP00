/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:24:06 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/18 14:53:07 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpp01.h"

#include <iostream>
#include <fstream>
#include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		void setInfo(std::string info, int type);
		std::string getInfo(int type);
};

class PhoneBook
{
	private:
		Contact	contacts[8];
		int	contactCount;
		int	nextIndex;

	public:
    	PhoneBook() noexcept;
		void addContact();
		// void searchContacts();
};

void	Contact::setInfo(std::string info, int type)
{
	if (info.empty())
		throw std::runtime_error("No field in a contact should be left empty.");
	if (type == FIRSTNAME)
		FirstName = info;
	else if (type == LASTNAME)
		LastName = info;
	else if (type == NICKNAME)
		NickName = info;
	else if (type == NUMBER)
	{
		for (size_t i = 0; i < info.length(); i++)
		{
			if (!std::isdigit(info[i]))
				throw std::runtime_error("Phone number should only hold digits.");
		}
		PhoneNumber = info;
	}
	else if (type == SECRET)
		DarkestSecret = info;
}

std::string Contact::getInfo(int type)
{
	if (type == FIRSTNAME)
		return FirstName;
	else if (type == LASTNAME)
		return LastName;
	else if (type == NICKNAME)
		return NickName;
	else if (type == NUMBER)
		return PhoneNumber;
	else if (type == SECRET)
		return DarkestSecret;
	return ""; // If they ask for something that isn't there?
}

void	inputToContact(Contact &contact, int type)
{
	std::string input;
	std::getline(std::cin, input);
	contact.setInfo(input, type);
}

PhoneBook::PhoneBook() noexcept : contactCount(0), nextIndex(0) {}
 // this is the constructor, no destructor if no new (malloc)?

void	PhoneBook::addContact(void)
{
	Contact newContact;
	while (true)
	{
		try
		{
			std::cout << "First name: ";
			inputToContact(newContact, FIRSTNAME);

			std::cout << "Last name: ";
			inputToContact(newContact, LASTNAME);

			std::cout << "Nickname: ";
			inputToContact(newContact, NICKNAME);

			std::cout << "Phone number: ";
			inputToContact(newContact, NUMBER);

			std::cout << "Darkest secret: ";
			inputToContact(newContact, SECRET);
		}
		catch (const std::exception& error)
		{
			std::cout << "Error: " << error.what() << "\n";
			continue ;
		}
		break ;
	}
	contacts[nextIndex] = newContact;
	if (contactCount < 8)
		contactCount++;
	nextIndex = (nextIndex + 1) % 8;
	
}

int	main(void)
{
	PhoneBook phonebook;
	std::string	prompt;

	while (true)
	{
		std::cout << "ADD, SEARCH or EXIT?\n\nAction: ";
		std::cin >> prompt;
		std::cin.ignore(); // discard newline
		if (prompt.compare("ADD") == 0)
			phonebook.addContact();
		else if (prompt.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Sorry, come again?\n";
	}
	return (0);
}




// • ADD: save a new contact
// ◦ If the user enters this command, they are prompted to input the information
// of the new contact one field at a time. Once all the fields have been completed,
// add the contact to the phonebook.
// ◦ The contact fields are: first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.

// • SEARCH: display a specific contact
// ◦ Display the saved contacts as a list of 4 columns: index, first name, last
// name and nickname.
// ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
// them. The text must be right-aligned. If the text is longer than the column,
// it must be truncated and the last displayable character must be replaced by a
// dot (’.’).
// ◦ Then, prompt the user again for the index of the entry to display. If the index
// is out of range or wrong, define a relevant behavior. Otherwise, display the
// contact information, one field per line.
// • EXIT
// ◦ The program quits and the contacts are lost forever!