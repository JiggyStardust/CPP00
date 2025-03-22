/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:15:37 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/22 13:55:41 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

# include <iostream> // cout and cin
# include <iomanip> // setw
# include <string> // for string stuff
# include <stdexcept> // for throw and catch
# include <fstream> // getline
# include <limits> // for limits used in cin.ignore

class PhoneBook
{
	private:
		Contact	Contacts[8];
		int	ContactCount;
		int	Index;

	public:
    	PhoneBook() noexcept;
		void addContact();
		void searchContacts();
};