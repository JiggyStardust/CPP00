/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:24:06 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/20 08:57:31 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpp01.hpp"

phoneBook::phoneBook() noexcept : contactCount(0), nextIndex(0) {}

std::string Contact::getInfo(int type)
{
	if (type == FIRSTNAME)
		return firstName;
	else if (type == LASTNAME)
		return lastName;
	else if (type == NICKNAME)
		return nickName;
	else if (type == NUMBER)
		return phoneNumber;
	else
		return darkestSecret;
}

int		strIsSpace(std::string str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if (!std::isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	Contact::setInfo(std::string info, int type)
{
	if (info.empty() || strIsSpace(info))
		throw std::runtime_error("No field in a contact should be left empty.");
	if (type == FIRSTNAME)
		firstName = info;
	else if (type == LASTNAME)
		lastName = info;
	else if (type == NICKNAME)
		nickName = info;
	else if (type == NUMBER)
	{
		for (size_t i = 0; i < info.length(); i++)
		{
			if (!std::isdigit(info[i]))
				throw std::runtime_error("Phone number should only hold digits.");
		}
		phoneNumber = info;
	}
	else if (type == SECRET)
		darkestSecret = info;
}

void	inputToContact(Contact &contact, int type)
{
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
		throw std::runtime_error("User canceled contact's detail setup.\n");
	contact.setInfo(input, type);
}


std::string truncOrAppend(std::string detail)
{
	if (detail.length() > 10)
		detail = detail.substr(0, 9) + ".";
	while (detail.length() < 10)
		detail = detail + " ";
	return (detail);
}

void	previewContact(Contact currContact, int index)
{
	std::string first;
	std::string last;
	std::string nick;

	first = currContact.getInfo(FIRSTNAME);
	last = currContact.getInfo(LASTNAME);
	nick = currContact.getInfo(NICKNAME);

	first = truncOrAppend(first);
	last = truncOrAppend(last);
	nick = truncOrAppend(nick);
	std::cout << "|     " << index << "    |" \
	<< first << "|" << last << "|" << nick << "|" << std::endl;
}

void	displayContact(Contact currContact)
{
	std::string first;
	std::string last;
	std::string nick;
	std::string number;
	std::string secret;

	first = currContact.getInfo(FIRSTNAME);
	last = currContact.getInfo(LASTNAME);
	nick = currContact.getInfo(NICKNAME);
	number = currContact.getInfo(NUMBER);
	secret = currContact.getInfo(SECRET);

	std::cout << "\n\n" << first << "\n" << last << "\n" << nick << "\n" << number << "\n" \
	<< secret << std::endl;
}

void	phoneBook::searchContacts(void)
{
	int index;
	if (contactCount < 1)
	{
		std::cout << "\n\nGet some friends first...\nReturning to main menu.\n";
		return ;
	}
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICK NAME|\n";
	for (int i = 0; i < contactCount; i++)
		previewContact(contacts[i], i);
	while (true)
	{
		std::cout << "\n\nSet the index of the desired contact\nIndex: ";
		std::cin >> index;
		if (std::cin.eof())
			return ;
		else if (std::cin.fail()) // if input is not int
			std::cin.clear(); // clear error flag (from stream?)
		else if (index >= 0 && index < contactCount)
			break ;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // try without this just with clear.
		std::cout << "\nNot a valid index, try again.";
	}
	displayContact(contacts[index]);
}

void	phoneBook::addContact(void)
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
			if (std::string(error.what()) != "User canceled contact's detail setup.\n")
				continue ;
			else
				return ;
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
	phoneBook phonebook;
	std::string	prompt;
	while (true)
	{
		std::cout << "\n\nADD, SEARCH or EXIT?\n\nAction: ";
		std::cin >> prompt;
		std::cin.ignore();
		if (std::cin.eof())
		{
			std::cout << "User canceled program.\n" << std::endl;
			break ;
		}
		else if (prompt.compare("ADD") == 0)
			phonebook.addContact();
		else if (prompt.compare("SEARCH") == 0)
			phonebook.searchContacts();
		else if (prompt.compare("EXIT") == 0)
		{
			std::cout << "\nGoodbye!\n" << std::endl;
			break ;
		}
		else
			std::cout << "\nSorry, come again?\n";
	}
	return (0);
}
