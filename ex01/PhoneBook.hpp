/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:15:37 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/20 15:23:41 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

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