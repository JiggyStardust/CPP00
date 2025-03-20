/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp01.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:22:45 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/20 08:09:26 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_HPP
# define CPP01_HPP
# include "cpp01.h"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void setInfo(std::string info, int type);
		std::string getInfo(int type);
};

class phoneBook
{
	private:
		Contact	contacts[8];
		int	contactCount;
		int	nextIndex;

	public:
    	phoneBook() noexcept;
		void addContact();
		void searchContacts();
};

#endif