/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:24:06 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/22 16:35:39 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() noexcept : ContactCount(0), Index(0) {}

std::string trunc(const std::string &detail)
{
    if (detail.length() > 10)
        return detail.substr(0, 9) + ".";  // Directly return modified string
    return detail;  // No need for reassignment
}

void	previewContact(Contact currContact, int index)
{
	std::string first;
	std::string last;
	std::string nick;

	first = currContact.getInfo(FIRSTNAME);
	last = currContact.getInfo(LASTNAME);
	nick = currContact.getInfo(NICKNAME);

	first = trunc(first);
	last = trunc(last);
	nick = trunc(nick);
	std::cout << "|" << std::setw(10) << index << "|" << std::setw(10) << first \
	<< "|" << std::setw(10) << last << "|" << std::setw(10) << nick << "|" << std::endl;
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

	std::cout << std::setfill('_') << std::setw(45) << "\n" << first << "\n" << last << "\n" << nick << "\n" << number << "\n" \
	<< secret << std::endl;
}

void	PhoneBook::searchContacts(void)
{
	int index;
	if (ContactCount < 1)
	{
		std::cout << "\n\nGet some friends first...\nReturning to main menu.\n";
		return ;
	}
	std::cout << "|" << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" \
	<< "|" << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICK NAME" << "|" << std::endl;

	for (int i = 0; i < ContactCount; i++)
		previewContact(Contacts[i], i);
	for (int tries = 1; tries <= 3; tries++)
	{
		std::cout << "\n\nSet the index of the desired contact\nIndex: ";
		std::cin >> index;
		if (std::cin.eof())
			return ;
		else if (std::cin.fail())
			std::cin.clear();
		else if (index >= 0 && index < ContactCount)
			break ;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (tries == 3)
		{
			std::cout << "\n- - - - Too many attempts, returning to main menu. - - - -";
			return ;
		}
		std::cout << "\nNot a valid index, try again.";
	}
	displayContact(Contacts[index]);
}

void	inputToContact(Contact &contact, int type)
{
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof() || input == "CANCEL")
		throw std::runtime_error("User canceled contact's detail setup.\n");
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
	Contacts[Index] = newContact;
	if (ContactCount < 8)
		ContactCount++;
	Index = (Index + 1) % 8;
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
		if (std::cin.eof())
		{
			std::cout << "User canceled program.\n" << std::endl;
			break ;
		}
		if (prompt == "ADD")
			Phonebook.addContact();
		else if (prompt == "SEARCH")
			Phonebook.searchContacts();
		else if (prompt == "EXIT")
		{
			std::cout << "\n- - - - - - - - - - - - Goodbye! - - - - - - - - - - -\n" << std::endl;
			break ;
		}
		else
			std::cout << "\nSorry, come again?\n";
	}
	return (0);
}
