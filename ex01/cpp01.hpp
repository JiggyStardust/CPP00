/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp01.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:22:45 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/19 17:10:37 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_HPP
# define CPP01_HPP
# define FIRSTNAME 0
# define LASTNAME 1
# define NICKNAME 2
# define NUMBER 3
# define SECRET 4


# include <cctype>
# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>
# include <type_traits> // for streamsize
# include <limits>

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
		void searchContacts();
};

#endif