/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:15:37 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/21 12:25:15 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

# include <iostream> // cout and cin
# include <string> // for string stuff
# include <stdexcept> // for throw and catch
# include <fstream> // getline
# include <limits> // for limits used in cin.ignore

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