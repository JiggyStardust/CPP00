/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:24:06 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/20 15:37:22 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

# include <cctype> //isspace, isdigit
# include <iostream> // cout and cin
# include <string> // for string stuff
# include <stdexcept> // for throw and catch
# include <fstream> // getline
# include <type_traits> // for streamsize // is it necessary?
# include <limits> // for limits used in cin.ignore

PhoneBook::PhoneBook() noexcept : contactCount(0), nextIndex(0) {}

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

void	PhoneBook::searchContacts(void)
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
		else if (std::cin.fail())
			std::cin.clear();
		else if (index >= 0 && index < contactCount)
			break ;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // doesn't work without, how does it work
		std::cout << "\nNot a valid index, try again.";
	}
	displayContact(contacts[index]);
}

void	inputToContact(Contact &contact, int type)
{
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
		throw std::runtime_error("User canceled contact's detail setup.\n"); // test with just throw""
	contact.setInfo(input, type);
}

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
	PhoneBook Phonebook;
	std::string	prompt;
	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << "User canceled program.\n" << std::endl;
			break ;
		}
		std::cout << "\n\nADD, SEARCH or EXIT?\n\nAction: ";
		std::cin >> prompt;
		std::cin.ignore();
		if (prompt.compare("ADD") == 0)
			Phonebook.addContact();
		else if (prompt.compare("SEARCH") == 0)
			Phonebook.searchContacts();
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
